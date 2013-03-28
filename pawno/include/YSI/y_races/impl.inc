/**--------------------------------------------------------------------------**\
					==============================
					 y_hooks - Hook any callback!
					==============================
Description:
	Automatically hooks any callbacks with a very simple syntax.
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
	
	The Original Code is the SA:MP callback hooks include.
	
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright (C) 2008
	the Initial Developer. All Rights Reserved.
	
	Contributors:
		ZeeX, koolk, JoeBullet/Google63, g_aSlice/Slice
	
	Thanks:
		JoeBullet/Google63 - Handy arbitrary ASM jump code using SCTRL.
		Peter, Cam - Support.
		ZeeX, g_aSlice/Slice, Popz, others - Very productive conversations.
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
	2.0
Changelog:
	27/03/13:
		Ported to the new YSI version.
	09/01/08:
		Added a fix for IsPlayerInRaceCheckpoint.
	11/10/07:
		Added race start count option.
	03/08/07:
		Updated timer system.
	02/08/07:
		Fixed repeating races.
	31/07/07:
		Added tracking support.
	21/06/07:
		Added restart option to races to not destroy them.
	02/05/07:
		Added YSI_ prefix to all globals.
	01/05/07:
		First version.
\**--------------------------------------------------------------------------**/

#include "y_bit"
#include "y_iterate"
#include "y_playerarray"
#include "y_text"
#if defined RACE_POSITION
	#include "y_timers"
#endif
#include "y_hooks"

#define MAX_RACE_WINNERS 3

#if !defined MAX_RACES
	#define MAX_RACES 16
#endif

#if !defined MAX_RACE_CHECKPOINTS
	#define MAX_RACE_CHECKPOINTS 1024
#endif

#if !defined MAX_RACE_STARTS
	#define MAX_RACE_STARTS 32//MAX_PLAYERS
#endif

#define NO_RACE -1
#define RACE_NO_CHECKPOINT -1
#define RACE_LOOP_GRANULARITY 5
#define RACE_PLAYER_OUT 0x80000000

enum e_RACE_FLAGS (<<= 1)
{
	e_RACE_FLAGS_EXIT_TIME = 0xFFFF,
	e_RACE_FLAGS_ACTIVE = 0x10000,
	e_RACE_FLAGS_ARIAL,
	e_RACE_FLAGS_REL_WIN,
	e_RACE_FLAGS_STARTED,
	e_RACE_FLAGS_RACING,
	e_RACE_FLAGS_CD_JOIN,
	e_RACE_FLAGS_RESTART
}

enum E_RACE
{
	e_RACE_FLAGS:E_RACE_FLAGS,
	E_RACE_LAPS,
	E_RACE_CHECKPOINTS,
	E_RACE_CP_START,
	E_RACE_RACER_COUNT,
	E_RACE_RACER_MAX,
	//PlayerArray:E_RACE_RACERS<MAX_PLAYERS>,
	E_RACE_COUNTDOWN,
	E_RACE_FINISHED,
	E_RACE_ENTRY,
	E_RACE_VW,
	E_RACE_INT,
	E_RACE_PRIZES[MAX_RACE_WINNERS]
}

enum E_RACE_PLAYER
{
	E_RACE_PLAYER_RACE,
	E_RACE_PLAYER_LAP,
	E_RACE_PLAYER_CP,
	E_RACE_PLAYER_TIME,
	#if defined RACE_POSITION
		E_RACE_PLAYER_POSITION,
	#endif
	E_RACE_PLAYER_TOUT,
	Float:E_RACE_PLAYER_X,
	Float:E_RACE_PLAYER_Y,
	Float:E_RACE_PLAYER_Z,
	Float:E_RACE_PLAYER_A,
	E_RACE_PLAYER_INT,
	E_RACE_PLAYER_WORLD
}

#define RACE_POS_DONE 0x80000000

enum E_RACE_POS
{
	//E_RACE_POS_RACE,
	E_RACE_POS_CP,
	//E_RACE_POS_LAP,
	Float:E_RACE_POS_TOGO//,
	//E_RACE_POS_POS
}

_Y_RACES_STATIC stock
	PlayerArray:YSI_g_sRacers[MAX_RACES]<MAX_PLAYERS>,
	YSI_g_sRaceData[MAX_RACES][E_RACE],
	//Float:YSI_g_sRaceCheckpoints[MAX_RACES][MAX_RACE_CHECKPOINTS][3],
	Float:YSI_g_sRaceCheckpoints[MAX_RACE_CHECKPOINTS][3],
	YSI_g_sPlayerRace[MAX_PLAYERS][E_RACE_PLAYER],
	Float:YSI_g_sRaceStarts[MAX_RACES][MAX_RACE_STARTS][4],
	YSI_g_sCPIndex,
	Iterator:YSI_g_sRacePeople[MAX_RACES]<MAX_PLAYERS>;

//#if defined RACE_POSITION
//	forward Race_Loop();
//#endif

forward Race_Countdown(race, time);
forward Race_Timeout(playerid);

loadtext core[ysi_race];

