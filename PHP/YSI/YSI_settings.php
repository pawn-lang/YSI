<?php
	
class YSI_settings
{
	/*global $YSI_SAMP_SERVER_PATH;
	global $YSI_MYSQL_HOSTNAME;
	global $YSI_MYSQL_USERNAME;
	global $YSI_MYSQL_PASSWORD;
	global $YSI_RECORD_LIVE;
	global $YSI_ACCESS_USERS;
	global $YSI_SCRIPTFILES;*/
	
	// Edit below this line
	// Define you server settings here
	
	public $YSI_SAMP_SERVER_PATH = 'C:/Program Files/Games/San Andreas (Original)/GTA San Andreas/samp/YSI';
	public $YSI_MYSQL_HOSTNAME = 'localhost';
	public $YSI_MYSQL_USERNAME = 'admin';
	public $YSI_MYSQL_PASSWORD = 'password';
	
	public $YSI_RECORD_LIVE = true;
	public $YSI_ACCESS_USERS = true;
	
	// DO NOT edit below this line
	
	public $YSI_SCRIPTFILES;

	function YSI_settings($ysi)
	{
		$this->YSI_SCRIPTFILES = rtrim($this->YSI_SAMP_SERVER_PATH, '/') . '/scriptfiles/' . trim($ysi, '/') . '/';
	}
	
}

?>