#include <YSI\y_groups>
#include <YSI\y_dialog>
#include <YSI\y_commands>
#include <YSI\y_text>
#include <YSI\y_jaggedarray>
#include <YSI\y_iterate>
#include <YSI\y_hooks>

// Return armour.
#define A(%0) (GetPlayerArmour((%0),Float:J@),Float:J@)
// Booleans.  Either:
//  
//  B:arr<42> = true;
//  
// Or:
//  
//  new
//      bool:a = B:arr<42>;
//  
#define B:%0<%1> (bool:QWERTY@B0:QWERTY@B1:QWERTY@B2:Bit_GetBit(Bit:%0,_:%1))
// Already in YSI (sorry).
//#define C
// Dialog with callback.  Now with optional ID.
#define D%9(%0,%1,%2$%3,%4) new Q@D3:__%3%9;static const %3%9__[]=":...:iiiis";Q@DF(%3%9__);Text_DialogBox(%0,%1,callback_tag:%3%9__,$%3,%4);for(new playerid,dialogid,response,listitem,inputtext[YSI_MAX_STRING];Q@DL(.y=_:__%3%9,.f=%3%9__);)
//#define E 
// Function.
#define F:%1(%2) forward %1(%2);public %1(%2)
#define G(%0) (_QWERTY_Group=Group_Create(%0));GROUP_ADD<Group:_QWERTY_Group>
// Return health.
#define H(%0) (GetPlayerHealth((%0),Float:J@),Float:J@)
// Iterator:
//  
//  I
//  {
//  }
//  
// I might rewrite this to use underlying foreach code instead of just the
// "foreach" macro to make the generated code much shorter (but also much less
// portable).
#define I foreach (new i : Player)
// Jagged array:
//  
//  new J:arr[10]<1, 1, 2, 3, 5, 8, 13, 21, 34, 55>;
//  
#define J:%0[%1]<%2> %0[%1][CEILDIV(_:QWERTY@J0:QWERTY@J1(%2),(%1))];Jagged_Resize(%0,%2)
// "Klass_Add".
//#define K Class_Add
// Loop:
//  
//  L(i, 42)
//  {
//  }
//  
#define L(%0,%1) for (new %0 = 0; %0 != (%1); ++%0)
//#define M GivePlayerMoney
//#define N ReturnPlayerName
#define N(%0) (GetPlayerName(%0,_QWERTY_Name,MAX_PLAYER_NAME),_QWERTY_Name)
#if defined CreateDynamicObject
	#define O CreateDynamicObject
#else
	#define O CreateObject
#endif
// Already in YSI (sorry).
//#define P
#define Q! for(new QWERTYUIOP_unknownVar@Z=0;QWERTYUIOP_unknownVar@Z!=sizeof(QWERTYUIOP_gUnknownVar@Z);++QWERTYUIOP_unknownVar@Z)print(QWERTYUIOP_gUnknownVar@Z[QWERTYUIOP_unknownVar@Z]);
//#define R random
// Send Message.
#define S Text_Send
// Text with any sort of formatting (short (130)).
#define T va_return
//#define U uvar
// CreateVehicle with iterator initialisation.
#define V(%0) (J@=CreateVehicle(%0),Itter_AddInternal(Vehicle@YSII_Cg,Vehicle@YSII_Ag,J@,sizeof(Vehicle@YSII_Ag)-1),J@)
// Wait:
//  
//  W(1000);
//  
// Waits for 1000 milliseconds.
#define W(%0)%1; {new QWERTY@W;static const _QWERTY@W[]="@WAIT:...:";if(!Inline_Loop(INLINE_LOOP_PATTERNS,QWERTY@W,_QWERTY@W))return QWERTY_Wait((%0),callback_tag:_QWERTY@W);}

// "X" marks the spot of a bug.
//#define X printf
// YCMD.  Either:
//  
//  Y<group>:cmd(playerid, params[], help)
//  
// Or:
//  
//  Y:cmd(playerid, params[], help)
//  
#define Y%9:%0(%1) forward QWERTY@Y0:@yQ_%0();QWERTY@Y1:@yQ_%0(){return QWERTY@Y(#%0,#%9);}RC:%0(%1)
// "Zone".
//#define Z Area_Add

