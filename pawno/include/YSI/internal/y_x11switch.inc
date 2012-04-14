/*----------------------------------------------------------------------------*\
					==========================
					 y_colours - X11 colours!
					==========================
Description:
	This holds the colour information that used to be part of the text system
	but which is far more useful than just for text.  This now supports the full
	set of X11 colours, both by name and by definition.  You can also define
	your own if you so choose (up to 32 - should be enough given that this
	includes the X11 colours).
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
	
	The Original Code is the YSI colours include.
	
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
	1.0
Changelog:
	29/11/10:
		Added the ability to use "X11" prefixes in strings.
		Added colourspace resolution for converting {FF0000} to ~r~.
	25/11/10:
		First version.
\*----------------------------------------------------------------------------*/

		switch (hash)
		{
			case _I(S,N,O,W):
				return alpha | X11_SNOW;
			case _I(G,H,O,S,T,W,H,I,T,E):
				return alpha | X11_GHOST_WHITE;
			case _I(G,H,O,S,T,_,W,H,I,T,E):
				return alpha | X11_GHOST_WHITE;
			case _I(G,H,O,S,T, ,W,H,I,T,E):
				return alpha | X11_GHOST_WHITE;
			case _I(W,H,I,T,E,S,M,O,K,E):
				return alpha | X11_WHITE_SMOKE;
			case _I(W,H,I,T,E,_,S,M,O,K,E):
				return alpha | X11_WHITE_SMOKE;
			case _I(W,H,I,T,E, ,S,M,O,K,E):
				return alpha | X11_WHITE_SMOKE;
			case _I(G,A,I,N,S,B,O,R,O):
				return alpha | X11_GAINSBORO;
			case _I(F,L,O,R,A,L,W,H,I,T,E):
				return alpha | X11_FLORAL_WHITE;
			case _I(F,L,O,R,A,L,_,W,H,I,T,E):
				return alpha | X11_FLORAL_WHITE;
			case _I(F,L,O,R,A,L, ,W,H,I,T,E):
				return alpha | X11_FLORAL_WHITE;
			case _I(O,L,D,L,A,C,E):
				return alpha | X11_OLD_LACE;
			case _I(O,L,D,_,L,A,C,E):
				return alpha | X11_OLD_LACE;
			case _I(O,L,D, ,L,A,C,E):
				return alpha | X11_OLD_LACE;
			case _I(L,I,N,E,N):
				return alpha | X11_LINEN;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E):
				return alpha | X11_ANTIQUE_WHITE;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E):
				return alpha | X11_ANTIQUE_WHITE;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E):
				return alpha | X11_ANTIQUE_WHITE;
			case _I(P,A,P,A,Y,A,W,H,I,P):
				return alpha | X11_PAPAYA_WHIP;
			case _I(P,A,P,A,Y,A,_,W,H,I,P):
				return alpha | X11_PAPAYA_WHIP;
			case _I(P,A,P,A,Y,A, ,W,H,I,P):
				return alpha | X11_PAPAYA_WHIP;
			case _I(B,L,A,N,C,H,E,D,A,L,M,O,N,D):
				return alpha | X11_BLANCHED_ALMOND;
			case _I(B,L,A,N,C,H,E,D,_,A,L,M,O,N,D):
				return alpha | X11_BLANCHED_ALMOND;
			case _I(B,L,A,N,C,H,E,D, ,A,L,M,O,N,D):
				return alpha | X11_BLANCHED_ALMOND;
			case _I(B,I,S,Q,U,E):
				return alpha | X11_BISQUE;
			case _I(P,E,A,C,H,P,U,F,F):
				return alpha | X11_PEACH_PUFF;
			case _I(P,E,A,C,H,_,P,U,F,F):
				return alpha | X11_PEACH_PUFF;
			case _I(P,E,A,C,H, ,P,U,F,F):
				return alpha | X11_PEACH_PUFF;
			case _I(N,A,V,A,J,O,W,H,I,T,E):
				return alpha | X11_NAVAJO_WHITE;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E):
				return alpha | X11_NAVAJO_WHITE;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E):
				return alpha | X11_NAVAJO_WHITE;
			case _I(M,O,C,C,A,S,I,N):
				return alpha | X11_MOCCASIN;
			case _I(C,O,R,N,S,I,L,K):
				return alpha | X11_CORNSILK;
			case _I(I,V,O,R,Y):
				return alpha | X11_IVORY;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N):
				return alpha | X11_LEMON_CHIFFON;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N):
				return alpha | X11_LEMON_CHIFFON;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N):
				return alpha | X11_LEMON_CHIFFON;
			case _I(S,E,A,S,H,E,L,L):
				return alpha | X11_SEASHELL;
			case _I(H,O,N,E,Y,D,E,W):
				return alpha | X11_HONEYDEW;
			case _I(M,I,N,T,C,R,E,A,M):
				return alpha | X11_MINT_CREAM;
			case _I(M,I,N,T,_,C,R,E,A,M):
				return alpha | X11_MINT_CREAM;
			case _I(M,I,N,T, ,C,R,E,A,M):
				return alpha | X11_MINT_CREAM;
			case _I(A,Z,U,R,E):
				return alpha | X11_AZURE;
			case _I(A,L,I,C,E,B,L,U,E):
				return alpha | X11_ALICE_BLUE;
			case _I(A,L,I,C,E,_,B,L,U,E):
				return alpha | X11_ALICE_BLUE;
			case _I(A,L,I,C,E, ,B,L,U,E):
				return alpha | X11_ALICE_BLUE;
			case _I(L,A,V,E,N,D,E,R):
				return alpha | X11_LAVENDER;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H):
				return alpha | X11_LAVENDER_BLUSH;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H):
				return alpha | X11_LAVENDER_BLUSH;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H):
				return alpha | X11_LAVENDER_BLUSH;
			case _I(M,I,S,T,Y,R,O,S,E):
				return alpha | X11_MISTY_ROSE;
			case _I(M,I,S,T,Y,_,R,O,S,E):
				return alpha | X11_MISTY_ROSE;
			case _I(M,I,S,T,Y, ,R,O,S,E):
				return alpha | X11_MISTY_ROSE;
			case _I(W,H,I,T,E):
				return alpha | X11_WHITE;
			case _I(B,L,A,C,K):
				return alpha | X11_BLACK;
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y):
				return alpha | X11_DARK_SLATE_GRAY;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y):
				return alpha | X11_DARK_SLATE_GRAY;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y):
				return alpha | X11_DARK_SLATE_GRAY;
			case _I(D,A,R,K,S,L,A,T,E,G,R,E,Y):
				return alpha | X11_DARK_SLATE_GREY;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,E,Y):
				return alpha | X11_DARK_SLATE_GREY;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,E,Y):
				return alpha | X11_DARK_SLATE_GREY;
			case _I(D,I,M,G,R,A,Y):
				return alpha | X11_DIM_GRAY;
			case _I(D,I,M,_,G,R,A,Y):
				return alpha | X11_DIM_GRAY;
			case _I(D,I,M, ,G,R,A,Y):
				return alpha | X11_DIM_GRAY;
			case _I(D,I,M,G,R,E,Y):
				return alpha | X11_DIM_GREY;
			case _I(D,I,M,_,G,R,E,Y):
				return alpha | X11_DIM_GREY;
			case _I(D,I,M, ,G,R,E,Y):
				return alpha | X11_DIM_GREY;
			case _I(S,L,A,T,E,G,R,A,Y):
				return alpha | X11_SLATE_GRAY;
			case _I(S,L,A,T,E,_,G,R,A,Y):
				return alpha | X11_SLATE_GRAY;
			case _I(S,L,A,T,E, ,G,R,A,Y):
				return alpha | X11_SLATE_GRAY;
			case _I(S,L,A,T,E,G,R,E,Y):
				return alpha | X11_SLATE_GREY;
			case _I(S,L,A,T,E,_,G,R,E,Y):
				return alpha | X11_SLATE_GREY;
			case _I(S,L,A,T,E, ,G,R,E,Y):
				return alpha | X11_SLATE_GREY;
			case _I(L,I,G,H,T,S,L,A,T,E,G,R,A,Y):
				return alpha | X11_LIGHT_SLATE_GRAY;
			case _I(L,I,G,H,T,_,S,L,A,T,E,_,G,R,A,Y):
				return alpha | X11_LIGHT_SLATE_GRAY;
			case _I(L,I,G,H,T, ,S,L,A,T,E, ,G,R,A,Y):
				return alpha | X11_LIGHT_SLATE_GRAY;
			case _I(L,I,G,H,T,S,L,A,T,E,G,R,E,Y):
				return alpha | X11_LIGHT_SLATE_GREY;
			case _I(L,I,G,H,T,_,S,L,A,T,E,_,G,R,E,Y):
				return alpha | X11_LIGHT_SLATE_GREY;
			case _I(L,I,G,H,T, ,S,L,A,T,E, ,G,R,E,Y):
				return alpha | X11_LIGHT_SLATE_GREY;
			case _I(G,R,A,Y):
				return alpha | X11_GRAY;
			case _I(G,R,E,Y):
				return alpha | X11_GREY;
			case _I(L,I,G,H,T,G,R,E,Y):
				return alpha | X11_LIGHT_GREY;
			case _I(L,I,G,H,T,_,G,R,E,Y):
				return alpha | X11_LIGHT_GREY;
			case _I(L,I,G,H,T, ,G,R,E,Y):
				return alpha | X11_LIGHT_GREY;
			case _I(L,I,G,H,T,G,R,A,Y):
				return alpha | X11_LIGHT_GRAY;
			case _I(L,I,G,H,T,_,G,R,A,Y):
				return alpha | X11_LIGHT_GRAY;
			case _I(L,I,G,H,T, ,G,R,A,Y):
				return alpha | X11_LIGHT_GRAY;
			case _I(M,I,D,N,I,G,H,T,B,L,U,E):
				return alpha | X11_MIDNIGHT_BLUE;
			case _I(M,I,D,N,I,G,H,T,_,B,L,U,E):
				return alpha | X11_MIDNIGHT_BLUE;
			case _I(M,I,D,N,I,G,H,T, ,B,L,U,E):
				return alpha | X11_MIDNIGHT_BLUE;
			case _I(N,A,V,Y):
				return alpha | X11_NAVY;
			case _I(N,A,V,Y,B,L,U,E):
				return alpha | X11_NAVY_BLUE;
			case _I(N,A,V,Y,_,B,L,U,E):
				return alpha | X11_NAVY_BLUE;
			case _I(N,A,V,Y, ,B,L,U,E):
				return alpha | X11_NAVY_BLUE;
			case _I(C,O,R,N,F,L,O,W,E,R,B,L,U,E):
				return alpha | X11_CORNFLOWER_BLUE;
			case _I(C,O,R,N,F,L,O,W,E,R,_,B,L,U,E):
				return alpha | X11_CORNFLOWER_BLUE;
			case _I(C,O,R,N,F,L,O,W,E,R, ,B,L,U,E):
				return alpha | X11_CORNFLOWER_BLUE;
			case _I(D,A,R,K,S,L,A,T,E,B,L,U,E):
				return alpha | X11_DARK_SLATE_BLUE;
			case _I(D,A,R,K,_,S,L,A,T,E,_,B,L,U,E):
				return alpha | X11_DARK_SLATE_BLUE;
			case _I(D,A,R,K, ,S,L,A,T,E, ,B,L,U,E):
				return alpha | X11_DARK_SLATE_BLUE;
			case _I(S,L,A,T,E,B,L,U,E):
				return alpha | X11_SLATE_BLUE;
			case _I(S,L,A,T,E,_,B,L,U,E):
				return alpha | X11_SLATE_BLUE;
			case _I(S,L,A,T,E, ,B,L,U,E):
				return alpha | X11_SLATE_BLUE;
			case _I(M,E,D,I,U,M,S,L,A,T,E,B,L,U,E):
				return alpha | X11_MEDIUM_SLATE_BLUE;
			case _I(M,E,D,I,U,M,_,S,L,A,T,E,_,B,L,U,E):
				return alpha | X11_MEDIUM_SLATE_BLUE;
			case _I(M,E,D,I,U,M, ,S,L,A,T,E, ,B,L,U,E):
				return alpha | X11_MEDIUM_SLATE_BLUE;
			case _I(L,I,G,H,T,S,L,A,T,E,B,L,U,E):
				return alpha | X11_LIGHT_SLATE_BLUE;
			case _I(L,I,G,H,T,_,S,L,A,T,E,_,B,L,U,E):
				return alpha | X11_LIGHT_SLATE_BLUE;
			case _I(L,I,G,H,T, ,S,L,A,T,E, ,B,L,U,E):
				return alpha | X11_LIGHT_SLATE_BLUE;
			case _I(M,E,D,I,U,M,B,L,U,E):
				return alpha | X11_MEDIUM_BLUE;
			case _I(M,E,D,I,U,M,_,B,L,U,E):
				return alpha | X11_MEDIUM_BLUE;
			case _I(M,E,D,I,U,M, ,B,L,U,E):
				return alpha | X11_MEDIUM_BLUE;
			case _I(R,O,Y,A,L,B,L,U,E):
				return alpha | X11_ROYAL_BLUE;
			case _I(R,O,Y,A,L,_,B,L,U,E):
				return alpha | X11_ROYAL_BLUE;
			case _I(R,O,Y,A,L, ,B,L,U,E):
				return alpha | X11_ROYAL_BLUE;
			case _I(B,L,U,E):
				return alpha | X11_BLUE;
			case _I(D,O,D,G,E,R,B,L,U,E):
				return alpha | X11_DODGER_BLUE;
			case _I(D,O,D,G,E,R,_,B,L,U,E):
				return alpha | X11_DODGER_BLUE;
			case _I(D,O,D,G,E,R, ,B,L,U,E):
				return alpha | X11_DODGER_BLUE;
			case _I(D,E,E,P,S,K,Y,B,L,U,E):
				return alpha | X11_DEEP_SKY_BLUE;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E):
				return alpha | X11_DEEP_SKY_BLUE;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E):
				return alpha | X11_DEEP_SKY_BLUE;
			case _I(S,K,Y,B,L,U,E):
				return alpha | X11_SKY_BLUE;
			case _I(S,K,Y,_,B,L,U,E):
				return alpha | X11_SKY_BLUE;
			case _I(S,K,Y, ,B,L,U,E):
				return alpha | X11_SKY_BLUE;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E):
				return alpha | X11_LIGHT_SKY_BLUE;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E):
				return alpha | X11_LIGHT_SKY_BLUE;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E):
				return alpha | X11_LIGHT_SKY_BLUE;
			case _I(S,T,E,E,L,B,L,U,E):
				return alpha | X11_STEEL_BLUE;
			case _I(S,T,E,E,L,_,B,L,U,E):
				return alpha | X11_STEEL_BLUE;
			case _I(S,T,E,E,L, ,B,L,U,E):
				return alpha | X11_STEEL_BLUE;
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E):
				return alpha | X11_LIGHT_STEEL_BLUE;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E):
				return alpha | X11_LIGHT_STEEL_BLUE;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E):
				return alpha | X11_LIGHT_STEEL_BLUE;
			case _I(L,I,G,H,T,B,L,U,E):
				return alpha | X11_LIGHT_BLUE;
			case _I(L,I,G,H,T,_,B,L,U,E):
				return alpha | X11_LIGHT_BLUE;
			case _I(L,I,G,H,T, ,B,L,U,E):
				return alpha | X11_LIGHT_BLUE;
			case _I(P,O,W,D,E,R,B,L,U,E):
				return alpha | X11_POWDER_BLUE;
			case _I(P,O,W,D,E,R,_,B,L,U,E):
				return alpha | X11_POWDER_BLUE;
			case _I(P,O,W,D,E,R, ,B,L,U,E):
				return alpha | X11_POWDER_BLUE;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_PALE_TURQUOISE;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_PALE_TURQUOISE;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_PALE_TURQUOISE;
			case _I(D,A,R,K,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_DARK_TURQUOISE;
			case _I(D,A,R,K,_,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_DARK_TURQUOISE;
			case _I(D,A,R,K, ,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_DARK_TURQUOISE;
			case _I(M,E,D,I,U,M,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_MEDIUM_TURQUOISE;
			case _I(M,E,D,I,U,M,_,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_MEDIUM_TURQUOISE;
			case _I(M,E,D,I,U,M, ,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_MEDIUM_TURQUOISE;
			case _I(T,U,R,Q,U,O,I,S,E):
				return alpha | X11_TURQUOISE;
			case _I(C,Y,A,N):
				return alpha | X11_CYAN;
			case _I(L,I,G,H,T,C,Y,A,N):
				return alpha | X11_LIGHT_CYAN;
			case _I(L,I,G,H,T,_,C,Y,A,N):
				return alpha | X11_LIGHT_CYAN;
			case _I(L,I,G,H,T, ,C,Y,A,N):
				return alpha | X11_LIGHT_CYAN;
			case _I(C,A,D,E,T,B,L,U,E):
				return alpha | X11_CADET_BLUE;
			case _I(C,A,D,E,T,_,B,L,U,E):
				return alpha | X11_CADET_BLUE;
			case _I(C,A,D,E,T, ,B,L,U,E):
				return alpha | X11_CADET_BLUE;
			case _I(M,E,D,I,U,M,A,Q,U,A,M,A,R,I,N,E):
				return alpha | X11_MEDIUM_AQUAMARINE;
			case _I(M,E,D,I,U,M,_,A,Q,U,A,M,A,R,I,N,E):
				return alpha | X11_MEDIUM_AQUAMARINE;
			case _I(M,E,D,I,U,M, ,A,Q,U,A,M,A,R,I,N,E):
				return alpha | X11_MEDIUM_AQUAMARINE;
			case _I(A,Q,U,A,M,A,R,I,N,E):
				return alpha | X11_AQUAMARINE;
			case _I(D,A,R,K,G,R,E,E,N):
				return alpha | X11_DARK_GREEN;
			case _I(D,A,R,K,_,G,R,E,E,N):
				return alpha | X11_DARK_GREEN;
			case _I(D,A,R,K, ,G,R,E,E,N):
				return alpha | X11_DARK_GREEN;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N):
				return alpha | X11_DARK_OLIVE_GREEN;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N):
				return alpha | X11_DARK_OLIVE_GREEN;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N):
				return alpha | X11_DARK_OLIVE_GREEN;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N):
				return alpha | X11_DARK_SEA_GREEN;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N):
				return alpha | X11_DARK_SEA_GREEN;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N):
				return alpha | X11_DARK_SEA_GREEN;
			case _I(S,E,A,G,R,E,E,N):
				return alpha | X11_SEA_GREEN;
			case _I(S,E,A,_,G,R,E,E,N):
				return alpha | X11_SEA_GREEN;
			case _I(S,E,A, ,G,R,E,E,N):
				return alpha | X11_SEA_GREEN;
			case _I(M,E,D,I,U,M,S,E,A,G,R,E,E,N):
				return alpha | X11_MEDIUM_SEA_GREEN;
			case _I(M,E,D,I,U,M,_,S,E,A,_,G,R,E,E,N):
				return alpha | X11_MEDIUM_SEA_GREEN;
			case _I(M,E,D,I,U,M, ,S,E,A, ,G,R,E,E,N):
				return alpha | X11_MEDIUM_SEA_GREEN;
			case _I(L,I,G,H,T,S,E,A,G,R,E,E,N):
				return alpha | X11_LIGHT_SEA_GREEN;
			case _I(L,I,G,H,T,_,S,E,A,_,G,R,E,E,N):
				return alpha | X11_LIGHT_SEA_GREEN;
			case _I(L,I,G,H,T, ,S,E,A, ,G,R,E,E,N):
				return alpha | X11_LIGHT_SEA_GREEN;
			case _I(P,A,L,E,G,R,E,E,N):
				return alpha | X11_PALE_GREEN;
			case _I(P,A,L,E,_,G,R,E,E,N):
				return alpha | X11_PALE_GREEN;
			case _I(P,A,L,E, ,G,R,E,E,N):
				return alpha | X11_PALE_GREEN;
			case _I(S,P,R,I,N,G,G,R,E,E,N):
				return alpha | X11_SPRING_GREEN;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N):
				return alpha | X11_SPRING_GREEN;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N):
				return alpha | X11_SPRING_GREEN;
			case _I(L,A,W,N,G,R,E,E,N):
				return alpha | X11_LAWN_GREEN;
			case _I(L,A,W,N,_,G,R,E,E,N):
				return alpha | X11_LAWN_GREEN;
			case _I(L,A,W,N, ,G,R,E,E,N):
				return alpha | X11_LAWN_GREEN;
			case _I(G,R,E,E,N):
				return alpha | X11_GREEN;
			case _I(C,H,A,R,T,R,E,U,S,E):
				return alpha | X11_CHARTREUSE;
			case _I(M,E,D,I,U,M,S,P,R,I,N,G,G,R,E,E,N):
				return alpha | X11_MEDIUM_SPRING_GREEN;
			case _I(M,E,D,I,U,M,_,S,P,R,I,N,G,_,G,R,E,E,N):
				return alpha | X11_MEDIUM_SPRING_GREEN;
			case _I(M,E,D,I,U,M, ,S,P,R,I,N,G, ,G,R,E,E,N):
				return alpha | X11_MEDIUM_SPRING_GREEN;
			case _I(G,R,E,E,N,Y,E,L,L,O,W):
				return alpha | X11_GREEN_YELLOW;
			case _I(G,R,E,E,N,_,Y,E,L,L,O,W):
				return alpha | X11_GREEN_YELLOW;
			case _I(G,R,E,E,N, ,Y,E,L,L,O,W):
				return alpha | X11_GREEN_YELLOW;
			case _I(L,I,M,E,G,R,E,E,N):
				return alpha | X11_LIME_GREEN;
			case _I(L,I,M,E,_,G,R,E,E,N):
				return alpha | X11_LIME_GREEN;
			case _I(L,I,M,E, ,G,R,E,E,N):
				return alpha | X11_LIME_GREEN;
			case _I(Y,E,L,L,O,W,G,R,E,E,N):
				return alpha | X11_YELLOW_GREEN;
			case _I(Y,E,L,L,O,W,_,G,R,E,E,N):
				return alpha | X11_YELLOW_GREEN;
			case _I(Y,E,L,L,O,W, ,G,R,E,E,N):
				return alpha | X11_YELLOW_GREEN;
			case _I(F,O,R,E,S,T,G,R,E,E,N):
				return alpha | X11_FOREST_GREEN;
			case _I(F,O,R,E,S,T,_,G,R,E,E,N):
				return alpha | X11_FOREST_GREEN;
			case _I(F,O,R,E,S,T, ,G,R,E,E,N):
				return alpha | X11_FOREST_GREEN;
			case _I(O,L,I,V,E,D,R,A,B):
				return alpha | X11_OLIVE_DRAB;
			case _I(O,L,I,V,E,_,D,R,A,B):
				return alpha | X11_OLIVE_DRAB;
			case _I(O,L,I,V,E, ,D,R,A,B):
				return alpha | X11_OLIVE_DRAB;
			case _I(D,A,R,K,K,H,A,K,I):
				return alpha | X11_DARK_KHAKI;
			case _I(D,A,R,K,_,K,H,A,K,I):
				return alpha | X11_DARK_KHAKI;
			case _I(D,A,R,K, ,K,H,A,K,I):
				return alpha | X11_DARK_KHAKI;
			case _I(K,H,A,K,I):
				return alpha | X11_KHAKI;
			case _I(P,A,L,E,G,O,L,D,E,N,R,O,D):
				return alpha | X11_PALE_GOLDENROD;
			case _I(P,A,L,E,_,G,O,L,D,E,N,R,O,D):
				return alpha | X11_PALE_GOLDENROD;
			case _I(P,A,L,E, ,G,O,L,D,E,N,R,O,D):
				return alpha | X11_PALE_GOLDENROD;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_GOLDENROD_YELLOW;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_GOLDENROD_YELLOW;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_GOLDENROD_YELLOW;
			case _I(L,I,G,H,T,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_YELLOW;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_YELLOW;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_YELLOW;
			case _I(Y,E,L,L,O,W):
				return alpha | X11_YELLOW;
			case _I(G,O,L,D):
				return alpha | X11_GOLD;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D):
				return alpha | X11_LIGHT_GOLDENROD;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D):
				return alpha | X11_LIGHT_GOLDENROD;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D):
				return alpha | X11_LIGHT_GOLDENROD;
			case _I(G,O,L,D,E,N,R,O,D):
				return alpha | X11_GOLDENROD;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D):
				return alpha | X11_DARK_GOLDENROD;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D):
				return alpha | X11_DARK_GOLDENROD;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D):
				return alpha | X11_DARK_GOLDENROD;
			case _I(R,O,S,Y,B,R,O,W,N):
				return alpha | X11_ROSY_BROWN;
			case _I(R,O,S,Y,_,B,R,O,W,N):
				return alpha | X11_ROSY_BROWN;
			case _I(R,O,S,Y, ,B,R,O,W,N):
				return alpha | X11_ROSY_BROWN;
			case _I(I,N,D,I,A,N,R,E,D):
				return alpha | X11_INDIAN_RED;
			case _I(I,N,D,I,A,N,_,R,E,D):
				return alpha | X11_INDIAN_RED;
			case _I(I,N,D,I,A,N, ,R,E,D):
				return alpha | X11_INDIAN_RED;
			case _I(S,A,D,D,L,E,B,R,O,W,N):
				return alpha | X11_SADDLE_BROWN;
			case _I(S,A,D,D,L,E,_,B,R,O,W,N):
				return alpha | X11_SADDLE_BROWN;
			case _I(S,A,D,D,L,E, ,B,R,O,W,N):
				return alpha | X11_SADDLE_BROWN;
			case _I(S,I,E,N,N,A):
				return alpha | X11_SIENNA;
			case _I(P,E,R,U):
				return alpha | X11_PERU;
			case _I(B,U,R,L,Y,W,O,O,D):
				return alpha | X11_BURLYWOOD;
			case _I(B,E,I,G,E):
				return alpha | X11_BEIGE;
			case _I(W,H,E,A,T):
				return alpha | X11_WHEAT;
			case _I(S,A,N,D,Y,B,R,O,W,N):
				return alpha | X11_SANDY_BROWN;
			case _I(S,A,N,D,Y,_,B,R,O,W,N):
				return alpha | X11_SANDY_BROWN;
			case _I(S,A,N,D,Y, ,B,R,O,W,N):
				return alpha | X11_SANDY_BROWN;
			case _I(T,A,N):
				return alpha | X11_TAN;
			case _I(C,H,O,C,O,L,A,T,E):
				return alpha | X11_CHOCOLATE;
			case _I(F,I,R,E,B,R,I,C,K):
				return alpha | X11_FIREBRICK;
			case _I(B,R,O,W,N):
				return alpha | X11_BROWN;
			case _I(D,A,R,K,S,A,L,M,O,N):
				return alpha | X11_DARK_SALMON;
			case _I(D,A,R,K,_,S,A,L,M,O,N):
				return alpha | X11_DARK_SALMON;
			case _I(D,A,R,K, ,S,A,L,M,O,N):
				return alpha | X11_DARK_SALMON;
			case _I(S,A,L,M,O,N):
				return alpha | X11_SALMON;
			case _I(L,I,G,H,T,S,A,L,M,O,N):
				return alpha | X11_LIGHT_SALMON;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N):
				return alpha | X11_LIGHT_SALMON;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N):
				return alpha | X11_LIGHT_SALMON;
			case _I(O,R,A,N,G,E):
				return alpha | X11_ORANGE;
			case _I(D,A,R,K,O,R,A,N,G,E):
				return alpha | X11_DARK_ORANGE;
			case _I(D,A,R,K,_,O,R,A,N,G,E):
				return alpha | X11_DARK_ORANGE;
			case _I(D,A,R,K, ,O,R,A,N,G,E):
				return alpha | X11_DARK_ORANGE;
			case _I(C,O,R,A,L):
				return alpha | X11_CORAL;
			case _I(L,I,G,H,T,C,O,R,A,L):
				return alpha | X11_LIGHT_CORAL;
			case _I(L,I,G,H,T,_,C,O,R,A,L):
				return alpha | X11_LIGHT_CORAL;
			case _I(L,I,G,H,T, ,C,O,R,A,L):
				return alpha | X11_LIGHT_CORAL;
			case _I(T,O,M,A,T,O):
				return alpha | X11_TOMATO;
			case _I(O,R,A,N,G,E,R,E,D):
				return alpha | X11_ORANGE_RED;
			case _I(O,R,A,N,G,E,_,R,E,D):
				return alpha | X11_ORANGE_RED;
			case _I(O,R,A,N,G,E, ,R,E,D):
				return alpha | X11_ORANGE_RED;
			case _I(R,E,D):
				return alpha | X11_RED;
			case _I(H,O,T,P,I,N,K):
				return alpha | X11_HOT_PINK;
			case _I(H,O,T,_,P,I,N,K):
				return alpha | X11_HOT_PINK;
			case _I(H,O,T, ,P,I,N,K):
				return alpha | X11_HOT_PINK;
			case _I(D,E,E,P,P,I,N,K):
				return alpha | X11_DEEP_PINK;
			case _I(D,E,E,P,_,P,I,N,K):
				return alpha | X11_DEEP_PINK;
			case _I(D,E,E,P, ,P,I,N,K):
				return alpha | X11_DEEP_PINK;
			case _I(P,I,N,K):
				return alpha | X11_PINK;
			case _I(L,I,G,H,T,P,I,N,K):
				return alpha | X11_LIGHT_PINK;
			case _I(L,I,G,H,T,_,P,I,N,K):
				return alpha | X11_LIGHT_PINK;
			case _I(L,I,G,H,T, ,P,I,N,K):
				return alpha | X11_LIGHT_PINK;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D):
				return alpha | X11_PALE_VIOLET_RED;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D):
				return alpha | X11_PALE_VIOLET_RED;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D):
				return alpha | X11_PALE_VIOLET_RED;
			case _I(M,A,R,O,O,N):
				return alpha | X11_MAROON;
			case _I(M,E,D,I,U,M,V,I,O,L,E,T,R,E,D):
				return alpha | X11_MEDIUM_VIOLET_RED;
			case _I(M,E,D,I,U,M,_,V,I,O,L,E,T,_,R,E,D):
				return alpha | X11_MEDIUM_VIOLET_RED;
			case _I(M,E,D,I,U,M, ,V,I,O,L,E,T, ,R,E,D):
				return alpha | X11_MEDIUM_VIOLET_RED;
			case _I(V,I,O,L,E,T,R,E,D):
				return alpha | X11_VIOLET_RED;
			case _I(V,I,O,L,E,T,_,R,E,D):
				return alpha | X11_VIOLET_RED;
			case _I(V,I,O,L,E,T, ,R,E,D):
				return alpha | X11_VIOLET_RED;
			case _I(M,A,G,E,N,T,A):
				return alpha | X11_MAGENTA;
			case _I(V,I,O,L,E,T):
				return alpha | X11_VIOLET;
			case _I(P,L,U,M):
				return alpha | X11_PLUM;
			case _I(O,R,C,H,I,D):
				return alpha | X11_ORCHID;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D):
				return alpha | X11_MEDIUM_ORCHID;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D):
				return alpha | X11_MEDIUM_ORCHID;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D):
				return alpha | X11_MEDIUM_ORCHID;
			case _I(D,A,R,K,O,R,C,H,I,D):
				return alpha | X11_DARK_ORCHID;
			case _I(D,A,R,K,_,O,R,C,H,I,D):
				return alpha | X11_DARK_ORCHID;
			case _I(D,A,R,K, ,O,R,C,H,I,D):
				return alpha | X11_DARK_ORCHID;
			case _I(D,A,R,K,V,I,O,L,E,T):
				return alpha | X11_DARK_VIOLET;
			case _I(D,A,R,K,_,V,I,O,L,E,T):
				return alpha | X11_DARK_VIOLET;
			case _I(D,A,R,K, ,V,I,O,L,E,T):
				return alpha | X11_DARK_VIOLET;
			case _I(B,L,U,E,V,I,O,L,E,T):
				return alpha | X11_BLUE_VIOLET;
			case _I(B,L,U,E,_,V,I,O,L,E,T):
				return alpha | X11_BLUE_VIOLET;
			case _I(B,L,U,E, ,V,I,O,L,E,T):
				return alpha | X11_BLUE_VIOLET;
			case _I(P,U,R,P,L,E):
				return alpha | X11_PURPLE;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E):
				return alpha | X11_MEDIUM_PURPLE;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E):
				return alpha | X11_MEDIUM_PURPLE;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E):
				return alpha | X11_MEDIUM_PURPLE;
			case _I(T,H,I,S,T,L,E):
				return alpha | X11_THISTLE;
			case _I(S,N,O,W,1):
				return alpha | X11_SNOW_1;
			case _I(S,N,O,W,_,1):
				return alpha | X11_SNOW_1;
			case _I(S,N,O,W, ,1):
				return alpha | X11_SNOW_1;
			case _I(S,N,O,W,2):
				return alpha | X11_SNOW_2;
			case _I(S,N,O,W,_,2):
				return alpha | X11_SNOW_2;
			case _I(S,N,O,W, ,2):
				return alpha | X11_SNOW_2;
			case _I(S,N,O,W,3):
				return alpha | X11_SNOW_3;
			case _I(S,N,O,W,_,3):
				return alpha | X11_SNOW_3;
			case _I(S,N,O,W, ,3):
				return alpha | X11_SNOW_3;
			case _I(S,N,O,W,4):
				return alpha | X11_SNOW_4;
			case _I(S,N,O,W,_,4):
				return alpha | X11_SNOW_4;
			case _I(S,N,O,W, ,4):
				return alpha | X11_SNOW_4;
			case _I(S,E,A,S,H,E,L,L,1):
				return alpha | X11_SEASHELL_1;
			case _I(S,E,A,S,H,E,L,L,_,1):
				return alpha | X11_SEASHELL_1;
			case _I(S,E,A,S,H,E,L,L, ,1):
				return alpha | X11_SEASHELL_1;
			case _I(S,E,A,S,H,E,L,L,2):
				return alpha | X11_SEASHELL_2;
			case _I(S,E,A,S,H,E,L,L,_,2):
				return alpha | X11_SEASHELL_2;
			case _I(S,E,A,S,H,E,L,L, ,2):
				return alpha | X11_SEASHELL_2;
			case _I(S,E,A,S,H,E,L,L,3):
				return alpha | X11_SEASHELL_3;
			case _I(S,E,A,S,H,E,L,L,_,3):
				return alpha | X11_SEASHELL_3;
			case _I(S,E,A,S,H,E,L,L, ,3):
				return alpha | X11_SEASHELL_3;
			case _I(S,E,A,S,H,E,L,L,4):
				return alpha | X11_SEASHELL_4;
			case _I(S,E,A,S,H,E,L,L,_,4):
				return alpha | X11_SEASHELL_4;
			case _I(S,E,A,S,H,E,L,L, ,4):
				return alpha | X11_SEASHELL_4;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E,1):
				return alpha | X11_ANTIQUE_WHITE_1;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E,_,1):
				return alpha | X11_ANTIQUE_WHITE_1;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E, ,1):
				return alpha | X11_ANTIQUE_WHITE_1;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E,2):
				return alpha | X11_ANTIQUE_WHITE_2;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E,_,2):
				return alpha | X11_ANTIQUE_WHITE_2;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E, ,2):
				return alpha | X11_ANTIQUE_WHITE_2;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E,3):
				return alpha | X11_ANTIQUE_WHITE_3;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E,_,3):
				return alpha | X11_ANTIQUE_WHITE_3;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E, ,3):
				return alpha | X11_ANTIQUE_WHITE_3;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E,4):
				return alpha | X11_ANTIQUE_WHITE_4;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E,_,4):
				return alpha | X11_ANTIQUE_WHITE_4;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E, ,4):
				return alpha | X11_ANTIQUE_WHITE_4;
			case _I(B,I,S,Q,U,E,1):
				return alpha | X11_BISQUE_1;
			case _I(B,I,S,Q,U,E,_,1):
				return alpha | X11_BISQUE_1;
			case _I(B,I,S,Q,U,E, ,1):
				return alpha | X11_BISQUE_1;
			case _I(B,I,S,Q,U,E,2):
				return alpha | X11_BISQUE_2;
			case _I(B,I,S,Q,U,E,_,2):
				return alpha | X11_BISQUE_2;
			case _I(B,I,S,Q,U,E, ,2):
				return alpha | X11_BISQUE_2;
			case _I(B,I,S,Q,U,E,3):
				return alpha | X11_BISQUE_3;
			case _I(B,I,S,Q,U,E,_,3):
				return alpha | X11_BISQUE_3;
			case _I(B,I,S,Q,U,E, ,3):
				return alpha | X11_BISQUE_3;
			case _I(B,I,S,Q,U,E,4):
				return alpha | X11_BISQUE_4;
			case _I(B,I,S,Q,U,E,_,4):
				return alpha | X11_BISQUE_4;
			case _I(B,I,S,Q,U,E, ,4):
				return alpha | X11_BISQUE_4;
			case _I(P,E,A,C,H,P,U,F,F,1):
				return alpha | X11_PEACH_PUFF_1;
			case _I(P,E,A,C,H,_,P,U,F,F,_,1):
				return alpha | X11_PEACH_PUFF_1;
			case _I(P,E,A,C,H, ,P,U,F,F, ,1):
				return alpha | X11_PEACH_PUFF_1;
			case _I(P,E,A,C,H,P,U,F,F,2):
				return alpha | X11_PEACH_PUFF_2;
			case _I(P,E,A,C,H,_,P,U,F,F,_,2):
				return alpha | X11_PEACH_PUFF_2;
			case _I(P,E,A,C,H, ,P,U,F,F, ,2):
				return alpha | X11_PEACH_PUFF_2;
			case _I(P,E,A,C,H,P,U,F,F,3):
				return alpha | X11_PEACH_PUFF_3;
			case _I(P,E,A,C,H,_,P,U,F,F,_,3):
				return alpha | X11_PEACH_PUFF_3;
			case _I(P,E,A,C,H, ,P,U,F,F, ,3):
				return alpha | X11_PEACH_PUFF_3;
			case _I(P,E,A,C,H,P,U,F,F,4):
				return alpha | X11_PEACH_PUFF_4;
			case _I(P,E,A,C,H,_,P,U,F,F,_,4):
				return alpha | X11_PEACH_PUFF_4;
			case _I(P,E,A,C,H, ,P,U,F,F, ,4):
				return alpha | X11_PEACH_PUFF_4;
			case _I(N,A,V,A,J,O,W,H,I,T,E,1):
				return alpha | X11_NAVAJO_WHITE_1;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E,_,1):
				return alpha | X11_NAVAJO_WHITE_1;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E, ,1):
				return alpha | X11_NAVAJO_WHITE_1;
			case _I(N,A,V,A,J,O,W,H,I,T,E,2):
				return alpha | X11_NAVAJO_WHITE_2;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E,_,2):
				return alpha | X11_NAVAJO_WHITE_2;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E, ,2):
				return alpha | X11_NAVAJO_WHITE_2;
			case _I(N,A,V,A,J,O,W,H,I,T,E,3):
				return alpha | X11_NAVAJO_WHITE_3;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E,_,3):
				return alpha | X11_NAVAJO_WHITE_3;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E, ,3):
				return alpha | X11_NAVAJO_WHITE_3;
			case _I(N,A,V,A,J,O,W,H,I,T,E,4):
				return alpha | X11_NAVAJO_WHITE_4;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E,_,4):
				return alpha | X11_NAVAJO_WHITE_4;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E, ,4):
				return alpha | X11_NAVAJO_WHITE_4;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N,1):
				return alpha | X11_LEMON_CHIFFON_1;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N,_,1):
				return alpha | X11_LEMON_CHIFFON_1;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N, ,1):
				return alpha | X11_LEMON_CHIFFON_1;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N,2):
				return alpha | X11_LEMON_CHIFFON_2;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N,_,2):
				return alpha | X11_LEMON_CHIFFON_2;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N, ,2):
				return alpha | X11_LEMON_CHIFFON_2;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N,3):
				return alpha | X11_LEMON_CHIFFON_3;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N,_,3):
				return alpha | X11_LEMON_CHIFFON_3;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N, ,3):
				return alpha | X11_LEMON_CHIFFON_3;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N,4):
				return alpha | X11_LEMON_CHIFFON_4;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N,_,4):
				return alpha | X11_LEMON_CHIFFON_4;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N, ,4):
				return alpha | X11_LEMON_CHIFFON_4;
			case _I(C,O,R,N,S,I,L,K,1):
				return alpha | X11_CORNSILK_1;
			case _I(C,O,R,N,S,I,L,K,_,1):
				return alpha | X11_CORNSILK_1;
			case _I(C,O,R,N,S,I,L,K, ,1):
				return alpha | X11_CORNSILK_1;
			case _I(C,O,R,N,S,I,L,K,2):
				return alpha | X11_CORNSILK_2;
			case _I(C,O,R,N,S,I,L,K,_,2):
				return alpha | X11_CORNSILK_2;
			case _I(C,O,R,N,S,I,L,K, ,2):
				return alpha | X11_CORNSILK_2;
			case _I(C,O,R,N,S,I,L,K,3):
				return alpha | X11_CORNSILK_3;
			case _I(C,O,R,N,S,I,L,K,_,3):
				return alpha | X11_CORNSILK_3;
			case _I(C,O,R,N,S,I,L,K, ,3):
				return alpha | X11_CORNSILK_3;
			case _I(C,O,R,N,S,I,L,K,4):
				return alpha | X11_CORNSILK_4;
			case _I(C,O,R,N,S,I,L,K,_,4):
				return alpha | X11_CORNSILK_4;
			case _I(C,O,R,N,S,I,L,K, ,4):
				return alpha | X11_CORNSILK_4;
			case _I(I,V,O,R,Y,1):
				return alpha | X11_IVORY_1;
			case _I(I,V,O,R,Y,_,1):
				return alpha | X11_IVORY_1;
			case _I(I,V,O,R,Y, ,1):
				return alpha | X11_IVORY_1;
			case _I(I,V,O,R,Y,2):
				return alpha | X11_IVORY_2;
			case _I(I,V,O,R,Y,_,2):
				return alpha | X11_IVORY_2;
			case _I(I,V,O,R,Y, ,2):
				return alpha | X11_IVORY_2;
			case _I(I,V,O,R,Y,3):
				return alpha | X11_IVORY_3;
			case _I(I,V,O,R,Y,_,3):
				return alpha | X11_IVORY_3;
			case _I(I,V,O,R,Y, ,3):
				return alpha | X11_IVORY_3;
			case _I(I,V,O,R,Y,4):
				return alpha | X11_IVORY_4;
			case _I(I,V,O,R,Y,_,4):
				return alpha | X11_IVORY_4;
			case _I(I,V,O,R,Y, ,4):
				return alpha | X11_IVORY_4;
			case _I(H,O,N,E,Y,D,E,W,1):
				return alpha | X11_HONEYDEW_1;
			case _I(H,O,N,E,Y,D,E,W,_,1):
				return alpha | X11_HONEYDEW_1;
			case _I(H,O,N,E,Y,D,E,W, ,1):
				return alpha | X11_HONEYDEW_1;
			case _I(H,O,N,E,Y,D,E,W,2):
				return alpha | X11_HONEYDEW_2;
			case _I(H,O,N,E,Y,D,E,W,_,2):
				return alpha | X11_HONEYDEW_2;
			case _I(H,O,N,E,Y,D,E,W, ,2):
				return alpha | X11_HONEYDEW_2;
			case _I(H,O,N,E,Y,D,E,W,3):
				return alpha | X11_HONEYDEW_3;
			case _I(H,O,N,E,Y,D,E,W,_,3):
				return alpha | X11_HONEYDEW_3;
			case _I(H,O,N,E,Y,D,E,W, ,3):
				return alpha | X11_HONEYDEW_3;
			case _I(H,O,N,E,Y,D,E,W,4):
				return alpha | X11_HONEYDEW_4;
			case _I(H,O,N,E,Y,D,E,W,_,4):
				return alpha | X11_HONEYDEW_4;
			case _I(H,O,N,E,Y,D,E,W, ,4):
				return alpha | X11_HONEYDEW_4;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H,1):
				return alpha | X11_LAVENDER_BLUSH_1;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H,_,1):
				return alpha | X11_LAVENDER_BLUSH_1;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H, ,1):
				return alpha | X11_LAVENDER_BLUSH_1;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H,2):
				return alpha | X11_LAVENDER_BLUSH_2;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H,_,2):
				return alpha | X11_LAVENDER_BLUSH_2;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H, ,2):
				return alpha | X11_LAVENDER_BLUSH_2;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H,3):
				return alpha | X11_LAVENDER_BLUSH_3;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H,_,3):
				return alpha | X11_LAVENDER_BLUSH_3;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H, ,3):
				return alpha | X11_LAVENDER_BLUSH_3;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H,4):
				return alpha | X11_LAVENDER_BLUSH_4;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H,_,4):
				return alpha | X11_LAVENDER_BLUSH_4;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H, ,4):
				return alpha | X11_LAVENDER_BLUSH_4;
			case _I(M,I,S,T,Y,R,O,S,E,1):
				return alpha | X11_MISTY_ROSE_1;
			case _I(M,I,S,T,Y,_,R,O,S,E,_,1):
				return alpha | X11_MISTY_ROSE_1;
			case _I(M,I,S,T,Y, ,R,O,S,E, ,1):
				return alpha | X11_MISTY_ROSE_1;
			case _I(M,I,S,T,Y,R,O,S,E,2):
				return alpha | X11_MISTY_ROSE_2;
			case _I(M,I,S,T,Y,_,R,O,S,E,_,2):
				return alpha | X11_MISTY_ROSE_2;
			case _I(M,I,S,T,Y, ,R,O,S,E, ,2):
				return alpha | X11_MISTY_ROSE_2;
			case _I(M,I,S,T,Y,R,O,S,E,3):
				return alpha | X11_MISTY_ROSE_3;
			case _I(M,I,S,T,Y,_,R,O,S,E,_,3):
				return alpha | X11_MISTY_ROSE_3;
			case _I(M,I,S,T,Y, ,R,O,S,E, ,3):
				return alpha | X11_MISTY_ROSE_3;
			case _I(M,I,S,T,Y,R,O,S,E,4):
				return alpha | X11_MISTY_ROSE_4;
			case _I(M,I,S,T,Y,_,R,O,S,E,_,4):
				return alpha | X11_MISTY_ROSE_4;
			case _I(M,I,S,T,Y, ,R,O,S,E, ,4):
				return alpha | X11_MISTY_ROSE_4;
			case _I(A,Z,U,R,E,1):
				return alpha | X11_AZURE_1;
			case _I(A,Z,U,R,E,_,1):
				return alpha | X11_AZURE_1;
			case _I(A,Z,U,R,E, ,1):
				return alpha | X11_AZURE_1;
			case _I(A,Z,U,R,E,2):
				return alpha | X11_AZURE_2;
			case _I(A,Z,U,R,E,_,2):
				return alpha | X11_AZURE_2;
			case _I(A,Z,U,R,E, ,2):
				return alpha | X11_AZURE_2;
			case _I(A,Z,U,R,E,3):
				return alpha | X11_AZURE_3;
			case _I(A,Z,U,R,E,_,3):
				return alpha | X11_AZURE_3;
			case _I(A,Z,U,R,E, ,3):
				return alpha | X11_AZURE_3;
			case _I(A,Z,U,R,E,4):
				return alpha | X11_AZURE_4;
			case _I(A,Z,U,R,E,_,4):
				return alpha | X11_AZURE_4;
			case _I(A,Z,U,R,E, ,4):
				return alpha | X11_AZURE_4;
			case _I(S,L,A,T,E,B,L,U,E,1):
				return alpha | X11_SLATE_BLUE_1;
			case _I(S,L,A,T,E,_,B,L,U,E,_,1):
				return alpha | X11_SLATE_BLUE_1;
			case _I(S,L,A,T,E, ,B,L,U,E, ,1):
				return alpha | X11_SLATE_BLUE_1;
			case _I(S,L,A,T,E,B,L,U,E,2):
				return alpha | X11_SLATE_BLUE_2;
			case _I(S,L,A,T,E,_,B,L,U,E,_,2):
				return alpha | X11_SLATE_BLUE_2;
			case _I(S,L,A,T,E, ,B,L,U,E, ,2):
				return alpha | X11_SLATE_BLUE_2;
			case _I(S,L,A,T,E,B,L,U,E,3):
				return alpha | X11_SLATE_BLUE_3;
			case _I(S,L,A,T,E,_,B,L,U,E,_,3):
				return alpha | X11_SLATE_BLUE_3;
			case _I(S,L,A,T,E, ,B,L,U,E, ,3):
				return alpha | X11_SLATE_BLUE_3;
			case _I(S,L,A,T,E,B,L,U,E,4):
				return alpha | X11_SLATE_BLUE_4;
			case _I(S,L,A,T,E,_,B,L,U,E,_,4):
				return alpha | X11_SLATE_BLUE_4;
			case _I(S,L,A,T,E, ,B,L,U,E, ,4):
				return alpha | X11_SLATE_BLUE_4;
			case _I(R,O,Y,A,L,B,L,U,E,1):
				return alpha | X11_ROYAL_BLUE_1;
			case _I(R,O,Y,A,L,_,B,L,U,E,_,1):
				return alpha | X11_ROYAL_BLUE_1;
			case _I(R,O,Y,A,L, ,B,L,U,E, ,1):
				return alpha | X11_ROYAL_BLUE_1;
			case _I(R,O,Y,A,L,B,L,U,E,2):
				return alpha | X11_ROYAL_BLUE_2;
			case _I(R,O,Y,A,L,_,B,L,U,E,_,2):
				return alpha | X11_ROYAL_BLUE_2;
			case _I(R,O,Y,A,L, ,B,L,U,E, ,2):
				return alpha | X11_ROYAL_BLUE_2;
			case _I(R,O,Y,A,L,B,L,U,E,3):
				return alpha | X11_ROYAL_BLUE_3;
			case _I(R,O,Y,A,L,_,B,L,U,E,_,3):
				return alpha | X11_ROYAL_BLUE_3;
			case _I(R,O,Y,A,L, ,B,L,U,E, ,3):
				return alpha | X11_ROYAL_BLUE_3;
			case _I(R,O,Y,A,L,B,L,U,E,4):
				return alpha | X11_ROYAL_BLUE_4;
			case _I(R,O,Y,A,L,_,B,L,U,E,_,4):
				return alpha | X11_ROYAL_BLUE_4;
			case _I(R,O,Y,A,L, ,B,L,U,E, ,4):
				return alpha | X11_ROYAL_BLUE_4;
			case _I(B,L,U,E,1):
				return alpha | X11_BLUE_1;
			case _I(B,L,U,E,_,1):
				return alpha | X11_BLUE_1;
			case _I(B,L,U,E, ,1):
				return alpha | X11_BLUE_1;
			case _I(B,L,U,E,2):
				return alpha | X11_BLUE_2;
			case _I(B,L,U,E,_,2):
				return alpha | X11_BLUE_2;
			case _I(B,L,U,E, ,2):
				return alpha | X11_BLUE_2;
			case _I(B,L,U,E,3):
				return alpha | X11_BLUE_3;
			case _I(B,L,U,E,_,3):
				return alpha | X11_BLUE_3;
			case _I(B,L,U,E, ,3):
				return alpha | X11_BLUE_3;
			case _I(B,L,U,E,4):
				return alpha | X11_BLUE_4;
			case _I(B,L,U,E,_,4):
				return alpha | X11_BLUE_4;
			case _I(B,L,U,E, ,4):
				return alpha | X11_BLUE_4;
			case _I(D,O,D,G,E,R,B,L,U,E,1):
				return alpha | X11_DODGER_BLUE_1;
			case _I(D,O,D,G,E,R,_,B,L,U,E,_,1):
				return alpha | X11_DODGER_BLUE_1;
			case _I(D,O,D,G,E,R, ,B,L,U,E, ,1):
				return alpha | X11_DODGER_BLUE_1;
			case _I(D,O,D,G,E,R,B,L,U,E,2):
				return alpha | X11_DODGER_BLUE_2;
			case _I(D,O,D,G,E,R,_,B,L,U,E,_,2):
				return alpha | X11_DODGER_BLUE_2;
			case _I(D,O,D,G,E,R, ,B,L,U,E, ,2):
				return alpha | X11_DODGER_BLUE_2;
			case _I(D,O,D,G,E,R,B,L,U,E,3):
				return alpha | X11_DODGER_BLUE_3;
			case _I(D,O,D,G,E,R,_,B,L,U,E,_,3):
				return alpha | X11_DODGER_BLUE_3;
			case _I(D,O,D,G,E,R, ,B,L,U,E, ,3):
				return alpha | X11_DODGER_BLUE_3;
			case _I(D,O,D,G,E,R,B,L,U,E,4):
				return alpha | X11_DODGER_BLUE_4;
			case _I(D,O,D,G,E,R,_,B,L,U,E,_,4):
				return alpha | X11_DODGER_BLUE_4;
			case _I(D,O,D,G,E,R, ,B,L,U,E, ,4):
				return alpha | X11_DODGER_BLUE_4;
			case _I(S,T,E,E,L,B,L,U,E,1):
				return alpha | X11_STEEL_BLUE_1;
			case _I(S,T,E,E,L,_,B,L,U,E,_,1):
				return alpha | X11_STEEL_BLUE_1;
			case _I(S,T,E,E,L, ,B,L,U,E, ,1):
				return alpha | X11_STEEL_BLUE_1;
			case _I(S,T,E,E,L,B,L,U,E,2):
				return alpha | X11_STEEL_BLUE_2;
			case _I(S,T,E,E,L,_,B,L,U,E,_,2):
				return alpha | X11_STEEL_BLUE_2;
			case _I(S,T,E,E,L, ,B,L,U,E, ,2):
				return alpha | X11_STEEL_BLUE_2;
			case _I(S,T,E,E,L,B,L,U,E,3):
				return alpha | X11_STEEL_BLUE_3;
			case _I(S,T,E,E,L,_,B,L,U,E,_,3):
				return alpha | X11_STEEL_BLUE_3;
			case _I(S,T,E,E,L, ,B,L,U,E, ,3):
				return alpha | X11_STEEL_BLUE_3;
			case _I(S,T,E,E,L,B,L,U,E,4):
				return alpha | X11_STEEL_BLUE_4;
			case _I(S,T,E,E,L,_,B,L,U,E,_,4):
				return alpha | X11_STEEL_BLUE_4;
			case _I(S,T,E,E,L, ,B,L,U,E, ,4):
				return alpha | X11_STEEL_BLUE_4;
			case _I(D,E,E,P,S,K,Y,B,L,U,E,1):
				return alpha | X11_DEEP_SKY_BLUE_1;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E,_,1):
				return alpha | X11_DEEP_SKY_BLUE_1;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E, ,1):
				return alpha | X11_DEEP_SKY_BLUE_1;
			case _I(D,E,E,P,S,K,Y,B,L,U,E,2):
				return alpha | X11_DEEP_SKY_BLUE_2;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E,_,2):
				return alpha | X11_DEEP_SKY_BLUE_2;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E, ,2):
				return alpha | X11_DEEP_SKY_BLUE_2;
			case _I(D,E,E,P,S,K,Y,B,L,U,E,3):
				return alpha | X11_DEEP_SKY_BLUE_3;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E,_,3):
				return alpha | X11_DEEP_SKY_BLUE_3;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E, ,3):
				return alpha | X11_DEEP_SKY_BLUE_3;
			case _I(D,E,E,P,S,K,Y,B,L,U,E,4):
				return alpha | X11_DEEP_SKY_BLUE_4;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E,_,4):
				return alpha | X11_DEEP_SKY_BLUE_4;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E, ,4):
				return alpha | X11_DEEP_SKY_BLUE_4;
			case _I(S,K,Y,B,L,U,E,1):
				return alpha | X11_SKY_BLUE_1;
			case _I(S,K,Y,_,B,L,U,E,_,1):
				return alpha | X11_SKY_BLUE_1;
			case _I(S,K,Y, ,B,L,U,E, ,1):
				return alpha | X11_SKY_BLUE_1;
			case _I(S,K,Y,B,L,U,E,2):
				return alpha | X11_SKY_BLUE_2;
			case _I(S,K,Y,_,B,L,U,E,_,2):
				return alpha | X11_SKY_BLUE_2;
			case _I(S,K,Y, ,B,L,U,E, ,2):
				return alpha | X11_SKY_BLUE_2;
			case _I(S,K,Y,B,L,U,E,3):
				return alpha | X11_SKY_BLUE_3;
			case _I(S,K,Y,_,B,L,U,E,_,3):
				return alpha | X11_SKY_BLUE_3;
			case _I(S,K,Y, ,B,L,U,E, ,3):
				return alpha | X11_SKY_BLUE_3;
			case _I(S,K,Y,B,L,U,E,4):
				return alpha | X11_SKY_BLUE_4;
			case _I(S,K,Y,_,B,L,U,E,_,4):
				return alpha | X11_SKY_BLUE_4;
			case _I(S,K,Y, ,B,L,U,E, ,4):
				return alpha | X11_SKY_BLUE_4;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E,1):
				return alpha | X11_LIGHT_SKY_BLUE_1;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E,_,1):
				return alpha | X11_LIGHT_SKY_BLUE_1;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E, ,1):
				return alpha | X11_LIGHT_SKY_BLUE_1;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E,2):
				return alpha | X11_LIGHT_SKY_BLUE_2;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E,_,2):
				return alpha | X11_LIGHT_SKY_BLUE_2;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E, ,2):
				return alpha | X11_LIGHT_SKY_BLUE_2;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E,3):
				return alpha | X11_LIGHT_SKY_BLUE_3;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E,_,3):
				return alpha | X11_LIGHT_SKY_BLUE_3;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E, ,3):
				return alpha | X11_LIGHT_SKY_BLUE_3;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E,4):
				return alpha | X11_LIGHT_SKY_BLUE_4;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E,_,4):
				return alpha | X11_LIGHT_SKY_BLUE_4;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E, ,4):
				return alpha | X11_LIGHT_SKY_BLUE_4;
			case _I(S,L,A,T,E,G,R,A,Y,1):
				return alpha | X11_SLATE_GRAY_1;
			case _I(S,L,A,T,E,_,G,R,A,Y,_,1):
				return alpha | X11_SLATE_GRAY_1;
			case _I(S,L,A,T,E, ,G,R,A,Y, ,1):
				return alpha | X11_SLATE_GRAY_1;
			case _I(S,L,A,T,E,G,R,A,Y,2):
				return alpha | X11_SLATE_GRAY_2;
			case _I(S,L,A,T,E,_,G,R,A,Y,_,2):
				return alpha | X11_SLATE_GRAY_2;
			case _I(S,L,A,T,E, ,G,R,A,Y, ,2):
				return alpha | X11_SLATE_GRAY_2;
			case _I(S,L,A,T,E,G,R,A,Y,3):
				return alpha | X11_SLATE_GRAY_3;
			case _I(S,L,A,T,E,_,G,R,A,Y,_,3):
				return alpha | X11_SLATE_GRAY_3;
			case _I(S,L,A,T,E, ,G,R,A,Y, ,3):
				return alpha | X11_SLATE_GRAY_3;
			case _I(S,L,A,T,E,G,R,A,Y,4):
				return alpha | X11_SLATE_GRAY_4;
			case _I(S,L,A,T,E,_,G,R,A,Y,_,4):
				return alpha | X11_SLATE_GRAY_4;
			case _I(S,L,A,T,E, ,G,R,A,Y, ,4):
				return alpha | X11_SLATE_GRAY_4;
				
			case _I(S,L,A,T,E,G,R,E,Y,1):
				return alpha | X11_SLATE_GREY_1;
			case _I(S,L,A,T,E,_,G,R,E,Y,_,1):
				return alpha | X11_SLATE_GREY_1;
			case _I(S,L,A,T,E, ,G,R,E,Y, ,1):
				return alpha | X11_SLATE_GREY_1;
			case _I(S,L,A,T,E,G,R,E,Y,2):
				return alpha | X11_SLATE_GREY_2;
			case _I(S,L,A,T,E,_,G,R,E,Y,_,2):
				return alpha | X11_SLATE_GREY_2;
			case _I(S,L,A,T,E, ,G,R,E,Y, ,2):
				return alpha | X11_SLATE_GREY_2;
			case _I(S,L,A,T,E,G,R,E,Y,3):
				return alpha | X11_SLATE_GREY_3;
			case _I(S,L,A,T,E,_,G,R,E,Y,_,3):
				return alpha | X11_SLATE_GREY_3;
			case _I(S,L,A,T,E, ,G,R,E,Y, ,3):
				return alpha | X11_SLATE_GREY_3;
			case _I(S,L,A,T,E,G,R,E,Y,4):
				return alpha | X11_SLATE_GREY_4;
			case _I(S,L,A,T,E,_,G,R,E,Y,_,4):
				return alpha | X11_SLATE_GREY_4;
			case _I(S,L,A,T,E, ,G,R,E,Y, ,4):
				return alpha | X11_SLATE_GREY_4;
				
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E,1):
				return alpha | X11_LIGHT_STEEL_BLUE_1;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E,_,1):
				return alpha | X11_LIGHT_STEEL_BLUE_1;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E, ,1):
				return alpha | X11_LIGHT_STEEL_BLUE_1;
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E,2):
				return alpha | X11_LIGHT_STEEL_BLUE_2;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E,_,2):
				return alpha | X11_LIGHT_STEEL_BLUE_2;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E, ,2):
				return alpha | X11_LIGHT_STEEL_BLUE_2;
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E,3):
				return alpha | X11_LIGHT_STEEL_BLUE_3;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E,_,3):
				return alpha | X11_LIGHT_STEEL_BLUE_3;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E, ,3):
				return alpha | X11_LIGHT_STEEL_BLUE_3;
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E,4):
				return alpha | X11_LIGHT_STEEL_BLUE_4;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E,_,4):
				return alpha | X11_LIGHT_STEEL_BLUE_4;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E, ,4):
				return alpha | X11_LIGHT_STEEL_BLUE_4;
			case _I(L,I,G,H,T,B,L,U,E,1):
				return alpha | X11_LIGHT_BLUE_1;
			case _I(L,I,G,H,T,_,B,L,U,E,_,1):
				return alpha | X11_LIGHT_BLUE_1;
			case _I(L,I,G,H,T, ,B,L,U,E, ,1):
				return alpha | X11_LIGHT_BLUE_1;
			case _I(L,I,G,H,T,B,L,U,E,2):
				return alpha | X11_LIGHT_BLUE_2;
			case _I(L,I,G,H,T,_,B,L,U,E,_,2):
				return alpha | X11_LIGHT_BLUE_2;
			case _I(L,I,G,H,T, ,B,L,U,E, ,2):
				return alpha | X11_LIGHT_BLUE_2;
			case _I(L,I,G,H,T,B,L,U,E,3):
				return alpha | X11_LIGHT_BLUE_3;
			case _I(L,I,G,H,T,_,B,L,U,E,_,3):
				return alpha | X11_LIGHT_BLUE_3;
			case _I(L,I,G,H,T, ,B,L,U,E, ,3):
				return alpha | X11_LIGHT_BLUE_3;
			case _I(L,I,G,H,T,B,L,U,E,4):
				return alpha | X11_LIGHT_BLUE_4;
			case _I(L,I,G,H,T,_,B,L,U,E,_,4):
				return alpha | X11_LIGHT_BLUE_4;
			case _I(L,I,G,H,T, ,B,L,U,E, ,4):
				return alpha | X11_LIGHT_BLUE_4;
			case _I(L,I,G,H,T,C,Y,A,N,1):
				return alpha | X11_LIGHT_CYAN_1;
			case _I(L,I,G,H,T,_,C,Y,A,N,_,1):
				return alpha | X11_LIGHT_CYAN_1;
			case _I(L,I,G,H,T, ,C,Y,A,N, ,1):
				return alpha | X11_LIGHT_CYAN_1;
			case _I(L,I,G,H,T,C,Y,A,N,2):
				return alpha | X11_LIGHT_CYAN_2;
			case _I(L,I,G,H,T,_,C,Y,A,N,_,2):
				return alpha | X11_LIGHT_CYAN_2;
			case _I(L,I,G,H,T, ,C,Y,A,N, ,2):
				return alpha | X11_LIGHT_CYAN_2;
			case _I(L,I,G,H,T,C,Y,A,N,3):
				return alpha | X11_LIGHT_CYAN_3;
			case _I(L,I,G,H,T,_,C,Y,A,N,_,3):
				return alpha | X11_LIGHT_CYAN_3;
			case _I(L,I,G,H,T, ,C,Y,A,N, ,3):
				return alpha | X11_LIGHT_CYAN_3;
			case _I(L,I,G,H,T,C,Y,A,N,4):
				return alpha | X11_LIGHT_CYAN_4;
			case _I(L,I,G,H,T,_,C,Y,A,N,_,4):
				return alpha | X11_LIGHT_CYAN_4;
			case _I(L,I,G,H,T, ,C,Y,A,N, ,4):
				return alpha | X11_LIGHT_CYAN_4;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E,1):
				return alpha | X11_PALE_TURQUOISE_1;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E,_,1):
				return alpha | X11_PALE_TURQUOISE_1;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E, ,1):
				return alpha | X11_PALE_TURQUOISE_1;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E,2):
				return alpha | X11_PALE_TURQUOISE_2;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E,_,2):
				return alpha | X11_PALE_TURQUOISE_2;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E, ,2):
				return alpha | X11_PALE_TURQUOISE_2;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E,3):
				return alpha | X11_PALE_TURQUOISE_3;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E,_,3):
				return alpha | X11_PALE_TURQUOISE_3;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E, ,3):
				return alpha | X11_PALE_TURQUOISE_3;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E,4):
				return alpha | X11_PALE_TURQUOISE_4;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E,_,4):
				return alpha | X11_PALE_TURQUOISE_4;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E, ,4):
				return alpha | X11_PALE_TURQUOISE_4;
			case _I(C,A,D,E,T,B,L,U,E,1):
				return alpha | X11_CADET_BLUE_1;
			case _I(C,A,D,E,T,_,B,L,U,E,_,1):
				return alpha | X11_CADET_BLUE_1;
			case _I(C,A,D,E,T, ,B,L,U,E, ,1):
				return alpha | X11_CADET_BLUE_1;
			case _I(C,A,D,E,T,B,L,U,E,2):
				return alpha | X11_CADET_BLUE_2;
			case _I(C,A,D,E,T,_,B,L,U,E,_,2):
				return alpha | X11_CADET_BLUE_2;
			case _I(C,A,D,E,T, ,B,L,U,E, ,2):
				return alpha | X11_CADET_BLUE_2;
			case _I(C,A,D,E,T,B,L,U,E,3):
				return alpha | X11_CADET_BLUE_3;
			case _I(C,A,D,E,T,_,B,L,U,E,_,3):
				return alpha | X11_CADET_BLUE_3;
			case _I(C,A,D,E,T, ,B,L,U,E, ,3):
				return alpha | X11_CADET_BLUE_3;
			case _I(C,A,D,E,T,B,L,U,E,4):
				return alpha | X11_CADET_BLUE_4;
			case _I(C,A,D,E,T,_,B,L,U,E,_,4):
				return alpha | X11_CADET_BLUE_4;
			case _I(C,A,D,E,T, ,B,L,U,E, ,4):
				return alpha | X11_CADET_BLUE_4;
			case _I(T,U,R,Q,U,O,I,S,E,1):
				return alpha | X11_TURQUOISE_1;
			case _I(T,U,R,Q,U,O,I,S,E,_,1):
				return alpha | X11_TURQUOISE_1;
			case _I(T,U,R,Q,U,O,I,S,E, ,1):
				return alpha | X11_TURQUOISE_1;
			case _I(T,U,R,Q,U,O,I,S,E,2):
				return alpha | X11_TURQUOISE_2;
			case _I(T,U,R,Q,U,O,I,S,E,_,2):
				return alpha | X11_TURQUOISE_2;
			case _I(T,U,R,Q,U,O,I,S,E, ,2):
				return alpha | X11_TURQUOISE_2;
			case _I(T,U,R,Q,U,O,I,S,E,3):
				return alpha | X11_TURQUOISE_3;
			case _I(T,U,R,Q,U,O,I,S,E,_,3):
				return alpha | X11_TURQUOISE_3;
			case _I(T,U,R,Q,U,O,I,S,E, ,3):
				return alpha | X11_TURQUOISE_3;
			case _I(T,U,R,Q,U,O,I,S,E,4):
				return alpha | X11_TURQUOISE_4;
			case _I(T,U,R,Q,U,O,I,S,E,_,4):
				return alpha | X11_TURQUOISE_4;
			case _I(T,U,R,Q,U,O,I,S,E, ,4):
				return alpha | X11_TURQUOISE_4;
			case _I(C,Y,A,N,1):
				return alpha | X11_CYAN_1;
			case _I(C,Y,A,N,_,1):
				return alpha | X11_CYAN_1;
			case _I(C,Y,A,N, ,1):
				return alpha | X11_CYAN_1;
			case _I(C,Y,A,N,2):
				return alpha | X11_CYAN_2;
			case _I(C,Y,A,N,_,2):
				return alpha | X11_CYAN_2;
			case _I(C,Y,A,N, ,2):
				return alpha | X11_CYAN_2;
			case _I(C,Y,A,N,3):
				return alpha | X11_CYAN_3;
			case _I(C,Y,A,N,_,3):
				return alpha | X11_CYAN_3;
			case _I(C,Y,A,N, ,3):
				return alpha | X11_CYAN_3;
			case _I(C,Y,A,N,4):
				return alpha | X11_CYAN_4;
			case _I(C,Y,A,N,_,4):
				return alpha | X11_CYAN_4;
			case _I(C,Y,A,N, ,4):
				return alpha | X11_CYAN_4;
			
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y,1):
				return alpha | X11_DARK_SLATE_GRAY_1;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y,_,1):
				return alpha | X11_DARK_SLATE_GRAY_1;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y, ,1):
				return alpha | X11_DARK_SLATE_GRAY_1;
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y,2):
				return alpha | X11_DARK_SLATE_GRAY_2;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y,_,2):
				return alpha | X11_DARK_SLATE_GRAY_2;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y, ,2):
				return alpha | X11_DARK_SLATE_GRAY_2;
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y,3):
				return alpha | X11_DARK_SLATE_GRAY_3;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y,_,3):
				return alpha | X11_DARK_SLATE_GRAY_3;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y, ,3):
				return alpha | X11_DARK_SLATE_GRAY_3;
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y,4):
				return alpha | X11_DARK_SLATE_GRAY_4;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y,_,4):
				return alpha | X11_DARK_SLATE_GRAY_4;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y, ,4):
				return alpha | X11_DARK_SLATE_GRAY_4;
			
			case _I(D,A,R,K,S,L,A,T,E,G,R,E,Y,1):
				return alpha | X11_DARK_SLATE_GREY_1;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,E,Y,_,1):
				return alpha | X11_DARK_SLATE_GREY_1;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,E,Y, ,1):
				return alpha | X11_DARK_SLATE_GREY_1;
			case _I(D,A,R,K,S,L,A,T,E,G,R,E,Y,2):
				return alpha | X11_DARK_SLATE_GREY_2;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,E,Y,_,2):
				return alpha | X11_DARK_SLATE_GREY_2;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,E,Y, ,2):
				return alpha | X11_DARK_SLATE_GREY_2;
			case _I(D,A,R,K,S,L,A,T,E,G,R,E,Y,3):
				return alpha | X11_DARK_SLATE_GREY_3;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,E,Y,_,3):
				return alpha | X11_DARK_SLATE_GREY_3;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,E,Y, ,3):
				return alpha | X11_DARK_SLATE_GREY_3;
			case _I(D,A,R,K,S,L,A,T,E,G,R,E,Y,4):
				return alpha | X11_DARK_SLATE_GREY_4;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,E,Y,_,4):
				return alpha | X11_DARK_SLATE_GREY_4;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,E,Y, ,4):
				return alpha | X11_DARK_SLATE_GREY_4;
			
			case _I(A,Q,U,A,M,A,R,I,N,E,1):
				return alpha | X11_AQUAMARINE_1;
			case _I(A,Q,U,A,M,A,R,I,N,E,_,1):
				return alpha | X11_AQUAMARINE_1;
			case _I(A,Q,U,A,M,A,R,I,N,E, ,1):
				return alpha | X11_AQUAMARINE_1;
			case _I(A,Q,U,A,M,A,R,I,N,E,2):
				return alpha | X11_AQUAMARINE_2;
			case _I(A,Q,U,A,M,A,R,I,N,E,_,2):
				return alpha | X11_AQUAMARINE_2;
			case _I(A,Q,U,A,M,A,R,I,N,E, ,2):
				return alpha | X11_AQUAMARINE_2;
			case _I(A,Q,U,A,M,A,R,I,N,E,3):
				return alpha | X11_AQUAMARINE_3;
			case _I(A,Q,U,A,M,A,R,I,N,E,_,3):
				return alpha | X11_AQUAMARINE_3;
			case _I(A,Q,U,A,M,A,R,I,N,E, ,3):
				return alpha | X11_AQUAMARINE_3;
			case _I(A,Q,U,A,M,A,R,I,N,E,4):
				return alpha | X11_AQUAMARINE_4;
			case _I(A,Q,U,A,M,A,R,I,N,E,_,4):
				return alpha | X11_AQUAMARINE_4;
			case _I(A,Q,U,A,M,A,R,I,N,E, ,4):
				return alpha | X11_AQUAMARINE_4;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N,1):
				return alpha | X11_DARK_SEA_GREEN_1;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N,_,1):
				return alpha | X11_DARK_SEA_GREEN_1;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N, ,1):
				return alpha | X11_DARK_SEA_GREEN_1;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N,2):
				return alpha | X11_DARK_SEA_GREEN_2;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N,_,2):
				return alpha | X11_DARK_SEA_GREEN_2;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N, ,2):
				return alpha | X11_DARK_SEA_GREEN_2;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N,3):
				return alpha | X11_DARK_SEA_GREEN_3;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N,_,3):
				return alpha | X11_DARK_SEA_GREEN_3;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N, ,3):
				return alpha | X11_DARK_SEA_GREEN_3;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N,4):
				return alpha | X11_DARK_SEA_GREEN_4;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N,_,4):
				return alpha | X11_DARK_SEA_GREEN_4;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N, ,4):
				return alpha | X11_DARK_SEA_GREEN_4;
			case _I(S,E,A,G,R,E,E,N,1):
				return alpha | X11_SEA_GREEN_1;
			case _I(S,E,A,_,G,R,E,E,N,_,1):
				return alpha | X11_SEA_GREEN_1;
			case _I(S,E,A, ,G,R,E,E,N, ,1):
				return alpha | X11_SEA_GREEN_1;
			case _I(S,E,A,G,R,E,E,N,2):
				return alpha | X11_SEA_GREEN_2;
			case _I(S,E,A,_,G,R,E,E,N,_,2):
				return alpha | X11_SEA_GREEN_2;
			case _I(S,E,A, ,G,R,E,E,N, ,2):
				return alpha | X11_SEA_GREEN_2;
			case _I(S,E,A,G,R,E,E,N,3):
				return alpha | X11_SEA_GREEN_3;
			case _I(S,E,A,_,G,R,E,E,N,_,3):
				return alpha | X11_SEA_GREEN_3;
			case _I(S,E,A, ,G,R,E,E,N, ,3):
				return alpha | X11_SEA_GREEN_3;
			case _I(S,E,A,G,R,E,E,N,4):
				return alpha | X11_SEA_GREEN_4;
			case _I(S,E,A,_,G,R,E,E,N,_,4):
				return alpha | X11_SEA_GREEN_4;
			case _I(S,E,A, ,G,R,E,E,N, ,4):
				return alpha | X11_SEA_GREEN_4;
			case _I(P,A,L,E,G,R,E,E,N,1):
				return alpha | X11_PALE_GREEN_1;
			case _I(P,A,L,E,_,G,R,E,E,N,_,1):
				return alpha | X11_PALE_GREEN_1;
			case _I(P,A,L,E, ,G,R,E,E,N, ,1):
				return alpha | X11_PALE_GREEN_1;
			case _I(P,A,L,E,G,R,E,E,N,2):
				return alpha | X11_PALE_GREEN_2;
			case _I(P,A,L,E,_,G,R,E,E,N,_,2):
				return alpha | X11_PALE_GREEN_2;
			case _I(P,A,L,E, ,G,R,E,E,N, ,2):
				return alpha | X11_PALE_GREEN_2;
			case _I(P,A,L,E,G,R,E,E,N,3):
				return alpha | X11_PALE_GREEN_3;
			case _I(P,A,L,E,_,G,R,E,E,N,_,3):
				return alpha | X11_PALE_GREEN_3;
			case _I(P,A,L,E, ,G,R,E,E,N, ,3):
				return alpha | X11_PALE_GREEN_3;
			case _I(P,A,L,E,G,R,E,E,N,4):
				return alpha | X11_PALE_GREEN_4;
			case _I(P,A,L,E,_,G,R,E,E,N,_,4):
				return alpha | X11_PALE_GREEN_4;
			case _I(P,A,L,E, ,G,R,E,E,N, ,4):
				return alpha | X11_PALE_GREEN_4;
			case _I(S,P,R,I,N,G,G,R,E,E,N,1):
				return alpha | X11_SPRING_GREEN_1;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N,_,1):
				return alpha | X11_SPRING_GREEN_1;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N, ,1):
				return alpha | X11_SPRING_GREEN_1;
			case _I(S,P,R,I,N,G,G,R,E,E,N,2):
				return alpha | X11_SPRING_GREEN_2;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N,_,2):
				return alpha | X11_SPRING_GREEN_2;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N, ,2):
				return alpha | X11_SPRING_GREEN_2;
			case _I(S,P,R,I,N,G,G,R,E,E,N,3):
				return alpha | X11_SPRING_GREEN_3;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N,_,3):
				return alpha | X11_SPRING_GREEN_3;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N, ,3):
				return alpha | X11_SPRING_GREEN_3;
			case _I(S,P,R,I,N,G,G,R,E,E,N,4):
				return alpha | X11_SPRING_GREEN_4;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N,_,4):
				return alpha | X11_SPRING_GREEN_4;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N, ,4):
				return alpha | X11_SPRING_GREEN_4;
			case _I(G,R,E,E,N,1):
				return alpha | X11_GREEN_1;
			case _I(G,R,E,E,N,_,1):
				return alpha | X11_GREEN_1;
			case _I(G,R,E,E,N, ,1):
				return alpha | X11_GREEN_1;
			case _I(G,R,E,E,N,2):
				return alpha | X11_GREEN_2;
			case _I(G,R,E,E,N,_,2):
				return alpha | X11_GREEN_2;
			case _I(G,R,E,E,N, ,2):
				return alpha | X11_GREEN_2;
			case _I(G,R,E,E,N,3):
				return alpha | X11_GREEN_3;
			case _I(G,R,E,E,N,_,3):
				return alpha | X11_GREEN_3;
			case _I(G,R,E,E,N, ,3):
				return alpha | X11_GREEN_3;
			case _I(G,R,E,E,N,4):
				return alpha | X11_GREEN_4;
			case _I(G,R,E,E,N,_,4):
				return alpha | X11_GREEN_4;
			case _I(G,R,E,E,N, ,4):
				return alpha | X11_GREEN_4;
			case _I(C,H,A,R,T,R,E,U,S,E,1):
				return alpha | X11_CHARTREUSE_1;
			case _I(C,H,A,R,T,R,E,U,S,E,_,1):
				return alpha | X11_CHARTREUSE_1;
			case _I(C,H,A,R,T,R,E,U,S,E, ,1):
				return alpha | X11_CHARTREUSE_1;
			case _I(C,H,A,R,T,R,E,U,S,E,2):
				return alpha | X11_CHARTREUSE_2;
			case _I(C,H,A,R,T,R,E,U,S,E,_,2):
				return alpha | X11_CHARTREUSE_2;
			case _I(C,H,A,R,T,R,E,U,S,E, ,2):
				return alpha | X11_CHARTREUSE_2;
			case _I(C,H,A,R,T,R,E,U,S,E,3):
				return alpha | X11_CHARTREUSE_3;
			case _I(C,H,A,R,T,R,E,U,S,E,_,3):
				return alpha | X11_CHARTREUSE_3;
			case _I(C,H,A,R,T,R,E,U,S,E, ,3):
				return alpha | X11_CHARTREUSE_3;
			case _I(C,H,A,R,T,R,E,U,S,E,4):
				return alpha | X11_CHARTREUSE_4;
			case _I(C,H,A,R,T,R,E,U,S,E,_,4):
				return alpha | X11_CHARTREUSE_4;
			case _I(C,H,A,R,T,R,E,U,S,E, ,4):
				return alpha | X11_CHARTREUSE_4;
			case _I(O,L,I,V,E,D,R,A,B,1):
				return alpha | X11_OLIVE_DRAB_1;
			case _I(O,L,I,V,E,_,D,R,A,B,_,1):
				return alpha | X11_OLIVE_DRAB_1;
			case _I(O,L,I,V,E, ,D,R,A,B, ,1):
				return alpha | X11_OLIVE_DRAB_1;
			case _I(O,L,I,V,E,D,R,A,B,2):
				return alpha | X11_OLIVE_DRAB_2;
			case _I(O,L,I,V,E,_,D,R,A,B,_,2):
				return alpha | X11_OLIVE_DRAB_2;
			case _I(O,L,I,V,E, ,D,R,A,B, ,2):
				return alpha | X11_OLIVE_DRAB_2;
			case _I(O,L,I,V,E,D,R,A,B,3):
				return alpha | X11_OLIVE_DRAB_3;
			case _I(O,L,I,V,E,_,D,R,A,B,_,3):
				return alpha | X11_OLIVE_DRAB_3;
			case _I(O,L,I,V,E, ,D,R,A,B, ,3):
				return alpha | X11_OLIVE_DRAB_3;
			case _I(O,L,I,V,E,D,R,A,B,4):
				return alpha | X11_OLIVE_DRAB_4;
			case _I(O,L,I,V,E,_,D,R,A,B,_,4):
				return alpha | X11_OLIVE_DRAB_4;
			case _I(O,L,I,V,E, ,D,R,A,B, ,4):
				return alpha | X11_OLIVE_DRAB_4;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N,1):
				return alpha | X11_DARK_OLIVE_GREEN_1;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N,_,1):
				return alpha | X11_DARK_OLIVE_GREEN_1;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N, ,1):
				return alpha | X11_DARK_OLIVE_GREEN_1;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N,2):
				return alpha | X11_DARK_OLIVE_GREEN_2;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N,_,2):
				return alpha | X11_DARK_OLIVE_GREEN_2;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N, ,2):
				return alpha | X11_DARK_OLIVE_GREEN_2;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N,3):
				return alpha | X11_DARK_OLIVE_GREEN_3;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N,_,3):
				return alpha | X11_DARK_OLIVE_GREEN_3;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N, ,3):
				return alpha | X11_DARK_OLIVE_GREEN_3;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N,4):
				return alpha | X11_DARK_OLIVE_GREEN_4;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N,_,4):
				return alpha | X11_DARK_OLIVE_GREEN_4;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N, ,4):
				return alpha | X11_DARK_OLIVE_GREEN_4;
			case _I(K,H,A,K,I,1):
				return alpha | X11_KHAKI_1;
			case _I(K,H,A,K,I,_,1):
				return alpha | X11_KHAKI_1;
			case _I(K,H,A,K,I, ,1):
				return alpha | X11_KHAKI_1;
			case _I(K,H,A,K,I,2):
				return alpha | X11_KHAKI_2;
			case _I(K,H,A,K,I,_,2):
				return alpha | X11_KHAKI_2;
			case _I(K,H,A,K,I, ,2):
				return alpha | X11_KHAKI_2;
			case _I(K,H,A,K,I,3):
				return alpha | X11_KHAKI_3;
			case _I(K,H,A,K,I,_,3):
				return alpha | X11_KHAKI_3;
			case _I(K,H,A,K,I, ,3):
				return alpha | X11_KHAKI_3;
			case _I(K,H,A,K,I,4):
				return alpha | X11_KHAKI_4;
			case _I(K,H,A,K,I,_,4):
				return alpha | X11_KHAKI_4;
			case _I(K,H,A,K,I, ,4):
				return alpha | X11_KHAKI_4;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,1):
				return alpha | X11_LIGHT_GOLDENROD_1;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,1):
				return alpha | X11_LIGHT_GOLDENROD_1;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,1):
				return alpha | X11_LIGHT_GOLDENROD_1;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,2):
				return alpha | X11_LIGHT_GOLDENROD_2;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,2):
				return alpha | X11_LIGHT_GOLDENROD_2;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,2):
				return alpha | X11_LIGHT_GOLDENROD_2;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,3):
				return alpha | X11_LIGHT_GOLDENROD_3;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,3):
				return alpha | X11_LIGHT_GOLDENROD_3;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,3):
				return alpha | X11_LIGHT_GOLDENROD_3;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,4):
				return alpha | X11_LIGHT_GOLDENROD_4;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,4):
				return alpha | X11_LIGHT_GOLDENROD_4;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,4):
				return alpha | X11_LIGHT_GOLDENROD_4;
			case _I(L,I,G,H,T,Y,E,L,L,O,W,1):
				return alpha | X11_LIGHT_YELLOW_1;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W,_,1):
				return alpha | X11_LIGHT_YELLOW_1;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W, ,1):
				return alpha | X11_LIGHT_YELLOW_1;
			case _I(L,I,G,H,T,Y,E,L,L,O,W,2):
				return alpha | X11_LIGHT_YELLOW_2;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W,_,2):
				return alpha | X11_LIGHT_YELLOW_2;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W, ,2):
				return alpha | X11_LIGHT_YELLOW_2;
			case _I(L,I,G,H,T,Y,E,L,L,O,W,3):
				return alpha | X11_LIGHT_YELLOW_3;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W,_,3):
				return alpha | X11_LIGHT_YELLOW_3;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W, ,3):
				return alpha | X11_LIGHT_YELLOW_3;
			case _I(L,I,G,H,T,Y,E,L,L,O,W,4):
				return alpha | X11_LIGHT_YELLOW_4;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W,_,4):
				return alpha | X11_LIGHT_YELLOW_4;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W, ,4):
				return alpha | X11_LIGHT_YELLOW_4;
			case _I(Y,E,L,L,O,W,1):
				return alpha | X11_YELLOW_1;
			case _I(Y,E,L,L,O,W,_,1):
				return alpha | X11_YELLOW_1;
			case _I(Y,E,L,L,O,W, ,1):
				return alpha | X11_YELLOW_1;
			case _I(Y,E,L,L,O,W,2):
				return alpha | X11_YELLOW_2;
			case _I(Y,E,L,L,O,W,_,2):
				return alpha | X11_YELLOW_2;
			case _I(Y,E,L,L,O,W, ,2):
				return alpha | X11_YELLOW_2;
			case _I(Y,E,L,L,O,W,3):
				return alpha | X11_YELLOW_3;
			case _I(Y,E,L,L,O,W,_,3):
				return alpha | X11_YELLOW_3;
			case _I(Y,E,L,L,O,W, ,3):
				return alpha | X11_YELLOW_3;
			case _I(Y,E,L,L,O,W,4):
				return alpha | X11_YELLOW_4;
			case _I(Y,E,L,L,O,W,_,4):
				return alpha | X11_YELLOW_4;
			case _I(Y,E,L,L,O,W, ,4):
				return alpha | X11_YELLOW_4;
			case _I(G,O,L,D,1):
				return alpha | X11_GOLD_1;
			case _I(G,O,L,D,_,1):
				return alpha | X11_GOLD_1;
			case _I(G,O,L,D, ,1):
				return alpha | X11_GOLD_1;
			case _I(G,O,L,D,2):
				return alpha | X11_GOLD_2;
			case _I(G,O,L,D,_,2):
				return alpha | X11_GOLD_2;
			case _I(G,O,L,D, ,2):
				return alpha | X11_GOLD_2;
			case _I(G,O,L,D,3):
				return alpha | X11_GOLD_3;
			case _I(G,O,L,D,_,3):
				return alpha | X11_GOLD_3;
			case _I(G,O,L,D, ,3):
				return alpha | X11_GOLD_3;
			case _I(G,O,L,D,4):
				return alpha | X11_GOLD_4;
			case _I(G,O,L,D,_,4):
				return alpha | X11_GOLD_4;
			case _I(G,O,L,D, ,4):
				return alpha | X11_GOLD_4;
			case _I(G,O,L,D,E,N,R,O,D,1):
				return alpha | X11_GOLDENROD_1;
			case _I(G,O,L,D,E,N,R,O,D,_,1):
				return alpha | X11_GOLDENROD_1;
			case _I(G,O,L,D,E,N,R,O,D, ,1):
				return alpha | X11_GOLDENROD_1;
			case _I(G,O,L,D,E,N,R,O,D,2):
				return alpha | X11_GOLDENROD_2;
			case _I(G,O,L,D,E,N,R,O,D,_,2):
				return alpha | X11_GOLDENROD_2;
			case _I(G,O,L,D,E,N,R,O,D, ,2):
				return alpha | X11_GOLDENROD_2;
			case _I(G,O,L,D,E,N,R,O,D,3):
				return alpha | X11_GOLDENROD_3;
			case _I(G,O,L,D,E,N,R,O,D,_,3):
				return alpha | X11_GOLDENROD_3;
			case _I(G,O,L,D,E,N,R,O,D, ,3):
				return alpha | X11_GOLDENROD_3;
			case _I(G,O,L,D,E,N,R,O,D,4):
				return alpha | X11_GOLDENROD_4;
			case _I(G,O,L,D,E,N,R,O,D,_,4):
				return alpha | X11_GOLDENROD_4;
			case _I(G,O,L,D,E,N,R,O,D, ,4):
				return alpha | X11_GOLDENROD_4;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D,1):
				return alpha | X11_DARK_GOLDENROD_1;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D,_,1):
				return alpha | X11_DARK_GOLDENROD_1;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D, ,1):
				return alpha | X11_DARK_GOLDENROD_1;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D,2):
				return alpha | X11_DARK_GOLDENROD_2;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D,_,2):
				return alpha | X11_DARK_GOLDENROD_2;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D, ,2):
				return alpha | X11_DARK_GOLDENROD_2;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D,3):
				return alpha | X11_DARK_GOLDENROD_3;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D,_,3):
				return alpha | X11_DARK_GOLDENROD_3;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D, ,3):
				return alpha | X11_DARK_GOLDENROD_3;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D,4):
				return alpha | X11_DARK_GOLDENROD_4;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D,_,4):
				return alpha | X11_DARK_GOLDENROD_4;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D, ,4):
				return alpha | X11_DARK_GOLDENROD_4;
			case _I(R,O,S,Y,B,R,O,W,N,1):
				return alpha | X11_ROSY_BROWN_1;
			case _I(R,O,S,Y,_,B,R,O,W,N,_,1):
				return alpha | X11_ROSY_BROWN_1;
			case _I(R,O,S,Y, ,B,R,O,W,N, ,1):
				return alpha | X11_ROSY_BROWN_1;
			case _I(R,O,S,Y,B,R,O,W,N,2):
				return alpha | X11_ROSY_BROWN_2;
			case _I(R,O,S,Y,_,B,R,O,W,N,_,2):
				return alpha | X11_ROSY_BROWN_2;
			case _I(R,O,S,Y, ,B,R,O,W,N, ,2):
				return alpha | X11_ROSY_BROWN_2;
			case _I(R,O,S,Y,B,R,O,W,N,3):
				return alpha | X11_ROSY_BROWN_3;
			case _I(R,O,S,Y,_,B,R,O,W,N,_,3):
				return alpha | X11_ROSY_BROWN_3;
			case _I(R,O,S,Y, ,B,R,O,W,N, ,3):
				return alpha | X11_ROSY_BROWN_3;
			case _I(R,O,S,Y,B,R,O,W,N,4):
				return alpha | X11_ROSY_BROWN_4;
			case _I(R,O,S,Y,_,B,R,O,W,N,_,4):
				return alpha | X11_ROSY_BROWN_4;
			case _I(R,O,S,Y, ,B,R,O,W,N, ,4):
				return alpha | X11_ROSY_BROWN_4;
			case _I(I,N,D,I,A,N,R,E,D,1):
				return alpha | X11_INDIAN_RED_1;
			case _I(I,N,D,I,A,N,_,R,E,D,_,1):
				return alpha | X11_INDIAN_RED_1;
			case _I(I,N,D,I,A,N, ,R,E,D, ,1):
				return alpha | X11_INDIAN_RED_1;
			case _I(I,N,D,I,A,N,R,E,D,2):
				return alpha | X11_INDIAN_RED_2;
			case _I(I,N,D,I,A,N,_,R,E,D,_,2):
				return alpha | X11_INDIAN_RED_2;
			case _I(I,N,D,I,A,N, ,R,E,D, ,2):
				return alpha | X11_INDIAN_RED_2;
			case _I(I,N,D,I,A,N,R,E,D,3):
				return alpha | X11_INDIAN_RED_3;
			case _I(I,N,D,I,A,N,_,R,E,D,_,3):
				return alpha | X11_INDIAN_RED_3;
			case _I(I,N,D,I,A,N, ,R,E,D, ,3):
				return alpha | X11_INDIAN_RED_3;
			case _I(I,N,D,I,A,N,R,E,D,4):
				return alpha | X11_INDIAN_RED_4;
			case _I(I,N,D,I,A,N,_,R,E,D,_,4):
				return alpha | X11_INDIAN_RED_4;
			case _I(I,N,D,I,A,N, ,R,E,D, ,4):
				return alpha | X11_INDIAN_RED_4;
			case _I(S,I,E,N,N,A,1):
				return alpha | X11_SIENNA_1;
			case _I(S,I,E,N,N,A,_,1):
				return alpha | X11_SIENNA_1;
			case _I(S,I,E,N,N,A, ,1):
				return alpha | X11_SIENNA_1;
			case _I(S,I,E,N,N,A,2):
				return alpha | X11_SIENNA_2;
			case _I(S,I,E,N,N,A,_,2):
				return alpha | X11_SIENNA_2;
			case _I(S,I,E,N,N,A, ,2):
				return alpha | X11_SIENNA_2;
			case _I(S,I,E,N,N,A,3):
				return alpha | X11_SIENNA_3;
			case _I(S,I,E,N,N,A,_,3):
				return alpha | X11_SIENNA_3;
			case _I(S,I,E,N,N,A, ,3):
				return alpha | X11_SIENNA_3;
			case _I(S,I,E,N,N,A,4):
				return alpha | X11_SIENNA_4;
			case _I(S,I,E,N,N,A,_,4):
				return alpha | X11_SIENNA_4;
			case _I(S,I,E,N,N,A, ,4):
				return alpha | X11_SIENNA_4;
			case _I(B,U,R,L,Y,W,O,O,D,1):
				return alpha | X11_BURLYWOOD_1;
			case _I(B,U,R,L,Y,W,O,O,D,_,1):
				return alpha | X11_BURLYWOOD_1;
			case _I(B,U,R,L,Y,W,O,O,D, ,1):
				return alpha | X11_BURLYWOOD_1;
			case _I(B,U,R,L,Y,W,O,O,D,2):
				return alpha | X11_BURLYWOOD_2;
			case _I(B,U,R,L,Y,W,O,O,D,_,2):
				return alpha | X11_BURLYWOOD_2;
			case _I(B,U,R,L,Y,W,O,O,D, ,2):
				return alpha | X11_BURLYWOOD_2;
			case _I(B,U,R,L,Y,W,O,O,D,3):
				return alpha | X11_BURLYWOOD_3;
			case _I(B,U,R,L,Y,W,O,O,D,_,3):
				return alpha | X11_BURLYWOOD_3;
			case _I(B,U,R,L,Y,W,O,O,D, ,3):
				return alpha | X11_BURLYWOOD_3;
			case _I(B,U,R,L,Y,W,O,O,D,4):
				return alpha | X11_BURLYWOOD_4;
			case _I(B,U,R,L,Y,W,O,O,D,_,4):
				return alpha | X11_BURLYWOOD_4;
			case _I(B,U,R,L,Y,W,O,O,D, ,4):
				return alpha | X11_BURLYWOOD_4;
			case _I(W,H,E,A,T,1):
				return alpha | X11_WHEAT_1;
			case _I(W,H,E,A,T,_,1):
				return alpha | X11_WHEAT_1;
			case _I(W,H,E,A,T, ,1):
				return alpha | X11_WHEAT_1;
			case _I(W,H,E,A,T,2):
				return alpha | X11_WHEAT_2;
			case _I(W,H,E,A,T,_,2):
				return alpha | X11_WHEAT_2;
			case _I(W,H,E,A,T, ,2):
				return alpha | X11_WHEAT_2;
			case _I(W,H,E,A,T,3):
				return alpha | X11_WHEAT_3;
			case _I(W,H,E,A,T,_,3):
				return alpha | X11_WHEAT_3;
			case _I(W,H,E,A,T, ,3):
				return alpha | X11_WHEAT_3;
			case _I(W,H,E,A,T,4):
				return alpha | X11_WHEAT_4;
			case _I(W,H,E,A,T,_,4):
				return alpha | X11_WHEAT_4;
			case _I(W,H,E,A,T, ,4):
				return alpha | X11_WHEAT_4;
			case _I(T,A,N,1):
				return alpha | X11_TAN_1;
			case _I(T,A,N,_,1):
				return alpha | X11_TAN_1;
			case _I(T,A,N, ,1):
				return alpha | X11_TAN_1;
			case _I(T,A,N,2):
				return alpha | X11_TAN_2;
			case _I(T,A,N,_,2):
				return alpha | X11_TAN_2;
			case _I(T,A,N, ,2):
				return alpha | X11_TAN_2;
			case _I(T,A,N,3):
				return alpha | X11_TAN_3;
			case _I(T,A,N,_,3):
				return alpha | X11_TAN_3;
			case _I(T,A,N, ,3):
				return alpha | X11_TAN_3;
			case _I(T,A,N,4):
				return alpha | X11_TAN_4;
			case _I(T,A,N,_,4):
				return alpha | X11_TAN_4;
			case _I(T,A,N, ,4):
				return alpha | X11_TAN_4;
			case _I(C,H,O,C,O,L,A,T,E,1):
				return alpha | X11_CHOCOLATE_1;
			case _I(C,H,O,C,O,L,A,T,E,_,1):
				return alpha | X11_CHOCOLATE_1;
			case _I(C,H,O,C,O,L,A,T,E, ,1):
				return alpha | X11_CHOCOLATE_1;
			case _I(C,H,O,C,O,L,A,T,E,2):
				return alpha | X11_CHOCOLATE_2;
			case _I(C,H,O,C,O,L,A,T,E,_,2):
				return alpha | X11_CHOCOLATE_2;
			case _I(C,H,O,C,O,L,A,T,E, ,2):
				return alpha | X11_CHOCOLATE_2;
			case _I(C,H,O,C,O,L,A,T,E,3):
				return alpha | X11_CHOCOLATE_3;
			case _I(C,H,O,C,O,L,A,T,E,_,3):
				return alpha | X11_CHOCOLATE_3;
			case _I(C,H,O,C,O,L,A,T,E, ,3):
				return alpha | X11_CHOCOLATE_3;
			case _I(C,H,O,C,O,L,A,T,E,4):
				return alpha | X11_CHOCOLATE_4;
			case _I(C,H,O,C,O,L,A,T,E,_,4):
				return alpha | X11_CHOCOLATE_4;
			case _I(C,H,O,C,O,L,A,T,E, ,4):
				return alpha | X11_CHOCOLATE_4;
			case _I(F,I,R,E,B,R,I,C,K,1):
				return alpha | X11_FIREBRICK_1;
			case _I(F,I,R,E,B,R,I,C,K,_,1):
				return alpha | X11_FIREBRICK_1;
			case _I(F,I,R,E,B,R,I,C,K, ,1):
				return alpha | X11_FIREBRICK_1;
			case _I(F,I,R,E,B,R,I,C,K,2):
				return alpha | X11_FIREBRICK_2;
			case _I(F,I,R,E,B,R,I,C,K,_,2):
				return alpha | X11_FIREBRICK_2;
			case _I(F,I,R,E,B,R,I,C,K, ,2):
				return alpha | X11_FIREBRICK_2;
			case _I(F,I,R,E,B,R,I,C,K,3):
				return alpha | X11_FIREBRICK_3;
			case _I(F,I,R,E,B,R,I,C,K,_,3):
				return alpha | X11_FIREBRICK_3;
			case _I(F,I,R,E,B,R,I,C,K, ,3):
				return alpha | X11_FIREBRICK_3;
			case _I(F,I,R,E,B,R,I,C,K,4):
				return alpha | X11_FIREBRICK_4;
			case _I(F,I,R,E,B,R,I,C,K,_,4):
				return alpha | X11_FIREBRICK_4;
			case _I(F,I,R,E,B,R,I,C,K, ,4):
				return alpha | X11_FIREBRICK_4;
			case _I(B,R,O,W,N,1):
				return alpha | X11_BROWN_1;
			case _I(B,R,O,W,N,_,1):
				return alpha | X11_BROWN_1;
			case _I(B,R,O,W,N, ,1):
				return alpha | X11_BROWN_1;
			case _I(B,R,O,W,N,2):
				return alpha | X11_BROWN_2;
			case _I(B,R,O,W,N,_,2):
				return alpha | X11_BROWN_2;
			case _I(B,R,O,W,N, ,2):
				return alpha | X11_BROWN_2;
			case _I(B,R,O,W,N,3):
				return alpha | X11_BROWN_3;
			case _I(B,R,O,W,N,_,3):
				return alpha | X11_BROWN_3;
			case _I(B,R,O,W,N, ,3):
				return alpha | X11_BROWN_3;
			case _I(B,R,O,W,N,4):
				return alpha | X11_BROWN_4;
			case _I(B,R,O,W,N,_,4):
				return alpha | X11_BROWN_4;
			case _I(B,R,O,W,N, ,4):
				return alpha | X11_BROWN_4;
			case _I(S,A,L,M,O,N,1):
				return alpha | X11_SALMON_1;
			case _I(S,A,L,M,O,N,_,1):
				return alpha | X11_SALMON_1;
			case _I(S,A,L,M,O,N, ,1):
				return alpha | X11_SALMON_1;
			case _I(S,A,L,M,O,N,2):
				return alpha | X11_SALMON_2;
			case _I(S,A,L,M,O,N,_,2):
				return alpha | X11_SALMON_2;
			case _I(S,A,L,M,O,N, ,2):
				return alpha | X11_SALMON_2;
			case _I(S,A,L,M,O,N,3):
				return alpha | X11_SALMON_3;
			case _I(S,A,L,M,O,N,_,3):
				return alpha | X11_SALMON_3;
			case _I(S,A,L,M,O,N, ,3):
				return alpha | X11_SALMON_3;
			case _I(S,A,L,M,O,N,4):
				return alpha | X11_SALMON_4;
			case _I(S,A,L,M,O,N,_,4):
				return alpha | X11_SALMON_4;
			case _I(S,A,L,M,O,N, ,4):
				return alpha | X11_SALMON_4;
			case _I(L,I,G,H,T,S,A,L,M,O,N,1):
				return alpha | X11_LIGHT_SALMON_1;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N,_,1):
				return alpha | X11_LIGHT_SALMON_1;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N, ,1):
				return alpha | X11_LIGHT_SALMON_1;
			case _I(L,I,G,H,T,S,A,L,M,O,N,2):
				return alpha | X11_LIGHT_SALMON_2;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N,_,2):
				return alpha | X11_LIGHT_SALMON_2;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N, ,2):
				return alpha | X11_LIGHT_SALMON_2;
			case _I(L,I,G,H,T,S,A,L,M,O,N,3):
				return alpha | X11_LIGHT_SALMON_3;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N,_,3):
				return alpha | X11_LIGHT_SALMON_3;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N, ,3):
				return alpha | X11_LIGHT_SALMON_3;
			case _I(L,I,G,H,T,S,A,L,M,O,N,4):
				return alpha | X11_LIGHT_SALMON_4;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N,_,4):
				return alpha | X11_LIGHT_SALMON_4;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N, ,4):
				return alpha | X11_LIGHT_SALMON_4;
			case _I(O,R,A,N,G,E,1):
				return alpha | X11_ORANGE_1;
			case _I(O,R,A,N,G,E,_,1):
				return alpha | X11_ORANGE_1;
			case _I(O,R,A,N,G,E, ,1):
				return alpha | X11_ORANGE_1;
			case _I(O,R,A,N,G,E,2):
				return alpha | X11_ORANGE_2;
			case _I(O,R,A,N,G,E,_,2):
				return alpha | X11_ORANGE_2;
			case _I(O,R,A,N,G,E, ,2):
				return alpha | X11_ORANGE_2;
			case _I(O,R,A,N,G,E,3):
				return alpha | X11_ORANGE_3;
			case _I(O,R,A,N,G,E,_,3):
				return alpha | X11_ORANGE_3;
			case _I(O,R,A,N,G,E, ,3):
				return alpha | X11_ORANGE_3;
			case _I(O,R,A,N,G,E,4):
				return alpha | X11_ORANGE_4;
			case _I(O,R,A,N,G,E,_,4):
				return alpha | X11_ORANGE_4;
			case _I(O,R,A,N,G,E, ,4):
				return alpha | X11_ORANGE_4;
			case _I(D,A,R,K,O,R,A,N,G,E,1):
				return alpha | X11_DARK_ORANGE_1;
			case _I(D,A,R,K,_,O,R,A,N,G,E,_,1):
				return alpha | X11_DARK_ORANGE_1;
			case _I(D,A,R,K, ,O,R,A,N,G,E, ,1):
				return alpha | X11_DARK_ORANGE_1;
			case _I(D,A,R,K,O,R,A,N,G,E,2):
				return alpha | X11_DARK_ORANGE_2;
			case _I(D,A,R,K,_,O,R,A,N,G,E,_,2):
				return alpha | X11_DARK_ORANGE_2;
			case _I(D,A,R,K, ,O,R,A,N,G,E, ,2):
				return alpha | X11_DARK_ORANGE_2;
			case _I(D,A,R,K,O,R,A,N,G,E,3):
				return alpha | X11_DARK_ORANGE_3;
			case _I(D,A,R,K,_,O,R,A,N,G,E,_,3):
				return alpha | X11_DARK_ORANGE_3;
			case _I(D,A,R,K, ,O,R,A,N,G,E, ,3):
				return alpha | X11_DARK_ORANGE_3;
			case _I(D,A,R,K,O,R,A,N,G,E,4):
				return alpha | X11_DARK_ORANGE_4;
			case _I(D,A,R,K,_,O,R,A,N,G,E,_,4):
				return alpha | X11_DARK_ORANGE_4;
			case _I(D,A,R,K, ,O,R,A,N,G,E, ,4):
				return alpha | X11_DARK_ORANGE_4;
			case _I(C,O,R,A,L,1):
				return alpha | X11_CORAL_1;
			case _I(C,O,R,A,L,_,1):
				return alpha | X11_CORAL_1;
			case _I(C,O,R,A,L, ,1):
				return alpha | X11_CORAL_1;
			case _I(C,O,R,A,L,2):
				return alpha | X11_CORAL_2;
			case _I(C,O,R,A,L,_,2):
				return alpha | X11_CORAL_2;
			case _I(C,O,R,A,L, ,2):
				return alpha | X11_CORAL_2;
			case _I(C,O,R,A,L,3):
				return alpha | X11_CORAL_3;
			case _I(C,O,R,A,L,_,3):
				return alpha | X11_CORAL_3;
			case _I(C,O,R,A,L, ,3):
				return alpha | X11_CORAL_3;
			case _I(C,O,R,A,L,4):
				return alpha | X11_CORAL_4;
			case _I(C,O,R,A,L,_,4):
				return alpha | X11_CORAL_4;
			case _I(C,O,R,A,L, ,4):
				return alpha | X11_CORAL_4;
			case _I(T,O,M,A,T,O,1):
				return alpha | X11_TOMATO_1;
			case _I(T,O,M,A,T,O,_,1):
				return alpha | X11_TOMATO_1;
			case _I(T,O,M,A,T,O, ,1):
				return alpha | X11_TOMATO_1;
			case _I(T,O,M,A,T,O,2):
				return alpha | X11_TOMATO_2;
			case _I(T,O,M,A,T,O,_,2):
				return alpha | X11_TOMATO_2;
			case _I(T,O,M,A,T,O, ,2):
				return alpha | X11_TOMATO_2;
			case _I(T,O,M,A,T,O,3):
				return alpha | X11_TOMATO_3;
			case _I(T,O,M,A,T,O,_,3):
				return alpha | X11_TOMATO_3;
			case _I(T,O,M,A,T,O, ,3):
				return alpha | X11_TOMATO_3;
			case _I(T,O,M,A,T,O,4):
				return alpha | X11_TOMATO_4;
			case _I(T,O,M,A,T,O,_,4):
				return alpha | X11_TOMATO_4;
			case _I(T,O,M,A,T,O, ,4):
				return alpha | X11_TOMATO_4;
			case _I(O,R,A,N,G,E,R,E,D,1):
				return alpha | X11_ORANGE_RED_1;
			case _I(O,R,A,N,G,E,_,R,E,D,_,1):
				return alpha | X11_ORANGE_RED_1;
			case _I(O,R,A,N,G,E, ,R,E,D, ,1):
				return alpha | X11_ORANGE_RED_1;
			case _I(O,R,A,N,G,E,R,E,D,2):
				return alpha | X11_ORANGE_RED_2;
			case _I(O,R,A,N,G,E,_,R,E,D,_,2):
				return alpha | X11_ORANGE_RED_2;
			case _I(O,R,A,N,G,E, ,R,E,D, ,2):
				return alpha | X11_ORANGE_RED_2;
			case _I(O,R,A,N,G,E,R,E,D,3):
				return alpha | X11_ORANGE_RED_3;
			case _I(O,R,A,N,G,E,_,R,E,D,_,3):
				return alpha | X11_ORANGE_RED_3;
			case _I(O,R,A,N,G,E, ,R,E,D, ,3):
				return alpha | X11_ORANGE_RED_3;
			case _I(O,R,A,N,G,E,R,E,D,4):
				return alpha | X11_ORANGE_RED_4;
			case _I(O,R,A,N,G,E,_,R,E,D,_,4):
				return alpha | X11_ORANGE_RED_4;
			case _I(O,R,A,N,G,E, ,R,E,D, ,4):
				return alpha | X11_ORANGE_RED_4;
			case _I(R,E,D,1):
				return alpha | X11_RED_1;
			case _I(R,E,D,_,1):
				return alpha | X11_RED_1;
			case _I(R,E,D, ,1):
				return alpha | X11_RED_1;
			case _I(R,E,D,2):
				return alpha | X11_RED_2;
			case _I(R,E,D,_,2):
				return alpha | X11_RED_2;
			case _I(R,E,D, ,2):
				return alpha | X11_RED_2;
			case _I(R,E,D,3):
				return alpha | X11_RED_3;
			case _I(R,E,D,_,3):
				return alpha | X11_RED_3;
			case _I(R,E,D, ,3):
				return alpha | X11_RED_3;
			case _I(R,E,D,4):
				return alpha | X11_RED_4;
			case _I(R,E,D,_,4):
				return alpha | X11_RED_4;
			case _I(R,E,D, ,4):
				return alpha | X11_RED_4;
			case _I(D,E,E,P,P,I,N,K,1):
				return alpha | X11_DEEP_PINK_1;
			case _I(D,E,E,P,_,P,I,N,K,_,1):
				return alpha | X11_DEEP_PINK_1;
			case _I(D,E,E,P, ,P,I,N,K, ,1):
				return alpha | X11_DEEP_PINK_1;
			case _I(D,E,E,P,P,I,N,K,2):
				return alpha | X11_DEEP_PINK_2;
			case _I(D,E,E,P,_,P,I,N,K,_,2):
				return alpha | X11_DEEP_PINK_2;
			case _I(D,E,E,P, ,P,I,N,K, ,2):
				return alpha | X11_DEEP_PINK_2;
			case _I(D,E,E,P,P,I,N,K,3):
				return alpha | X11_DEEP_PINK_3;
			case _I(D,E,E,P,_,P,I,N,K,_,3):
				return alpha | X11_DEEP_PINK_3;
			case _I(D,E,E,P, ,P,I,N,K, ,3):
				return alpha | X11_DEEP_PINK_3;
			case _I(D,E,E,P,P,I,N,K,4):
				return alpha | X11_DEEP_PINK_4;
			case _I(D,E,E,P,_,P,I,N,K,_,4):
				return alpha | X11_DEEP_PINK_4;
			case _I(D,E,E,P, ,P,I,N,K, ,4):
				return alpha | X11_DEEP_PINK_4;
			case _I(H,O,T,P,I,N,K,1):
				return alpha | X11_HOT_PINK_1;
			case _I(H,O,T,_,P,I,N,K,_,1):
				return alpha | X11_HOT_PINK_1;
			case _I(H,O,T, ,P,I,N,K, ,1):
				return alpha | X11_HOT_PINK_1;
			case _I(H,O,T,P,I,N,K,2):
				return alpha | X11_HOT_PINK_2;
			case _I(H,O,T,_,P,I,N,K,_,2):
				return alpha | X11_HOT_PINK_2;
			case _I(H,O,T, ,P,I,N,K, ,2):
				return alpha | X11_HOT_PINK_2;
			case _I(H,O,T,P,I,N,K,3):
				return alpha | X11_HOT_PINK_3;
			case _I(H,O,T,_,P,I,N,K,_,3):
				return alpha | X11_HOT_PINK_3;
			case _I(H,O,T, ,P,I,N,K, ,3):
				return alpha | X11_HOT_PINK_3;
			case _I(H,O,T,P,I,N,K,4):
				return alpha | X11_HOT_PINK_4;
			case _I(H,O,T,_,P,I,N,K,_,4):
				return alpha | X11_HOT_PINK_4;
			case _I(H,O,T, ,P,I,N,K, ,4):
				return alpha | X11_HOT_PINK_4;
			case _I(P,I,N,K,1):
				return alpha | X11_PINK_1;
			case _I(P,I,N,K,_,1):
				return alpha | X11_PINK_1;
			case _I(P,I,N,K, ,1):
				return alpha | X11_PINK_1;
			case _I(P,I,N,K,2):
				return alpha | X11_PINK_2;
			case _I(P,I,N,K,_,2):
				return alpha | X11_PINK_2;
			case _I(P,I,N,K, ,2):
				return alpha | X11_PINK_2;
			case _I(P,I,N,K,3):
				return alpha | X11_PINK_3;
			case _I(P,I,N,K,_,3):
				return alpha | X11_PINK_3;
			case _I(P,I,N,K, ,3):
				return alpha | X11_PINK_3;
			case _I(P,I,N,K,4):
				return alpha | X11_PINK_4;
			case _I(P,I,N,K,_,4):
				return alpha | X11_PINK_4;
			case _I(P,I,N,K, ,4):
				return alpha | X11_PINK_4;
			case _I(L,I,G,H,T,P,I,N,K,1):
				return alpha | X11_LIGHT_PINK_1;
			case _I(L,I,G,H,T,_,P,I,N,K,_,1):
				return alpha | X11_LIGHT_PINK_1;
			case _I(L,I,G,H,T, ,P,I,N,K, ,1):
				return alpha | X11_LIGHT_PINK_1;
			case _I(L,I,G,H,T,P,I,N,K,2):
				return alpha | X11_LIGHT_PINK_2;
			case _I(L,I,G,H,T,_,P,I,N,K,_,2):
				return alpha | X11_LIGHT_PINK_2;
			case _I(L,I,G,H,T, ,P,I,N,K, ,2):
				return alpha | X11_LIGHT_PINK_2;
			case _I(L,I,G,H,T,P,I,N,K,3):
				return alpha | X11_LIGHT_PINK_3;
			case _I(L,I,G,H,T,_,P,I,N,K,_,3):
				return alpha | X11_LIGHT_PINK_3;
			case _I(L,I,G,H,T, ,P,I,N,K, ,3):
				return alpha | X11_LIGHT_PINK_3;
			case _I(L,I,G,H,T,P,I,N,K,4):
				return alpha | X11_LIGHT_PINK_4;
			case _I(L,I,G,H,T,_,P,I,N,K,_,4):
				return alpha | X11_LIGHT_PINK_4;
			case _I(L,I,G,H,T, ,P,I,N,K, ,4):
				return alpha | X11_LIGHT_PINK_4;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D,1):
				return alpha | X11_PALE_VIOLET_RED_1;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D,_,1):
				return alpha | X11_PALE_VIOLET_RED_1;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D, ,1):
				return alpha | X11_PALE_VIOLET_RED_1;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D,2):
				return alpha | X11_PALE_VIOLET_RED_2;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D,_,2):
				return alpha | X11_PALE_VIOLET_RED_2;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D, ,2):
				return alpha | X11_PALE_VIOLET_RED_2;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D,3):
				return alpha | X11_PALE_VIOLET_RED_3;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D,_,3):
				return alpha | X11_PALE_VIOLET_RED_3;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D, ,3):
				return alpha | X11_PALE_VIOLET_RED_3;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D,4):
				return alpha | X11_PALE_VIOLET_RED_4;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D,_,4):
				return alpha | X11_PALE_VIOLET_RED_4;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D, ,4):
				return alpha | X11_PALE_VIOLET_RED_4;
			case _I(M,A,R,O,O,N,1):
				return alpha | X11_MAROON_1;
			case _I(M,A,R,O,O,N,_,1):
				return alpha | X11_MAROON_1;
			case _I(M,A,R,O,O,N, ,1):
				return alpha | X11_MAROON_1;
			case _I(M,A,R,O,O,N,2):
				return alpha | X11_MAROON_2;
			case _I(M,A,R,O,O,N,_,2):
				return alpha | X11_MAROON_2;
			case _I(M,A,R,O,O,N, ,2):
				return alpha | X11_MAROON_2;
			case _I(M,A,R,O,O,N,3):
				return alpha | X11_MAROON_3;
			case _I(M,A,R,O,O,N,_,3):
				return alpha | X11_MAROON_3;
			case _I(M,A,R,O,O,N, ,3):
				return alpha | X11_MAROON_3;
			case _I(M,A,R,O,O,N,4):
				return alpha | X11_MAROON_4;
			case _I(M,A,R,O,O,N,_,4):
				return alpha | X11_MAROON_4;
			case _I(M,A,R,O,O,N, ,4):
				return alpha | X11_MAROON_4;
			case _I(V,I,O,L,E,T,R,E,D,1):
				return alpha | X11_VIOLET_RED_1;
			case _I(V,I,O,L,E,T,_,R,E,D,_,1):
				return alpha | X11_VIOLET_RED_1;
			case _I(V,I,O,L,E,T, ,R,E,D, ,1):
				return alpha | X11_VIOLET_RED_1;
			case _I(V,I,O,L,E,T,R,E,D,2):
				return alpha | X11_VIOLET_RED_2;
			case _I(V,I,O,L,E,T,_,R,E,D,_,2):
				return alpha | X11_VIOLET_RED_2;
			case _I(V,I,O,L,E,T, ,R,E,D, ,2):
				return alpha | X11_VIOLET_RED_2;
			case _I(V,I,O,L,E,T,R,E,D,3):
				return alpha | X11_VIOLET_RED_3;
			case _I(V,I,O,L,E,T,_,R,E,D,_,3):
				return alpha | X11_VIOLET_RED_3;
			case _I(V,I,O,L,E,T, ,R,E,D, ,3):
				return alpha | X11_VIOLET_RED_3;
			case _I(V,I,O,L,E,T,R,E,D,4):
				return alpha | X11_VIOLET_RED_4;
			case _I(V,I,O,L,E,T,_,R,E,D,_,4):
				return alpha | X11_VIOLET_RED_4;
			case _I(V,I,O,L,E,T, ,R,E,D, ,4):
				return alpha | X11_VIOLET_RED_4;
			case _I(M,A,G,E,N,T,A,1):
				return alpha | X11_MAGENTA_1;
			case _I(M,A,G,E,N,T,A,_,1):
				return alpha | X11_MAGENTA_1;
			case _I(M,A,G,E,N,T,A, ,1):
				return alpha | X11_MAGENTA_1;
			case _I(M,A,G,E,N,T,A,2):
				return alpha | X11_MAGENTA_2;
			case _I(M,A,G,E,N,T,A,_,2):
				return alpha | X11_MAGENTA_2;
			case _I(M,A,G,E,N,T,A, ,2):
				return alpha | X11_MAGENTA_2;
			case _I(M,A,G,E,N,T,A,3):
				return alpha | X11_MAGENTA_3;
			case _I(M,A,G,E,N,T,A,_,3):
				return alpha | X11_MAGENTA_3;
			case _I(M,A,G,E,N,T,A, ,3):
				return alpha | X11_MAGENTA_3;
			case _I(M,A,G,E,N,T,A,4):
				return alpha | X11_MAGENTA_4;
			case _I(M,A,G,E,N,T,A,_,4):
				return alpha | X11_MAGENTA_4;
			case _I(M,A,G,E,N,T,A, ,4):
				return alpha | X11_MAGENTA_4;
			case _I(O,R,C,H,I,D,1):
				return alpha | X11_ORCHID_1;
			case _I(O,R,C,H,I,D,_,1):
				return alpha | X11_ORCHID_1;
			case _I(O,R,C,H,I,D, ,1):
				return alpha | X11_ORCHID_1;
			case _I(O,R,C,H,I,D,2):
				return alpha | X11_ORCHID_2;
			case _I(O,R,C,H,I,D,_,2):
				return alpha | X11_ORCHID_2;
			case _I(O,R,C,H,I,D, ,2):
				return alpha | X11_ORCHID_2;
			case _I(O,R,C,H,I,D,3):
				return alpha | X11_ORCHID_3;
			case _I(O,R,C,H,I,D,_,3):
				return alpha | X11_ORCHID_3;
			case _I(O,R,C,H,I,D, ,3):
				return alpha | X11_ORCHID_3;
			case _I(O,R,C,H,I,D,4):
				return alpha | X11_ORCHID_4;
			case _I(O,R,C,H,I,D,_,4):
				return alpha | X11_ORCHID_4;
			case _I(O,R,C,H,I,D, ,4):
				return alpha | X11_ORCHID_4;
			case _I(P,L,U,M,1):
				return alpha | X11_PLUM_1;
			case _I(P,L,U,M,_,1):
				return alpha | X11_PLUM_1;
			case _I(P,L,U,M, ,1):
				return alpha | X11_PLUM_1;
			case _I(P,L,U,M,2):
				return alpha | X11_PLUM_2;
			case _I(P,L,U,M,_,2):
				return alpha | X11_PLUM_2;
			case _I(P,L,U,M, ,2):
				return alpha | X11_PLUM_2;
			case _I(P,L,U,M,3):
				return alpha | X11_PLUM_3;
			case _I(P,L,U,M,_,3):
				return alpha | X11_PLUM_3;
			case _I(P,L,U,M, ,3):
				return alpha | X11_PLUM_3;
			case _I(P,L,U,M,4):
				return alpha | X11_PLUM_4;
			case _I(P,L,U,M,_,4):
				return alpha | X11_PLUM_4;
			case _I(P,L,U,M, ,4):
				return alpha | X11_PLUM_4;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D,1):
				return alpha | X11_MEDIUM_ORCHID_1;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D,_,1):
				return alpha | X11_MEDIUM_ORCHID_1;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D, ,1):
				return alpha | X11_MEDIUM_ORCHID_1;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D,2):
				return alpha | X11_MEDIUM_ORCHID_2;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D,_,2):
				return alpha | X11_MEDIUM_ORCHID_2;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D, ,2):
				return alpha | X11_MEDIUM_ORCHID_2;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D,3):
				return alpha | X11_MEDIUM_ORCHID_3;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D,_,3):
				return alpha | X11_MEDIUM_ORCHID_3;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D, ,3):
				return alpha | X11_MEDIUM_ORCHID_3;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D,4):
				return alpha | X11_MEDIUM_ORCHID_4;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D,_,4):
				return alpha | X11_MEDIUM_ORCHID_4;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D, ,4):
				return alpha | X11_MEDIUM_ORCHID_4;
			case _I(D,A,R,K,O,R,C,H,I,D,1):
				return alpha | X11_DARK_ORCHID_1;
			case _I(D,A,R,K,_,O,R,C,H,I,D,_,1):
				return alpha | X11_DARK_ORCHID_1;
			case _I(D,A,R,K, ,O,R,C,H,I,D, ,1):
				return alpha | X11_DARK_ORCHID_1;
			case _I(D,A,R,K,O,R,C,H,I,D,2):
				return alpha | X11_DARK_ORCHID_2;
			case _I(D,A,R,K,_,O,R,C,H,I,D,_,2):
				return alpha | X11_DARK_ORCHID_2;
			case _I(D,A,R,K, ,O,R,C,H,I,D, ,2):
				return alpha | X11_DARK_ORCHID_2;
			case _I(D,A,R,K,O,R,C,H,I,D,3):
				return alpha | X11_DARK_ORCHID_3;
			case _I(D,A,R,K,_,O,R,C,H,I,D,_,3):
				return alpha | X11_DARK_ORCHID_3;
			case _I(D,A,R,K, ,O,R,C,H,I,D, ,3):
				return alpha | X11_DARK_ORCHID_3;
			case _I(D,A,R,K,O,R,C,H,I,D,4):
				return alpha | X11_DARK_ORCHID_4;
			case _I(D,A,R,K,_,O,R,C,H,I,D,_,4):
				return alpha | X11_DARK_ORCHID_4;
			case _I(D,A,R,K, ,O,R,C,H,I,D, ,4):
				return alpha | X11_DARK_ORCHID_4;
			case _I(P,U,R,P,L,E,1):
				return alpha | X11_PURPLE_1;
			case _I(P,U,R,P,L,E,_,1):
				return alpha | X11_PURPLE_1;
			case _I(P,U,R,P,L,E, ,1):
				return alpha | X11_PURPLE_1;
			case _I(P,U,R,P,L,E,2):
				return alpha | X11_PURPLE_2;
			case _I(P,U,R,P,L,E,_,2):
				return alpha | X11_PURPLE_2;
			case _I(P,U,R,P,L,E, ,2):
				return alpha | X11_PURPLE_2;
			case _I(P,U,R,P,L,E,3):
				return alpha | X11_PURPLE_3;
			case _I(P,U,R,P,L,E,_,3):
				return alpha | X11_PURPLE_3;
			case _I(P,U,R,P,L,E, ,3):
				return alpha | X11_PURPLE_3;
			case _I(P,U,R,P,L,E,4):
				return alpha | X11_PURPLE_4;
			case _I(P,U,R,P,L,E,_,4):
				return alpha | X11_PURPLE_4;
			case _I(P,U,R,P,L,E, ,4):
				return alpha | X11_PURPLE_4;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E,1):
				return alpha | X11_MEDIUM_PURPLE_1;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E,_,1):
				return alpha | X11_MEDIUM_PURPLE_1;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E, ,1):
				return alpha | X11_MEDIUM_PURPLE_1;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E,2):
				return alpha | X11_MEDIUM_PURPLE_2;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E,_,2):
				return alpha | X11_MEDIUM_PURPLE_2;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E, ,2):
				return alpha | X11_MEDIUM_PURPLE_2;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E,3):
				return alpha | X11_MEDIUM_PURPLE_3;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E,_,3):
				return alpha | X11_MEDIUM_PURPLE_3;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E, ,3):
				return alpha | X11_MEDIUM_PURPLE_3;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E,4):
				return alpha | X11_MEDIUM_PURPLE_4;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E,_,4):
				return alpha | X11_MEDIUM_PURPLE_4;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E, ,4):
				return alpha | X11_MEDIUM_PURPLE_4;
			case _I(T,H,I,S,T,L,E,1):
				return alpha | X11_THISTLE_1;
			case _I(T,H,I,S,T,L,E,_,1):
				return alpha | X11_THISTLE_1;
			case _I(T,H,I,S,T,L,E, ,1):
				return alpha | X11_THISTLE_1;
			case _I(T,H,I,S,T,L,E,2):
				return alpha | X11_THISTLE_2;
			case _I(T,H,I,S,T,L,E,_,2):
				return alpha | X11_THISTLE_2;
			case _I(T,H,I,S,T,L,E, ,2):
				return alpha | X11_THISTLE_2;
			case _I(T,H,I,S,T,L,E,3):
				return alpha | X11_THISTLE_3;
			case _I(T,H,I,S,T,L,E,_,3):
				return alpha | X11_THISTLE_3;
			case _I(T,H,I,S,T,L,E, ,3):
				return alpha | X11_THISTLE_3;
			case _I(T,H,I,S,T,L,E,4):
				return alpha | X11_THISTLE_4;
			case _I(T,H,I,S,T,L,E,_,4):
				return alpha | X11_THISTLE_4;
			case _I(T,H,I,S,T,L,E, ,4):
				return alpha | X11_THISTLE_4;
			case _I(G,R,A,Y,0):
				return alpha | X11_GRAY_0;
			case _I(G,R,A,Y,_,0):
				return alpha | X11_GRAY_0;
			case _I(G,R,A,Y, ,0):
				return alpha | X11_GRAY_0;
			case _I(G,R,E,Y,0):
				return alpha | X11_GREY_0;
			case _I(G,R,E,Y,_,0):
				return alpha | X11_GREY_0;
			case _I(G,R,E,Y, ,0):
				return alpha | X11_GREY_0;
			case _I(G,R,A,Y,1):
				return alpha | X11_GRAY_1;
			case _I(G,R,A,Y,_,1):
				return alpha | X11_GRAY_1;
			case _I(G,R,A,Y, ,1):
				return alpha | X11_GRAY_1;
			case _I(G,R,E,Y,1):
				return alpha | X11_GREY_1;
			case _I(G,R,E,Y,_,1):
				return alpha | X11_GREY_1;
			case _I(G,R,E,Y, ,1):
				return alpha | X11_GREY_1;
			case _I(G,R,A,Y,2):
				return alpha | X11_GRAY_2;
			case _I(G,R,A,Y,_,2):
				return alpha | X11_GRAY_2;
			case _I(G,R,A,Y, ,2):
				return alpha | X11_GRAY_2;
			case _I(G,R,E,Y,2):
				return alpha | X11_GREY_2;
			case _I(G,R,E,Y,_,2):
				return alpha | X11_GREY_2;
			case _I(G,R,E,Y, ,2):
				return alpha | X11_GREY_2;
			case _I(G,R,A,Y,3):
				return alpha | X11_GRAY_3;
			case _I(G,R,A,Y,_,3):
				return alpha | X11_GRAY_3;
			case _I(G,R,A,Y, ,3):
				return alpha | X11_GRAY_3;
			case _I(G,R,E,Y,3):
				return alpha | X11_GREY_3;
			case _I(G,R,E,Y,_,3):
				return alpha | X11_GREY_3;
			case _I(G,R,E,Y, ,3):
				return alpha | X11_GREY_3;
			case _I(G,R,A,Y,4):
				return alpha | X11_GRAY_4;
			case _I(G,R,A,Y,_,4):
				return alpha | X11_GRAY_4;
			case _I(G,R,A,Y, ,4):
				return alpha | X11_GRAY_4;
			case _I(G,R,E,Y,4):
				return alpha | X11_GREY_4;
			case _I(G,R,E,Y,_,4):
				return alpha | X11_GREY_4;
			case _I(G,R,E,Y, ,4):
				return alpha | X11_GREY_4;
			case _I(G,R,A,Y,5):
				return alpha | X11_GRAY_5;
			case _I(G,R,A,Y,_,5):
				return alpha | X11_GRAY_5;
			case _I(G,R,A,Y, ,5):
				return alpha | X11_GRAY_5;
			case _I(G,R,E,Y,5):
				return alpha | X11_GREY_5;
			case _I(G,R,E,Y,_,5):
				return alpha | X11_GREY_5;
			case _I(G,R,E,Y, ,5):
				return alpha | X11_GREY_5;
			case _I(G,R,A,Y,6):
				return alpha | X11_GRAY_6;
			case _I(G,R,A,Y,_,6):
				return alpha | X11_GRAY_6;
			case _I(G,R,A,Y, ,6):
				return alpha | X11_GRAY_6;
			case _I(G,R,E,Y,6):
				return alpha | X11_GREY_6;
			case _I(G,R,E,Y,_,6):
				return alpha | X11_GREY_6;
			case _I(G,R,E,Y, ,6):
				return alpha | X11_GREY_6;
			case _I(G,R,A,Y,7):
				return alpha | X11_GRAY_7;
			case _I(G,R,A,Y,_,7):
				return alpha | X11_GRAY_7;
			case _I(G,R,A,Y, ,7):
				return alpha | X11_GRAY_7;
			case _I(G,R,E,Y,7):
				return alpha | X11_GREY_7;
			case _I(G,R,E,Y,_,7):
				return alpha | X11_GREY_7;
			case _I(G,R,E,Y, ,7):
				return alpha | X11_GREY_7;
			case _I(G,R,A,Y,8):
				return alpha | X11_GRAY_8;
			case _I(G,R,A,Y,_,8):
				return alpha | X11_GRAY_8;
			case _I(G,R,A,Y, ,8):
				return alpha | X11_GRAY_8;
			case _I(G,R,E,Y,8):
				return alpha | X11_GREY_8;
			case _I(G,R,E,Y,_,8):
				return alpha | X11_GREY_8;
			case _I(G,R,E,Y, ,8):
				return alpha | X11_GREY_8;
			case _I(G,R,A,Y,9):
				return alpha | X11_GRAY_9;
			case _I(G,R,A,Y,_,9):
				return alpha | X11_GRAY_9;
			case _I(G,R,A,Y, ,9):
				return alpha | X11_GRAY_9;
			case _I(G,R,E,Y,9):
				return alpha | X11_GREY_9;
			case _I(G,R,E,Y,_,9):
				return alpha | X11_GREY_9;
			case _I(G,R,E,Y, ,9):
				return alpha | X11_GREY_9;
			case _I(G,R,A,Y,1,0):
				return alpha | X11_GRAY_10;
			case _I(G,R,A,Y,_,1,0):
				return alpha | X11_GRAY_10;
			case _I(G,R,A,Y, ,1,0):
				return alpha | X11_GRAY_10;
			case _I(G,R,E,Y,1,0):
				return alpha | X11_GREY_10;
			case _I(G,R,E,Y,_,1,0):
				return alpha | X11_GREY_10;
			case _I(G,R,E,Y, ,1,0):
				return alpha | X11_GREY_10;
			case _I(G,R,A,Y,1,1):
				return alpha | X11_GRAY_11;
			case _I(G,R,A,Y,_,1,1):
				return alpha | X11_GRAY_11;
			case _I(G,R,A,Y, ,1,1):
				return alpha | X11_GRAY_11;
			case _I(G,R,E,Y,1,1):
				return alpha | X11_GREY_11;
			case _I(G,R,E,Y,_,1,1):
				return alpha | X11_GREY_11;
			case _I(G,R,E,Y, ,1,1):
				return alpha | X11_GREY_11;
			case _I(G,R,A,Y,1,2):
				return alpha | X11_GRAY_12;
			case _I(G,R,A,Y,_,1,2):
				return alpha | X11_GRAY_12;
			case _I(G,R,A,Y, ,1,2):
				return alpha | X11_GRAY_12;
			case _I(G,R,E,Y,1,2):
				return alpha | X11_GREY_12;
			case _I(G,R,E,Y,_,1,2):
				return alpha | X11_GREY_12;
			case _I(G,R,E,Y, ,1,2):
				return alpha | X11_GREY_12;
			case _I(G,R,A,Y,1,3):
				return alpha | X11_GRAY_13;
			case _I(G,R,A,Y,_,1,3):
				return alpha | X11_GRAY_13;
			case _I(G,R,A,Y, ,1,3):
				return alpha | X11_GRAY_13;
			case _I(G,R,E,Y,1,3):
				return alpha | X11_GREY_13;
			case _I(G,R,E,Y,_,1,3):
				return alpha | X11_GREY_13;
			case _I(G,R,E,Y, ,1,3):
				return alpha | X11_GREY_13;
			case _I(G,R,A,Y,1,4):
				return alpha | X11_GRAY_14;
			case _I(G,R,A,Y,_,1,4):
				return alpha | X11_GRAY_14;
			case _I(G,R,A,Y, ,1,4):
				return alpha | X11_GRAY_14;
			case _I(G,R,E,Y,1,4):
				return alpha | X11_GREY_14;
			case _I(G,R,E,Y,_,1,4):
				return alpha | X11_GREY_14;
			case _I(G,R,E,Y, ,1,4):
				return alpha | X11_GREY_14;
			case _I(G,R,A,Y,1,5):
				return alpha | X11_GRAY_15;
			case _I(G,R,A,Y,_,1,5):
				return alpha | X11_GRAY_15;
			case _I(G,R,A,Y, ,1,5):
				return alpha | X11_GRAY_15;
			case _I(G,R,E,Y,1,5):
				return alpha | X11_GREY_15;
			case _I(G,R,E,Y,_,1,5):
				return alpha | X11_GREY_15;
			case _I(G,R,E,Y, ,1,5):
				return alpha | X11_GREY_15;
			case _I(G,R,A,Y,1,6):
				return alpha | X11_GRAY_16;
			case _I(G,R,A,Y,_,1,6):
				return alpha | X11_GRAY_16;
			case _I(G,R,A,Y, ,1,6):
				return alpha | X11_GRAY_16;
			case _I(G,R,E,Y,1,6):
				return alpha | X11_GREY_16;
			case _I(G,R,E,Y,_,1,6):
				return alpha | X11_GREY_16;
			case _I(G,R,E,Y, ,1,6):
				return alpha | X11_GREY_16;
			case _I(G,R,A,Y,1,7):
				return alpha | X11_GRAY_17;
			case _I(G,R,A,Y,_,1,7):
				return alpha | X11_GRAY_17;
			case _I(G,R,A,Y, ,1,7):
				return alpha | X11_GRAY_17;
			case _I(G,R,E,Y,1,7):
				return alpha | X11_GREY_17;
			case _I(G,R,E,Y,_,1,7):
				return alpha | X11_GREY_17;
			case _I(G,R,E,Y, ,1,7):
				return alpha | X11_GREY_17;
			case _I(G,R,A,Y,1,8):
				return alpha | X11_GRAY_18;
			case _I(G,R,A,Y,_,1,8):
				return alpha | X11_GRAY_18;
			case _I(G,R,A,Y, ,1,8):
				return alpha | X11_GRAY_18;
			case _I(G,R,E,Y,1,8):
				return alpha | X11_GREY_18;
			case _I(G,R,E,Y,_,1,8):
				return alpha | X11_GREY_18;
			case _I(G,R,E,Y, ,1,8):
				return alpha | X11_GREY_18;
			case _I(G,R,A,Y,1,9):
				return alpha | X11_GRAY_19;
			case _I(G,R,A,Y,_,1,9):
				return alpha | X11_GRAY_19;
			case _I(G,R,A,Y, ,1,9):
				return alpha | X11_GRAY_19;
			case _I(G,R,E,Y,1,9):
				return alpha | X11_GREY_19;
			case _I(G,R,E,Y,_,1,9):
				return alpha | X11_GREY_19;
			case _I(G,R,E,Y, ,1,9):
				return alpha | X11_GREY_19;
			case _I(G,R,A,Y,2,0):
				return alpha | X11_GRAY_20;
			case _I(G,R,A,Y,_,2,0):
				return alpha | X11_GRAY_20;
			case _I(G,R,A,Y, ,2,0):
				return alpha | X11_GRAY_20;
			case _I(G,R,E,Y,2,0):
				return alpha | X11_GREY_20;
			case _I(G,R,E,Y,_,2,0):
				return alpha | X11_GREY_20;
			case _I(G,R,E,Y, ,2,0):
				return alpha | X11_GREY_20;
			case _I(G,R,A,Y,2,1):
				return alpha | X11_GRAY_21;
			case _I(G,R,A,Y,_,2,1):
				return alpha | X11_GRAY_21;
			case _I(G,R,A,Y, ,2,1):
				return alpha | X11_GRAY_21;
			case _I(G,R,E,Y,2,1):
				return alpha | X11_GREY_21;
			case _I(G,R,E,Y,_,2,1):
				return alpha | X11_GREY_21;
			case _I(G,R,E,Y, ,2,1):
				return alpha | X11_GREY_21;
			case _I(G,R,A,Y,2,2):
				return alpha | X11_GRAY_22;
			case _I(G,R,A,Y,_,2,2):
				return alpha | X11_GRAY_22;
			case _I(G,R,A,Y, ,2,2):
				return alpha | X11_GRAY_22;
			case _I(G,R,E,Y,2,2):
				return alpha | X11_GREY_22;
			case _I(G,R,E,Y,_,2,2):
				return alpha | X11_GREY_22;
			case _I(G,R,E,Y, ,2,2):
				return alpha | X11_GREY_22;
			case _I(G,R,A,Y,2,3):
				return alpha | X11_GRAY_23;
			case _I(G,R,A,Y,_,2,3):
				return alpha | X11_GRAY_23;
			case _I(G,R,A,Y, ,2,3):
				return alpha | X11_GRAY_23;
			case _I(G,R,E,Y,2,3):
				return alpha | X11_GREY_23;
			case _I(G,R,E,Y,_,2,3):
				return alpha | X11_GREY_23;
			case _I(G,R,E,Y, ,2,3):
				return alpha | X11_GREY_23;
			case _I(G,R,A,Y,2,4):
				return alpha | X11_GRAY_24;
			case _I(G,R,A,Y,_,2,4):
				return alpha | X11_GRAY_24;
			case _I(G,R,A,Y, ,2,4):
				return alpha | X11_GRAY_24;
			case _I(G,R,E,Y,2,4):
				return alpha | X11_GREY_24;
			case _I(G,R,E,Y,_,2,4):
				return alpha | X11_GREY_24;
			case _I(G,R,E,Y, ,2,4):
				return alpha | X11_GREY_24;
			case _I(G,R,A,Y,2,5):
				return alpha | X11_GRAY_25;
			case _I(G,R,A,Y,_,2,5):
				return alpha | X11_GRAY_25;
			case _I(G,R,A,Y, ,2,5):
				return alpha | X11_GRAY_25;
			case _I(G,R,E,Y,2,5):
				return alpha | X11_GREY_25;
			case _I(G,R,E,Y,_,2,5):
				return alpha | X11_GREY_25;
			case _I(G,R,E,Y, ,2,5):
				return alpha | X11_GREY_25;
			case _I(G,R,A,Y,2,6):
				return alpha | X11_GRAY_26;
			case _I(G,R,A,Y,_,2,6):
				return alpha | X11_GRAY_26;
			case _I(G,R,A,Y, ,2,6):
				return alpha | X11_GRAY_26;
			case _I(G,R,E,Y,2,6):
				return alpha | X11_GREY_26;
			case _I(G,R,E,Y,_,2,6):
				return alpha | X11_GREY_26;
			case _I(G,R,E,Y, ,2,6):
				return alpha | X11_GREY_26;
			case _I(G,R,A,Y,2,7):
				return alpha | X11_GRAY_27;
			case _I(G,R,A,Y,_,2,7):
				return alpha | X11_GRAY_27;
			case _I(G,R,A,Y, ,2,7):
				return alpha | X11_GRAY_27;
			case _I(G,R,E,Y,2,7):
				return alpha | X11_GREY_27;
			case _I(G,R,E,Y,_,2,7):
				return alpha | X11_GREY_27;
			case _I(G,R,E,Y, ,2,7):
				return alpha | X11_GREY_27;
			case _I(G,R,A,Y,2,8):
				return alpha | X11_GRAY_28;
			case _I(G,R,A,Y,_,2,8):
				return alpha | X11_GRAY_28;
			case _I(G,R,A,Y, ,2,8):
				return alpha | X11_GRAY_28;
			case _I(G,R,E,Y,2,8):
				return alpha | X11_GREY_28;
			case _I(G,R,E,Y,_,2,8):
				return alpha | X11_GREY_28;
			case _I(G,R,E,Y, ,2,8):
				return alpha | X11_GREY_28;
			case _I(G,R,A,Y,2,9):
				return alpha | X11_GRAY_29;
			case _I(G,R,A,Y,_,2,9):
				return alpha | X11_GRAY_29;
			case _I(G,R,A,Y, ,2,9):
				return alpha | X11_GRAY_29;
			case _I(G,R,E,Y,2,9):
				return alpha | X11_GREY_29;
			case _I(G,R,E,Y,_,2,9):
				return alpha | X11_GREY_29;
			case _I(G,R,E,Y, ,2,9):
				return alpha | X11_GREY_29;
			case _I(G,R,A,Y,3,0):
				return alpha | X11_GRAY_30;
			case _I(G,R,A,Y,_,3,0):
				return alpha | X11_GRAY_30;
			case _I(G,R,A,Y, ,3,0):
				return alpha | X11_GRAY_30;
			case _I(G,R,E,Y,3,0):
				return alpha | X11_GREY_30;
			case _I(G,R,E,Y,_,3,0):
				return alpha | X11_GREY_30;
			case _I(G,R,E,Y, ,3,0):
				return alpha | X11_GREY_30;
			case _I(G,R,A,Y,3,1):
				return alpha | X11_GRAY_31;
			case _I(G,R,A,Y,_,3,1):
				return alpha | X11_GRAY_31;
			case _I(G,R,A,Y, ,3,1):
				return alpha | X11_GRAY_31;
			case _I(G,R,E,Y,3,1):
				return alpha | X11_GREY_31;
			case _I(G,R,E,Y,_,3,1):
				return alpha | X11_GREY_31;
			case _I(G,R,E,Y, ,3,1):
				return alpha | X11_GREY_31;
			case _I(G,R,A,Y,3,2):
				return alpha | X11_GRAY_32;
			case _I(G,R,A,Y,_,3,2):
				return alpha | X11_GRAY_32;
			case _I(G,R,A,Y, ,3,2):
				return alpha | X11_GRAY_32;
			case _I(G,R,E,Y,3,2):
				return alpha | X11_GREY_32;
			case _I(G,R,E,Y,_,3,2):
				return alpha | X11_GREY_32;
			case _I(G,R,E,Y, ,3,2):
				return alpha | X11_GREY_32;
			case _I(G,R,A,Y,3,3):
				return alpha | X11_GRAY_33;
			case _I(G,R,A,Y,_,3,3):
				return alpha | X11_GRAY_33;
			case _I(G,R,A,Y, ,3,3):
				return alpha | X11_GRAY_33;
			case _I(G,R,E,Y,3,3):
				return alpha | X11_GREY_33;
			case _I(G,R,E,Y,_,3,3):
				return alpha | X11_GREY_33;
			case _I(G,R,E,Y, ,3,3):
				return alpha | X11_GREY_33;
			case _I(G,R,A,Y,3,4):
				return alpha | X11_GRAY_34;
			case _I(G,R,A,Y,_,3,4):
				return alpha | X11_GRAY_34;
			case _I(G,R,A,Y, ,3,4):
				return alpha | X11_GRAY_34;
			case _I(G,R,E,Y,3,4):
				return alpha | X11_GREY_34;
			case _I(G,R,E,Y,_,3,4):
				return alpha | X11_GREY_34;
			case _I(G,R,E,Y, ,3,4):
				return alpha | X11_GREY_34;
			case _I(G,R,A,Y,3,5):
				return alpha | X11_GRAY_35;
			case _I(G,R,A,Y,_,3,5):
				return alpha | X11_GRAY_35;
			case _I(G,R,A,Y, ,3,5):
				return alpha | X11_GRAY_35;
			case _I(G,R,E,Y,3,5):
				return alpha | X11_GREY_35;
			case _I(G,R,E,Y,_,3,5):
				return alpha | X11_GREY_35;
			case _I(G,R,E,Y, ,3,5):
				return alpha | X11_GREY_35;
			case _I(G,R,A,Y,3,6):
				return alpha | X11_GRAY_36;
			case _I(G,R,A,Y,_,3,6):
				return alpha | X11_GRAY_36;
			case _I(G,R,A,Y, ,3,6):
				return alpha | X11_GRAY_36;
			case _I(G,R,E,Y,3,6):
				return alpha | X11_GREY_36;
			case _I(G,R,E,Y,_,3,6):
				return alpha | X11_GREY_36;
			case _I(G,R,E,Y, ,3,6):
				return alpha | X11_GREY_36;
			case _I(G,R,A,Y,3,7):
				return alpha | X11_GRAY_37;
			case _I(G,R,A,Y,_,3,7):
				return alpha | X11_GRAY_37;
			case _I(G,R,A,Y, ,3,7):
				return alpha | X11_GRAY_37;
			case _I(G,R,E,Y,3,7):
				return alpha | X11_GREY_37;
			case _I(G,R,E,Y,_,3,7):
				return alpha | X11_GREY_37;
			case _I(G,R,E,Y, ,3,7):
				return alpha | X11_GREY_37;
			case _I(G,R,A,Y,3,8):
				return alpha | X11_GRAY_38;
			case _I(G,R,A,Y,_,3,8):
				return alpha | X11_GRAY_38;
			case _I(G,R,A,Y, ,3,8):
				return alpha | X11_GRAY_38;
			case _I(G,R,E,Y,3,8):
				return alpha | X11_GREY_38;
			case _I(G,R,E,Y,_,3,8):
				return alpha | X11_GREY_38;
			case _I(G,R,E,Y, ,3,8):
				return alpha | X11_GREY_38;
			case _I(G,R,A,Y,3,9):
				return alpha | X11_GRAY_39;
			case _I(G,R,A,Y,_,3,9):
				return alpha | X11_GRAY_39;
			case _I(G,R,A,Y, ,3,9):
				return alpha | X11_GRAY_39;
			case _I(G,R,E,Y,3,9):
				return alpha | X11_GREY_39;
			case _I(G,R,E,Y,_,3,9):
				return alpha | X11_GREY_39;
			case _I(G,R,E,Y, ,3,9):
				return alpha | X11_GREY_39;
			case _I(G,R,A,Y,4,0):
				return alpha | X11_GRAY_40;
			case _I(G,R,A,Y,_,4,0):
				return alpha | X11_GRAY_40;
			case _I(G,R,A,Y, ,4,0):
				return alpha | X11_GRAY_40;
			case _I(G,R,E,Y,4,0):
				return alpha | X11_GREY_40;
			case _I(G,R,E,Y,_,4,0):
				return alpha | X11_GREY_40;
			case _I(G,R,E,Y, ,4,0):
				return alpha | X11_GREY_40;
			case _I(G,R,A,Y,4,1):
				return alpha | X11_GRAY_41;
			case _I(G,R,A,Y,_,4,1):
				return alpha | X11_GRAY_41;
			case _I(G,R,A,Y, ,4,1):
				return alpha | X11_GRAY_41;
			case _I(G,R,E,Y,4,1):
				return alpha | X11_GREY_41;
			case _I(G,R,E,Y,_,4,1):
				return alpha | X11_GREY_41;
			case _I(G,R,E,Y, ,4,1):
				return alpha | X11_GREY_41;
			case _I(G,R,A,Y,4,2):
				return alpha | X11_GRAY_42;
			case _I(G,R,A,Y,_,4,2):
				return alpha | X11_GRAY_42;
			case _I(G,R,A,Y, ,4,2):
				return alpha | X11_GRAY_42;
			case _I(G,R,E,Y,4,2):
				return alpha | X11_GREY_42;
			case _I(G,R,E,Y,_,4,2):
				return alpha | X11_GREY_42;
			case _I(G,R,E,Y, ,4,2):
				return alpha | X11_GREY_42;
			case _I(G,R,A,Y,4,3):
				return alpha | X11_GRAY_43;
			case _I(G,R,A,Y,_,4,3):
				return alpha | X11_GRAY_43;
			case _I(G,R,A,Y, ,4,3):
				return alpha | X11_GRAY_43;
			case _I(G,R,E,Y,4,3):
				return alpha | X11_GREY_43;
			case _I(G,R,E,Y,_,4,3):
				return alpha | X11_GREY_43;
			case _I(G,R,E,Y, ,4,3):
				return alpha | X11_GREY_43;
			case _I(G,R,A,Y,4,4):
				return alpha | X11_GRAY_44;
			case _I(G,R,A,Y,_,4,4):
				return alpha | X11_GRAY_44;
			case _I(G,R,A,Y, ,4,4):
				return alpha | X11_GRAY_44;
			case _I(G,R,E,Y,4,4):
				return alpha | X11_GREY_44;
			case _I(G,R,E,Y,_,4,4):
				return alpha | X11_GREY_44;
			case _I(G,R,E,Y, ,4,4):
				return alpha | X11_GREY_44;
			case _I(G,R,A,Y,4,5):
				return alpha | X11_GRAY_45;
			case _I(G,R,A,Y,_,4,5):
				return alpha | X11_GRAY_45;
			case _I(G,R,A,Y, ,4,5):
				return alpha | X11_GRAY_45;
			case _I(G,R,E,Y,4,5):
				return alpha | X11_GREY_45;
			case _I(G,R,E,Y,_,4,5):
				return alpha | X11_GREY_45;
			case _I(G,R,E,Y, ,4,5):
				return alpha | X11_GREY_45;
			case _I(G,R,A,Y,4,6):
				return alpha | X11_GRAY_46;
			case _I(G,R,A,Y,_,4,6):
				return alpha | X11_GRAY_46;
			case _I(G,R,A,Y, ,4,6):
				return alpha | X11_GRAY_46;
			case _I(G,R,E,Y,4,6):
				return alpha | X11_GREY_46;
			case _I(G,R,E,Y,_,4,6):
				return alpha | X11_GREY_46;
			case _I(G,R,E,Y, ,4,6):
				return alpha | X11_GREY_46;
			case _I(G,R,A,Y,4,7):
				return alpha | X11_GRAY_47;
			case _I(G,R,A,Y,_,4,7):
				return alpha | X11_GRAY_47;
			case _I(G,R,A,Y, ,4,7):
				return alpha | X11_GRAY_47;
			case _I(G,R,E,Y,4,7):
				return alpha | X11_GREY_47;
			case _I(G,R,E,Y,_,4,7):
				return alpha | X11_GREY_47;
			case _I(G,R,E,Y, ,4,7):
				return alpha | X11_GREY_47;
			case _I(G,R,A,Y,4,8):
				return alpha | X11_GRAY_48;
			case _I(G,R,A,Y,_,4,8):
				return alpha | X11_GRAY_48;
			case _I(G,R,A,Y, ,4,8):
				return alpha | X11_GRAY_48;
			case _I(G,R,E,Y,4,8):
				return alpha | X11_GREY_48;
			case _I(G,R,E,Y,_,4,8):
				return alpha | X11_GREY_48;
			case _I(G,R,E,Y, ,4,8):
				return alpha | X11_GREY_48;
			case _I(G,R,A,Y,4,9):
				return alpha | X11_GRAY_49;
			case _I(G,R,A,Y,_,4,9):
				return alpha | X11_GRAY_49;
			case _I(G,R,A,Y, ,4,9):
				return alpha | X11_GRAY_49;
			case _I(G,R,E,Y,4,9):
				return alpha | X11_GREY_49;
			case _I(G,R,E,Y,_,4,9):
				return alpha | X11_GREY_49;
			case _I(G,R,E,Y, ,4,9):
				return alpha | X11_GREY_49;
			case _I(G,R,A,Y,5,0):
				return alpha | X11_GRAY_50;
			case _I(G,R,A,Y,_,5,0):
				return alpha | X11_GRAY_50;
			case _I(G,R,A,Y, ,5,0):
				return alpha | X11_GRAY_50;
			case _I(G,R,E,Y,5,0):
				return alpha | X11_GREY_50;
			case _I(G,R,E,Y,_,5,0):
				return alpha | X11_GREY_50;
			case _I(G,R,E,Y, ,5,0):
				return alpha | X11_GREY_50;
			case _I(G,R,A,Y,5,1):
				return alpha | X11_GRAY_51;
			case _I(G,R,A,Y,_,5,1):
				return alpha | X11_GRAY_51;
			case _I(G,R,A,Y, ,5,1):
				return alpha | X11_GRAY_51;
			case _I(G,R,E,Y,5,1):
				return alpha | X11_GREY_51;
			case _I(G,R,E,Y,_,5,1):
				return alpha | X11_GREY_51;
			case _I(G,R,E,Y, ,5,1):
				return alpha | X11_GREY_51;
			case _I(G,R,A,Y,5,2):
				return alpha | X11_GRAY_52;
			case _I(G,R,A,Y,_,5,2):
				return alpha | X11_GRAY_52;
			case _I(G,R,A,Y, ,5,2):
				return alpha | X11_GRAY_52;
			case _I(G,R,E,Y,5,2):
				return alpha | X11_GREY_52;
			case _I(G,R,E,Y,_,5,2):
				return alpha | X11_GREY_52;
			case _I(G,R,E,Y, ,5,2):
				return alpha | X11_GREY_52;
			case _I(G,R,A,Y,5,3):
				return alpha | X11_GRAY_53;
			case _I(G,R,A,Y,_,5,3):
				return alpha | X11_GRAY_53;
			case _I(G,R,A,Y, ,5,3):
				return alpha | X11_GRAY_53;
			case _I(G,R,E,Y,5,3):
				return alpha | X11_GREY_53;
			case _I(G,R,E,Y,_,5,3):
				return alpha | X11_GREY_53;
			case _I(G,R,E,Y, ,5,3):
				return alpha | X11_GREY_53;
			case _I(G,R,A,Y,5,4):
				return alpha | X11_GRAY_54;
			case _I(G,R,A,Y,_,5,4):
				return alpha | X11_GRAY_54;
			case _I(G,R,A,Y, ,5,4):
				return alpha | X11_GRAY_54;
			case _I(G,R,E,Y,5,4):
				return alpha | X11_GREY_54;
			case _I(G,R,E,Y,_,5,4):
				return alpha | X11_GREY_54;
			case _I(G,R,E,Y, ,5,4):
				return alpha | X11_GREY_54;
			case _I(G,R,A,Y,5,5):
				return alpha | X11_GRAY_55;
			case _I(G,R,A,Y,_,5,5):
				return alpha | X11_GRAY_55;
			case _I(G,R,A,Y, ,5,5):
				return alpha | X11_GRAY_55;
			case _I(G,R,E,Y,5,5):
				return alpha | X11_GREY_55;
			case _I(G,R,E,Y,_,5,5):
				return alpha | X11_GREY_55;
			case _I(G,R,E,Y, ,5,5):
				return alpha | X11_GREY_55;
			case _I(G,R,A,Y,5,6):
				return alpha | X11_GRAY_56;
			case _I(G,R,A,Y,_,5,6):
				return alpha | X11_GRAY_56;
			case _I(G,R,A,Y, ,5,6):
				return alpha | X11_GRAY_56;
			case _I(G,R,E,Y,5,6):
				return alpha | X11_GREY_56;
			case _I(G,R,E,Y,_,5,6):
				return alpha | X11_GREY_56;
			case _I(G,R,E,Y, ,5,6):
				return alpha | X11_GREY_56;
			case _I(G,R,A,Y,5,7):
				return alpha | X11_GRAY_57;
			case _I(G,R,A,Y,_,5,7):
				return alpha | X11_GRAY_57;
			case _I(G,R,A,Y, ,5,7):
				return alpha | X11_GRAY_57;
			case _I(G,R,E,Y,5,7):
				return alpha | X11_GREY_57;
			case _I(G,R,E,Y,_,5,7):
				return alpha | X11_GREY_57;
			case _I(G,R,E,Y, ,5,7):
				return alpha | X11_GREY_57;
			case _I(G,R,A,Y,5,8):
				return alpha | X11_GRAY_58;
			case _I(G,R,A,Y,_,5,8):
				return alpha | X11_GRAY_58;
			case _I(G,R,A,Y, ,5,8):
				return alpha | X11_GRAY_58;
			case _I(G,R,E,Y,5,8):
				return alpha | X11_GREY_58;
			case _I(G,R,E,Y,_,5,8):
				return alpha | X11_GREY_58;
			case _I(G,R,E,Y, ,5,8):
				return alpha | X11_GREY_58;
			case _I(G,R,A,Y,5,9):
				return alpha | X11_GRAY_59;
			case _I(G,R,A,Y,_,5,9):
				return alpha | X11_GRAY_59;
			case _I(G,R,A,Y, ,5,9):
				return alpha | X11_GRAY_59;
			case _I(G,R,E,Y,5,9):
				return alpha | X11_GREY_59;
			case _I(G,R,E,Y,_,5,9):
				return alpha | X11_GREY_59;
			case _I(G,R,E,Y, ,5,9):
				return alpha | X11_GREY_59;
			case _I(G,R,A,Y,6,0):
				return alpha | X11_GRAY_60;
			case _I(G,R,A,Y,_,6,0):
				return alpha | X11_GRAY_60;
			case _I(G,R,A,Y, ,6,0):
				return alpha | X11_GRAY_60;
			case _I(G,R,E,Y,6,0):
				return alpha | X11_GREY_60;
			case _I(G,R,E,Y,_,6,0):
				return alpha | X11_GREY_60;
			case _I(G,R,E,Y, ,6,0):
				return alpha | X11_GREY_60;
			case _I(G,R,A,Y,6,1):
				return alpha | X11_GRAY_61;
			case _I(G,R,A,Y,_,6,1):
				return alpha | X11_GRAY_61;
			case _I(G,R,A,Y, ,6,1):
				return alpha | X11_GRAY_61;
			case _I(G,R,E,Y,6,1):
				return alpha | X11_GREY_61;
			case _I(G,R,E,Y,_,6,1):
				return alpha | X11_GREY_61;
			case _I(G,R,E,Y, ,6,1):
				return alpha | X11_GREY_61;
			case _I(G,R,A,Y,6,2):
				return alpha | X11_GRAY_62;
			case _I(G,R,A,Y,_,6,2):
				return alpha | X11_GRAY_62;
			case _I(G,R,A,Y, ,6,2):
				return alpha | X11_GRAY_62;
			case _I(G,R,E,Y,6,2):
				return alpha | X11_GREY_62;
			case _I(G,R,E,Y,_,6,2):
				return alpha | X11_GREY_62;
			case _I(G,R,E,Y, ,6,2):
				return alpha | X11_GREY_62;
			case _I(G,R,A,Y,6,3):
				return alpha | X11_GRAY_63;
			case _I(G,R,A,Y,_,6,3):
				return alpha | X11_GRAY_63;
			case _I(G,R,A,Y, ,6,3):
				return alpha | X11_GRAY_63;
			case _I(G,R,E,Y,6,3):
				return alpha | X11_GREY_63;
			case _I(G,R,E,Y,_,6,3):
				return alpha | X11_GREY_63;
			case _I(G,R,E,Y, ,6,3):
				return alpha | X11_GREY_63;
			case _I(G,R,A,Y,6,4):
				return alpha | X11_GRAY_64;
			case _I(G,R,A,Y,_,6,4):
				return alpha | X11_GRAY_64;
			case _I(G,R,A,Y, ,6,4):
				return alpha | X11_GRAY_64;
			case _I(G,R,E,Y,6,4):
				return alpha | X11_GREY_64;
			case _I(G,R,E,Y,_,6,4):
				return alpha | X11_GREY_64;
			case _I(G,R,E,Y, ,6,4):
				return alpha | X11_GREY_64;
			case _I(G,R,A,Y,6,5):
				return alpha | X11_GRAY_65;
			case _I(G,R,A,Y,_,6,5):
				return alpha | X11_GRAY_65;
			case _I(G,R,A,Y, ,6,5):
				return alpha | X11_GRAY_65;
			case _I(G,R,E,Y,6,5):
				return alpha | X11_GREY_65;
			case _I(G,R,E,Y,_,6,5):
				return alpha | X11_GREY_65;
			case _I(G,R,E,Y, ,6,5):
				return alpha | X11_GREY_65;
			case _I(G,R,A,Y,6,6):
				return alpha | X11_GRAY_66;
			case _I(G,R,A,Y,_,6,6):
				return alpha | X11_GRAY_66;
			case _I(G,R,A,Y, ,6,6):
				return alpha | X11_GRAY_66;
			case _I(G,R,E,Y,6,6):
				return alpha | X11_GREY_66;
			case _I(G,R,E,Y,_,6,6):
				return alpha | X11_GREY_66;
			case _I(G,R,E,Y, ,6,6):
				return alpha | X11_GREY_66;
			case _I(G,R,A,Y,6,7):
				return alpha | X11_GRAY_67;
			case _I(G,R,A,Y,_,6,7):
				return alpha | X11_GRAY_67;
			case _I(G,R,A,Y, ,6,7):
				return alpha | X11_GRAY_67;
			case _I(G,R,E,Y,6,7):
				return alpha | X11_GREY_67;
			case _I(G,R,E,Y,_,6,7):
				return alpha | X11_GREY_67;
			case _I(G,R,E,Y, ,6,7):
				return alpha | X11_GREY_67;
			case _I(G,R,A,Y,6,8):
				return alpha | X11_GRAY_68;
			case _I(G,R,A,Y,_,6,8):
				return alpha | X11_GRAY_68;
			case _I(G,R,A,Y, ,6,8):
				return alpha | X11_GRAY_68;
			case _I(G,R,E,Y,6,8):
				return alpha | X11_GREY_68;
			case _I(G,R,E,Y,_,6,8):
				return alpha | X11_GREY_68;
			case _I(G,R,E,Y, ,6,8):
				return alpha | X11_GREY_68;
			case _I(G,R,A,Y,6,9):
				return alpha | X11_GRAY_69;
			case _I(G,R,A,Y,_,6,9):
				return alpha | X11_GRAY_69;
			case _I(G,R,A,Y, ,6,9):
				return alpha | X11_GRAY_69;
			case _I(G,R,E,Y,6,9):
				return alpha | X11_GREY_69;
			case _I(G,R,E,Y,_,6,9):
				return alpha | X11_GREY_69;
			case _I(G,R,E,Y, ,6,9):
				return alpha | X11_GREY_69;
			case _I(G,R,A,Y,7,0):
				return alpha | X11_GRAY_70;
			case _I(G,R,A,Y,_,7,0):
				return alpha | X11_GRAY_70;
			case _I(G,R,A,Y, ,7,0):
				return alpha | X11_GRAY_70;
			case _I(G,R,E,Y,7,0):
				return alpha | X11_GREY_70;
			case _I(G,R,E,Y,_,7,0):
				return alpha | X11_GREY_70;
			case _I(G,R,E,Y, ,7,0):
				return alpha | X11_GREY_70;
			case _I(G,R,A,Y,7,1):
				return alpha | X11_GRAY_71;
			case _I(G,R,A,Y,_,7,1):
				return alpha | X11_GRAY_71;
			case _I(G,R,A,Y, ,7,1):
				return alpha | X11_GRAY_71;
			case _I(G,R,E,Y,7,1):
				return alpha | X11_GREY_71;
			case _I(G,R,E,Y,_,7,1):
				return alpha | X11_GREY_71;
			case _I(G,R,E,Y, ,7,1):
				return alpha | X11_GREY_71;
			case _I(G,R,A,Y,7,2):
				return alpha | X11_GRAY_72;
			case _I(G,R,A,Y,_,7,2):
				return alpha | X11_GRAY_72;
			case _I(G,R,A,Y, ,7,2):
				return alpha | X11_GRAY_72;
			case _I(G,R,E,Y,7,2):
				return alpha | X11_GREY_72;
			case _I(G,R,E,Y,_,7,2):
				return alpha | X11_GREY_72;
			case _I(G,R,E,Y, ,7,2):
				return alpha | X11_GREY_72;
			case _I(G,R,A,Y,7,3):
				return alpha | X11_GRAY_73;
			case _I(G,R,A,Y,_,7,3):
				return alpha | X11_GRAY_73;
			case _I(G,R,A,Y, ,7,3):
				return alpha | X11_GRAY_73;
			case _I(G,R,E,Y,7,3):
				return alpha | X11_GREY_73;
			case _I(G,R,E,Y,_,7,3):
				return alpha | X11_GREY_73;
			case _I(G,R,E,Y, ,7,3):
				return alpha | X11_GREY_73;
			case _I(G,R,A,Y,7,4):
				return alpha | X11_GRAY_74;
			case _I(G,R,A,Y,_,7,4):
				return alpha | X11_GRAY_74;
			case _I(G,R,A,Y, ,7,4):
				return alpha | X11_GRAY_74;
			case _I(G,R,E,Y,7,4):
				return alpha | X11_GREY_74;
			case _I(G,R,E,Y,_,7,4):
				return alpha | X11_GREY_74;
			case _I(G,R,E,Y, ,7,4):
				return alpha | X11_GREY_74;
			case _I(G,R,A,Y,7,5):
				return alpha | X11_GRAY_75;
			case _I(G,R,A,Y,_,7,5):
				return alpha | X11_GRAY_75;
			case _I(G,R,A,Y, ,7,5):
				return alpha | X11_GRAY_75;
			case _I(G,R,E,Y,7,5):
				return alpha | X11_GREY_75;
			case _I(G,R,E,Y,_,7,5):
				return alpha | X11_GREY_75;
			case _I(G,R,E,Y, ,7,5):
				return alpha | X11_GREY_75;
			case _I(G,R,A,Y,7,6):
				return alpha | X11_GRAY_76;
			case _I(G,R,A,Y,_,7,6):
				return alpha | X11_GRAY_76;
			case _I(G,R,A,Y, ,7,6):
				return alpha | X11_GRAY_76;
			case _I(G,R,E,Y,7,6):
				return alpha | X11_GREY_76;
			case _I(G,R,E,Y,_,7,6):
				return alpha | X11_GREY_76;
			case _I(G,R,E,Y, ,7,6):
				return alpha | X11_GREY_76;
			case _I(G,R,A,Y,7,7):
				return alpha | X11_GRAY_77;
			case _I(G,R,A,Y,_,7,7):
				return alpha | X11_GRAY_77;
			case _I(G,R,A,Y, ,7,7):
				return alpha | X11_GRAY_77;
			case _I(G,R,E,Y,7,7):
				return alpha | X11_GREY_77;
			case _I(G,R,E,Y,_,7,7):
				return alpha | X11_GREY_77;
			case _I(G,R,E,Y, ,7,7):
				return alpha | X11_GREY_77;
			case _I(G,R,A,Y,7,8):
				return alpha | X11_GRAY_78;
			case _I(G,R,A,Y,_,7,8):
				return alpha | X11_GRAY_78;
			case _I(G,R,A,Y, ,7,8):
				return alpha | X11_GRAY_78;
			case _I(G,R,E,Y,7,8):
				return alpha | X11_GREY_78;
			case _I(G,R,E,Y,_,7,8):
				return alpha | X11_GREY_78;
			case _I(G,R,E,Y, ,7,8):
				return alpha | X11_GREY_78;
			case _I(G,R,A,Y,7,9):
				return alpha | X11_GRAY_79;
			case _I(G,R,A,Y,_,7,9):
				return alpha | X11_GRAY_79;
			case _I(G,R,A,Y, ,7,9):
				return alpha | X11_GRAY_79;
			case _I(G,R,E,Y,7,9):
				return alpha | X11_GREY_79;
			case _I(G,R,E,Y,_,7,9):
				return alpha | X11_GREY_79;
			case _I(G,R,E,Y, ,7,9):
				return alpha | X11_GREY_79;
			case _I(G,R,A,Y,8,0):
				return alpha | X11_GRAY_80;
			case _I(G,R,A,Y,_,8,0):
				return alpha | X11_GRAY_80;
			case _I(G,R,A,Y, ,8,0):
				return alpha | X11_GRAY_80;
			case _I(G,R,E,Y,8,0):
				return alpha | X11_GREY_80;
			case _I(G,R,E,Y,_,8,0):
				return alpha | X11_GREY_80;
			case _I(G,R,E,Y, ,8,0):
				return alpha | X11_GREY_80;
			case _I(G,R,A,Y,8,1):
				return alpha | X11_GRAY_81;
			case _I(G,R,A,Y,_,8,1):
				return alpha | X11_GRAY_81;
			case _I(G,R,A,Y, ,8,1):
				return alpha | X11_GRAY_81;
			case _I(G,R,E,Y,8,1):
				return alpha | X11_GREY_81;
			case _I(G,R,E,Y,_,8,1):
				return alpha | X11_GREY_81;
			case _I(G,R,E,Y, ,8,1):
				return alpha | X11_GREY_81;
			case _I(G,R,A,Y,8,2):
				return alpha | X11_GRAY_82;
			case _I(G,R,A,Y,_,8,2):
				return alpha | X11_GRAY_82;
			case _I(G,R,A,Y, ,8,2):
				return alpha | X11_GRAY_82;
			case _I(G,R,E,Y,8,2):
				return alpha | X11_GREY_82;
			case _I(G,R,E,Y,_,8,2):
				return alpha | X11_GREY_82;
			case _I(G,R,E,Y, ,8,2):
				return alpha | X11_GREY_82;
			case _I(G,R,A,Y,8,3):
				return alpha | X11_GRAY_83;
			case _I(G,R,A,Y,_,8,3):
				return alpha | X11_GRAY_83;
			case _I(G,R,A,Y, ,8,3):
				return alpha | X11_GRAY_83;
			case _I(G,R,E,Y,8,3):
				return alpha | X11_GREY_83;
			case _I(G,R,E,Y,_,8,3):
				return alpha | X11_GREY_83;
			case _I(G,R,E,Y, ,8,3):
				return alpha | X11_GREY_83;
			case _I(G,R,A,Y,8,4):
				return alpha | X11_GRAY_84;
			case _I(G,R,A,Y,_,8,4):
				return alpha | X11_GRAY_84;
			case _I(G,R,A,Y, ,8,4):
				return alpha | X11_GRAY_84;
			case _I(G,R,E,Y,8,4):
				return alpha | X11_GREY_84;
			case _I(G,R,E,Y,_,8,4):
				return alpha | X11_GREY_84;
			case _I(G,R,E,Y, ,8,4):
				return alpha | X11_GREY_84;
			case _I(G,R,A,Y,8,5):
				return alpha | X11_GRAY_85;
			case _I(G,R,A,Y,_,8,5):
				return alpha | X11_GRAY_85;
			case _I(G,R,A,Y, ,8,5):
				return alpha | X11_GRAY_85;
			case _I(G,R,E,Y,8,5):
				return alpha | X11_GREY_85;
			case _I(G,R,E,Y,_,8,5):
				return alpha | X11_GREY_85;
			case _I(G,R,E,Y, ,8,5):
				return alpha | X11_GREY_85;
			case _I(G,R,A,Y,8,6):
				return alpha | X11_GRAY_86;
			case _I(G,R,A,Y,_,8,6):
				return alpha | X11_GRAY_86;
			case _I(G,R,A,Y, ,8,6):
				return alpha | X11_GRAY_86;
			case _I(G,R,E,Y,8,6):
				return alpha | X11_GREY_86;
			case _I(G,R,E,Y,_,8,6):
				return alpha | X11_GREY_86;
			case _I(G,R,E,Y, ,8,6):
				return alpha | X11_GREY_86;
			case _I(G,R,A,Y,8,7):
				return alpha | X11_GRAY_87;
			case _I(G,R,A,Y,_,8,7):
				return alpha | X11_GRAY_87;
			case _I(G,R,A,Y, ,8,7):
				return alpha | X11_GRAY_87;
			case _I(G,R,E,Y,8,7):
				return alpha | X11_GREY_87;
			case _I(G,R,E,Y,_,8,7):
				return alpha | X11_GREY_87;
			case _I(G,R,E,Y, ,8,7):
				return alpha | X11_GREY_87;
			case _I(G,R,A,Y,8,8):
				return alpha | X11_GRAY_88;
			case _I(G,R,A,Y,_,8,8):
				return alpha | X11_GRAY_88;
			case _I(G,R,A,Y, ,8,8):
				return alpha | X11_GRAY_88;
			case _I(G,R,E,Y,8,8):
				return alpha | X11_GREY_88;
			case _I(G,R,E,Y,_,8,8):
				return alpha | X11_GREY_88;
			case _I(G,R,E,Y, ,8,8):
				return alpha | X11_GREY_88;
			case _I(G,R,A,Y,8,9):
				return alpha | X11_GRAY_89;
			case _I(G,R,A,Y,_,8,9):
				return alpha | X11_GRAY_89;
			case _I(G,R,A,Y, ,8,9):
				return alpha | X11_GRAY_89;
			case _I(G,R,E,Y,8,9):
				return alpha | X11_GREY_89;
			case _I(G,R,E,Y,_,8,9):
				return alpha | X11_GREY_89;
			case _I(G,R,E,Y, ,8,9):
				return alpha | X11_GREY_89;
			case _I(G,R,A,Y,9,0):
				return alpha | X11_GRAY_90;
			case _I(G,R,A,Y,_,9,0):
				return alpha | X11_GRAY_90;
			case _I(G,R,A,Y, ,9,0):
				return alpha | X11_GRAY_90;
			case _I(G,R,E,Y,9,0):
				return alpha | X11_GREY_90;
			case _I(G,R,E,Y,_,9,0):
				return alpha | X11_GREY_90;
			case _I(G,R,E,Y, ,9,0):
				return alpha | X11_GREY_90;
			case _I(G,R,A,Y,9,1):
				return alpha | X11_GRAY_91;
			case _I(G,R,A,Y,_,9,1):
				return alpha | X11_GRAY_91;
			case _I(G,R,A,Y, ,9,1):
				return alpha | X11_GRAY_91;
			case _I(G,R,E,Y,9,1):
				return alpha | X11_GREY_91;
			case _I(G,R,E,Y,_,9,1):
				return alpha | X11_GREY_91;
			case _I(G,R,E,Y, ,9,1):
				return alpha | X11_GREY_91;
			case _I(G,R,A,Y,9,2):
				return alpha | X11_GRAY_92;
			case _I(G,R,A,Y,_,9,2):
				return alpha | X11_GRAY_92;
			case _I(G,R,A,Y, ,9,2):
				return alpha | X11_GRAY_92;
			case _I(G,R,E,Y,9,2):
				return alpha | X11_GREY_92;
			case _I(G,R,E,Y,_,9,2):
				return alpha | X11_GREY_92;
			case _I(G,R,E,Y, ,9,2):
				return alpha | X11_GREY_92;
			case _I(G,R,A,Y,9,3):
				return alpha | X11_GRAY_93;
			case _I(G,R,A,Y,_,9,3):
				return alpha | X11_GRAY_93;
			case _I(G,R,A,Y, ,9,3):
				return alpha | X11_GRAY_93;
			case _I(G,R,E,Y,9,3):
				return alpha | X11_GREY_93;
			case _I(G,R,E,Y,_,9,3):
				return alpha | X11_GREY_93;
			case _I(G,R,E,Y, ,9,3):
				return alpha | X11_GREY_93;
			case _I(G,R,A,Y,9,4):
				return alpha | X11_GRAY_94;
			case _I(G,R,A,Y,_,9,4):
				return alpha | X11_GRAY_94;
			case _I(G,R,A,Y, ,9,4):
				return alpha | X11_GRAY_94;
			case _I(G,R,E,Y,9,4):
				return alpha | X11_GREY_94;
			case _I(G,R,E,Y,_,9,4):
				return alpha | X11_GREY_94;
			case _I(G,R,E,Y, ,9,4):
				return alpha | X11_GREY_94;
			case _I(G,R,A,Y,9,5):
				return alpha | X11_GRAY_95;
			case _I(G,R,A,Y,_,9,5):
				return alpha | X11_GRAY_95;
			case _I(G,R,A,Y, ,9,5):
				return alpha | X11_GRAY_95;
			case _I(G,R,E,Y,9,5):
				return alpha | X11_GREY_95;
			case _I(G,R,E,Y,_,9,5):
				return alpha | X11_GREY_95;
			case _I(G,R,E,Y, ,9,5):
				return alpha | X11_GREY_95;
			case _I(G,R,A,Y,9,6):
				return alpha | X11_GRAY_96;
			case _I(G,R,A,Y,_,9,6):
				return alpha | X11_GRAY_96;
			case _I(G,R,A,Y, ,9,6):
				return alpha | X11_GRAY_96;
			case _I(G,R,E,Y,9,6):
				return alpha | X11_GREY_96;
			case _I(G,R,E,Y,_,9,6):
				return alpha | X11_GREY_96;
			case _I(G,R,E,Y, ,9,6):
				return alpha | X11_GREY_96;
			case _I(G,R,A,Y,9,7):
				return alpha | X11_GRAY_97;
			case _I(G,R,A,Y,_,9,7):
				return alpha | X11_GRAY_97;
			case _I(G,R,A,Y, ,9,7):
				return alpha | X11_GRAY_97;
			case _I(G,R,E,Y,9,7):
				return alpha | X11_GREY_97;
			case _I(G,R,E,Y,_,9,7):
				return alpha | X11_GREY_97;
			case _I(G,R,E,Y, ,9,7):
				return alpha | X11_GREY_97;
			case _I(G,R,A,Y,9,8):
				return alpha | X11_GRAY_98;
			case _I(G,R,A,Y,_,9,8):
				return alpha | X11_GRAY_98;
			case _I(G,R,A,Y, ,9,8):
				return alpha | X11_GRAY_98;
			case _I(G,R,E,Y,9,8):
				return alpha | X11_GREY_98;
			case _I(G,R,E,Y,_,9,8):
				return alpha | X11_GREY_98;
			case _I(G,R,E,Y, ,9,8):
				return alpha | X11_GREY_98;
			case _I(G,R,A,Y,9,9):
				return alpha | X11_GRAY_99;
			case _I(G,R,A,Y,_,9,9):
				return alpha | X11_GRAY_99;
			case _I(G,R,A,Y, ,9,9):
				return alpha | X11_GRAY_99;
			case _I(G,R,E,Y,9,9):
				return alpha | X11_GREY_99;
			case _I(G,R,E,Y,_,9,9):
				return alpha | X11_GREY_99;
			case _I(G,R,E,Y, ,9,9):
				return alpha | X11_GREY_99;
			case _I(G,R,A,Y,1,0,0):
				return alpha | X11_GRAY_100;
			case _I(G,R,A,Y,_,1,0,0):
				return alpha | X11_GRAY_100;
			case _I(G,R,A,Y, ,1,0,0):
				return alpha | X11_GRAY_100;
			case _I(G,R,E,Y,1,0,0):
				return alpha | X11_GREY_100;
			case _I(G,R,E,Y,_,1,0,0):
				return alpha | X11_GREY_100;
			case _I(G,R,E,Y, ,1,0,0):
				return alpha | X11_GREY_100;
			case _I(D,A,R,K,G,R,E,Y):
				return alpha | X11_DARK_GREY;
			case _I(D,A,R,K,_,G,R,E,Y):
				return alpha | X11_DARK_GREY;
			case _I(D,A,R,K, ,G,R,E,Y):
				return alpha | X11_DARK_GREY;
			case _I(D,A,R,K,G,R,A,Y):
				return alpha | X11_DARK_GRAY;
			case _I(D,A,R,K,_,G,R,A,Y):
				return alpha | X11_DARK_GRAY;
			case _I(D,A,R,K, ,G,R,A,Y):
				return alpha | X11_DARK_GRAY;
			case _I(D,A,R,K,B,L,U,E):
				return alpha | X11_DARK_BLUE;
			case _I(D,A,R,K,_,B,L,U,E):
				return alpha | X11_DARK_BLUE;
			case _I(D,A,R,K, ,B,L,U,E):
				return alpha | X11_DARK_BLUE;
			case _I(D,A,R,K,C,Y,A,N):
				return alpha | X11_DARK_CYAN;
			case _I(D,A,R,K,_,C,Y,A,N):
				return alpha | X11_DARK_CYAN;
			case _I(D,A,R,K, ,C,Y,A,N):
				return alpha | X11_DARK_CYAN;
			case _I(D,A,R,K,M,A,G,E,N,T,A):
				return alpha | X11_DARK_MAGENTA;
			case _I(D,A,R,K,_,M,A,G,E,N,T,A):
				return alpha | X11_DARK_MAGENTA;
			case _I(D,A,R,K, ,M,A,G,E,N,T,A):
				return alpha | X11_DARK_MAGENTA;
			case _I(D,A,R,K,R,E,D):
				return alpha | X11_DARK_RED;
			case _I(D,A,R,K,_,R,E,D):
				return alpha | X11_DARK_RED;
			case _I(D,A,R,K, ,R,E,D):
				return alpha | X11_DARK_RED;
			case _I(L,I,G,H,T,G,R,E,E,N):
				return alpha | X11_LIGHT_GREEN;
			case _I(L,I,G,H,T,_,G,R,E,E,N):
				return alpha | X11_LIGHT_GREEN;
			case _I(L,I,G,H,T, ,G,R,E,E,N):
				return alpha | X11_LIGHT_GREEN;
		}
