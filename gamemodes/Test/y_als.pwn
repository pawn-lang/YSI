// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

native WP_Hash(target[], size, text[]);

//#define YSI_DO_USER_UPGRADE
#define YSI_TESTS

#define MODE_NAME "alltests"
#define PP_WP

#include <a_samp>
#include <YSI\y_als>
#undef ALS_MAKE
#include <YSI\y_zonepulse>
#include <YSI\y_users>

public OnGameModeInit()
{
	Langs_Add("EN", "English");
	Langs_Add("NL", "Nederlands");
	AddPlayerClass(0, 0.0, 0.0, 4.0, 0.0, 0, 0, 0, 0, 0, 0);
}

