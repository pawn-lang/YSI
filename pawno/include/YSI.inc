/*----------------------------------------------------------------------------*\
					=======================================
					  YSI - YSI Server Includes functions
					=======================================
Description:
	Lists all the functions available in YSI for PAWNO.
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
	
	The Original Code is the YSI group include.
	
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
	25/02/12:
		First version
\*----------------------------------------------------------------------------*/

//forward __y_als__();




//forward __y_amx__();


forward AMX_GetBaseCount(E_AMX_TABLE:table, &base, &count);
forward AMX_GetGlobalAddress(...);
forward AMX_Read(addr);
forward AMX_Write(addr, value);
forward AMX_ReadString(addr, str[], len = sizeof (str));
forward AMX_WriteString(addr, const str[], len = sizeof (str));
forward AMX_ReadArray(addr, dest[], len = sizeof (dest));
forward AMX_WriteArray(addr, const src[], len = sizeof (src));

forward AMX_GetPublicEntry(idx, &buffer, const pattern[] = "");
forward AMX_GetNativeEntry(idx, &buffer, const pattern[] = "");
forward AMX_GetLibraryEntry(idx, &buffer, const pattern[] = "");
forward AMX_GetPubvarEntry(idx, &buffer, const pattern[] = "");
forward AMX_GetTagEntry(idx, &buffer, const pattern[] = "");
forward AMX_GetEntry(E_AMX_TABLE:table, idx, &buffer, const pattern[] = "");

forward AMX_GetPublicEntryPrefix(idx, &buffer, pattern);
forward AMX_GetNativeEntryPrefix(idx, &buffer, pattern);
forward AMX_GetLibraryEntryPrefix(idx, &buffer, pattern);
forward AMX_GetPubvarEntryPrefix(idx, &buffer, pattern);
forward AMX_GetTagEntryPrefix(idx, &buffer, pattern);
forward AMX_GetEntryPrefix(E_AMX_TABLE:table, idx, &buffer, pattern);

forward AMX_GetPublicEntrySuffix(idx, &buffer, pattern);
forward AMX_GetNativeEntrySuffix(idx, &buffer, pattern);
forward AMX_GetLibraryEntrySuffix(idx, &buffer, pattern);
forward AMX_GetPubvarEntrySuffix(idx, &buffer, pattern);
forward AMX_GetTagEntrySuffix(idx, &buffer, pattern);
forward AMX_GetEntrySuffix(E_AMX_TABLE:table, idx, &buffer, pattern);

forward AMX_GetPublicName(idx, buffer[32], const pattern[] = "");
forward AMX_GetNativeName(idx, buffer[32], const pattern[] = "");
forward AMX_GetLibraryName(idx, buffer[32], const pattern[] = "");
forward AMX_GetPubvarName(idx, buffer[32], const pattern[] = "");
forward AMX_GetTagName(idx, buffer[32], const pattern[] = "");
forward AMX_GetName(E_AMX_TABLE:table, idx, buffer[32], const pattern[] = "");

forward AMX_GetPublicNamePrefix(idx, buffer[32], pattern);
forward AMX_GetNativeNamePrefix(idx, buffer[32], pattern);
forward AMX_GetLibraryNamePrefix(idx, buffer[32], pattern);
forward AMX_GetPubvarNamePrefix(idx, buffer[32], pattern);
forward AMX_GetTagNamePrefix(idx, buffer[32], pattern);
forward AMX_GetNamePrefix(E_AMX_TABLE:table, idx, buffer[32], pattern);

forward AMX_GetPublicNameSuffix(idx, buffer[32], pattern);
forward AMX_GetNativeNameSuffix(idx, buffer[32], pattern);
forward AMX_GetLibraryNameSuffix(idx, buffer[32], pattern);
forward AMX_GetPubvarNameSuffix(idx, buffer[32], pattern);
forward AMX_GetTagNameSuffix(idx, buffer[32], pattern);
forward AMX_GetNameSuffix(E_AMX_TABLE:table, idx, buffer[32], pattern);

forward AMX_GetPublicPointer(idx, &buffer, const pattern[] = "");
forward AMX_GetNativePointer(idx, &buffer, const pattern[] = "");
forward AMX_GetLibraryPointer(idx, &buffer, const pattern[] = "");
forward AMX_GetPubvarPointer(idx, &buffer, const pattern[] = "");
forward AMX_GetTagPointer(idx, &buffer, const pattern[] = "");
forward AMX_GetPointer(E_AMX_TABLE:table, idx, &buffer, const pattern[] = "");

forward AMX_GetPublicPointerPrefix(idx, &buffer, pattern);
forward AMX_GetNativePointerPrefix(idx, &buffer, pattern);
forward AMX_GetLibraryPointerPrefix(idx, &buffer, pattern);
forward AMX_GetPubvarPointerPrefix(idx, &buffer, pattern);
forward AMX_GetTagPointerPrefix(idx, &buffer, pattern);
forward AMX_GetPointerPrefix(E_AMX_TABLE:table, idx, &buffer, pattern);

forward AMX_GetPublicPointerSuffix(idx, &buffer, pattern);
forward AMX_GetNativePointerSuffix(idx, &buffer, pattern);
forward AMX_GetLibraryPointerSuffix(idx, &buffer, pattern);
forward AMX_GetPubvarPointerSuffix(idx, &buffer, pattern);
forward AMX_GetTagPointerSuffix(idx, &buffer, pattern);
forward AMX_GetPointerSuffix(E_AMX_TABLE:table, idx, &buffer, pattern);

forward AMX_GetPublicValue(idx, &buffer, const pattern[] = "");
forward AMX_GetNativeValue(idx, &buffer, const pattern[] = "");
forward AMX_GetLibraryValue(idx, &buffer, const pattern[] = "");
forward AMX_GetPubvarValue(idx, &buffer, const pattern[] = "");
forward AMX_GetTagValue(idx, &buffer, const pattern[] = "");
forward AMX_GetValue(E_AMX_TABLE:table, idx, &buffer, const pattern[] = "");

forward AMX_GetPublicValuePrefix(idx, &buffer, pattern);
forward AMX_GetNativeValuePrefix(idx, &buffer, pattern);
forward AMX_GetLibraryValuePrefix(idx, &buffer, pattern);
forward AMX_GetPubvarValuePrefix(idx, &buffer, pattern);
forward AMX_GetTagValuePrefix(idx, &buffer, pattern);
forward AMX_GetValuePrefix(E_AMX_TABLE:table, idx, &buffer, pattern);

forward AMX_GetPublicValueSuffix(idx, &buffer, pattern);
forward AMX_GetNativeValueSuffix(idx, &buffer, pattern);
forward AMX_GetLibraryValueSuffix(idx, &buffer, pattern);
forward AMX_GetPubvarValueSuffix(idx, &buffer, pattern);
forward AMX_GetTagValueSuffix(idx, &buffer, pattern);
forward AMX_GetValueSuffix(E_AMX_TABLE:table, idx, &buffer, pattern);


//forward __y_areas__();


forward Area_AddCube(Float:x0, Float:y0, Float:z0, Float:x1, Float:y1, Float:z1);
forward Area_AddBox(Float:minx, Float:miny, Float:maxx, Float:maxy);
//forward Area_AddCircle(Float:x, Float:y, Float:r, Float:h = FLOAT_INFINITY);
forward Area_AddSphere(Float:x, Float:y, Float:z, Float:r);
forward Area_AddPoly(Float:x1, Float:y1, Float:x2, Float:y2, Float:x3, Float:y3, Float:...);
forward Area_Delete(area);
forward Area_GetPlayerArea(playerid);
forward Area_SetPlayer(area, playerid, bool:set);
forward bool:Area_GetPlayer(area, playerid);
forward Area_SetAllPlayers(area, bool:set);
forward Area_SetWorld(area, world, bool:set);
forward bool:Area_GetWorld(area, world);
forward Area_SetAllWorlds(area, bool:set);
forward bool:Area_IsValid(area);
forward bool:Area_IsEmpty(area);


