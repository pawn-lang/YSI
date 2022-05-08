#include <a_samp>

new ch[] = "0123456789@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";

Write@XX_(a, b, base)
{
	new name[128];
	// Avoid case-sensitivity issues on Windows.
	//new bf = ((a >= 'a') * 2) + (b >= 'a');
	/*new a2 = a, b2 = b, c = 3;
	if ('A' <= a <= 'Z')
	{
		a2 = a | 0x20;
		c -= 2;
	}
	if ('A' <= b <= 'Z')
	{
		b2 = b | 0x20;
		c -= 1;
	}*/
	//format(name, sizeof (name), "y_unique__%c%c0_%c%cz_%d.inc", a2, b2, a2, b2, c);
	format(name, sizeof (name), "DANGEROUS_SERVER_ROOT/pawno/include/YSI_Coding/y_unique/y_unique_%06d_%06d.inc", base, base + 64 - 1);
	new File:f = fopen(name, io_write);
	if (f)
	{
		/*format(name, sizeof (name), "static stock const Y_UNIQUE_%c%c0_%c%cz_CALLED = cellmin;\n", a, b, a, b), fwrite(f, name);
		format(name, sizeof (name), "\n"), fwrite(f, name);
		format(name, sizeof (name), "#if defined _inc_y_unique__%c%c0_%c%cz_%d\n", a2, b2, a2, b2, c), fwrite(f, name);
		format(name, sizeof (name), "	#undef _inc_y_unique__%c%c0_%c%cz_%d\n", a2, b2, a2, b2, c), fwrite(f, name);
		format(name, sizeof (name), "#endif\n"), fwrite(f, name);*/
		format(name, sizeof (name), "static stock const Y_UNIQUE_%06d_%06d_CALLED = UNIQUE_SYMBOL;\n", base, base + 64 - 1), fwrite(f, name);
		format(name, sizeof (name), "\n"), fwrite(f, name);
		format(name, sizeof (name), "#if defined _inc_y_unique_%06d_%06d\n", base, base + 64 - 1), fwrite(f, name);
		format(name, sizeof (name), "	#undef _inc_y_unique_%06d_%06d\n", base, base + 64 - 1), fwrite(f, name);
		format(name, sizeof (name), "#endif\n"), fwrite(f, name);
		format(name, sizeof (name), "\n"), fwrite(f, name);
		for (new i = 0; i != 8; ++i)
		{
			if (i == 7)
				format(name, sizeof (name), "#else\n"), fwrite(f, name);
			else
				format(name, sizeof (name), "#%sif UNIQUE_SYMBOL < (%d)\n", i ? "else" : "", base + i * 8 - 1 + 8), fwrite(f, name);
			for (new j = 0; j != 8; ++j)
			{
				if (j == 7)
					format(name, sizeof (name), "	#else\n"), fwrite(f, name);
				else
					format(name, sizeof (name), "	#%sif UNIQUE_SYMBOL == (%d)\n", i ? "else" : "", base + i * 8 + j - 1), fwrite(f, name);
				format(name, sizeof (name), "		#undef UNIQUE_SYMBOL\n"), fwrite(f, name);
				format(name, sizeof (name), "		#define UNIQUE_SYMBOL (%d)\n", base + i * 8 + j), fwrite(f, name);
				format(name, sizeof (name), "		#define UNIQUE_FUNCTION<%%0...%%1> %%0%c%c%c%%1\n", a, b, ch[i * 8 + j]), fwrite(f, name);
				format(name, sizeof (name), "		#endinput\n"), fwrite(f, name);
			}
			format(name, sizeof (name), "	#endif\n"), fwrite(f, name);
		}
		format(name, sizeof (name), "#endif\n"), fwrite(f, name);
		fclose(f);
	}
}

Write@X__(a, base)
{
	#pragma unused a
	new name[128];
	// Avoid case-sensitivity issues on Windows.
	//new bf = ((a >= 'a') * 2) + (b >= 'a');
	/*new a2 = a, b2 = b, c = 3;
	if ('A' <= a <= 'Z')
	{
		a2 = a | 0x20;
		c -= 2;
	}
	if ('A' <= b <= 'Z')
	{
		b2 = b | 0x20;
		c -= 1;
	}*/
	//format(name, sizeof (name), "y_unique__%c%c0_%c%cz_%d.inc", a2, b2, a2, b2, c);
	format(name, sizeof (name), "DANGEROUS_SERVER_ROOT/pawno/include/YSI_Coding/y_unique/y_unique_%06d_%06d.inc", base, base + 64 * 64 - 1);
	new File:f = fopen(name, io_write);
	if (f)
	{
		/*format(name, sizeof (name), "static stock const Y_UNIQUE_%c%c0_%c%cz_CALLED = cellmin;\n", a, b, a, b), fwrite(f, name);
		format(name, sizeof (name), "\n"), fwrite(f, name);
		format(name, sizeof (name), "#if defined _inc_y_unique__%c%c0_%c%cz_%d\n", a2, b2, a2, b2, c), fwrite(f, name);
		format(name, sizeof (name), "	#undef _inc_y_unique__%c%c0_%c%cz_%d\n", a2, b2, a2, b2, c), fwrite(f, name);
		format(name, sizeof (name), "#endif\n"), fwrite(f, name);*/
		format(name, sizeof (name), "static stock const Y_UNIQUE_%06d_%06d_CALLED = UNIQUE_SYMBOL;\n", base, base + 64 * 64 - 1), fwrite(f, name);
		format(name, sizeof (name), "\n"), fwrite(f, name);
		format(name, sizeof (name), "#if defined _inc_y_unique_%06d_%06d\n", base, base + 64 * 64 - 1), fwrite(f, name);
		format(name, sizeof (name), "	#undef _inc_y_unique_%06d_%06d\n", base, base + 64 * 64 - 1), fwrite(f, name);
		format(name, sizeof (name), "#endif\n"), fwrite(f, name);
		format(name, sizeof (name), "\n"), fwrite(f, name);
		for (new i = 0; i != 8; ++i)
		{
			if (i == 7)
				format(name, sizeof (name), "#else\n"), fwrite(f, name);
			else
				format(name, sizeof (name), "#%sif UNIQUE_SYMBOL < (%d)\n", i ? "else" : "", base + i * 64 * 8 + 64 * 8 - 1), fwrite(f, name);
			for (new j = 0; j != 8; ++j)
			{
				if (j == 7)
					format(name, sizeof (name), "	#else\n"), fwrite(f, name);
				else
					format(name, sizeof (name), "	#%sif UNIQUE_SYMBOL < (%d)\n", i ? "else" : "", base + i * 64 * 8 + j * 64 + 64 - 1), fwrite(f, name);
				format(name, sizeof (name), "		#include \"y_unique_%06d_%06d\"\n", base + i * 64 * 8 + j * 64, base + i * 64 * 8 + j * 64 + 64 - 1), fwrite(f, name);
			}
			format(name, sizeof (name), "	#endif\n"), fwrite(f, name);
		}
		format(name, sizeof (name), "#endif\n"), fwrite(f, name);
		fclose(f);
	}
}

