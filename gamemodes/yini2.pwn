// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>

#include <YSI\y_ini>

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
	new
		INI:a = INI_Open("moo.ini");
	//INI_SetTag(a, "ha");
	INI_WriteInt(a, "hello", 2722);
	INI_WriteFloat(a, "hi", 4422);
	INI_WriteHex(a, "hi1", 7722);
	INI_WriteHex(a, "hi5", -7722);
	INI_WriteBin(a, "hi4", 7722);
	INI_WriteBin(a, "hi2", -7722);
	INI_WriteString(a, "woop", "yeah");
	INI_Close(a);
	INI_Load("moo.ini");


	a = INI_Open("woo.ini");
	//INI_SetTag(a, "ha");
	INI_WriteInt(a, "hello66", 2766);
	INI_WriteFloat(a, "hi66", 4466);
	INI_WriteHex(a, "hi166", 7766);
	INI_WriteHex(a, "hi566", -7766);
	INI_WriteBin(a, "hi466", 7766);
	INI_WriteBin(a, "hi266", -7766);
	INI_WriteString(a, "woop66", "yeah66");
	INI_Close(a);
	return 0;
}

INI:moo[](name[], value[])
{
	new
		b,
		Float:c;
	INI_Int("hello", b);
	INI_Float("hi", c);
	INI_Hex("hi1", b);
	INI_Bin("hi2", b);
	INI_Bin("hi4", b);
	INI_Bool("hi3", b);
	INI_String("hi", name, 2);
	return 0;
}

