// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <YSI\y_timers>

Timer:RepeatingFunction1[1000]()
{
	printf("1");
}

Timer:RepeatingFunction2[1000]()
{
	printf("2");
}

Timer:RepeatingFunction3[1000]()
{
	printf("3");
}

Delay:MyFunc[1000, ii ](playerid, moo)
{
	printf("%d %d", playerid, moo);
}

FixDelay:MyFunc2[1000,]()
{
	printf("MyFunc2");
}

/*Delay@p:MyFunc3[1000,is](playerid, moo[])<playerid, moo>
{
	printf("%d %s", playerid, moo);
	MyFunc3(playerid, moo);
}*/

main()
{
	print("\n----------------------------------");
	print(" Blank Gamemode by your name here");
	print("----------------------------------\n");
	printf("call:");
	RepeatingFunction1();
//	MyFunc3(60, "hello");
	MyFunc(40, 50);
	skip:MyFunc(30, 20);
	delay:MyFunc[100](60, 90);
	MyFunc2();
	//skip:MyFunc2();
	//delay:MyFunc2[70]();
}

