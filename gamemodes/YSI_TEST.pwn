//#pragma compress 0

//#pragma pack 0
#define _DEBUG 0
#pragma option -d0

#pragma option -O1

// Generic configurable settings.
#tryinclude <compile_flags>
//#define JUST_TEST Master_ModulesPhase6
//#define JUST_TEST DOESNT_EXIST
//#define JUST_TEST_GROUP "y_amx"
//#define RUN_SLOW_TESTS
//#define RUN_TESTS
#define YSI_TESTS
//#define RUN_PROFILINGS

#if defined __PawnBuild
	#pragma option -r
	//#pragma option -l
	//#pragma option -a

	/*#pragma warning disable 213
	#pragma warning disable 214
	#pragma warning disable 234
	#pragma warning disable 204
	#pragma warning disable 239
	#pragma warning disable 237*/
#endif

#if !defined COMPILE_FLAGS
	#define COMPILE_FLAGS "Pawno"
#endif

#if !defined _DEBUG
	#define _DEBUG -1
#endif

// Fixes settings.
#define FIXES_Single 0

/*#define FIXES_ExplicitSettings 1
#define FIXES_DefaultDisabled 1
#define FIXES_EnableAll 0
#define FIXES_EnableDeprecated 0
#define FIXES_ExplicitOptions 1
#define FIXES_SilentKick 0
#define FIXES_Debug 0
#define FIXES_NoSingleMsg 1
#define FIXES_NoServerVarMsg 1
#define FIXES_NoGetMaxPlayersMsg 1
#define FIXES_NoPawndoc 1
#define FIXES_CorrectInvalidTimerID 1
#define FIXES_NoYSI 0
#define FIXES_OneRandomVehicleColour 0
#define FIXES_NoVehicleColourMsg 1
#define FIXES_CountFilterscripts 0
#define FIXES_NoFilterscriptsMsg 1*/

#if !defined MTYPE
	// Some module tests in non-type-2.
	#define MTYPE 2 // 0 - 3 (None, Server, Cloud, Client)
#endif
#if !defined GTYPE
	#define GTYPE 2 // 0 - 3 (None, Start, Middle, End)
#endif

#if MTYPE == 0
	#define YSI_NO_MASTER
#elseif MTYPE == 1
	#define YSI_IS_SERVER
#elseif MTYPE == 2
	//#define YSI_IS_CLOUD // Doesn't exist (default).
#elseif MTYPE == 3
	#error Can't run tests as "CLIENT" (MTYPE 3).
	#define YSI_IS_CLIENT
#endif

#define MODE_NAME "YSI_TEST"
#define PP_WP
#define YSI_HASHMAP_TESTS
#define Y_COMMANDS_NO_IPC
#define PROFILINGS_FILE
//#define YSI_COMPATIBILITY_MODE
#define YSI_NO_HEAP_MALLOC

native WP_Hash(buffer[], len, const str[]);

//native NopNative() = nop;

/*IsNumeric(const number[])
{
	#pragma unused number
	return 0;
}*/

#define STRONG_TAGS

#tryinclude <samp-stdlib\a_samp>
#tryinclude <a_samp>
#tryinclude <crashdetect>
//#include <../fixes/fixes>

#tryinclude "..\sa-mp-fixes\fixes"
#tryinclude "..\..\sa-mp-fixes\fixes"
#tryinclude <sa-mp-fixes\fixes>
#tryinclude "..\fixes\fixes"
#tryinclude "..\..\fixes\fixes"
#tryinclude <fixes\fixes>
#tryinclude <fixes>

//#include <fixes>
#include <amx\disasm>

//#include <YSI_Server\y_lock>

