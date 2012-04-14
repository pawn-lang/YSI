<?php

$YSI_gLockHandle = array();

function YSI_Lock($name)
{
	// Do not use this for significant code - it blocks on Windows...
	global $YSI_gLockHandle;
	// Use flock (disk-based).
	$YSI_gLockHandle[$name] = fopen('./tmp/' . $name . '.tmp', 'c');
	flock($YSI_gLockHandle[$name], LOCK_EX);
}

function YSI_Unlock($name)
{
	// Use flock (disk-based).
	flock($YSI_gLockHandle[$name], LOCK_UN);
	fclose($YSI_gLockHandle[$name]);
}

function YSI_Bernstein($str)
{
	$len = strlen($str);
	$i = 0;
	$hash = -1;
	while ($i < $len)
	{
		// Try and supress conversion to a float on overflow (untested).
		$hash = ($hash * 33 + ord($str[$i])) & 0xFFFFFFFF;
		++$i;
	}
	return $hash;
}

function YSI_WriteNum($dest, $idx, $num)
{
	$str = chr($num >> 24 & 0xFF) . chr($num >> 16 & 0xFF) . chr($num >> 8 & 0xFF) . chr($num & 0xFF);
	return shmop_write($dest, $str, $idx);
}

function YSI_ReadNum($src, $idx, &$num)
{
	$str = shmop_read($src, $idx, 4);
	$num = ord($str[0] << 24) | ord($str[1] << 16) | ord($str[2] << 8) | ord($str[3]);
	return 4;
}

?>
