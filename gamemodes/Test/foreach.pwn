// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>

#define _FOREACH_NO_TEST
#define FOREACH_NO_BOTS

//#include <foreach>
#include <YSI\y_iterate>

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
	new
		Iterator:test<10>;
	Iter_Add(test, 3);
	Iter_Add(test, 55);
	foreach (new i : test)
	{
		printf("%d", i);
	}
	foreach (new i : test)
	{
		Iter_SafeRemove(test, i, i);
	}
	new
		Iterator:test2[1]<10>;
	Iter_Init(test2);
	Iter_Add(test2[0], 3);
	Iter_Add(test2[0], 55);
	foreach (new i : test2[0])
	{
		printf("%d %d", i, Iter_Count(test2[0]));
	}
	foreach (new i : test2[0])
	{
		Iter_SafeRemove(test2[0], i, i);
	}
}

public OnPlayerConnect(playerid)
{
	printf("players: %d, random: %d", Iter_Count(Player), Iter_Random(Player));
	foreach (new i : Player)
	{
		printf("%d", i);
	}
}

public OnPlayerDisconnect(playerid, reason)
{
	printf("players: %d, random: %d", Iter_Count(Player), Iter_Random(Player));
	foreach (Player, i)
	{
		printf("%d", i);
	}
}

