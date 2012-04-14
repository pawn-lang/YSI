<?php

include('./YSI.php');

$YSI = new YSI_Data();

YSI_Parse($YSI);

class YSI_Data
{
	function First($value)
	{
		echo 'The data is ' . $value;
	}
}
