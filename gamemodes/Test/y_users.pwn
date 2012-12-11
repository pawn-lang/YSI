// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT
//#define _DEBUG 7

#include <a_samp>

#define MODE_NAME y_users
#define PP_YSI
#include <sscanf2>
native WP_Hash(buffer[], len, const str[]);

//#define YSI_NO_X11

#include <YSI\y_commands>
#include <YSI\y_inline>
#include <YSI\y_users>
#include <YSI\y_extra>
#include <YSI\y_classes>
#include <YSI\y_text>

loadtext ftext[ftext], core[ysi_dialog];

main()
{
}

public OnGameModeInit()
{
	Langs_AddLanguage("English", "EN");
}

public OnPlayerLogin(playerid, yid)
{
	inline Response(pid, dialogid, response, listitem, string:text0[])
	{
		#pragma unused pid, dialogid, text0
		if(!response)
		{
			Text_Send(playerid, $LOGIN_KICK);
			Kick(playerid);
			return 1;
		}
		else
		{
			new nomegrado = listitem;
			inline Response1(pid1, dialogid1, response1, listitem1, string:text1[])
			{
				#pragma unused pid1, dialogid1, response1, listitem1, text1
				if (response)
				{

				}
			}
			Text_PasswordBox(playerid, using inline Response1, $RANK_PASSWORD_TITLE, $RANK_PASSWORD_MESSAGE, $DIALOG_OK, $DIALOG_CANCEL, nomegrado);
		}
	}
	Text_ListBox(playerid, using inline Response, $RANK_TITLE, $RANK_LIST, $DIALOG_OK, $DIALOG_CANCEL);
	return 1;
}

