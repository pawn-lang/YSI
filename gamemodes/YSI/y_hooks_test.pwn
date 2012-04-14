// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#define _YSI_NO_VERSION_CHECK

#include <a_samp>
#include <YSI\y_hooks>
#include <YSI\y_iterate>

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
	state go:n;
	CallLocalFunction("OnPlayerConnect", "i", 42);
	CallLocalFunction("OnPlayerDisconnect", "ii", 42, 5);
	state go:y;
	CallLocalFunction("OnPlayerConnect", "i", 42);
	CallLocalFunction("OnPlayerDisconnect", "ii", 42, 5);
}

hook OnPlayerConnect(playerid) <go:n>
{
	printf("opc n");
	return 1;
}

rehook OnPlayerConnect(playerid) <go:y>
{
	printf("opc y");
	foreach (Player, h)
	{
		printf("Player: %d", h);
	}
	return 1;
}

hook OnPlayerDisconnect(playerid, reason) <go:n>
{
	printf("opdc n");
	return 1;
}

rehook OnPlayerDisconnect(playerid, reason) <go:y>
{
	printf("opdc y");
	foreach (Player, h)
	{
		printf("Player: %d", h);
	}
	return 1;
}

