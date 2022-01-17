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
	format(src, sizeof (src), "ucm\\%s.ucm", name);
	new File:fin = fopen(src, io_read);
	if (!fin)
	{
		printf("Could not open input file \"%s\"", src);
		return false;
	}
	format(src, sizeof (src), "YSI\\codepages\\%s.txt", name);
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
	ParseFile("aix-big5-4.3.6");
	ParseFile("aix-CNS11643.1986_1-4.3.6");
	ParseFile("aix-CNS11643.1986_2-4.3.6");
	ParseFile("aix-IBM_1046-4.3.6");
	ParseFile("aix-IBM_1124-4.3.6");
	ParseFile("aix-IBM_1129-4.3.6");
	ParseFile("aix-IBM_1252-4.3.6");
	ParseFile("aix-IBM_850-4.3.6");
	ParseFile("aix-IBM_856-4.3.6");
	ParseFile("aix-IBM_858-4.3.6");
	ParseFile("aix-IBM_932-4.3.6");
	ParseFile("aix-IBM_943-4.3.6");
	ParseFile("aix-IBM_eucJP-4.3.6");
	ParseFile("aix-IBM_eucKR-4.3.6");
	ParseFile("aix-IBM_eucTW-4.3.6");
	ParseFile("aix-IBM_udcJP-4.3.6");
	ParseFile("aix-IBM_udcJP_GR-4.3.6");
	ParseFile("aix-ISO8859_1-4.3.6");
	ParseFile("aix-ISO8859_15-4.3.6");
	ParseFile("aix-ISO8859_2-4.3.6");
	ParseFile("aix-ISO8859_3-4.3.6");
	ParseFile("aix-ISO8859_4-4.3.6");
	ParseFile("aix-ISO8859_5-4.3.6");
	ParseFile("aix-ISO8859_6-4.3.6");
	ParseFile("aix-ISO8859_7-4.3.6");
	ParseFile("aix-ISO8859_8-4.3.6");
	ParseFile("aix-ISO8859_9-4.3.6");
	ParseFile("aix-JISX0201.1976_0-4.3.6");
	ParseFile("aix-JISX0201.1976_GR-4.3.6");
	ParseFile("aix-JISX0208.1983_0-4.3.6");
	ParseFile("aix-JISX0208.1983_GR-4.3.6");
	ParseFile("aix-KSC5601.1987_0-4.3.6");
	ParseFile("aix-TIS_620-4.3.6");
	ParseFile("cns-11643-1992");
	ParseFile("euc-jp-2007");
	ParseFile("euc-tw-2014");
	ParseFile("gb-18030-2000");
	ParseFile("gb-18030-2005");
	ParseFile("glibc-ANSI_X3.110-2.1.2");
	ParseFile("glibc-ANSI_X3.110-2.3.3");
	ParseFile("glibc-ARMSCII_8-2.3.3");
	ParseFile("glibc-ASMO_449-2.1.2");
	ParseFile("glibc-BALTIC-2.1.2");
	ParseFile("glibc-BIG5-2.1.2");
	ParseFile("glibc-BIG5-2.3.3");
	ParseFile("glibc-BIG5HKSCS-2.3.3");
	ParseFile("glibc-BS_4730-2.3.3");
	ParseFile("glibc-CP10007-2.3.3");
	ParseFile("glibc-CP1125-2.3.3");
	ParseFile("glibc-CP1250-2.1.2");
	ParseFile("glibc-CP1251-2.1.2");
	ParseFile("glibc-CP1252-2.1.2");
	ParseFile("glibc-CP1253-2.1.2");
	ParseFile("glibc-CP1254-2.1.2");
	ParseFile("glibc-CP1255-2.1.2");
	ParseFile("glibc-CP1256-2.1.2");
	ParseFile("glibc-CP1257-2.1.2");
	ParseFile("glibc-CP1258-2.1.2");
	ParseFile("glibc-CP737-2.1.2");
	ParseFile("glibc-CP775-2.1.2");
	ParseFile("glibc-CP932-2.3.3");
	ParseFile("glibc-CSA_Z243.4_1985_1-2.3.3");
	ParseFile("glibc-CSA_Z243.4_1985_2-2.3.3");
	ParseFile("glibc-CSN_369103-2.1.2");
	ParseFile("glibc-CWI-2.1.2");
	ParseFile("glibc-DEC_MCS-2.1.2");
	ParseFile("glibc-DIN_66003-2.3.3");
	ParseFile("glibc-DS_2089-2.3.3");
	ParseFile("glibc-EBCDIC_AT_DE-2.1.2");
	ParseFile("glibc-EBCDIC_AT_DE_A-2.1.2");
	ParseFile("glibc-EBCDIC_CA_FR-2.1.2");
	ParseFile("glibc-EBCDIC_DK_NO-2.1.2");
	ParseFile("glibc-EBCDIC_DK_NO_A-2.1.2");
	ParseFile("glibc-EBCDIC_ES-2.1.2");
	ParseFile("glibc-EBCDIC_ES_A-2.1.2");
	ParseFile("glibc-EBCDIC_ES_S-2.1.2");
	ParseFile("glibc-EBCDIC_FI_SE-2.1.2");
	ParseFile("glibc-EBCDIC_FI_SE_A-2.1.2");
	ParseFile("glibc-EBCDIC_FR-2.1.2");
	ParseFile("glibc-EBCDIC_IS_FRISS-2.1.2");
	ParseFile("glibc-EBCDIC_IT-2.1.2");
	ParseFile("glibc-EBCDIC_PT-2.1.2");
	ParseFile("glibc-EBCDIC_UK-2.1.2");
	ParseFile("glibc-EBCDIC_US-2.1.2");
	ParseFile("glibc-ECMA_CYRILLIC-2.3.3");
	ParseFile("glibc-ES-2.3.3");
	ParseFile("glibc-ES2-2.3.3");
	ParseFile("glibc-EUC_CN-2.1.2");
	ParseFile("glibc-EUC_CN-2.3.3");
	ParseFile("glibc-EUC_JP-2.1.2");
	ParseFile("glibc-EUC_JP-2.3.3");
	ParseFile("glibc-EUC_JP_MS-2.3.3");
	ParseFile("glibc-EUC_KR-2.1.2");
	ParseFile("glibc-EUC_KR-2.3.3");
	ParseFile("glibc-EUC_TW-2.1.2");
	ParseFile("glibc-GBK-2.3.3");
	ParseFile("glibc-GB_1988_80-2.3.3");
	ParseFile("glibc-GEORGIAN_ACADEMY-2.3.3");
	ParseFile("glibc-GEORGIAN_PS-2.3.3");
	ParseFile("glibc-GOST_19768_74-2.1.2");
	ParseFile("glibc-GREEK7-2.1.2");
	ParseFile("glibc-GREEK7_OLD-2.1.2");
	ParseFile("glibc-GREEK_CCITT-2.1.2");
	ParseFile("glibc-HP_ROMAN8-2.1.2");
	ParseFile("glibc-IBM037-2.1.2");
	ParseFile("glibc-IBM038-2.1.2");
	ParseFile("glibc-IBM1004-2.1.2");
	ParseFile("glibc-IBM1026-2.1.2");
	ParseFile("glibc-IBM1046-2.3.3");
	ParseFile("glibc-IBM1047-2.1.2");
	ParseFile("glibc-IBM1124-2.3.3");
	ParseFile("glibc-IBM1129-2.3.3");
	ParseFile("glibc-IBM1132-2.3.3");
	ParseFile("glibc-IBM1133-2.3.3");
	ParseFile("glibc-IBM1160-2.3.3");
	ParseFile("glibc-IBM1161-2.3.3");
	ParseFile("glibc-IBM1162-2.3.3");
	ParseFile("glibc-IBM1163-2.3.3");
	ParseFile("glibc-IBM1164-2.3.3");
	ParseFile("glibc-IBM256-2.1.2");
	ParseFile("glibc-IBM273-2.1.2");
	ParseFile("glibc-IBM274-2.1.2");
	ParseFile("glibc-IBM275-2.1.2");
	ParseFile("glibc-IBM277-2.1.2");
	ParseFile("glibc-IBM278-2.1.2");
	ParseFile("glibc-IBM280-2.1.2");
	ParseFile("glibc-IBM281-2.1.2");
	ParseFile("glibc-IBM284-2.1.2");
	ParseFile("glibc-IBM285-2.1.2");
	ParseFile("glibc-IBM290-2.1.2");
	ParseFile("glibc-IBM297-2.1.2");
	ParseFile("glibc-IBM420-2.1.2");
	ParseFile("glibc-IBM423-2.1.2");
	ParseFile("glibc-IBM424-2.1.2");
	ParseFile("glibc-IBM437-2.1.2");
	ParseFile("glibc-IBM500-2.1.2");
	ParseFile("glibc-IBM850-2.1.2");
	ParseFile("glibc-IBM851-2.1.2");
	ParseFile("glibc-IBM852-2.1.2");
	ParseFile("glibc-IBM855-2.1.2");
	ParseFile("glibc-IBM856-2.3.3");
	ParseFile("glibc-IBM857-2.1.2");
	ParseFile("glibc-IBM860-2.1.2");
	ParseFile("glibc-IBM861-2.1.2");
	ParseFile("glibc-IBM862-2.1.2");
	ParseFile("glibc-IBM863-2.1.2");
	ParseFile("glibc-IBM864-2.1.2");
	ParseFile("glibc-IBM864-2.3.3");
	ParseFile("glibc-IBM865-2.1.2");
	ParseFile("glibc-IBM866-2.1.2");
	ParseFile("glibc-IBM866NAV-2.3.3");
	ParseFile("glibc-IBM868-2.1.2");
	ParseFile("glibc-IBM869-2.1.2");
	ParseFile("glibc-IBM870-2.1.2");
	ParseFile("glibc-IBM870-2.3.3");
	ParseFile("glibc-IBM871-2.1.2");
	ParseFile("glibc-IBM874-2.1.2");
	ParseFile("glibc-IBM874-2.3.3");
	ParseFile("glibc-IBM875-2.1.2");
	ParseFile("glibc-IBM880-2.1.2");
	ParseFile("glibc-IBM891-2.1.2");
	ParseFile("glibc-IBM903-2.1.2");
	ParseFile("glibc-IBM904-2.1.2");
	ParseFile("glibc-IBM905-2.1.2");
	ParseFile("glibc-IBM918-2.1.2");
	ParseFile("glibc-IBM922-2.3.3");
	ParseFile("glibc-IBM943-2.3.3");
	ParseFile("glibc-IEC_P27_1-2.1.2");
	ParseFile("glibc-INIS-2.1.2");
	ParseFile("glibc-INIS_8-2.1.2");
	ParseFile("glibc-INIS_CYRILLIC-2.1.2");
	ParseFile("glibc-ISIRI_3342-2.3.3");
	ParseFile("glibc-ISO646_US-2.1.2");
	ParseFile("glibc-ISO_10367_BOX-2.1.2");
	ParseFile("glibc-ISO_5427-2.1.2");
	ParseFile("glibc-ISO_5427_EXT-2.1.2");
	ParseFile("glibc-ISO_5428-2.1.2");
	ParseFile("glibc-ISO_5428-2.3.3");
	ParseFile("glibc-ISO_6937-2.3.3");
	ParseFile("glibc-ISO_8859_1-2.1.2");
	ParseFile("glibc-ISO_8859_10-2.1.2");
	ParseFile("glibc-ISO_8859_11-2.1.2");
	ParseFile("glibc-ISO_8859_13-2.1.2");
	ParseFile("glibc-ISO_8859_13-2.3.3");
	ParseFile("glibc-ISO_8859_14-2.1.2");
	ParseFile("glibc-ISO_8859_15-2.1.2");
	ParseFile("glibc-ISO_8859_16-2.3.3");
	ParseFile("glibc-ISO_8859_2-2.1.2");
	ParseFile("glibc-ISO_8859_3-2.1.2");
	ParseFile("glibc-ISO_8859_4-2.1.2");
	ParseFile("glibc-ISO_8859_5-2.1.2");
	ParseFile("glibc-ISO_8859_6-2.1.2");
	ParseFile("glibc-ISO_8859_7-2.1.2");
	ParseFile("glibc-ISO_8859_7-2.3.3");
	ParseFile("glibc-ISO_8859_8-2.1.2");
	ParseFile("glibc-ISO_8859_8-2.3.3");
	ParseFile("glibc-ISO_8859_9-2.1.2");
	ParseFile("glibc-ISO_IR_197-2.1.2");
	ParseFile("glibc-ISO_IR_209-2.3.3");
	ParseFile("glibc-IT-2.3.3");
	ParseFile("glibc-JIS_C6220_1969_RO-2.3.3");
	ParseFile("glibc-JIS_C6229_1984_B-2.3.3");
	ParseFile("glibc-JOHAB-2.3.3");
	ParseFile("glibc-JUS_I.B1.002-2.3.3");
	ParseFile("glibc-KOI8_R-2.1.2");
	ParseFile("glibc-KOI8_R-2.3.3");
	ParseFile("glibc-KOI8_T-2.3.3");
	ParseFile("glibc-KOI8_U-2.1.2");
	ParseFile("glibc-KOI8_U-2.3.3");
	ParseFile("glibc-KOI_8-2.1.2");
	ParseFile("glibc-KSC5636-2.3.3");
	ParseFile("glibc-LATIN_GREEK-2.1.2");
	ParseFile("glibc-LATIN_GREEK_1-2.1.2");
	ParseFile("glibc-MACINTOSH-2.1.2");
	ParseFile("glibc-MACINTOSH-2.3.3");
	ParseFile("glibc-MAC_IS-2.1.2");
	ParseFile("glibc-MAC_SAMI-2.3.3");
	ParseFile("glibc-MAC_UK-2.1.2");
	ParseFile("glibc-MSZ_7795.3-2.3.3");
	ParseFile("glibc-NATS_DANO-2.1.2");
	ParseFile("glibc-NATS_SEFI-2.1.2");
	ParseFile("glibc-NC_NC00_10-2.3.3");
	ParseFile("glibc-NF_Z_62_010-2.3.3");
	ParseFile("glibc-NF_Z_62_010_1973-2.3.3");
	ParseFile("glibc-NS_4551_1-2.3.3");
	ParseFile("glibc-NS_4551_2-2.3.3");
	ParseFile("glibc-PT-2.3.3");
	ParseFile("glibc-PT154-2.3.3");
	ParseFile("glibc-PT2-2.3.3");
	ParseFile("glibc-RK1048-2.3.3");
	ParseFile("glibc-SEN_850200_B-2.3.3");
	ParseFile("glibc-SEN_850200_C-2.3.3");
	ParseFile("glibc-SJIS-2.1.2");
	ParseFile("glibc-SJIS-2.3.3");
	ParseFile("glibc-T.61_8BIT-2.3.3");
	ParseFile("glibc-TIS_620-2.1.2");
	ParseFile("glibc-UHC-2.1.2");
	ParseFile("glibc-UHC-2.3.3");
	ParseFile("glibc-VISCII-2.3.3");
	ParseFile("glibc-WIN_SAMI_2-2.3.3");
	ParseFile("hpux-big5-11.11");
	ParseFile("hpux-cp1140-11.11");
	ParseFile("hpux-cp1141-11.11");
	ParseFile("hpux-cp1142-11.11");
	ParseFile("hpux-cp1143-11.11");
	ParseFile("hpux-cp1144-11.11");
	ParseFile("hpux-cp1145-11.11");
	ParseFile("hpux-cp1146-11.11");
	ParseFile("hpux-cp1147-11.11");
	ParseFile("hpux-cp1148-11.11");
	ParseFile("hpux-cp1149-11.11");
	ParseFile("hpux-cp1250-11.11");
	ParseFile("hpux-cp1251-11.11");
	ParseFile("hpux-cp1252-11.11");
	ParseFile("hpux-cp1253-11.11");
	ParseFile("hpux-cp1254-11.11");
	ParseFile("hpux-cp1255-11.11");
	ParseFile("hpux-cp1256-11.11");
	ParseFile("hpux-cp1257-11.11");
	ParseFile("hpux-cp1258-11.11");
	ParseFile("hpux-cp437-11.11");
	ParseFile("hpux-cp737-11.11");
	ParseFile("hpux-cp775-11.11");
	ParseFile("hpux-cp850-11.11");
	ParseFile("hpux-cp852-11.11");
	ParseFile("hpux-cp855-11.11");
	ParseFile("hpux-cp857-11.11");
	ParseFile("hpux-cp860-11.11");
	ParseFile("hpux-cp861-11.11");
	ParseFile("hpux-cp862-11.11");
	ParseFile("hpux-cp863-11.11");
	ParseFile("hpux-cp864-11.11");
	ParseFile("hpux-cp865-11.11");
	ParseFile("hpux-cp866-11.11");
	ParseFile("hpux-cp869-11.11");
	ParseFile("hpux-cp874-11.11");
	ParseFile("hpux-eucJP-11.11");
	ParseFile("hpux-eucJP0201-11.11");
	ParseFile("hpux-eucJPMS-11.11");
	ParseFile("hpux-eucKR-11.11");
	ParseFile("hpux-eucTW-11.11");
	ParseFile("hpux-greee-11.11");
	ParseFile("hpux-hkbig5-11.11");
	ParseFile("hpux-hp15CN-11.11");
	ParseFile("hpux-iso81-11.0");
	ParseFile("hpux-iso815-11.0");
	ParseFile("hpux-iso82-11.0");
	ParseFile("hpux-iso85-11.0");
	ParseFile("hpux-iso86-11.0");
	ParseFile("hpux-iso87-11.0");
	ParseFile("hpux-iso87-11.11");
	ParseFile("hpux-iso88-11.0");
	ParseFile("hpux-iso89-11.0");
	ParseFile("hpux-roc15-11.11");
	ParseFile("hpux-roma8-11.0");
	ParseFile("hpux-sjis-11.11");
	ParseFile("hpux-sjis0201-11.11");
	ParseFile("hpux-sjisMS-11.11");
	ParseFile("hpux-thai8-11.0");
	ParseFile("ibm-1004_P100-1995");
	ParseFile("ibm-1006_P100-1995");
	ParseFile("ibm-1006_X100-1995");
	ParseFile("ibm-1008_P100-1995");
	ParseFile("ibm-1008_X100-1995");
	ParseFile("ibm-1009_P100-1995");
	ParseFile("ibm-1010_P100-1995");
	ParseFile("ibm-1011_P100-1995");
	ParseFile("ibm-1012_P100-1995");
	ParseFile("ibm-1013_P100-1995");
	ParseFile("ibm-1014_P100-1995");
	ParseFile("ibm-1015_P100-1995");
	ParseFile("ibm-1016_P100-1995");
	ParseFile("ibm-1017_P100-1995");
	ParseFile("ibm-1018_P100-1995");
	ParseFile("ibm-1019_P100-1995");
	ParseFile("ibm-1020_P100-2003");
	ParseFile("ibm-1021_P100-2003");
	ParseFile("ibm-1023_P100-2003");
	ParseFile("ibm-1025_P100-1995");
	ParseFile("ibm-1026_P100-1995");
	ParseFile("ibm-1027_P100-1995");
	ParseFile("ibm-1040_P100-1995");
	ParseFile("ibm-1041_P100-1995");
	ParseFile("ibm-1042_P100-1995");
	ParseFile("ibm-1043_P100-1995");
	ParseFile("ibm-1046_X110-1999");
	ParseFile("ibm-1047_P100-1995");
	ParseFile("ibm-1051_P100-1999");
	ParseFile("ibm-1088_P100-1995");
	ParseFile("ibm-1089_P100-1995");
	ParseFile("ibm-1097_P100-1995");
	ParseFile("ibm-1097_X100-1995");
	ParseFile("ibm-1098_P100-1995");
	ParseFile("ibm-1098_X100-1995");
	ParseFile("ibm-1100_P100-2003");
	ParseFile("ibm-1101_P100-2003");
	ParseFile("ibm-1102_P100-2003");
	ParseFile("ibm-1103_P100-2003");
	ParseFile("ibm-1104_P100-2003");
	ParseFile("ibm-1105_P100-2003");
	ParseFile("ibm-1106_P100-2003");
	ParseFile("ibm-1107_P100-2003");
	ParseFile("ibm-1112_P100-1995");
	ParseFile("ibm-1114_P100-1995");
	ParseFile("ibm-1114_P100-2001");
	ParseFile("ibm-1115_P100-1995");
	ParseFile("ibm-1122_P100-1999");
	ParseFile("ibm-1123_P100-1995");
	ParseFile("ibm-1124_X100-1996");
	ParseFile("ibm-1125_P100-1997");
	ParseFile("ibm-1126_P100-1997");
	ParseFile("ibm-1126_P100_P100-1997_U3");
	ParseFile("ibm-1127_P100-2004");
	ParseFile("ibm-1129_P100-1997");
	ParseFile("ibm-1130_P100-1997");
	ParseFile("ibm-1131_P100-1997");
	ParseFile("ibm-1132_P100-1997");
	ParseFile("ibm-1132_P100-1998");
	ParseFile("ibm-1133_P100-1997");
	ParseFile("ibm-1137_P100-1999");
	ParseFile("ibm-1137_PMOD-1999");
	ParseFile("ibm-1140_P100-1997");
	ParseFile("ibm-1141_P100-1997");
	ParseFile("ibm-1142_P100-1997");
	ParseFile("ibm-1143_P100-1997");
	ParseFile("ibm-1144_P100-1997");
	ParseFile("ibm-1145_P100-1997");
	ParseFile("ibm-1146_P100-1997");
	ParseFile("ibm-1147_P100-1997");
	ParseFile("ibm-1148_P100-1997");
	ParseFile("ibm-1149_P100-1997");
	ParseFile("ibm-1153_P100-1999");
	ParseFile("ibm-1154_P100-1999");
	ParseFile("ibm-1155_P100-1999");
	ParseFile("ibm-1156_P100-1999");
	ParseFile("ibm-1157_P100-1999");
	ParseFile("ibm-1158_P100-1999");
	ParseFile("ibm-1159_P100-1999");
	ParseFile("ibm-1160_P100-1999");
	ParseFile("ibm-1161_P100-1999");
	ParseFile("ibm-1162_P100-1999");
	ParseFile("ibm-1163_P100-1999");
	ParseFile("ibm-1164_P100-1999");
	ParseFile("ibm-1165_P101-2000");
	ParseFile("ibm-1166_P100-2002");
	ParseFile("ibm-1167_P100-2002");
	ParseFile("ibm-1168_P100-2002");
	ParseFile("ibm-1174_X100-2007");
	ParseFile("ibm-1250_P100-1999");
	ParseFile("ibm-1251_P100-1995");
	ParseFile("ibm-1252_P100-2000");
	ParseFile("ibm-1253_P100-1995");
	ParseFile("ibm-1254_P100-1995");
	ParseFile("ibm-1255_P100-1995");
	ParseFile("ibm-1256_P110-1997");
	ParseFile("ibm-1257_P100-1995");
	ParseFile("ibm-1258_P100-1997");
	ParseFile("ibm-12712_P100-1998");
	ParseFile("ibm-1275_P100-1995");
	ParseFile("ibm-1275_X100-1995");
	ParseFile("ibm-1276_P100-1995");
	ParseFile("ibm-1277_P100-1995");
	ParseFile("ibm-1280_P100-1996");
	ParseFile("ibm-1281_P100-1996");
	ParseFile("ibm-1282_P100-1996");
	ParseFile("ibm-1283_P100-1996");
	ParseFile("ibm-1284_P100-1996");
	ParseFile("ibm-1285_P100-1996");
	ParseFile("ibm-13121_P100-1995");
	ParseFile("ibm-13124_P100-1995");
	ParseFile("ibm-13124_P10A-1995");
	ParseFile("ibm-13125_P100-1997");
	ParseFile("ibm-13140_P101-2000");
	ParseFile("ibm-13143_P101-2000");
	ParseFile("ibm-13145_P101-2000");
	ParseFile("ibm-13156_P101-2000");
	ParseFile("ibm-13157_P101-2000");
	ParseFile("ibm-13162_P101-2000");
	ParseFile("ibm-13218_P100-1996");
	ParseFile("ibm-1350_P110-1997");
	ParseFile("ibm-1351_P110-1997");
	ParseFile("ibm-1362_P100-1997");
	ParseFile("ibm-1362_P110-1999");
	ParseFile("ibm-1363_P100-1997");
	ParseFile("ibm-1363_P10A-1997");
	ParseFile("ibm-1363_P10B-1998");
	ParseFile("ibm-1363_P110-1999");
	ParseFile("ibm-1363_P11A-1999");
	ParseFile("ibm-1363_P11B-1999");
	ParseFile("ibm-1363_P11C-2006");
	ParseFile("ibm-1364_P100-2007");
	ParseFile("ibm-1364_P110-2007");
	ParseFile("ibm-13676_P102-2001");
	ParseFile("ibm-1370_P100-1999");
	ParseFile("ibm-1370_X100-1999");
	ParseFile("ibm-1371_P100-1999");
	ParseFile("ibm-1371_X100-1999");
	ParseFile("ibm-1373_P100-2002");
	ParseFile("ibm-1374_P100-2005");
	ParseFile("ibm-1374_P100_P100-2005_MS");
	ParseFile("ibm-1375_P100-2004");
	ParseFile("ibm-1375_P100-2006");
	ParseFile("ibm-1375_P100-2007");
	ParseFile("ibm-1375_P100-2008");
	ParseFile("ibm-1375_X100-2004");
	ParseFile("ibm-1377_P100-2006");
	ParseFile("ibm-1377_P100-2008");
	ParseFile("ibm-1377_P100_P100-2006_U3");
	ParseFile("ibm-1380_P100-1995");
	ParseFile("ibm-1380_X100-1995");
	ParseFile("ibm-1381_P110-1999");
	ParseFile("ibm-1381_X110-1999");
	ParseFile("ibm-1382_P100-1995");
	ParseFile("ibm-1382_X100-1995");
	ParseFile("ibm-1383_P110-1999");
	ParseFile("ibm-1383_X110-1999");
	ParseFile("ibm-1385_P100-1997");
	ParseFile("ibm-1385_P100-2005");
	ParseFile("ibm-1386_P100-2001");
	ParseFile("ibm-1386_P110-1997");
	ParseFile("ibm-1388_P103-2001");
	ParseFile("ibm-1388_P110-2000");
	ParseFile("ibm-1390_P100-1999");
	ParseFile("ibm-1390_P110-2003");
	ParseFile("ibm-1399_P100-1999");
	ParseFile("ibm-1399_P110-2003");
	ParseFile("ibm-16684_P100-1999");
	ParseFile("ibm-16684_P110-2003");
	ParseFile("ibm-16804_X110-1999");
	ParseFile("ibm-17221_P100-2001");
	ParseFile("ibm-17240_P101-2000");
	ParseFile("ibm-17248_X110-1999");
	ParseFile("ibm-20780_P100-1999");
	ParseFile("ibm-21344_P101-2000");
	ParseFile("ibm-21427_P100-1999");
	ParseFile("ibm-21427_X100-1999");
	ParseFile("ibm-25546_P100-1997");
	ParseFile("ibm-256_P100-1995");
	ParseFile("ibm-259_P100-1995");
	ParseFile("ibm-259_X100-1995");
	ParseFile("ibm-273_P100-1999");
	ParseFile("ibm-274_P100-2000");
	ParseFile("ibm-275_P100-1995");
	ParseFile("ibm-277_P100-1999");
	ParseFile("ibm-278_P100-1999");
	ParseFile("ibm-280_P100-1999");
	ParseFile("ibm-282_P100-1995");
	ParseFile("ibm-284_P100-1999");
	ParseFile("ibm-285_P100-1999");
	ParseFile("ibm-286_P100-2003");
	ParseFile("ibm-28709_P100-1995");
	ParseFile("ibm-290_P100-1995");
	ParseFile("ibm-293_P100-1995");
	ParseFile("ibm-293_X100-1995");
	ParseFile("ibm-297_P100-1999");
	ParseFile("ibm-300_P110-1997");
	ParseFile("ibm-300_P120-2006");
	ParseFile("ibm-300_X110-1997");
	ParseFile("ibm-301_P110-1997");
	ParseFile("ibm-301_X110-1997");
	ParseFile("ibm-33058_P100-2000");
	ParseFile("ibm-33722_P120-1999");
	ParseFile("ibm-33722_P12A-1999");
	ParseFile("ibm-33722_P12A_P12A-2004_U2");
	ParseFile("ibm-33722_P12A_P12A-2009_U2");
	ParseFile("ibm-367_P100-1995");
	ParseFile("ibm-37_P100-1999");
	ParseFile("ibm-420_X110-1999");
	ParseFile("ibm-420_X120-1999");
	ParseFile("ibm-423_P100-1995");
	ParseFile("ibm-424_P100-1995");
	ParseFile("ibm-425_P101-2000");
	ParseFile("ibm-437_P100-1995");
	ParseFile("ibm-4517_P100-2005");
	ParseFile("ibm-4899_P100-1998");
	ParseFile("ibm-4904_P101-2000");
	ParseFile("ibm-4909_P100-1999");
	ParseFile("ibm-4930_P100-1997");
	ParseFile("ibm-4930_P110-1999");
	ParseFile("ibm-4933_P100-1996");
	ParseFile("ibm-4933_P100-2002");
	ParseFile("ibm-4944_P101-2000");
	ParseFile("ibm-4945_P101-2000");
	ParseFile("ibm-4948_P100-1995");
	ParseFile("ibm-4951_P100-1995");
	ParseFile("ibm-4952_P100-1995");
	ParseFile("ibm-4954_P101-2000");
	ParseFile("ibm-4955_P101-2000");
	ParseFile("ibm-4956_P101-2000");
	ParseFile("ibm-4957_P101-2000");
	ParseFile("ibm-4958_P101-2000");
	ParseFile("ibm-4959_P101-2000");
	ParseFile("ibm-4960_P100-1995");
	ParseFile("ibm-4960_X100-1995");
	ParseFile("ibm-4961_P101-2000");
	ParseFile("ibm-4962_P101-2000");
	ParseFile("ibm-4963_P101-2000");
	ParseFile("ibm-4971_P100-1999");
	ParseFile("ibm-500_P100-1999");
	ParseFile("ibm-5012_P100-1999");
	ParseFile("ibm-5026_P120-1999");
	ParseFile("ibm-5026_X120-1999");
	ParseFile("ibm-5035_P120-1999");
	ParseFile("ibm-5035_P120_P12A-2005_U2");
	ParseFile("ibm-5035_X120-1999");
	ParseFile("ibm-5039_P110-1996");
	ParseFile("ibm-5039_P11A-1998");
	ParseFile("ibm-5048_P100-1995");
	ParseFile("ibm-5049_P100-1995");
	ParseFile("ibm-5050_P120-1999");
	ParseFile("ibm-5050_P12A-1999");
	ParseFile("ibm-5067_P100-1995");
	ParseFile("ibm-5104_X110-1999");
	ParseFile("ibm-5123_P100-1999");
	ParseFile("ibm-5142_P100-1995");
	ParseFile("ibm-5210_P100-1999");
	ParseFile("ibm-5233_P100-2011");
	ParseFile("ibm-5346_P100-1998");
	ParseFile("ibm-5347_P100-1998");
	ParseFile("ibm-5348_P100-1997");
	ParseFile("ibm-5349_P100-1998");
	ParseFile("ibm-5350_P100-1998");
	ParseFile("ibm-5351_P100-1998");
	ParseFile("ibm-5352_P100-1998");
	ParseFile("ibm-5353_P100-1998");
	ParseFile("ibm-5354_P100-1998");
	ParseFile("ibm-53685_P101-2000");
	ParseFile("ibm-54191_P100-2006");
	ParseFile("ibm-5470_P100-2005");
	ParseFile("ibm-5470_P100_P100-2005_MS");
	ParseFile("ibm-5471_P100-2006");
	ParseFile("ibm-5471_P100-2007");
	ParseFile("ibm-5473_P100-2006");
	ParseFile("ibm-5478_P100-1995");
	ParseFile("ibm-5486_P100-1999");
	ParseFile("ibm-5487_P100-2001");
	ParseFile("ibm-5488_P100-2001");
	ParseFile("ibm-5495_P100-1999");
	ParseFile("ibm-62383_P100-2007");
	ParseFile("ibm-720_P100-1997");
	ParseFile("ibm-737_P100-1997");
	ParseFile("ibm-775_P100-1996");
	ParseFile("ibm-803_P100-1999");
	ParseFile("ibm-806_P100-1998");
	ParseFile("ibm-808_P100-1999");
	ParseFile("ibm-813_P100-1995");
	ParseFile("ibm-819_P100-1999");
	ParseFile("ibm-833_P100-1995");
	ParseFile("ibm-834_P100-1995");
	ParseFile("ibm-834_X100-1995");
	ParseFile("ibm-835_P100-1995");
	ParseFile("ibm-835_X100-1995");
	ParseFile("ibm-836_P100-1995");
	ParseFile("ibm-837_P100-1995");
	ParseFile("ibm-837_P100-2011");
	ParseFile("ibm-837_X100-1995");
	ParseFile("ibm-838_P100-1995");
	ParseFile("ibm-8482_P100-1999");
	ParseFile("ibm-848_P100-1999");
	ParseFile("ibm-849_P100-1999");
	ParseFile("ibm-850_P100-1999");
	ParseFile("ibm-851_P100-1995");
	ParseFile("ibm-852_P100-1999");
	ParseFile("ibm-855_P100-1995");
	ParseFile("ibm-856_P100-1995");
	ParseFile("ibm-857_P100-1995");
	ParseFile("ibm-858_P100-1997");
	ParseFile("ibm-859_P100-1999");
	ParseFile("ibm-860_P100-1995");
	ParseFile("ibm-8612_P100-1995");
	ParseFile("ibm-8612_X110-1995");
	ParseFile("ibm-861_P100-1995");
	ParseFile("ibm-862_P100-1995");
	ParseFile("ibm-863_P100-1995");
	ParseFile("ibm-864_X110-1999");
	ParseFile("ibm-864_X120-2012");
	ParseFile("ibm-865_P100-1995");
	ParseFile("ibm-866_P100-1995");
	ParseFile("ibm-867_P100-1998");
	ParseFile("ibm-868_P100-1995");
	ParseFile("ibm-868_X100-1995");
	ParseFile("ibm-869_P100-1995");
	ParseFile("ibm-870_P100-1999");
	ParseFile("ibm-871_P100-1999");
	ParseFile("ibm-872_P100-1999");
	ParseFile("ibm-874_P100-1995");
	ParseFile("ibm-875_P100-1995");
	ParseFile("ibm-878_P100-1996");
	ParseFile("ibm-880_P100-1995");
	ParseFile("ibm-891_P100-1995");
	ParseFile("ibm-895_P100-1995");
	ParseFile("ibm-896_P100-1995");
	ParseFile("ibm-897_P100-1995");
	ParseFile("ibm-9005_X100-2005");
	ParseFile("ibm-9005_X110-2007");
	ParseFile("ibm-901_P100-1999");
	ParseFile("ibm-9027_P100-1999");
	ParseFile("ibm-9027_X100-1999");
	ParseFile("ibm-902_P100-1999");
	ParseFile("ibm-9030_P100-1995");
	ParseFile("ibm-903_P100-1995");
	ParseFile("ibm-9042_P101-2000");
	ParseFile("ibm-9044_P100-1999");
	ParseFile("ibm-9048_P100-1998");
	ParseFile("ibm-9049_P100-1999");
	ParseFile("ibm-904_P100-1995");
	ParseFile("ibm-9056_P100-1995");
	ParseFile("ibm-905_P100-1995");
	ParseFile("ibm-9061_P100-1999");
	ParseFile("ibm-9064_P101-2000");
	ParseFile("ibm-9066_P100-1995");
	ParseFile("ibm-9067_X100-2005");
	ParseFile("ibm-912_P100-1999");
	ParseFile("ibm-913_P100-2000");
	ParseFile("ibm-9145_P110-1997");
	ParseFile("ibm-9145_X110-1997");
	ParseFile("ibm-914_P100-1995");
	ParseFile("ibm-915_P100-1995");
	ParseFile("ibm-916_P100-1995");
	ParseFile("ibm-918_P100-1995");
	ParseFile("ibm-918_X100-1995");
	ParseFile("ibm-920_P100-1995");
	ParseFile("ibm-921_P100-1995");
	ParseFile("ibm-922_P100-1999");
	ParseFile("ibm-9238_X110-1999");
	ParseFile("ibm-923_P100-1998");
	ParseFile("ibm-924_P100-1998");
	ParseFile("ibm-926_P100-2000");
	ParseFile("ibm-927_P100-1995");
	ParseFile("ibm-927_X100-1995");
	ParseFile("ibm-928_P100-1995");
	ParseFile("ibm-9306_P101-2000");
	ParseFile("ibm-930_P120-1999");
	ParseFile("ibm-930_P120_P12A-2006_U2");
	ParseFile("ibm-930_X120-1999");
	ParseFile("ibm-931_P120-1999");
	ParseFile("ibm-931_X120-1999");
	ParseFile("ibm-932_P120-1999");
	ParseFile("ibm-932_P12A-1999");
	ParseFile("ibm-932_P12A_P12A-2000_U2");
	ParseFile("ibm-933_P110-1999");
	ParseFile("ibm-933_X110-1999");
	ParseFile("ibm-935_P110-1999");
	ParseFile("ibm-935_X110-1999");
	ParseFile("ibm-937_P110-1999");
	ParseFile("ibm-937_X110-1999");
	ParseFile("ibm-939_P120-1999");
	ParseFile("ibm-939_P120_P12A-2005_U2");
	ParseFile("ibm-939_X120-1999");
	ParseFile("ibm-941_P120-1996");
	ParseFile("ibm-941_P12A-1996");
	ParseFile("ibm-941_P130-2001");
	ParseFile("ibm-941_P13A-2001");
	ParseFile("ibm-941_X110-1996");
	ParseFile("ibm-941_X11A-1996");
	ParseFile("ibm-942_P120-1999");
	ParseFile("ibm-942_P12A-1999");
	ParseFile("ibm-942_P12A_P12A-2000_U2");
	ParseFile("ibm-943_P130-1999");
	ParseFile("ibm-943_P14A-1999");
	ParseFile("ibm-943_P15A-2003");
	ParseFile("ibm-9444_P100-2001");
	ParseFile("ibm-9444_P100-2005");
	ParseFile("ibm-9444_P100_P100-2005_MS");
	ParseFile("ibm-9447_P100-2002");
	ParseFile("ibm-9448_X100-2005");
	ParseFile("ibm-9449_P100-2002");
	ParseFile("ibm-944_P100-1995");
	ParseFile("ibm-944_X100-1995");
	ParseFile("ibm-946_P100-1995");
	ParseFile("ibm-947_P100-1995");
	ParseFile("ibm-947_X100-1995");
	ParseFile("ibm-948_P110-1999");
	ParseFile("ibm-948_X110-1999");
	ParseFile("ibm-949_P110-1999");
	ParseFile("ibm-949_P11A-1999");
	ParseFile("ibm-949_X110-1999");
	ParseFile("ibm-950_P110-1999");
	ParseFile("ibm-950_X110-1999");
	ParseFile("ibm-951_P100-1995");
	ParseFile("ibm-951_X100-1995");
	ParseFile("ibm-952_P110-1997");
	ParseFile("ibm-953_P100-2000");
	ParseFile("ibm-954_P101-2007");
	ParseFile("ibm-955_P110-1997");
	ParseFile("ibm-9577_P100-2001");
	ParseFile("ibm-9580_P110-1999");
	ParseFile("ibm-960_P100-2000");
	ParseFile("ibm-963_P100-1995");
	ParseFile("ibm-964_P110-1999");
	ParseFile("ibm-964_X110-1999");
	ParseFile("ibm-970_P110-1999");
	ParseFile("ibm-970_P110_P110-2006_U2");
	ParseFile("ibm-971_P100-1995");
	ParseFile("iso-8859_1-1998");
	ParseFile("iso-8859_10-1998");
	ParseFile("iso-8859_11-2001");
	ParseFile("iso-8859_13-1998");
	ParseFile("iso-8859_14-1998");
	ParseFile("iso-8859_15-1999");
	ParseFile("iso-8859_16-2001");
	ParseFile("iso-8859_2-1999");
	ParseFile("iso-8859_3-1999");
	ParseFile("iso-8859_4-1998");
	ParseFile("iso-8859_5-1999");
	ParseFile("iso-8859_6-1999");
	ParseFile("iso-8859_7-1987");
	ParseFile("iso-8859_7-2003");
	ParseFile("iso-8859_8-1999");
	ParseFile("iso-8859_9-1999");
	ParseFile("java-ASCII-1.3_P");
	ParseFile("java-Big5-1.3_P");
	ParseFile("java-Cp037-1.3_P");
	ParseFile("java-Cp1006-1.3_P");
	ParseFile("java-Cp1025-1.3_P");
	ParseFile("java-Cp1026-1.3_P");
	ParseFile("java-Cp1097-1.3_P");
	ParseFile("java-Cp1098-1.3_P");
	ParseFile("java-Cp1112-1.3_P");
	ParseFile("java-Cp1122-1.3_P");
	ParseFile("java-Cp1123-1.3_P");
	ParseFile("java-Cp1124-1.3_P");
	ParseFile("java-Cp1250-1.3_P");
	ParseFile("java-Cp1251-1.3_P");
	ParseFile("java-Cp1252-1.3_P");
	ParseFile("java-Cp1253-1.3_P");
	ParseFile("java-Cp1254-1.3_P");
	ParseFile("java-Cp1255-1.3_P");
	ParseFile("java-Cp1256-1.3_P");
	ParseFile("java-Cp1257-1.3_P");
	ParseFile("java-Cp1258-1.3_P");
	ParseFile("java-Cp1381-1.3_P");
	ParseFile("java-Cp1383-1.3_P");
	ParseFile("java-Cp1390A-1.6_P");
	ParseFile("java-Cp1399A-1.6_P");
	ParseFile("java-Cp273-1.3_P");
	ParseFile("java-Cp277-1.3_P");
	ParseFile("java-Cp278-1.3_P");
	ParseFile("java-Cp280-1.3_P");
	ParseFile("java-Cp284-1.3_P");
	ParseFile("java-Cp285-1.3_P");
	ParseFile("java-Cp297-1.3_P");
	ParseFile("java-Cp33722-1.3_P");
	ParseFile("java-Cp420-1.3_P");
	ParseFile("java-Cp420s-1.6_P");
	ParseFile("java-Cp424-1.3_P");
	ParseFile("java-Cp437-1.3_P");
	ParseFile("java-Cp500-1.3_P");
	ParseFile("java-Cp737-1.3_P");
	ParseFile("java-Cp775-1.3_P");
	ParseFile("java-Cp838-1.3_P");
	ParseFile("java-Cp850-1.3_P");
	ParseFile("java-Cp852-1.3_P");
	ParseFile("java-Cp855-1.3_P");
	ParseFile("java-Cp856-1.3_P");
	ParseFile("java-Cp857-1.3_P");
	ParseFile("java-Cp860-1.3_P");
	ParseFile("java-Cp861-1.3_P");
	ParseFile("java-Cp862-1.3_P");
	ParseFile("java-Cp863-1.3_P");
	ParseFile("java-Cp864-1.3_P");
	ParseFile("java-Cp865-1.3_P");
	ParseFile("java-Cp866-1.3_P");
	ParseFile("java-Cp868-1.3_P");
	ParseFile("java-Cp869-1.3_P");
	ParseFile("java-Cp870-1.3_P");
	ParseFile("java-Cp871-1.3_P");
	ParseFile("java-Cp874-1.3_P");
	ParseFile("java-Cp875-1.3_P");
	ParseFile("java-Cp918-1.3_P");
	ParseFile("java-Cp921-1.3_P");
	ParseFile("java-Cp922-1.3_P");
	ParseFile("java-Cp930-1.3_P");
	ParseFile("java-Cp933-1.3_P");
	ParseFile("java-Cp935-1.3_P");
	ParseFile("java-Cp937-1.3_P");
	ParseFile("java-Cp939-1.3_P");
	ParseFile("java-Cp942-1.3_P");
	ParseFile("java-Cp942C-1.3_P");
	ParseFile("java-Cp943-1.2.2");
	ParseFile("java-Cp943C-1.3_P");
	ParseFile("java-Cp948-1.3_P");
	ParseFile("java-Cp949-1.3_P");
	ParseFile("java-Cp949C-1.3_P");
	ParseFile("java-Cp950-1.3_P");
	ParseFile("java-Cp964-1.3_P");
	ParseFile("java-Cp970-1.3_P");
	ParseFile("java-EUC_CN-1.3_P");
	ParseFile("java-EUC_JP-1.3_P");
	ParseFile("java-euc_jp_linux-1.6_P");
	ParseFile("java-EUC_KR-1.3_P");
	ParseFile("java-EUC_TW-1.3_P");
	ParseFile("java-ISO2022JP-1.3_P");
	ParseFile("java-ISO2022KR-1.3_P");
	ParseFile("java-ISO8859_1-1.3_P");
	ParseFile("java-ISO8859_13-1.3_P");
	ParseFile("java-ISO8859_2-1.3_P");
	ParseFile("java-ISO8859_3-1.3_P");
	ParseFile("java-ISO8859_4-1.3_P");
	ParseFile("java-ISO8859_5-1.3_P");
	ParseFile("java-ISO8859_6-1.3_P");
	ParseFile("java-ISO8859_7-1.3_P");
	ParseFile("java-ISO8859_8-1.3_P");
	ParseFile("java-ISO8859_9-1.3_P");
	ParseFile("java-Johab-1.3_P");
	ParseFile("java-KOI8_R-1.3_P");
	ParseFile("java-MS874-1.3_P");
	ParseFile("java-MS932-1.3_P");
	ParseFile("java-MS949-1.3_P");
	ParseFile("java-SJIS-1.3_P");
	ParseFile("java-sjis_0213-1.6_P");
	ParseFile("java-TIS620-1.3_P");
	ParseFile("macos-0_1-10.2");
	ParseFile("macos-0_2-10.2");
	ParseFile("macos-1024-10.2");
	ParseFile("macos-1040-10.2");
	ParseFile("macos-1049-10.2");
	ParseFile("macos-1057-10.2");
	ParseFile("macos-1059-10.2");
	ParseFile("macos-1280-10.2");
	ParseFile("macos-1281-10.2");
	ParseFile("macos-1282-10.2");
	ParseFile("macos-1283-10.2");
	ParseFile("macos-1284-10.2");
	ParseFile("macos-1285-10.2");
	ParseFile("macos-1286-10.2");
	ParseFile("macos-1287-10.2");
	ParseFile("macos-1288-10.2");
	ParseFile("macos-1536-10.2");
	ParseFile("macos-21-10.5");
	ParseFile("macos-2562-10.2");
	ParseFile("macos-2563-10.2");
	ParseFile("macos-2566-10.2");
	ParseFile("macos-2817-10.2");
	ParseFile("macos-29-10.2");
	ParseFile("macos-3074-10.2");
	ParseFile("macos-33-10.5");
	ParseFile("macos-34-10.2");
	ParseFile("macos-35-10.2");
	ParseFile("macos-36_1-10.2");
	ParseFile("macos-36_2-10.2");
	ParseFile("macos-37_2-10.2");
	ParseFile("macos-37_3-10.2");
	ParseFile("macos-37_4-10.2");
	ParseFile("macos-37_5-10.2");
	ParseFile("macos-38_1-10.2");
	ParseFile("macos-38_2-10.2");
	ParseFile("macos-513-10.2");
	ParseFile("macos-514-10.2");
	ParseFile("macos-515-10.2");
	ParseFile("macos-516-10.2");
	ParseFile("macos-517-10.2");
	ParseFile("macos-518-10.2");
	ParseFile("macos-519-10.2");
	ParseFile("macos-520-10.2");
	ParseFile("macos-521-10.2");
	ParseFile("macos-527-10.2");
	ParseFile("macos-6-10.2");
	ParseFile("macos-6_2-10.4");
	ParseFile("macos-7_1-10.2");
	ParseFile("macos-7_2-10.2");
	ParseFile("macos-7_3-10.2");
	ParseFile("osd-EBCDIC-DF03-IRV");
	ParseFile("osd-EBCDIC-DF04-1");
	ParseFile("osd-EBCDIC-DF04-15");
	ParseFile("solaris-5601-2.7");
	ParseFile("solaris-646-2.7");
	ParseFile("solaris-8859_1-2.7");
	ParseFile("solaris-8859_10-2.7");
	ParseFile("solaris-8859_15-2.7");
	ParseFile("solaris-8859_2-2.7");
	ParseFile("solaris-8859_3-2.7");
	ParseFile("solaris-8859_4-2.7");
	ParseFile("solaris-8859_5-2.7");
	ParseFile("solaris-8859_6-2.7");
	ParseFile("solaris-8859_7-2.7");
	ParseFile("solaris-8859_8-2.7");
	ParseFile("solaris-8859_9-2.7");
	ParseFile("solaris-eucJP-2.7");
	ParseFile("solaris-eucTH-2.7");
	ParseFile("solaris-EUC_KR-2.7");
	ParseFile("solaris-KOI8_R-2.7");
	ParseFile("solaris-PCK-2.7");
	ParseFile("solaris-zh_CN.euc-2.7");
	ParseFile("solaris-zh_CN.gbk-2.7");
	ParseFile("solaris-zh_CN_cp935-2.7");
	ParseFile("solaris-zh_HK.hkscs-5.9");
	ParseFile("solaris-zh_TW_big5-2.7");
	ParseFile("solaris-zh_TW_cp937-2.7");
	ParseFile("solaris-zh_TW_euc-2.7");
	ParseFile("windows-10000-2000");
	ParseFile("windows-10001-2000");
	ParseFile("windows-10002-2000");
	ParseFile("windows-10003-2000");
	ParseFile("windows-10004-2000");
	ParseFile("windows-10005-2000");
	ParseFile("windows-10006-2000");
	ParseFile("windows-10007-2000");
	ParseFile("windows-10008-2000");
	ParseFile("windows-10010-2000");
	ParseFile("windows-10017-2000");
	ParseFile("windows-10021-2000");
	ParseFile("windows-10029-2000");
	ParseFile("windows-10079-2000");
	ParseFile("windows-10081-2000");
	ParseFile("windows-10082-2000");
	ParseFile("windows-1026-2000");
	ParseFile("windows-1047-2000");
	ParseFile("windows-1140-2000");
	ParseFile("windows-1141-2000");
	ParseFile("windows-1142-2000");
	ParseFile("windows-1143-2000");
	ParseFile("windows-1144-2000");
	ParseFile("windows-1145-2000");
	ParseFile("windows-1146-2000");
	ParseFile("windows-1147-2000");
	ParseFile("windows-1148-2000");
	ParseFile("windows-1149-2000");
	ParseFile("windows-1250-2000");
	ParseFile("windows-1251-2000");
	ParseFile("windows-1252-2000");
	ParseFile("windows-1253-2000");
	ParseFile("windows-1254-2000");
	ParseFile("windows-1255-2000");
	ParseFile("windows-1256-2000");
	ParseFile("windows-1257-2000");
	ParseFile("windows-1258-2000");
	ParseFile("windows-1258_db-2013");
	ParseFile("windows-1361-2000");
	ParseFile("windows-20000-2000");
	ParseFile("windows-20001-2000");
	ParseFile("windows-20002-2000");
	ParseFile("windows-20003-2000");
	ParseFile("windows-20004-2000");
	ParseFile("windows-20005-2000");
	ParseFile("windows-20105-2000");
	ParseFile("windows-20106-2000");
	ParseFile("windows-20107-2000");
	ParseFile("windows-20108-2000");
	ParseFile("windows-20127-2000");
	ParseFile("windows-20261-2000");
	ParseFile("windows-20269-2000");
	ParseFile("windows-20273-2000");
	ParseFile("windows-20277-2000");
	ParseFile("windows-20278-2000");
	ParseFile("windows-20280-2000");
	ParseFile("windows-20284-2000");
	ParseFile("windows-20285-2000");
	ParseFile("windows-20290-2000");
	ParseFile("windows-20297-2000");
	ParseFile("windows-20420-2000");
	ParseFile("windows-20423-2000");
	ParseFile("windows-20424-2000");
	ParseFile("windows-20833-2000");
	ParseFile("windows-20838-2000");
	ParseFile("windows-20866-2000");
	ParseFile("windows-20871-2000");
	ParseFile("windows-20880-2000");
	ParseFile("windows-20905-2000");
	ParseFile("windows-20924-2000");
	ParseFile("windows-20932-2000");
	ParseFile("windows-20936-2000");
	ParseFile("windows-20949-2000");
	ParseFile("windows-21025-2000");
	ParseFile("windows-21027-2000");
	ParseFile("windows-21866-2000");
	ParseFile("windows-28591-2000");
	ParseFile("windows-28592-2000");
	ParseFile("windows-28593-2000");
	ParseFile("windows-28594-2000");
	ParseFile("windows-28595-2000");
	ParseFile("windows-28596-2000");
	ParseFile("windows-28597-2000");
	ParseFile("windows-28598-2000");
	ParseFile("windows-28599-2000");
	ParseFile("windows-28603-vista");
	ParseFile("windows-28605-2000");
	ParseFile("windows-37-2000");
	ParseFile("windows-38598-2000");
	ParseFile("windows-437-2000");
	ParseFile("windows-500-2000");
	ParseFile("windows-51932-2006");
	ParseFile("windows-51936-2000");
	ParseFile("windows-51949-2000");
	ParseFile("windows-708-2000");
	ParseFile("windows-720-2000");
	ParseFile("windows-737-2000");
	ParseFile("windows-775-2000");
	ParseFile("windows-850-2000");
	ParseFile("windows-852-2000");
	ParseFile("windows-855-2000");
	ParseFile("windows-857-2000");
	ParseFile("windows-858-2000");
	ParseFile("windows-860-2000");
	ParseFile("windows-861-2000");
	ParseFile("windows-862-2000");
	ParseFile("windows-863-2000");
	ParseFile("windows-864-2000");
	ParseFile("windows-865-2000");
	ParseFile("windows-866-2000");
	ParseFile("windows-869-2000");
	ParseFile("windows-870-2000");
	ParseFile("windows-874-2000");
	ParseFile("windows-875-2000");
	ParseFile("windows-932-2000");
	ParseFile("windows-936-2000");
	ParseFile("windows-949-2000");
	ParseFile("windows-950-2000");
	ParseFile("windows-950_hkscs-2001");
}



