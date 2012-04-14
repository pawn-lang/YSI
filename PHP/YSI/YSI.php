<?php

define('NL', chr(255));
define('YSI', 0x554); // 'Y', 'S', 'I'.
define('YSI_SHARE_SIZE', 2048);
define('YSI_HEADER', "\0\11");
define('YSI_SHARE', 'YSI_share');
define('YSI_MASTER', 'YSI_master');
define('YSI_RETURN', 'YSI_return');
define('YSI_ERROR', '0');
define('YSI_SUCCESS', '1');
define('YSI_NO_MASTER', "\0\0");

$YSI_gMemoryID = YSI;

if (function_exists('sem_get'))
{
	if (PHP_INT_SIZE == 4)
	{
		include 'YSI_32l.php';
	}
	else
	{
		include 'YSI_64l.php';
	}
}
else
{
	if (PHP_INT_SIZE == 4)
	{
		include 'YSI_32w.php';
	}
	else
	{
		include 'YSI_64w.php';
	}
}

$YSI_gWrite = FALSE;

function YSI_TryOpen()
{
	global $YSI_gWrite, $YSI_gMemoryID;
	if ($YSI_gWrite === FALSE)
	{
		//if (!function_exists('shmop_open'))
		//{
		//	return FALSE;
		//}
		$tries = 0;
		while ($tries < 400)
		{
			++$tries;
			$YSI_gWrite = shmop_open($YSI_gMemoryID, 'w', 0, 0);
			if ($YSI_gWrite === FALSE)
			{
				++$YSI_gMemoryID;
			}
			else
			{
				return TRUE;
			}
		}
		return FALSE;
	}
	return TRUE;
}

function YSI_Num32($num)
{
	//return chr($num >> 24 & 0xFF) . chr($num >> 16 & 0xFF) . chr($num >> 8 & 0xFF) . chr($num & 0xFF);
	// Encodes the data in 5 bytes to not need to worry about NULL.
	//return chr($num >> 24 & 0xFE | 0x01) . chr($num >> 17 & 0xFE | 0x01) . chr($num >> 10 & 0xFE | 0x01) . chr($num >> 3 & 0xFE | 0x01) . chr($num << 1 & 0x1E | 0x01);
	return chr($num >> 25 & 0x7F | 0x80) . chr($num >> 18 & 0x7F | 0x80) . chr($num >> 11 & 0x7F | 0x80) . chr($num >> 4 & 0x7F | 0x80) . chr($num & 0x0F | 0x80);
}

function YSI_Float32($num)
{
	$num = unpack('l', pack('f', $num));
	//return chr($num >> 24 & 0xFF) . chr($num >> 16 & 0xFF) . chr($num >> 8 & 0xFF) . chr($num & 0xFF);
	// Encodes the data in 5 bytes to not need to worry about NULL.
	//return chr($num >> 24 & 0xFE | 0x01) . chr($num >> 17 & 0xFE | 0x01) . chr($num >> 10 & 0xFE | 0x01) . chr($num >> 3 & 0xFE | 0x01) . chr($num << 1 & 0x1E | 0x01);
	return chr($num >> 25 & 0x7F | 0x80) . chr($num >> 18 & 0x7F | 0x80) . chr($num >> 11 & 0x7F | 0x80) . chr($num >> 4 & 0x7F | 0x80) . chr($num & 0x0F | 0xC0);
}

function YSI_Result($str)
{
	//return chr($num >> 24 & 0xFF) . chr($num >> 16 & 0xFF) . chr($num >> 8 & 0xFF) . chr($num & 0xFF);
	// Encodes the data in 5 bytes to not need to worry about NULL.
	//return chr($num >> 24 & 0xFE | 0x01) . chr($num >> 17 & 0xFE | 0x01) . chr($num >> 10 & 0xFE | 0x01) . chr($num >> 3 & 0xFE | 0x01) . chr($num << 1 & 0x1E | 0x01);
	return ((ord($str[0]) & ~0x80) << 25) | ((ord($str[1]) & ~0x80) << 18) | ((ord($str[2]) & ~0x80) << 11) | ((ord($str[3]) & ~0x80) << 4) | (ord($str[4]) & ~0xF0);
}

function YSI_GetNum8($str)
{
	//return chr($num >> 24 & 0xFF) . chr($num >> 16 & 0xFF) . chr($num >> 8 & 0xFF) . chr($num & 0xFF);
	// Encodes the data in 5 bytes to not need to worry about NULL.
	//return chr($num >> 24 & 0xFE | 0x01) . chr($num >> 17 & 0xFE | 0x01) . chr($num >> 10 & 0xFE | 0x01) . chr($num >> 3 & 0xFE | 0x01) . chr($num << 1 & 0x1E | 0x01);
	return (ord($str[0]) & ~0x80);
}

