// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>

#define INCLUDE_TESTS
//#define _DEBUG 2

#include <YSI\y_testing>
#include <YSI\y_commands>
#include <YSI\y_iterate>

forward T0();
public T0(){}

forward T1(playerid, cmdtext[]);
public T1(playerid, cmdtext[])
{
	return 1;
}

R0()
{
	Hooks_RedirectPublic("T0", "OnPlayerCommandText");
	Hooks_RedirectPublic("OnPlayerCommandText", "T1");
	return 1;
}

R1()
{
	Hooks_RedirectPublic("OnPlayerCommandText", "T0");
	return 1;
}

#define CMDFAIL(%1,%2) \
	SendClientMessage(playerid, 0x0000FFAA, "Test:" #%2 ": A failure should follow..."); \
	if (R0(),W@("OnPlayerCommandText", "is", playerid, "/" #%1),R1(),P@("OnPlayerCommandText", "is", playerid, "/" #%1)) TEST_TRUE(FALSE); \
	else SendClientMessage(playerid, 0xFF0000AA, "Test:" #%2 ": Fail!"), TEST_TRUE(TRUE); \
	SendClientMessage(playerid, 0x0000FFAA, "Test:" #%2 ": No failure above means the test failed.")

#define CMDPASS(%1,%2) \
	SendClientMessage(playerid, 0x0000FFAA, "Test:" #%2 ": A message should follow..."); \
	TEST_NOT_NULL((R0(),W@("OnPlayerCommandText", "is", playerid, "/" #%1),R1(),P@("OnPlayerCommandText", "is", playerid, "/" #%1))); \
	SendClientMessage(playerid, 0x0000FFAA, "Test:" #%2 ": No message above means the test failed.")

#define CMDNONE(%1,%2) \
	SendClientMessage(playerid, 0x0000FFAA, "Test:" #%2 ": No message should follow..."); \
	TEST_NOT_NULL((R0(),W@("OnPlayerCommandText", "is", playerid, "/" #%1),R1(),P@("OnPlayerCommandText", "is", playerid, "/" #%1))); \
	SendClientMessage(playerid, 0x0000FFAA, "Test:" #%2 ": A message above means the test failed.")

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
}

public OnGameModeInit()
{
	printf("================");
	printf("| Master ID: %d |", _@);
	printf("================");
	SendRconCommand("loadfs test\\y_commands_fs");
}

public OnGameModeExit()
{
	SendRconCommand("unloadfs test\\y_commands_fs");
}

new
	gPass;

CMD:cmd1(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:cmd1: Message!");
	++gPass;
	return 1;
}

CMD:cmd2(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:cmd2: Message!");
	++gPass;
	return 1;
}

CMD:cmd3(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:cmd3: Message!");
	++gPass;
	return 0;
}

Test:cmd1()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	CMDPASS(cmd1, cmd1);
	ASSERT(gPass == 1);
}

Test:nocmd1()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_SetUnknownReturn(false);
	CMDFAIL(nocmd1, nocmd1);
	ASSERT(gPass == 0);
}

Test:altcmd1()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	CMDPASS(altcmd1, altcmd1);
	ASSERT(gPass == 1);
}

Test:altcmd2()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetUnknownReturn(false);
	Command_SetDeniedReturn(false);
	CMDPASS(altcmd1, altcmd2);
	Command_SetPlayer(YCMD:altcmd1, playerid, false);
	CMDFAIL(altcmd1, altcmd2);
	ASSERT(gPass == 1);
}

Test:altcmd3()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetUnknownReturn(false);
	Command_SetDeniedReturn(false);
	Command_SetPlayer(YCMD:altcmd1, playerid, false);
	CMDFAIL(altcmd1, altcmd3);
	Command_SetPlayer(YCMD:altcmd1, playerid, true);
	CMDPASS(altcmd1, altcmd3);
	ASSERT(gPass == 1);
}

Test:altcmd4()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_SetUnknownReturn(false);
	Command_SetDeniedReturn(false);
	CMDFAIL(altcmd1, altcmd4);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	CMDPASS(altcmd1, altcmd4);
	ASSERT(gPass == 1);
}

Test:denied0()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_SetPlayer(YCMD:cmd2, playerid, false);
	Command_SetUnknownReturn(false);
	Command_SetDeniedReturn(false);
	ASSERT(!Command_GetDeniedReturn());
	CMDFAIL(cmd2, denied0);
	ASSERT(gPass == 0);
}

Test:denied1()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_SetPlayer(YCMD:cmd2, playerid, false);
	Command_SetUnknownReturn(false);
	Command_SetDeniedReturn(false);
	Command_SetDeniedReturn(true);
	ASSERT(Command_GetDeniedReturn());
	CMDNONE(cmd2, denied0);
	ASSERT(gPass == 0);
}

Test:denied3()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_SetUnknownReturn(false);
	Command_SetDeniedReturn(false);
	ASSERT(!Command_GetUnknownReturn());
	CMDFAIL(nocmd2, denied3);
	ASSERT(gPass == 0);
}

Test:denied4()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_SetUnknownReturn(false);
	Command_SetDeniedReturn(false);
	Command_SetUnknownReturn(true);
	ASSERT(Command_GetUnknownReturn());
	CMDNONE(nocmd2, denied4);
	ASSERT(gPass == 0);
}

/*Test:denied6()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_SetUnknownReturn(false);
	ASSERT(!Command_GetUnknownReturn());
	Command_SetPlayer(YCMD:cmd3, playerid, false);
	CMDFAIL(cmd3, denied6);
	ASSERT(gPass == 1);
}

Test:denied7()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_SetUnknownReturn(true);
	ASSERT(Command_GetUnknownReturn());
	Command_SetPlayer(YCMD:cmd3, playerid, false);
	CMDFAIL(cmd3, denied7);
	ASSERT(gPass == 1);
}*/

Test:name0()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetPlayer(YCMD:cmd1, playerid, false);
	Command_SetPlayer(YCMD:altcmd1, playerid, true);
	ASSERT(!strcmp(Command_GetDisplayNamed("cmd1", playerid), "altcmd1"));
}

Test:name1()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetPlayer(YCMD:cmd1, playerid, true);
	Command_SetPlayer(YCMD:altcmd1, playerid, false);
	ASSERT(!strcmp(Command_GetDisplayNamed("cmd1", playerid), "cmd1"));
}

Test:name2()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetPlayer(YCMD:cmd1, playerid, false);
	Command_SetPlayer(YCMD:altcmd1, playerid, true);
	ASSERT(!strcmp(Command_GetDisplayNamed("altcmd1", playerid), "altcmd1"));
}

Test:name3()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetPlayer(YCMD:cmd1, playerid, true);
	Command_SetPlayer(YCMD:altcmd1, playerid, false);
	ASSERT(strlen(Command_GetDisplayNamed("altcmd1", playerid)) == 0);
}

