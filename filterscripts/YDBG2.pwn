/**
*
*       YDBG.pwn
*       2008 (c) LexSoftware Foundation, Alexander de Jong (mrdejong)
*       2008 (c) Alex "Y_Less" cole
*
*       Version 1.0.0 BETA
*
*       YDBG comes with two lang files English and Dutch:
*       YDBG.en
*       YDBG.nl
*       YDBG_format.YSI
*
*       All the files can be found in:
*       scriptfiles/YSI/
*
*
*       This file need to make all the property's, ammunation's, bank's.
*       This file can save also Area's and much more. With this file you can create your server
*       In a minute. It works allmost automatically that means that you don't need to
*       use much commands. No it's simple thinking, simple use thought
*
*       This file saves all information in to an xml file "scriptfiles/YSI/YDBG" there you can find everything you need.
*
*       This file loads every property's, ammunation's, bank's all what you want automatically.
*
*       This file also uses an administration system, thats linked to the user system of YSI.
*       It's not really an adminisrator system, but i call him "BUILDERS" you can give people some rights
*       and they can use only the commands they have rights to :) simple?
*
*
*       I wish you all good luck with it. And keep SIMPLE THINKING if not you make it your self so dificult!
*
*       cya arround homi's
*
*       Alexander de Jong (mrdejong).
*
*       This file is copyrighted and protected by the GNU General Public License
*       You can do all you want in this file, that will say if you don't like the working of something, easely edit it to your hand
*
*       License:
*
*       This program is free software: you can redistribute it and/or modify
*	    it under the terms of the GNU General Public License as published by
*	    the Free Software Foundation, either version 3 of the License, or
*	    (at your option) any later version.
*
*	    This program is distributed in the hope that it will be useful,
*	    but WITHOUT ANY WARRANTY; without even the implied warranty of
*	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*		GNU General Public License for more details.
*
*	    You should have received a copy of the GNU General Public License
*	    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*       Complete license: (please read them)
*
*       http://www.gnu.org/licenses/gpl.html
*
*       If you don't agree with this license please don't use IT!
*
*/

// We are building a filterscript, that means we need to let know the system that it is a filterscript. So it is a child of the gamemode.
#define FILTERSCRIPT

#define _DEBUG 5

// Setup all the defines we need:

/**
*   Options
*/
	// Load options

// #define NO_VEHICLE_LOAD
// #define NO_PROPERTYS_LOAD
// #define NO_MONEYPOINT_LOAD
// #define NO_BANK_LOAD

#define MAX_XML_FILES 30

#include <YSI>

enum binfo
{
	blevel,
	Float:spos_x,
	Float:spos_y,
	Float:spos_z,
	Float:spos_a,
	sinterior,
}

new userinfo[MAX_PLAYERS][binfo];
new userLoged[MAX_PLAYERS] = {-1, ...};

// Menu var's
new Menu:propertyMenu;
new Menu:vehicleSpawn;
new Menu:saveMenu;
new Menu:propertyOptionsMenu;

new propertyOption = 0;
new SaveOption = 0;
new MoneyOption = 0;
new bankOption = 0;

new	popos[256];
new	pnames[256];
new	setup1[256];
new	setup2[256];

// vars for the command permissions
new spos;
new lpos;
new mkprop;
new giveright;
new veh;
new savepos;
new c_menu;

new builder;
new superbuilder;

/**
* forwards
*/
forward ycmd_spos(playerid, params[], help);
forward ycmd_lpos(playerid, params[], help);
forward ycmd_kill(playerid, params[], help);
forward ycmd_mkprop(playerid, params[], help);
forward ycmd_giveright(playerid, params[], help);
forward ycmd_gr(playerid, params[], help);
forward ycmd_veh(playerid, params[], help);
forward ycmd_menu(playerid, params[], help);
forward ycmd_savepos(playerid, params[], help);
forward ycmd_explain(playerid, params[], help);
forward ycmd_hexplain(playerid, params[], help);
forward ycmd_bgmx(playerid, params[], help);

forward MkProp(playerid, prop1[], prop2[], prop3[], prop4[]);
forward SpawnVehicle(playerid, vehicleid);
forward LoadCars();
forward LoadProp();
forward Load_MoneyPoint();
forward LoadBank();

forward LoginDat_YDBG(playerid, identifier[], text[]);

/**
* Register tags for the lang files
*/
Text_RegisterTag(info);
Text_RegisterTag(complete);
Text_RegisterTag(error);