/*----------------------------------------------------------------------------*-
Function:
	RaceArray_IndexShift
Params:
	from - Which slot to start shifting up.
	add - How to adjust the slots.
Return:
	-
Notes:
	Find all races whose checkpoint blocks start above the current index and
	increment them.
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC stock RaceArray_IndexShift(from, add)
{
	for (new i = 0; i != MAX_RACES; ++i)
	{
		if (YSI_g_sRaceData[i][E_RACE_CP_START] >= from) YSI_g_sRaceData[i][E_RACE_CP_START] += add;
	}
}

/*----------------------------------------------------------------------------*-
Function:
	RaceArray_Shift
Params:
	from - Which slot to start shifting up.
	&end - Slot to end the shifting on.
	to - Slot to shift to.
Return:
	-
Notes:
	Shifts checkpoints up in the main array to make room for new ones.
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC stock RaceArray_Shift(from, &end, to)
{
	// Basic version.
	/*if (++to >= MAX_RACE_CHECKPOINTS)
	{
		--to;
		return false;
	}
	for (new i = to; i != from; --i)
	{
		YSI_g_sRaceCheckpoints[0][i] = YSI_g_sRaceCheckpoints[0][i - 1];
	}
	return true;*/
	// Fast version.
	end -= from;
	if (end + to >= MAX_RACE_CHECKPOINTS)
	{
		return false;
	}
	memcpy(_:YSI_g_sRaceCheckpoints[to], _:YSI_g_sRaceCheckpoints[from], 0, end * 4 * 3, end * 3);
	//++to;
	end += to;
	return true;
}

/*----------------------------------------------------------------------------*-
Function:
	RaceArray_Add
Params:
	slot - Slot to add to.
	Float:x - Position data.
	Float:y - Position data.
	Float:z - Position data.
Return:
	-
Notes:
	Adds a new checkpoint to the checkpoints array.
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC stock RaceArray_Add(slot, Float:x, Float:y, Float:z)
{
	if (slot < YSI_g_sCPIndex)
	{
		if (!RaceArray_Shift(slot, YSI_g_sCPIndex, slot + 1)) return false;
		RaceArray_IndexShift(slot, 1);
	}
	YSI_g_sRaceCheckpoints[slot][0] = x;
	YSI_g_sRaceCheckpoints[slot][1] = y;
	YSI_g_sRaceCheckpoints[slot][2] = z;
	return true;
}

/*----------------------------------------------------------------------------*-
Function:
	Race__IsActive
Params:
	raceid - Race to check.
Return:
	-
Notes:
	Checks a race is active.
-*----------------------------------------------------------------------------*/

#define Race__IsActive(%1) \
	(YSI_g_sRaceData[(%1)][E_RACE_FLAGS] & e_RACE_FLAGS_ACTIVE)

/*----------------------------------------------------------------------------*-
Function:
	Race_IsValid
Params:
	raceid - Race to check.
Return:
	-
Notes:
	Checks an id is valid and active.
-*----------------------------------------------------------------------------*/

#define Race_IsValid(%1) \
	(0 <= (%1) < MAX_RACES && Race__IsActive((%1)))

/*----------------------------------------------------------------------------*-
Function:
	Race_Create
Params:
	laps - Number of laps to race for.
	entry - Cost of entry.
	countdown - Time to count down from for start.
	bool:arial - Use arial checkpoints instead.
	bool:fixedPrize - Set prize amounts manually.
	exitTime - Time allowed out a vehicle before fail.
	interior - The interior of the race.
	world - The world of the race.
	bool:restart - Don't destroy the race on completion.
Return:
	raceid - ID of the race for reference or -1.
Notes:
	Finds an empty slot and sets the race up for use.  All
	parameters are optional and can be set separately aswell.
-*----------------------------------------------------------------------------*/

