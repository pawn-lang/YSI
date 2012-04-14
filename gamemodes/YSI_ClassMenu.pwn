// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#define _DEBUG 3

#include <a_samp>

#include <YSI\y_classes>
#include <YSI\y_groups>
#include <YSI\y_commands>

#define CLASS_ADD(%0) Class_AddForGroup(CUR_GROUP,%0,0.0,0.0,4.0,0.0)

new
	Group:g_groupGangs,
	Group:g_groupServices,
	Group:g_groupGirlfriends,
	Group:g_groupBeach,
	Group:g_groupAgriculture,
	Group:g_groupWhores,
	Group:g_groupSport,
	Group:g_groupProfessional,
	Group:g_groupOther,
	//Group:g_groupNormal,
	Group:g_groupNone,
	g_skinCJ,
	Menu:g_menu;

main()
{
}

YCMD:kill(playerid, params[], help)
{
	SetPlayerHealth(playerid, 0.0);
	return 1;
	#pragma unused params, help
}

ShowMenu(playerid)
{
	// Don't let them select a class until they select a category.
	Class_DenySelection(playerid);
	ShowMenuForPlayer(g_menu, playerid);
}

public OnPlayerConnect(playerid)
{
	Group_SetPlayer(g_groupNone, playerid, true);
	ShowMenu(playerid);
}

