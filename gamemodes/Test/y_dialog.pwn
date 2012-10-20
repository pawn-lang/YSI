//#define _DEBUG 5

#define RUN_TESTS

#include <YSI\y_testing>
#include <YSI\y_dialog>

// y_dialog test file.

#define DIALOG_CLEAN:%0; TestClose:%0for(new i=0;i!=MAX_DIALOGS;++i)Dialog_Free(i);

// =============================================================================

Test:ObtainID0() ASSERT(Dialog_ObtainID() != -1);
Test:ObtainID1() ASSERT(Dialog_ObtainID() == 1);
Test:ObtainID2() ASSERT(Dialog_ObtainID() == 2);
Test:ObtainID3() ASSERT(Dialog_ObtainID() == 3);
Test:ObtainID4() ASSERT(Dialog_ObtainID() == 4);

DIALOG_CLEAN:ObtainID4();

// =============================================================================

TestInit:TryObtainID0()
{
	Dialog_ObtainID();
}

Test:TryObtainID0() ASSERT(Dialog_TryObtainID(0) == -1);
Test:TryObtainID1() ASSERT(Dialog_TryObtainID(5) == 5);
Test:TryObtainID2() ASSERT(Dialog_TryObtainID(5) == -1);

DIALOG_CLEAN:TryObtainID2();

// =============================================================================

Test:Get0() ASSERT(Dialog_Get(0) == -1);
Test:Get1() ASSERT(Dialog_Get(MAX_PLAYERS - 1) == -1);
Test:Get2() ASSERT(Dialog_Get(100) == -1);
Test:Get3()
{
	ASSERT(Dialog_Get(100) == -1);
	ASSERT(Dialog_Set(100, 7) == 1);
	ASSERT(Dialog_Get(100) == 7);
}

// =============================================================================

Test:Get4()
{
	Dialog_Set(100, 7);
	new id = Dialog_ObtainID();
	Dialog_Garbage(id);
	ASSERT(Dialog_Set(100, id) == 1);
	ASSERT(Dialog_Get(100) == id);
	ASSERT(Dialog_Set(100, -1) == 0);
	ASSERT(Dialog_Get(100) == -1);
	ASSERT(Dialog_ObtainID() == id);
	ASSERT(Dialog_ObtainID() != id);
}

DIALOG_CLEAN:Get4();

// =============================================================================

Test:Free0()
{
	new id = Dialog_ObtainID();
	Dialog_Set(100, id);
	Iter_Add(Player, 100);
	ASSERT(Dialog_Get(100) == id);
	Dialog_Free(id);
	ASSERT(Dialog_Get(100) == -1);
	Iter_Remove(Player, 100);
}

Test:Free1()
{
	new id = Dialog_ObtainID();
	Dialog_Set(100, id);
	Dialog_Garbage(id);
	Dialog_Set(100, -1);
	ASSERT(Dialog_ObtainID() == id);
}

Test:Free2()
{
	new id = Dialog_ObtainID();
	Dialog_Set(100, id);
	Dialog_Set(100, -1);
	ASSERT(Dialog_ObtainID() != id);
}

// =============================================================================

new
	bool:gCheck;

Test:CB0()
{
	gCheck = false;
	inline Hi0(playerid, dialogid, response, listitem, string:inputtext[])
	{
		#pragma unused playerid, dialogid, response, listitem, inputtext
		gCheck = true;
	}
	new id = Dialog_ShowCallback(42, using inline Hi0, 0, "", "", "");
	ASSERT(call OnDialogResponse(42, id, true, 0, NULL) == 1);
	ASSERT(gCheck);
}

forward Hi1(playerid, dialogid, response, listitem, string:inputtext[]);

public Hi1(playerid, dialogid, response, listitem, string:inputtext[])
{
	gCheck = true;
	return 1;
}

Test:CB1()
{
	gCheck = false;
	new id = Dialog_ShowCallback(42, using public Hi1, 0, "", "", "");
	ASSERT(call OnDialogResponse(42, id, true, 0, NULL) == 1);
	ASSERT(gCheck);
}

Test:CB2()
{
	gCheck = false;
	new id = Dialog_ShowCallback(42, using public IDontExist, 0, "", "", "");
	ASSERT(call OnDialogResponse(42, id, true, 0, NULL) == 0);
	gCheck = true;
}

TestClose:CB2()
{
	ASSERT(gCheck);
}

TestInit:CB3()
{
	Iter_Add(Player, 42);
	for (new i = 0; i != MAX_DIALOGS; ++i)
	{
		Dialog_Free(i);
	}
	Iter_Remove(Player, 42);
}

Test:CB3()
{
	new id = Dialog_ShowCallback(42, using public Hi1, 0, "", "", "");
	ASSERT(call OnDialogResponse(42, id, true, 0, NULL) == 1);
	ASSERT(Dialog_Get(42) == -1);
	ASSERT(Dialog_ObtainID() == id);
}

TestInit:CB4()
{
	Iter_Add(Player, 42);
	for (new i = 0; i != MAX_DIALOGS; ++i)
	{
		Dialog_Free(i);
	}
	Iter_Remove(Player, 42);
}

Test:CB4()
{
	new id = Dialog_ShowCallback(42, using public Hi1, 0, "", "", "");
	ASSERT(Dialog_Hide(42) == 0);
	ASSERT(Dialog_Hide(42) == 1);
	ASSERT(Dialog_ObtainID() == id);
}

// =============================================================================

Test:Clear0()
{
	ASSERT(Dialog_Hide(42) == 1);
	ASSERT(Dialog_Set(42, 2) == 1);
	ASSERT(Dialog_Hide(42) == 1);
}

Test:Clear1()
{
	ASSERT(Dialog_Set(42, 2) == 1);
	ASSERT(Dialog_Set(42, 3) == 1);
	ASSERT(Dialog_Set(42, 4) == 1);
	ASSERT(Dialog_Set(42, -1) == 1);
	ASSERT(Dialog_Set(42, -1) == 1);
}

Test:Clear2()
{
	ASSERT(Dialog_Set(42, 2) == 1);
	Dialog_Garbage(2);
	ASSERT(Dialog_Set(42, 3) == 0);
	ASSERT(Dialog_Set(42, 4) == 1);
	ASSERT(Dialog_Set(42, -1) == 1);
	ASSERT(Dialog_Set(42, -1) == 1);
}

// =============================================================================

Test:Keep0()
{
	new id = Dialog_ObtainID();
	Dialog_Show(42, 0, "", "", "", "", id);
	Dialog_Hide(42);
	ASSERT(Dialog_ObtainID() != id);
}

DIALOG_CLEAN:Keep0();

Test:Keep1()
{
	new id = Dialog_ObtainID();
	Dialog_Show(42, 0, "", "", "", "", id);
	Dialog_Set(42, -1);
	ASSERT(Dialog_ObtainID() != id);
}

DIALOG_CLEAN:Keep1();

Test:Keep2()
{
	new id = Dialog_ObtainID();
	ASSERT(Dialog_TryObtainID(id) == -1);
}

DIALOG_CLEAN:Keep2();

Test:Keep3()
{
	new id = Dialog_ObtainID();
	ASSERT(Dialog_TryObtainID(id + 1) == id + 1);
}

DIALOG_CLEAN:Keep3();