/*----------------------------------------------------------------------------*-
 |                                                                            | 
 | And now come the support functions and macros to make the above code work. | 
 |                                                                            | 
-*----------------------------------------------------------------------------*/

//stock QWERTY@D_Loop(p0, p1, p2, p3, &__yil, volatile const {QWERTY@D0, QWERTY@D2, _}:format[])
stock Q@DL(p0 = INLINE_LOOP_PATTERN_0, p1 = INLINE_LOOP_PATTERN_1, p2 = INLINE_LOOP_PATTERN_2, p3 = INLINE_LOOP_PATTERN_3, &y = 0, volatile const f[] = "")
//stock Q@DL(p0, p1, p2, p3, &__yil, volatile const {Q@D0, Q@D2, _}:format[])
{
	P:4("Q@DL called: %d, %s", y, f);
	#pragma unused p0, p1, p2, p3, f
	if (y)
	{
		// Somehow I need to check 
		#emit LOAD.S.alt 0
		#emit MOVE.pri
		#emit ADD.C      4
		#emit LOAD.I
		#emit XCHG
		#emit LOAD.I
		#emit SCTRL      5
		#emit MOVE.pri
		#emit SCTRL      6
	}
	y = 1;
	return 0;
}

//stock QWERTY@D_Fake(const {QWERTY@D0, QWERTY@D1, _}:str[], num = 4 + YSI_MAX_STRING)
stock Q@DF(const str[], num = 4 + YSI_MAX_STRING)
{
	P:4("Q@DF called: %s, %d", str, num);
	//printf("num = %d", num);
	// This function needs to be modified to store the stack size at this point
	// and write it to the relevant slot (easy since the relevant slot is
	// passed).  I know "volatile const" makes no sense, but "const" is for the
	// compiler, "volatile" is to show that really it does change.
	// Get the number of parameters passed to the last function.
	#emit LOAD.S.pri    0
	#emit ADD.C         8
	#emit LOAD.I
	#emit PUSH.pri
	// Get the local variable sizes.  Need to allocate the data somewhere.
	#emit LCTRL         5
	#emit ADD.C         20 // 2 * 4 + 12
	// Subtract the parameters passed to this function.
	// Subtract the start of this function.
	#emit LOAD.S.alt    0
	#emit SUB.alt
	// Add on the extra parameters that don't exist yet (inputtext et al.)
	#emit LOAD.S.alt    num
	#emit SHL.C.alt     2
	#emit ADD
	#emit PUSH.pri
	// Don't do strfind, the 
	#emit LOAD.S.pri    str
	#emit ADD.C         12
	//#emit ADD
	#emit STOR.S.pri    str
	#emit POP.alt
	#emit SHL.C.alt     6
	#emit POP.pri
	#emit SHR.C.pri     2
	#emit ADD
	#emit SREF.S.pri    str
	//printf("%04x", str[0]);
	return 0;
}

stock
	Group:_QWERTY_Group,
	_QWERTY_Name[MAX_PLAYER_NAME];

//#define Q@DF(%3:%9__);Text_DialogBox(%0,%1,callback_tag:%4:%5__,$%8);for(%7; Q@DF(%3%9__);Text_DialogBox(%0,%1,callback_tag:%4%5__,$%8);for(new playerid%3,dialogid%3,response%3,listitem%3,inputtext%3[YSI_MAX_STRING];
#define Q@DF(%3:%9__);Text_DialogBox(%0,%1,callback_tag:%4:%5__,$%8);for(%7; Q@DF(%3%9__);Text_DialogBox(%0,%1,callback_tag:%4%5__,$%8);for(new playerid%9,dialogid%9,response%9,listitem%9,inputtext%9[YSI_MAX_STRING];
#define Q@DL(.y=_:__%3:%9,.f=%4:%5__);) Q@DL(.y=_:__%3%9,.f=%4%5__);)
//#define Q@D2:%3:%9__);) %3%9__);)
#define Q@D3:%3:%0;static%1:%2__[] %3%0;static%1%2__[]

#define QWERTY@J0:QWERTY@J1(%0,%1) %0+_:QWERTY@J0:QWERTY@J1(%1)
#define QWERTY@J1(%0) %0

// Strip any "<>" from around the group name.
#define QWERTY@Y0:%0();QWERTY@Y1:%1(){%3(#%2,#<%9>);} QWERTY@Y0:%0();QWERTY@Y0:%1(){%3(#%2,#%9);}

