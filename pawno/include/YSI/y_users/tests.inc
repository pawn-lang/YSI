Test:Player_Existing()
{
	new
		ret[E_USER_PRELOAD];
	Player_Preload("TestPlayer", ret);
	ASSERT(0 == ret[E_USER_PRELOAD_YID]);
	ASSERT(Langs_GetLanguage("EN") == ret[E_USER_PRELOAD_LANG]);
	ASSERT(0x12345678 == ret[E_USER_PRELOAD_BITS]);
	ASSERT(0xAABBCCDD >= ret[E_USER_PRELOAD_DATE]);
}

new
	gBot = INVALID_PLAYER_ID;

Test:Player_ChangeLanguage()
{
	// Connect the bot here so that it is done way before the PTest is run.
	ConnectNPC("TestPlayer", "npcidle");
}

public OnPlayerConnect(playerid)
{
	new
		name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof (name));
	if (!strcmp(name, "TestPlayer")) gBot = playerid;
	#if defined Testing_OnPlayerConnect
		return Testing_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Testing_OnPlayerConnect
#if defined Testing_OnPlayerConnect
	forward Testing_OnPlayerConnect(playerid);
#endif

PTestInit:Player_ChangeLanguage(playerid)
{
	// So that their language can be changed.
	Player_ForceLogin(gBot);
}

PTest:Player_ChangeLanguage(playerid)
{
	new
		ret[E_USER_PRELOAD];
	// Check their language is English, then change it to Dutch.
	Player_Preload("TestPlayer", ret);
	ASSERT(Langs_GetLanguage("EN") == ret[E_USER_PRELOAD_LANG]);
	Player_ChangeLanguage(gBot, "NL");
	Player_Preload("TestPlayer", ret);
	ASSERT(Langs_GetLanguage("NL") == ret[E_USER_PRELOAD_LANG]);
}

PTestClose:Player_ChangeLanguage(playerid)
{
	// Reset the player.
	Player_ChangeLanguage(gBot, "EN");
	//Kick(gBot);
}

PTestInit:Player_ChangePassword(playerid)
{
	// So that their password can be changed.
	Player_ForceLogin(gBot);
}

PTest:Player_ChangePassword(playerid)
{
	new
		ret[E_USER_PRELOAD];
	// Change their password.
	Player_Preload("TestPlayer", ret);
	ASSERT(!strcmp(ret[E_USER_PRELOAD_PASS], "");
	Player_ChangePassword(gBot, "thisisabadpass");
	Player_Preload("TestPlayer", ret);
	ASSERT(!strcmp(ret[E_USER_PRELOAD_PASS], "0E7FD2E6CC6B63AE3F5199113EBDEE95D59B37D3BF2FF22FFAA910E5A1DAC9BB7D52A5D8BA813423900B1BFA629D9A1A579DA21C0316BFB69291859D535BE60F");
}

PTestClose:Player_ChangePassword(playerid)
{
	// Reset the player.
	Player_ChangePassword(gBot, "thisisanOKpass");
	//Kick(gBot);
}

PTest:Player_Preload(playerid)
{
	new
		name[MAX_PLAYER_NAME],
		ret[E_USER_PRELOAD];
	GetPlayerName(playerid, name, sizeof (name));
	Player_Preload(name, ret);
	ASSERT(Player_GetYID(playerid) == ret[E_USER_PRELOAD_YID]);
	ASSERT(Langs_GetPlayerLanguage(playerid) == ret[E_USER_PRELOAD_LANG]);
	ASSERT(0 == ret[E_USER_PRELOAD_BITS]);
	ASSERT(gettime() >= ret[E_USER_PRELOAD_DATE]);
}

PTestInit:Player_GetID(playerid)
{
	// So that their password can be changed.
	Player_ForceLogin(gBot);
}

PTest:Player_GetID(playerid)
{
	ASSERT(Player_GetYID(gBot) == 0);
	ASSERT(Player_GetYID(playerid) < 0);
}