Write@___()
{
	new name[128];
	// Avoid case-sensitivity issues on Windows.
	//new bf = ((a >= 'a') * 2) + (b >= 'a');
	/*new a2 = a, b2 = b, c = 3;
	if ('A' <= a <= 'Z')
	{
		a2 = a | 0x20;
		c -= 2;
	}
	if ('A' <= b <= 'Z')
	{
		b2 = b | 0x20;
		c -= 1;
	}*/
	//format(name, sizeof (name), "y_unique__%c%c0_%c%cz_%d.inc", a2, b2, a2, b2, c);
	format(name, sizeof (name), "DANGEROUS_SERVER_ROOT/pawno/include/YSI_Coding/y_unique/y_unique_.inc");
	new File:f = fopen(name, io_write);
	if (f)
	{
		/*format(name, sizeof (name), "static stock const Y_UNIQUE_%c%c0_%c%cz_CALLED = cellmin;\n", a, b, a, b), fwrite(f, name);
		format(name, sizeof (name), "\n"), fwrite(f, name);
		format(name, sizeof (name), "#if defined _inc_y_unique__%c%c0_%c%cz_%d\n", a2, b2, a2, b2, c), fwrite(f, name);
		format(name, sizeof (name), "	#undef _inc_y_unique__%c%c0_%c%cz_%d\n", a2, b2, a2, b2, c), fwrite(f, name);
		format(name, sizeof (name), "#endif\n"), fwrite(f, name);*/
		format(name, sizeof (name), "static stock const Y_UNIQUE__CALLED = UNIQUE_SYMBOL;\n"), fwrite(f, name);
		format(name, sizeof (name), "\n"), fwrite(f, name);
		format(name, sizeof (name), "#if defined _inc_y_unique_\n"), fwrite(f, name);
		format(name, sizeof (name), "	#undef _inc_y_unique_\n"), fwrite(f, name);
		format(name, sizeof (name), "#endif\n"), fwrite(f, name);
		format(name, sizeof (name), "\n"), fwrite(f, name);
		for (new i = 0; i != 8; ++i)
		{
			if (i == 7)
				format(name, sizeof (name), "#else\n"), fwrite(f, name);
			else
				format(name, sizeof (name), "#%sif UNIQUE_SYMBOL < (%d)\n", i ? "else" : "", i * 64 * 64 * 8 + 64 * 64 * 8 - 1), fwrite(f, name);
			for (new j = 0; j != 8; ++j)
			{
				if (j == 7)
					format(name, sizeof (name), "	#else\n"), fwrite(f, name);
				else
					format(name, sizeof (name), "	#%sif UNIQUE_SYMBOL < (%d)\n", i ? "else" : "", i * 64 * 64 * 8 + j * 64 * 64 + 64 * 64 - 1), fwrite(f, name);
				format(name, sizeof (name), "		static stock const UNIQUE_SYMBOL_LESS_THAN_%06d = UNIQUE_SYMBOL;\n", i * 64 * 64 * 8 + j * 64 * 64 + 64 * 64 - 1), fwrite(f, name);
				format(name, sizeof (name), "		#include \"y_unique_%06d_%06d\"\n", i * 64 * 64 * 8 + j * 64 * 64, i * 64 * 64 * 8 + j * 64 * 64 + 64 * 64 - 1), fwrite(f, name);
				format(name, sizeof (name), "		#endinput\n"), fwrite(f, name);
			}
			format(name, sizeof (name), "	#endif\n"), fwrite(f, name);
		}
		format(name, sizeof (name), "#endif\n"), fwrite(f, name);
		fclose(f);
	}
}

main()
{
	Write@___();
	for (new i = 0; i != 64; ++i)
	{
		Write@X__(ch[i], i * 64 * 64);
		for (new j = 0; j != 64; ++j)
		{
			Write@XX_(ch[i], ch[j], i * 64 * 64 + j * 64);
		}
	}
}