//forward __y_bintree__();


//forward Bintree_Generate(Bintree:output[][E_BINTREE_TREE], input[][E_BINTREE_INPUT], size);
//forward Bintree_Reset(Bintree:tree[][E_BINTREE_TREE], pointer = 0);
//forward Bintree_FindValue(Bintree:tree[][E_BINTREE_TREE], value, &cont = 0, &old = 0);
//forward Bintree_Add(Bintree:data[][E_BINTREE_TREE], pointer, value, offset, maxsize = sizeof (data));
//forward Bintree_Delete(Bintree:source[][E_BINTREE_TREE], index, count);
//forward Bintree_UpdatePointers(Bintree:data[][E_BINTREE_TREE], offset, size, mod = -1);


//forward __y_bit__();


forward Bit_Set(Bit:array[], slot, bool:set);
forward Bit_SetAll(Bit:array[], bool:set, size = sizeof (array));
forward Bit_GetCount(Bit:array[], size = sizeof (array));
forward Bit_Display(Bit:array[], size = sizeof (array));
forward Bits@YSII_Ag(Bit:data[], start, size = sizeof (data));
forward Blanks@YSII_Ag(Bit:data[], start, size = sizeof (data));


//forward __y_cell__();


//forward Cell_ReverseBits({Float, _}:data);
//forward Cell_ReverseNibbles({Float, _}:data);
//forward Cell_ReverseBytes({Float, _}:data);
//forward Cell_CountBits({Float, _}:data);
//forward Cell_GetLowestBit({Float, _}:data);
//forward Cell_GetLowestComponent({Float, _}:data);


//forward __y_classes__();


forward Class_Add(skin, Float:x, Float:y, Float:z, Float:a, ...);

forward Class_AddEx(Group:forgroup, Group:setgroup, skin, Float:x, Float:y, Float:z, Float:a, ...);
forward Class_AddForGroup(Group:group, skin, Float:x, Float:y, Float:z, Float:a, ...);
forward Class_AddWithGroupSet(Group:group, skin, Float:x, Float:y, Float:z, Float:a, ...);
forward Class_Enable(classid, bool:toggle);
forward Class_Delete(classid);
forward Class_SetPlayer(cl, pid, bool:s);
forward bool:Class_GetPlayer(cl, pid);
forward Class_Get(playerid);
forward Class_Goto(playerid, playerclass);

forward Class_DisableSelection(playerid);
forward Class_DisableReselection(playerid);
forward Class_EnableReselection(playerid);
forward Class_ForceReselection(playerid);
forward Class_ReturnToSelection(playerid);


//forward __y_colours__();
//forward __y_colors__();


forward SetColoursCanHaveSpaces(bool:set);
forward SetColour(const name[], color);
forward SetColourHash(hash, color);
forward GetColour(const name[], alpha = 0xAA);
forward GetColourStream(const str[], &idx, alpha = 0xAA);
forward GetColourHash(hash, alpha = 0xAA);


//forward __y_commands__();


forward Command_AddAlt(oidx, altname[]);
forward Command_AddAltNamed(function[], altname[]);
forward Command_SetPlayer(c, p, bool:s);
forward Command_SetPlayerNamed(f[], p, bool:s);

forward Command_SetDeniedReturn(bool:set);
forward bool:Command_GetDeniedReturn();
forward Command_SetIllegalReturn(bool:set);
forward bool:Command_GetIllegalReturn();
forward Command_SetUnknownReturn(bool:set);
forward bool:Command_GetUnknownReturn();
forward Command_SetDisconnectReturn(bool:set);
forward bool:Command_GetDisconnectReturn();

forward Command_GetID(function[]);
forward bool:Command_GetPlayer(command, playerid);
forward bool:Command_GetPlayerNamed(func[], playerid);
forward Command_Remove(func);
forward Command_RemoveNamed(func[]);
forward Command_ReProcess(p, c[], h);
forward Command_GetName(funcid);
forward Command_GetDisplay(funcid, playerid);
forward Command_GetDisplayNamed(func[], playerid);
forward Command_GetPlayerCommandCount(playerid);
forward Command_GetNext(index, playerid);

forward Command_SetProvider(p);
forward Command_GetProvider();
forward Command_SetPlayerProvider(playerid, p);
forward Command_GetPlayerProvider(playerid);


//forward __y_debug__();


forward Debug_Print0(str[], {Float, _}:...);


//forward __y_dialog__();


forward Dialog_Show(playerid, style, title[], caption[], button1[], button2[] = "", dialog = -1);
forward Dialog_ShowCallback(playerid, const callback_tag:callback[], style, title[], caption[], button1[], button2[] = "", dialog = -1);

forward Dialog_ObtainID();
forward Dialog_TryObtainID(id);
forward Dialog_Get(playerid);
forward Dialog_Garbage(dialogid);
forward Dialog_Free(dialogid);
forward Dialog_Set(playerid, dialogid);
//forward Dialog_ShowCallbackData(playerid, callback[E_CALLBACK_DATA], style, title[], caption[], button1[], button2[] = "", dialogid = -1);
forward Dialog_Hide(playerid);
forward Dialog_SetCallback(dialogid, const callback_tag:callback[]);
//forward Dialog_SetCallbackData(dialogid, callback[E_CALLBACK_DATA]);


//forward __y_flooding__();


//forward SetMaxConnections(max = -1, e_FLOOD_ACTION:action = e_FLOOD_ACTION_BLOCK);


//forward __y_groups__();


forward Group:Group_Create(name[]);
forward Group_Destroy(Group:group);
forward Group_SetPlayer(Group:g, p, bool:s);
forward bool:Group_GetPlayer(Group:g, p);

forward Group_SetCommand(Group:g, e, bool:s);
forward Group_SetCommandDefault(Group:g, bool:s);
forward Group_SetGlobalCommand(e, bool:s);
forward Group_SetGlobalCommandDefault(bool:s);

forward Group_SetArea(Group:g, e, bool:s);
forward Group_SetAreaDefault(Group:g, bool:s);
forward Group_SetGlobalArea(e, bool:s);
forward Group_SetGlobalAreaDefault(bool:s);

forward Group_SetClass(Group:g, e, bool:s);
forward Group_SetClassDefault(Group:g, bool:s);
forward Group_SetGlobalClass(e, bool:s);
forward Group_SetGlobalCalssDefault(bool:s);

//forward Iterator:PlayerGroups(playerid);
forward Group:PlayerGroups@YSII_Ag(playerid, Group:start);
forward Group@YSII_Ag(Group:group, start);

forward Group:Group_SetBalanced(playerid, Group:...);
forward Group_GetColour(Group:g);
forward Group_SetColour(Group:g, c);
forward bool:Group_GetGang(Group:g);
forward Group_SetGang(Group:g, bool:n);
forward Group:Group_GetID(name[]);
forward Group_GetName(Group:g);
forward Group_SetName(Group:g, n[]);


//forward __y_hooks__();


//forward __y_ini__();


forward bool:INI_ParseFile(fname[], remoteFormat[], bool:bFileFirst = false, bool:bExtra = false, extra = 0, bool:bLocal = true, bool:bPassTag = false, bool:bFilter = true, filter[] = "");
forward bool:INI_Load(filename[], bool:bExtra = false, extra = 0, bool:bLocal = true);

forward INI:INI_Open(filename[]);
forward INI_Close(INI:file);

forward INI_SetTag(INI:file, tag[]);
forward INI_DeleteTag(INI:file, tag[]);
forward INI_WriteArray(INI:file, const name[], data[], len);
forward INI_RemoveEntry(INI:file, name[]);
forward INI_WriteString(INI:file, name[], data[]);
forward INI_WriteInt(INI:file, name[], data);
forward INI_WriteHex(INI:file, name[], data);
forward INI_WriteBin(INI:file, name[], data);
forward INI_WriteBool(INI:file, name[], bool:data);
forward INI_WriteFloat(INI:file, name[], Float:data, accuracy = 6);


