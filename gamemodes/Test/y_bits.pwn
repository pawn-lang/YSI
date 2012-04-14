#define _DEBUG 1

#include <YSI\y_bit>
#include <YSI\y_testing>

// =============================================================================

Test:Size0() ASSERT(bits<32> == 1);
Test:Size1() ASSERT(bits<31> == 1);
Test:Size2() ASSERT(bits<33> == 2);
Test:Size3() ASSERT(bits<64> == 2);
Test:Size4() ASSERT(bits<500> == 16);
Test:Size5() ASSERT(bits<501> == 16);
Test:Size6() ASSERT(bits<512> == 16);
Test:Size7() ASSERT(bits<513> == 17);
Test:Size8() ASSERT(bits<480> == 15);
Test:Size9()
{
	for (new i = 0; i != 100; ++i)
	{
	    if (bits<i> * 32 < i)
	    {
	        ASSERT(FALSE);
	    }
	}
}

// =============================================================================

Test:Blank0()
{
	new
		BitArray:hi<500>;
	for (new i = 0; i != 16; ++i)
	{
	    if (hi[i])
	    {
		    ASSERT(FALSE);
	    }
	}
}

Test:Blank1()
{
	new
		BitArray:hi<500>;
	for (new i = 0; i != 500; ++i)
	{
	    if (Bit_Get(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
}

Test:Blank2()
{
	new
		BitArray:hi<500>;
	for (new i = 0; i != 500; ++i)
	{
	    if (Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
}

// =============================================================================

Test:Full0()
{
	new
		BitArray:hi<500> = {Bit:-1, ...};
	for (new i = 0; i != 16; ++i)
	{
	    if (!hi[i])
	    {
		    ASSERT(FALSE);
	    }
	}
}

Test:Full1()
{
	new
		BitArray:hi<500> = {Bit:-1, ...};
	for (new i = 0; i != 500; ++i)
	{
	    if (!Bit_Get(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
}

Test:Full2()
{
	new
		BitArray:hi<500> = {Bit:-1, ...};
	for (new i = 0; i != 500; ++i)
	{
	    if (!Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
}

// =============================================================================

Test:Change0()
{
	new
		BitArray:hi<500> = {Bit:-1, ...};
	for (new i = 0; i != 500; ++i)
	{
	    if (!Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
	Bit_SetAll(hi, false);
	for (new i = 0; i != 500; ++i)
	{
	    if (Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
	Bit_SetAll(hi, true);
	for (new i = 0; i != 500; ++i)
	{
	    if (!Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
}

Test:Change1()
{
	new
		BitArray:hi<500>;
	for (new i = 0; i != 500; ++i)
	{
	    if (Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
	Bit_SetAll(hi, true);
	for (new i = 0; i != 500; ++i)
	{
	    if (!Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
	Bit_SetAll(hi, false);
	for (new i = 0; i != 500; ++i)
	{
	    if (Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
}

// =============================================================================

Test:Set0()
{
	new
		BitArray:hi<27>;
	Bit_Set(hi, 10, true);
	ASSERT(Bit_Get(hi, 10));
	Bit_Set(hi, 10, false);
	ASSERT(!Bit_Get(hi, 10));
}

Test:Set1()
{
	new
		BitArray:hi<27>;
	Bit_Let(hi, 22);
	ASSERT(!!Bit_GetBit(hi, 22));
	Bit_Vet(hi, 22);
	ASSERT(!Bit_GetBit(hi, 22));
}

Test:Set2()
{
	new
		BitArray:hi<27>;
	Bit_Set(hi, 10, true);
	for (new i = 0; i != 27; ++i)
	{
	    if (i != 10 && Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
	Bit_Set(hi, 10, false);
	for (new i = 0; i != 27; ++i)
	{
	    if (Bit_GetBit(hi, i))
	    {
		    ASSERT(FALSE);
	    }
	}
}

// =============================================================================

Test:Count0()
{
	new
		BitArray:hi<50> = {Bit:-1, ...};
	ASSERT(Bit_Count(hi) == 64);
}

Test:Count1()
{
	new
		BitArray:hi<50> = {Bit:-1, ...};
	ASSERT(Bit_Count(hi) == 64);
	Bit_Vet(hi, 10);
	ASSERT(Bit_Count(hi) == 63);
	Bit_Vet(hi, 11);
	ASSERT(Bit_Count(hi) == 62);
	Bit_Vet(hi, 11);
	ASSERT(Bit_Count(hi) == 62);
}

Test:Count2()
{
	new
		BitArray:hi<500>;
	ASSERT(Bit_Count(hi) == 0);
	Bit_Let(hi, 20);
	Bit_Let(hi, 40);
	Bit_Let(hi, 200);
	Bit_Let(hi, 400);
	Bit_Let(hi, 500);
	Bit_Let(hi, 50);
	Bit_Let(hi, 2);
	ASSERT(Bit_Count(hi) == 7);
	Bit_Vet(hi, 2);
	ASSERT(Bit_Count(hi) == 6);
}

Test:Count3()
{
	new
		BitArray:hi<500> = {Bit:4, ...};
	ASSERT(Bit_Count(hi) == 16);
}

// =============================================================================

// =============================================================================

// =============================================================================

