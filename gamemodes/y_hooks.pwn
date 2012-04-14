// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIP
#define _DEBUG 2

#include <a_samp>
#include <YSI\y_timers>
#include <YSI\y_hooks>
//#include <YSI\y_commands>

/*Timer:woo0[1000]()
{
	printf("Timer woo0");
}

Timer:woo1[1000]()
{
	printf("Timer woo1");
}

Timer:woo2[1000]()
{
	printf("Timer woo2");
}

Timer:woo3[1000]()
{
	printf("Timer woo3");
}

Timer:woo4[4000]()
{
	printf("Timer woo4");
	haha();
}

Delay:haha[33,]()
{
	printf("Delay haha");
}*/

main()
{
	printf("main");
	CallRemoteFunction("OnPlayerUpdate", "i", 42);
}

Hook:s1_OnPlayerUpdate(playerid)
{
	printf("s1");
}

Hook:s2_OnPlayerUpdate(playerid)
{
	printf("s2");
}

Hook:s3_OnPlayerUpdate(playerid)
{
	printf("s3");
}

Hook:s4_OnPlayerUpdate(playerid)
{
	printf("s4");
}

Hook:s5_OnPlayerUpdate(playerid)
{
	printf("s5");
}

Hook:s6_OnPlayerUpdate(playerid)
{
	printf("s6");
}

Hook:s7_OnPlayerUpdate(playerid)
{
	printf("s7");
}

Hook:s8_OnPlayerUpdate(playerid)
{
	printf("s8");
}

Hook:Mine_OnGameModeInit()
{
	printf("Called");
}

public OnGameModeExit()
{
	printf("OGME");
}