//forward __y_inline__();


//forward Callback_Get(callback:name, result[E_CALLBACK_DATA], expect = -1);
//forward Callback_Release(const input[E_CALLBACK_DATA]);
//forward Callback_Call(const input[E_CALLBACK_DATA], {Float, _}:...);


//forward __y_iterate__();


forward Itter_InitInternal(arr[][], s0, s1);
forward Itter_AddInternal(&count, array[], value, size);
forward Itter_RemoveInternal(&count, array[], value, size);
forward Itter_ContainsInternal(array[], value, size);
forward Itter_SafeRemoveInternal(&count, array[], value, &last, size);
forward Itter_RandomInternal(count, array[], size);
forward Itter_ClearInternal(&count, array[], size);
forward Itter_FreeInternal(array[], size);

forward Itter_PrevInternal(array[], size, slot);


//forward __y_languages__();


forward Language:Langs_Add(code[], name[]);
forward Language:Langs_SetPlayerLanguage(playerid, Language:l);
forward Language:Langs_GetPlayerLanguage(playerid);

forward Language:Langs_AddLanguage(code[], name[]);
forward Langs_RemoveLanguage(Language:l);
forward Language:Langs_GetLanguage(identifier[]);
forward Language:Langs_GetLanguageCount();
forward Langs_GetLanguageCodes();
forward Langs_GetName(Language:l);
forward Langs_GetCode(Language:l);
forward bool:Langs_IsValid(Language:l);
forward Language:Langs_SetPlayerCode(playerid, code[]);


//forward __y_lock__();


//forward __y_malloc__();


forward Alloc:Malloc_NewS(const string[], bool:pack = false);

forward Malloc_GetS(target[], length, Alloc:array, index);
forward Malloc_SetS(Alloc:array, index, const str[]);
forward Malloc_SetVAS(Alloc:array, index, arg);

forward Malloc_GetA(target[], length, Alloc:array, index);
forward Malloc_SetA(Alloc:array, index, const str[], len);
forward Malloc_SetVAA(Alloc:array, index, arg);

forward Alloc:calloc(size);


//forward __y_master__();


forward Master_Caller();


//forward __y_php__();


forward PHP_SendString(name[], value[], bool:priority = false);
forward PHP_SendFloat(name[], Float:value, bool:priority = false);
forward PHP_SendBool(name[], bool:value, bool:priority = false);
forward PHP_SendInt(name[], value, bool:priority = false);


//forward __y_playerarray__();


forward PA_Init(Bit:a[], bool:init = false, s = (((MAX_PLAYERS) + cellbits - 1) / cellbits));
forward PA_Set(Bit:d[], slot, bool:set);
forward PA@YSII_Ag(Bit:data[], start);


//forward __y_playerset__();


forward PS@YSII_Ag(__ps_addr_t:addr, cur);
forward __PS_C(source[MAX_PLAYERS][], idx);
forward bool:__PS_A(__ps_addr_t:addr, Bit:ret[((MAX_PLAYERS) + cellbits - 1) / cellbits + 1]);


//forward __y_remote__();


//forward __y_scriptinit__();


//forward __y_stringhash__();


//forward YHash(const str[], bool:sensitive = true, e_HASH_TYPE:type = hash_bernstein, len = -1, pack = false);


//forward __y_svar__();


//forward __y_td__();


//forward Style:TD_Create(Float:x = 0.0, Float:y = 0.0, Float:letterX = 0.48, Float:letterY = 1.12, Float:textX = 1280.0, Float:textY = 1280.0, colour = 0xE1E1E1FF, boxColour = 0x80808080, bgColour = 0x000000FF, shadow = 2, outline = 0, align = _:td_align_none, font = 1, bool:proportional = false, bool:box = false, time = 0, name[] = "\1");
forward TD_Delete(Style:styleId);

forward Text:TD_Display(text[], Style:id, Float:x = Float:0xFFFFFFFF, Float:y = Float:0xFFFFFFFF);
forward TD_Destroy(Text:textDraw);
forward TD_TextPosition(Text:textID, Float:x, Float:y);
forward TD_TextXPos(Text:textID, Float:x);
forward TD_TextYPos(Text:textID, Float:y);
forward TD_SetString(Text:td, text[]);

forward TD_ShowForPlayer(playerid, Text:textDraw);
forward TD_HideForPlayer(playerid, Text:textDraw);
forward TD_ShowForAll(Text:textDraw);
forward TD_HideForAll(Text:textDraw);
forward Text:TD_DisplayForPlayer(playerid, text[], Style:id, Float:x = Float:0xFFFFFFFF, Float:y = Float:0xFFFFFFFF);
forward Text:TD_DisplayForAll(text[], Style:id, Float:x = Float:0xFFFFFFFF, Float:y = Float:0xFFFFFFFF);

forward TD_StylePosition(Style:styleID, Float:x, Float:y);
forward TD_StyleXPos(Style:styleID, Float:x);
forward TD_StyleYPos(Style:styleID, Float:y);
forward TD_LetterSize(Style:styleID, Float:x, Float:y);
forward TD_LetterX(Style:styleID, Float:x);
forward TD_LetterY(Style:styleID, Float:y);
forward TD_TextSize(Style:styleID, Float:x, Float:y);
forward TD_TextX(Style:styleID, Float:x);
forward TD_TextY(Style:styleID, Float:y);
//forward TD_Alignment(Style:styleID, alignment = _:td_align_none);
forward TD_Colour(Style:styleID, colour);
forward TD_Color(Style:styleID, color);
forward TD_UseBox(Style:styleID, bool:use);
forward TD_BoxColour(Style:styleID, colour);
forward TD_BoxColor(Style:styleID, color);
forward TD_SetShadow(Style:styleID, size);
forward TD_SetOutline(Style:styleID, size);
forward TD_BackgroundColour(Style:styleID, colour);
forward TD_BackgroundColor(Style:styleID, color);
forward TD_Font(Style:styleID, font);
forward TD_SetProportional(Style:styleID, bool:set);
forward TD_SetTime(Style:styleID, time, bool:existing = false);

forward TD_Morph(Text:textDraw, Style:style, time, delay = 0);
forward TD_Link(Text:base, Text:other);
forward TD_Unlink(Text:td);
forward Style:TD_GetDisplayStyle(Text:td);
forward Text:TD_DisplayHashed(text[], hash, Float:x = Float:0xFFFFFFFF, Float:y = Float:0xFFFFFFFF);
forward Text:TD_DisplayHashedForPlayer(playerid, text[], hash, Float:x = Float:0xFFFFFFFF, Float:y = Float:0xFFFFFFFF);
forward Text:TD_DisplayHashedForAll(text[], hash, Float:x = Float:0xFFFFFFFF, Float:y = Float:0xFFFFFFFF);
forward Text:TD_DisplayNamed(text[], style[], Float:x = Float:0xFFFFFFFF, Float:y = Float:0xFFFFFFFF);
forward Text:TD_DisplayNamedForPlayer(playerid, text[], style[], Float:x = Float:0xFFFFFFFF, Float:y = Float:0xFFFFFFFF);
forward Text:TD_DisplayNamedForAll(text[], style[], Float:x = Float:0xFFFFFFFF, Float:y = Float:0xFFFFFFFF);
forward TD_Garbage(Text:textDraw);
forward TD_Parse(filename[]);

forward Style:TD_GetNamed(name[]);
forward Style:TD_GetID(hash);
forward Style:TD_Clone(Style:styleID, name[] = "\1");
//forward TD_GetStyleData(Style:styleID, ret[E_TD_DATA]);
forward TD_Name(Style:styleID, name[]);