public OnPlayerRequestClass(playerid, classid)
{
	if (classid == g_skinCJ)
	{
		ShowMenu(playerid);
	}
	else
	{
		SetPlayerPos(playerid, 0.0, 0.0, 5.0);
		SetPlayerFacingAngle(playerid, 0.0);
		SetPlayerCameraPos(playerid, 0.0, 4.0, 7.0);
		SetPlayerCameraLookAt(playerid, 0.0, 0.0, 6.0);
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
	printf("Remove from all...");
	RemoveFromAll(playerid);
	Group_SetPlayer(g_groupNone, playerid, true);
}

RemoveFromAll(playerid)
{
	Group_SetPlayer(g_groupGangs, playerid, false);
	Group_SetPlayer(g_groupServices, playerid, false);
	Group_SetPlayer(g_groupGirlfriends, playerid, false);
	Group_SetPlayer(g_groupBeach, playerid, false);
	Group_SetPlayer(g_groupAgriculture, playerid, false);
	Group_SetPlayer(g_groupWhores, playerid, false);
	Group_SetPlayer(g_groupSport, playerid, false);
	Group_SetPlayer(g_groupProfessional, playerid, false);
	Group_SetPlayer(g_groupOther, playerid, false);
}

public OnPlayerExitedMenu(playerid)
{
	// Don't let them close the type selection menu.
	ShowMenuForPlayer(g_menu, playerid);
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	// They selected a class type - set which one.
	HideMenuForPlayer(g_menu, playerid);
	switch (row)
	{
		case 0:
			Group_SetPlayer(g_groupGangs, playerid, true);
		case 1:
			Group_SetPlayer(g_groupServices, playerid, true);
		case 2:
			Group_SetPlayer(g_groupGirlfriends, playerid, true);
		case 3:
			Group_SetPlayer(g_groupBeach, playerid, true);
		case 4:
			Group_SetPlayer(g_groupAgriculture, playerid, true);
		case 5:
			Group_SetPlayer(g_groupWhores, playerid, true);
		case 6:
			Group_SetPlayer(g_groupSport, playerid, true);
		case 7:
			Group_SetPlayer(g_groupProfessional, playerid, true);
		case 8:
			Group_SetPlayer(g_groupOther, playerid, true);
	}
	Group_SetPlayer(g_groupNone, playerid, false);
	// Now let them select a normal class.
	Class_ReturnToSelection(playerid);
}

public OnGameModeInit()
{
	g_groupGangs = Group_Create("Gangs");
	g_groupServices = Group_Create("Services");
	g_groupGirlfriends = Group_Create("Girlfriends");
	g_groupBeach = Group_Create("Beach");
	g_groupAgriculture = Group_Create("Agriculture");
	g_groupWhores = Group_Create("Whores");
	g_groupSport = Group_Create("Sport");
	g_groupProfessional = Group_Create("Professional");
	g_groupOther = Group_Create("Other");
	//g_groupNormal = Group_Create("Normal");
	g_groupNone = Group_Create("None");
	#define CUR_GROUP g_groupNone
	g_skinCJ = CLASS_ADD(0);
	#undef CUR_GROUP
	#define CUR_GROUP g_groupGangs
	CLASS_ADD(105);
	CLASS_ADD(106);
	CLASS_ADD(107);
	CLASS_ADD(102);
	CLASS_ADD(103);
	CLASS_ADD(104);
	CLASS_ADD(114);
	CLASS_ADD(115);
	CLASS_ADD(116);
	CLASS_ADD(108);
	CLASS_ADD(109);
	CLASS_ADD(110);
	CLASS_ADD(121);
	CLASS_ADD(122);
	CLASS_ADD(123);
	CLASS_ADD(173);
	CLASS_ADD(174);
	CLASS_ADD(175);
	CLASS_ADD(117);
	CLASS_ADD(118);
	CLASS_ADD(120);
	CLASS_ADD(247);
	CLASS_ADD(248);
	CLASS_ADD(254);
	CLASS_ADD(111);
	CLASS_ADD(112);
	CLASS_ADD(113);
	CLASS_ADD(124);
	CLASS_ADD(125);
	CLASS_ADD(126);
	CLASS_ADD(127);
	#undef CUR_GROUP
	#define CUR_GROUP g_groupServices
	CLASS_ADD(165);
	CLASS_ADD(166);
	CLASS_ADD(280);
	CLASS_ADD(281);
	CLASS_ADD(282);
	CLASS_ADD(283);
	CLASS_ADD(288);
	CLASS_ADD(284);
	CLASS_ADD(285);
	CLASS_ADD(286);
	CLASS_ADD(287);
	CLASS_ADD(277);
	CLASS_ADD(278);
	CLASS_ADD(279);
	CLASS_ADD(274);
	CLASS_ADD(275);
	CLASS_ADD(276);
	CLASS_ADD(163);
	CLASS_ADD(164);
	#undef CUR_GROUP
	#define CUR_GROUP g_groupGirlfriends
	CLASS_ADD(195);
	CLASS_ADD(190);
	CLASS_ADD(191);
	CLASS_ADD(192);
	CLASS_ADD(193);
	CLASS_ADD(194);
	#undef CUR_GROUP
	#define CUR_GROUP g_groupBeach
	CLASS_ADD(138);
	CLASS_ADD(139);
	CLASS_ADD(140);
	CLASS_ADD(145);
	CLASS_ADD(146);
	CLASS_ADD(154);
	CLASS_ADD(251);
	CLASS_ADD(92);
	CLASS_ADD(97);
	CLASS_ADD(45);
	CLASS_ADD(18);
	#undef CUR_GROUP
	#define CUR_GROUP g_groupAgriculture
	CLASS_ADD(128);
	CLASS_ADD(129);
	CLASS_ADD(130);
	CLASS_ADD(131);
	CLASS_ADD(132);
	CLASS_ADD(133);
	CLASS_ADD(157);
	CLASS_ADD(158);
	CLASS_ADD(159);
	CLASS_ADD(160);
	CLASS_ADD(196);
	CLASS_ADD(197);
	CLASS_ADD(198);
	CLASS_ADD(199);
	CLASS_ADD(161);
	CLASS_ADD(162);
	CLASS_ADD(200);
	CLASS_ADD(201);
	CLASS_ADD(202);
	CLASS_ADD(31);
	CLASS_ADD(32);
	CLASS_ADD(33);
	CLASS_ADD(34);
	#undef CUR_GROUP
	#define CUR_GROUP g_groupWhores
	CLASS_ADD(152);
	CLASS_ADD(178);
	CLASS_ADD(237);
	CLASS_ADD(238);
	CLASS_ADD(243);
	CLASS_ADD(244);
	CLASS_ADD(207);
	CLASS_ADD(245);
	CLASS_ADD(246);
	CLASS_ADD(85);
	CLASS_ADD(256);
	CLASS_ADD(257);
	CLASS_ADD(64);
	CLASS_ADD(63);
	CLASS_ADD(87);
	CLASS_ADD(90);
	#undef CUR_GROUP
	#define CUR_GROUP g_groupSport
	CLASS_ADD(258);
	CLASS_ADD(259);
	CLASS_ADD(26);
	CLASS_ADD(51);
	CLASS_ADD(52);
	CLASS_ADD(80);
	CLASS_ADD(81);
	CLASS_ADD(23);
	CLASS_ADD(96);
	CLASS_ADD(99);
	#undef CUR_GROUP
	#define CUR_GROUP g_groupProfessional
	CLASS_ADD(11);
	CLASS_ADD(141);
	CLASS_ADD(147);
	CLASS_ADD(148);
	CLASS_ADD(150);
	CLASS_ADD(153);
	CLASS_ADD(167);
	CLASS_ADD(68);
	CLASS_ADD(171);
	CLASS_ADD(176);
	CLASS_ADD(177);
	CLASS_ADD(172);
	CLASS_ADD(179);
	CLASS_ADD(187);
	CLASS_ADD(189);
	CLASS_ADD(203);
	CLASS_ADD(204);
	CLASS_ADD(155);
	CLASS_ADD(205);
	CLASS_ADD(209);
	CLASS_ADD(217);
	CLASS_ADD(211);
	CLASS_ADD(219);
	CLASS_ADD(260);
	CLASS_ADD(16);
	CLASS_ADD(27);
	CLASS_ADD(264);
	CLASS_ADD(70);
	#undef CUR_GROUP
	#define CUR_GROUP g_groupOther
	CLASS_ADD(134);
	CLASS_ADD(135);
	CLASS_ADD(137);
	CLASS_ADD(181);
	CLASS_ADD(213);
	CLASS_ADD(212);
	CLASS_ADD(224);
	CLASS_ADD(230);
	CLASS_ADD(239);
	CLASS_ADD(249);
	CLASS_ADD(241);
	CLASS_ADD(242);
	CLASS_ADD(252);
	CLASS_ADD(253);
	CLASS_ADD(255);
	CLASS_ADD(29);
	CLASS_ADD(30);
	CLASS_ADD(49);
	CLASS_ADD(50);
	CLASS_ADD(57);
	CLASS_ADD(61);
	CLASS_ADD(62);
	CLASS_ADD(66);
	CLASS_ADD(73);
	CLASS_ADD(77);
	CLASS_ADD(78);
	CLASS_ADD(79);
	CLASS_ADD(82);
	CLASS_ADD(83);
	CLASS_ADD(84);
	#undef CUR_GROUP
	g_menu = CreateMenu("Select class category", 1, 220, 150, 200);
	AddMenuItem(g_menu, 0, "Gangs");
	AddMenuItem(g_menu, 0, "Services");
	AddMenuItem(g_menu, 0, "Girlfriends");
	AddMenuItem(g_menu, 0, "Beach");
	AddMenuItem(g_menu, 0, "Agricultural");
	AddMenuItem(g_menu, 0, "Whores");
	AddMenuItem(g_menu, 0, "Sport");
	AddMenuItem(g_menu, 0, "Professional");
	AddMenuItem(g_menu, 0, "Other");
}