Script_OnFilterScriptInit()
{
	print("\n------------------------------------");
	print(" YDBG Ysi DeBuG tool.");
	print(" 2008 (c) LexSoftware Foundation, Alexander de Jong");
	print(" 2008 (c) Alex \"Y_Less\" Cole");
	print(" Alex \"Y_Less\" Cole is also the founder of YSI");
	print("------------------------------------\n");

	// Set groups
	builder = Group_Create("Builder");
	superbuilder = Group_Create("Superbuilder");

    load_functions();
	
	Langs_AddLanguage("EN", "English");
    Langs_AddLanguage("NL", "Nederlands");
	Langs_AddFile("core", "YSI");
	Langs_AddFile("YDBG", "YSI");

	// ** Create the menu's
	/// Make the propertyOptionsMenu
	propertyOptionsMenu = CreateMenu("Property options", 2, 150.0, 150.0, 170.0, 200.0);
	AddMenuItem(propertyOptionsMenu, 0, "1. Bussinus"); // 0
	AddMenuItem(propertyOptionsMenu, 0, "2. Bank"); // 1
	AddMenuItem(propertyOptionsMenu, 0, "3. Ammunation"); // 2
	AddMenuItem(propertyOptionsMenu, 0, "4. Money area"); // 3
	AddMenuItem(propertyOptionsMenu, 0, "5. Money point"); // 4
	AddMenuItem(propertyOptionsMenu, 0, "6. Teleport"); // 5
	AddMenuItem(propertyOptionsMenu, 0, "7. Forbidden Area"); // 6
	AddMenuItem(propertyOptionsMenu, 0, "8. Houses"); // 7
	AddMenuItem(propertyOptionsMenu, 0, "9. Cancel"); // 8
	
	AddMenuItem(propertyOptionsMenu, 1, "CreateProperty");
	AddMenuItem(propertyOptionsMenu, 1, "CreateBank");
	AddMenuItem(propertyOptionsMenu, 1, "CreateAmmunation");
	AddMenuItem(propertyOptionsMenu, 1, "CreateMoneyArea");
	AddMenuItem(propertyOptionsMenu, 1, "CreateMoneyPoint");
	AddMenuItem(propertyOptionsMenu, 1, "CreateTeleport");
	AddMenuItem(propertyOptionsMenu, 1, "CreateForbiddenArea");
	
	/// Make property menu:
	propertyMenu = CreateMenu("Property builder", 1, 10.0, 150.0, 225.0);
	AddMenuItem(propertyMenu, 0, "1. Make property");
	AddMenuItem(propertyMenu, 0, "2. Give a name");
	AddMenuItem(propertyMenu, 0, "3. Setup 1");
	AddMenuItem(propertyMenu, 0, "4. Setup 2");
	AddMenuItem(propertyMenu, 0, "5. Cancel");
	
	// /savep menu
	saveMenu = CreateMenu("Save options", 1, 200.0, 150.0, 200.0);
	AddMenuItem(saveMenu, 0, "1. Save vehicles");
	AddMenuItem(saveMenu, 0, "2. Save custom positions");
	AddMenuItem(saveMenu, 0, "3. Save pickups");
	AddMenuItem(saveMenu, 0, "4. Save arrea's");
	AddMenuItem(saveMenu, 0, "5. Cancel");
	
	/**
	* Make a vehicle menu;
	* This is used if the builder doesn't have add a vulue when typing /veh
	*/
	vehicleSpawn = CreateMenu("Vehicle Menu", 2, 200.0, 100.0, 100.0, 125.0);
	AddMenuItem(vehicleSpawn, 0, "521 Bike :"); // FCR-900
	AddMenuItem(vehicleSpawn, 0, "522 Bike :"); // NRG-500
	AddMenuItem(vehicleSpawn, 0, "463 Bike :"); // Freeway
	AddMenuItem(vehicleSpawn, 0, "541 Car :"); // Bullet
	AddMenuItem(vehicleSpawn, 0, "411 Car :"); // Invernus
 	AddMenuItem(vehicleSpawn, 0, "482 Bus :"); // Buritto
 	AddMenuItem(vehicleSpawn, 0, "487 Heli :"); // Maverick
 	
 	AddMenuItem(vehicleSpawn, 1, "FCR-900");
 	AddMenuItem(vehicleSpawn, 1, "NRG-500");
 	AddMenuItem(vehicleSpawn, 1, "Freeway");
 	AddMenuItem(vehicleSpawn, 1, "Bullet");
 	AddMenuItem(vehicleSpawn, 1, "Invernus");
 	AddMenuItem(vehicleSpawn, 1, "Buritto");
 	AddMenuItem(vehicleSpawn, 1, "Maverick");
 	
 	/**
 	* Load xml init
 	*/
	load_xml_init();

	return 1;
}

/**
* This command is only for testing
*/

public ycmd_menu(playerid, params[], help)
{
	#pragma unused params, help
	ShowMenu(propertyOptionsMenu, playerid);
	
	return 1;
}

Script_OnFilterScriptExit()
{
	return 1;
}

Script_OnGameModeInit()
{
	printf("call OGMI");
	return 1;
}

Script_OnGameModeExit()
{
    Master_@Master();
	return 1;
}

Script_OnPlayerRequestClass(playerid, classid)
{
	return 1;
}