Test:name10()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetPlayer(YCMD:cmd1, playerid, false);
	Command_SetPlayer(YCMD:altcmd1, playerid, true);
	ASSERT(!strcmp(Command_GetDisplay(YCMD:cmd1, playerid), "altcmd1"));
}

Test:name11()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetPlayer(YCMD:cmd1, playerid, true);
	Command_SetPlayer(YCMD:altcmd1, playerid, false);
	ASSERT(!strcmp(Command_GetDisplay(YCMD:cmd1, playerid), "cmd1"));
}

Test:name12()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetPlayer(YCMD:cmd1, playerid, false);
	Command_SetPlayer(YCMD:altcmd1, playerid, true);
	ASSERT(!strcmp(Command_GetDisplay(YCMD:altcmd1, playerid), "altcmd1"));
}

Test:name13()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_Remove(YCMD:altcmd1);
	Command_AddAlt(YCMD:cmd1, "altcmd1");
	Command_SetPlayer(YCMD:cmd1, playerid, true);
	Command_SetPlayer(YCMD:altcmd1, playerid, false);
	ASSERT(strlen(Command_GetDisplay(YCMD:altcmd1, playerid)) == 0);
}

CMD:test(playerid, params[])
{
	Testing_RunAll();
	return 1;
}

#define MASTER 5
#include <YSI\y_master>

CMD:fs2(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs2: GM!");
	++gPass;
	return 1;
}

CMD:fs3(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs3: GM!");
	++gPass;
	return 1;
}

#define MASTER 6
#define YSIM_C_ENABLE
#include <YSI\y_master>

CMD:fs4(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs4: GM!");
	++gPass;
	return 1;
}

CMD:fs5(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs5: GM!");
	++gPass;
	return 1;
}

Test:master0()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_SetUnknownReturn(false);
	Command_SetDeniedReturn(false);
	CMDPASS(fs0, master0);
	CMDPASS(fs1, master0);
	CMDPASS(fs2, master0);
	CMDPASS(fs3, master0);
	CMDPASS(fs4, master0);
	CMDPASS(fs5, master0);
	CMDFAIL(fs6, master0);
	CMDFAIL(fs7, master0);
	ASSERT(gPass == 2);
}

Test:provider1()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	Command_SetPlayerProvider(playerid, -1);
	Command_SetProvider(-1);
	Command_SetPlayer(YCMD:cmd1, playerid, true);
	Command_SetPlayer(YCMD:cmd2, playerid, true);
	Command_SetPlayer(YCMD:cmd3, playerid, true);
	CMDPASS(cmd1, provider1);
	CMDPASS(cmd2, provider1);
	CMDFAIL(cmd3, provider1);
	ASSERT(gPass == 3);
	Command_SetPlayerProvider(playerid, -1);
}

Test:provider2()
{
	gPass = 0;
	new
		playerid = Iter_First(Player);
	// I'm GUESSING the master ID here
	printf("If this test fails, check the master ID.");
	Command_SetPlayerProvider(playerid, 1);
	Command_SetProvider(1);
	Command_SetPlayer(YCMD:cmd1, playerid, true);
	Command_SetPlayer(YCMD:cmd2, playerid, true);
	Command_SetPlayer(YCMD:cmd3, playerid, true);
	Command_SetProvider(-1);
	CMDPASS(cmd1, provider2);
	CMDPASS(cmd2, provider2);
	CMDPASS(cmd3, provider2);
	ASSERT(gPass == 0);
	Command_SetPlayerProvider(playerid, -1);
}