public OnGameModeInit()
{
	//PrintBacktrace();
	#emit const.pri 64
	#emit sctrl 0xFF
	//#emit ZERO 0
	//AMX_WriteString(0, "hi");
	#emit const.pri 192
	#emit sctrl 0xFF
	#if defined YSI_OnGameModeInit
		YSI_OnGameModeInit();
	#endif
	__emit(CONST.pri 34, SCTRL 0xFF); // Enable
	__emit(CONST.pri 36, SCTRL 0xFF); // Reset
	__emit(CONST.pri 40, SCTRL 0xFF); // Restart
	//Server_EnableLongCall();
	//Server_ResetLongCallTime();
	printf("before...");
	/*for (new i = 0; i != 1000000; ++i)
	{
		for (new j = 0; j != 1000000; ++j)
		{
		}
	}*/
	printf("...after");
	return 1;
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit YSI_OnGameModeInit

#if defined YSI_OnGameModeInit
	forward YSI_OnGameModeInit();
#endif

#pragma dynamic 65536

#if GTYPE == 1
	#include <YSI_Players\y_groups>
#endif

// Failing tests are removed with "//", slow tests with "////".

#include <YSI_Core\y_als>
#include <YSI_Core\y_debug>
#include <YSI_Core\y_testing>
#include <YSI_Core\y_utils>
#include <YSI_Coding\y_va>
#include <YSI_Core\y_cell>
#include <YSI_Core\y_master>
#include <YSI_Core\y_profiling>

#include <YSI_Coding\y_hooks>
#include <YSI_Coding\y_inline>
#include <YSI_Coding\y_malloc>
#include <YSI_Coding\y_remote>
#include <YSI_Coding\y_stringhash>
#include <YSI_Coding\y_timers>
#include <YSI_Coding\y_ctrl>
#include <YSI_Coding\y_functional>

#include <YSI_Data\y_bintree>
#include <YSI_Data\y_circular>
#include <YSI_Data\y_bit>
#include <YSI_Data\y_hashmap>
#include <YSI_Data\y_iterate>
#include <YSI_Data\y_jaggedarray>
#include <YSI_Data\y_playerarray>
#include <YSI_Data\y_playerset>

#if GTYPE == 2
	#include <YSI_Players\y_groups>
#endif

/*#include <YSI_Players\y_languages>
//#include <YSI_Players\y_text>
//#include <YSI_Players\y_users>

#include <YSI_Server\y_colours>
#include <YSI_Server\y_flooding>
#include <YSI_Server\y_punycode>
#include <YSI_Server\y_scriptinit>
#include <YSI_Server\y_td>*/

#include <YSI_Storage\y_amx>
////#include <YSI_Storage\y_bitmap>
#include <YSI_Storage\y_ini>
//#include <YSI_Storage\y_php>
//#include <YSI_Storage\y_svar>
//#include <YSI_Storage\y_uvar>
#include <YSI_Storage\y_xml>

//#include <YSI_Visual\y_areas>
//#include <YSI_Visual\y_classes>
#include <YSI_Visual\y_commands>
#include <YSI_Visual\y_dialog>
//#include <YSI_Visual\y_properties>
//#include <YSI_Visual\y_races>
//#include <YSI_Visual\y_zonenames>
#include <YSI_Visual\y_zonepulse>

#if GTYPE == 3
	#include <YSI_Players\y_groups>
#endif

@init() F1()
{
}

@init(init_mode) F2()
{
}

main()
{
	print(" ");
	print("------------------------------");
	print("|                            |");
	print("|     YSI auto-test mode     |");
	print("|                            |");
	printf("| Compiler: 0x%04x           |", __Pawn);
	print("| Flags:                     |");
	printf("|  %24s  |", COMPILE_FLAGS);
	print("| Master:                    |");
	printf("|  %24d  |", @_);
	print("|                            |");
	print("------------------------------");
	print(" ");
	//FIXES_ApplyAnimation(0, "", "", 0.0, 0, 0, 0, 0, 0, 0);
	//DisasmDump("YSI_TEST.asm");
}

public OnScriptInit()
{
	if (FALSE)
	{
		printf("dumping...");
		DisasmWrite("PostDump.asm");
		printf("done!");
	}
//	Langs_Add("English", "EN");
	return 1;
}

public OnTestsComplete(tests, checks, fails)
{
	print(" ");
	print("------------------------------");
	print("|                            |");
	print("|     YSI auto-test done     |");
	print("|                            |");
	printf("| Compiler: 0x%04x           |", __Pawn);
	print("| Flags:                     |");
	printf("|  %24s  |", COMPILE_FLAGS);
	print("| Master:                    |");
	printf("|  %24d  |", @_);
	print("|                            |");
	print("------------------------------");
	print(" ");
}

new gAddr;
new gInput[128];
new gOutput[128];

Test_ReadUnpackedString1(addr, str[], len = sizeof (str))
{
	new
		buffer = 0,
		idx = 0;
	for ( ; ; )
	{
		// Read 4 bytes.
		#emit LREF.S.pri                addr
		#emit STOR.S.pri                buffer
		if (!(str[idx++] = buffer & 0xFF) || (idx == len))
		{
			return;
		}
		if (!(str[idx++] = (buffer >>> 8) & 0xFF) || (idx == len))
		{
			return;
		}
		if (!(str[idx++] = (buffer >>> 16) & 0xFF) || (idx == len))
		{
			return;
		}
		if (!(str[idx++] = buffer >>> 24) || (idx == len))
		{
			return;
		}
		addr += cellbytes;
	}
}

Test_ReadUnpackedString2(addr, str[], len = sizeof (str))
{
	new
		buffer = 0,
		idx = 0;
	len -= cellbytes - 1;
	while (idx < len)
	{
		// Read 4 bytes.
		#emit LREF.S.pri                addr
		#emit STOR.S.pri                buffer
		if (
			((str[idx++] = buffer & 0xFF) == 0) ||
			((str[idx++] = (buffer >>> 8) & 0xFF) == 0) ||
			((str[idx++] = (buffer >>> 16) & 0xFF) == 0) ||
			((str[idx++] = buffer >>> 24) == 0))
		{
			return;
		}
		addr += cellbytes;
	}
	len += cellbytes - 1;
	// Read 4 bytes.
	#emit LREF.S.pri                addr
	#emit STOR.S.pri                buffer
	if (!(str[idx++] = buffer & 0xFF) || (idx == len))
	{
		return;
	}
	if (!(str[idx++] = (buffer >>> 8) & 0xFF) || (idx == len))
	{
		return;
	}
	if (!(str[idx++] = (buffer >>> 16) & 0xFF) || (idx == len))
	{
		return;
	}
	if (!(str[idx++] = buffer >>> 24) || (idx == len))
	{
		return;
	}
}

Test_WritePackedString1(addr, const str[])
{
	new
		buffer,
		idx = 0,
		c = strlen(str);
	while (c >= cellbytes)
	{
		buffer = swapchars(str[idx++]),
		AMX_Write(addr, buffer),
		addr += cellbytes,
		c -= cellbytes;
	}
	idx *= cellbytes;
	// Write trailing bytes, always including `NULL`.
	do
	{
		buffer = AMX_Read(addr),
		c = str{idx++},
		buffer = (buffer & ~0xFF) | (c & 0xFF),
		AMX_Write(addr, buffer),
		++addr;
	}
	while (c);
}

Test_WritePackedString2(addr, const str[])
{
	new
		buffer,
		idx = 0,
		c;
	//while (c >= cellbytes)
	for ( ; ; )
	{
		c = swapchars(str[idx]);
		if (Cell_HasZeroByte(c))
		{
			break;
		}
		++idx,
		AMX_Write(addr, c),
		addr += cellbytes;
	}
	// Write trailing bytes, always including `NULL`.
	do
	{
		buffer = AMX_Read(addr),
		//c = str{idx++},
		buffer = (buffer & ~0xFF) | (c & 0xFF),
		AMX_Write(addr, buffer),
		c >>>= 8,
		++addr;
	}
	while (buffer & 0xFF);
}

/*@profileinit() StringWrite1A()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite1A()
{
	AMX_WriteString(gAddr, __COMPILER_PACK"This is a source string, it is quite long, but not too long");
}

@profileinit() StringWrite2A()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite2A()
{
	AMX_WritePackedString(gAddr, __COMPILER_PACK"This is a source string, it is quite long, but not too long");
}

@profileinit() StringWrite3A()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite3A()
{
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"This is a source string, it is quite long, but not too long");
}

@profileinit() StringWrite4A()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite4A()
{
	Test_WritePackedString1(gAddr, __COMPILER_UNPACK"This is a source string, it is quite long, but not too long");
}

@profileinit() StringWrite5A()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite5A()
{
	Test_WritePackedString2(gAddr, __COMPILER_UNPACK"This is a source string, it is quite long, but not too long");
}

@profileinit() StringRead1A()
{
	gAddr = ref(gInput);
	AMX_WriteString(gAddr, __COMPILER_PACK"This is a source string, it is quite long, but not too long");
}

@profile(100000) StringRead1A()
{
	AMX_ReadString(gAddr, gOutput);
}

@profileinit() StringRead2A()
{
	gAddr = ref(gInput);
	AMX_WritePackedString(gAddr, __COMPILER_PACK"This is a source string, it is quite long, but not too long");
}

@profile(100000) StringRead2A()
{
	AMX_ReadPackedString(gAddr, gOutput);
}

@profileinit() StringRead3A()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"This is a source string, it is quite long, but not too long");
}

@profile(100000) StringRead3A()
{
	AMX_ReadUnpackedString(gAddr, gOutput);
}

@profileinit() StringRead4A()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"This is a source string, it is quite long, but not too long");
}

@profile(100000) StringRead4A()
{
	Test_ReadUnpackedString1(gAddr, gOutput);
}

@profileinit() StringRead5A()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"This is a source string, it is quite long, but not too long");
}

@profile(100000) StringRead5A()
{
	Test_ReadUnpackedString2(gAddr, gOutput);
}

@profileinit() StringWrite1B()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite1B()
{
	AMX_WriteString(gAddr, __COMPILER_PACK"Shorter string.");
}

@profileinit() StringWrite2B()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite2B()
{
	AMX_WritePackedString(gAddr, __COMPILER_PACK"Shorter string.");
}

@profileinit() StringWrite3B()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite3B()
{
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"Shorter string.");
}

@profileinit() StringWrite4B()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite4B()
{
	Test_WritePackedString1(gAddr, __COMPILER_UNPACK"Shorter string.");
}

@profileinit() StringWrite5B()
{
	gAddr = ref(gOutput);
}

@profile(100000) StringWrite5B()
{
	Test_WritePackedString2(gAddr, __COMPILER_UNPACK"Shorter string.");
}

@profileinit() StringRead1B()
{
	gAddr = ref(gInput);
	AMX_WriteString(gAddr, __COMPILER_PACK"Shorter string.");
}

@profile(100000) StringRead1B()
{
	AMX_ReadString(gAddr, gOutput);
}

@profileinit() StringRead2B()
{
	gAddr = ref(gInput);
	AMX_WritePackedString(gAddr, __COMPILER_PACK"Shorter string.");
}

@profile(100000) StringRead2B()
{
	AMX_ReadPackedString(gAddr, gOutput);
}

@profileinit() StringRead3B()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"Shorter string.");
}

@profile(100000) StringRead3B()
{
	AMX_ReadUnpackedString(gAddr, gOutput);
}

@profileinit() StringRead4B()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"Shorter string.");
}

@profile(100000) StringRead4B()
{
	Test_ReadUnpackedString1(gAddr, gOutput);
}

@profileinit() StringRead5B()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"Shorter string.");
}

@profile(100000) StringRead5B()
{
	Test_ReadUnpackedString2(gAddr, gOutput);
}

@test() StringRead1B()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"Shorter string.");
	AMX_ReadString(gAddr, gOutput);
	ASSERT_SAME(gOutput, "Shorter string.");
}

@test() StringRead2B()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"Shorter string.");
	AMX_ReadPackedString(gAddr, gOutput);
	ASSERT_SAME(gOutput, "Shorter string.");
}

@test() StringRead3B()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"Shorter string.");
	AMX_ReadUnpackedString(gAddr, gOutput);
	ASSERT_SAME(gOutput, "Shorter string.");
}

@test() StringRead4B()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"Shorter string.");
	Test_ReadUnpackedString1(gAddr, gOutput);
	ASSERT_SAME(gOutput, "Shorter string.");
}

@test() StringRead5B()
{
	gAddr = ref(gInput);
	AMX_WriteUnpackedString(gAddr, __COMPILER_UNPACK"Shorter string.");
	Test_ReadUnpackedString2(gAddr, gOutput);
	ASSERT_SAME(gOutput, "Shorter string.");
}*/

static stock
	Iterator:y_iter_Next_Profile<1000>;

@profileinit() y_iter_Next()
{
	Iter_Clear(y_iter_Next_Profile);
	for (new i = 0; i != 200; ++i)
	{
		Iter_RandomAdd(y_iter_Next_Profile);
	}
}

@profile() y_iter_Next()
{
	new x = Iter_First(y_iter_Next_Profile);
	for (new i = 0; i != 100; ++i)
	{
		x = Iter_Next(y_iter_Next_Profile, x);
	}
}

@profileinit() y_iter_Prev()
{
	/*Iter_Clear(y_iter_Next_Profile);
	for (new i = 0; i != 200; ++i)
	{
		Iter_RandomAdd(y_iter_Next_Profile);
	}*/
}

@profile() y_iter_Prev()
{
	new x = Iter_Last(y_iter_Next_Profile);
	for (new i = 0; i != 100; ++i)
	{
		x = Iter_Prev(y_iter_Next_Profile, x);
	}
}