//forward __y_testing__();


forward Testing_RunAll();


//forward __y_text__();


//forward formatex(output[], len, const format[], GLOBAL_TAG_TYPES:...)

//forward Text_Send(@PlayerSet:players, message[], {Float, _}:...);

//forward Text_MessageBox(@PlayerSet:players, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);
//forward Text_InputBox(@PlayerSet:players, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);
//forward Text_ListBox(@PlayerSet:players, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);
//forward Text_PasswordBox(@PlayerSet:players, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);
//forward Text_DialogBox(@PlayerSet:players, style, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);


//forward __y_timers__();


//forward __y_users__();


forward Language:Player_GetPreloadLanguage(playerid);
forward Player_IsRegistered(playerid);
forward bool:Player_IsLoggedIn(playerid);
forward Player_GetYID(playerid);

forward Player_RemoveEntry(name[]);
forward Player_WriteString(name[], data[]);
forward Player_WriteArray(const name[], data[], len);
forward Player_WriteInt(name[], data);
forward Player_WriteHex(name[], data);
forward Player_WriteBin(name[], data);
forward Player_WriteBool(name[], bool:data);
forward Player_WriteFloat(name[], Float:data, accuracy = 6);
forward Player_SetTag(tag[]);
forward Player_DeleteTag(tag[]);

forward Player_TryLogin(playerid, password[]);
forward Player_ForceLogin(playerid);
forward Player_TryRegister(playerid, password[]);
forward Player_ChangePassword(playerid, password[]);
forward Player_TryGroup(playerid, other[], password[]);
forward Player_ForceGroup(playerid, other[]);

forward Player_Reload(playerid);
//forward Player_SetPreload(playerid, data[E_USER_PRELOAD]);
//forward Player_Preload(name[], ret[E_USER_PRELOAD]);


//forward __y_utils__();

forward StripNL(str[]);
forward endofline(line[], pos);
forward chrfind(needle, haystack[], start = 0);
forward chrfindp(needle, haystack[], start = 0);
forward bernstein(string[]);
forward ishex(str[]);
forward unpack(const str[]);
forward GetIP(playerid);
forward getstring(addr);
forward getstringarg(addr);
forward isnumeric(str[]);
forward hexstr(string[]);
forward bool:boolstr(string[]);
forward binstr(string[]);
forward memset(dest[], size = sizeof (dest), val = 0, blocksize = 8);
forward ReturnPlayerName(playerid);
forward ftouch(const filename[]);


//forward __y_uvar__();


//forward __y_va__();


forward va_printf(fmat[], va_:STATIC_ARGS);
forward va_format(out[], size, fmat[], va_:STATIC_ARGS);
forward va_strlen(arg);
forward va_getstring(dest[], arg, len = sizeof (dest));


//forward __y_writemem__();


forward WriteMem(addr, value);


//forward __y_xml__();


forward XML:XML_New();
forward XML_Destroy(XML:rule);

forward XML_AddHandler(XML:rule, trigger[], function[]);
forward XML_RemoveHandler(XML:rule, trigger[]);
forward XML_Parse(XML:rule, filename[]);
forward XML_GetKeyValue(key[], value[]);

forward XMLEntry:XML_AddParameter(XMLEntry:parent, tag[], value[] = "");
forward XMLEntry:XML_AddItem(tag[], name[] = "", XMLEntry:parent = XMLEntry:cellmax);
forward XMLEntry:XML_CreateEntry(tag[], name[] = "", XMLEntry:parent = XMLEntry:cellmax);
forward XMLEntry:XML_AddSubEntry(tag[], name[] = "", XMLEntry:parent = XMLEntry:cellmax);
forward XML_WriteItem(filename[], XMLEntry:item, bool:bIncludeXML = true, bool:bFavourShort = false);
forward XML_WriteEntry(filename[], XMLEntry:item, bool:bIncludeXML = true, bool:bFavourShort = false);
forward XML_RemoveItem(file[], tag[], name[]);
forward XML_ReplaceItem(file[], tag[], name[], replacement);


//forward __y_zonepulse__();


//forward GangZonePulse(@PlayerSet:players, zone, from, to, time, delay = ZONE_PULSE_STAGE_TIME, time2 = -1, delay2 = -1);
//forward GangZonePulseForPlayer(playerid, zone, from, to, time, delay = ZONE_PULSE_STAGE_TIME, time2 = -1, delay2 = -1);
//forward GangZonePulseForAll(zone, from, to, time, delay = ZONE_PULSE_STAGE_TIME, time2 = -1, delay2 = -1);
forward GangZoneStopPulse(__ps_addr_t:players, zone);
forward GangZoneStopPulseForPlayer(playerid, zone);
forward GangZoneStopPulseForAll(zone);

#include <YSI\internal\y_version>

/*

native 
native __y_als__();
native 
native 
native 

*/

// CAN'T include by default.
//#include <YSI\y_als>

