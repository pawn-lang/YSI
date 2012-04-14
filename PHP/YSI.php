<?php
	
	include 'YSI/YSI_settings.php';
	include 'YSI/YSI_ini.php';
	$set = new YSI_settings('ysi');

//	$set->YSI_settings;
//	echo $set->YSI_SAMP_SERVER_PATH;
	
	include 'YSI/YSI_output.php';



	if ($set->YSI_RECORD_LIVE) include 'YSI/YSI_live.php';
	if ($set->YSI_ACCESS_USERS) include 'YSI/YSI_users.php';	
	
	$live = new YSI_live;
	
	$live->SetSettings($set);
	
	while (1)
	{
		$live->Loop();
		usleep(10000);
	}
	
	
	
?>
