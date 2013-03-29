/**--------------------------------------------------------------------------**\
					=================================
					   y_bitmap - Generate bitmaps.
					=================================
Description:
	Code to generate images on the server in the bitmap format.  This is by far
	the simplest format to write to as it is just a huge array of colours (at
	least 24-bit bitmaps are, and we only do them).
	
	This file combines a colour with alpha on to the pixel already at the given
	location.
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

stock Bitmap_WritePixel(Bitmap:ctx, x, y, colour)
{
	new
		a = colour & 0xFF;
	switch (a)
	{
		case 0: return;
		case 0xFF: Bitmap_WriteCtx(ctx, x, y, colour);
		default:
		{
			/*// Blend them.
			new
				sr = (colour >>> 24) * a,
				sg = (colour >>> 16 & 0xFF) * a,
				sb = (colour >>>  8 & 0xFF) * a;
			a = 256 - a;
			new
				oc = Bitmap_ReadCtx(ctx, x, y),
				dr = (oc >>> 24) * a,
				dg = (oc >>> 16 & 0xFF) * a,
				db = (oc >>>  8 & 0xFF) * a;
			colour =
				(((sr + dr) / 256) << 24) |
				(((sg + dg) / 256) << 16 & 0x00FF0000) |
				(((sb + db) / 256) <<  8 & 0x0000FF00) |
				0xFF;
			Bitmap_WriteCtx(ctx, x, y, colour);*/
			// Blend them.
			new
				oc = Bitmap_ReadCtx(ctx, x, y),
				sr = (colour >>> 24) * a,
				sg = (colour >>> 16 & 0xFF) * a,
				sb = (colour >>>  8 & 0xFF) * a;
			a = 256 - a;
			colour = 0xFF
				| (((sr + ((oc >>> 24) * a)) / 256) << 24)
				| (((sg + ((oc >>> 16 & 0xFF) * a)) / 256) << 16 & 0x00FF0000)
				| (((sb + ((oc >>>  8 & 0xFF) * a)) / 256) <<  8 & 0x0000FF00);
			Bitmap_WriteCtx(ctx, x, y, colour);
		}
	}
}
