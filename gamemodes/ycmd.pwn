//#define YSI_NO_MASTER
//#define COMMAND_ACCURATE
#define _COMMANDS_FAST
#define _DEBUG 5
#include <YSI\y_groups>
#include <YSI\y_commands>
#include <YSI\y_master>
#pragma tabsize 0

main()
{
	print("\n----------------------------------");
	print("  Bare Script\n");
	print("----------------------------------\n");
}


public OnPlayerConnect(playerid)
{
	GameTextForPlayer(playerid,"~w~SA-MP: ~r~Bare Script",5000,5);
	return 1;
}

public OnPlayerSpawn(playerid)
{
	SetPlayerInterior(playerid,0);
	TogglePlayerClock(playerid,0);
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
   	return 1;
}

SetupPlayerForClassSelection(playerid)
{
 	SetPlayerInterior(playerid,14);
	SetPlayerPos(playerid,258.4893,-41.4008,1002.0234);
	SetPlayerFacingAngle(playerid, 270.0);
	SetPlayerCameraPos(playerid,256.0815,-43.0475,1004.0234);
	SetPlayerCameraLookAt(playerid,258.4893,-41.4008,1002.0234);
}

public OnPlayerRequestClass(playerid, classid)
{
	SetupPlayerForClassSelection(playerid);
	return 1;
}

public OnGameModeInit()
{
	SetGameModeText("Bare Script");
	ShowPlayerMarkers(1);
	ShowNameTags(1);
	AllowAdminTeleport(1);

	AddPlayerClass(265,1958.3783,1343.1572,15.3746,270.1425,0,0,0,0,-1,-1);
    Command_SetDeniedReturn(true);
    CallLocalFunction("OnPlayerCommandText", "is", 0, "/me woo");
    Command_Debug();
	return 1;
}



YCMD:me(playerid, params[], help)
{
	print("DWDWDWWD");
    if (help)
    {
        SendClientMessage(playerid, 0xFF0000AA, "Sends an action to other players.");
		print("Sends an action to other players.");
    }
    else
    {
        new
            str[128];
        if (isnull(params))
        {
            format(str, sizeof (str), "Usage: \"/%s [action]\"", Command_GetDisplayNamed("me", playerid));
            SendClientMessage(playerid, 0xFF0000AA, str);
            print(str);
        }
        else
        {
            GetPlayerName(playerid, str, sizeof (str));
            format(str, sizeof (str), "* %s %s", str, params);
            SendClientMessageToAll(0xFF0000AA, str);
            print(str);
        }
    }
    return 1;
}

