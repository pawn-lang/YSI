<?php

if (!function_exists('shmop_open'))
{
	die(YSI_ERROR . '3');
}

include('./YSI.php');

// This is not sanitised - do not make this code externally accessible.  Also,
// this should never be over 65535.  Now sanitised. (but still don't let this
// code get out).
$ID = $_GET['ID'];
//echo 'ID = ' . $ID;
if (!is_numeric($ID) || $ID < 0 || $ID > 65535)
{
	die(YSI_ERROR . '0'); // ID out of bounds.
}

// All scripts set to time out after 15 (or 18 in some cases) seconds.
$YSI_gEnd = time() + rand(10, 15);
$YSI_gMaster = 0;

$YSI_gShare = FALSE;
$tries = 0;
while ($tries < 400)
{
	++$tries;
	$YSI_gShare = shmop_open($YSI_gMemoryID, 'c', 0777, YSI_SHARE_SIZE);
	if ($YSI_gShare === FALSE)
	{
		++$YSI_gMemoryID;
	}
	else
	{
		break;
	}
}
if ($YSI_gShare === FALSE)
{
	die(YSI_ERROR . '1'); // Could not open shared memory.
}

if ($ID == 0)
{
	// Reset all data.
	YSI_Lock(YSI_SHARE);
	shmop_write($YSI_gShare, YSI_HEADER, 2);
	YSI_Unlock(YSI_SHARE);
}
else
{
	$data = $_GET['TO'];
	if ($data != 0)
	{
		// Write the new return value.
		YSI_Lock(YSI_RETURN);
		if (shmop_read($YSI_gWrite, 4, 2) !== "\0\0")
		{
			YSI_Unlock(YSI_RETURN);
			// Give a sinlge script fair chance to catch up.
			usleep(50);
			YSI_Lock(YSI_RETURN);
		}
		if (shmop_read($YSI_gWrite, 4, 2) !== "\0\0")
		{
			YSI_Unlock(YSI_RETURN);
			// Give a sinlge script fair chance to catch up.
			usleep(50);
			YSI_Lock(YSI_RETURN);
		}
		shmop_write($YSI_gShare, YSI_Num32($_GET['RE']), 6);
		shmop_write($YSI_gShare, chr($data >> 8 & 0xFF) . chr($data & 0xFF), 4);
		YSI_Unlock(YSI_RETURN);
	}
	for ( ; ; )
	{
		// Try get the master, so only one reply ever sends.
		YSI_Lock(YSI_MASTER);
		$data = shmop_read($YSI_gShare, 0, 2);
		$YSI_gMaster = ord($data[0]) << 8 | ord($data[1]);
		if ($YSI_gMaster == 0)
		{
			$YSI_gMaster = $ID;
			shmop_write($YSI_gShare, chr($ID >> 8 & 0xFF) . chr($ID & 0xFF), 0);
		}
		YSI_Unlock(YSI_MASTER);
		if ($YSI_gMaster == $ID)
		{
			// We are now the master script!
			break;
		}
		else if (time() > $YSI_gEnd)
		{
			die(YSI_ERROR . '2');
			// Unrequired (this one's replacement should in theory take the
			// master, so we don't loose the memory block).
		}
		usleep(50);
	}
	
	function GetIndex()
	{
		global $YSI_gShare;
		YSI_Lock(YSI_SHARE);
		$str = shmop_read($YSI_gShare, 2, 2);
		YSI_Unlock(YSI_SHARE);
		return ord($str[0]) << 8 | ord($str[1]);
	}
	
	function GetData()
	{
		global $YSI_gShare;
		YSI_Lock(YSI_SHARE);
		// Get the index.
		$str = shmop_read($YSI_gShare, 2, 2);
		$idx = ord($str[0]) << 8 | ord($str[1]);
		// Get all the data.
		$str = shmop_read($YSI_gShare, 11, $idx - 11);
		// Reset.
		shmop_write($YSI_gShare, YSI_HEADER, 2);
		YSI_Unlock(YSI_SHARE);
		return $str;
	}
	
	function GetIndexUnsafe()
	{
		// Has no locks.
		global $YSI_gShare;
		$str = shmop_read($YSI_gShare, 2, 2);
		return ord($str[0]) << 8 | ord($str[1]);
	}
	
	function GetDataUnsafe()
	{
		// Has no locks.
		global $YSI_gShare;
		// Get the index.
		$str = shmop_read($YSI_gShare, 2, 2);
		$idx = ord($str[0]) << 8 | ord($str[1]);
		// Get all the data.
		$str = shmop_read($YSI_gShare, 11, $idx - 11);
		// Reset.
		shmop_write($YSI_gShare, YSI_HEADER, 2);
		return $str;
	}
	
	for ( ; ; )
	{
		YSI_Lock(YSI_SHARE);
		$idx = GetIndexUnsafe();
		if ($idx >= YSI_SHARE_SIZE / 4 || time() > $YSI_gEnd)
		{
			echo YSI_SUCCESS . GetDataUnsafe();
			YSI_Unlock(YSI_SHARE);
			break;
		}
		YSI_Unlock(YSI_SHARE);
		usleep(50);
	}
	
	// Now relinquish control.
}

// Wait 3 seconds before giving up looking for a replacement.
$YSI_gEnd = time() + 3;
YSI_Lock(YSI_MASTER);
shmop_write($YSI_gShare, YSI_NO_MASTER, 0);
YSI_Unlock(YSI_MASTER);
for ( ; ; )
{
	usleep(50);
	YSI_Lock(YSI_MASTER);
	// Try get the master, so only one reply ever sends.
	$data = shmop_read($YSI_gShare, 0, 2);
	YSI_Unlock(YSI_MASTER);
	if ((ord($data[0]) << 8 | ord($data[1])) != 0)
	{
		// There is another master script.
		break;
	}
	else if (time() > $YSI_gEnd)
	{
		// No more masters, close down the system.
		shmop_close($YSI_gShare);
		break;
	}
}

if ($ID == 0)
{
	die('-');
}

?>