/*

native 
native __y_amx__();
native 
native 
native AMX_GetBaseCount(E_AMX_TABLE:table, &base, &count);
native AMX_GetGlobalAddress(...);
native AMX_Read(addr);
native AMX_Write(addr, value);
native AMX_ReadString(addr, str[], len = sizeof (str));
native AMX_WriteString(addr, const str[], len = sizeof (str));
native AMX_ReadArray(addr, dest[], len = sizeof (dest));
native AMX_WriteArray(addr, const src[], len = sizeof (src));
native 
native AMX_GetPublicEntry(idx, &buffer, const pattern[] = "");
native AMX_GetNativeEntry(idx, &buffer, const pattern[] = "");
native AMX_GetLibraryEntry(idx, &buffer, const pattern[] = "");
native AMX_GetPubvarEntry(idx, &buffer, const pattern[] = "");
native AMX_GetTagEntry(idx, &buffer, const pattern[] = "");
native AMX_GetEntry(E_AMX_TABLE:table, idx, &buffer, const pattern[] = "");
native 
native AMX_GetPublicEntryPrefix(idx, &buffer, pattern);
native AMX_GetNativeEntryPrefix(idx, &buffer, pattern);
native AMX_GetLibraryEntryPrefix(idx, &buffer, pattern);
native AMX_GetPubvarEntryPrefix(idx, &buffer, pattern);
native AMX_GetTagEntryPrefix(idx, &buffer, pattern);
native AMX_GetEntryPrefix(E_AMX_TABLE:table, idx, &buffer, pattern);
native 
native AMX_GetPublicEntrySuffix(idx, &buffer, pattern);
native AMX_GetNativeEntrySuffix(idx, &buffer, pattern);
native AMX_GetLibraryEntrySuffix(idx, &buffer, pattern);
native AMX_GetPubvarEntrySuffix(idx, &buffer, pattern);
native AMX_GetTagEntrySuffix(idx, &buffer, pattern);
native AMX_GetEntrySuffix(E_AMX_TABLE:table, idx, &buffer, pattern);
native 
native AMX_GetPublicName(idx, buffer[32], const pattern[] = "");
native AMX_GetNativeName(idx, buffer[32], const pattern[] = "");
native AMX_GetLibraryName(idx, buffer[32], const pattern[] = "");
native AMX_GetPubvarName(idx, buffer[32], const pattern[] = "");
native AMX_GetTagName(idx, buffer[32], const pattern[] = "");
native AMX_GetName(E_AMX_TABLE:table, idx, buffer[32], const pattern[] = "");
native 
native AMX_GetPublicNamePrefix(idx, buffer[32], pattern);
native AMX_GetNativeNamePrefix(idx, buffer[32], pattern);
native AMX_GetLibraryNamePrefix(idx, buffer[32], pattern);
native AMX_GetPubvarNamePrefix(idx, buffer[32], pattern);
native AMX_GetTagNamePrefix(idx, buffer[32], pattern);
native AMX_GetNamePrefix(E_AMX_TABLE:table, idx, buffer[32], pattern);
native 
native AMX_GetPublicNameSuffix(idx, buffer[32], pattern);
native AMX_GetNativeNameSuffix(idx, buffer[32], pattern);
native AMX_GetLibraryNameSuffix(idx, buffer[32], pattern);
native AMX_GetPubvarNameSuffix(idx, buffer[32], pattern);
native AMX_GetTagNameSuffix(idx, buffer[32], pattern);
native AMX_GetNameSuffix(E_AMX_TABLE:table, idx, buffer[32], pattern);
native 
native AMX_GetPublicPointer(idx, &buffer, const pattern[] = "");
native AMX_GetNativePointer(idx, &buffer, const pattern[] = "");
native AMX_GetLibraryPointer(idx, &buffer, const pattern[] = "");
native AMX_GetPubvarPointer(idx, &buffer, const pattern[] = "");
native AMX_GetTagPointer(idx, &buffer, const pattern[] = "");
native AMX_GetPointer(E_AMX_TABLE:table, idx, &buffer, const pattern[] = "");
native 
native AMX_GetPublicPointerPrefix(idx, &buffer, pattern);
native AMX_GetNativePointerPrefix(idx, &buffer, pattern);
native AMX_GetLibraryPointerPrefix(idx, &buffer, pattern);
native AMX_GetPubvarPointerPrefix(idx, &buffer, pattern);
native AMX_GetTagPointerPrefix(idx, &buffer, pattern);
native AMX_GetPointerPrefix(E_AMX_TABLE:table, idx, &buffer, pattern);
native 
native AMX_GetPublicPointerSuffix(idx, &buffer, pattern);
native AMX_GetNativePointerSuffix(idx, &buffer, pattern);
native AMX_GetLibraryPointerSuffix(idx, &buffer, pattern);
native AMX_GetPubvarPointerSuffix(idx, &buffer, pattern);
native AMX_GetTagPointerSuffix(idx, &buffer, pattern);
native AMX_GetPointerSuffix(E_AMX_TABLE:table, idx, &buffer, pattern);
native 
native AMX_GetPublicValue(idx, &buffer, const pattern[] = "");
native AMX_GetNativeValue(idx, &buffer, const pattern[] = "");
native AMX_GetLibraryValue(idx, &buffer, const pattern[] = "");
native AMX_GetPubvarValue(idx, &buffer, const pattern[] = "");
native AMX_GetTagValue(idx, &buffer, const pattern[] = "");
native AMX_GetValue(E_AMX_TABLE:table, idx, &buffer, const pattern[] = "");
native 
native AMX_GetPublicValuePrefix(idx, &buffer, pattern);
native AMX_GetNativeValuePrefix(idx, &buffer, pattern);
native AMX_GetLibraryValuePrefix(idx, &buffer, pattern);
native AMX_GetPubvarValuePrefix(idx, &buffer, pattern);
native AMX_GetTagValuePrefix(idx, &buffer, pattern);
native AMX_GetValuePrefix(E_AMX_TABLE:table, idx, &buffer, pattern);
native 
native AMX_GetPublicValueSuffix(idx, &buffer, pattern);
native AMX_GetNativeValueSuffix(idx, &buffer, pattern);
native AMX_GetLibraryValueSuffix(idx, &buffer, pattern);
native AMX_GetPubvarValueSuffix(idx, &buffer, pattern);
native AMX_GetTagValueSuffix(idx, &buffer, pattern);
native AMX_GetValueSuffix(E_AMX_TABLE:table, idx, &buffer, pattern);
native 

*/

#include <YSI\y_amx>

/*

native 
native __y_areas__();
native 
native 
native Area_AddCube(Float:x0, Float:y0, Float:z0, Float:x1, Float:y1, Float:z1);
native Area_AddBox(Float:minx, Float:miny, Float:maxx, Float:maxy);
native Area_AddCircle(Float:x, Float:y, Float:r, Float:h = FLOAT_INFINITY);
native Area_AddSphere(Float:x, Float:y, Float:z, Float:r);
native Area_AddPoly(Float:x1, Float:y1, Float:x2, Float:y2, Float:x3, Float:y3, Float:...);
native Area_Delete(area);
native Area_GetPlayerArea(playerid);
native Area_SetPlayer(area, playerid, bool:set);
native bool:Area_GetPlayer(area, playerid);
native Area_SetAllPlayers(area, bool:set);
native Area_SetWorld(area, world, bool:set);
native bool:Area_GetWorld(area, world);
native Area_SetAllWorlds(area, bool:set);
native bool:Area_IsValid(area);
native bool:Area_IsEmpty(area);
native 

*/

#include <YSI\y_areas>

/*

native 
native __y_bintree__();
native 
native 
native Bintree_Generate(BinaryTree:output<>, input[][E_BINTREE_INPUT], size);
native Bintree_Reset(BinaryTree:tree<>, pointer = 0);
native Bintree_FindValue(BinaryTree:tree<>, value, &cont = 0, &old = 0);
native Bintree_Add(BinaryTree:data<>, pointer, value, offset, maxsize = sizeof (data));
native Bintree_Delete(BinaryTree:source<>, index, count);
native Bintree_UpdatePointers(BinaryTree:data<>, offset, size, mod = -1);
native 

*/

#include <YSI\y_bintree>

/*

native 
native __y_bit__();
native 
native 
native Bit_Set(BitArray:array<>, slot, bool:set);
native Bit_SetAll(BitArray:array<>, bool:set, size = sizeof (array));
native Bit_Get(BitArray:array<>, slot);
native Bit_Let(BitArray:array<>, slot);
native Bit_Vet(BitArray:array<>, slot);
native Bit_Slot(value);
native Bit_Mask(value);
native Bit_GetCount(BitArray:array<>, size = sizeof (array));
native Bit_Display(BitArray:array<>, size = sizeof (array));
native Iterator:Bits(BitArray:array<>);
native Iterator:Blanks(BitArray:array<>);
native 
native bits();
native bitsof();
native 

*/

#include <YSI\y_bit>

/*

native 
native __y_cell__();
native 
native 
native Cell_ReverseBits(GLOBAL_TAG_TYPES:data);
native Cell_ReverseNibbles(GLOBAL_TAG_TYPES:data);
native Cell_ReverseBytes(GLOBAL_TAG_TYPES:data);
native Cell_CountBits(GLOBAL_TAG_TYPES:data);
native Cell_GetLowestBit(GLOBAL_TAG_TYPES:data);
native Cell_GetLowestComponent(GLOBAL_TAG_TYPES:data);
native 

*/

#include <YSI\y_cell>

/*

native 
native __y_classes__();
native 
native 
native Class_Add(skin, Float:x, Float:y, Float:z, Float:a, ...);
native 
native Class_AddEx(Group:forgroup, Group:setgroup, skin, Float:x, Float:y, Float:z, Float:a, ...);
native Class_AddForGroup(Group:group, skin, Float:x, Float:y, Float:z, Float:a, ...);
native Class_AddWithGroupSet(Group:group, skin, Float:x, Float:y, Float:z, Float:a, ...);
native Class_Enable(classid, bool:toggle);
native Class_Delete(classid);
native Class_SetPlayer(classid, playerid, bool:s);
native bool:Class_GetPlayer(classid, playerid);
native Class_Get(playerid);
native Class_Goto(playerid, playerclass);
native 
native Class_DisableSelection(playerid);
native Class_DisableReselection(playerid);
native Class_EnableReselection(playerid);
native Class_ForceReselection(playerid);
native Class_ReturnToSelection(playerid);
native 

*/

#include <YSI\y_classes>

/*

native 
native __y_colours__();
native __y_colors__();
native 
native 
native SetColoursCanHaveSpaces(bool:set);
native SetColour(const name[], color);
native SetColourHash(hash, color);
native GetColour(const name[], alpha = 0xAA);
native GetColourStream(const str[], &idx, alpha = 0xAA);
native GetColourHash(hash, alpha = 0xAA);
native 

*/

