// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#define _YSI_SPECIAL_DEBUG
#define RUN_TESTS

#include <a_samp>
#include <YSI\y_stringise>
#include <YSI\y_testing>

Test:Test1()
{
	new
		bool:res;
	res = !strcmp("HELLO", S("HE" ... "LLO"));
	ASSERT(res);
	res = !strcmp("HELLO", S("HE" ... #LLO));
	ASSERT(res);
	res = !strcmp("HELLO()", S("HE" ... "LLO()"));
	ASSERT(res);
	res = !strcmp("HELLO()", S("HE" ... #LLO()));
	ASSERT(res);
	res = !strcmp("HELLO\"\"()", S("HE" ... #LLO""()));
	ASSERT(res);
	res = !strcmp("HELLO,,#", S("HE" ... #LLO,,#));
	ASSERT(res);
	res = !strcmp("HELLO", S(#H ... #E ... #L ... #L ... #O));
	ASSERT(res);
	res = !strcmp("()\"HELLO\"", S(#() ... "\"HELLO\""));
	ASSERT(res);
}