Script_OnPlayerRequestSpawnEx(playerid, classid)
{
	return 1;
}

Script_OnPlayerConnect(playerid)
{
	Command_SetPlayerUseByID(spos, playerid, 0);
	Command_SetPlayerUseByID(lpos, playerid, 0);
	Command_SetPlayerUseByID(mkprop, playerid, 0);
	Command_SetPlayerUseByID(giveright, playerid, 0);
	Command_SetPlayerUseByID(veh, playerid, 0);
	Command_SetPlayerUseByID(savepos, playerid, 0);
	Command_SetPlayerUseByID(c_menu, playerid, 0);

	return 1;
}

Script_OnPlayerDisconnect(playerid, reason)
{
	#pragma unused reason, playerid
	return 1;
}

Script_OnPlayerSpawn(playerid)
{
	return 1;
}

Script_OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

Script_OnVehicleSpawn(vehicleid)
{
	return 1;
}

Script_OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

Script_OnPlayerText(playerid, text[])
{
 	if(propertyOption >= 1)
	{
	    new str[256]; // This is for the format lines

   	    switch(propertyOption)
	    {
	        case 1:
	        {
	            if(!FindText(text, "yes", 3))
	            {
          		    new
						Float:x,
						Float:y,
						Float:z;
					GetPlayerPos(playerid, x, y, z);

		            format(str, sizeof(str), "%f, %f, %f", x, y, z);
		            popos = str;

		            Text_Send(playerid, "YDBG_PROP_ADD_1");
		            
					propertyOption = 0;

		            return 0;
				}
			}
			case 2:
			{
				new name[60];
				if(GetText(text, 60, name))
				{
					pnames = name;
					
					Text_Send(playerid, "YDBG_PROP_ADD_2");
					
					propertyOption = 0;
				    
				    return 0;
				}
			}
			case 3:
			{
			    new opt[125];
			    if(GetText(text, 125, opt))
			    {
					setup1 = opt;
					
					Text_Send(playerid, "YDBG_PROP_ADD_3");
					
					propertyOption = 0;
					
					return 0;
				}
			}
			case 4:
			{
			    new opt2[125];
			    if(GetText(text, 125, opt2))
			    {
					setup2 = opt2;
					
					Text_Send(playerid, "YDBG_PROP_ADD_4");
					Text_Send(playerid, "YDBG_PROP_ADD_5");
					
					propertyOption = 522;

					return 0;
				}
			}
		}
	}
	
	if(!FindText(text, "save", 4) && propertyOption == 522)
	{
	    propertyOption = 0;
	    MkProp(playerid, popos, pnames, setup1, setup2);
	    return 0;
	}
	
	if(MoneyOption >= 1)
	{
	    switch(MoneyOption)
	    {
	        case 1:
	        {
	            if(!FindText(text, "yes", 4))
	            {
					Text_Send(playerid, "YDBG_MP_INFO_1.1");
	                Text_Send(playerid, "YDBG_MP_INFO_1.2");
	                Text_Send(playerid, "YDBG_MP_INFO_1.3");
	                Text_Send(playerid, "YDBG_MP_INFO_1.4");
	                Text_Send(playerid, "YDBG_MP_INFO_1.5");
	                Text_Send(playerid, "YDBG_MP_INFO_1.6");
	                Text_Send(playerid, "YDBG_MP_INFO_1.7");
	                Text_Send(playerid, "YDBG_MP_INFO_1.8");
	                MoneyOption = 2;
	                return 0;
				}
			}
			
			case 2:
			{
			    new options[125];
			    new str[256];
			    GetText(text, 125, options);
			    
			    new xmlMpoint = XML_AddItem("moneypoint");
			    new Float:x, Float:y, Float:z;
			    
			    GetPlayerPos(playerid, x, y, z);
			    
			    XML_AddParameter(xmlMpoint, "options", options);

				format(str, sizeof(str), "%f, %f, %f", x, y, z);
				XML_AddParameter(xmlMpoint, "position", str);
				
				XML_WriteItem("YSI/YDBG/moneypoint.xml", xmlMpoint);
				
				Text_Send(playerid, "YDBG_MP_ADD");
				MoneyOption = 255;
				return 0;
			}
		}
	}
	
	if(bankOption >= 1)
	{
	    switch(bankOption)
	    {
	        case 1:
	        {
	            if(!FindText(text, "yes", 3))
	            {
	                Text_Send(playerid, "YDBG_BANK_INFO_1");
	                Text_Send(playerid, "YDBG_BANK_INFO_2");
	                bankOption = 2;
	                
	                return 0;
				}
			}
			case 2:
			{
			    new name[125];
			    new str[256];
			    
			    GetText(text, 125, name);
			    
			    new xmlBank = XML_AddItem("bank");
			    
			    new Float:x, Float:y, Float:z;
			    GetPlayerPos(playerid, x, y, z);
			    
			    format(str, sizeof(str), "%f, %f, %f", x, y, z);
			    
			    XML_AddParameter(xmlBank, "position", str);
			    XML_AddParameter(xmlBank, "name", name);
			    
			    XML_WriteItem("YSI/YDBG/bank.xml", xmlBank);
			    
			    Text_Send(playerid, "YDBG_BANK_ADD");
			    
				bankOption = 255;
				return 0;
			}
		}
	}

	return 1;
}