#include <YSI\y_colours>

/*

native 
native __y_commands__();
native 
native 
native Command_AddAlt(commandid, altname[]);
native Command_AddAltNamed(command[], altname[]);
native Command_SetPlayer(commandid, playerid, bool:set);
native Command_SetPlayerNamed(command[], playerid, bool:set);
native 
native Command_SetDeniedReturn(bool:set);
native bool:Command_GetDeniedReturn();
native Command_SetIllegalReturn(bool:set);
native bool:Command_GetIllegalReturn();
native Command_SetUnknownReturn(bool:set);
native bool:Command_GetUnknownReturn();
native Command_SetDisconnectReturn(bool:set);
native bool:Command_GetDisconnectReturn();
native 
native Command_GetID(command[]);
native bool:Command_GetPlayer(commandid, playerid);
native bool:Command_GetPlayerNamed(command[], playerid);
native Command_Remove(commandid);
native Command_RemoveNamed(command[]);
native Command_ReProcess(playerid, cmdtext[], help);
native Command_GetName(commandid);
native Command_GetDisplay(commandid, playerid);
native Command_GetDisplayNamed(command[], playerid);
native Command_GetPlayerCommandCount(playerid);
native Command_GetNext(index, playerid);
native 
native Command_SetProvider(p);
native Command_GetProvider();
native Command_SetPlayerProvider(playerid, p);
native Command_GetPlayerProvider(playerid);
native 

*/

#include <YSI\y_commands>

/*

native 
native __y_debug__();
native 
native 
native P_level(str[], {Float, _}:...);
native P_I(str[], {Float, _}:...);
native P_W(str[], {Float, _}:...);
native P_E(str[], {Float, _}:...);
native P_F(str[], {Float, _}:...);
native P_C(str[], {Float, _}:...);
native 

*/

#include <YSI\y_debug>

/*

native 
native __y_dialog__();
native 
native 
native Dialog_Show(playerid, style, title[], caption[], button1[], button2[] = "", dialogid = -1);
native Dialog_ShowCallback(playerid, using:callback[], style, title[], caption[], button1[], button2[] = "", dialogid = -1);
native 
native Dialog_ObtainID();
native Dialog_TryObtainID(id);
native Dialog_Get(playerid);
native Dialog_Garbage(dialogid);
native Dialog_Free(dialogid);
native Dialog_Set(playerid, dialogid);
native Dialog_ShowCallbackData(playerid, callback[E_CALLBACK_DATA], style, title[], caption[], button1[], button2[] = "", dialogid = -1);
native Dialog_Hide(playerid);
native Dialog_SetCallback(dialogid, using:callback[]);
native Dialog_SetCallbackData(dialogid, callback[E_CALLBACK_DATA]);
native 

*/

#include <YSI\y_dialog>

/*

native 
native __y_flooding__();
native 
native 
native SetMaxConnections(max = -1, e_FLOOD_ACTION:action = e_FLOOD_ACTION_BLOCK);
native 

*/

#include <YSI\y_flooding>

/*

native 
native __y_groups__();
native 
native 
native Group:Group_Create(name[]);
native Group_Destroy(Group:group);
native Group_SetPlayer(Group:group, playerid, bool:s);
native bool:Group_GetPlayer(Group:group, playerid);
native 
native Group_SetCommand(Group:group, commandid, bool:s);
native Group_SetCommandDefault(Group:group, bool:s);
native Group_SetGlobalCommand(commandid, bool:s);
native Group_SetGlobalCommandDefault(bool:s);
native 
native Group_SetArea(Group:group, area, bool:s);
native Group_SetAreaDefault(Group:group, bool:s);
native Group_SetGlobalArea(area, bool:s);
native Group_SetGlobalAreaDefault(bool:s);
native 
native Group_SetClass(Group:group, class, bool:s);
native Group_SetClassDefault(Group:group, bool:s);
native Group_SetGlobalClass(class, bool:s);
native Group_SetGlobalCalssDefault(bool:s);
native 
native Iterator:PlayerGroups(playerid);
native Iterator:Group(Group:group);
native 
native Group:Group_SetBalanced(playerid, Group:...);
native Group_GetColour(Group:group);
native Group_GetColor(Group:group);
native Group_SetColour(Group:group, colour);
native Group_SetColor(Group:group, color);
native bool:Group_GetGang(Group:group);
native Group_SetGang(Group:group, bool:set);
native Group:Group_GetID(name[]);
native Group_GetName(Group:group);
native Group_SetName(Group:group, name[]);
native 

*/

#include <YSI\y_groups>

/*

native 
native __y_hooks__();
native 
native 
native hook();
native 

*/

// Is included as then they can use hooks straight off.
#include <YSI\y_hooks>

/*

native 
native __y_ini__();
native 
native 
native bool:INI_ParseFile(fname[], remoteFormat[], bool:bFileFirst = false, bool:bExtra = false, extra = 0, bool:bLocal = true, bool:bPassTag = false, bool:bFilter = true, filter[] = "");
native bool:INI_Load(filename[], bool:bExtra = false, extra = 0, bool:bLocal = true);
native 
native INI_Int(name[], &dest);
native INI_Float(name[], &Float:dest);
native INI_Hex(name[], &dest);
native INI_Bin(name[], &dest);
native INI_String(name[], dest[], size);
native 
native INI:INI_Open(filename[]);
native INI_Close(INI:file);
native 
native INI_SetTag(INI:file, tag[]);
native INI_DeleteTag(INI:file, tag[]);
native INI_WriteArray(INI:file, const name[], data[], len);
native INI_RemoveEntry(INI:file, name[]);
native INI_WriteString(INI:file, name[], data[]);
native INI_WriteInt(INI:file, name[], data);
native INI_WriteHex(INI:file, name[], data);
native INI_WriteBin(INI:file, name[], data);
native INI_WriteBool(INI:file, name[], bool:data);
native INI_WriteFloat(INI:file, name[], Float:data, accuracy = 6);
native 

*/

#include <YSI\y_ini>

/*

native 
native __y_inline__();
native 
native 
native using();
native inline();
native 
native Callback_Get(callback:name, result[E_CALLBACK_DATA], expect = -1);
native Callback_Release(const input[E_CALLBACK_DATA]);
native Callback_Call(const input[E_CALLBACK_DATA], {Float, _}:...);
native 

*/

#include <YSI\y_inline>

/*

native 
native __y_iterate__();
native 
native 
native Iter_Init(Iterator:arr[]<>);
native Iter_Add(Iterator:iter<>, element);
native Iter_Remove(Iterator:iter<>, element);
native Iter_Contains(Iterator:iter<>, element);
native Iter_SafeRemove(Iterator:iter<>, element, &ret);
native Iter_Random(Iterator:iter<>);
native Iter_Count(Iterator:iter<>);
native Iter_Clear(Iterator:iter<>);
native Iter_Free(Iterator:iter<>);
native 
native foreach();
native 
native Iter_Begin(Iterator:iter<>);
native Iter_End(Iterator:iter<>);
native Iter_First(Iterator:iter<>);
native Iter_Last(Iterator:iter<>);
native Iter_Next(Iterator:iter<>, cur);
native Iter_Prev(Iterator:iter<>, cur);
native 

*/

#include <YSI\y_iterate>

/*

native 
native __y_languages__();
native 
native 
native Language:Langs_Add(code[], name[]);
native Language:Langs_SetPlayerLanguage(playerid, Language:l);
native Language:Langs_GetPlayerLanguage(playerid);
native 
native Language:Langs_AddLanguage(code[], name[]);
native Langs_RemoveLanguage(Language:l);
native Language:Langs_GetLanguage(identifier[]);
native Language:Langs_GetLanguageCount();
native Langs_GetLanguageCodes();
native Langs_GetName(Language:l);
native Langs_GetCode(Language:l);
native bool:Langs_IsValid(Language:l);
native Language:Langs_SetPlayerCode(playerid, code[]);
native 

*/

