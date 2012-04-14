//uncomment the following line to make this a filterscript
//#define FILTERSCRIPT

#include <a_samp>
#include <YSI/setup/YSI_master.own>
#include <YSI>

//default roundtime is disabled, time is in minutes
//new gRoundTime = 30; //30 minutes
//new gRoundTime = 15; //15 minutes
//new gRoundTime = 10; //10 minutes
new gRoundTime = 0;

#if defined FILTERSCRIPT

Script_OnFilterScriptInit()
{
    print("\n------------------------------------");
    print(" YSI Filterscript by your name here");
    print("------------------------------------\n");

    ycmd(kill);
    ycmd("mycommand");
    Langs_AddLanguage("EN", "English");
    Langs_AddFile("core", "YSI");
    return 1;
}

Script_OnFilterScriptExit()
{
    return 1;
}

#else

main()
{
	print("\n-------------------------------------");
	print("  YSI Monster by [AU]Hell_Demon");
	print(" ");
	print(" Based on Monster freeroam by Mike");
	print("-------------------------------------\n");
}

#endif

Text_RegisterTag(tag_with_MY_KILL_HELP);

forward ycmd_kill(playerid, params[], help);
forward AddClassesAndVehicles(); //Spawnpoints and Vehicle spawnpoints setup
forward GameModeExitFunc();
public ycmd_kill(playerid, params[], help)
{
    if (help) Text_Send(playerid, "MY_KILL_HELP");
    else SetPlayerHealth(playerid, 0.0);
    return 1;
}

Script_OnGameModeInit()
{
    // Don't use these lines if it's a filterscript
    SetGameModeText("Monster Freeroam");
	AddClassesAndVehicles();
	if (gRoundTime > 0) {
	    SetTimer("GameModeExitFunc", gRoundTime*60000, 0);
	}
    ycmd(kill);
    ycmd("mycommand");
    Langs_AddLanguage("EN", "English");
    Langs_AddFile("core", "YSI");
    return 1;
}

Command_(mycommand)
{
    // Your code here
    return 1;
}

Script_OnGameModeExit()
{
    Master_@Master();
    return 1;
}

SetupPlayerForClassSelection(playerid)
{
	SetPlayerPos(playerid,398.4077,2540.5049,19.6311);
	SetPlayerCameraPos(playerid,398.4077,2530.5049,19.6311);
	SetPlayerCameraLookAt(playerid,398.4077,2540.5049,19.6311);
	SetPlayerFacingAngle(playerid, 180.0);
}

Script_OnPlayerRequestClass(playerid, classid)
{
    SetupPlayerForClassSelection(playerid);
    return 1;
}

Script_OnPlayerRequestSpawnEx(playerid, classid)
{
    return 1;
}

Script_OnPlayerConnect(playerid)
{
    GameTextForPlayer(playerid,"~w~Monster freeroam!",1000,5);
    return 1;
}

Script_OnPlayerDisconnect(playerid, reason)
{
    return 1;
}

Script_OnPlayerSpawn(playerid)
{
    return 1;
}

Script_OnPlayerDeath(playerid, killerid, reason)
{
    SendDeathMessage(killerid,playerid,reason);
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
    return 1;
}

Script_OnPlayerPrivmsg(playerid, recieverid, text[])
{
    return 1;
}

Script_OnPlayerCommandText(playerid, cmdtext[])
{
    return 0;
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

Script_OnObjectMoved(objectid)
{
    return 1;
}

Script_OnPlayerObjectMoved(playerid, objectid)
{
    return 1;
}

Script_OnPlayerPickUpPickup(playerid, pickupid)
{
    return 1;
}

Script_OnPlayerSelectedMenuRow(playerid, row)
{
    return 1;
}

Script_OnPlayerExitedMenu(playerid)
{
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
    return 1;
}

Script_OnPlayerLogout(playerid)
{
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

public AddClassesAndVehicles()
{
   	new id;
	new count;
    new Float:monsterX = 414.9143;
	new Float:boatX = 260.0439;
	new Float:bikeX = 393.8199;
	
    // Players
	for (id = 254; id <= 288; id++) {
		if (id == 265) id = 274; // Skip over the bad ones
		Class_Add(id,389.8672,2543.0046,16.5391,173.7645,-1,-1,-1,-1,-1,-1);
		
	}

	// Special monster truck, Mike owns it
	AddStaticVehicle(556,423.9143,2482.2766,16.8594,0.0,1,1);
	
	// monster trucks
	for(count = 0; count <= 50; count++) {
		AddStaticVehicle(557,monsterX,2482.4856,16.8594,0.0,1,1);
		monsterX -= 9.0;
	}

	// Boats
	for(count = 0; count <= 15; count++) {
		AddStaticVehicle(446,boatX,2970.7834,-1.0287,7.0391,-1,-1);
		boatX += 6.0;
	}

	// Mountain bikes/BMXes
	for(count = 0; count <= 10; count++) {
		AddStaticVehicle(481,bikeX,2547.0911,16.0545,356.9482,-1,-1);
		AddStaticVehicle(510,bikeX,2538.3503,16.1516,356.1028,-1,-1);
		bikeX -= 2.5;
	}

	AddStaticVehicle(513,324.7664,2546.0984,16.4876,178.8663,-1,-1); // stuntplane
	AddStaticVehicle(513,290.2709,2544.7771,16.5000,178.0178,-1,-1); // stuntplane
	AddStaticVehicle(487,261.9073,2522.6987,16.4046,175.9395,-1,-1); // heli
	AddStaticVehicle(487,244.0523,2524.3516,16.4171,180.8316,-1,-1); // heli
	AddStaticVehicle(592,-73.1792,2502.1990,16.1641,270.0,-1,-1); //adromeda
	AddStaticVehicle(532,101.5550,2584.0725,17.4540,178.0316,-1,-1); // combine
}

public GameModeExitFunc()
{
	GameModeExit();
}
