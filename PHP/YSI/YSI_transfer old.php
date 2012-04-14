<?php

include 'YSI.php';

// Use 'n', not 'c', so that we are always in charge.
$shared = shmop_open(4242, 'n', 0664, 1024) or die 'Could not create shared memory block';

// Initialise the session system for this script.
session_start();

// No sanitation here, make sure this can only be got from a safe place.
$ID = $_GET['id'];
//$LOOP = 0;
$END = time() + 10;

define('NL', "\r\n");
define('CLAIMED', '__CLAIMED__');

echo 'Start' . NL;

for ( ; ; )
{
	// Try and become the only script sending data to the client.  More
	// importantly, try and become the only script getting data to be send so
	// that other PHP scripts don't end up having their data sent multiple
	// times.
	$first = false;
	if (isset($_SESSION['YSI_owner']))
	{
		if ($_SESSION['YSI_owner'] == $ID)
		{
			goto YSI_transfer_run;
		}
		else
		{
			goto YSI_transfer_retry;
		}
	}
	else
	{
		$_SESSION['YSI_claim_' . $ID] = CLAIMED;
		$requests = array_keys($_SESSION, CLAIMED, true);
		foreach ($requests as $key)
		{
			if (strncmp($key, 'YSI_claim_', 10) == 0)
			{
				if (strncmp($ID, substr($key, 10)) == 0)
				{
					$first = true;
				}
				else
				{
					// Another script has claimed the master, don't bother.
					goto YSI_transfer_retry;
				}
			}
		}
		$_SESSION['YSI_owner'] = $ID;
		continue;
	}
YSI_transfer_retry:
	unset($_SESSION['YSI_claim_' . $ID]);
	//++$LOOP;
	//if ($LOOP >= 2000000)
	if (time() > $END)
	{
		goto YSI_transfer_end;
	}
	if (!$first)
	{
		// The script with the lowest ID will retry straight away.
		usleep(10);
	}
}
YSI_transfer_run:

echo 'OK' . NL;

// Now we start doing all the interesting code.

$stream = '';

function AddMessage($key, $value)
{
	global $stream;
	$len = strlen($key);
	if ($len > 31)
	{
		$key = substr($key, 0, 31);
		$len = 31;
	}
	$stream = $stream . NL . $len . ':' . strlen($value) . ':' . $key . ':' . $value;
}

function RequestUniqueID()
{
	// Note that there is a SMALL chance that this will not be unique.
	$ret = '';
	do
	{
		$ret = uniqid("YSI_unq_", true);
	}
	while (isset($_SESSION[$ret]));
	$_SESSION[$ret] = true;
	return $ret;
}

function ReleaseUniqueID($ret)
{
	unset($_SESSION[$ret]);
}

AddMessage('YSI_id', $ID);

for ( ; ; )
{
	if ($_SESSION['YSI_owner'] == $ID)
	{
		// Poll for messages.
	}
	else
	{
		AddMessage('YSI_error', '"YSI_owner" value corrupted (should never happen)');
		break;
	}
	//++$LOOP;
	if (time() > $END)
	{
		break;
	}
	usleep(10);
}

YSI_transfer_done:

echo 'End 1' . NL;

// Send the message.
echo $stream;
unset($_SESSION['YSI_claim_' . $ID]);
unset($_SESSION['YSI_owner']);
YSI_transfer_end:

echo 'End 2' . NL;

?>
