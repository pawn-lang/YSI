/**--------------------------------------------------------------------------**\
					=================================
					   y_bitmap - Generate bitmaps.
					=================================
Description:
	Code to generate images on the server in the bitmap format.  This is by far
	the simplest format to write to as it is just a huge array of colours (at
	least 24-bit bitmaps are, and we only do them).
	
	This file handles the patterns selectable in lines and fills.
Legal:
	Version: MPL 1.1
	
	The contents of this file are subject to the Mozilla Public License Version 
	1.1 (the "License"); you may not use this file except in compliance with 
	the License. You may obtain a copy of the License at 
	http://www.mozilla.org/MPL/
	
	Software distributed under the License is distributed on an "AS IS" basis,
	WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
	for the specific language governing rights and limitations under the
	License.
	
	The Original Code is the YSI utils include.
	
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright (C) 2011
	the Initial Developer. All Rights Reserved.
	
	Contributors:
		ZeeX, koolk, JoeBullet/Google63, g_aSlice/Slice
	
	Thanks:
		JoeBullet/Google63 - Handy arbitrary ASM jump code using SCTRL.
		ZeeX - Very productive conversations.
		koolk - IsPlayerinAreaEx code.
		TheAlpha - Danish translation.
		breadfish - German translation.
		Fireburn - Dutch translation.
		yom - French translation.
		50p - Polish translation.
		Zamaroht - Spanish translation.
		Dracoblue, sintax, mabako, Xtreme, other coders - Producing other modes
			for me to strive to better.
		Pixels^ - Running XScripters where the idea was born.
		Matite - Pestering me to release it and using it.
	
	Very special thanks to:
		Thiadmer - PAWN, whose limits continue to amaze me!
		Kye/Kalcor - SA:MP.
		SA:MP Team past, present and future - SA:MP.
	
Version:
	0.1
Changelog:
	29/03/13:
		First version.
Functions:
	Stock:
		-
	Inline:
		-
Variables:
	Global:
		-
\**--------------------------------------------------------------------------**/

/*#define _PATTERN_FLAGS     (0x01010000)
#define _PATTERN_FADE_EDGE (0x01000000)

#define _PATTERN_WIDTH     (0xFE000000)
#define _PATTERN_PADDING   (0x00FE0000)

#define _PATTERN_MASK      (0x0000FFFF)

// Pre-defined patterns.
// ---------
#define PATTERN_SOLID    (0b1)
// - - - - -
#define PATTERN_DOTTED   (0b10)
// -- -- -- 
#define PATTERN_DASHED   (0b110)
// - -- - --
#define PATTERN_DOT_DASH (0b10110)
// --  --  --
#define PATTERN_WIDE_DASH (0b1100)
// - - -- - - --
#define PATTERN_DOT_DOT_DASH (0b1010110)
// - -- --- --
#define PATTERN_O_A_O_O_A_O_O_O_A_O_O_A (0b101101110110)*/

/*stock const
	PATTERN_SOLID = "PATTERN_SOLID",
	PATTERN_DOTTED = "PATTERN_DOTTED",
	PATTERN_SOLID = "PATTERN_SOLID";*/

/*#define PATTERN(%0) (_:_MK_PAT(0,%0@)&0xFFFF)
#define _MK_PAT(%1,%0) _yPd:_yPD:_yPS:(%1,%0)
// Dot.
#define _yPd:%9(%1,.%0) _MK_PAT((%1)*2|1,%0)
// Space.
#define _yPD:%9(%1,-%0) _MK_PAT((%1)*2,%0)
#define _yPS:%9(%1,)   (%1)
//#define _yPN:%9(%1,_%0)  _MK_PAT((%1)*2%0)*/

#define PATTERN_MASK_X (256)
#define PATTERN_MASK_Y (256)

stock
	// 8Kb
	BitArray:YSI_gBitmapAlpha[PATTERN_MASK_Y]<PATTERN_MASK_X>;

stock const
	BitArray:YSI_gBitmapBlank[PATTERN_MASK_Y]<PATTERN_MASK_X>;// = {Bit:0, ...};

//stock Bitmap_ResetPattern()
//{
//	YSI_gBitmapAlpha = YSI_gBitmapBlank;
//}

#define _Bitmap_ResetPattern() (YSI_gBitmapAlpha=YSI_gBitmapBlank)