stock Race_Create(laps = 0, entry = 0, countdown = 3, bool:arial = false, bool:fixedPrize = true, exitTime = 0, interior = 0, world = 0, bool:restart = false)
{
	new
		raceid;
	for (raceid = 0; raceid < MAX_RACES; raceid++) if (!Race__IsActive(raceid)) break;
	if (raceid == MAX_RACES) return NO_RACE;
	YSI_g_sRaceData[raceid][E_RACE_FLAGS] = e_RACE_FLAGS_ACTIVE;
	Race_SetLaps(raceid, laps);
	Race_SetEntry(raceid, entry);
	if (fixedPrize) for (new i = 1; i <= MAX_RACE_WINNERS; i++) Race_SetPrize(raceid, (MAX_RACE_WINNERS + 1) - i, entry * i);
	Race_SetFixedWin(raceid, _:fixedPrize);
	Race_SetArial(raceid, _:arial);
	Race_SetActive(raceid, 1);
	Race_SetCountdown(raceid, countdown);
	Race_SetExitTime(raceid, exitTime);
	Race_SetInterior(raceid, interior);
	Race_SetWorld(raceid, world);
	Race_SetRestart(raceid, _:restart);
	YSI_g_sRaceData[raceid][E_RACE_CHECKPOINTS] = 0;
	YSI_g_sRaceData[raceid][E_RACE_RACER_COUNT] = 0;
	YSI_g_sRaceData[raceid][E_RACE_FINISHED] = 0;
	YSI_g_sRaceData[raceid][E_RACE_RACER_MAX] = 0;
	PA_Init(YSI_g_sRacers[raceid]);
	Iter_Clear(YSI_g_sRacePeople[raceid]);
	YSI_g_sRaceData[raceid][E_RACE_CP_START] = YSI_g_sCPIndex;
	return raceid;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Destroy
Params:
	slot - Race to destroy.
	bool:refund - Should entrants get their money back?
Return:
	-
Notes:
	Called whenever a player leaves the race, checks the
	number of remaining racers and if none ends the race.
-*----------------------------------------------------------------------------*/

stock Race_Destroy(slot, bool:refund = false)
{
	if (Race_IsValid(slot))
	{
		if (YSI_g_sRaceData[slot][E_RACE_FLAGS] & e_RACE_FLAGS_STARTED)
		{
			foreach (new i : Player)
			{
				if (PA_Get(YSI_g_sRacers[slot], i))
				{
					DisablePlayerRaceCheckpoint(i);
					Race_PlayerDone(i);
				}
			}
		}
		else
		{
			foreach (new i : Player)
			{
				if (PA_Get(YSI_g_sRacers[slot], i))
				{
					Race_PlayerLeave(i, refund);
				}
			}
		}
		YSI_g_sRaceData[slot][E_RACE_RACER_COUNT] = 0;
		YSI_g_sRaceData[slot][E_RACE_FLAGS] = e_RACE_FLAGS:0;
		new
			count = YSI_g_sRaceData[slot][E_RACE_CHECKPOINTS],
			start = YSI_g_sRaceData[slot][E_RACE_CP_START];
		RaceArray_Shift(start + count, YSI_g_sCPIndex, start);
		RaceArray_IndexShift(start, -count);
	}
}

/*----------------------------------------------------------------------------*-
Function:
	Race_AddCheckpoint
Params:
	raceid - Race to add to.
	Float:x - X position.
	Float:y - Y position.
	Float:z - Z position.
Return:
	position or -1.
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Race_AddCheckpoint(raceid, Float:x, Float:y, Float:z)
{
	if (!Race_IsValid(raceid)) return RACE_NO_CHECKPOINT;
	new
		count = YSI_g_sRaceData[raceid][E_RACE_CHECKPOINTS];
	/*if (count >= MAX_RACE_CHECKPOINTS) return RACE_NO_CHECKPOINT;
	YSI_g_sRaceCheckpoints[raceid][count][0] = x;
	YSI_g_sRaceCheckpoints[raceid][count][1] = y;
	YSI_g_sRaceCheckpoints[raceid][count][2] = z;*/
	RaceArray_Add(YSI_g_sRaceData[raceid][E_RACE_CP_START] + count, x, y, z);
	YSI_g_sRaceData[raceid][E_RACE_CHECKPOINTS]++;
	return count;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_AddStart
Params:
	raceid - Race to add to.
	Float:x - X position.
	Float:y - Y position.
	Float:z - Z position.
	Float:a - Angle.
Return:
	position or -1.
Notes:
	Adds a starting point to a race and increases the max
	number of racers for the race.
-*----------------------------------------------------------------------------*/

stock Race_AddStart(raceid, Float:x, Float:y, Float:z, Float:a)
{
	if (!Race_IsValid(raceid)) return RACE_NO_CHECKPOINT;
	new
		count = YSI_g_sRaceData[raceid][E_RACE_RACER_MAX];
	if (count >= MAX_RACE_STARTS) return RACE_NO_CHECKPOINT;
	YSI_g_sRaceStarts[raceid][count][0] = x;
	YSI_g_sRaceStarts[raceid][count][1] = y;
	YSI_g_sRaceStarts[raceid][count][2] = z;
	YSI_g_sRaceStarts[raceid][count][3] = a;
	YSI_g_sRaceData[raceid][E_RACE_RACER_MAX]++;
	return count;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetFixedWin
Params:
	raceid - Race to set for.
	set - 1/0.
Return:
	-
Notes:
	Sets wether or not a race has fixed prizes for the
	winners.  If not the prizes are calculated at race start
	based on the number of entrants and the entry fee.
-*----------------------------------------------------------------------------*/

stock Race_SetFixedWin(raceid, set)
{
	if (!Race_IsValid(raceid)) return;
	if (set) YSI_g_sRaceData[raceid][E_RACE_FLAGS] &= ~e_RACE_FLAGS_REL_WIN;
	else YSI_g_sRaceData[raceid][E_RACE_FLAGS] |= e_RACE_FLAGS_REL_WIN;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetRestart
Params:
	raceid - Race to set for.
	set - 1/0.
Return:
	-
Notes:
	Sets wether or not a race is destroyed after completion.
-*----------------------------------------------------------------------------*/

stock Race_SetRestart(raceid, set)
{
	if (!Race_IsValid(raceid)) return;
	if (set) YSI_g_sRaceData[raceid][E_RACE_FLAGS] |= e_RACE_FLAGS_RESTART;
	else YSI_g_sRaceData[raceid][E_RACE_FLAGS] &= ~e_RACE_FLAGS_RESTART;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetArial
Params:
	raceid - Race to set for.
	set - 1/0.
Return:
	-
Notes:
	Toggles the use of arial checkpoints.
-*----------------------------------------------------------------------------*/

stock Race_SetArial(raceid, set)
{
	if (!Race_IsValid(raceid)) return;
	if (set) YSI_g_sRaceData[raceid][E_RACE_FLAGS] |= e_RACE_FLAGS_ARIAL;
	else YSI_g_sRaceData[raceid][E_RACE_FLAGS] &= ~e_RACE_FLAGS_ARIAL;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetActive
Params:
	raceid - Race to set for.
	set - 1/0.
Return:
	-
Notes:
	Activates the race for entry and use.
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC stock Race_SetActive(raceid, set)
{
	if (!Race_IsValid(raceid)) return;
	if (set) YSI_g_sRaceData[raceid][E_RACE_FLAGS] |= e_RACE_FLAGS_ACTIVE;
	else YSI_g_sRaceData[raceid][E_RACE_FLAGS] &= ~e_RACE_FLAGS_ACTIVE;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetCountdown
Params:
	raceid - Race to set for.
	countdown - Number to count down from.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Race_SetCountdown(raceid, countdown)
{
	if (!Race_IsValid(raceid)) return;
	YSI_g_sRaceData[raceid][E_RACE_COUNTDOWN] = countdown;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetInterior
Params:
	raceid - Race to set for.
	interior - Interior where race is located.
Return:
	-
Notes:
	AFAIK you can't drive between interiors so all the
	checkpoints must be located in the same interior.
-*----------------------------------------------------------------------------*/

stock Race_SetInterior(raceid, interior)
{
	if (!Race_IsValid(raceid)) return;
	YSI_g_sRaceData[raceid][E_RACE_INT] = interior;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetWorld
Params:
	raceid - Race to set for.
	world - World to run race in.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Race_SetWorld(raceid, world)
{
	if (!Race_IsValid(raceid)) return;
	YSI_g_sRaceData[raceid][E_RACE_VW] = world;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetPrize
Params:
	raceid - Race to set for.
	position - Winning position to set for/.
	amount - Amount for that position to win.
Return:
	-
Notes:
	If this is used after the race has started it will over-
	write prizes set by relative winnings.
-*----------------------------------------------------------------------------*/

stock Race_SetPrize(raceid, position, amount)
{
	if (!Race_IsValid(raceid) || position >= MAX_RACE_WINNERS) return;
	YSI_g_sRaceData[raceid][E_RACE_PRIZES][position] = amount;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Set_ExitTime
Params:
	raceid - Race to set for.
	time - Time to set.
Return:
	-
Notes:
	Sets the time you are allowed out a vehicle before you
	fail the race.  0 means a vehicle exit is an instant fail.
	
	Useful for long races where cars may well be destroyed.
-*----------------------------------------------------------------------------*/

stock Race_SetExitTime(raceid, time)
{
	if (!Race_IsValid(raceid)) return;
	YSI_g_sRaceData[raceid][E_RACE_FLAGS] = (YSI_g_sRaceData[raceid][E_RACE_FLAGS] & (~e_RACE_FLAGS_EXIT_TIME)) | (e_RACE_FLAGS:time & e_RACE_FLAGS_EXIT_TIME);
}

/*----------------------------------------------------------------------------*-
Function:
	Race_IsActive
Params:
	raceid - Race to check.
Return:
	-
Notes:
	Wrapper for Race_IsValid.
-*----------------------------------------------------------------------------*/

stock Race_IsActive(raceid)
{
	return Race_IsValid(raceid);
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetLaps
Params:
	raceid - Race to set for.
	laps - Number of laps to set.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Race_SetLaps(raceid, laps)
{
	if (!Race_IsValid(raceid)) return;
	YSI_g_sRaceData[raceid][E_RACE_LAPS] = laps;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_SetEntry
Params:
	raceid - Race to set for.
	cost - Cost of entry to the race.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Race_SetEntry(raceid, cost)
{
	if (!Race_IsValid(raceid)) return;
	YSI_g_sRaceData[raceid][E_RACE_ENTRY] = cost;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Dropout
Params:
	playerid - Player dropping out.
Return:
	-
Notes:
	Called when a player exits their vehicle.
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC Race_Dropout(playerid)
{
	SetTimerEx("Race_Timeout", (YSI_g_sRaceData[(YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE])][E_RACE_FLAGS] & e_RACE_FLAGS_EXIT_TIME), 0, "i", playerid);
	YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE] |= RACE_PLAYER_OUT;
	YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_TOUT] = GetTickCount();
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Rejoin
Params:
	playerid - Player rejoining.
Return:
	-
Notes:
	Called when a player gets in a new vehicle if not timmed
	out..
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC Race_Rejoin(playerid)
{
	YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE] &= ~RACE_PLAYER_OUT;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Timeout
Params:
	playerid - Player to check.
Return:
	-
Notes:
	Called from Race_Dropout after the race's exit time.  If
	the player still isn't in a vehicle (set by Race_Rejoin) the
	player fails the race.
-*----------------------------------------------------------------------------*/

public Race_Timeout(playerid)
{
	if (YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE] & RACE_PLAYER_OUT) Race_Exit(playerid);
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Exit
Params:
	playerid - Player who left.
Return:
	-
Notes:
	Called when a player leaves a race prematurly.
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC Race_Exit(playerid)
{
	DisablePlayerRaceCheckpoint(playerid);
	new
		slot = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE];
	Race_PlayerDone(playerid);
	CallRemoteFunction("OnPlayerExitRace", "ii", playerid, slot);
	Race_CheckEnd(slot);
}

/*----------------------------------------------------------------------------*-
Function:
	Race_CheckEnd
Params:
	slot - Race to check.
Return:
	-
Notes:
	Called whenever a player leaves the race, checks the
	number of remaining racers and if none ends the race.
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC Race_CheckEnd(slot)
{
	// This shouldn't be here...
	//YSI_g_sRaceData[slot][E_RACE_RACER_COUNT]--;
	if (!(--YSI_g_sRaceData[slot][E_RACE_RACER_COUNT]))
	{
		CallRemoteFunction("OnRaceEnd", "i", slot);
		if (!(YSI_g_sRaceData[slot][E_RACE_FLAGS] & e_RACE_FLAGS_RESTART))
		{
			YSI_g_sRaceData[slot][E_RACE_FLAGS] = e_RACE_FLAGS:0;
		}
		else
		{
			YSI_g_sRaceData[slot][E_RACE_FLAGS] &= ~e_RACE_FLAGS_STARTED;
			YSI_g_sRaceData[slot][E_RACE_FINISHED] = 0;
			new
				count = YSI_g_sRaceData[slot][E_RACE_CHECKPOINTS],
				start = YSI_g_sRaceData[slot][E_RACE_CP_START];
			RaceArray_Shift(start + count, YSI_g_sCPIndex, start);
			RaceArray_IndexShift(start, -count);
		}
	}
}

/*----------------------------------------------------------------------------*-
Function:
	Race_PlayerDone
Params:
	playerid - Player done.
Return:
	-
Notes:
	Generic cleanup for anyone who has left a race.  Sets
	the player back to their old position and sets a few other
	variables.
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC Race_PlayerDone(playerid)
{
	new
		race = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE];
	YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE] = NO_RACE;
	YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_TIME] = GetTickCount() - YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_TIME];
	#if defined RACE_POSITION
		YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_POSITION] = 0;
	#endif
	if (Race_IsValid(race))
	{
		PA_Set(YSI_g_sRacers[race], playerid, false);
		Iter_Remove(YSI_g_sRacePeople[race], playerid);
		if (IsPlayerConnected(playerid))
		{
			SetPlayerPos(playerid, YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_X], YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_Y], YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_Z]);
			SetPlayerFacingAngle(playerid, YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_A]);
			new
				vehicleid;
			if ((vehicleid = GetPlayerVehicleID(playerid)))
			{
				SetVehiclePos(vehicleid, YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_X], YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_Y], YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_Z]);
				SetVehicleZAngle(vehicleid, YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_A]);
				LinkVehicleToInterior(vehicleid, YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_INT]);
				SetVehicleVirtualWorld(vehicleid, YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_WORLD]);
			}
			SetPlayerInterior(playerid, YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_INT]);
			SetPlayerVirtualWorld(playerid, YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_WORLD]);
		}
	}
}

/*----------------------------------------------------------------------------*-
Function:
	Race_GetPlayerExitedTime
Params:
	playerid - Player to get time of.
Return:
	The time a player has been out a vehicle.
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Race_GetPlayerExitedTime(playerid)
{
	return GetTickCount() - YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_TOUT];
}

/*----------------------------------------------------------------------------*-
Function:
	Race_PlayerJoin
Params:
	playerid - Player to add.
	race - Race to add to.
Return:
	-
Notes:
	Checks if a player is valid to join a race and if the race
	is valid to be joined to and if so adds them to it.
-*----------------------------------------------------------------------------*/

stock Race_PlayerJoin(playerid, race)
{
	if (YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE] != NO_RACE ||
		!Race_IsValid(race)) return 0;
	new
		e_RACE_FLAGS:flags = YSI_g_sRaceData[race][E_RACE_FLAGS];
	if ((flags & e_RACE_FLAGS_STARTED) ||
		YSI_g_sRaceData[race][E_RACE_RACER_COUNT] >= YSI_g_sRaceData[race][E_RACE_RACER_MAX] ||
		GetPlayerMoney(playerid) < YSI_g_sRaceData[race][E_RACE_ENTRY]) return 0;
	GivePlayerMoney(playerid, 0 - YSI_g_sRaceData[race][E_RACE_ENTRY]);
	YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE] = race;
	YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_LAP] = 0;
	YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_CP] = 0;
	PA_Set(YSI_g_sRacers[race], playerid, true);
	++YSI_g_sRaceData[race][E_RACE_RACER_COUNT];
	Iter_Add(YSI_g_sRacePeople[race], playerid);
	#if defined RACE_POSITION
		YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_POSITION] = 0;
	#endif
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_PlayerLeave
Params:
	playerid - Player to leave the race.
	refund - Wether or not to give them their entry fee back.
Return:
	-
Notes:
	Called if a player leaves a race before the race has
	started.
-*----------------------------------------------------------------------------*/

stock Race_PlayerLeave(playerid, bool:refund = false)
{
	new
		race = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE];
	if (!Race_IsValid(race) || YSI_g_sRaceData[race][E_RACE_FLAGS] & e_RACE_FLAGS_STARTED) return 0;
	if (refund) GivePlayerMoney(playerid, YSI_g_sRaceData[race][E_RACE_ENTRY]);
	YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE] = NO_RACE;
	PA_Set(YSI_g_sRacers[race], playerid, false);
	--YSI_g_sRaceData[race][E_RACE_RACER_COUNT];
	Iter_Remove(YSI_g_sRacePeople[race], playerid);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Finish
Params:
	playerid - Player who finished the race.
Return:
	-
Notes:
	Called when a player completes a race.
-*----------------------------------------------------------------------------*/

_Y_RACES_STATIC Race_Finish(playerid)
{
	new
		slot = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE],
		winners = YSI_g_sRaceData[slot][E_RACE_FINISHED];
	YSI_g_sRaceData[slot][E_RACE_FINISHED]++;
	Race_PlayerDone(playerid);
	new
		prize;
	if (winners < MAX_RACE_WINNERS) prize = YSI_g_sRaceData[slot][E_RACE_PRIZES][winners];
	GivePlayerMoney(playerid, prize);
	CallRemoteFunction("OnPlayerFinishRace", "iiiii", playerid, slot, winners + 1, prize, YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_TIME]);
	Race_CheckEnd(slot);
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Start
Params:
	race - Race to start.
Return:
	-
Notes:
	Loops through all players who have entered the race and
	moves them to their respective start points.  If the prize
	is set as relative the prizes are calculated here based on
	number of entrants, number of possible winners and entry
	fee.
-*----------------------------------------------------------------------------*/

stock Race_Start(race)
{
	if (!Race_IsValid(race)) return 0;
	new
		j;
	foreach (new i : YSI_g_sRacePeople[race])
	{
		//if (PA_Get(YSI_g_sRacers[race], i))
		{
			new
				vehicleid;
			//if (IsPlayerConnected(i))
			{
				GetPlayerPos(i, YSI_g_sPlayerRace[i][E_RACE_PLAYER_X], YSI_g_sPlayerRace[i][E_RACE_PLAYER_Y], YSI_g_sPlayerRace[i][E_RACE_PLAYER_Z]);
				if ((vehicleid = GetPlayerVehicleID(i)))
				{
					GetPlayerFacingAngle(i, YSI_g_sPlayerRace[i][E_RACE_PLAYER_A]);
					YSI_g_sPlayerRace[i][E_RACE_PLAYER_INT] = GetPlayerInterior(i);
					YSI_g_sPlayerRace[i][E_RACE_PLAYER_WORLD] = GetPlayerVirtualWorld(i);
					LinkVehicleToInterior(vehicleid, YSI_g_sRaceData[race][E_RACE_INT]);
					SetVehicleVirtualWorld(vehicleid, YSI_g_sRaceData[race][E_RACE_VW]);
					SetPlayerInterior(i, YSI_g_sRaceData[race][E_RACE_INT]);
					SetPlayerVirtualWorld(i, YSI_g_sRaceData[race][E_RACE_VW]);
					SetVehiclePos(vehicleid, YSI_g_sRaceStarts[race][j % MAX_RACE_STARTS][0], YSI_g_sRaceStarts[race][j % MAX_RACE_STARTS][1], YSI_g_sRaceStarts[race][j % MAX_RACE_STARTS][2]);
					SetVehicleZAngle(vehicleid, YSI_g_sRaceStarts[race][j % MAX_RACE_STARTS][3]);
					TogglePlayerControllable(i, 0);
					++j;
				}
				else Race_Exit(i);
			}
		}
	}
	if (j)
	{
		YSI_g_sRaceData[race][E_RACE_FLAGS] |= e_RACE_FLAGS_STARTED;
		Race_Countdown(race, YSI_g_sRaceData[race][E_RACE_COUNTDOWN]);
		if (YSI_g_sRaceData[race][E_RACE_FLAGS] & e_RACE_FLAGS_REL_WIN)
		{
			new
				prize;
			if (j < MAX_RACE_WINNERS) prize = ((j * j) + j) / 2;
			else prize = (MAX_RACE_WINNERS * (MAX_RACE_WINNERS + 1)) / 2;
			new
				count = (YSI_g_sRaceData[race][E_RACE_ENTRY] * j) / prize;
			for (new i = 0; i < MAX_RACE_WINNERS; i++) YSI_g_sRaceData[race][E_RACE_PRIZES][i] = (MAX_RACE_WINNERS - i) * count;
		}
		return 1;
	}
	return 0;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Countdown
Params:
	race - Race to do countdown for.
	time - Seconds remaining.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

public Race_Countdown(race, time)
{
	if (!(YSI_g_sRaceData[race][E_RACE_FLAGS] & e_RACE_FLAGS_ACTIVE)) return;
	if (time)
	{
		//printf("Text_Send");
		//print(Bit_Display(YSI_g_sRacers[race][1]));
		Text_Send(YSI_g_sRacers[race], $YSI_RACE_COUNTDOWN, time);
		SetTimerEx("Race_Countdown", 1000, 0, "ii", race, time - 1);
	}
	else
	{
		Text_Send(YSI_g_sRacers[race], $YSI_RACE_GO);
		new
			startTime = GetTickCount(),
			vehicleid,
			pos;
		//foreach (new i : Player)
		foreach (new i : YSI_g_sRacePeople[race])
		{
			//if (Bit_Get(YSI_g_sRacers[race], i))
			{
				//if (IsPlayerConnected(i) && (vehicleid = GetPlayerVehicleID(i)))
				if ((vehicleid = GetPlayerVehicleID(i)))
				{
					TogglePlayerControllable(i, 1);
					Race_DoEnterRaceCP(i);
					SetVehiclePos(vehicleid, YSI_g_sRaceStarts[race][pos % MAX_RACE_STARTS][0], YSI_g_sRaceStarts[race][pos % MAX_RACE_STARTS][1], YSI_g_sRaceStarts[race][pos % MAX_RACE_STARTS][2] + 0.1);
					SetVehicleZAngle(vehicleid, YSI_g_sRaceStarts[race][pos % MAX_RACE_STARTS][3]);
					YSI_g_sPlayerRace[i][E_RACE_PLAYER_TIME] = startTime;
					pos++;
				}
				else Race_Exit(i);
			}
		}
	}
}

/*----------------------------------------------------------------------------*-
Function:
	Race_Race
Params:
	-
Return:
	-
Notes:
	Sets up important variables
-*----------------------------------------------------------------------------*/

hook OnScriptInit()
{
	//#if defined RACE_POSITION
	//	Timer_Add("Race_Loop", RACE_LOOP_GRANULARITY);
	//#endif
	for (new i = 0; i < MAX_PLAYERS; i++)
	{
		YSI_g_sPlayerRace[i][E_RACE_PLAYER_RACE] = NO_RACE;
	}
	Iter_Init(YSI_g_sRacePeople);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_OnPlayerEnterRaceCheckpoint
Params:
	playerid - Player who entered.
Return:
	-
Notes:
	Checks a players position in the race and displays the
	corresponding next checkpoint or calls Race_Finish.
-*----------------------------------------------------------------------------*/

//#define Race_OnPlayerEnterRaceCheckpoint Race_OnPlayerEnterRaceCP

hook OnPlayerEnterRaceCheckpoint(playerid)
{
	return Race_DoEnterRaceCP(playerid);
}

_Y_RACES_STATIC Race_DoEnterRaceCP(playerid)
{
	new
		race = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE];
	if (race & RACE_PLAYER_OUT) return 1;
	// Race_IsValid check mixed with running check.
	if ((0 <= race < MAX_RACES) && (YSI_g_sRaceData[race][E_RACE_FLAGS] & (e_RACE_FLAGS_ACTIVE | e_RACE_FLAGS_STARTED) == (e_RACE_FLAGS_ACTIVE | e_RACE_FLAGS_STARTED)))
	{
		DisablePlayerRaceCheckpoint(playerid);
		new
			start = YSI_g_sRaceData[race][E_RACE_CP_START],
			check = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_CP],
			checks = YSI_g_sRaceData[race][E_RACE_CHECKPOINTS],
			laps = YSI_g_sRaceData[race][E_RACE_LAPS],
			type = _:(YSI_g_sRaceData[race][E_RACE_FLAGS] & e_RACE_FLAGS_ARIAL);
		if (laps)
		{
			new
				lap = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_LAP];
			if (lap == laps)
			{
				Race_Finish(playerid);
				//++YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_CP];
				return 1;
			}
			else
			{
				if (check + 1 == checks)
				{
					if (lap + 1 == laps)
					{
						SetPlayerRaceCheckpoint(playerid, type ? 4 : 1, YSI_g_sRaceCheckpoints[start][0], YSI_g_sRaceCheckpoints[start][1], YSI_g_sRaceCheckpoints[start][2], 0.0, 0.0, 0.0, 5.0);
					}
					else
					{
						check += start;
						SetPlayerRaceCheckpoint(playerid, type ? 3 : 0, YSI_g_sRaceCheckpoints[check][0], YSI_g_sRaceCheckpoints[check][1], YSI_g_sRaceCheckpoints[check][2], YSI_g_sRaceCheckpoints[start][0], YSI_g_sRaceCheckpoints[start][1], YSI_g_sRaceCheckpoints[start][2], 5.0);
					}
					//check = start;
					YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_CP] = 0;
					++YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_LAP];
					return 1;
					//++lap;
				}
				else
				{
					check += start;
					SetPlayerRaceCheckpoint(playerid, type ? 3 : 0, YSI_g_sRaceCheckpoints[check][0], YSI_g_sRaceCheckpoints[check][1], YSI_g_sRaceCheckpoints[check][2], YSI_g_sRaceCheckpoints[check + 1][0], YSI_g_sRaceCheckpoints[check + 1][1], YSI_g_sRaceCheckpoints[check + 1][2], 5.0);
					//++check;
					++YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_CP];
					return 1;
				}
				//if (++check == checks)
				//{
				//	++lap;
				//	check = 0;
				//}
			}
		}
		else
		{
			switch (checks - check)
			{
				case 0:
				{
					Race_Finish(playerid);
				}
				case 1:
				{
					check += start;
					SetPlayerRaceCheckpoint(playerid, type ? 4 : 1, YSI_g_sRaceCheckpoints[check][0], YSI_g_sRaceCheckpoints[check][1], YSI_g_sRaceCheckpoints[check][2], 0.0, 0.0, 0.0, 5.0);
				}
				default:
				{
					check += start;
					SetPlayerRaceCheckpoint(playerid, type ? 3 : 0, YSI_g_sRaceCheckpoints[check][0], YSI_g_sRaceCheckpoints[check][1], YSI_g_sRaceCheckpoints[check][2], YSI_g_sRaceCheckpoints[check + 1][0], YSI_g_sRaceCheckpoints[check + 1][1], YSI_g_sRaceCheckpoints[check + 1][2], 5.0);
				}
			}
			//++check;
			++YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_CP];
			//YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_LAP] = lap;
			return 1;
		}
	}
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_OnPlayerStateChange
Params:
	playerid - Player who's state changed.
	newstate - Their new state.
	oldstate - Their last state.