// Remove the group set function if there is no group set (leave the forward).
#define QWERTY@Y1:%1(){%3(#%2,#%9);}

stock QWERTY@Y0:QWERTY@Y(cmd[], group[])
{
	//printf("QWERTY@Y called: %d %s %s", gg, cmd, group);
	if (!isnull(group))
	{
		G(group)
		{
			Command_TouchNamed(cmd);
		}
	}
	return QWERTY@Y0:1;
}

stock QWERTY_TouchGroupCommands()
{
	//printf("TOUCH");
	new
		idx,
		buffer;
	while ((idx = AMX_GetPublicPointerPrefix(idx, buffer, _A<@yQ_>)))
	{
		#emit PUSH.C     0
		#emit LCTRL      6
		#emit ADD.C      28
		#emit PUSH.pri
		#emit LOAD.S.pri buffer
		#emit SCTRL      6
	}
}

/*----------------------------------------------------------------------------*\
Wait.
\*----------------------------------------------------------------------------*/

forward @QWERTY_Wait(a, b, c, d);

public @QWERTY_Wait(a, b, c, d)
{
	new
		res[E_CALLBACK_DATA];
	res[E_CALLBACK_DATA_FLAGS] = e_CALLBACK_FLAGS:a;
	res[E_CALLBACK_DATA_POINTER] = b;
	res[E_CALLBACK_DATA_FORMAT] = c;
	res[E_CALLBACK_DATA_ALLOC] = Alloc:d;
	Callback_Call(res);
	Callback_Release(res);
}

stock QWERTY_Wait(delay, callback:c)
{
	new
		res[E_CALLBACK_DATA];
	Callback_Get(c, res, _F<>);
	SetTimerEx("@QWERTY_Wait", delay, false, "iiii", _:res[E_CALLBACK_DATA_FLAGS], res[E_CALLBACK_DATA_POINTER], res[E_CALLBACK_DATA_FORMAT], _:res[E_CALLBACK_DATA_ALLOC]);
	return cellmin;
}

/*----------------------------------------------------------------------------*\
Code VERY internal to y_groups!
\*----------------------------------------------------------------------------*/

/*static stock
	_yGI,
	_yGA,
	bool:QWERTY_gInit = false;

forward _yGA@QWERTY(&group);

public _yGA@QWERTY(&group)
{
	GROUP_CHAIN?<_yGA>(group);
	if (QWERTY_gInit)
	{
		// New group created, update commands MATCHING THIS GROUP.
		QWERTY_TouchGroupCommands(group | _:GROUP_MASK);
	}
}

forward _yGI@QWERTY(&ni, &na, &nu);

public _yGI@QWERTY(&ni, &na, &nu)
{
	if (ni != -1)
	{
		ni = AMX_GetPublicPointerPrefix(ni, _yGI, _A<_yGI>);
		na = AMX_GetPublicPointerPrefix(na, _yGA, _A<_yGA>);
	}
	GROUP_CHAIN?<_yGI>(ni, na, nu);
}*/

static stock
	bool:QWERTY_gInit = false;

public OnFilterScriptInit()
{
	if (!QWERTY_gInit)
	{
		CallLocalFunction("QWERTY_OnFilterScriptInit", "");
		QWERTY_TouchGroupCommands();
		QWERTY_gInit = true;
	}
	return 1;
}
#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit QWERTY_OnFilterScriptInit
forward QWERTY_OnFilterScriptInit();