Script_OnPlayerPrivmsg(playerid, recieverid, text[])
{
	return 1;
}

Script_OnPlayerCommandText(playerid, cmdtext[])
{
	return Command_Process(playerid, cmdtext);
}

Script_OnPlayerInfoChange(playerid)
{
	return 1;
}

Script_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

Script_OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

Script_OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

Script_OnPlayerEnterCheckpointEx(playerid, cpid)
{
	return 1;
}

Script_OnPlayerLeaveCheckpointEx(playerid, cpid)
{
	return 1;
}

Script_OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

Script_OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

Script_OnRconCommand(cmd[])
{
	return 1;
}

Script_OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

Script_OnPlayerSelectedMenuRow(playerid, row)
{
	new Menu:PlayerMenu = GetPlayerMenu(playerid);
	
	// Property Option menu
	if(PlayerMenu == propertyOptionsMenu)
	{
	    switch(row)
	    {
	        case 0:
	        {
	            ShowMenu(propertyMenu, playerid);
			}
			case 1:
			{
			    Text_Send(playerid, "YDBG_BANK_INFO_3");
			    Text_Send(playerid, "YDBG_BANK_INFO_4");
			    bankOption = 1;
			}
			case 4:
			{
			    MoneyOption = 1;
			    Text_Send(playerid, "YDBG_MP_INFO_2.1");
			    Text_Send(playerid, "YDBG_MP_INFO_2.2");
			}
			case 7:
			{
			    new Float:x, Float:y, Float:z;
			    GetPlayerPos(playerid, x, y, z);
			    
			    new xmlHouse = XML_AddItem("house");
			    new str[256];
			    format(str, sizeof(str), "%f, %f, %f", x, y, z);
			    XML_AddParameter(xmlHouse, "position", str);
			    
			    XML_WriteItem("propertys/houses.xml", xmlHouse);
			}
			
			default:
			{
			    Text_Send(playerid, "YDBG_MENU_NOT_EXIST");
			}
		}
		TogglePlayerControllable(playerid, 1);
	}
	
	// PorpertyMenu
	if(PlayerMenu == propertyMenu)
	{
	    switch(row)
		{
		    case 0:
		    {
		        Text_Send(playerid, "YDBG_PROP_INFO_1");
		        Text_Send(playerid, "YDBG_PROP_INFO_2");
		        Text_Send(playerid, "YDBG_PROP_INFO_3");
		        propertyOption = 1;
			}
			case 1:
			{
			    Text_Send(playerid, "YDBG_PROP_INFO_4");
			    propertyOption = 2;
			}
			case 2:
			{
			    Text_Send(playerid, "YDBG_PROP_INFO_5");
			    Text_Send(playerid, "YDBG_PROP_INFO_6");
			    Text_Send(playerid, "YDBG_PROP_INFO_7");
			    Text_Send(playerid, "YDBG_PROP_INFO_8");
			    Text_Send(playerid, "YDBG_PROP_INFO_9");
			    Text_Send(playerid, "YDBG_PROP_INFO_10");
			    Text_Send(playerid, "YDBG_PROP_INFO_11");
			    Text_Send(playerid, "YDBG_PROP_INFO_12");
			    propertyOption = 3;
			}
			case 3:
			{
			    Text_Send(playerid, "YDBG_PROP_INFO_13");
			    Text_Send(playerid, "YDBG_PROP_INFO_14");
                Text_Send(playerid, "YDBG_PROP_INFO_15");
                Text_Send(playerid, "YDBG_PROP_INFO_16");
                Text_Send(playerid, "YDBG_PROP_INFO_17");
                Text_Send(playerid, "YDBG_PROP_INFO_18");
                Text_Send(playerid, "YDBG_PROP_INFO_19");
                Text_Send(playerid, "YDBG_PROP_INFO_20");
                Text_Send(playerid, "YDBG_PROP_INFO_21");
                Text_Send(playerid, "YDBG_PROP_INFO_22");
                propertyOption = 4;
			}
		}
		TogglePlayerControllable(playerid, 1);
	}

	// Vehicle menu
 	if(PlayerMenu == vehicleSpawn)
 	{
 	    switch(row)
		{
			case 0:
			{
			    SpawnVehicle(playerid, 521);
			}
			
			case 1:
			{
			    SpawnVehicle(playerid, 522);
			}
			
			case 2:
			{
			    SpawnVehicle(playerid, 463);
			}

			case 3:
			{
			    SpawnVehicle(playerid, 541);
			}
			
			case 4:
			{
			    SpawnVehicle(playerid, 411);
			}
			
			case 5:
			{
			    SpawnVehicle(playerid, 482);
			}
			
			case 6:
			{
			    SpawnVehicle(playerid, 487);
			}
		}
		TogglePlayerControllable(playerid, 1);
	}
	
	if(PlayerMenu == saveMenu)
	{
	    switch(row)
	    {
	        case 0:
	        {
	            SaveOption = 1;
	            SendClientMessage(playerid, 0x00FF00AA, "Gebruik nu /savepos om de auto's op te slaan");
			}
			
			case 1:
			{
				SaveOption = 2;
			    SendClientMessage(playerid, 0x00FF00AA, "Costum position selected use /savepos");
			}
			
			case 2:
			{
			    SaveOption = 3;
			    SendClientMessage(playerid, 0x00FF00AA, "Pickups gebruik nu /savepos [pickupid]");
			}
			
			case 3:
			{
			    SaveOption = 4;
			    SendClientMessage(playerid, 0x00FF00AA, "DEZE OPTIE IS NOG NIET INGEBOUWD");
			}
			
			case 4:
			{
				HideMenuForPlayer(saveMenu, playerid);
			}
		}
		TogglePlayerControllable(playerid, 1);
	}
	return 1;
}