Return:
	-
Notes:
	Processes a players vehicle exit or entry mid race and
	calls the relevant functions.
-*----------------------------------------------------------------------------*/

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
	new
		race = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE];
	if (!Race_IsValid(race) || !(YSI_g_sRaceData[race][E_RACE_FLAGS] & e_RACE_FLAGS_STARTED)) return 0;
	if (oldstate == PLAYER_STATE_DRIVER)
	{
		if (!(YSI_g_sRaceData[race][E_RACE_FLAGS] & e_RACE_FLAGS_EXIT_TIME) || newstate != PLAYER_STATE_EXIT_VEHICLE) Race_Exit(playerid);
		else Race_Dropout(playerid);
	}
	else if (newstate == PLAYER_STATE_DRIVER) Race_Rejoin(playerid);
	else if (newstate != PLAYER_STATE_ONFOOT && newstate != PLAYER_STATE_ENTER_VEHICLE_DRIVER) Race_Exit(playerid);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	Race_OnPlayerDisconnect
Params:
	playerid - Player who left.
	reason - Why they left.
Return:
	-
Notes:
	Similar to the Race_OnPlayerStateChange function but
	instantly exits them from the race as they're not there
	anymore.
-*----------------------------------------------------------------------------*/

hook OnPlayerDisconnect(playerid, reason)
{
	new
		race = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE];
	if (!Race_IsValid(race)) return 0;
	if (YSI_g_sRaceData[race][E_RACE_FLAGS] & e_RACE_FLAGS_STARTED)
	{
		Race_Exit(playerid);
	}
	else
	{
		Race_PlayerLeave(playerid);
	}
	return 1;
	#pragma unused reason
}

