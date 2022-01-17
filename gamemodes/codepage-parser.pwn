#pragma dynamic 100000

#include <a_samp>
#include <sscanf2>

#if !defined SSCANF_VERSION
	#error Requires sscanf 2.10.4 or greater.
#elseif SSCANF_VERSION < 0x021004
	#error Requires sscanf 2.10.4 or greater.
#endif

#define LEADBYTE (0xFFFE)

bool:ParseFile(const name[])
{
	printf("Parsing codepage \"%s\"...", name);
	new codepage[65536]; // Enough to store all DBCS data.
	new src[64];
	format(src, sizeof (src), "%s.ucm", name);
	new File:fin = fopen(src, io_read);
	if (!fin)
	{
		printf("Could not open input file \"%s\"", src);
		return false;
	}
	format(src, sizeof (src), "%s.txt", name);
	new File:fout = fopen(src, io_write);
	if (!fout)
	{
		fclose(fin);
		printf("Could not open output file \"%s\"", src);
		return false;
	}
	new bool:inCharmap = false;
	new unicode, lead, ascii;
	new line[128];
	while (fread(fin, line))
	{
		if (line[0] == '#')
		{
			//printf("Line: \"%s\"", line);
			//printf("Comment");
			// Comment.  Ignore.
		}
		else if (!strcmp(line, "CHARMAP", false, 7))
		{
			//printf("Line: \"%s\"", line);
			//printf("START");
			// Character map started.
			inCharmap = true;
		}
		else if (!strcmp(line, "END CHARMAP", false, 11))
		{
			//printf("END");
			// Character map ended.
			inCharmap = false;
		}
		else if (inCharmap)
		{
			// Normal line.  E.g:
			//
			//     <U00B7>  \xA1\x50 |0
			//
			// Note that we only care about `|0` lines, those are from the
			// codepage to unicode (possibly full round-trip).  `|1` lines are
			// best approximation going from unicode back to the codepage, but
			// we never do that.
			//printf("Line: \"%s\"", line);
			if (!sscanf(line, "'<U'p<>>x'x'p<\\>x'x'p< >x'|0'", unicode, lead, ascii))
			{
				// DBCS.
				//printf("%x%x = %x", lead, ascii, unicode);
				codepage[lead << 8 | ascii] = unicode;
				codepage[lead] = -1;
			}
			else if (!sscanf(line, "'<U'p<>>x'x'p< >x'|0'", unicode, ascii))
			{
				// Single byte.
				//printf("%x = %x", ascii, unicode);
				codepage[ascii] = unicode;
			}
		}
		else
		{
			// Header data.  E.g:
			//
			//     <code_set_name>               "big5"
			//     <subchar>                     \xC8\xFE
			//
		}
	}
	format(line, sizeof (line), "# This file was auto-generated from \"%s.ucm\"\n", name);
	fwrite(fout, line);
	fwrite(fout, "# by \"codepage-parser.pwn\", (c) MPL 1.1, Alex \"Y_Less\" Cole, 2022.\n");
	fwrite(fout, "#\n");
	fwrite(fout, "# Lines with a single number denote bytes that are followed by a second byte to\n");
	fwrite(fout, "# create a DCBS pair.\n");
	fwrite(fout, "#\n");
	fwrite(fout, "# Lines with two numbers are byte sequence to unicode equivalent.\n");
	fwrite(fout, "\n");
	fwrite(fout, "# DBCS Lead Bytes\n");
	for (new i = 0; i != 256; ++i)
	{
		if (codepage[i] == -1)
		{
			// Lead byte.
			format(line, sizeof (line), "%d\n", i);
			fwrite(fout, line);
		}
	}
	fwrite(fout, "\n# Single Byte Codes\n");
	for (new i = 0; i != 256; ++i)
	{
		if (codepage[i] > 0)
		{
			// Single byte.
			format(line, sizeof (line), "%d %d\n", i, codepage[i]);
			fwrite(fout, line);
		}
	}
	fwrite(fout, "\n# Double Byte Codes\n");
	for (new i = 256; i != sizeof (codepage); ++i)
	{
		if (codepage[i] > 0)
		{
			// DBCS.
			format(line, sizeof (line), "%d %d\n", i, codepage[i]);
			fwrite(fout, line);
		}
	}
	// Write the data.
	printf("... Done!");
	fclose(fin);
	fclose(fout);
	return true;
}

main()
{
	ParseFile("aix-CNS11643.1986_2-4.3.6");
}



