#include <a_samp>
#include <YSI\y_text>
#include <YSI\y_commands>

// Team stuff
new
	Attackers,
	Defenders;

// Checkpoint stuff
new
	CP_Plane,
	CP_A69;

// Winner state
#define ATTACK_WIN 1
#define DEFENCE_WIN 2

// If the army defends the lab for this amount of time they win!
// Time is in minutes!
new
	gRoundTime = 10;					// Round time - 10 mins

main()
{
    print("\n-------------------------------------");
    print(" YSI Area 51 Recode by [AU]Hell_Demon");
    print("      Original Area 51 coded by");
    print("                 Mike");
    print("---------------------------------------\n");
}

forward AddClasses();
forward DefenceWin();
forward GameModeExitFunc();

CMD:kill(playerid, params[], help)
{
    if (help) Text_Send(playerid, "MY_KILL_HELP");
    else SetPlayerHealth(playerid, 0.0);
    return 1;
}

public OnGameModeInit()
{
    // Don't use these lines if it's a filterscript
    SetGameModeText("Area 51 Break-in");
	ShowNameTags(1);
	ShowPlayerMarkers(0);
	SetWorldTime(0);
    AddClasses();
    SetTimer("DefenceWin", gRoundTime * 60 * 1000, 0);
    
    Attackers = Group_Create("TEAM_ATTACK");
	Defenders = Group_Create("TEAM_DEFEND");
	
	CP_Plane = CreateCheckpoint(315.7353, 1035.6589, 1945.1191, 5.0);
	CP_A69 = CreateCheckpoint(268.5821, 1883.8224, -30.0938, 5.0);

    Langs_AddLanguage("EN", "English");
    Langs_AddFile("core", "YSI");
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetupPlayerForClassSelection(playerid);
    switch (classid)
	{
		case 0:
	    {
			GameTextForPlayer(playerid, "~r~Attack", 1000, 3);
		}
	    case 1, 2:
        {
			GameTextForPlayer(playerid, "~g~Defence", 1000, 3);
		}
	}
    return 1;
}

SetupPlayerForClassSelection(playerid)
{
	SetPlayerInterior(playerid,9);
	SetPlayerFacingAngle(playerid,0.0);
	SetPlayerPos(playerid,315.7802,972.0253,1961.8705);
	SetPlayerCameraPos(playerid,315.7802,975.0253,1961.8705);
	SetPlayerCameraLookAt(playerid,315.7802,972.0253,1961.8705);
	return 1;
}

public OnPlayerRequestSpawnEx(playerid, classid)
{
	if(classid==0)
	{
		Checkpoint_AddPlayer(CP_Plane, playerid);
		Checkpoint_AddPlayer(CP_A69, playerid);
	}
	else
	{
	    Checkpoint_RemovePlayer(CP_Plane, playerid);
	    Checkpoint_RemovePlayer(CP_A69, playerid);
	}
    return 1;
}

public OnPlayerConnect(playerid)
{
    GameTextForPlayer(playerid,"~w~SA:MP Area51 Break-in!",4000,3);
	SetPlayerColor(playerid, X11_GREY);
	Checkpoint_RemovePlayer(CP_Plane, playerid);
	Checkpoint_RemovePlayer(CP_A69, playerid);
    return 1;
}

SetPlayerToTeamColor(playerid)
{
	if(Group_HasPlayer(Attackers, playerid))
	{
	    SetPlayerColor(playerid, X11_RED); // Red
	}
	else if(Group_HasPlayer(Defenders, playerid))
	{
	    SetPlayerColor(playerid, X11_GREEN); // Green
	}
}

public OnPlayerSpawn(playerid)
{
	SetPlayerToTeamColor(playerid);
    return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
    if (killerid != INVALID_PLAYER_ID)
	{
	    if(Group_HasPlayer(Attackers, playerid) && Group_HasPlayer(Attackers, killerid))
	    {
	        SetPlayerScore(killerid, GetPlayerScore(killerid) - 1);
		}
		else
		{
			SetPlayerScore(killerid, GetPlayerScore(killerid) + 1);
		}
	}
	SendDeathMessage(killerid, playerid, reason);

	SetPlayerColor(playerid, X11_GREY);
    return 1;
}

public OnPlayerEnterCheckpointEx(playerid, cpid)
{
	if(cpid == CP_Plane)
	{
	    GameTextForPlayer(playerid, "Now parachute to ~r~Area 51", 2000, 5);
        SetPlayerInterior(playerid,0);
        SetPlayerPos(playerid, 239.5148, 1813.7039, 500.6836);
	}
	
	if(cpid == CP_A69)
	{
	    EndTheRound(ATTACK_WIN);
	}
	    
    return 1;
}

public AddClasses()
{
	// Classes
	Class_AddWithGroupSet(Attackers, 111, 315.4792, 984.1290, 1959.1129, 353.5, 3, 0, 23, 1000, 25, 100); //Mafia skin in andromena - Attackers
	Class_AddWithGroupSet(Defenders, 287, 245.1233, 1859.1162, 14.0840, 358.717, 4, 0, 32, 1000, 31, 5000); // Army - Defender
	Class_AddWithGroupSet(Defenders, 70, 271.6828, 1873.8666, 8.7578, 229.4508, 4, 0, 24, 1000, 32, 1000); // Lab - Defender
	
	// Parachutes
	Pickup_Add(371, 319.3416, 1020.7169, 1950.6696);
	Pickup_Add(371, 312.6138, 1020.7346, 1950.6655);
}

EndTheRound(winner)
{
	switch (winner)
	{
	    case 1:
	    {
	        GameTextForAll("The attackers broke into Area 51.", 2000, 5);
	    }
	    case 2:
	    {
	        GameTextForAll("Area 51 was successfully defended.", 2000, 5);
	    }
	}
	SetTimer("GameModeExitFunc", 5000, 0);
}

public GameModeExitFunc()
{
	GameModeExit();
}

public DefenceWin()
{
	EndTheRound(DEFENCE_WIN);
}
