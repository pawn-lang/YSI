// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

//#define DETECT_PLUGIN(%0) stock HAS_PLUGIN_%0 = 0;forward DETECT_PLUGIN_%0();public DETECT_PLUGIN_%0() HAS_PLUGIN_%0 = 1

//DETECT_PLUGIN(FIXES2);

//trynative

//if (HAS_PLUGIN(FIXES2))


native WP_Hash(target[], len, text[]);
//#define _DEBUG 4

//#define YSI_DO_USER_UPGRADE
//#define YSI_NO_X11
#define YSI_TESTS

#define RACE_POSITION

#define MODE_NAME "alltests"
#define PP_WP

#include <a_samp>
#include <f2\fixes>

#include <YSI\y_groups>

//#include <YSI>
#include <YSI\y_hooks>
#include <YSI\y_als>
#include <YSI\y_va>
#include <YSI\y_timers>
//#include <YSI\y_svar>
//#undef ALS_MAKE
#include <YSI\y_zonepulse>
#include <YSI\y_users>
//#include <YSI\y_uvar>
#include <YSI\y_races>

/*
4F6E506C
 O n P l
0079485F
   y H _
*/
//uvar gggx[MAX_PLAYERS][22];
//CC500 (836864)
main()
{
	new
		pointer;
	AMX_GetPublicPointer(0, pointer, "S@@_OnGameModeInit", true);
	printf("pointer = %d", pointer);
/*	#emit PUSH.C     0
	#emit LCTRL      6
	#emit ADD.C      28
	#emit PUSH.pri
	#emit LOAD.S.pri pointer
	#emit SCTRL      6*/
	printf("done");
}


public OnGameModeInit()
{
	//Func(0);
	printf("woo");
	Langs_Add("EN", "English");
	Langs_Add("NL", "Nederlands");
	AddPlayerClass(0, 0.0, 0.0, 4.0, 0.0, 0, 0, 0, 0, 0, 0);
	//Group_SetRace(Group:0, 0, true);
	//_Group_IncludeAllRace();
	new
	    i;
    printf("HEP = %d", AMX_HEADER_HEA - AMX_BASE_ADDRESS);
    #emit LCTRL 2
    #emit STOR.S.pri i
    printf("HEA = %d", i);
    #emit LCTRL 4
    #emit STOR.S.pri i
    printf("STK = %d", i);
    #emit LCTRL 3
    #emit STOR.S.pri i
    printf("STP = %d", i);
    printf("%d", i ? 6 : 7);
	new
		Group:g = Group_Create("TEST");//,
//		race = Race_Create();
//	printf("CLF");
//	CallLocalFunction("Group_ExclusiveRace@", "ii", _:0, race);
//	Group_ExclusiveRace(Group:0, race);
	//sleep 9;
	return 1;
}
//#assert !defined _Group_AddInternal

