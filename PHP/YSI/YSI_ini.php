<?php
/*
$ini = new YSI_ini;

$ini->Open('..\Games\San Andreas (Original)\GTA San Andreas\samp\YSI\scriptfiles\woo.txt');
$ini->SetTag('hmm');
$ini->Write('er', 2);
$ini->Write('we', 6);
$ini->Write('moo', 7);
$ini->SetTag('core');
$ini->Write('fjweoifj', 're');
$ini->SetTag('yeah');
$ini->Write('yeah', '');
$ini->Close();
*/
class YSI_ini
{
	private $writefile;
	private $tagpointer;
	private $tagcount;
	private $buffer;
	
	function Parse($file, $cclass, $funcform)
	{
		$handle = @fopen($file, 'r');
		if ($handle)
		{
			$function = false;
			while (!feof($handle))
			{
				$line = fgets($handle);
				if ($line !== false)
				{
					$comment = strpos($line, ';');
					if ($comment !== false) $line = substr($line, 0, $comment);
					$line = trim($line);
					$comment = strlen($line);
					if ($line{0} == '[' && $line{$comment - 1} == ']')
					{
						$function = sprintf($funcform, substr($line, 1, $comment - 2), $file);
					}
					else if ($function != false && method_exists($cclass, $function) && ord($line{0}))
					{
						$i = 0;
						do
						{
							$j = ord($line{$i++});
						}
						while ($j > 32 && $j != 61 && $i <= $comment);
						if ($i > $comment) $cclass->$function($line, '');
						else
						{
							$k = $i - 1;
							do
							{
								$j = ord($line{$i++});
							}
							while (($j <= 32 || $j == 61) && $i <= $comment);
							if ($i > $comment) $cclass->$function(substr($line, 0, $k), '');
							else $cclass->$function(substr($line, 0, $k), substr($line, $i - 1));
						}
					}
				}
			}
			fclose($handle);
		}
	}
	
	function Open($file)
	{
		$this->writefile = $file;
		$this->tagpointer = 0;
		$this->tagcount = 0;
		$this->buffer = array ();
	}
	
	function SetTag($tag)
	{
		$pointer = $this->tagcount;
		for ($i = 0; $i < $pointer; $i++)
		{
			if (!strcmp($tag, $this->buffer[$i]['tag']))
			{
				$this->tagpointer = $i;
				return;
			}
		}
		$this->buffer[] = array ('tag' => $tag, 'idx' => 0, 'dat' => array (), 'r' => 0);
		$this->tagpointer = $this->tagcount;
		$this->tagcount++;
	}
	
	function Write($name, $data)
	{
		$pointer = $this->tagpointer;
		$this->buffer[$pointer]['dat'][] = array ('nam' => $name, 'dat' => $data, 'r' => 0);
		$this->buffer[$pointer]['idx']++;
	}
	
	function Close()
	{
		$handle = @fopen($this->writefile, 'r');
		$write = @fopen('_temp_ysi_php_file_.ysi', 'w');
		if ($write)
		{
			$nl = false;
			if ($handle)
			{
				$function = false;
				$tag = -1;
				while (!feof($handle))
				{
					$comline = '';
					$line = fgets($handle);
					if ($line !== false)
					{
						$comment = strpos($line, ';');
						if ($comment !== false)
						{
							$comline = trim(substr($line, $comment + 1));
							$line = substr($line, 0, $comment);
						}
						$line = trim($line);
						$comment = strlen($line);
						if ($line{0} == '[' && $line{$comment - 1} == ']')
						{
							if ($tag != -1)
							{
								$count = $this->buffer[$tag]['idx'];
								for ($i = 0; $i < $count; $i++)
								{
									if (!$this->buffer[$tag]['dat'][$i]['r'])
									{
										fwrite($write, $this->buffer[$tag]['dat'][$i]['nam'] . ' = ' . $this->buffer[$tag]['dat'][$i]['dat'] . "\r\n");
										$this->buffer[$tag]['dat'][$i]['r'] = 1;
									}
								}
								$this->buffer[$tag]['r'] = 1;
							}
							$function = substr($line, 1, $comment - 2);
							if ($nl) fwrite($write, "\r\n");
							else $nl = true;
							fwrite($write, $line);
							if ($comline) fwrite($write, ' ; ' . $comline);
							fwrite($write, "\r\n");
							$tag = -1;
							$count = $this->tagcount;
							for ($i = 0; $i < $count; $i++)
							{
								if (!strcmp($function, $this->buffer[$i]['tag']))
								{
									$tag = $i;
									break;
								}
							}
						}
						else if ($function != false && ord($line{0}))
						{
							if ($tag == -1)
							{
								fwrite($write, $line);
								if ($comline) fwrite($write, ' ; ' . $comline);
								fwrite($write, "\r\n");
							}
							else
							{
								$i = 0;
								do
								{
									$j = ord($line{$i++});
								}
								while ($j > 32 && $j != 61 && $i <= $comment);
								if ($i <= $comment) $i--;
								$name = substr($line, 0, $i);
								$count = $this->buffer[$tag]['idx'];
								for ($k = 0; $k < $count; $k++)
								{
									if (!strcmp($name, $this->buffer[$tag]['dat'][$k]['nam']))
									{
										fwrite($write, $name . ' = ' . $this->buffer[$tag]['dat'][$k]['dat']);
										$this->buffer[$tag]['dat'][$k]['r'] = 1;
										break;
									}
								}
								if ($k == $count) fwrite($write, $line);
								if ($comline) fwrite($write, ' ; ' . $comline);
								fwrite($write, "\r\n");
							}
						}
					}
				}
				if ($tag != -1)
				{
					$count = $this->buffer[$tag]['idx'];
					for ($i = 0; $i < $count; $i++)
					{
						if (!$this->buffer[$tag]['dat'][$i]['r'])
						{
							fwrite($write, $this->buffer[$tag]['dat'][$i]['nam'] . ' = ' . $this->buffer[$tag]['dat'][$i]['dat'] . "\r\n");
							$this->buffer[$tag]['dat'][$i]['r'] = 1;
						}
					}
					$this->buffer[$tag]['r'] = 1;
				}
				fclose($handle);
			}
			$tagc = $this->tagcount;
			for ($tag = 0; $tag < $tagc; $tag++)
			{
				if (!$this->buffer[$tag]['r'])
				{
					if ($nl) fwrite($write, "\r\n");
					else $nl = true;
					fwrite($write, '[' . $this->buffer[$tag]['tag'] . ']' . "\r\n");
					$count = $this->buffer[$tag]['idx'];
					for ($i = 0; $i < $count; $i++)
					{
						if (!$this->buffer[$tag]['dat'][$i]['r'])
						{
							fwrite($write, $this->buffer[$tag]['dat'][$i]['nam']);
							if ($this->buffer[$tag]['dat'][$i]['dat']) fwrite($write, ' = ' . $this->buffer[$tag]['dat'][$i]['dat']);
							fwrite($write, "\r\n");
							$this->buffer[$tag]['dat'][$i]['r'] = 1;
						}
					}
				}
			}
			fclose($write);
			@unlink($this->writefile);
			rename('_temp_ysi_php_file_.ysi', $this->writefile);
		}
	}
}

?>