Script_OnPlayerExitedMenu(playerid)
{
	TogglePlayerControllable(playerid, 1);
	return 1;
}

Script_OnVehicleMod(vehicleid, componentid)
{
	return 1;
}

Script_OnVehiclePaintjob(vehicleid, paintjobid)
{
	return 1;
}

Script_OnVehicleRespray(vehicleid, color1, color2)
{
	return 1;
}

Script_OnPlayerLogin(playerid, yid)
{
	userLoged[playerid] = 1;
	return 1;
}

Script_OnPlayerLogout(playerid, yid)
{
	Debug_Print_1("Script_OnPlayerLogout");
    userLoged[playerid] = 0;
    
    if(Group_HasPlayer(builder, playerid))
	{
	    Group_RemovePlayer(builder, playerid);
	}

	if(Group_HasPlayer(superbuilder, playerid))
	{
	    Group_RemovePlayer(superbuilder, playerid);
	}

	new playersIp[20];
	GetPlayerIp(playerid, playersIp, 20);
    // Write the user information
	Player_SetTag("YDBG");
	Player_WriteInt("blevel", userinfo[playerid][blevel]);
	Player_WriteFloat("spos_x", userinfo[playerid][spos_x]);
	Player_WriteFloat("spos_y", userinfo[playerid][spos_y]);
	Player_WriteFloat("spos_z", userinfo[playerid][spos_z]);
	Player_WriteFloat("spos_a", userinfo[playerid][spos_a]);
	Player_WriteInt("sinterior", userinfo[playerid][sinterior]);

	return 1;
}

Script_OnPlayerEnterArea(playerid, areaid)
{
	return 1;
}

Script_OnPlayerLeaveArea(playerid, areaid)
{
	return 1;
}

Script_OnRaceEnd(raceid)
{
	return 1;
}

Script_OnPlayerExitRace(playerid, raceid)
{
	return 1;
}

Script_OnPlayerFinishRace(playerid, raceid, position, prize, time)
{
	return 1;
}

Script_OnDynamicObjectMoved(objectid)
{
	return 1;
}

Script_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

Script_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

Script_OnPlayerKeyPress(playerid, key)
{
	return 1;
}

Script_OnPlayerKeyRelease(playerid, key)
{
	return 1;
}

Script_OnGangWarCapture(zoneid, attacker, defender)
{
	return 1;
}

Script_OnGangWarStart(zoneid, attacker, defender)
{
	return 1;
}

Script_OnGangWarDefend(zoneid, attacker, defender)
{
	return 1;
}

/**
* Commands
*/
public ycmd_kill(playerid, params[], help)
{
	#pragma unused help, params
	SetPlayerHealth(playerid, 0.0);
	return 1;
}

public ycmd_spos(playerid, params[], help)
{
	#pragma unused help, params
	new Float:x, Float:y, Float:z, Float:a;

	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);
	new intid;
	intid = GetPlayerInterior(playerid);

	userinfo[playerid][spos_x] = x;
	userinfo[playerid][spos_y] = y;
	userinfo[playerid][spos_z] = z;
	userinfo[playerid][spos_a] = a;
	userinfo[playerid][sinterior] = intid;

	return 1;
}

public ycmd_lpos(playerid, params[], help)
{
    #pragma unused help, params
	SetPlayerPos(playerid, userinfo[playerid][spos_x], userinfo[playerid][spos_y], userinfo[playerid][spos_z]);
	SetPlayerFacingAngle(playerid, userinfo[playerid][spos_a]);
	SetPlayerInterior(playerid, userinfo[playerid][sinterior]);

	return 1;
}

