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
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 0.0, 160.0, 120.0, 0xFF0000FF, "Hello"));
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
/*	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 0.0, 50.0, 60.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 60.0, 100.0, 60.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 120.0, 50.0, 60.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 180.0, 100.0, 60.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 240.0, 50.0, 60.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 300.0, 100.0, 60.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 360.0, 50.0, 60.0, 0x00FF00FF, "Hello"));
	TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 420.0, 100.0, 60.0, 0x00FF00FF, "Hello"));*/
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(10.0, 10.0, 100.0, 100.0, 0x00FF00FF, "Hello"));
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(110.0, 10.0, 100.0, 100.0, 0x00FF00FF, "Hello"));
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(440.0, 280.0, 150.0, 150.0, 0x00FF00FF, "Hello"));
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(540.0, 380.0, 50.0, 50.0, 0xFF0000FF, "Hello"));
	//TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 480.0, 0.0, 60.0, 50.0, 0x00FF00FF, "Hello"));
	//TextDrawShowForPlayer(playerid, GUI_DrawBox(0.0, 540.0, 0.0, 60.0, 100.0, 0x00FF00FF, "Hello"));
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(640.0, 0.0, 20.0, 150.0, 0x00FF00FF, "Hello"));
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(220.0, 0.0, 20.0, 200.0, 0x00FF00FF, "Hello"));
//	TextDrawShowForPlayer(playerid, GUI_DrawBox(240.0, 0.0, 20.0, 250.0, 0x00FF00FF, "Hello"));
	//new GUI:g = GUI_Create(100.0, 100.0, 100.0, 100.0);
	//GUI_Button(g, 30.0, 10.0, 40.0, 20.0, "OK");
	//GUI_Button(g, 30.0, 40.0, 40.0, 20.0, "Cancel");
	//GUI_Button(g, 30.0, 70.0, 40.0, 20.0, "Back");
	//GUI_Show(playerid, g);
	new GUI:h = GUI_Window(100.0, 100.0, 100.0, 110.0, "Window");
	GUI_Button(h, 30.0, 20.0, 40.0, 20.0, "OK");
	GUI_Button(h, 30.0, 50.0, 40.0, 20.0, "Cancel");
	GUI_Button(h, 30.0, 80.0, 40.0, 20.0, "Back");
	GUI_Show(playerid, h);
}

CMD:test(playerid, params[])
{
	Testing_RunAll();
	return 1;
}

