// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

native WP_Hash(target[], len, text[]);

//#define _DEBUG 6

//#define YSI_DO_USER_UPGRADE
#define YSI_NO_X11
#define YSI_TESTS

#define RACE_POSITION

#define MODE_NAME "alltests"
#define PP_WP

#include <a_samp>
/*#include <YSI\y_commands>
#include <YSI\y_hooks>
#include <YSI\y_als>
#include <YSI\y_va>
#include <YSI\y_timers>
#include <YSI\y_svar>*/

//#include <YSI\y_groups>

//#include <YSI>
#include <YSI\y_hooks>
#include <YSI\y_als>
#include <YSI\y_va>
#include <YSI\y_timers>
#include <YSI\y_svar>
//#undef ALS_MAKE
#include <YSI\y_zonepulse>
#include <YSI\y_users>
#include <YSI\y_uvar>
#include <YSI\y_races>

#include <YSI\y_groups>

uvar gggx[MAX_PLAYERS][22];

public OnGameModeInit()
{
	printf("woo");
	Langs_Add("EN", "English");
	Langs_Add("NL", "Nederlands");
	AddPlayerClass(0, 0.0, 0.0, 4.0, 0.0, 0, 0, 0, 0, 0, 0);
	//Group_SetRace(Group:0, 0, true);
	return 1;
}
//#assert !defined _Group_AddInternal