public ycmd_mkprop(playerid, params[], help)
{
	#pragma unused help, params
	ShowMenu(propertyMenu, playerid);
	return 1;
}

public ycmd_giveright(playerid, params[], help)
{
	#pragma unused help
	new
	    bblevel,
	    giveid;
	if(sscanf(params, "i", bblevel)) SendClientMessage(playerid, 0xff0000AA, "USAGE: /giveright [playerid] [builder] (1 = builder 2 = sbuilder)");
	else
	{
		switch(bblevel)
		{
		    case 1:
		    {
		        userinfo[playerid][blevel] = 1;
				Group_AddPlayer(builder, giveid);
			}
			
			case 2:
			{
			    userinfo[playerid][blevel] = 2;
			    Group_AddPlayer(superbuilder, giveid);
			}
		}
	}
	return 1;
}

public ycmd_gr(playerid, params[], help)
{
    #pragma unused help, params
    if(IsPlayerAdmin(playerid))
    {
        userinfo[playerid][blevel] = 2;
        Group_AddPlayer(superbuilder, playerid);
		SendClientMessage(playerid, 0x00FF00AA, "You are now SuperBuilder");
	}
	return 1;
}

public ycmd_veh(playerid, params[], help)
{
	#pragma unused help
	new vehicle;
	if(sscanf(params, "i", vehicle)) ShowMenu(vehicleSpawn, playerid);
	else
	{
	    SpawnVehicle(playerid, vehicle);
	}

	return 1;
}

public ycmd_savepos(playerid, params[], help)
{
	#pragma unused help
	new menushoww;
	sscanf(params, "i", menushoww);
	if(menushoww == 522) ShowMenu(saveMenu, playerid);
	else
	{
		switch(SaveOption)
		{
		    case 1:
		    {
		        new command[256];
		        sscanf(params, "z", command);

		        new vehicle = GetPlayerVehicleID(playerid);
		        new Float:x, Float:y, Float:z, Float:a;

		        GetVehiclePos(vehicle, x, y, z);
		        GetVehicleZAngle(vehicle, a);

				new str[256];

				format(str, sizeof(str), "%s", command);
				new xml_cars = XML_AddItem("vehicle", str);

				format(str, sizeof(str), "%f, %f, %f, %f", x, y, z, a);
				XML_AddParameter(xml_cars, "position", str);
				format(str, sizeof(str), "%i", GetVehicleModel(vehicle));
				XML_AddParameter(xml_cars, "model", str);

				XML_WriteItem("YSI/YDBG/cars.xml", xml_cars);
			}

			case 2:
			{
			    new command[256];
			    sscanf(params, "z", command);

			    new Float:x, Float:y, Float:z, Float:a;

			    GetPlayerPos(playerid, x, y, z);
			    GetPlayerFacingAngle(playerid, a);
			}

			default:
			{
			    ShowMenu(saveMenu, playerid);
			}
		}
	}
	return 1;
}

new Text:showTxt;

public ycmd_explain(playerid, params[], help)
{
	#pragma unused params, help
	
	showTxt = TextDrawCreate(130, 50, "Welkom,\
	~n~~n~\
	you want some explaining, here you GOOOO!\
	~n~~n~\
	this sytem....");
	
 	TextDrawFont(showTxt, 1);
	TextDrawSetShadow(showTxt, 2);
	TextDrawUseBox(showTxt, 1);
	TextDrawLetterSize(showTxt, 0.3, 0.3);
	TextDrawTextSize(showTxt, 430, 350);
	TextDrawBoxColor(showTxt, 0x00000AA);

	TextDrawShowForPlayer(playerid, showTxt);
	
	return 1;
}

public ycmd_hexplain(playerid, params[], help)
{
    #pragma unused params, help
	TextDrawHideForPlayer(playerid, showTxt);
	return 1;
}

/**
* Functions
*/
stock IsBuilder(playerid, level)
{
	if(userinfo[playerid][blevel] == level)
	{
	    return 1;
	}

	return 0;
}

stock IsBuilderEx(playerid, from, to)
{
	if(userinfo[playerid][blevel] >= from && userinfo[playerid][blevel] <= to)
	{
	    return 1;
	}

	return 0;
}

stock IsValidVehicle(carid)
{
	if(carid >= 400 && carid <= 611)
	{
	    return 1;
	}
	return 0;
}

public SpawnVehicle(playerid, vehicleid)
{
	if(IsPlayerInAnyVehicle(playerid)) SendClientMessage(playerid, 0xFF0000AA, "Get off the vehicle please ...");
	else if(!IsValidVehicle(vehicleid)) SendClientMessage(playerid, 0xFF0000AA, "Invallid vehicle");
	else
	{
		new Float:x, Float:y, Float:z, Float:a;
		
		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, a);
		
		new spcar;
		
		spcar = CreateVehicle(vehicleid, x+2.0, y, z, a, -1, -1, 100000);
		
		PutPlayerInVehicle(playerid, spcar, 0);
		
		Debug_Print_1("%i is spawned", vehicleid);
	}
}

