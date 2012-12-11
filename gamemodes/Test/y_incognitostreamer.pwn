// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#define INCLUDE_TESTS

#include <a_samp>
#include <streamer>
#include <YSI\y_groups>
#include <YSI\y_testing>
#include <YSI\y_commands>

new
	gPlayerid;

YCMD:run(playerid, params[], help)
{
	gPlayerid = playerid;
	Testing_RunAll();
}

Test:Create1()
{
	new
		Group:g = Group_Create(),
		area,
		pickup,
		Text3D:text;
	GROUP_ADD<g>
	{
		@YCMD:run;
		area = CreateDynamicRectangleEx(0.0, 0.0, 10.0, 10.0);
		pickup = CreateDynamicPickup(1337, 2, 0.0, 0.0, 4.0);
		text = CreateDynamic3DTextLabelEx("hi", 0xFF0000AA, 0.0, 0.0, 5.0, 7.0);
	}
	//Group_SetSPickup(g, pickup, true);
	//Group_SetSArea(g, area, true);
	//Group_SetSText3D(g, text, true);
}