#define PATTERN(%0) (_:_PATTERN:(#%0))
#define _PATTERN:(%0,%1) _PATTERN:(%0"\x2c;"#%1)

stock _Bitmap_DrawPattern(const pattern[], Bitmap:ctx, const posX, const posY, const colour0, const colour1, const offsetX, const offsetY)
{
	static
		func[32] = "_BMP_PAT@";
	new
		pos = strfind(pattern, ",");
	func[9] = '\0';
	strcat(func, pattern);
	if (pos == -1)
	{
		if (funcidx(func) == -1) func = "_BMP_PAT@SOLID";
		CallLocalFunction(func, "iiiiiiis", _:ctx, posX, posY, colour0, colour1, offsetX, offsetY, NULL);
	}
	else
	{
		func[pos + 9] = '\0';
		if (funcidx(func) == -1) func = "_BMP_PAT@SOLID";
		CallLocalFunction(func, "iiiiiiis", _:ctx, posX, posY, colour0, colour1, offsetX, offsetY, pattern[pos]);
	}
}

stock _Bitmap_Param(const str[], const find[])
{
	new
		pos = strfind(str, find, true),
		len = strlen(str),
		ch;
	if (0 < pos)
	{
		ch = str[pos - 1];
		if (ch == ' ' || ch == ',')
		{
			new
				p = pos;
			while (p != len)
			{
				ch = str[p];
				if (ch == '=')
				{
					return strval(str[++p]);
				}
				else if (ch == ',')
				{
					// There, but no value.
					return 0;
				}
				++p;
			}
			return 0;
		}
	}
	return cellmin;
}

forward _BMP_PAT@SOLID(Bitmap:ctx, const posX, const posY, const colour0, const colour1, const offsetX, const offsetY, const flags[]);

public _BMP_PAT@SOLID(Bitmap:ctx, const posX, const posY, const colour0, const colour1, const offsetX, const offsetY, const flags[])
{
	#pragma unused colour1
	// "offsetX" and "offsetY" are used when the main mask doesn't cover the
	// whole pattern.
	new
		width = Bitmap_Width(ctx),
		bmpX = min(posX + offsetX + PATTERN_MASK_X, width),
		bmpY = min(posY + offsetY + PATTERN_MASK_Y, Bitmap_Height(ctx));
	P:5("_Bitmap_DrawPattern@SOLID: %d, %d = %d; %d, %d = %d", posX + offsetX + PATTERN_MASK_X, width, bmpX, posY + offsetY + PATTERN_MASK_Y, Bitmap_Height(ctx), bmpY);
	// Calculate the colour information.
	new
		// Alpha.
		a = colour0 & 0xFF;
	switch (a)
	{
		case 0x00: return; // Stupid!
		case 0xFF:
		{
			for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
			{
				new
					read = Bitmap_IndexInt(ctx, sx, width, y);
				for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
				{
					if (YSI_gBitmapAlpha[yr][slot] & Bit:mask)
					{
						YSI_gMallocMemory[read] = colour0;
					}
					if (!(mask <<= 1))
					{
						mask = 1;
						++slot;
					}
					++read;
				}
			}
		}
		default  :
		{
			new
				// 256 - alpha.
				//n = 256 - a,
				// Colour components.
				r = ((colour0 & 0xFF000000) >>> 8) * a,
				g = ((colour0 & 0x00FF0000) >>> 8) * a,
				b = ((colour0 & 0x0000FF00) >>> 8) * a,
				orig;
			a = 256 - a;
			for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
			{
				new
					read = Bitmap_IndexInt(ctx, sx, width, y);
				for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
				{
					if (YSI_gBitmapAlpha[yr][slot] & Bit:mask)
					{
						// Want this pixel in the final image.
						orig = YSI_gMallocMemory[read];
						YSI_gMallocMemory[read] =
							((((orig & 0xFF000000) >>> 8) * a + r) & 0xFF000000) |
							((((orig & 0x00FF0000) >>> 8) * a + g) & 0x00FF0000) |
							((((orig & 0x0000FF00) >>> 8) * a + b) & 0x0000FF00) ;
					}
					if (!(mask <<= 1))
					{
						mask = 1;
						++slot;
					}
					++read;
				}
			}
		}
	}
}

forward _BMP_PAT@DIAGONAL(Bitmap:ctx, const posX, const posY, const colour0, const colour1, const offsetX, const offsetY, const flags[]);

