// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#define _DEBUG 1

#include <a_samp>
#include <YSI\y_bit>
#include <YSI\y_iterate>
#include <YSI\y_testing>

Test:count()
{
	new
		BitArray:data<100>;
	Bit_Set(data, 0, true);
	Bit_Set(data, 20, true);
	Bit_Set(data, 30, true);
	Bit_Set(data, 40, true);
	Bit_Set(data, 50, true);
	new
		count = 0;
	foreach (new i : Bits(data))
	{
		++count;
	}
	ASSERT(count == 5);
}

Test:values()
{
	new
		BitArray:data<100>;
	Bit_Set(data, 0, true);
	Bit_Set(data, 20, true);
	Bit_Set(data, 30, true);
	Bit_Set(data, 40, true);
	Bit_Set(data, 50, true);
	new
		count = 0;
	foreach (new i : Bits(data))
	{
		ASSERT(i % 10 == 0);
		++count;
	}
	ASSERT(count == 5);
}

Test:all()
{
	new
		BitArray:data<100>;
	Bit_Set(data, 0, true);
	Bit_Set(data, 20, true);
	Bit_Set(data, 30, true);
	Bit_Set(data, 40, true);
	Bit_Set(data, 50, true);
	new
		count = 0,
		values[5] = {0, 20, 30, 40, 50};
	//value = Iter_First(BITS(data));
	foreach (new i : Bits(data))
	{
		ASSERT(i == values[count]);
		++count;
	}
	ASSERT(count == 5);
}

Test:remove()
{
	new
		BitArray:data<100>;
	Bit_Set(data, 0, true);
	Bit_Set(data, 20, true);
	Bit_Set(data, 30, true);
	Bit_Set(data, 40, true);
	Bit_Set(data, 50, true);
	new
		count = 0,
		values[5] = {0, 20, 30, 40, 50};
	//value = Iter_First(BITS(data));
	foreach (new i : Bits(data))
	{
		ASSERT(i == values[count]);
		if (count & 1) Bit_Set(data, i, false);
		++count;
	}
	ASSERT(count == 5);
	count = 0;
	foreach (new i : Bits(data))
	{
		ASSERT(i == values[count * 2]);
		++count;
	}
	ASSERT(count == 3);
}