stock ShowMenu(Menu:smenu, playerid)
{
	TogglePlayerControllable(playerid, 0);
	ShowMenuForPlayer(smenu, playerid);
	return 1;
}

public MkProp(playerid, prop1[], prop2[], prop3[], prop4[])
{
	new xml_prop = XML_AddItem("property", prop2);

	XML_AddParameter(xml_prop, "position", prop1);
	XML_AddParameter(xml_prop, "name", prop2);
	XML_AddParameter(xml_prop, "options_1", prop3);
	XML_AddParameter(xml_prop, "options_2", prop4);

	XML_WriteItem("YSI/YDBG/prop.xml", xml_prop);

	Text_Send(playerid, "YDBG_PROP_ADD_6");

	return 1;
}


/**
native YDBG_FUNCTIONS
	native
native FindText(text[], find[], maxlength, &output = '', outp = false);
native GetText(text[], &output);
*/

stock FindText(text[], find[], maxlength)
{
	if(strlen(text) <= maxlength)
	{
	    if(strfind(text, find))
		{
			return 1;
		}
	}
 	return 0;
}

stock GetText(text[], maxlength, output[])
{
	if(strlen(text) <= maxlength)
	{
	    format(output, maxlength, "%s", text);
	    return 1;
	}
	return 0;
}

/**
* Call the builder login
* Load data functions
*/
public LoginDat_YDBG(playerid, identifier[], text[])
{
	Debug_Print_1("LoginDat_YDBG");
	if(!strcmp(identifier, "blevel")) userinfo[playerid][blevel] = strval(text);
	else if(!strcmp(identifier, "spos_x")) userinfo[playerid][spos_x] = floatstr(text);
	else if(!strcmp(identifier, "spos_y")) userinfo[playerid][spos_y] = floatstr(text);
	else if(!strcmp(identifier, "spos_z")) userinfo[playerid][spos_z] = floatstr(text);
	else if(!strcmp(identifier, "spos_a")) userinfo[playerid][spos_a] = floatstr(text);
	else if(!strcmp(identifier, "sinterior")) userinfo[playerid][sinterior] = strval(text);
	
	if(userinfo[playerid][blevel] == 1)
	{
	    SetPlayerColor(playerid, 0x12bddbAA);
     	SendClientMessage(playerid, 0x00FF00AA, "You are as builder loged in");
     	Group_AddPlayer(builder, playerid);
	}

	if(userinfo[playerid][blevel] == 2)
	{
		SetPlayerColor(playerid, 0x017a8cAA);
		SendClientMessage(playerid, 0x00FF00AA, "You are as Superbuilder loged in");
		Group_AddPlayer(superbuilder, playerid);
	}
	
	return 1;
}

public LoadCars()
{
    static
		key[MAX_XML_ENTRY_NAME],
		val[MAX_XML_ENTRY_TEXT];

	new
     	model,
    	pos[256];
	while (XML_GetKeyValue(key, val))
	{
		if(!strcmp(key, "model")) model = strval(val);
		else if(!strcmp(key, "position")) pos = val;
	}
	new dest[4][256];
	explode(pos, dest, ',');
	// printf("Model: %i x: %f  y: %f  z: %f  a: %f", model, floatstr(dest[0]), floatstr(dest[1]), floatstr(dest[2]), floatstr(dest[3]));
	CreateVehicle(model, floatstr(dest[0]), floatstr(dest[1]), floatstr(dest[2]), floatstr(dest[3]), -1, -1, 1000);
}

public LoadProp()
{
	static
	    key[MAX_XML_ENTRY_NAME],
	    val[MAX_XML_ENTRY_TEXT];

	new
	    options_1[256],
	    options_2[256],
	    name[256],
	    pos[256];

	while (XML_GetKeyValue(key, val))
	{
	    if(!strcmp(key, "options_2")) options_2 = val;
	    else if(!strcmp(key, "options_1")) options_1 = val;
	    else if(!strcmp(key, "name")) name = val;
	    else if(!strcmp(key, "position")) pos = val;
	}
	
	new opt1[3][30];
	new opt2[5][30];
	new dest[3][30];
	
	explode(options_1, opt1, ',');
	explode(options_2, opt2, ',');
	explode(pos, dest, ',');
	
	// printf("Setups: 1: %i 2: %i 3: %i 4: %i 5: %i 6: %i 7: %i 8: %i", strval(opt1[0]), strval(opt1[1]), strval(opt1[2]), strval(opt2[0]), strval(opt2[1]), strval(opt2[2]), strval(opt2[3]), strval(opt2[4]));
 	// printf("Name: %s Position: %f, %f, %f", name, floatstr(dest[0]), floatstr(dest[1]), floatstr(dest[2]));
	
	CreateProperty(name, floatstr(dest[0]), floatstr(dest[1]), floatstr(dest[2]), strval(opt1[0]), strval(opt1[1]), strval(opt1[2]), strval(opt2[0]), strval(opt2[1]), strval(opt2[2]), strval(opt2[3]), strval(opt2[4]));
}

