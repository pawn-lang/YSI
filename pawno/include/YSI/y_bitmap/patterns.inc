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

#define _PATTERN_FLAGS     (0x01010000)
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
#define PATTERN_O_A_O_O_A_O_O_O_A_O_O_A (0b101101110110)

#endinput

#define PATTERN(%0) (_:_MK_PAT(0,%0@)&0xFFFF)
#define _MK_PAT(%1,%0) _yPd:_yPD:_yPS:(%1,%0)
// Dot.
#define _yPd:%9(%1,.%0) _MK_PAT((%1)*2|1,%0)
// Space.
#define _yPD:%9(%1,-%0) _MK_PAT((%1)*2,%0)
#define _yPS:%9(%1,)   (%1)
//#define _yPN:%9(%1,_%0)  _MK_PAT((%1)*2%0)


