// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#define PHP_RECEIVE ""
#define PHP_SEND "There"
#define _DEBUG 1

#include <a_samp>

#define HTTP(%0HTTP_POST, TestResponse(

#include <YSI\y_php>

#undef HTTP

#include <YSI\y_timers>
#include <YSI\y_testing>

new
	gPass,
	gData[2048];

// HOORAY FOR UNIT TESTS!

TestResponse(string:addr[], string:data[], string:callback[])
{
	printf("addr: %s", addr);
	printf("data: %x %x %x %x %x", data[6], data[7], data[8], data[9], data[10]);
	printf("callback: %s", callback);
	strcpy(gData, data, sizeof (gData));
}

Test:0SendInt()
{
	static
		sData[] =
		{
			'D', 'R', '=', // Header.
			2 | 0x80, // Function name length.
			'h', 'i', // Function name.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 2 | 0x80, 10 | 0x80, // 42.
			255, // Footer.
			'\0' // End
		};
	PHP_SendInt("hi", 42, true);
	ASSERT(!strcmp(gData, sData));
}

Test:0SendFloat()
{
	static
		sData[] =
		{
			'D', 'R', '=', // Header.
			2 | 0x80, // Function name length.
			'h', 'i', // Function name.
			33 | 0x80, 10 | 0x80, 0 | 0x80, 0 | 0x80, 0 | 0xC0, // 42.
			255, // Footer.
			'\0' // End
		};
	PHP_SendFloat("hi", 42.0, true);
	ASSERT(!strcmp(gData, sData));
}

Test:0SendTrue()
{
	static
		sData[] =
		{
			'D', 'R', '=', // Header.
			2 | 0x80, // Function name length.
			'h', 'i', // Function name.
			'1',
			'\0' // End
		};
	PHP_SendBool("hi", true, true);
	ASSERT(!strcmp(gData, sData));
}

Test:0SendFalse()
{
	static
		sData[] =
		{
			'D', 'R', '=', // Header.
			2 | 0x80, // Function name length.
			'h', 'i', // Function name.
			'0',
			'\0' // End
		};
	PHP_SendBool("hi", false, true);
	ASSERT(!strcmp(gData, sData));
}

Test:0SendString()
{
	static
		sData[] =
		{
			'D', 'R', '=', // Header.
			2 | 0x80, // Function name length.
			'h', 'i', // Function name.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 0 | 0x80, 9 | 0x80, // 9.
			'H', 'i', ' ', 't', 'h', 'e', 'r', 'e', '.',
			255, // Footer.
			'\0' // End
		};
	PHP_SendString("hi", "Hi there.", true);
	ASSERT(!strcmp(gData, sData));
}

Test:0SendTwo()
{
	static
		sData[] =
		{
			'D', 'R', '=', // Header.
			2 | 0x80, // Function name length.
			'h', 'i', // Function name.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 0 | 0x80, 9 | 0x80, // 9.
			'H', 'i', ' ', 't', 'h', 'e', 'r', 'e', '.',
			255, // Footer.
			3 | 0x80, // Function name length.
			'y', 'o', 'u', // Function name.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 0 | 0x80, 9 | 0x80, // 9.
			'H', 'i', ' ', 't', 'h', 'e', 'r', 'e', '.',
			255, // Footer.
			'\0' // End
		};
	PHP_SendString("hi", "Hi there.", false);
	PHP_SendString("you", "Hi there.", true);
	ASSERT(!strcmp(gData, sData));
}

Test:0SendThree()
{
	static
		sData[] =
		{
			'D', 'R', '=', // Header.
			2 | 0x80, // Function name length.
			'h', 'i', // Function name.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 2 | 0x80, 10 | 0x80, // 42.
			255, // Footer.
			2 | 0x80, // Function name length.
			'h', 'i', // Function name.
			33 | 0x80, 10 | 0x80, 0 | 0x80, 0 | 0x80, 0 | 0xC0, // 42.
			255, // Footer.
			2 | 0x80, // Function name length.
			'h', 'i', // Function name.
			'1',
			'\0' // End
		};
	PHP_SendInt("hi", 42, false);
	PHP_SendFloat("hi", 42.0, false);
	PHP_SendBool("hi", true, true);
	ASSERT(!strcmp(gData, sData));
}

Test:9SendEventually()
{
	// Has no ASSERT, just look in the console output for the data later.
	PHP_SendInt("hi", 42, false);
}

// These tests test the packet decoding part of y_php.  There is no packet
// construction code in y_php yet (but I need to write some), so I have to
// manually construct the packets byte-by-byte.  Of course, even if there was
// packet construction code, that would still need tests requiring packet
// construction by hand, and I don't even know if the formats would be the same
// as it's for a different target (I suspect so though).

phpfunc First()
{
	// Has been called - that's all we care about!
	++gPass;
}

phpfunc Second(a)
{
	if (a == 42) ++gPass;
}

phpfunc Third(a, string:b[])
{
	if (a == 100 && !strcmp(b, "Hello")) ++gPass;
}

phpfunc Fourth(a, b, c, d)
{
	if (a == 42 && b == 1024 && c == -7890 && d == -1) ++gPass;
}

phpfunc Fifth(bool:a, string:b[], c)
{
	if (a && !strcmp(b, "How are you?") && c == 0x55555555) ++gPass;
}

