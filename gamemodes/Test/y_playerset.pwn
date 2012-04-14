#define _DEBUG 1

#define _YSI_SPECIAL_DEBUG

#include <YSI\y_testing>
#include <YSI\y_playerset>

#define PlayerVarFunc PSF:_PlayerVarFunc
#define PlayerSetFunc PSF:_PlayerSetFunc
#define PlayerArrayFunc PSF:_PlayerArrayFunc

#define CHECK(%0) Check(__name,%0)
#define FALSES() Falses(__name)
#define TRUES() Trues(__name)
#define RESET() Reset(__name)

new
	gCalls,
	bool:gIDs[MAX_PLAYERS];

_PlayerVarFunc(@PlayerVar:var)
{
	gIDs[var] = true;
	++gCalls;
}

// =============================================================================

Test:SingleID1()
{
	RESET();
	PlayerVarFunc(5);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:SingleAll1()
{
	RESET();
	PlayerVarFunc(ALL_PLAYERS);
	ASSERT(gCalls == MAX_PLAYERS);
	TRUES();
}

// =============================================================================

Test:SingleArray1()
{
	new
		bool:arr[MAX_PLAYERS];
	RESET();
	arr[5] = true;
	PlayerVarFunc(@arr);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:ManyArray1()
{
	new
		bool:arr[MAX_PLAYERS];
	RESET();
	arr[5] = true;
	arr[6] = true;
	arr[42] = true;
	arr[11] = true;
	arr[19] = true;
	PlayerVarFunc(@arr);
	ASSERT(gCalls == 5);
	CHECK(5);
	CHECK(6);
	CHECK(42);
	CHECK(11);
	CHECK(19);
	FALSES();
}

// =============================================================================

Test:SingleList1()
{
	new
		arr[MAX_PLAYERS];
	RESET();
	arr[0] = 5;
	arr[1] = INVALID_PLAYER_ID;
	PlayerVarFunc(@arr);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:ManyList1()
{
	new
		arr[MAX_PLAYERS];
	RESET();
	arr[0] = 5;
	arr[1] = 400;
	arr[2] = 123;
	arr[3] = 321;
	arr[4] = 55;
	arr[5] = INVALID_PLAYER_ID;
	PlayerVarFunc(@arr);
	ASSERT(gCalls == 5);
	CHECK(5);
	CHECK(400);
	CHECK(123);
	CHECK(321);
	CHECK(55);
	FALSES();
}

// =============================================================================

Test:SinglePA1()
{
	new
		PlayerArray:arr<MAX_PLAYERS>;
	RESET();
	PA_FastInit(arr);
	PA_Set(arr, 5, true);
	PlayerVarFunc(arr);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:ManyPA1()
{
	new
		PlayerArray:arr<MAX_PLAYERS>;
	RESET();
	PA_FastInit(arr);
	PA_Set(arr, 6, true);
	PA_Set(arr, 55, true);
	PA_Set(arr, 340, true);
	PA_Set(arr, 99, true);
	PA_Set(arr, 12, true);
	PlayerVarFunc(arr);
	ASSERT(gCalls == 5);
	CHECK(6);
	CHECK(55);
	CHECK(340);
	CHECK(99);
	CHECK(12);
	FALSES();
}

// =============================================================================

_PlayerSetFunc(@PlayerSet:ps)
{
	foreach (new var : PS(ps))
	{
		gIDs[var] = true;
		++gCalls;
	}
}

// =============================================================================

Test:SingleID2()
{
	RESET();
	PlayerSetFunc(5);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:SingleAll2()
{
	RESET();
	PlayerSetFunc(ALL_PLAYERS);
	ASSERT(gCalls == MAX_PLAYERS);
	TRUES();
}

// =============================================================================

Test:SingleArray2()
{
	new
		bool:arr[MAX_PLAYERS];
	RESET();
	arr[5] = true;
	PlayerSetFunc(@arr);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:ManyArray2()
{
	new
		bool:arr[MAX_PLAYERS];
	RESET();
	arr[5] = true;
	arr[6] = true;
	arr[42] = true;
	arr[11] = true;
	arr[19] = true;
	PlayerSetFunc(@arr);
	ASSERT(gCalls == 5);
	CHECK(5);
	CHECK(6);
	CHECK(42);
	CHECK(11);
	CHECK(19);
	FALSES();
}

// =============================================================================

Test:SingleList2()
{
	new
		arr[MAX_PLAYERS];
	RESET();
	arr[0] = 5;
	arr[1] = INVALID_PLAYER_ID;
	PlayerSetFunc(@arr);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:ManyList2()
{
	new
		arr[MAX_PLAYERS];
	RESET();
	arr[0] = 5;
	arr[1] = 400;
	arr[2] = 123;
	arr[3] = 321;
	arr[4] = 55;
	arr[5] = INVALID_PLAYER_ID;
	PlayerSetFunc(@arr);
	ASSERT(gCalls == 5);
	CHECK(5);
	CHECK(400);
	CHECK(123);
	CHECK(321);
	CHECK(55);
	FALSES();
}

// =============================================================================

Test:SinglePA2()
{
	new
		PlayerArray:arr<MAX_PLAYERS>;
	RESET();
	PA_FastInit(arr);
	PA_Set(arr, 5, true);
	PlayerSetFunc(arr);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:ManyPA2()
{
	new
		PlayerArray:arr<MAX_PLAYERS>;
	RESET();
	PA_FastInit(arr);
	PA_Set(arr, 6, true);
	PA_Set(arr, 55, true);
	PA_Set(arr, 340, true);
	PA_Set(arr, 99, true);
	PA_Set(arr, 12, true);
	PlayerSetFunc(arr);
	ASSERT(gCalls == 5);
	CHECK(6);
	CHECK(55);
	CHECK(340);
	CHECK(99);
	CHECK(12);
	FALSES();
}

// =============================================================================

_PlayerArrayFunc(@PlayerArray:pa<MAX_PLAYERS>)
{
	foreach (new var : PA(pa))
	{
		gIDs[var] = true;
		++gCalls;
	}
}

// =============================================================================

Test:SingleID3()
{
	RESET();
	PlayerArrayFunc(5);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:SingleAll3()
{
	RESET();
	PlayerArrayFunc(ALL_PLAYERS);
	ASSERT(gCalls == MAX_PLAYERS);
	TRUES();
}

// =============================================================================

Test:SingleArray3()
{
	new
		bool:arr[MAX_PLAYERS];
	RESET();
	arr[5] = true;
	PlayerArrayFunc(@arr);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:ManyArray3()
{
	new
		bool:arr[MAX_PLAYERS];
	RESET();
	arr[5] = true;
	arr[6] = true;
	arr[42] = true;
	arr[11] = true;
	arr[19] = true;
	PlayerArrayFunc(@arr);
	ASSERT(gCalls == 5);
	CHECK(5);
	CHECK(6);
	CHECK(42);
	CHECK(11);
	CHECK(19);
	FALSES();
}

// =============================================================================

Test:SingleList3()
{
	new
		arr[MAX_PLAYERS];
	RESET();
	arr[0] = 5;
	arr[1] = INVALID_PLAYER_ID;
	PlayerArrayFunc(@arr);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:ManyList3()
{
	new
		arr[MAX_PLAYERS];
	RESET();
	arr[0] = 5;
	arr[1] = 400;
	arr[2] = 123;
	arr[3] = 321;
	arr[4] = 55;
	arr[5] = INVALID_PLAYER_ID;
	PlayerArrayFunc(@arr);
	ASSERT(gCalls == 5);
	CHECK(5);
	CHECK(400);
	CHECK(123);
	CHECK(321);
	CHECK(55);
	FALSES();
}

// =============================================================================

Test:SinglePA3()
{
	new
		PlayerArray:arr<MAX_PLAYERS>;
	RESET();
	PA_FastInit(arr);
	PA_Set(arr, 5, true);
	PlayerArrayFunc(arr);
	ASSERT(gCalls == 1);
	CHECK(5);
	FALSES();
}

Test:ManyPA3()
{
	new
		PlayerArray:arr<MAX_PLAYERS>;
	RESET();
	PA_FastInit(arr);
	PA_Set(arr, 6, true);
	PA_Set(arr, 55, true);
	PA_Set(arr, 340, true);
	PA_Set(arr, 99, true);
	PA_Set(arr, 12, true);
	PlayerArrayFunc(arr);
	ASSERT(gCalls == 5);
	CHECK(6);
	CHECK(55);
	CHECK(340);
	CHECK(99);
	CHECK(12);
	FALSES();
}

// =============================================================================

#define PlayerVarMore PSF:_PlayerVarMore
#define PlayerSetMore PSF:_PlayerSetMore
#define PlayerArrayMore PSF:_PlayerArrayMore

_PlayerSetMore(@PlayerSet:ps, other, pars)
{
	#pragma unused other, pars, ps
}

_PlayerVarMore(@PlayerVar:var, other, pars)
{
	#pragma unused other, pars
}

_PlayerArrayMore(@PlayerArray:pa<MAX_PLAYERS>, other, pars)
{
	#pragma unused other, pars
}

Test:FuncTypes()
{
	PlayerSetMore(0, 0, 0);
	PlayerVarMore(0, 0, 0);
	PlayerArrayMore(0, 0, 0);
	ASSERT(true);
}

// =============================================================================
//
//  HELPER FUNCTIONS
//
// =============================================================================

Reset(__name[])
{
	#pragma unused __name
	gCalls = 0;
	for (new i = 0; i != MAX_PLAYERS; ++i)
	{
		gIDs[i] = false;
	}
}

Falses(__name[])
{
	new
		bool:pass = true;
	for (new i = 0; i != MAX_PLAYERS; ++i)
	{
		pass = pass && (gIDs[i] == false);
	}
	ASSERT(pass);
}

Trues(__name[])
{
	new
		bool:fail = false;
	for (new i = 0; i != MAX_PLAYERS; ++i)
	{
		fail = fail || (gIDs[i] == false);
	}
	ASSERT(!fail);
}

Check(__name[], id)
{
	ASSERT(gIDs[id] == true);
	gIDs[id]= false;
}