#include <YSI\y_languages>

/*

native 
native __y_lock__();
native 
native 
native 

*/

// DO NOT include by default!
//#include <YSI\y_lock>

/*

native 
native __y_malloc__();
native 
native 
native Alloc:malloc(size);
native Alloc:calloc(size);
native free(Alloc:slot);
native 
native mget(Alloc:array, index);
native mset(Alloc:array, index, value);
native mgets(target[], length, Alloc:array, index);
native msets(Alloc:array, index, const str[]);
native 
native Malloc_SlotSize(Alloc:array);
native Malloc_Get(Alloc:array, index);
native Malloc_Set(Alloc:array, index, value);
native Malloc_GetS(target[], length, Alloc:array, index);
native Malloc_SetS(Alloc:array, index, const str[]);
native Malloc_GetA(target[], length, Alloc:array, index);
native Malloc_SetA(Alloc:array, index, const arr[], len);
native 

*/

#include <YSI\y_malloc>

/*

native 
native __y_master__();
native 
native 
native Master_Caller();
native 
native foreign();
native global();
native 

*/

#include <YSI\y_master>

/*

native 
native __y_php__();
native 
native 
native PHP_SendString(string:name[], string:value[], bool:priority = false);
native PHP_SendFloat(string:name[], Float:value, bool:priority = false);
native PHP_SendBool(string:name[], bool:value, bool:priority = false);
native PHP_SendInt(string:name[], value, bool:priority = false);
native 
native phpdata();
native phpfunc();
native 

*/

// DO NOT include by default!
//#include <YSI\y_php>

/*

native 
native __y_playerarray__();
native 
native 
native PA_Init(PlayerArray:pa<>, bool:init = false, s = bits<MAX_PLAYERS>);
native PA_FastInit(PlayerArray:pa<>);
native PA_Set(PlayerArray:pa<>, slot, bool:set);
native PA_Let(PlayerArray:pa<>, slot);
native PA_Vet(PlayerArray:pa<>, slot);
native PA_Get(PlayerArray:pa<>, slot);
native PA_GetCount(PlayerArray:pa<>);
native Iterator:PA(PlayerArray:pa<>);
native 

*/

#include <YSI\y_playerarray>

/*

native 
native __y_playerset__();
native 
native 
native Iterator:PS(@PlayerSet:iter);
native 

*/

#include <YSI\y_playerset>

/*

native 
native __y_remote__();
native 
native 
native remotefunc();
native broadcastfunc();
native localfunc();
native targetfunc();
native 

*/

#include <YSI\y_remote>

/*

native 
native __y_scriptinit__();
native 
native 
native 

*/

#include <YSI\y_scriptinit>

/*

native 
native __y_stringhash__();
native 
native 
native YHash(const str[], bool:sensitive = true, e_HASH_TYPE:type = hash_bernstein, len = -1, pack = false);
native 

*/

#include <YSI\y_stringhash>

/*

native 
native __y_svar__();
native 
native 
native svar();
native 

*/

#include <YSI\y_svar>

/*

native 
native __y_td__();
native 
native 
native Style:TD_Create(Float:x = 0.0, Float:y = 0.0, Float:letterX = 0.48, Float:letterY = 1.12, Float:textX = 1280.0, Float:textY = 1280.0, colour = 0xE1E1E1FF, boxColour = 0x80808080, bgColour = 0x000000FF, shadow = 2, outline = 0, align = _:td_align_none, font = 1, bool:proportional = false, bool:box = false, time = 0, name[] = "\1");
native TD_Delete(Style:styleId);
native 
native Text:TD_Display(text[], Style:id, Float:x = NAN, Float:y = NAN);
native TD_Destroy(Text:textDraw);
native TD_TextPosition(Text:textID, Float:x, Float:y);
native TD_TextXPos(Text:textID, Float:x);
native TD_TextYPos(Text:textID, Float:y);
native TD_SetString(Text:td, text[]);
native 
native TD_ShowForPlayer(playerid, Text:textDraw);
native TD_HideForPlayer(playerid, Text:textDraw);
native TD_ShowForAll(Text:textDraw);
native TD_HideForAll(Text:textDraw);
native Text:TD_DisplayForPlayer(playerid, text[], Style:id, Float:x = NAN, Float:y = NAN);
native Text:TD_DisplayForAll(text[], Style:id, Float:x = NAN, Float:y = NAN);
native 
native TD_StylePosition(Style:styleID, Float:x, Float:y);
native TD_StyleXPos(Style:styleID, Float:x);
native TD_StyleYPos(Style:styleID, Float:y);
native TD_LetterSize(Style:styleID, Float:x, Float:y);
native TD_LetterX(Style:styleID, Float:x);
native TD_LetterY(Style:styleID, Float:y);
native TD_TextSize(Style:styleID, Float:x, Float:y);
native TD_TextX(Style:styleID, Float:x);
native TD_TextY(Style:styleID, Float:y);
native TD_Alignment(Style:styleID, alignment = _:td_align_none);
native TD_Colour(Style:styleID, colour);
native TD_Color(Style:styleID, color);
native TD_UseBox(Style:styleID, bool:use);
native TD_BoxColour(Style:styleID, colour);
native TD_BoxColor(Style:styleID, color);
native TD_SetShadow(Style:styleID, size);
native TD_SetOutline(Style:styleID, size);
native TD_BackgroundColour(Style:styleID, colour);
native TD_BackgroundColor(Style:styleID, color);
native TD_Font(Style:styleID, font);
native TD_SetProportional(Style:styleID, bool:set);
native TD_SetTime(Style:styleID, time, bool:existing = false);
native 
native TD_Morph(Text:textDraw, Style:style, time, delay = 0);
native TD_Link(Text:base, Text:other);
native TD_Unlink(Text:td);
native Style:TD_GetDisplayStyle(Text:td);
native Text:TD_DisplayHashed(text[], hash, Float:x = NAN, Float:y = NAN);
native Text:TD_DisplayHashedForPlayer(playerid, text[], hash, Float:x = NAN, Float:y = NAN);
native Text:TD_DisplayHashedForAll(text[], hash, Float:x = NAN, Float:y = NAN);
native Text:TD_DisplayNamed(text[], style[], Float:x = NAN, Float:y = NAN);
native Text:TD_DisplayNamedForPlayer(playerid, text[], style[], Float:x = NAN, Float:y = NAN);
native Text:TD_DisplayNamedForAll(text[], style[], Float:x = NAN, Float:y = NAN);
native TD_Garbage(Text:textDraw);
native TD_Parse(filename[]);
native 
native Style:TD_GetNamed(name[]);
native Style:TD_GetID(hash);
native Style:TD_Clone(Style:styleID, name[] = "\1");
native TD_GetStyleData(Style:styleID, ret[E_TD_DATA]);
native TD_Name(Style:styleID, name[]);
native 

*/

#include <YSI\y_td>

/*

native 
native __y_testing__();
native 
native 
native Testing_RunAll();
native 

*/

// DO NOT include by default!
//#include <YSI\y_testing>

/*

native 
native __y_text__();
native 
native 
native Text_Send(@PlayerSet:players, message[], {Float, _}:...);
native 
native Text_MessageBox(@PlayerSet:players, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);
native Text_InputBox(@PlayerSet:players, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);
native Text_ListBox(@PlayerSet:players, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);
native Text_PasswordBox(@PlayerSet:players, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);
native Text_DialogBox(@PlayerSet:players, style, using:callback[], title[], text[], button1[], button2[], {Float, _}:...);
native 

*/

#include <YSI\y_text>

/*

native 
native __y_timers__();
native 
native 
native stop();
native defer();
native repeat();
native timer();
native task();
native ptask();
native pause();
native resume();
native 

*/

