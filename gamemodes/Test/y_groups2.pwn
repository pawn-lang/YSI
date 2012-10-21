// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT
//#define _DEBUG 4

//#define _YSI_SPECIAL_DEBUG
#define RUN_TESTS

#include <YSI\y_testing>

#define GROUP_LIBRARY_NAME<%0...%1> %0Test%1
#define GROUP_LIBRARY_SIZE 100

#include <YSI\y_groups>
#include <YSI\y_commands>

new
	gPl,
	gEl,
	bool:gS;

Test_SetPlayer(el, playerid, bool:s)
{
	gPl = playerid;
	gEl = el;
	gS = s;
	return 1;
}

Test:0Connect1()
{
	gPl = INVALID_PLAYER_ID;
	gEl = 100;
	gS = false;
	//new
	//	Group:g = Group_Create();
	Test_InitialiseFromGroups(8);
	ASSERT(gPl == INVALID_PLAYER_ID);
	ASSERT(gEl == 100);
	ASSERT(gS == false);
	call OnPlayerConnect(43, 0);
	ASSERT(gPl == 43);
	ASSERT(gEl == 8);
	ASSERT(gS == true);
	call OnPlayerDisconnect(43, 0);
}

Test:0Connect0()
{
	gPl = INVALID_PLAYER_ID;
	gEl = 100;
	gS = false;
	//new
	//	Group:g = Group_Create();
	call OnPlayerConnect(42, 0);
	ASSERT(gPl == INVALID_PLAYER_ID);
	ASSERT(gEl == 100);
	ASSERT(gS == false);
	//printf("%d %d %d", gPl, gEl, gS);
	Test_InitialiseFromGroups(7);
	ASSERT(gPl == 42);
	ASSERT(gEl == 7);
	ASSERT(gS == true);
	call OnPlayerDisconnect(42, 0);
}

Test:Chains()
{
	new
		Group:g = Group_Create();
	call OnPlayerConnect(44, 0);
	ASSERT_FALSE(Group_GetPlayer(g, 44));
	Group_SetGlobalGroup(g, true);
	ASSERT_TRUE(Group_GetPlayer(g, 44));
}

