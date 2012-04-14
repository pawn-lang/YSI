// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>

#define RUN_TESTS

#include <YSI\y_testing>

#include <YSI\y_commands>
#include <YSI\y_gui2>
#include <YSI\y_iterate>

main()
{
}

Test:make2()
{
	new
		playerid = Iter_First(Player);
	ASSERT(playerid == 0);
	//TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 0.0, 320.0, 240.0, 0xFF0000FF));
	/*TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 50.0, 100.0, 10.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 100.0, 200.0, 10.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 150.0, 300.0, 10.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 200.0, 400.0, 10.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 250.0, 500.0, 10.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 300.0, 600.0, 10.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 350.0, 500.0, 10.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 400.0, 600.0, 10.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 450.0, 100.0, 10.0, 0x00FF00FF, "Hello"));*/
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 0.0, 160.0, 120.0, 0xFF0000FF, "Hello"));
	/*TextDrawShowForPlayer(playerid, GUI_DrawBox(160.0, 0.0, 160.0, 120.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(320.0, 0.0, 160.0, 120.0, 0x0000FFFF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(480.0, 0.0, 160.0, 120.0, 0xFF0000FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 120.0, 160.0, 120.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(160.0, 120.0, 160.0, 120.0, 0x0000FFFF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(320.0, 120.0, 160.0, 120.0, 0xFF0000FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(480.0, 120.0, 160.0, 120.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 240.0, 160.0, 120.0, 0x0000FFFF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(160.0, 240.0, 160.0, 120.0, 0xFF0000FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(320.0, 240.0, 160.0, 120.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(480.0, 240.0, 160.0, 120.0, 0x0000FFFF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 360.0, 160.0, 120.0, 0xFF0000FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(160.0, 360.0, 160.0, 120.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(320.0, 360.0, 160.0, 120.0, 0x0000FFFF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(480.0, 360.0, 160.0, 120.0, 0xFF0000FF, "Hello"));*/
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 0.0, 60.0, 50.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(60.0, 0.0, 60.0, 100.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(120.0, 0.0, 60.0, 50.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(180.0, 0.0, 60.0, 100.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(240.0, 0.0, 60.0, 50.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(300.0, 0.0, 60.0, 100.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(360.0, 0.0, 60.0, 50.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(420.0, 0.0, 60.0, 100.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(480.0, 0.0, 60.0, 50.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(540.0, 0.0, 60.0, 100.0, 0x00FF00FF, "Hello"));
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(640.0, 0.0, 20.0, 150.0, 0x00FF00FF, "Hello"));
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(220.0, 0.0, 20.0, 200.0, 0x00FF00FF, "Hello"));
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(240.0, 0.0, 20.0, 250.0, 0x00FF00FF, "Hello"));
}

CMD:test(playerid, params[])
{
	Testing_RunAll();
	return 1;
}

