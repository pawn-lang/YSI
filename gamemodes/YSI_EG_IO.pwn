// This MUST go ABOVE "#include <YSI>"
//#define FILTERSCRIPT

#include <YSI>

main()
{
	print("\n------------------------------");
	print(" Language and command example ");
	print("------------------------------\n");
}

// Slightly unusual syntax - this function DOES go here
// This tells the system to load all text from "eg1_entries" parts of files
Text_RegisterTag(eg1_entries);

// Define the commands

// Long syntax version
forward ycmd_kill(playerid, params[], help);
public ycmd_kill(playerid, params[], help)
{
	if (help)
	{
		// Send the message defined as "EG1_KILL_HELP" to the player
		// Use the data defined in the language file to send it to them natively
		Text_Send(playerid, "EG1_KILL_HELP");
	}
	else
	{
		// Kill the player
		SetPlayerHealth(playerid, 0.0);
	}
	return 1;
}

// Short syntax version
Command_(drop)
{
	if (help)
	{
		// The player typed "/help drop" not "/drop"
		Text_Send(playerid, "EG1_DROP_HELP_0");
		Text_Send(playerid, "EG1_DROP_HELP_1");
	}
	else
	{
		new
			Float:x,
			Float:y,
			Float:z;
		
		// Get the player pos
		GetPlayerPos(playerid, x, y, z);
		z += 1000.0;
		
		// Format a message and send it to the player
		Text_SendFormat(playerid, "EG1_DROP_MSG_0", z);
		
		// Send a regular message
		Text_Send(playerid, "EG1_DROP_MSG_1");
		
		// Send an OPTIMISED message to all players
		// This is sent to each person in their own respective language
		Text_SendToAllFormat("EG1_DROP_SPLAT", ReturnPlayerName(playerid));
		
		// Teleport the player
		SetPlayerPos(playerid, x, y, z);
	}
	return 1;
}

public OnGameModeInit()
{
	//  Set up languages
	// ==================
	
	// Add source files
	Langs_AddFile("core", "YSI");
	Langs_AddFile("eg1"); // Our own file of text
	
	// Add selectable/loadable languages
	// First one here is the default language
	// Players can change their language with "/language"
	Langs_AddLanguage("EN", "English");
	Langs_AddLanguage("NL", "Nederlands");
	
	// The code above will load text from 4 files if they exist:
	//
	//  YSI/core.EN
	//  YSI/core.NL
	//  eg1.EN
	//  eg1.NL
	//
	// It will also load format information from two files if they exist:
	//
	//  YSI/core_LANG_DATA.YSI
	//  eg1_LANG_DATA.YSI
	//
	// Formatting information can be read about on the YSI wiki
	
	//  Set up commands
	// =================
	
	// Add commands
	ycmd("kill");
	ycmd("drop");
	
	// Set the command prefix
	Command_SetPrefix("mc");
	// Enable prefix processing (or it'll be ignored)
	Command_UsePrefix(true);
	
	// The commands are now "/mckill" and "/mcdrop"
	
	// Set the prefix space
	Command_UseSpace(true);
	
	// The commands are now "/mc kill" and "/mc drop"
	
	// Rename "/drop" - Note that you can have spaces in command renames
	Command_SetAltName("drop", "big fall");
	// Enable alt-name processing (or it'll be ignored)
	Command_UseAltNames(true);

	// The commands are now "/mc kill" and "/mc big fall"
	
	// Disable the prefix
	Command_UsePrefix(false);
	
	// The commands are now "/kill" and "/big fall"
	
	//  Other stuff
	// =============
	
	// Add a class
	Class_Add(104, 1400.5906, 2225.6960, 11.0234, 0.0, WEAPON_COLT45, 100, WEAPON_SAWEDOFF, 20, WEAPON_MINIGUN, 1000, WEAPON_ARMOUR, 1);
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	// Borrowed from LVDM
 	SetPlayerInterior(playerid, 14);
	SetPlayerPos(playerid, 258.4893, -41.4008, 1002.0234);
	SetPlayerFacingAngle(playerid, 270.0);
	SetPlayerCameraPos(playerid, 256.0815, -43.0475, 1004.0234);
	SetPlayerCameraLookAt(playerid, 258.4893, -41.4008, 1002.0234);
	return 1;
}

public OnPlayerSpawn(playerid)
{
	SetPlayerInterior(playerid, 0);
	return 1;
}

