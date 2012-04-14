<?php

function YSI_Lock($name)
{
	do
	{
		$sem = sem_get(YSI_Bernstein($name));
	}
	while ($sem === FALSE);
	sem_acquire($sem);
}

function YSI_Unlock($name)
{
	do
	{
		$sem = sem_get(YSI_Bernstein($name));
	}
	while ($sem === FALSE);
	sem_release($sem);
}

function YSI_Bernstein($str)
{
	$len = strlen($str);
	$i = 0;
	$hash = -1;
	while ($i < $len)
	{
		//$hash = ((($hash * 33) & 0xFFFFFFFF) + ord($str[$i])) & 0xFFFFFFFF;
		//$hash = $hash * 33 + ord($str[$i]);
		$hash *= 33;
		// Limit this to 32-bit overflow (I hope - now tested more).
		if ($hash & 0x80000000)
		{
			$hash |= 0xFFFFFFFF00000000;
		}
		else
		{
			$hash &= 0x00000000FFFFFFFF;
		}
		$hash += ord($str[$i]);
		if ($hash & 0x80000000)
		{
			$hash |= 0xFFFFFFFF00000000;
		}
		else
		{
			$hash &= 0x00000000FFFFFFFF;
		}
		//echo "Hash stage $i: $hash\r\n";
		++$i;
	}
	return $hash;
}

function YSI_WriteNum($dest, $idx, $num)
{
	$str = chr($num >> 56 & 0xFF) . chr($num >> 48 & 0xFF) . chr($num >> 40 & 0xFF) . chr($num >> 32 & 0xFF) . chr($num >> 24 & 0xFF) . chr($num >> 16 & 0xFF) . chr($num >> 8 & 0xFF) . chr($num & 0xFF);
	return shmop_write($dest, $str, $idx);
}

function YSI_ReadNum($src, $idx, &$num)
{
	$str = shmop_read($src, $idx, 8);
	$num = ord($str[0]) << 56 | ord($str[1]) << 48 | ord($str[2]) << 40 | ord($str[3]) << 32 | ord($str[4]) << 24 | ord($str[5]) << 16 | ord($str[6]) << 8 | ord($str[7]);
	return 8;
}

?>
