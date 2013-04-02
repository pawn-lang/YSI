/**--------------------------------------------------------------------------**\
					=================================
					   y_bitmap - Generate bitmaps.
					=================================
Description:
	Code to generate images on the server in the bitmap format.  This is by far
	the simplest format to write to as it is just a huge array of colours (at
	least 24-bit bitmaps are, and we only do them).
	
	This file contains functions to draw various shapes.
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

// End the input above because all this code is being written with no testing
// or compiling until I am home again.  So in the interests of leaving the code
// stable, this is all ignored.
stock Bitmap_DrawRectangle(Bitmap:ctx, const minX, const minY, const maxX, const maxY, fillColour, lineColour = 0, linePattern[] = "SOLID", fillPattern[] = "SOLID")
{
	if (fillColour)
	{
		_Bitmap_DoRectangle(ctx, minX, minY, maxX, maxY, fillColour, fillPattern);
	}
	if (lineColour)
	{
		// Do the borders.
		if (strcmp(linePattern, "DOTTED", true, 6))
		{
			new
				border = _Bitmap_Param(linePattern, "border");
			if (border == cellmin) border = 8;
			//printf("1");
			_Bitmap_DoRectangle(ctx, minX - border, minY - border, maxX + border, minY, lineColour, linePattern);
			//printf("1");
			_Bitmap_DoRectangle(ctx, minX - border, minY, minX, maxY, lineColour, linePattern);
			//printf("1");
			_Bitmap_DoRectangle(ctx, minX - border, maxY, maxX + border, maxY + border, lineColour, linePattern);
			//printf("1");
			_Bitmap_DoRectangle(ctx, maxX, minY, maxX + border, maxY, lineColour, linePattern);
			//printf("1");
		}
		else
		{
			new
				border = _Bitmap_Param(linePattern, "border"),
				pat[128] = "STRIPED";
			strcat(pat, linePattern[6]);
			if (border == cellmin) border = 8;
			_Bitmap_DoRectangle(ctx, minX - border, minY - border, maxX + border, minY, lineColour, pat);
			_Bitmap_DoRectangle(ctx, minX - border, maxY, maxX + border, maxY + border, lineColour, pat);
			strcat(pat, ",HORIZONTAL");
			_Bitmap_DoRectangle(ctx, minX - border, minY, minX, maxY, lineColour, pat);
			_Bitmap_DoRectangle(ctx, maxX, minY, maxX + border, maxY, lineColour, pat);
		}
	}
}

static stock _Bitmap_DoRectangle(Bitmap:ctx, const minX, const minY, const maxX, const maxY, colour, pattern[])
{
	new
		xx = maxX - minX,
		yy = maxY - minY;
	// Basic version (uses the existing pixel code).
	// The patterns code doesn't exist yet.
	if (xx > PATTERN_MASK_X || yy > PATTERN_MASK_Y)
	{
		//P:E("Large rectangles are currently not supported in Bitmap_DrawRectangle.");
		//return;
		new
			tx = maxX - PATTERN_MASK_X,
			ty = maxY - PATTERN_MASK_Y,
			cy = minY;
		for ( ; cy < ty; cy += PATTERN_MASK_Y)
		{
			new
				cx = minX;
			Bit_SetAll(YSI_gBitmapAlpha[0], true);
			if (cx < tx)
			{
				_Bitmap_RectangleRecopy(PATTERN_MASK_Y, YSI_gBitmapAlpha[0]);
				do
				{
					_Bitmap_DrawPattern(pattern, ctx, cx, cy, colour, 0, 0, 0);
				}
				while ((cx += PATTERN_MASK_X) <= tx);
			}
			if (cx == maxX) continue;
			// Since they were all 1, blank out bits.
			tx = maxX - cx;
			new
				ss = bits<PATTERN_MASK_X>,
				bm = Bit_Slot(tx) + 1;
			while (ss-- != bm)
			{
				YSI_gBitmapAlpha[0][ss] = Bit:0;
			}
			bm = _:Bit_Mask(tx);
			do
			{
				YSI_gBitmapAlpha[0][ss] &= ~Bit:bm;
			}
			while ((bm <<= 1));
			_Bitmap_RectangleRecopy(PATTERN_MASK_Y, YSI_gBitmapAlpha[0]);
			_Bitmap_DrawPattern(pattern, ctx, cx, cy, colour, 0, 0, 0);
		}
		//cy = maxY - cy;
		_Bitmap_ResetPattern();
		tx = maxX - PATTERN_MASK_X;
		new
			cx = minX;
		Bit_SetAll(YSI_gBitmapAlpha[0], true);
		if (cx < tx)
		{
			_Bitmap_RectangleRecopy(maxY - cy, YSI_gBitmapAlpha[0]);
			do
			{
				_Bitmap_DrawPattern(pattern, ctx, cx, cy, colour, 0, 0, 0);
			}
			while ((cx += PATTERN_MASK_X) <= tx);
		}
		if (cx == maxX) return;
		// Since they were all 1, blank out bits.
		tx = maxX - cx;
		new
			ss = bits<PATTERN_MASK_X>,
			bm = Bit_Slot(tx) + 1;
		while (ss-- != bm)
		{
			YSI_gBitmapAlpha[0][ss] = Bit:0;
		}
		bm = _:Bit_Mask(tx);
		do
		{
			YSI_gBitmapAlpha[0][ss] &= ~Bit:bm;
		}
		while ((bm <<= 1));
		_Bitmap_RectangleRecopy(maxY - cy, YSI_gBitmapAlpha[0]);
		_Bitmap_DrawPattern(pattern, ctx, cx, cy, colour, 0, 0, 0);
	}
	else
	{
		// Reset the bit pattern array.
		_Bitmap_ResetPattern();
		// Set all the bits in the map.
		new
			ss,
			bm = Bit_Slot(xx);
		while (ss != bm)
		{
			YSI_gBitmapAlpha[0][ss++] = Bit:-1;
		}
		bm = _:Bit_Mask(xx);
		while ((bm >>>= 1))
		{
			YSI_gBitmapAlpha[0][ss] |= Bit:bm;
		}
		// Now copy for the other parts of the rectangle (easy and fast).
		_Bitmap_RectangleRecopy(yy, YSI_gBitmapAlpha[0]);
		_Bitmap_DrawPattern(pattern, ctx, minX, minY, colour, 0, 0, 0);
		//_Bitmap_DrawPattern@SOLID(ctx, minX, minY, fillColour, 0, 0, 0, 0);
	}
}

static stock _Bitmap_RectangleRecopy(n, BitArray:pattern<PATTERN_MASK_X>)
{
	for (new y = 1; y != n; ++y)
	{
		YSI_gBitmapAlpha[y] = pattern;
	}
}
