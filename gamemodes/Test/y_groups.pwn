//#define _DEBUG 1
#define RUN_TESTS
#define _YSI_SPECIAL_DEBUG

//#include <streamer>
#include <YSI\y_groups>
#include <YSI\y_iterate>
#include <YSI\y_testing>

//#define REP(%0"%1") %0%1

public OnGameModeInit()
{
	//printf("hi");
	//printf(REP("#hi"));
}

public OnPlayerConnect(playerid)
{
	//printf("hi %d", playerid);
}

Test:000Global()
{
	call OnPlayerConnect(42);
	ASSERT(Group_GetPlayer(GROUP_GLOBAL, 42));
}

Test:Valid()
{
	new
		Group:g = Group_Create("Valid"),
		Group:i = Group_Create("Invalid");
	Group_Destroy(i);
	ASSERT_TRUE(Group_IsValid(g));
	ASSERT_FALSE(Group_IsValid(i));
	ASSERT_FALSE(Group_IsValid(Group:3));
}

Test:Create0()
{
	new
		Group:g = Group_Create();
	ASSERT(g != INVALID_GROUP);
}

Test:Create1()
{
	new
		Group:g = Group_Create("Group 1");
	ASSERT(g != INVALID_GROUP);
}

Test:GetID()
{
	new
		Group:g = Group_Create("Group 2");
	ASSERT(g == Group_GetID("Group 2"));
	ASSERT(!strcmp("Group 2", Group_GetName(g)));
}

Test:GetGang0()
{
	new
		Group:g = Group_Create("Group 3");
	ASSERT_FALSE(Group_GetGang(g));
}

Test:GetGang1()
{
	new
		Group:g = Group_Create("Group 4");
	Group_SetGang(g, true);
	ASSERT_TRUE(Group_GetGang(g));
}

Test:GetGang2()
{
	new
		Group:g = Group_Create("Group 5");
	Group_SetGang(g, true);
	Group_SetGang(g, false);
	ASSERT_FALSE(Group_GetGang(g));
}

Test:GetColour()
{
	new
		Group:g = Group_Create("Group 6");
	Group_SetColour(g, 0x11227654);
	ASSERT(Group_GetColor(g) == 0x112276AA);
	Group_SetColour(g, 0x76541122);
	ASSERT(Group_GetColor(g) == 0x765411AA);
	Group_SetColour(g, 0x65127412);
	ASSERT(Group_GetColor(g) == 0x651274AA);
}

Test:Set1()
{
	new
		Group:g = Group_Create("Group 7");
	ASSERT(Group_GetCount(g) == 0);
	Group_SetPlayer(g, 42, true);
	ASSERT_TRUE(Group_GetPlayer(g, 42));
	ASSERT(Group_GetCount(g) == 1);
	new
		c = 0;
	foreach (new p : Group(g))
	{
		ASSERT(p == 42);
		++c;
	}
	ASSERT(c == 1);
}

Test:Set2()
{
	new
		Group:g = Group_Create("Group 8");
	ASSERT(Group_GetCount(g) == 0);
	ASSERT_TRUE(Group_SetPlayer(g, 42, true));
	ASSERT(Group_GetCount(g) == 1);
	ASSERT_TRUE(Group_SetPlayer(g, 42, false));
	ASSERT_FALSE(Group_SetPlayer(g, 42, false));
	ASSERT(Group_GetCount(g) == 0);
	new
		c = 0;
	foreach (new p : Group(g))
	{
		++c;
	}
	ASSERT(c == 0);
}

Test:Set3()
{
	new
		Group:g = Group_Create("Group 8");
	Group_SetPlayer(g, 42, true);
	ASSERT(Group_GetCount(g) == 1);
	//W@(#On#PlayerDisconnect         ,x:#ii#,42, 0);
	call OnPlayerDisconnect(42, 0);
	//ASSERT(Group_GetCount(g) == 0);
	//call OnPlayerConnect(42);
	//ASSERT(Group_GetCount(g) == 0);
}

