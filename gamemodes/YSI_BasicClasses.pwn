// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT
#define _DEBUG 5
#define YSI_NO_MASTER
#include <a_samp>
//#define MASTER 5
//#include <YSI\y_master>
#include <YSI\y_classes>
#include <YSI\y_commands>
#include <YSI\y_groups>

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
}

public OnGameModeInit()
{
	/*AddPlayerClass(0, 0.0, 0.0, 10.0, 0.0, WEAPON_MP5, 50, 0, 0, 0, 0);
	AddPlayerClass(165, 0.0, 0.0, 10.0, 0.0, WEAPON_BAT, 50, 0, 0, 0, 0);
	AddPlayerClass(282, 0.0, 0.0, 10.0, 0.0, WEAPON_MOLTOV, 50, 0, 0, 0, 0);
	AddPlayerClass(283, 0.0, 0.0, 10.0, 0.0, WEAPON_DEAGLE, 50, 0, 0, 0, 0);
	AddPlayerClass(287, 0.0, 0.0, 10.0, 0.0, WEAPON_UZI, 50, 0, 0, 0, 0);*/
	printf("%d", Class_Add(0, 0.0, 0.0, 10.0, 0.0, WEAPON_MP5, 50));
	printf("%d", Class_Add(165, 0.0, 0.0, 10.0, 0.0, WEAPON_BAT, 50));
	printf("%d", Class_Add(282, 0.0, 0.0, 10.0, 0.0, WEAPON_MOLTOV, 50, WEAPON_ARMOUR));
	printf("%d", Class_Add(283, 0.0, 0.0, 10.0, 0.0, WEAPON_DEAGLE, 50));
	printf("%d", Class_Add(287, 0.0, 0.0, 10.0, 0.0, WEAPON_UZI, 50));
	Group_SetGlobalClass(0, false);
	Group_Create("hi");
	CallRemoteFunction("OnPlayerCommandText", "is", 0, "/fire 7");
}

YCMD:fire(playerid, params[], help)
{
	printf("/fire called!");
	Class_Add(279, 0.0, 0.0, 10.0, 0.0);
	return 1;
}

YCMD:go(playerid, params[], help)
{
	Class_Goto(playerid, 1);
	return 1;
}

YCMD:cj(playerid, params[], help)
{
	Class_Delete(3);
	return 1;
}

public OnPlayerConnect(playerid)
{
	//Class_SetPlayer(0, playerid, false);
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerPos(playerid, 0.0, 0.0, 5.0);
	SetPlayerCameraPos(playerid, 3.0, 3.0, 7.0);
	SetPlayerCameraLookAt(playerid, 0.0, 0.0, 6.0);
	return 1;
}