/*----------------------------------------------------------------------------*-
Function:
	Race_OnPlayerConnect
Params:
	playerid - Player who joined.
Return:
	-
Notes:
	Just a fix for IsPlayerInRaceCheckpoint.
-*----------------------------------------------------------------------------*/

hook OnPlayerConnect(playerid)
{
	DisablePlayerRaceCheckpoint(playerid);
	return 1;
}

#if defined RACE_POSITION

/*----------------------------------------------------------------------------*-
Function:
	Race_Loop
Params:
	-
Return:
	-
Notes:
	If compiled with RACE_POSITION this function will
	keep track of all player's positions in their race.  It uses
	current lap, checkpoint and distance from next
	checkpoint to approximate position.
	
	Note: If a race doubles back between two checkpoints
	you may be closer than another player thus show as a
	higher position when you are infact behind them.
-*----------------------------------------------------------------------------*/

task Race_Loop[500 / MAX_RACES]()
{
	static
		race = -1;
	// Process a different race every call.
	race = (race + 1) % MAX_RACES;
	static
		racePos[MAX_PLAYERS][E_RACE_POS];
	//foreach (new playerid : Player)
	//for (new race = 0; race != MAX_RACES; ++race) if (Race__IsActive(race))
	if (Race__IsActive(race))
	{
		new
			start = YSI_g_sRaceData[race][E_RACE_CP_START],
			lap,
			cp,
			Float:togo,
			pos;//,
			//opl, // Other player lap,
			//opc; // Other player CP;
		foreach (new playerid : YSI_g_sRacePeople[race])
		{
			lap = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_LAP],
			cp = YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_CP] + start;
			static
				Float:x,
				Float:y,
				Float:z;
			GetPlayerPos(playerid, x, y, z);
			// Get the player's (squared) distance to the next checkpoint.
			x -= YSI_g_sRaceCheckpoints[cp][0];
			y -= YSI_g_sRaceCheckpoints[cp][1];
			z -= YSI_g_sRaceCheckpoints[cp][2];
			togo = ((x * x) + (y * y) + (z * z)),
			pos = 1;
			//racePos[playerid][E_RACE_POS_RACE] = race; // | RACE_POS_DONE;
			//racePos[playerid][E_RACE_POS_LAP] = lap;
			racePos[playerid][E_RACE_POS_CP] = cp;
			racePos[playerid][E_RACE_POS_TOGO] = togo;
			//foreach (new i : YSI_g_sRacePeople[race])
			for (new i = Iter_Begin(YSI_g_sRacePeople[race]); (i = Iter_Next(YSI_g_sRacePeople[race], i)) != playerid; )
			{
				//opl = YSI_g_sPlayerRace[i][E_RACE_PLAYER_LAP];
				//opc = racePos[i][E_RACE_POS_CP];
				// This checks "checkpoint + start", but both players have that
				// offset so it is fine.
				if (YSI_g_sPlayerRace[i][E_RACE_PLAYER_LAP] > lap ||
				   (YSI_g_sPlayerRace[i][E_RACE_PLAYER_LAP] == lap &&
				       (racePos[i][E_RACE_POS_CP] > cp ||
				       (racePos[i][E_RACE_POS_CP] == cp && racePos[i][E_RACE_POS_TOGO] < togo)))) ++pos;
				//if (racePos[i][E_RACE_POS_LAP] > lap ||
				//       (racePos[i][E_RACE_POS_LAP] == lap &&
				//         (racePos[i][E_RACE_POS_CP] > cp ||
				//            racePos[i][E_RACE_POS_TOGO] < togo))) ++pos;
				// This player is on a higher lap, or on a higher checkpoint,
				// or less distance from their next checkpoint.
				else ++YSI_g_sPlayerRace[i][E_RACE_PLAYER_POSITION]; //racePos[i][E_RACE_POS_POS];
			}
			//racePos[playerid][E_RACE_POS_POS] = pos;
			YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_POSITION] = pos; //racePos[playerid][E_RACE_POS_POS];
		}
		//foreach (new playerid : YSI_g_sRacePeople[race])
		//{
		//}
	}
}
//if (opl > lap || (opl == lap && (opc > cp || (opc == cp && racePos[i][E_RACE_POS_TOGO] < togo)))) ++pos;
// switch (floatcmp(YSI_g_sPlayerRace[i][E_RACE_PLAYER_LAP], lap))
// {
	// case  1: ++YSI_g_sPlayerRace[i][E_RACE_PLAYER_POSITION];
	// case -1: ++pos; // This player better.
	// default:
	// {
		// switch (floatcmp(racePos[i][E_RACE_POS_CP], cp))
		// {
			// case  1: ++YSI_g_sPlayerRace[i][E_RACE_PLAYER_POSITION];
			// case -1: ++pos;
			// default:
			// {
				// // Backwards as bigger is now worse.
				// switch (floatcmp(togo, racePos[i][E_RACE_POS_TOGO]))
				// {
					// case  1: ++YSI_g_sPlayerRace[i][E_RACE_PLAYER_POSITION];
					// case -1: ++pos;
					// // Default do nothing (leave them in the same position).
				// }
			// }
		// }
	// }
