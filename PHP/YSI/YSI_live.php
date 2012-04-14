<?php

class YSI_live
{

	public $YSI_live_stats = array(array());

	public $settings;
	
	function SetSettings($set)
	{
		$this->settings = $set;
	}
	
	function Loop()
	{
		$file = $this->settings->YSI_SCRIPTFILES . '_temp_ysi_live_file_.ysi';
		if (file_exists($file))
		{
			$ini = new YSI_ini($file);
			$ini->Parse('INI_data_', $this);
			foreach ($this->YSI_live_stats[0] as $name => $value)
			{
				echo $name . ' : ' . $value . "\n";
			}
			@unlink($file);
		}
	}
	
	function INIData($tag, $identifier, $text)
	{
		//echo $tag . ' ' . $identifier . ' ' . $text . "\n";
		switch ($tag)
		{
			case 'player_data':
				$end = strpos($identifier, '_');
				$this->YSI_live_stats[substr($identifier, $end + 1)][substr($identifier, 0, $end)] = $text;
				break;
			case 'connections':
				$player = substr($identifier, 5);
				switch (substr($identifier, 0, 4))
				{
					case 'name':
						$this->YSI_live_stats[$player]['name'] = $text;
						break;
					case 'conn':
						if (!$this->YSI_live_stats[$player]['in'] && $this->YSI_live_stats[$player]['conn'] < $text)
						{
							$this->YSI_live_stats[$player]['conn'] = $text;
							$this->YSI_live_stats[$player]['in'] = 1;
						}
						break;
				}
				break;
			case 'disconnections':
				$player = substr($identifier, 4);
				switch (substr($identifier, 0, 3))
				{
					case 'res':
						$this->YSI_live_stats[$player]['disres'] = $text;
						break;
					case 'dis':
						if ($this->YSI_live_stats[$player]['in'] && $this->YSI_live_stats[$player]['conn'] < $text)
						{
							$this->YSI_live_stats[$player]['conn'] = $text;
							$this->YSI_live_stats[$player]['in'] = 0;
						}
						break;
				}
				break;
		}
	}
	
	function PlayerData($identifier, $text)
	{
		$end = strpos($identifier, '_');
		$player = intval(substr($identifier, $end + 1));
		$name = substr($identifier, 0, $end);
		if (!strncmp($name, 'weapon', 6))
		{
			$this->YSI_live_stats[$player][$name] = intval($text);
		}
		else if (!strncmp($name, 'ammo', 4))
		{
		}
		else if (!strncmp($name, 'prop', 4))
		{
		}
		if (!strncmp($name, 'sweap', 5))
		{
		}
		else if (!strncmp($name, 'sammo', 5))
		{
		}
		else
		{
			$this->YSI_live_stats[$player][$name] = $text;
			/*switch ($name)
			{
				case 'health':
				case 'armour':
				case 'x':
				case 'y':
				case 'z':
				case 'a':
					$this->YSI_live_stats[$player][$name] = floatval($text);
					break;
				default:
					$this->YSI_live_stats[$player][$name] = intval($text);
					break;
			}*/
		}
	}
}

?>