function YSI_Send($key, $data, $priority = FALSE)
{
	global $YSI_gWrite;
	if (YSI_TryOpen())
	{
		//echo '0';
		// Construct the full messgae.
		$len = strlen($key);
		if ($len > 31)
		{
			$key = substr($key, 0, 31);
			$len = 31;
		}
		$stream = chr($len | 0x80) . $key;
		switch (gettype($data))
		{
			case 'boolean':
				if ($data) $stream .= '1';
				else $stream .= '0';
				break;
			case 'double':
				$stream .= YSI_Float32($data) . NL;
				break;
			case 'integer':
				$stream .= YSI_Num32($data) . NL;
				break;
			case 'string':
				$len = strlen($data);
				if ($len == 0)
				{
					$stream .= YSI_Num32(1) . "\1" . NL;
				}
				else
				{
					$stream .= YSI_Num32($len) . $data . NL;
				}
				break;
			default:
				return FALSE;
		}
		//$stream .= NL;
		$len = strlen($stream);
		if ($len > YSI_SHARE_SIZE - 5)
		{
			return FALSE;
		}
		// The loop here is just in case some data doesn't get sent because the
		// buffer is too full.
		for ($i = 0; $i != 10; ++$i)
		{
			// Now do the sending (lock for as short a time as possible).
			YSI_Lock(YSI_SHARE);
			//echo '2';
			// Read the write index.  The header is a 2 byte master ID then a 2
			// byte index in to the write string.
			$str = shmop_read($YSI_gWrite, 2, 2);
			$idx = ord($str[0]) << 8 | ord($str[1]);
			//echo ':' . $idx . ':';
			//$len += $idx;
			if ($len + $idx <= YSI_SHARE_SIZE)
			{
				if ($priority)
				{
					// Force a send by marking the buffer as full.
					shmop_write($YSI_gWrite, $stream, $idx);
					$target = YSI_SHARE_SIZE;
				}
				else
				{
					$target = $idx + shmop_write($YSI_gWrite, $stream, $idx);
				}
				// Write the new index back.
				shmop_write($YSI_gWrite, chr($target >> 8 & 0xFF) . chr($target & 0xFF), 2);
				//echo '3 ' . $idx . ' ' . $len . ' ';
				YSI_Unlock(YSI_SHARE);
				return TRUE;
			}
			else
			{
				$target = YSI_SHARE_SIZE;
				shmop_write($YSI_gWrite, chr($target >> 8 & 0xFF) . chr($target & 0xFF), 2);
			}
			YSI_Unlock(YSI_SHARE);
			// Could be very bad (but I hope unlikely).
			usleep(25);
		}
		//echo '4';
	}
	return FALSE;
}

function YSI_Call($what, $args)
{
	$c = YSI_ACall($what, $args);
	if ($c !== FALSE)
	{
		usleep(5000);
		$ret = 0;
		while (YSI_APoll($c, $ret))
		{
			usleep(25);
		}
		if ($ret !== FALSE)
		{
			return $ret;
		}
	}
	return FALSE;
}

