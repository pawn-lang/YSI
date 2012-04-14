// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>
#include <YSI\internal\y_formatin>

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
	new
		str[32] = "Hi there ~r~";
	Format_Standardise(str, str);
	printf("str: %s", str);
}