public OnGameModeInit()
{
	if (!QWERTY_gInit)
	{
		CallLocalFunction("QWERTY_OnGameModeInit", "");
		QWERTY_TouchGroupCommands();
		QWERTY_gInit = true;
	}
	return 1;
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit QWERTY_OnGameModeInit
forward QWERTY_OnGameModeInit();

#define QWERTY@B0:QWERTY@B1:QWERTY@B2:Bit_GetBit(Bit:%0,_:%1))%7=%8, Bit_Set(%0,%1,%8)),
#define QWERTY@B1:QWERTY@B2:Bit_GetBit(Bit:%0,_:%1))%7=%8) Bit_Set(%0,%1,%8)))
#define QWERTY@B2:Bit_GetBit(Bit:%0,_:%1))%7=%8; Bit_Set(%0,%1,%8));

// Hook group initialisation so we know when a new group that might own a
// command is created.  Of course, make sure this comes last always, so that we
// know the command groups have been initialised.  TODO: This.

stock
	Iterator:Vehicle<MAX_VEHICLES>;

stock const
	QWERTYUIOP_gUnknownVar@Z[][] =
	{
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x2020202E, 0x203A3A3A, 0x3A3A2C20, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202000},
		{0x20202020, 0x20202020, 0x20202020, 0x2020202E, 0x32766920, 0x20424020, 0x20205342, 0x4A202E2E, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202000},
		{0x20202020, 0x20202020, 0x2020202C, 0x4C2C2020, 0x42402020, 0x20404D20, 0x20204640, 0x20202020, 0x2E404269, 0x2C202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202000},
		{0x20202020, 0x3A2C723A, 0x692C2E3A, 0x402E2020, 0x69402E2E, 0x2E4D402E, 0x2C2E4040, 0x202E2C20, 0x40422020, 0x202E4A2E, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202000},
		{0x20202020, 0x69203059, 0x37723A20, 0x4A402020, 0x2E402020, 0x206B4220, 0x2020426A, 0x20202042, 0x422E2020, 0x20724275, 0x2E202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202000},
		{0x20202020, 0x2069203A, 0x724D353A, 0x20425520, 0x20423220, 0x20504020, 0x20204020, 0x20202042, 0x72202020, 0x4C427220, 0x203B2020, 0x20202020, 0x20202020, 0x20202020, 0x202C3731, 0x353A3A3A, 0x3A594D42, 0x75202020, 0x20202020, 0x20202000},
		{0x20372C76, 0x724F7220, 0x202E5337, 0x20204220, 0x20504220, 0x20584220, 0x204D4220, 0x20203840, 0x20202020, 0x4255203A, 0x203B3020, 0x20202020, 0x20202020, 0x203A3540, 0x424D692E, 0x20202020, 0x2020202C, 0x7140533A, 0x20202020, 0x20202000},
		{0x20372075, 0x4042405A, 0x2E206976, 0x37206940, 0x20204020, 0x205A4020, 0x20422020, 0x202C4020, 0x20202042, 0x40202020, 0x76424058, 0x20202072, 0x3A206942, 0x40424069, 0x20202020, 0x20203A55, 0x40424D50, 0x4E424042, 0x4C697620, 0x20202000},
		{0x20202020, 0x2E3A7240, 0x374C2072, 0x69762E76, 0x35204276, 0x20403720, 0x53402020, 0x20403820, 0x20204240, 0x20202042, 0x423A2020, 0x2050424E, 0x20374240, 0x42202020, 0x202E5340, 0x42404240, 0x42404240, 0x40404240, 0x42404240, 0x2E202000},
		{0x20202020, 0x20202037, 0x722E7669, 0x3A20723B, 0x692E694D, 0x20402E20, 0x403A2020, 0x72422020, 0x20424020, 0x20204042, 0x20202076, 0x40352020, 0x40424220, 0x2020204E, 0x40424042, 0x426A3A20, 0x20202020, 0x20203A59, 0x4F4E4020, 0x2E3A2000},
		{0x20202020, 0x20203755, 0x72205340, 0x69752069, 0x3A3A2E72, 0x2040203A, 0x40202020, 0x42692020, 0x47402020, 0x20404220, 0x20204240, 0x3A203A40, 0x42372020, 0x20404240, 0x473A2020, 0x20202020, 0x20202020, 0x20202020, 0x2020424F, 0x203A2E00},
		{0x20202020, 0x202E7276, 0x372C4C5A, 0x3A6B4620, 0x76202E76, 0x3542204D, 0x72202042, 0x40202075, 0x40202020, 0x404F2020, 0x3A424020, 0x20374042, 0x20202053, 0x40427520, 0x20202020, 0x203A6969, 0x4C6B5853, 0x58313A3A, 0x20207242, 0x20207500},
		{0x20202020, 0x202E7575, 0x3769203A, 0x59767242, 0x204E3A69, 0x424A2040, 0x20205540, 0x20202040, 0x76202C40, 0x4F202072, 0x40402020, 0x6B404220, 0x20204240, 0x5A202020, 0x20724240, 0x42404240, 0x42404040, 0x42404240, 0x42404D6A, 0x42404200},
		{0x20202020, 0x2020466A, 0x4C2E7259, 0x7655693A, 0x462E403A, 0x402E464F, 0x2020403A, 0x20204055, 0x20204042, 0x20202042, 0x40202069, 0x40422020, 0x2E42402C, 0x20206942, 0x40424038, 0x4C692C20, 0x20202020, 0x20202C3A, 0x3730402C, 0x404E7200},
		{0x20202020, 0x2020322E, 0x3A207237, 0x203A696A, 0x422E2020, 0x20203172, 0x20404220, 0x20404220, 0x2E404245, 0x20206940, 0x4E202040, 0x424A2020, 0x40402020, 0x69404240, 0x552C2020, 0x20202020, 0x20202020, 0x20202020, 0x20202076, 0x42202000},
		{0x20202020, 0x203A463A, 0x6920752E, 0x203A2E72, 0x20202020, 0x20202020, 0x3A422020, 0x42402020, 0x40202C42, 0x20204042, 0x72202042, 0x4020202E, 0x402E2020, 0x40423020, 0x20202020, 0x20202069, 0x37304742, 0x40424042, 0x4F586920, 0x452C2C00},
		{0x20202020, 0x206A2020, 0x5920202E, 0x592E3A20, 0x20202020, 0x20202020, 0x20202E53, 0x42202040, 0x76202040, 0x20204F40, 0x20202040, 0x4020202E, 0x423A2020, 0x42402020, 0x20202072, 0x45404240, 0x40404240, 0x42404240, 0x4240422E, 0x42404200},
		{0x20202020, 0x20592020, 0x2C20204C, 0x204C2020, 0x20202020, 0x20202020, 0x20202072, 0x58206940, 0x20202042, 0x69203A42, 0x69202042, 0x40692020, 0x404D2020, 0x40422C20, 0x20204042, 0x40404D72, 0x2E202020, 0x20202020, 0x20207676, 0x40207200},
		{0x20202020, 0x20203A3A, 0x20204A4A, 0x3A2E2020, 0x20202020, 0x20202020, 0x20202020, 0x202E7572, 0x20202045, 0x42202040, 0x42202030, 0x426B2020, 0x38402020, 0x4D405020, 0x20554240, 0x4F202020, 0x20202020, 0x20202020, 0x20202C69, 0x40202C00},
		{0x20202020, 0x2020202E, 0x3A3A722C, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20204A20, 0x69423720, 0x402C204D, 0x4020202E, 0x40422020, 0x20423020, 0x20424020, 0x20404035, 0x20202020, 0x20202E37, 0x6A58404D, 0x4D4E762E, 0x403A2000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20203A37, 0x4240423A, 0x20402020, 0x40402020, 0x42403A20, 0x20474220, 0x204A423A, 0x20464220, 0x20204A40, 0x42404240, 0x42404240, 0x4240532E, 0x40202000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202032, 0x4020204F, 0x76714520, 0x72424A20, 0x20424020, 0x20204042, 0x20203142, 0x692E403A, 0x40424053, 0x3A202020, 0x20202020, 0x2037313A, 0x40202000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x37202020, 0x69534276, 0x204C404C, 0x202E4240, 0x20202042, 0x42692075, 0x42696975, 0x47202020, 0x20202020, 0x20202020, 0x2E2E692C, 0x42462000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x2E4C404F, 0x202C3038, 0x20204542, 0x72202C42, 0x402C2020, 0x40423A20, 0x20202020, 0x202E203A, 0x46404042, 0x4042402E, 0x203A2020, 0x40752000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20204D4F, 0x475A3537, 0x20202C37, 0x764A2E4E, 0x3A202020, 0x20202020, 0x20202020, 0x20205340, 0x504A372E, 0x2E4F4C20, 0x37692020, 0x42382000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x2020203A, 0x20202C72, 0x20202E37, 0x2020204C, 0x20202020, 0x20202020, 0x20202020, 0x20202076, 0x20202020, 0x203A203A, 0x4F372020, 0x40402000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x2020204C, 0x42475A37, 0x20202040, 0x31697637, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x59536B4A, 0x4E372045, 0x37722E20, 0x40402000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x2020204C, 0x20202C37, 0x2020206A, 0x2020552E, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x3A2C2020, 0x20692020, 0x69552020, 0x40462000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x2020206B, 0x3A2C2C3A, 0x20202037, 0x20203A2E, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x204F7237, 0x374E202E, 0x69312069, 0x42463A00},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202047, 0x35354020, 0x20202042, 0x4D4F4020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x2E322020, 0x2E58202E, 0x40752072, 0x40594600},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202069, 0x20202C2E, 0x2020204C, 0x2020692E, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x2E3A2020, 0x20752020, 0x69762040, 0x42202000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202047, 0x4E714F20, 0x2020202C, 0x75724620, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20424747, 0x40372020, 0x202C2040, 0x406A4F00},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202059, 0x20203A3A, 0x20202020, 0x4E376B20, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x593A2020, 0x692E2020, 0x20203A40, 0x76203A00},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x2020204E, 0x536B593A, 0x20202069, 0x2E207220, 0x20202020, 0x20202020, 0x20202020, 0x2020202E, 0x353A7235, 0x47202020, 0x20202C42, 0x20202000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202E72, 0x20695A20, 0x20202037, 0x693A373A, 0x20202020, 0x20202020, 0x20202020, 0x20202075, 0x692E202E, 0x37202020, 0x20206920, 0x2E374200},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x204F4042, 0x7220692E, 0x2020204D, 0x3A2C726B, 0x20202020, 0x20202020, 0x20202020, 0x20204D76, 0x20202E4D, 0x2C202020, 0x20204D2C, 0x20204A00},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x694D3558, 0x4F692020, 0x20202040, 0x42404271, 0x20202020, 0x20202020, 0x20202020, 0x20404240, 0x4076202E, 0x20202020, 0x20404040, 0x404D2000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202000},
		{0x2020206F, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F6F6F20, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F6F6F6F, 0x206F6F6F, 0x6F6F6F6F, 0x6F6F6F2E, 0x20206F6F, 0x6F6F6F6F, 0x6F6F6F2E, 0x20202020, 0x20202020, 0x202E6F2E, 0x20202020, 0x2020202E, 0x6F2E202E, 0x6F2E2000},
		{0x20206427, 0x22222222, 0x22226438, 0x38382720, 0x60383838, 0x27202020, 0x20206038, 0x20603838, 0x38272020, 0x20605938, 0x62206038, 0x38382020, 0x20605938, 0x382E2020, 0x20202020, 0x2E383838, 0x2E202020, 0x20202038, 0x38382038, 0x38382000},
		{0x20202020, 0x20202020, 0x2E383838, 0x50202020, 0x20383838, 0x20202020, 0x20202020, 0x20203838, 0x38202020, 0x20203838, 0x38202038, 0x38382020, 0x202E6438, 0x38272020, 0x2020202E, 0x38223838, 0x382E2020, 0x20202038, 0x38382038, 0x38382000},
		{0x20202020, 0x20202064, 0x38383827, 0x20202020, 0x20383838, 0x6F6F6F6F, 0x38202020, 0x20203838, 0x386F6F6F, 0x6F383838, 0x27202038, 0x38386F6F, 0x6F383850, 0x27202020, 0x20202E38, 0x27206038, 0x38382E20, 0x20202059, 0x38502059, 0x38502000},
		{0x20202020, 0x202E3838, 0x38502020, 0x20202020, 0x20383838, 0x20202020, 0x22202020, 0x20203838, 0x38202020, 0x20603838, 0x62202038, 0x38386038, 0x38622E20, 0x20202020, 0x202E3838, 0x6F6F6F38, 0x3838382E, 0x20202060, 0x38272060, 0x38272000},
		{0x20202020, 0x64383838, 0x27202020, 0x202E5020, 0x20383838, 0x20202020, 0x2020206F, 0x20203838, 0x38202020, 0x202E3838, 0x50202038, 0x38382020, 0x60383862, 0x2E202020, 0x2E382720, 0x20202020, 0x60383838, 0x2E20202E, 0x6F2E202E, 0x6F2E2000},
		{0x20202E38, 0x38383838, 0x38383838, 0x38502020, 0x6F383838, 0x6F6F6F6F, 0x6F6F6438, 0x206F3838, 0x38626F6F, 0x64385027, 0x20206F38, 0x38386F20, 0x206F3838, 0x386F206F, 0x38386F20, 0x20202020, 0x6F383838, 0x386F2059, 0x38502059, 0x38502000},
		{0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202020, 0x20202000}
	};