function YSI_ACall($what, $args)
{
	global $YSI_gWrite;
	$master = 0;
	if (YSI_TryOpen())
	{
		//echo '0';
		// Construct the full messgae.
		$len = strlen($key);
		if ($len > 31)
		{
			$key = substr($key, 0, 31);
			$len = 31;
		}
		if (count($args) > 63)
		{
			return FALSE;
		}
		$stream = chr($len | 0x80) . $key . chr(count($args) | 0x40);
		foreach ($args as $data)
		{
			// Push all the arguments.  Note that "$args" should be in reverse
			// order.
			switch (gettype($data))
			{
				case 'boolean':
					if ($data) $stream .= '1';
					else $stream .= '0';
					break;
				case 'integer':
					$stream .= YSI_Num32($data) . NL;
					break;
				case 'string':
					$len = strlen($data);
					if ($len == 0)
					{
						$stream .= YSI_Num32(1) . "\1" . NL;
					}
					else
					{
						$stream .= YSI_Num32($len) . $data . NL;
					}
					break;
				default:
					return FALSE;
			}
			//$stream .= NL;
		}
		$len = strlen($stream);
		if ($len > YSI_SHARE_SIZE - 5)
		{
			return FALSE;
		}
		// The loop here is just in case some data doesn't get sent because the
		// buffer is too full.
		for ($i = 0; $i != 10; ++$i)
		{
			// Now do the sending (lock for as short a time as possible).
			YSI_Lock(YSI_SHARE);
			//echo '2';
			// Read the write index.  The header is a 2 byte master ID then a 2
			// byte index in to the write string.
			$str = shmop_read($YSI_gWrite, 2, 2);
			$idx = ord($str[0]) << 8 | ord($str[1]);
			//echo ':' . $idx . ':';
			//$len += $idx;
			if ($len + $idx <= YSI_SHARE_SIZE)
			{
				if ($priority)
				{
					// Force a send by marking the buffer as full.
					shmop_write($YSI_gWrite, $stream, $idx);
					$target = YSI_SHARE_SIZE;
				}
				else
				{
					$target = $idx + shmop_write($YSI_gWrite, $stream, $idx);
				}
				// Write the new index back.
				shmop_write($YSI_gWrite, chr($target >> 8 & 0xFF) . chr($target & 0xFF), 2);
				YSI_Lock(YSI_MASTER);
				$master = shmop_read($YSI_gWrite, 0, 2);
				YSI_Unlock(YSI_MASTER);
				//echo '3 ' . $idx . ' ' . $len . ' ';
				YSI_Unlock(YSI_SHARE);
				return array ($master, microtime(TRUE) + 0.005);
				/*// NOW WAIT FOR THE RETURN.
				usleep(5000);
				// At least 5ms as YSI will take longer just to send the reply.
				for ($i = 0; $i != 40000; ++$i)
				{
					YSI_Lock(YSI_RETURN);
					if (shmop_read($YSI_gWrite, 4, 2) === $master)
					{
						$master = shmop_read($YSI_gWrite, 6, 5);
						shmop_write($YSI_gWrite, "\0\0\0\0\0\0\0", 4);
						YSI_Unlock(YSI_RETURN);
						return YSI_Result($master);
					}
					YSI_Unlock(YSI_RETURN);
					usleep(25);
				}
				return TRUE;*/
			}
			else
			{
				$target = YSI_SHARE_SIZE;
				shmop_write($YSI_gWrite, chr($target >> 8 & 0xFF) . chr($target & 0xFF), 2);
			}
			YSI_Unlock(YSI_SHARE);
			// Could be very bad (but I hope unlikely).
			usleep(25);
		}
	}
	return FALSE;
}

function YSI_APoll($polldat, &$ret)
{
	global $YSI_gWrite;
	if ($polldat[1] > microtime(TRUE))
	{
		// Special case - long wait (five milliseconds).
		$ret = TRUE;
		return TRUE;
	}
	$ret = FALSE;
	if (YSI_TryOpen())
	{
		//usleep(5000);
		// At least 5ms as YSI will take longer just to send the reply.
		for ($i = 0; $i != 40000; ++$i)
		{
			YSI_Lock(YSI_RETURN);
			if (shmop_read($YSI_gWrite, 4, 2) === $polldat[10])
			{
				$master = shmop_read($YSI_gWrite, 6, 5);
				shmop_write($YSI_gWrite, "\0\0\0\0\0\0\0", 4);
				YSI_Unlock(YSI_RETURN);
				$ret = YSI_Result($master);
				return FALSE;
			}
			YSI_Unlock(YSI_RETURN);
			usleep(25);
		}
		return TRUE;
	}
	return FALSE;
}

function YSI_Parse($obj)
{
	if (isset($_POST['DR']))
	{
		$data = $_POST['DR'];
		// Now loop through the data and parse.
		$len = strlen($data);
		for ($i = 0; $i < $len; )
		{
			$flen = YSI_GetNum8(substr($data, $i, 1));
			++$i;
			$func = substr($data, $i, $flen);
			$i += $flen;
			$test = ord($data[$i]);
			if ($test & 0x80)
			{
				$flen = YSI_Result(substr($data, $i, 5));
				$i += 5;
				if (ord($data[$i]) == 255)
				{
					// Number.
					if (method_exists($obj, $func))
					{
						if (ord($data[$i - 1]) & 0x40)
						{
							// Float.
							$flen = unpack('fdata', pack('l', $flen));
							$obj->$func($flen['data']);
						}
						else
						{
							// Int.
							$obj->$func($flen);
						}
					}
					++$i;
				}
				else
				{
					// String.
					if (method_exists($obj, $func))
					{
						$obj->$func(substr($data, $i, $flen));
					}
					$i += $flen + 1;
				}
			}
			else if ($test & 0x40)
			{
				// Does nothing, no function support this way yet (I CBA).
			}
			else if ($test == 0x31) // '1'
			{
				if (method_exists($obj, $func))
				{
					$obj->$func(TRUE);
				}
				++$i;
			}
			else // '0'
			{
				if (method_exists($obj, $func))
				{
					$obj->$func(FALSE);
				}
				++$i;
			}
		}
		return TRUE;
	}
	return FALSE;
}

?>