// }
// switch (floatcmp(YSI_g_sPlayerRace[i][E_RACE_PLAYER_LAP], lap) * 3 + floatcmp(racePos[i][E_RACE_POS_CP], cp))
// {
	// //case  4: // Other player lap higher, CP higher.
	// //case  3: // Other player lap higher, CP the same.
	// //case  2: // Other player lap higher, CP lower.
	// //case  1: // Laps the same, other player CP higher.
	// //case  0: // Everything the same.
	// //case -1: // Laps the same, this player CP higher.
	// //case -2: // This player lap higher, CP lower.
	// //case -3: // This player lap higher, CP the same.
	// //case -4: // This player lap higher, CP higher.
	// case 4, 3, 2, 1: ++YSI_g_sPlayerRace[i][E_RACE_PLAYER_POSITION]; // Other player better.
	// case 0: if (racePos[i][E_RACE_POS_TOGO] < togo) ++pos; else ++YSI_g_sPlayerRace[i][E_RACE_PLAYER_POSITION];
	// default: ++pos; // This player better.
	// //case -1, -2, -3, -4: // This player better.
// }

/*----------------------------------------------------------------------------*-
Function:
	Race_GetPlayerPosition
Params:
	playerid - Player to get position of.
Return:
	Dynamic position in race.
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Race_GetPlayerPosition(playerid)
{
	return YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_POSITION];
}

#endif

/*----------------------------------------------------------------------------*-
Function:
	Race_GetPlayerRaceTime
Params:
	playerid - Player to get time for.
Return:
	Time in race so far.
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Race_GetPlayerRaceTime(playerid)
{
	return GetTickCount() - YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_TIME];
}

/*----------------------------------------------------------------------------*-
Function:
	Race_GetPlayerRace
Params:
	playerid - Player to get race of.
Return:
	Player's race.
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Race_GetPlayerRace(playerid)
{
	if (playerid >= 0 && playerid < MAX_PLAYERS) return YSI_g_sPlayerRace[playerid][E_RACE_PLAYER_RACE];
	return NO_RACE;
}
