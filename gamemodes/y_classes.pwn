// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#define _DEBUG 2

#include <YSI\y_classes>
#include <YSI\y_commands>

main()
{
	print("\n-----------------------");
	print(" y_classes test script");
	print("-----------------------\n");
}

public OnGameModeInit()
{
	printf("OGMI");
	printf("%d", Class_AddClass(0, 0.0, 0.0, 15.0, 45.0, "", 0, Group:-1, Group:-1));
	printf("%d", Class_AddClass(102, 0.0, 0.0, 15.0, 45.0, "", 0, Group:-1, Group:-1));
	printf("%d", Class_AddClass(114, 0.0, 0.0, 15.0, 45.0, "", 0, Group:-1, Group:-1));
	printf("%d", Class_AddClass(108, 0.0, 0.0, 15.0, 45.0, "", 0, Group:-1, Group:-1));
	AddPlayerClass(0, 0.0, 0.0, 10.0, 0.0, 0, 0, 0, 0, 0, 0);
}

public OnPlayerConnect(playerid)
{
//	Class_SetPlayer(0, playerid, false);
//	Class_SetPlayer(2, playerid, false);
	Class_DenySelection(playerid);
}

YCMD:kill(playerid, params[], help)
{
	SetPlayerHealth(playerid, 0.0);
	return 1;
}

YCMD:deny(playerid, params[], help)
{
	Class_AllowReselection(0);
	return 1;
}

YCMD:enable(playerid, params[], help)
{
	Class_AllowReselection(1);
	return 1;
}

YCMD:return(playerid, params[], help)
{
	Class_ReturnToSelection(playerid);
	return 1;
}