public Load_MoneyPoint()
{
    static
		key[MAX_XML_ENTRY_NAME],
		val[MAX_XML_ENTRY_TEXT];

	new
     	pos[256],
    	options[256];
	while (XML_GetKeyValue(key, val))
	{
		if(!strcmp(key, "position")) pos = val;
		else if(!strcmp(key, "options")) options = val;
	}
	
	new posdest[3][30];
	new optdest[2][30];

	explode(pos, posdest, ',');
	explode(options, optdest, ',');

	// printf("POS: %f, %f, %f OPTIONS: %i, %i", floatstr(posdest[0]), floatstr(posdest[1]), floatstr(posdest[2]), strval(optdest[0]), strval(optdest[1]));
	CreateMoneyPoint(floatstr(posdest[0]), floatstr(posdest[1]), floatstr(posdest[2]), 2.0, strval(optdest[0]), strval(optdest[1]));
}

public LoadBank()
{
    static
		key[MAX_XML_ENTRY_NAME],
		val[MAX_XML_ENTRY_TEXT];

	new
     	posi[256],
    	name[256];
	while (XML_GetKeyValue(key, val))
	{
		if(!strcmp(key, "name")) name = val;
		else if(!strcmp(key, "position")) posi = val;
	}
	
	new posidest[3][30];

	explode(posi, posidest, ',');

	printf("POS: %f, %f, %f NAME: %s", floatstr(posidest[0]), floatstr(posidest[1]), floatstr(posidest[2]), name);
	CreateBank(floatstr(posidest[0]), floatstr(posidest[1]), floatstr(posidest[2]), name);
}

stock load_functions()
{
	ycmd(kill);
	ycmd(gr);
	ycmd(explain);
	ycmd(hexplain);
	c_menu = ycmd(menu);
	spos = ycmd(spos);
	lpos = ycmd(lpos);
	mkprop = ycmd(mkprop);
	giveright = ycmd(giveright);
	veh = ycmd(veh);
	savepos = ycmd(savepos);

	Group_SetDefaultCommandByID(spos, 0);
	Group_SetDefaultCommandByID(lpos, 0);
	Group_SetDefaultCommandByID(mkprop, 0);
	Group_SetDefaultCommandByID(c_menu, 0);
	Group_SetDefaultCommandByID(giveright, 0);
	Group_SetDefaultCommandByID(veh, 0);
	Group_SetDefaultCommandByID(savepos, 0);

	// Set the bulder commands
	Group_SetCommandByID(builder, spos, 1);
	Group_SetCommandByID(builder, lpos, 1);
	Group_SetCommandByID(builder, mkprop, 1);
	Group_SetCommandByID(builder, savepos, 1);

	// Set the Superbuilder commands
	Group_SetCommandByID(superbuilder, spos, 1);
	Group_SetCommandByID(superbuilder, lpos, 1);
	Group_SetCommandByID(superbuilder, mkprop, 1);
	Group_SetCommandByID(superbuilder, giveright, 1);
	Group_SetCommandByID(superbuilder, veh, 1);
	Group_SetCommandByID(superbuilder, c_menu, 1);
	Group_SetCommandByID(superbuilder, savepos, 1);

	Command_SetDeniedReturn(1);
	Command_UseDeniedMessage(1);
	Command_SetDisconnectReturn(1);
}

stock load_xml_init()
{
	#if !defined NO_VEHICLE_LOAD
	 	new
			XML:xCars = XML_New();
		if (xCars != NO_XML_FILE)
		{
			XML_AddHandler(xCars, "vehicle", "LoadCars");
			XML_Parse(xCars, "YSI\\YDBG\\cars.xml");
		}
	#endif

	#if !defined NO_PROPERTYS_LOAD
	    new
			XML:xProps = XML_New();
		if(xProps != NO_XML_FILE)
		{
		    XML_AddHandler(xCars, "property", "LoadProp");
			XML_Parse(xCars, "YSI\\YDBG\\prop.xml");
		}
	#endif

	#if !defined NO_MONEYPOINT_LOAD
	    new
	        XML:xMPoint = XML_New();
		if(xMPoint != NO_XML_FILE)
		{
		    XML_AddHandler(xMPoint, "moneypoint", "Load_MoneyPoint");
		    XML_Parse(xMPoint, "YSI\\YDBG\\moneypoint.xml");
		}
	#endif

	#if !defined NO_BANK_LOAD
	    new
	        XML:xBank = XML_New();
		if(xBank != NO_XML_FILE)
		{
		    XML_AddHandler(xBank, "bank", "LoadBank");
		    XML_Parse(xBank, "YSI\\YDBG\\bank.xml");
		}
	#endif
}