public _BMP_PAT@DIAGONAL(Bitmap:ctx, const posX, const posY, const colour0, const colour1, const offsetX, const offsetY, const flags[])
{
	#pragma unused colour1
	// "offsetX" and "offsetY" are used when the main mask doesn't cover the
	// whole pattern.
	new
		width = Bitmap_Width(ctx),
		bmpX = min(posX + offsetX + PATTERN_MASK_X, width),
		bmpY = min(posY + offsetY + PATTERN_MASK_Y, Bitmap_Height(ctx));
	P:5("_Bitmap_DrawPattern@DIAGONAL: %d, %d = %d; %d, %d = %d", posX + offsetX + PATTERN_MASK_X, width, bmpX, posY + offsetY + PATTERN_MASK_Y, Bitmap_Height(ctx), bmpY);
	// Calculate the colour information.
	new
		// Alpha.
		stripe1 = _Bitmap_Param(flags, "stripe1"),
		stripe2 = _Bitmap_Param(flags, "stripe2"),
		left = _Bitmap_Param(flags, "right"),
		a = colour0 & 0xFF;
	if (stripe1 == cellmin) stripe1 = 8;
	if (stripe2 == cellmin) stripe2 = stripe1;
	new
		stripes = stripe1 + stripe2;
	switch (a)
	{
		case 0x00: return; // Stupid!
		case 0xFF:
		{
			if (left)
			{
				for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
				{
					new
						read = Bitmap_IndexInt(ctx, sx, width, y);
					for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
					{
						if (YSI_gBitmapAlpha[yr][slot] & Bit:mask && (x - y) % stripes < stripe1)
						{
							YSI_gMallocMemory[read] = colour0;
						}
						if (!(mask <<= 1))
						{
							mask = 1;
							++slot;
						}
						++read;
					}
				}
			}
			else
			{
				for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
				{
					new
						wy = width - y,
						read = Bitmap_IndexInt(ctx, sx, width, y);
					for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
					{
						if (YSI_gBitmapAlpha[yr][slot] & Bit:mask && (wy - x) % stripes < stripe1)
						{
							YSI_gMallocMemory[read] = colour0;
						}
						if (!(mask <<= 1))
						{
							mask = 1;
							++slot;
						}
						++read;
					}
				}
			}
		}
		default  :
		{
			new
				// 256 - alpha.
				//n = 256 - a,
				// Colour components.
				r = ((colour0 & 0xFF000000) >>> 8) * a,
				g = ((colour0 & 0x00FF0000) >>> 8) * a,
				b = ((colour0 & 0x0000FF00) >>> 8) * a,
				orig;
			a = 256 - a;
			if (left)
			{
				for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
				{
					new
						read = Bitmap_IndexInt(ctx, sx, width, y);
					for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
					{
						if (YSI_gBitmapAlpha[yr][slot] & Bit:mask && (x - y) % stripes < stripe1)
						{
							// Want this pixel in the final image.
							orig = YSI_gMallocMemory[read];
							YSI_gMallocMemory[read] =
								((((orig & 0xFF000000) >>> 8) * a + r) & 0xFF000000) |
								((((orig & 0x00FF0000) >>> 8) * a + g) & 0x00FF0000) |
								((((orig & 0x0000FF00) >>> 8) * a + b) & 0x0000FF00) ;
						}
						if (!(mask <<= 1))
						{
							mask = 1;
							++slot;
						}
						++read;
					}
				}
			}
			else
			{
				for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
				{
					new
						wy = width - y,
						read = Bitmap_IndexInt(ctx, sx, width, y);
					for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
					{
						if (YSI_gBitmapAlpha[yr][slot] & Bit:mask && (wy - x) % stripes < stripe1)
						{
							// Want this pixel in the final image.
							orig = YSI_gMallocMemory[read];
							YSI_gMallocMemory[read] =
								((((orig & 0xFF000000) >>> 8) * a + r) & 0xFF000000) |
								((((orig & 0x00FF0000) >>> 8) * a + g) & 0x00FF0000) |
								((((orig & 0x0000FF00) >>> 8) * a + b) & 0x0000FF00) ;
						}
						if (!(mask <<= 1))
						{
							mask = 1;
							++slot;
						}
						++read;
					}
				}
			}
		}
	}
}

forward _BMP_PAT@STRIPED(Bitmap:ctx, const posX, const posY, const colour0, const colour1, const offsetX, const offsetY, const flags[]);

