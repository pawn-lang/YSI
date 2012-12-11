// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>

#define RUN_TESTS

#include <YSI\y_stringhash>
#include <YSI\y_testing>

Test:Hashes()
{
	new h;
	h = _H<hello>;
	ASSERT(h == YHash("hello"));
	ASSERT(h != YHash("Hello"));
	h = _I<hello>;
	ASSERT(h == YHash("hello", false));
	ASSERT(h == YHash("Hello", false));
	h = _H@f<hello>;
	ASSERT(h == YHash("hello", true, hash_fnv1));
	ASSERT(h != YHash("Hello", true, hash_fnv1));
	ASSERT(h != YHash("hello", true));
	h = _I@f<hello>;
	ASSERT(h == YHash("hello", false, hash_fnv1));
	ASSERT(h == YHash("Hello", false, hash_fnv1));
	ASSERT(h != YHash("hello", false));
	h = _H@a<hello>;
	ASSERT(h == YHash("hello", true, hash_fnv1a));
	ASSERT(h != YHash("Hello", true, hash_fnv1a));
	ASSERT(h != YHash("hello", true, hash_fnv1));
	ASSERT(h != YHash("hello", true));
	h = _I@a<hello>;
	ASSERT(h == YHash("hello", false, hash_fnv1a));
	ASSERT(h == YHash("Hello", false, hash_fnv1a));
	ASSERT(h != YHash("hello", false, hash_fnv1));
	ASSERT(h != YHash("hello", false));
	h = _I(S,N,O,W);
	ASSERT(h == 0x001EF6E6);
	ASSERT(YHash("sNoWkk", false, hash_bernstein, 4) == 0x001EF6E6);
}

