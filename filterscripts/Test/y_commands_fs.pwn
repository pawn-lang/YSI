// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#pragma compress 0

//#define _DEBUG 2

#include <a_samp>

//#define YSI_IS_CLIENT

#include <YSI\y_commands>

CMD:fs0(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs0: FS!");
	return 1;
}

CMD:fs1(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs1: FS!");
	return 1;
}

#define MASTER 5
#include <YSI\y_master>

CMD:fs2(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs2: FS!");
	return 1;
}

CMD:fs3(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs3: FS!");
	return 1;
}

#define MASTER 6
#include <YSI\y_master>

CMD:fs4(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs4: FS!");
	return 1;
}

CMD:fs5(playerid, params[])
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:fs5: FS!");
	return 1;
}

public OnFilterScriptInit()
{
	printf("================");
	printf("| Master ID: %d |", _@);
	printf("================");
	new
		idx,
		buffer[32],
		os[32];
	while ((idx = AMX_GetPublicNamePrefix(idx, buffer, _A<@yC_>)))
	{
		P:2("Command_OnScriptInit: Adding %s", unpack(buffer));
		//strunpack(os, buffer);
		strunpack(os, buffer[1]);
		P:2("Command_OnScriptInit: Adding %s", os);
		if ('0' <= os[0] <= '9')
		{
			new
				pos = strfind(os, "_");
			if (pos != -1)
			{
				// Only set the provider if a valid command is found.
				new
					id = Command_GetID(os);
				Command_SetProvider(_@);
				Command_AddAlt(id, os[pos + 1]);
				Command_SetProvider(-1);
			}
		}
		//Command_Add(buffer, _@);
		//Command_Add(unpack(buffer), _@);
		//Command_Add(unpack(buffer), _@);
	}
}

#define MMU_FUNCTION<%0...%1> %01%1

#define CMD2:%0(%1) MMU_FUNCTION<@yC_..._%0>(%1,__master);MMU_FUNCTION<@yC_..._%0>(%1,__master)if((printf("__master: %d %d")||TRUE)&&__master!=_@)return 0;else

//@y_C // Don't think I've ever used this form before...

CMD2:cmd1(playerid, params[], help)
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:cmd1b: Message!");
	return 1;
}

CMD2:cmd2(playerid, params[], help)
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:cmd2b: Message!");
	return 1;
}

CMD2:cmd3(playerid, params[], help)
{
	SendClientMessage(playerid, 0x00FF00AA, "CMD:cmd3b: Message!");
	return 1;
}