public _BMP_PAT@STRIPED(Bitmap:ctx, const posX, const posY, const colour0, const colour1, const offsetX, const offsetY, const flags[])
{
	#pragma unused colour1
	// "offsetX" and "offsetY" are used when the main mask doesn't cover the
	// whole pattern.
	new
		width = Bitmap_Width(ctx),
		bmpX = min(posX + offsetX + PATTERN_MASK_X, width),
		bmpY = min(posY + offsetY + PATTERN_MASK_Y, Bitmap_Height(ctx));
	P:5("_Bitmap_DrawPattern@STRIPED: %d, %d = %d; %d, %d = %d", posX + offsetX + PATTERN_MASK_X, width, bmpX, posY + offsetY + PATTERN_MASK_Y, Bitmap_Height(ctx), bmpY);
	// Calculate the colour information.
	new
		// Alpha.
		stripe1 = _Bitmap_Param(flags, "stripe1"),
		stripe2 = _Bitmap_Param(flags, "stripe2"),
		vert = _Bitmap_Param(flags, "horizontal"),
		a = colour0 & 0xFF;
	if (stripe1 == cellmin) stripe1 = 8;
	if (stripe2 == cellmin) stripe2 = stripe1;
	new
		stripes = stripe1 + stripe2;
	switch (a)
	{
		case 0x00: return; // Stupid!
		case 0xFF:
		{
			if (vert)
			{
				for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
				{
					new
						read = Bitmap_IndexInt(ctx, sx, width, y);
					for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
					{
						if (YSI_gBitmapAlpha[yr][slot] & Bit:mask && x % stripes < stripe1)
						{
							YSI_gMallocMemory[read] = colour0;
						}
						if (!(mask <<= 1))
						{
							mask = 1;
							++slot;
						}
						++read;
					}
				}
			}
			else
			{
				for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
				{
					new
						read = Bitmap_IndexInt(ctx, sx, width, y);
					for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
					{
						if (YSI_gBitmapAlpha[yr][slot] & Bit:mask && y % stripes < stripe1)
						{
							YSI_gMallocMemory[read] = colour0;
						}
						if (!(mask <<= 1))
						{
							mask = 1;
							++slot;
						}
						++read;
					}
				}
			}
		}
		default  :
		{
			new
				// 256 - alpha.
				//n = 256 - a,
				// Colour components.
				r = ((colour0 & 0xFF000000) >>> 8) * a,
				g = ((colour0 & 0x00FF0000) >>> 8) * a,
				b = ((colour0 & 0x0000FF00) >>> 8) * a,
				orig;
			a = 256 - a;
			if (vert)
			{
				for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
				{
					new
						read = Bitmap_IndexInt(ctx, sx, width, y);
					for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
					{
						if (YSI_gBitmapAlpha[yr][slot] & Bit:mask && x % stripes < stripe1)
						{
							// Want this pixel in the final image.
							orig = YSI_gMallocMemory[read];
							YSI_gMallocMemory[read] =
								((((orig & 0xFF000000) >>> 8) * a + r) & 0xFF000000) |
								((((orig & 0x00FF0000) >>> 8) * a + g) & 0x00FF0000) |
								((((orig & 0x0000FF00) >>> 8) * a + b) & 0x0000FF00) ;
						}
						if (!(mask <<= 1))
						{
							mask = 1;
							++slot;
						}
						++read;
					}
				}
			}
			else
			{
				for (new y = posY + offsetY, sx = posX + offsetX, yr = 0; y != bmpY; ++y, ++yr)
				{
					new
						read = Bitmap_IndexInt(ctx, sx, width, y);
					for (new x = sx, slot = 0, mask = 1; x != bmpX; ++x)
					{
						if (YSI_gBitmapAlpha[yr][slot] & Bit:mask && y % stripes < stripe1)
						{
							// Want this pixel in the final image.
							orig = YSI_gMallocMemory[read];
							YSI_gMallocMemory[read] =
								((((orig & 0xFF000000) >>> 8) * a + r) & 0xFF000000) |
								((((orig & 0x00FF0000) >>> 8) * a + g) & 0x00FF0000) |
								((((orig & 0x0000FF00) >>> 8) * a + b) & 0x0000FF00) ;
						}
						if (!(mask <<= 1))
						{
							mask = 1;
							++slot;
						}
						++read;
					}
				}
			}
		}
	}
}