Test:Function1()
{
	static
		sData[] =
		{
			'1', // Header.
			5 | 0x80, // Function name length.
			'F', 'i', 'r', 's', 't', // Function name.
			0 | 0x40, // Parameter count.
			'\0' // End
		};
	gPass = 0;
	_PHP_Result(42, 200, sData);
	ASSERT(gPass == 1);
}

Test:Function2()
{
	static
		sData[] =
		{
			'1', // Header.
			6 | 0x80, // Function name length.
			'S', 'e', 'c', 'o', 'n', 'd', // Function name.
			1 | 0x40, // Parameter count.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 2 | 0x80, 10 | 0x80, // 42.
			255, // Footer.
			'\0' // End
		};
	gPass = 0;
	_PHP_Result(42, 200, sData);
	ASSERT(gPass == 1);
}

Test:Function3()
{
	static
		sData[] =
		{
			'1', // Header.
			5 | 0x80, // Function name length.
			'T', 'h', 'i', 'r', 'd', // Function name.
			2 | 0x40, // Parameter count.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 0 | 0x80, 5 | 0x80, // 5.
			'H', 'e', 'l', 'l', 'o', // String.
			255, // Separator.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 6 | 0x80, 4 | 0x80, // 100.
			255, // Footer.
			'\0' // End
		};
	gPass = 0;
	_PHP_Result(42, 200, sData);
	ASSERT(gPass == 1);
}

Test:Function4()
{
	static
		sData[] =
		{
			'1', // Header.
			6 | 0x80, // Function name length.
			'F', 'o', 'u', 'r', 't', 'h', // Function name.
			2 | 0x40, // Parameter count.
			127 | 0x80, 127 | 0x80, 127 | 0x80, 127 | 0x80, 15 | 0x80, // -1.
			255, // Separator.
			127 | 0x80, 127 | 0x80, 124 | 0x80, 18 | 0x80, 14 | 0x80, // -7890.
			255, // Separator.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 64 | 0x80, 0 | 0x80, // 1024.
			255, // Separator.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 2 | 0x80, 10 | 0x80, // 42.
			255, // Footer.
			'\0' // End
		};
	gPass = 0;
	_PHP_Result(42, 200, sData);
	ASSERT(gPass == 1);
}

Test:Function5()
{
	static
		sData[] =
		{
			'1', // Header.
			5 | 0x80, // Function name length.
			'F', 'i', 'f', 't', 'h', // Function name.
			2 | 0x40, // Parameter count.
			42 | 0x80, 85 | 0x80, 42 | 0x80, 85 | 0x80, 5 | 0x80, // 0x55555555.
			255, // Separator.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 0 | 0x80, 12 | 0x80, // 12.
			'H', 'o', 'w', ' ', 'a', 'r', 'e', ' ', 'y', 'o', 'u', '?', // String.
			255, // Separator.
			'1', // True.
			'\0' // End
		};
	gPass = 0;
	_PHP_Result(42, 200, sData);
	ASSERT(gPass == 1);
}

Test:Function12()
{
	static
		sData[] =
		{
			'1', // Header.
			5 | 0x80, // Function name length.
			'F', 'i', 'r', 's', 't', // Function name.
			0 | 0x40, // Parameter count.
			6 | 0x80, // Function name length.
			'S', 'e', 'c', 'o', 'n', 'd', // Function name.
			1 | 0x40, // Parameter count.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 2 | 0x80, 10 | 0x80, // 42.
			255, // Footer.
			'\0' // End
		};
	gPass = 0;
	_PHP_Result(42, 200, sData);
	ASSERT(gPass == 2);
}

Test:Function15()
{
	static
		sData[] =
		{
			'1', // Header.
			5 | 0x80, // Function name length.
			'F', 'i', 'r', 's', 't', // Function name.
			0 | 0x40, // Parameter count.
			5 | 0x80, // Function name length.
			'F', 'i', 'f', 't', 'h', // Function name.
			2 | 0x40, // Parameter count.
			42 | 0x80, 85 | 0x80, 42 | 0x80, 85 | 0x80, 5 | 0x80, // 0x55555555.
			255, // Separator.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 0 | 0x80, 12 | 0x80, // 12.
			'H', 'o', 'w', ' ', 'a', 'r', 'e', ' ', 'y', 'o', 'u', '?', // String.
			255, // Separator.
			'1', // True.
			'\0' // End
		};
	gPass = 0;
	_PHP_Result(42, 200, sData);
	ASSERT(gPass == 2);
}

Test:Function51()
{
	static
		sData[] =
		{
			'1', // Header.
			5 | 0x80, // Function name length.
			'F', 'i', 'f', 't', 'h', // Function name.
			2 | 0x40, // Parameter count.
			42 | 0x80, 85 | 0x80, 42 | 0x80, 85 | 0x80, 5 | 0x80, // 0x55555555.
			255, // Separator.
			0 | 0x80, 0 | 0x80, 0 | 0x80, 0 | 0x80, 12 | 0x80, // 12.
			'H', 'o', 'w', ' ', 'a', 'r', 'e', ' ', 'y', 'o', 'u', '?', // String.
			255, // Separator.
			'1', // True.
			5 | 0x80, // Function name length.
			'F', 'i', 'r', 's', 't', // Function name.
			0 | 0x40, // Parameter count.
			'\0' // End
		};
	gPass = 0;
	_PHP_Result(42, 200, sData);
	ASSERT(gPass == 2);
}