#include <YSI\y_timers>

/*

native 
native __y_users__();
native 
native 
native Language:Player_GetPreloadLanguage(playerid);
native Player_IsRegistered(playerid);
native bool:Player_IsLoggedIn(playerid);
native Player_GetYID(playerid);
native 
native Player_RemoveEntry(name[]);
native Player_WriteString(name[], data[]);
native Player_WriteArray(const name[], data[], len);
native Player_WriteInt(name[], data);
native Player_WriteHex(name[], data);
native Player_WriteBin(name[], data);
native Player_WriteBool(name[], bool:data);
native Player_WriteFloat(name[], Float:data, accuracy = 6);
native Player_SetTag(tag[]);
native Player_DeleteTag(tag[]);
native 
native Player_TryLogin(playerid, password[]);
native Player_ForceLogin(playerid);
native Player_TryRegister(playerid, password[]);
native Player_ChangePassword(playerid, password[]);
native Player_TryGroup(playerid, other[], password[]);
native Player_ForceGroup(playerid, other[]);
native 
native Player_Reload(playerid);
native Player_SetPreload(playerid, data[E_USER_PRELOAD]);
native Player_Preload(name[], ret[E_USER_PRELOAD]);
native 

*/

#include <YSI\y_users>

/*

native 
native __y_utils__();
native 
native 
native ceildiv(num, denom);
native floordiv(num, denom);
native isnull(str[]);
native isodd(num);
native iseven(num);
native strcpy(dest[], src[], maxlength = sizeof (dest));
native StripNL(str[]);
native endofline(line[], pos);
native chrfind(needle, haystack[], start = 0);
native chrfindp(needle, haystack[], start = 0);
native bernstein(string[]);
native ishex(str[]);
native unpack(const str[]);
native GetIP(playerid);
native getstring(addr);
native getstringarg(addr);
native isnumeric(str[]);
native hexstr(string[]);
native bool:boolstr(string[]);
native binstr(string[]);
native memset(dest[], size = sizeof (dest), val = 0, blocksize = 8);
native ReturnPlayerName(playerid);
native ftouch(const filename[]);
native 

*/

#include <YSI\y_utils>

/*

native 
native __y_uvar__();
native 
native 
native uvar();
native 

*/

#include <YSI\y_uvar>

/*

native 
native __y_va__();
native 
native 
native va_printf(fmat[], va_start);
native va_format(out[], size, fmat[], va_start);
native va_strlen(arg);
native va_getstring(dest[], arg, len = sizeof (dest));
native 

*/

#include <YSI\y_va>

/*

native 
native __y_writemem__();
native 
native 
native WriteMem(addr, value);
native 

*/

#include <YSI\y_writemem>

/*

native 
native __y_xml__();
native 
native 
native XML:XML_New();
native XML_Destroy(XML:rule);
native 
native XML_AddHandler(XML:rule, trigger[], function[]);
native XML_RemoveHandler(XML:rule, trigger[]);
native XML_Parse(XML:rule, filename[]);
native XML_GetKeyValue(key[], value[]);
native 
native XMLEntry:XML_AddParameter(XMLEntry:parent, tag[], value[] = "");
native XMLEntry:XML_AddItem(tag[], name[] = "", XMLEntry:parent = XMLEntry:cellmax);
native XMLEntry:XML_CreateEntry(tag[], name[] = "", XMLEntry:parent = XMLEntry:cellmax);
native XMLEntry:XML_AddSubEntry(tag[], name[] = "", XMLEntry:parent = XMLEntry:cellmax);
native XML_WriteItem(filename[], XMLEntry:item, bool:bIncludeXML = true, bool:bFavourShort = false);
native XML_WriteEntry(filename[], XMLEntry:item, bool:bIncludeXML = true, bool:bFavourShort = false);
native XML_RemoveItem(file[], tag[], name[]);
native XML_ReplaceItem(file[], tag[], name[], replacement);
native 

*/

#include <YSI\y_xml>

/*

native 
native __y_zonepulse__();
native 
native 
native GangZonePulse(@PlayerSet:players, zone, from, to, time, delay = ZONE_PULSE_STAGE_TIME, time2 = -1, delay2 = -1);
native GangZonePulseForPlayer(playerid, zone, from, to, time, delay = ZONE_PULSE_STAGE_TIME, time2 = -1, delay2 = -1);
native GangZonePulseForAll(zone, from, to, time, delay = ZONE_PULSE_STAGE_TIME, time2 = -1, delay2 = -1);
native GangZoneStopPulse(@PlayerSet:players, zone);
native GangZoneStopPulseForPlayer(playerid, zone);
native GangZoneStopPulseForAll(zone);
native 

*/

#include <YSI\y_zonepulse>

/*----------------------------------------------------------------------------*\
Function:
	OnScriptInit
Params:
	-
Return:
	-
Notes:
	Called when the script first starts, regardless of what type it is.
\*----------------------------------------------------------------------------*/

forward OnScriptInit();

/*----------------------------------------------------------------------------*\
Function:
	OnScriptExit
Params:
	-
Return:
	-
Notes:
	Called when the script ends, regardless of what type it is.
\*----------------------------------------------------------------------------*/

forward OnScriptExit();

/*----------------------------------------------------------------------------*\
Function:
	OnPlayerEnterArea
Params:
	playerid - The player who entered an area.
	areaid - The area they entered.
Return:
	-
Notes:
	Currently this does not support overlapping areas, but there's no reason why
	it can't in the future.
\*----------------------------------------------------------------------------*/

forward OnPlayerEnterArea(playerid, areaid);

/*----------------------------------------------------------------------------*\
Function:
	OnPlayerLeaveArea
Params:
	playerid - The player who left an area.
	areaid - The area they left.
Return:
	-
Notes:
	Currently this does not support overlapping areas, but there's no reason why
	it can't in the future.
\*----------------------------------------------------------------------------*/

forward OnPlayerLeaveArea(playerid, areaid);

/*----------------------------------------------------------------------------*\
Function:
	OnPlayerCommandReceived
Params:
	playerid - The player who typed a command.
	cmdtext[] - The command text they entered.
Return:
	-1 - Don't process the command and instead show a message.
	0 - Don't process the command and don't show a message.
	1 - Process the command.
Notes:
	Called before the command is processed.
\*----------------------------------------------------------------------------*/

forward OnPlayerCommandReceived(playerid, cmdtext[]);

/*----------------------------------------------------------------------------*\
Function:
	OnPlayerCommandPerformed
Params:
	playerid - The player who ran a command.
	cmdtext[] - The command text they entered.
	success - Did the command run?
Return:
	-1 - Return "success" from OnPlayerCommandText.
	0 - Return 0 from OnPlayerCommandText.
	1 - Return 1 from OnPlayerCommandText.
Notes:
	Called after the command is processed, and passed the command's return.
\*----------------------------------------------------------------------------*/

forward OnPlayerCommandPerformed(playerid, cmdtext[], success);

/*----------------------------------------------------------------------------*\
Function:
	OnPlayerLogin
Params:
	playerid - The player who logged in.
	yid - Their globally unique ID (on this server).
Return:
	-
Notes:
	The "yid" parameter is unique to each player registerd on a server, and
	corresponds to their data file.  Note that one user can have multiple nicks.
\*----------------------------------------------------------------------------*/

forward OnPlayerLogin(playerid, yid);

/*----------------------------------------------------------------------------*\
Function:
	OnPlayerLogout
Params:
	playerid - The player who logged out (usually on disconnect).
	yid - Their globally unique ID (on this server).
Return:
	-
Notes:
	The "yid" parameter is unique to each player registerd on a server, and
	corresponds to their data file.  Note that one user can have multiple nicks.
\*----------------------------------------------------------------------------*/

forward OnPlayerLogout(playerid, yid);
