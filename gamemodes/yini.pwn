#include <YSI\y_ini>

INI:core[ysi_properties](name[], value[])
{
}

INI:core[ysi_help](name[], value[])
{
}

INI:core[](name[], value[])
{
	printf("Name: \"%s\"", name);
	printf("Value: \"%s\"", value);
	printf("====");
}

INI:testing[](name[], value[])
{
//	printf("Name: \"%s\"", name);
//	printf("Value: \"%s\"", value);
//	printf("====");
}

INI:testing[woo](name[], value[])
{
//	printf("Name: \"%s\"", name);
//	printf("Value: \"%s\"", value);
	printf("%s = %s", name, value);
//	printf("====");
}

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
	//INI_Load("YSI/core.EN");
	//printf("%d", !strcmp("", "hi"));
	INI_Load("testing.ini");
	new
		INI:tt = INI_Open("testing.ini");
	/*INI_WriteString(tt, "fa", "aa");
	INI_WriteString(tt, "fb", "aa");
	INI_WriteString(tt, "fc", "aa");
	INI_WriteString(tt, "fd", "aa");*/
	INI_SetTag(tt, "woo");
	INI_WriteString(tt, "fa", "ca1");
	INI_WriteString(tt, "fb", "ca1");
	INI_WriteString(tt, "fc", "ca1");
	INI_WriteString(tt, "fd", "ca1");
	INI_RemoveEntry(tt, "fb");
	INI_Close(tt);
	INI_Load("testing.ini");
}

