/* 
 * ===============
 *  INTRODUCTION: 
 * ===============
 * 
 * fixes.inc - Community patch for buggy SA:MP functions.
 * 
 * ================
 *  LIST OF FIXES: 
 * ================
 * 
 * FIX:      GetPlayerColor
 * PROBLEM:  Returns "0" if "SetPlayerColor" has never been called.
 * SOLUTION: Call "SetPlayerColor" in "OnPlayerConnect".
 * SEE:      "OnPlayerConnect".
 * AUTHOR:   KoczkaHUN
 * POST:     http://forum.sa-mp.com/showpost.php?p=1486048&postcount=45
 * 
 * FIX:      FILTERSCRIPT
 * PROBLEM:  Despite the fact that is in every new script, many people don't
 *           define "FILTERSCRIPT" where appropriate.
 * SOLUTION: Provide an "IS_FILTERSCRIPT" variable (note the naming to match
 *           the original macro).
 * AUTHOR:   Y_Less
 * SEE:      "OnFilterScriptInit" and "OnGameModeInit".
 * 
 * FIX:      SpawnPlayer
 * PROBLEM:  Kills the player if they are in a vehicle.
 * SOLUTION: Remove the from the vehicle.
 * SEE:      "FIXES_SpawnPlayer".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerName
 * PROBLEM:  Using "SetPlayerName" when the new name only differs from the old
 *           name in case does not alter the name at all.
 * SOLUTION: Change their name twice - once to "_FIXES TEMP NAME" and then to
 *           the actual required name.
 * SEE:      "OnPlayerConnect" and "FIXES_SetPlayerName".
 * AUTHOR:   Y_Less
 * 
 * FIX:      GetPlayerSkin
 * PROBLEM:  Returns the new skin after "SetSpawnInfo" is called but before the
 *           player actually respawns to get the new skin.
 * SOLUTION: Record the skin in "OnPlayerSpawn" and always return that one.
 * SEE:      "OnPlayerSpawn", "FIXES_GetPlayerSkin" and "FIXES_SetPlayerSkin".
 * AUTHOR:   Y_Less
 * 
 * FIX:      GetWeaponName
 * PROBLEM:  Returns nothing for 18, 44, and 45.
 * SOLUTION: Return the correct names ("Molotov Cocktail", "Thermal Goggles",
 *           and "Night vision Goggles").
 * SEE:      "FIXES_GetWeaponName".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerWorldBounds
 * PROBLEM:  Aiming can bypass the edge.
 * SOLUTION: Check for the player leaving the area and reset them to their last
 *           good position if they leave the area (aiming or not).
 * SEE:      "OnPlayerUpdate" and "FIXES_SetPlayerWorldBounds".
 * AUTHOR:   Y_Less
 * 
 * FIX:      TogglePlayerControllable
 * PROBLEM:  Other players see you moving on the spot.
 * SOLUTION: Return 0 in OnPlayerUpdate.
 * SEE:      "FIXES_TogglePlayerControllable" and "OnPlayerUpdate".
 * AUTHOR:   Slice
 * POST:     http://forum.sa-mp.com/showpost.php?p=876854&postcount=1
 * 
 * FIX:      HydraSniper
 * PROBLEM:  Entring military aircraft with a sniper rifle messes up vies.
 * SOLUTION: Set their armed weapon to fists.
 * SEE:      "OnPlayerStateChange".
 * AUTHOR:   funky1234
 * POST:     http://forum.sa-mp.com/showpost.php?p=965644&postcount=48
 * 
 * FIX:      IsPlayerInCheckpoint
 * PROBLEM:  Function returns an undefined value if it is called before any
 *           other checkpoint functions are called to initialise the value.
 * SOLUTION: Call "DisablePlayerCheckpoint" when they connect.
 * SEE:      "OnPlayerConnect".
 * AUTHOR:   Y_Less
 * 
 * FIX:      IsPlayerInRaceCheckpoint
 * PROBLEM:  Function returns an undefined value if it is called before any
 *           other race checkpoint functions are called to initialise the value.
 * SOLUTION: Call "DisablePlayerRaceCheckpoint" when they connect.
 * SEE:      "OnPlayerConnect".
 * AUTHOR:   Y_Less
 * 
 * FIX:      GetPlayerWeapon
 * PROBLEM:  Returns the old value after using "SetPlayerArmedWeapon" when they
 *           are in a vehicle.
 * SOLUTION: If "SetPlayerArmedWeapon" is called in a vehicle, store the new
 *           value and return that instead.
 * SEE:      "OnPlayerStateChange", "FIXES_SetPlayerArmedWeapon", and
 *           "FIXES_GetPlayerWeapon".
 * AUTHOR:   Y_Less
 * 
 * FIX:      PutPlayerInVehicle
 * PROBLEM:  If this is used on a passenger the driver of their old vehicle
 *           doesn't see them in their new vehicle.
 * SOLUTION: Remove them from the vehicle first.
 * SEE:      "OnPlayerStateChange" and "FIXES_PutPlayerInVehicle".
 * AUTHOR:   leong124/Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1265965&postcount=148
 * 
 * FIX:      KEY_AIM
 * PROBLEM:  "KEY_AIM" isn't defined by default.
 * SOLUTION: Define it.
 * SEE:      N/A.
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerCheckpoint
 * PROBLEM:  If a checkpoint is already set it will use the size of that
 *           checkpoint instead of the new one.
 * SOLUTION: Call "DisablePlayerCheckpoint" before setting the checkpoint.
 * SEE:      "FIXES_SetPlayerCheckpoint".
 * AUTHOR:   KoczkaHUN
 * POST:     http://forum.sa-mp.com/showpost.php?p=1482401&postcount=23
 *
 * FIX:      SetPlayerRaceCheckpoint
 * PROBLEM:  If a checkpoint is already set it will use the size of that
 *           checkpoint instead of the new one.
 * SOLUTION: Call "DisablePlayerRaceCheckpoint" before setting the checkpoint.
 * SEE:      "FIXES_SetPlayerRaceCheckpoint".
 * AUTHOR:   KoczkaHUN
 * POST:     http://forum.sa-mp.com/showpost.php?p=1482401&postcount=23
 *
 * FIX:      TextDrawCreate
 * PROBLEM:  Crashes on a blank string.
 * SOLUTION: Intercept blank strings.
 * SEE:      "FIXES_TextDrawCreate".
 * AUTHOR:   wups
 * POST:     http://forum.sa-mp.com/showpost.php?p=1484008&postcount=30
 * 
 * FIX:      TextDrawSetString
 * PROBLEM:  Crashes on a blank string and size greater than 1024.
 * SOLUTION: Intercept blank strings and truncate long strings.
 * SEE:      "FIXES_TextDrawSetString".
 * AUTHOR:   TomTrox
 * POST:     http://forum.sa-mp.com/showpost.php?p=1487870&postcount=56
 * 
 * FIX:      AllowInteriorWeapons
 * PROBLEM:  Does nothing.
 * SOLUTION: Set the player's weapon to fists in an interior.
 * SEE:      "FIXES_AllowInteriorWeapons", "OnGameModeInit" and
 *           "OnPlayerUpdate".
 * AUTHOR:   KoczkaHUN
 * POST:     http://forum.sa-mp.com/showpost.php?p=1502696&postcount=82
 * 
 * FIX:      OnPlayerEnterVehicle
 * PROBLEM:  Crashes other players when people enter an invalid seat.
 * SOLUTION: Desync the people with invalid seats.
 * SEE:      "OnPlayerStateChange" and "OnPlayerUpdate".
 * AUTHOR:   RyDeR`/Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1410296&postcount=2440
 * 
 * FIX:      AllowTeleport
 * PROBLEM:  0.3dRC9 removed "AllowPlayerTeleport" and "AllowAdminTeleport" in
 *           favour of "OnPlayerClickMap".  Some scripts used the old code and.
 * SOLUTION: Teleport the player in "OnPlayerClickMap".
 * SEE:      "OnPlayerClickMap", "FIXES_AllowPlayerTeleport", and
 *           "FIXES_AllowAdminTeleport".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerSpecialAction
 * PROBLEM:  Removing jetpacks from players by setting their special action to 0
 *           causes the sound to stay until death.
 * SOLUTION: Call "ClearAnimations" before "SetPlayerSpecialAction".
 * SEE:      "FIXES_SetPlayerSpecialAction".
 * AUTHOR:   MP2
 * POST:     Private message from MP2.
 * 
 * FIX:      OnDialogResponse
 * PROBLEM:  Cheaters can spoof the dialogid they are using to respond to ones
 *           they can't actually see.
 * SOLUTION: Store the displayed dialogid and use that instead.
 * SEE:      "FIXES_OnDialogResponse", "FIXES_ShowPlayerDialog".
 * AUTHOR:   Y_Less
 * FIXED IN: 0.3e RC6
 * 
 * FIX:      GetPlayerDialog
 * PROBLEM:  This function doesn't exist.
 * SOLUTION: Add it.  DEFAULTS TO FALSE!
 * SEE:      "FIXES_GetPlayerDialog".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetSpawnInfo
 * PROBLEM:  Kicks the player if "SpawnPlayer" is called before "SetSpawnInfo".
 * SOLUTION: Call "SetSpawnInfo" at least once.
 * SEE:      "OnPlayerConnect".
 * AUTHOR:   Y_Less
 * 
 * FIX:      SetPlayerSkin
 * PROBLEM:  Breaks sitting on bikes.
 * SOLUTION: Put them back in the vehicle after setting their skin.
 * SEE:      "FIXES_SetPlayerSkin".
 * AUTHOR:   CyNiC
 * POST:     http://forum.sa-mp.com/showpost.php?p=1756094&postcount=3119
 * 
 * FIX:      HideMenuForPlayer
 * PROBLEM:  Crashes when passed an invalid menu ID.
 * SOLUTION: Don't hide it when passed an invalid menu.
 * SEE:      "FIXES_HideMenuForPlayer".
 * AUTHOR:   Y_Less
 * POST:     http://forum.sa-mp.com/showpost.php?p=1787297&postcount=1
 * 
 * FIX:      valstr
 * PROBLEM:  Crashes on large numbers.
 * SOLUTION: Use "format" instead.
 * SEE:      "FIXES_valstr".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      fclose
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fclose".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      fwrite
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fwrite".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      fread
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fread".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      fputchar
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fputchar".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      fgetchar
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fgetchar".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      fblockwrite
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fblockwrite".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      fblockread
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fblockread".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      fseek
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_fseek".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      flength
 * PROBLEM:  Crashes on an invalid handle.
 * SOLUTION: Check for an invalid handle.
 * SEE:      "FIXES_flength".
 * AUTHOR:   Slice.
 * POST:     http://forum.sa-mp.com/showpost.php?p=1790300&postcount=142
 * 
 * FIX:      file_inc
 * PROBLEM:  All file.inc fixes are included separately for major overhead.
 * SOLUTION: Optionally group them all under one define.
 * SEE:      "FIX_file_inc".
 * AUTHOR:   Y_Less.
 * 
 * FIX:      IsPlayerAttachedObjectSlotUsed
 * PROBLEM:  Doesn't work.
 * SOLUTION: Maintain an internal record of slots used.
 * SEE:      "FIXES_SetPlayerAttachedObject",
 *           "FIXES_RemovePlayerAttachedObject",
 *           "FIXES_IsPAttachedObjectSlotUsed", and
 *           "OnPlayerDisconnect".
 * 
 * FIX:      SetPlayerAttachedObject
 * PROBLEM:  Doesn't remove objects when the mode ends.
 * SOLUTION: Remove them.
 * SEE:      "FIXES_SetPlayerAttachedObject",
 *           "FIXES_RemovePlayerAttachedObject", and
 *           "OnPlayerDisconnect".
 * 
 * FIX:      OnPlayerDeath
 * PROBLEM:  Clients get stuck when they die with an animation applied.
 * SOLUTION: Clear their animations.
 * SEE:      "OnPlayerDeath" and "OnPlayerUpdate".
 * AUTHOR:   h02
 * POST:     http://forum.sa-mp.com/showpost.php?p=1641144&postcount=1
 * 
 * ==============
 *  STYLE RULES: 
 * ==============
 * 
 * All globals should be "static stock" whenever possible (so they can only be
 *     accessed from this one file).
 * 
 * Statics must start with "FIXES_gs", and all other globals with "FIXES_g".
 * 
 * All functions not overriding existing functions must start with "FIXES_".
 * 
 * Macros must be upper case, use underscores, and start "FIXES_":
 *     "FIXES_LIKE_THIS".
 * 
 * Functions should be upper camel case (as the original functions are)
 *     "FIXES_LikeThis".
 * 
 * Globals (after the prefix) should be upper camel case, and locals lower camel
 *     case "likeThis".
 * 
 * ALS should be used to hook functions and callbacks.
 * 
 * The ALS prefix for chaining is also "FIXES_"
 * 
 * Enums start with "E_" or "e_" depending on type, then follow rules for
 *     macros.
 * 
 * Use "FIXES_gsCallbackHooks" and "E_FIXES_CALLBACK_HOOKS" for ALS chaining.
 * 
 * NO libraries should be included - not even the default SA:MP ones.  Let the
 *     user do it.
 * 
 * Due to the above rule, you cannot assume any third party libraries AT ALL, so
 *     do not use them.
 * 
 * Certain terms may be shortened when dealing with long callback names to avoid
 *     compile truncation warnings (max symbol length is 31).  Current list:
 *     
 *     "Checkpoint" -> "CP"
 *     "Update"     -> "Up"
 *     "TextDraw"   -> "TD"
 *     "Object"     -> "Obj"
 *     "Player"     -> "P"
 * 
 * Document all fixes at the top of the file, and highlight code.
 * 
 * 4 space TABS - do not edit this file in PAWNO unless you know how to correct
 *     the indentation.
 * 
 * All rules have exceptions, but they must be justifiable.  For example
 *     "IS_FILTERSCRIPT" is a global variable, but is not called
 *     "FIXES_gIsFilterscript" to better match the "FILTERSCRIPT" macro it
 *     replaces.  Now a macro for "_FIXES_gIsFilterscript".
 * 
 * Variables which need to be fully global (i.e. not "static"), but should not
 *     actually be used by other people (e.g. appear inside a macro) should be
 *     prefixed with "_FIXES" instead of "FIXES" to indicate their private use.
 * 
 * No comments beyond the end of column 80 (where the line in "PAWNO" is).
 * 
 * When redefining a native, add a "BAD_" external name declaration with the
 *     "_ALS_" definition so that others may use the original native if they so
 *     desire (with the caveat that it may break all fixes).  Note the "BAD_"
 *     name is meant to indicate the possibility of breaking the fix, not a
 *     comment on the original native function.
 * 
 * If a bug is fixed in some version of the server it can be conditionally
 *     included here.  This is done by checking for the existance of a native
 *     function introduced in the same server version.  For example
 *     "TogglePlayerControllable" was fixed in 0.3eRC6, the same time as the
 *     "SetObjectMaterial" native was introduced, thus the inclusion becomes:
 *     
 *     #if !defined FIX_TogglePlayerControllable
 *         #define FIX_TogglePlayerControllable (!defined SetObjectMaterial)
 *     #endif
 *     
 *     This only includes this fix if that native doesn't exist.
 * 
 * Documentation explanation:
 * 
 *     FIX:      <Short name>
 *     PROBLEM:  <Description of problem>
 *     SOLUTION: <Description of solution>
 *     SEE:      <List of relevant functions>
 *     AUTHOR:   <Person who wrote the fix>
 *     POST:     <Link to the original post where applicable>
 *     FIXED IN: <Server version of official fix where applicable>
 */

// We can add server version compiler code here to only compile fixes that apply
// to the version of the includes for which the user is compiling.
#if !defined FIX_GetPlayerColor
	#if defined FIX_GetPlayerColour
		#define FIX_GetPlayerColor       (FIX_GetPlayerColour)
	#else
		#define FIX_GetPlayerColor       (1)
	#endif
#endif

#if !defined FIX_FILTERSCRIPT
	#define FIX_FILTERSCRIPT             (1)
#endif

#if !defined FIX_SpawnPlayer
	#define FIX_SpawnPlayer              (1)
#endif

#if !defined FIX_SetPlayerName
	#define FIX_SetPlayerName            (1)
#endif

#if !defined FIX_GetPlayerSkin
	#define FIX_GetPlayerSkin            (1)
#endif

#if !defined FIX_GetWeaponName
	#define FIX_GetWeaponName            (1)
#endif

#if !defined FIX_SetPlayerWorldBounds
	#define FIX_SetPlayerWorldBounds     (1)
#endif

#if !defined FIX_TogglePlayerControllable
	#define FIX_TogglePlayerControllable (!defined SetObjectMaterial)
#endif

#if !defined FIX_HydraSniper
	#define FIX_HydraSniper              (1)
#endif

#if !defined FIX_IsPlayerInCheckpoint
	#define FIX_IsPlayerInCheckpoint     (1)
#endif

#if !defined FIX_IsPlayerInRaceCheckpoint
	#define FIX_IsPlayerInRaceCheckpoint (1)
#endif

#if !defined FIX_GetPlayerWeapon
	#define FIX_GetPlayerWeapon          (1)
#endif

#if !defined FIX_PutPlayerInVehicle
	#define FIX_PutPlayerInVehicle       (1)
#endif

#if !defined FIX_KEY_AIM
	#define FIX_KEY_AIM                  (!defined KEY_AIM)
#endif

#if !defined FIX_SetPlayerCheckpoint
	#define FIX_SetPlayerCheckpoint      (1)
#endif

#if !defined FIX_SetPlayerRaceCheckpoint
	#define FIX_SetPlayerRaceCheckpoint  (1)
#endif

#if !defined FIX_TextDrawCreate
	#define FIX_TextDrawCreate           (1)
#endif

#if !defined FIX_TextDrawSetString
	#define FIX_TextDrawSetString        (1)
#endif

#if !defined FIX_AllowInteriorWeapons
	#define FIX_AllowInteriorWeapons     (1)
#endif

#if !defined FIX_OnPlayerEnterVehicle
	#define FIX_OnPlayerEnterVehicle     (!defined OnPlayerClickMap)
#endif

#if !defined FIX_AllowTeleport
	#define FIX_AllowTeleport            (defined OnPlayerClickMap)
#endif

#if !defined FIX_SetPlayerSpecialAction
	#define FIX_SetPlayerSpecialAction   (1)
#endif

#if !defined FIX_OnDialogResponse
	#define FIX_OnDialogResponse         (1)
#endif

#if !defined FIX_GetPlayerDialog
	#define FIX_GetPlayerDialog          (0)
#endif

#if !defined FIX_SetSpawnInfo
	#define FIX_SetSpawnInfo             (!defined GetPlayerVersion)
#endif

#if !defined FIX_SetPlayerSkin
	#define FIX_SetPlayerSkin            (1)
#endif

#if !defined FIX_HideMenuForPlayer
	#define FIX_HideMenuForPlayer        (1)
#endif

#if !defined FIX_valstr
	#define FIX_valstr                   (1)
#endif

#if !defined FIX_file_inc
	#define FIX_file_inc                 (1)
#endif

#if !defined FIX_fclose
	#define FIX_fclose                   (FIX_file_inc)
#endif

#if !defined FIX_fwrite
	#define FIX_fwrite                   (FIX_file_inc)
#endif

#if !defined FIX_fread
	#define FIX_fread                    (FIX_file_inc)
#endif

#if !defined FIX_fputchar
	#define FIX_fputchar                 (FIX_file_inc)
#endif

#if !defined FIX_fgetchar
	#define FIX_fgetchar                 (FIX_file_inc)
#endif

#if !defined FIX_fblockwrite
	#define FIX_fblockwrite              (FIX_file_inc)
#endif

#if !defined FIX_fblockread
	#define FIX_fblockread               (FIX_file_inc)
#endif

#if !defined FIX_fseek
	#define FIX_fseek                    (FIX_file_inc)
#endif

#if !defined FIX_flength
	#define FIX_flength                  (FIX_file_inc)
#endif

#if !defined FIX_IsPlayerAttachedObjSlotUsed
	#define FIX_IsPlayerAttachedObjSlotUsed (1)
#endif

#if !defined FIX_SetPlayerAttachedObject
	#define FIX_SetPlayerAttachedObject  (1)
#endif

#if !defined FIX_OnPlayerDeath
	#define FIX_OnPlayerDeath            (1)
#endif

/* 
 * E_FIXES_CALLBACK_HOOKS_1
 * E_FIXES_CALLBACK_HOOKS_2
 * 
 * Two enums to define the bits used to efficiently store wether of not the next
 * callback in the ALS chain exists.  Breaks naming convention for elements from
 * "E_FIXES_ON_GAME_MODE_INIT" to "E_FIXES_OnGameModeInit" for compatibility
 * with existing names.  Note that "Checkpoint" and "Update" have been shortened
 * to "CP" and "Up" in certain symbols to stay below the 31 character limit.
 */
enum E_FIXES_CALLBACK_HOOKS_1 (<<= 1)
{
	E_FIXES_OnGameModeInit = 1,
	E_FIXES_OnGameModeExit,
	E_FIXES_OnFilterScriptInit,
	E_FIXES_OnFilterScriptExit,
	E_FIXES_OnPlayerConnect,
	E_FIXES_OnPlayerDisconnect,
	E_FIXES_OnPlayerSpawn,
	E_FIXES_OnPlayerDeath,
	E_FIXES_OnVehicleSpawn,
	E_FIXES_OnVehicleDeath,
	E_FIXES_OnPlayerText,
	E_FIXES_OnPlayerCommandText,
	E_FIXES_OnPlayerRequestClass,
	E_FIXES_OnPlayerEnterVehicle,
	E_FIXES_OnPlayerExitVehicle,
	E_FIXES_OnPlayerStateChange,
	E_FIXES_OnPlayerEnterCheckpoint,
	E_FIXES_OnPlayerLeaveCheckpoint,
	E_FIXES_OnPlayerEnterRaceCP,
	E_FIXES_OnPlayerLeaveRaceCP,
	E_FIXES_OnRconCommand,
	E_FIXES_OnPlayerRequestSpawn,
	E_FIXES_OnObjectMoved,
	E_FIXES_OnPlayerObjectMoved,
	E_FIXES_OnPlayerPickUpPickup,
	E_FIXES_OnVehicleMod,
	E_FIXES_OnEnterExitModShop,
	E_FIXES_OnVehiclePaintjob,
	E_FIXES_OnVehicleRespray,
	E_FIXES_OnVehicleDamageStatusUp,
	E_FIXES_OnPlayerSelectedMenuRow,
	E_FIXES_OnPlayerExitedMenu
}

enum E_FIXES_CALLBACK_HOOKS_2 (<<= 1)
{
	E_FIXES_OnPlayerInteriorChange = 1,
	E_FIXES_OnPlayerKeyStateChange,
	E_FIXES_OnRconLoginAttempt,
	E_FIXES_OnPlayerUpdate,
	E_FIXES_OnPlayerStreamIn,
	E_FIXES_OnPlayerStreamOut,
	E_FIXES_OnVehicleStreamIn,
	E_FIXES_OnVehicleStreamOut,
	E_FIXES_OnDialogResponse,
	E_FIXES_OnPlayerClickPlayer,
	E_FIXES_OnPlayerClickMap,
	E_FIXES_OnPlayerClickTextDraw,
	E_FIXES_OnPlayerClickPlayerTD,
	E_FIXES_OnPlayerEditObject,
	E_FIXES_OnPlayerEditAttachedObj,
	E_FIXES_OnPlayerSelectObject,
	E_FIXES_OnPlayerTakeDamage,
	E_FIXES_OnPlayerGiveDamage
}

/* 
 * E_FIXES_WORLDBOUND_DATA
 * 
 * Store data for each player on their worldbound data.
 */
enum E_FIXES_WORLDBOUND_DATA
{
	// "Previous".
	Float:E_FIXES_WORLDBOUND_DATA_PX,
	Float:E_FIXES_WORLDBOUND_DATA_PY,
	Float:E_FIXES_WORLDBOUND_DATA_PZ,
	// "Lower".
	Float:E_FIXES_WORLDBOUND_DATA_LX,
	Float:E_FIXES_WORLDBOUND_DATA_LY,
	// "Upper".
	Float:E_FIXES_WORLDBOUND_DATA_UX,
	Float:E_FIXES_WORLDBOUND_DATA_UY
}

/* 
 * e_FIXES_BOOLS
 * 
 * Collection of boolean values for players, designed to collect multiple checks
 * in to one variable to reduce memory consumption.
 */
enum e_FIXES_BOOLS (<<= 1)
{
	// Handy definition for nothing set.
	e_FIXES_BOOLS_NONE = 0,
	// Does this player have worldbounds enabled?
	e_FIXES_BOOLS_WORLDBOUNDS = 1,
	e_FIXES_BOOLS_UNCONTROLLABLE,
	e_FIXES_BOOLS_PUT_IN_VEHICLE,
	e_FIXES_BOOLS_BLOCK,
	e_FIXES_BOOLS_TELEPORT
}

/* 
 * e_FIXES_SETTINGS
 * 
 * Collection of boolean values for the script as a whole.  Stores a variety of
 * settings that are true/false.
 */
enum e_FIXES_SETTINGS (<<= 1)
{
	// Handy definition for nothing set.
	e_FIXES_SETTINGS_NONE = 0,
	// Does this player have worldbounds enabled?
	e_FIXES_SETTINGS_INTERIOR = 1,
	e_FIXES_SETTINGS_ADMIN_TELEPORT
}

/* 
 * _FIXES_CEILDIV
 * 
 * Do a ceiling division of the first number by the second number.
 */
#define _FIXES_CEILDIV(%0,%1) (((%0) + (%1) - 1) / (%1))

/* 
 * _FIXES_ATTACHMENTS
 * 
 * The number of players whose attachment data (10-bits) can be stored in one
 * cell.
 */
#define _FIXES_ATTACHMENTS (cellbits / MAX_PLAYER_ATTACHED_OBJECTS)

// These varaibles are NOT pre-processor dependent as they are stock.  It's just
// simpler than trying to figure out when or if a semi-colon is needed.
#if !FIX_FILTERSCRIPT
static
#endif
stock
	/* 
	 * bool:_FIXES_gIsFilterscript
	 * 
	 * Runtime equivalent of "FILTERSCRIPT" for when it is not set by the user.
	 */
	bool:_FIXES_gIsFilterscript;

static stock
	/* 
	 * E_FIXES_CALLBACK_HOOKS_1:FIXES_gsCallbackHooks1
	 * E_FIXES_CALLBACK_HOOKS_1:FIXES_gsCallbackHooks2
	 * 
	 * Bit arrays of callbacks.  You can only have 32 callbacks per variable,
	 * and there are more than that many, so we need more than one variable.
	 * Add new callback detection to "FIXES_ScriptInit" - only actually used
	 * callbacks are currently hooked.
	 */
	E_FIXES_CALLBACK_HOOKS_1:FIXES_gsCallbackHooks1,
	E_FIXES_CALLBACK_HOOKS_2:FIXES_gsCallbackHooks2,
	/* 
	 * FIXES_gsPlayerSkin[MAX_PLAYERS]
	 * 
	 * The skin the player is currently using.
	 */
	FIXES_gsPlayerSkin[MAX_PLAYERS],
	/* 
	 * e_FIXES_BOOLEAN_DATA:FIXES_gsPlayerBools[MAX_PLAYERS]
	 * 
	 * Collection of boolean values for players.
	 */
	e_FIXES_BOOLS:FIXES_gsPlayerBools[MAX_PLAYERS],
	/* 
	 * FIXES_gsWorldbounds[MAX_PLAYERS][E_FIXES_WORLDBOUND_DATA]
	 * 
	 * All data for players on where their worldbounds are and where they last
	 * were before they went through the bounds by crouching.
	 */
	FIXES_gsWorldbounds[MAX_PLAYERS][E_FIXES_WORLDBOUND_DATA],
	/* 
	 * FIXES_gsPlayerWeapon[MAX_PLAYERS]
	 * 
	 * Stores the weapon set by "SetPlayerArmedWeapon" when in a vehicle.
	 */
	FIXES_gsPlayerWeapon[MAX_PLAYERS],
	/* 
	 * FIXES_gsVehicleSeatData[MAX_PLAYERS]
	 * 
	 * What vehicle the player is due to go in.
	 */
	FIXES_gsVehicleSeatData[MAX_PLAYERS],
	/* 
	 * FIXES_gsVehicleLocked[(MAX_PLAYERS * MAX_VEHICLES + cellbits - 1) / cellbits]
	 * 
	 * Is this vehicle locked for a player.  This is a compressed 2D binary
	 * array, made by concatenating many bits together (saves 1kb-3kb)!  Is
	 * there a reason this array exists?
	 */
	FIXES_gsVehicleLocked[_FIXES_CEILDIV(MAX_PLAYERS * MAX_VEHICLES, cellbits)],
	/* 
	 * FIXES_gsDialogID[MAX_PLAYERS]
	 * 
	 * Stores the true ID of the dialog the player is looking at to prevent
	 * spoofing.
	 */
	FIXES_gsDialogID[MAX_PLAYERS] = {-1, ...},
	/* 
	 * e_FIXES_SETTINGS:FIXES_gsSettings
	 * 
	 * A collection of 1-bit options, compressed together to save space.
	 */
	e_FIXES_SETTINGS:FIXES_gsSettings,
	/* 
	 * FIXES_gsObjectSlots[_FIXES_CEILDIV(MAX_PLAYERS, _FIXES_ATTACHMENTS)]
	 * 
	 * A record of which attached object slots a player has used.
	 */
	FIXES_gsObjectSlots[_FIXES_CEILDIV(MAX_PLAYERS, _FIXES_ATTACHMENTS)],
	/* 
	 * FIXES_gsLastAnimation[MAX_PLAYERS]
	 * 
	 * The last animation a player used.
	 */
	FIXES_gsLastAnimation[MAX_PLAYERS];

static stock const
	/* 
	 * FIXES_gscPlayerColours[100]
	 * 
	 * There are only 100 colours used by default, with SA:MP looping through
	 * them repeatedly.
	 */
	FIXES_gscPlayerColours[100] =
		{
			0xFF8C13FF, 0xC715FFFF, 0x20B2AAFF, 0xDC143CFF, 0x6495EDFF,
			0xF0E68CFF, 0x778899FF, 0xFF1493FF, 0xF4A460FF, 0xEE82EEFF,
			0xFFD720FF, 0x8B4513FF, 0x4949A0FF, 0x148B8BFF, 0x14FF7FFF,
			0x556B2FFF, 0x0FD9FAFF, 0x10DC29FF, 0x534081FF, 0x0495CDFF,
			0xEF6CE8FF, 0xBD34DAFF, 0x247C1BFF, 0x0C8E5DFF, 0x635B03FF,
			0xCB7ED3FF, 0x65ADEBFF, 0x5C1ACCFF, 0xF2F853FF, 0x11F891FF,
			0x7B39AAFF, 0x53EB10FF, 0x54137DFF, 0x275222FF, 0xF09F5BFF,
			0x3D0A4FFF, 0x22F767FF, 0xD63034FF, 0x9A6980FF, 0xDFB935FF,
			0x3793FAFF, 0x90239DFF, 0xE9AB2FFF, 0xAF2FF3FF, 0x057F94FF, 
			0xB98519FF, 0x388EEAFF, 0x028151FF, 0xA55043FF, 0x0DE018FF,
			0x93AB1CFF, 0x95BAF0FF, 0x369976FF, 0x18F71FFF, 0x4B8987FF,
			0x491B9EFF, 0x829DC7FF, 0xBCE635FF, 0xCEA6DFFF, 0x20D4ADFF,
			0x2D74FDFF, 0x3C1C0DFF, 0x12D6D4FF, 0x48C000FF, 0x2A51E2FF,
			0xE3AC12FF, 0xFC42A8FF, 0x2FC827FF, 0x1A30BFFF, 0xB740C2FF,
			0x42ACF5FF, 0x2FD9DEFF, 0xFAFB71FF, 0x05D1CDFF, 0xC471BDFF,
			0x94436EFF, 0xC1F7ECFF, 0xCE79EEFF, 0xBD1EF2FF, 0x93B7E4FF,
			0x3214AAFF, 0x184D3BFF, 0xAE4B99FF, 0x7E49D7FF, 0x4C436EFF,
			0xFA24CCFF, 0xCE76BEFF, 0xA04E0AFF, 0x9F945CFF, 0xDCDE3DFF, 
			0x10C9C5FF, 0x70524DFF, 0x0BE472FF, 0x8A2CD7FF, 0x6152C2FF,
			0xCF72A9FF, 0xE59338FF, 0xEEDC2DFF, 0xD8C762FF, 0xD8C762FF
		},
	/* 
	 * FIXES_gscMaxPassengers[]
	 * 
	 * This is a compressed (4-bit) list of the maximum number of passengers in
	 * any vehicle, confirmed by a number of sources. "F" (15) means invalid
	 * vehicle.
	 */
	FIXES_gscMaxPassengers[] =
		{
			0x10331113, 0x11311131, 0x11331313, 0x80133301, 0x1381F110, 0x10311103, 0x10001F10, 0x11113311, 0x13113311,
			0x31101100, 0x30001301, 0x11031311, 0x11111331, 0x10013111, 0x01131100, 0x11111110, 0x11100031, 0x11130221,
			0x33113311, 0x11111101, 0x33101133, 0x101001F0, 0x03133111, 0xFF11113F, 0x13330111, 0xFF131111, 0x0000FF3F
		};

/* 
 * _FIXES_KEY_AIM
 * KEY_AIM
 * 
 * Because the default SA:MP includes missed this one.
 */
#define _FIXES_KEY_AIM                   (128)
#if FIX_KEY_AIM
	#define KEY_AIM                      _FIXES_KEY_AIM
#endif

/* 
 * IS_FILTERSCRIPT
 * 
 * "FILTERSCRIPT" can't always be relied on to be set.  This is not a pre-
 * processor macro, but may be better than nothing (also used internally).
 */
#if FIX_FILTERSCRIPT
	#define IS_FILTERSCRIPT _FIXES_gIsFilterscript
#endif

/* 
 * FIXES_DETECT_CALLBACK_1(callback)
 * FIXES_DETECT_CALLBACK_2(callback)
 * 
 * Macro to make detecting callbacks simpler.  The number relates to which
 * variable the callback is found it.  This explicity detects the "On" part of
 * the callback because some scripts redefine the callback names and we need to
 * always correctly detect them, and always have "FIXES_On"#%0 work without
 * using the redefined name (e.g. if a prior script uses ALS).
 */
#define FIXES_DETECT_CALLBACK_1(%0On%1) (FIXES_gsCallbackHooks1|=E_FIXES_On%1*E_FIXES_CALLBACK_HOOKS_1:(funcidx("FIXES_On"#%1)!=-1))
#define FIXES_DETECT_CALLBACK_2(%0On%1) (FIXES_gsCallbackHooks2|=E_FIXES_On%1*E_FIXES_CALLBACK_HOOKS_2:(funcidx("FIXES_On"#%1)!=-1))

/* 
 * FIXES_CALL_CALLBACK_1(callback, default, format[], ...)
 * FIXES_CALL_CALLBACK_2(callback, default, format[], ...)
 * 
 * Macro to make calling callbacks simpler.  This takes the name of a callback
 * to chain - if it exists then it is called, if it doesn't exist the default
 * is returned.  Note that this DOES NOT end the current function, use in
 * conjunction with "return", or store the value to call the next element in the
 * chain before some bits of processing.
 */
#define FIXES_CALL_CALLBACK_1(%0On%1,%2,%3) ((FIXES_gsCallbackHooks1&E_FIXES_On%1)?(CallLocalFunction("FIXES_On"#%1,%3)):(%2))
#define FIXES_CALL_CALLBACK_2(%0On%1,%2,%3) ((FIXES_gsCallbackHooks2&E_FIXES_On%1)?(CallLocalFunction("FIXES_On"#%1,%3)):(%2))

/*
 * FIXES_BlockUpdate(playerid, bool:block)
 *
 * Block a player from using OnPlayerUpdate at all.
 */
static stock FIXES_BlockUpdate(playerid, bool:block)
{
	if (block)
	{
		FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_BLOCK;
		return 0;
	}
	else
	{
		FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_BLOCK;
		return 1;
	}
}

/* 
 * FIXES_OnScriptInit()
 * 
 * Do all initialisation code in here.  Is called once when the script starts,
 * regardless of HOW the script is started (FilterScript or GameMode).  Add
 * detection of new callbacks here.
 * 
 * FIXES:
 */
static FIXES_OnScriptInit()
{
	FIXES_DETECT_CALLBACK_1(OnGameModeInit);
	FIXES_DETECT_CALLBACK_1(OnFilterScriptInit);
	#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_SetPlayerName || FIX_GetPlayerColor || FIX_GetPlayerSkin || FIX_IsPlayerInCheckpoint || FIX_IsPlayerInRaceCheckpoint || FIX_GetPlayerWeapon || FIX_PutPlayerInVehicle || FIX_OnPlayerEnterVehicle || FIX_AllowTeleport || FIX_OnDialogResponse || FIX_SetSpawnInfo
		FIXES_DETECT_CALLBACK_1(OnPlayerConnect);
	#endif
	#if FIX_SetPlayerAttachedObject || FIX_IsPlayerAttachedObjSlotUsed
		FIXES_DETECT_CALLBACK_1(OnPlayerDisconnect);
	#endif
	#if FIX_GetPlayerSkin || FIX_TogglePlayerControllable
		FIXES_DETECT_CALLBACK_1(OnPlayerSpawn);
	#endif
	#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_AllowInteriorWeapons || FIX_OnPlayerEnterVehicle || FIX_OnPlayerDeath
		FIXES_DETECT_CALLBACK_2(OnPlayerUpdate);
	#endif
	#if FIX_HydraSniper || FIX_GetPlayerWeapon || FIX_PutPlayerInVehicle || FIX_OnPlayerEnterVehicle
		FIXES_DETECT_CALLBACK_1(OnPlayerStateChange);
	#endif
	#if FIX_AllowTeleport
		FIXES_DETECT_CALLBACK_2(OnPlayerClickMap);
	#endif
	#if FIX_OnDialogResponse
		FIXES_DETECT_CALLBACK_2(OnDialogResponse);
	#endif
	#if FIX_OnPlayerDeath
		FIXES_DETECT_CALLBACK_1(OnPlayerDeath);
	#endif
}

/* 
 * OnFilterScriptInit()
 * 
 * Set "IS_FILTERSCRIPT" to true as this callback is ONLY called if this script
 * is actually a FilterScript.  Then call "FIXES_OnScriptInit".
 * 
 * FIXES:
 *     IS_FILTERSCRIPT
 */
public OnFilterScriptInit()
{
	_FIXES_gIsFilterscript = true;
	FIXES_OnScriptInit();
	return FIXES_CALL_CALLBACK_1(OnFilterScriptInit, 1, "");
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit FIXES_OnFilterScriptInit

forward OnFilterScriptInit();

/* 
 * OnGameModeInit()
 * 
 * Call "FIXES_OnScriptInit" if this is not a FilterScript.
 * 
 * FIXES:
 *     IS_FILTERSCRIPT
 *     AllowInteriorWeapons
 *     AllowTeleport
 */
public OnGameModeInit()
{
	if (!_FIXES_gIsFilterscript)
	{
		FIXES_OnScriptInit();
	}
	// =============================
	//  START: AllowInteriorWeapons 
	// =============================
	#if FIX_AllowInteriorWeapons
		FIXES_gsSettings |= e_FIXES_SETTINGS_INTERIOR;
	#endif
	// ===========================
	//  END: AllowInteriorWeapons 
	// ===========================
	
	// ======================
	//  START: AllowTeleport 
	// ======================
	#if FIX_AllowTeleport
		FIXES_gsSettings &= e_FIXES_SETTINGS_ADMIN_TELEPORT;
	#endif
	// ======================
	//  END:   AllowTeleport 
	// ======================
	return FIXES_CALL_CALLBACK_1(OnGameModeInit, 1, "");
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit FIXES_OnGameModeInit

forward OnGameModeInit();

/* 
 * OnPlayerConnect(playerid)
 * 
 * Almost every fix uses this callback for initialisation.  It is only
 * explicitly referenced for those fixes where this is all the code.
 * 
 * FIXES:
 *     TogglePlayerControllable
 *     SetPlayerWorldBounds
 *     GetPlayerColor
 *     SetPlayerName
 *     GetPlayerSkin
 *     IsPlayerInCheckpoint
 *     IsPlayerInRaceCheckpoint
 *     GetPlayerWeapon
 */
#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_SetPlayerName || FIX_GetPlayerColor || FIX_GetPlayerSkin || FIX_IsPlayerInCheckpoint || FIX_IsPlayerInRaceCheckpoint || FIX_GetPlayerWeapon || FIX_PutPlayerInVehicle || FIX_OnPlayerEnterVehicle || FIX_AllowTeleport || FIX_OnDialogResponse || FIX_SetSpawnInfo
	public OnPlayerConnect(playerid)
	{
		#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_PutPlayerInVehicle || FIX_OnPlayerEnterVehicle || FIX_AllowTeleport
			FIXES_gsPlayerBools[playerid] = e_FIXES_BOOLS_NONE;
		#endif
		
		// ======================
		//  START: SetPlayerName 
		// ======================
		#if FIX_SetPlayerName
			new
				name[MAX_PLAYER_NAME];
			GetPlayerName(playerid, name, MAX_PLAYER_NAME);
			if (strcmp(name, "FIXES_TEMP_NAME") == 0)
			{
				Kick(playerid);
			}
		#endif
		// ======================
		//  END:   SetPlayerName 
		// ======================
		
		// =======================
		//  START: SetPlayerColor 
		// =======================
		#if FIX_GetPlayerColor
			SetPlayerColor(playerid, FIXES_gscPlayerColours[playerid % 100]);
		#endif
		// =======================
		//  END:   SetPlayerColor 
		// =======================
		
		// ======================
		//  START: GetPlayerSkin 
		// ======================
		#if FIX_GetPlayerSkin
			FIXES_gsPlayerSkin[playerid] = 0;
		#endif
		// ======================
		//  END:   GetPlayerSkin 
		// ======================
		
		// =============================
		//  START: IsPlayerInCheckpoint 
		// =============================
		#if FIX_IsPlayerInCheckpoint
			DisablePlayerCheckpoint(playerid);
		#endif
		// =============================
		//  END:   IsPlayerInCheckpoint 
		// =============================
		
		// =================================
		//  START: IsPlayerInRaceCheckpoint 
		// =================================
		#if FIX_IsPlayerInRaceCheckpoint
			DisablePlayerRaceCheckpoint(playerid);
		#endif
		// =================================
		//  END:   IsPlayerInRaceCheckpoint 
		// =================================
		
		// ========================
		//  START: GetPlayerWeapon 
		// ========================
		#if FIX_GetPlayerWeapon
			FIXES_gsPlayerWeapon[playerid] = -1;
		#endif
		// ========================
		//  END:   GetPlayerWeapon 
		// ========================
		
		// =========================
		//  START: OnDialogResponse 
		// =========================
		#if FIX_OnDialogResponse
			FIXES_gsDialogID[playerid] = -1;
		#endif
		// =========================
		//  END:   OnDialogResponse 
		// =========================
		
		// =====================
		//  START: SetSpawnInfo 
		// =====================
		#if FIX_SetSpawnInfo
			SetSpawnInfo(playerid, NO_TEAM, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
		#endif
		// =====================
		//  END:   SetSpawnInfo 
		// =====================
		
		return FIXES_CALL_CALLBACK_1(OnPlayerConnect, 1, "i", playerid);
	}
	
	#if defined _ALS_OnPlayerConnect
		#undef OnPlayerConnect
	#else
		#define _ALS_OnPlayerConnect
	#endif
	#define OnPlayerConnect FIXES_OnPlayerConnect
	
	forward OnPlayerConnect(playerid);
#endif

/* 
 * OnPlayerDisonnect(playerid, reason)
 * 
 * FIXES:
 *     SetPlayerAttachedObject
 *     IsPlayerAttachedObjectSlotUsed
 */
#if FIX_SetPlayerAttachedObject || FIX_IsPlayerAttachedObjSlotUsed
	public OnPlayerDisconnect(playerid, reason)
	{
		new
			ret = FIXES_CALL_CALLBACK_1(OnPlayerDisconnect, 1, "ii", playerid, reason);
		
		// ================================
		//  START: SetPlayerAttachedObject 
		// ================================
		#if FIX_SetPlayerAttachedObject
			new
				slot = playerid / _FIXES_ATTACHMENTS,
				shift = playerid % _FIXES_ATTACHMENTS * MAX_PLAYER_ATTACHED_OBJECTS;
			for (new i = 0; i != MAX_PLAYER_ATTACHED_OBJECTS; ++i)
			{
				if (FIXES_gsObjectSlots[slot] & 1 << shift + i)
				{
					RemovePlayerAttachedObject(playerid, i);
				}
			}
			FIXES_gsObjectSlots[slot] &= ~((1 << MAX_PLAYER_ATTACHED_OBJECTS) - 1 << shift);
		#endif
		// ================================
		//  END:   SetPlayerAttachedObject 
		// ================================
		
		// =======================================
		//  START: IsPlayerAttachedObjectSlotUsed 
		// =======================================
		#if FIX_IsPlayerAttachedObjSlotUsed && !FIX_SetPlayerAttachedObject
			FIXES_gsObjectSlots[playerid / _FIXES_ATTACHMENTS] &= ~((1 << MAX_PLAYER_ATTACHED_OBJECTS) - 1 << playerid % _FIXES_ATTACHMENTS * MAX_PLAYER_ATTACHED_OBJECTS);
		#endif
		// =======================================
		//  END:   IsPlayerAttachedObjectSlotUsed 
		// =======================================
		
		return ret;
	}
	
	#if defined _ALS_OnPlayerDisconnect
		#undef OnPlayerDisconnect
	#else
		#define _ALS_OnPlayerDisconnect
	#endif
	#define OnPlayerDisconnect FIXES_OnPlayerDisconnect
	
	forward OnPlayerDisconnect(playerid, reason);
#endif

/* 
 * OnPlayerDeath(playerid, killerid, reason)
 * 
 * FIXES:
 *     OnPlayerDeath
 */
#if FIX_OnPlayerDeath
	public OnPlayerDeath(playerid, killerid, reason)
	{
		// ======================
		//  START: OnPlayerDeath 
		// ======================
		#if FIX_OnPlayerDeath
			static
				sAnimlib[32],
				sAnimname[32];
			GetAnimationName(FIXES_gsLastAnimation[playerid], sAnimlib, sizeof (sAnimlib), sAnimname, sizeof (sAnimname));
			if (!strcmp(sAnimlib, "PED", true))
			{
				ClearAnimations(playerid);
			}
		#endif
		// ======================
		//  END:   OnPlayerDeath 
		// ======================
		
		return FIXES_CALL_CALLBACK_1(OnPlayerDeath, 1, "iii", playerid, killerid, reason);
	}
	
	#if defined _ALS_OnPlayerDeath
		#undef OnPlayerDeath
	#else
		#define _ALS_OnPlayerDeath
	#endif
	#define OnPlayerDeath FIXES_OnPlayerDeath
	
	forward OnPlayerDeath(playerid, killerid, reason);
#endif

/* 
 * FIXES_SpawnPlayer(playerid)
 * 
 * FIXES:
 *     SpawnPlayer
 */
#if FIX_SpawnPlayer
	stock FIXES_SpawnPlayer(playerid)
	{
		new
			vid = GetPlayerVehicleID(playerid);
		if (vid)
		{
			new
				Float:x,
				Float:y,
				Float:z;
			// Remove them without the animation.
			GetVehiclePos(vid, x, y, z);
			SetPlayerPos(playerid, x, y, z);
		}
		return SpawnPlayer(playerid);
	}
	
	#if defined _ALS_SpawnPlayer
		#undef SpawnPlayer
	#else
		
		native BAD_SpawnPlayer(playerid) = SpawnPlayer;
		
		#define _ALS_SpawnPlayer
	#endif
	#define SpawnPlayer FIXES_SpawnPlayer
#endif

/* 
 * FIXES_SetPlayerName(playerid, const name[])
 * 
 * FIXES:
 *     SetPlayerName
 */
#if FIX_SetPlayerName
	stock FIXES_SetPlayerName(playerid, name[])
	{
		if (strcmp(name, "FIXES_TEMP_NAME") == 0)
		{
			return 0;
		}
		
		new old_name[MAX_PLAYER_NAME];
		
		GetPlayerName(playerid, old_name, sizeof(old_name));
		
		if (strcmp(name, old_name, true) == 0)
		{
			return 0;
		}
		
		SetPlayerName(playerid, "FIXES_TEMP_NAME");
		
		new retval = SetPlayerName(playerid, name);
		
		if (retval != 1)
		{
			SetPlayerName(playerid, old_name);
		}
		
		return retval;
	}
	#if defined _ALS_SetPlayerName
		#undef SetPlayerName
	#else
		
		native BAD_SetPlayerName(playerid, const name[]) = SetPlayerName;
		
		#define _ALS_SetPlayerName
	#endif
	#define SetPlayerName FIXES_SetPlayerName
#endif

/* 
 * OnPlayerSpawn(playerid)
 * 
 * FIXES:
 *     GetPlayerSkin
 *     TogglePlayerControllable
 */
#if FIX_GetPlayerSkin || FIX_TogglePlayerControllable
	public OnPlayerSpawn(playerid)
	{
		// ======================
		//  START: GetPlayerSkin 
		// ======================
		#if FIX_GetPlayerSkin
			FIXES_gsPlayerSkin[playerid] = GetPlayerSkin(playerid);
		#endif
		// ======================
		//  END:   GetPlayerSkin 
		// ======================
		
		// =================================
		//  START: TogglePlayerControllable 
		// =================================
		#if FIX_TogglePlayerControllable
			FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_UNCONTROLLABLE;
		#endif
		// =================================
		//  END:   TogglePlayerControllable 
		// =================================
		
		return FIXES_CALL_CALLBACK_1(OnPlayerSpawn, 1, "i", playerid);
	}
	
	#if defined _ALS_OnPlayerSpawn
		#undef OnPlayerSpawn
	#else
		#define _ALS_OnPlayerSpawn
	#endif
	#define OnPlayerSpawn FIXES_OnPlayerSpawn
	
	forward OnPlayerSpawn(playerid);
#endif

/* 
 * FIXES_SetPlayerSkin(playerid, skinid)
 * 
 * FIXES:
 *     GetPlayerSkin
 *     SetPlayerSkin
 */
#if FIX_GetPlayerSkin || FIX_SetPlayerSkin
	stock FIXES_SetPlayerSkin(playerid, skinid)
	{
		// ======================
		//  START: SetPlayerSkin 
		// ======================
		#if FIX_SetPlayerSkin
			new
				vehicleid = GetPlayerVehicleID(playerid);
			if (vehicleid)
			{
				new
					seat = GetPlayerVehicleSeat(playerid);
				ClearAnimations(playerid);
				new
					ret = SetPlayerSkin(playerid, skinid);
				PutPlayerInVehicle(playerid, vehicleid, seat);
				
				// ======================
				//  START: GetPlayerSkin 
				// ======================
				#if FIX_GetPlayerSkin
					FIXES_gsPlayerSkin[playerid] = skinid;
				#endif
				// ======================
				//  END:   GetPlayerSkin 
				// ======================
				
				return ret;
			}
			
			// ======================
			//  START: GetPlayerSkin 
			// ======================
			#if FIX_GetPlayerSkin
				else
			#endif
			// ======================
			//  END:   GetPlayerSkin 
			// ======================
		#endif
		// ======================
		//  END:   SetPlayerSkin 
		// ======================
		
		// ======================
		//  START: GetPlayerSkin 
		// ======================
		#if FIX_GetPlayerSkin
			if (0 <= playerid < MAX_PLAYERS)
			{
				FIXES_gsPlayerSkin[playerid] = skinid;
			}
		#endif
		// ======================
		//  END:   GetPlayerSkin 
		// ======================
		
		return SetPlayerSkin(playerid, skinid);
	}
	
	#if defined _ALS_SetPlayerSkin
		#undef SetPlayerSkin
	#else
		
		native BAD_SetPlayerSkin(playerid, skinid) = SetPlayerSkin;
		
		#define _ALS_SetPlayerSkin
	#endif
	#define SetPlayerSkin FIXES_SetPlayerSkin
#endif

/* 
 * FIXES_GetPlayerSkin(playerid, skinid)
 * 
 * FIXES:
 *     GetPlayerSkin
 */
#if FIX_GetPlayerSkin
	stock FIXES_GetPlayerSkin(playerid)
	{
		if (0 <= playerid < MAX_PLAYERS)
		{
			return FIXES_gsPlayerSkin[playerid];
		}
		return 0;
	}
	
	#if defined _ALS_GetPlayerSkin
		#undef GetPlayerSkin
	#else
		
		native BAD_GetPlayerSkin(playerid) = GetPlayerSkin;
		
		#define _ALS_GetPlayerSkin
	#endif
	#define GetPlayerSkin FIXES_GetPlayerSkin
#endif

/* 
 * FIXES_GetWeaponName(weaponid, weapon[], len)
 * 
 * FIXES:
 *     GetWeaponName
 */
#if FIX_GetWeaponName
	stock FIXES_GetWeaponName(weaponid, weapon[], len)
	{
		switch (weaponid)
		{
			case 18:
			{
				weapon[0] = 0;
				strcat(weapon, "Molotov Cocktail", len);
				return 1;
			}
			case 44:
			{
				weapon[0] = 0;
				strcat(weapon, "Thermal Goggles", len);
				return 1;
			}
			case 45:
			{
				weapon[0] = 0;
				strcat(weapon, "Night vision Goggles", len);
				return 1;
			}
			default:
			{
				return GetWeaponName(weaponid, weapon, len);
			}
		}
		return 0;
	}
	
	#if defined _ALS_GetWeaponName
		#undef GetWeaponName
	#else
		
		native BAD_GetWeaponName(weaponid, weapon[], len) = GetWeaponName;
		
		#define _ALS_GetWeaponName
	#endif
	#define GetWeaponName FIXES_GetWeaponName
#endif

/* 
 * OnPlayerUpdate(playerid)
 * 
 * FIXES:
 *     SetPlayerWorldBounds
 *     TogglePlayerControllable
 *     AllowInteriorWeapons
 *     OnPlayerDeath
 */
#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable || FIX_AllowInteriorWeapons || FIX_OnPlayerEnterVehicle || FIX_OnPlayerDeath
	public OnPlayerUpdate(playerid)
	{
		// =============================
		//  BEGIN: OnPlayerEnterVehicle 
		// =============================
		#if FIX_OnPlayerEnterVehicle
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_BLOCK)
			{
				return 0;
			}
		#endif
		// =============================
		//  END:   OnPlayerEnterVehicle 
		// =============================
		
		// =============================
		//  START: AllowInteriorWeapons 
		// =============================
		#if FIX_AllowInteriorWeapons
			if (!(FIXES_gsSettings & e_FIXES_SETTINGS_INTERIOR) && GetPlayerInterior(playerid) && GetPlayerWeapon(playerid))
			{
				SetPlayerArmedWeapon(playerid, 0);
			}
		#endif
		// ============================
		//  END: AllowInteriorWeapons 
		// ============================
		
		#if FIX_SetPlayerWorldBounds || FIX_TogglePlayerControllable
			new
				ud,
				lr,
				keys;
			GetPlayerKeys(playerid, keys, ud, lr);
		#endif
		
		#if FIX_SetPlayerWorldBounds && !FIX_TogglePlayerControllable
			#pragma unused ud, lr
		#endif
		
		// =============================
		//  START: SetPlayerWorldBounds 
		// =============================
		#if FIX_SetPlayerWorldBounds
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_WORLDBOUNDS && keys & _FIXES_KEY_AIM)
			{
				new
					Float:x,
					Float:y,
					Float:z;
				GetPlayerPos(playerid, x, y, z);
				if (FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LX] < x < FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UX] && FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LY] < y < FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UY])
				{
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PX] = x;
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PY] = y;
					FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PZ] = z;
				}
				else
				{
					SetPlayerPos(playerid, FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PX], FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PY], FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PZ]);
				}
			}
		#endif
		// =============================
		//  END:   SetPlayerWorldBounds 
		// =============================
		
		// ======================
		//  START: OnPlayerDeath 
		// ======================
		#if FIX_OnPlayerDeath
			FIXES_gsLastAnimation[playerid] = GetPlayerAnimationIndex(playerid);
		#endif
		// ======================
		//  END:   OnPlayerDeath 
		// ======================
		
		// =================================
		//  START: TogglePlayerControllable 
		// =================================
		#if FIX_TogglePlayerControllable
			// MUST come last.
			if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_UNCONTROLLABLE)
			{
				// Keys based sync blocking, modified based on a post by Slice:
				// http://forum.sa-mp.com/showpost.php?p=876854&postcount=1
				// Use "playerid" here as it's a variable that already exists,
				// but note that after this point, you CANNOT use "playerid" as
				// it has been "clobbered" (and yes, that's the technical term).
				// This is just to avoid "statement has no effect" warnings.
				// ALWAYS return 0 in this case, regardless of what other
				// callbacks return.
				playerid = FIXES_CALL_CALLBACK_2(OnPlayerUpdate, 1, "i", playerid);
				if (keys || ud || lr)
				{
					return 0;
				}
				else
				{
					return playerid;
				}
			}
			else
			{
				return FIXES_CALL_CALLBACK_2(OnPlayerUpdate, 1, "i", playerid);
			}
		#else
			return 1;
		#endif
		// =================================
		//  END:   TogglePlayerControllable 
		// =================================
	}
	
	#if defined _ALS_OnPlayerUpdate
		#undef OnPlayerUpdate
	#else
		#define _ALS_OnPlayerUpdate
	#endif
	#define OnPlayerUpdate FIXES_OnPlayerUpdate
	
	forward OnPlayerUpdate(playerid);
#endif

/* 
 * FIXES_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min)
 * 
 * TODO: Modify this to remove aim animations when they get to the boundaries.
 * 
 * FIXES:
 *     SetPlayerWorldBounds
 */
#if FIX_SetPlayerWorldBounds
	stock FIXES_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min)
	{
		if (0 <= playerid < MAX_PLAYERS)
		{
			// This code could do with a way to mostly remove the checks.  Maybe
			// when setting everything to FIXES_INFINITY (with default
			// parameters).
			FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_WORLDBOUNDS;
			new
				Float:tmp;
			if (x_max < x_min)
			{
				tmp = x_min;
				x_min = x_max;
				x_max = tmp;
			}
			if (y_max < y_min)
			{
				tmp = y_min;
				y_min = y_max;
				y_max = tmp;
			}
			// Give a little leway so this fix isn't noticed if you're not
			// trying to break through the world bounds.  Leway removed in
			// favour of keys.
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LX] = x_min;
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UX] = x_max;
			
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_LY] = y_min;
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_UY] = y_max;
			
			GetPlayerPos(playerid, tmp, tmp, tmp);
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PX] = (x_max - x_min) / 2 + x_min;
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PY] = (y_max - y_min) / 2 + y_min;
			FIXES_gsWorldbounds[playerid][E_FIXES_WORLDBOUND_DATA_PZ] = tmp;
			
			return SetPlayerWorldBounds(playerid, x_max, x_min, y_max, y_min);
		}
		return 0;
	}
	
	#if defined _ALS_SetPlayerWorldBounds
		#undef SetPlayerWorldBounds
	#else
		
		native BAD_SetPlayerWorldBounds(playerid, Float:x_max, Float:x_min, Float:y_max, Float:y_min) = SetPlayerWorldBounds;
		
		#define _ALS_SetPlayerWorldBounds
	#endif
	#define SetPlayerWorldBounds FIXES_SetPlayerWorldBounds
#endif

/* 
 * FIXES_TogglePlayerControllable(playerid, toggle)
 * 
 * FIXES:
 *     TogglePlayerControllable
 */
#if FIX_TogglePlayerControllable
	stock FIXES_TogglePlayerControllable(playerid, toggle)
	{
		if (0 <= playerid < MAX_PLAYERS)
		{
			if (toggle)
			{
				FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_UNCONTROLLABLE;
			}
			else
			{
				FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_UNCONTROLLABLE;
			}
			return TogglePlayerControllable(playerid, toggle);
		}
		return 0;
	}
	
	#if defined _ALS_TogglePlayerControllable
		#undef TogglePlayerControllable
	#else
		
		native BAD_TogglePlayerControllable(playerid, toggle) = TogglePlayerControllable;
		
		#define _ALS_TogglePlayerControllable
	#endif
	#define TogglePlayerControllable FIXES_TogglePlayerControllable
#endif

/* 
 * OnPlayerStateChange(playerid, newstate, oldstate)
 * 
 * FIXES:
 *     HydraSniper
 *     GetPlayerWeapon
 *     PutPlayerInVehicle
 */
#if FIX_HydraSniper || FIX_GetPlayerWeapon || FIX_PutPlayerInVehicle || FIX_OnPlayerEnterVehicle
	public OnPlayerStateChange(playerid, newstate, oldstate)
	{
		// =============================
		//  BEGIN: OnPlayerEnterVehicle 
		// =============================
		#if FIX_OnPlayerEnterVehicle
				if (newstate == PLAYER_STATE_PASSENGER)
				{
					new
						model = GetVehicleModel(GetPlayerVehicleID(playerid));
					if (400 <= model <= 611)
					{
						model -= 400;
						new
							seat = GetPlayerVehicleSeat(playerid);
						if (seat != 128)
						{
							model = (FIXES_gscMaxPassengers[model >>> 3] >>> ((model & 7) << 2)) & 0xF;
							if (model == 0 || model == 15)
							{
								// Shouldn't be in this vehicle at all.
								FIXES_BlockUpdate(playerid, true);
								Kick(playerid);
							}
							else if (!(0 < seat <= model))
							{
								// In an out of range seat.
								FIXES_BlockUpdate(playerid, true);
								Kick(playerid);
							}
						}
					}
					else
					{
						FIXES_BlockUpdate(playerid, true);
						Kick(playerid);
					}
				}
				else if (newstate == PLAYER_STATE_DRIVER)
				{
						new
							model = GetPlayerVehicleSeat(playerid);
						if (model != 128)
						{
							if (model == 0)
							{
								model = GetVehicleModel(GetPlayerVehicleID(playerid));
								if (!(400 <= model <= 611) || FIXES_gscMaxPassengers[model - 400 >>> 3] >>> ((model - 400 & 7) << 2) & 0xF == 15)
								{
									// In an invalid vehicle (one you can't drive).
									FIXES_BlockUpdate(playerid, true);
									Kick(playerid);
								}
							}
							else
							{
								// They are a driver, but not in the driver's seat.
								FIXES_BlockUpdate(playerid, true);
								Kick(playerid);
							}
						}
					#if FIX_HydraSniper
						else
						{
							model = GetVehicleModel(GetPlayerVehicleID(playerid));
						}
					#endif
			#if !FIX_HydraSniper
				}
			#endif
		#endif
		// =============================
		//  END:   OnPlayerEnterVehicle 
		// =============================
		
		// ====================
		//  BEGIN: HydraSniper 
		// ====================
		#if FIX_HydraSniper
			#if !FIX_OnPlayerEnterVehicle
				if (newstate == PLAYER_STATE_DRIVER)
				{
					new
						model = GetVehicleModel(GetPlayerVehicleID(playerid));
			#endif
					if (model == 520 || model == 425)
					{
						SetPlayerArmedWeapon(playerid, 0);
						#if FIX_GetPlayerWeapon
							// This is the first cross-dependednt fix.
							FIXES_gsPlayerWeapon[playerid] = 0;
						#endif
					}
			}
		#endif
		// ====================
		//  END:   HydraSniper 
		// ====================
		
		#if FIX_GetPlayerWeapon || FIX_PutPlayerInVehicle
			if (oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER)
			{
				// ========================
				//  BEGIN: GetPlayerWeapon 
				// ========================
				#if FIX_GetPlayerWeapon
					FIXES_gsPlayerWeapon[playerid] = -1;
				#endif
				// ========================
				//  END:   GetPlayerWeapon 
				// ========================
				
				// ===========================
				//  START: PutPlayerInVehicle 
				// ===========================
				#if FIX_PutPlayerInVehicle
					// Update their vehicle once we KNOW the client has done
					// the removeal from the vehicle.
					if (FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_PUT_IN_VEHICLE)
					{
						// Limited to "only" 16777216 vehicles and 256 seats.
						PutPlayerInVehicle(playerid, FIXES_gsVehicleSeatData[playerid] & 0x00FFFFFF, FIXES_gsVehicleSeatData[playerid] >>> 24);
						FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_PUT_IN_VEHICLE;
					}
				#endif
				// ===========================
				//  END:   PutPlayerInVehicle 
				// ===========================
			}
		#endif
		
		return FIXES_CALL_CALLBACK_1(OnPlayerStateChange, 1, "iii", playerid, newstate, oldstate);
	}
	
	#if defined _ALS_OnPlayerStateChange
		#undef OnPlayerStateChange
	#else
		#define _ALS_OnPlayerStateChange
	#endif
	#define OnPlayerStateChange FIXES_OnPlayerStateChange
	
	forward OnPlayerStateChange(playerid, newstate, oldstate);
#endif

/* 
 * FIXES_SetPlayerArmedWeapon(playerid, weaponid)
 * 
 * FIXES:
 *     GetPlayerWeapon
 */
#if FIX_GetPlayerWeapon
	stock FIXES_SetPlayerArmedWeapon(playerid, weaponid)
	{
		if (IsPlayerInAnyVehicle(playerid))
		{
			FIXES_gsPlayerWeapon[playerid] = weaponid;
		}
		return SetPlayerArmedWeapon(playerid, weaponid);
	}
	
	#if defined _ALS_SetPlayerArmedWeapon
		#undef SetPlayerArmedWeapon
	#else
		
		native BAD_SetPlayerArmedWeapon(playerid, weaponid) = SetPlayerArmedWeapon;
		
		#define _ALS_SetPlayerArmedWeapon
	#endif
	#define SetPlayerArmedWeapon FIXES_SetPlayerArmedWeapon
#endif

/* 
 * FIXES_GetPlayerWeapon(playerid)
 * 
 * FIXES:
 *     GetPlayerWeapon
 */
#if FIX_GetPlayerWeapon
	stock FIXES_GetPlayerWeapon(playerid)
	{
		if (0 <= playerid < MAX_PLAYERS)
		{
			if (FIXES_gsPlayerWeapon[playerid] == -1)
			{
				return GetPlayerWeapon(playerid);
			}
			return FIXES_gsPlayerWeapon[playerid];
		}
		return 0;
	}
	
	#if defined _ALS_GetPlayerWeapon
		#undef GetPlayerWeapon
	#else
		
		native BAD_GetPlayerWeapon(playerid) = GetPlayerWeapon;
		
		#define _ALS_GetPlayerWeapon
	#endif
	#define GetPlayerWeapon FIXES_GetPlayerWeapon
#endif

/* 
 * FIXES_PutPlayerInVehicle(playerid, vehicleid, seatid)
 * 
 * FIXES:
 *     PutPlayerInVehicle
 */
#if FIX_PutPlayerInVehicle
	stock FIXES_PutPlayerInVehicle(playerid, vehicleid, seatid)
	{
		new
			vid = GetPlayerVehicleID(playerid);
		if (vid)
		{
			new
				Float:x,
				Float:y,
				Float:z;
			// Remove them without the animation.
			GetVehiclePos(vid, x, y, z);
			SetPlayerPos(playerid, x, y, z);
			FIXES_gsVehicleSeatData[playerid] = seatid << 24 | vehicleid;
			FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_PUT_IN_VEHICLE;
			return 1;
		}
		return PutPlayerInVehicle(playerid, vehicleid, seatid);
	}
	
	#if defined _ALS_PutPlayerInVehicle
		#undef PutPlayerInVehicle
	#else
		
		native BAD_PutPlayerInVehicle(playerid, vehicleid, seatid) = PutPlayerInVehicle;
		
		#define _ALS_PutPlayerInVehicle
	#endif
	#define PutPlayerInVehicle FIXES_PutPlayerInVehicle
#endif

/*
 * FIXES_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size)
 *
 * FIXES:
 *     SetPlayerCheckpoint
 */
#if FIX_SetPlayerCheckpoint
	stock FIXES_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size)
	{
			DisablePlayerCheckpoint(playerid);
			return SetPlayerCheckpoint(playerid, x, y, z, size);
	}
	
	#if defined _ALS_SetPlayerCheckpoint
		#undef SetPlayerCheckpoint
	#else
		
		native BAD_SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size) = SetPlayerCheckpoint;
		
		#define _ALS_SetPlayerCheckpoint
	#endif
	#define SetPlayerCheckpoint FIXES_SetPlayerCheckpoint
#endif

/*
 * FIXES_SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size)
 *
 * FIXES:
 *     SetPlayerRaceCheckpoint
 */
#if FIX_SetPlayerRaceCheckpoint
	stock FIXES_SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size)
	{
		DisablePlayerRaceCheckpoint(playerid);
		return SetPlayerRaceCheckpoint(playerid, type, x, y, z, nextx, nexty, nextz, size);
	}
	
	#if defined _ALS_SetPlayerRaceCheckpoint
		#undef SetPlayerRaceCheckpoint
	#else
		
		native BAD_SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size) = SetPlayerRaceCheckpoint;
		
		#define _ALS_SetPlayerRaceCheckpoint
	#endif
	#define SetPlayerRaceCheckpoint FIXES_SetPlayerRaceCheckpoint
#endif

/*
 * Text:FIXES_TextDrawCreate(Float:x, Float:y, text[])
 *
 * FIXES:
 *     TextDrawCreate
 */
#if FIX_TextDrawCreate
	stock Text:FIXES_TextDrawCreate(Float:x, Float:y, text[])
	{
		if (text[0] == '\0' || text[0] == '\1' && text[1] == '\0')
		{
			return TextDrawCreate(x, y, " ");
		}
		else
		{
			return TextDrawCreate(x, y, text);
		}
	}
	
	#if defined _ALS_TextDrawCreate
		#undef TextDrawCreate
	#else
		
		native Text:BUG_TextDrawCreate(Float:x, Float:y, text[]) = TextDrawCreate;
		
		#define _ALS_TextDrawCreate
	#endif
	#define TextDrawCreate FIXES_TextDrawCreate
#endif

/*
 * FIXES_TextDrawSetString(Text:text, string[])
 *
 * FIXES:
 *     TextDrawSetString
 */
#if FIX_TextDrawSetString
	stock FIXES_TextDrawSetString(Text:text, string[])
	{
		if (string[0] == '\0' || string[0] == '\1' && string[1] == '\0')
		{
			return TextDrawSetString(text, " ");
		}
		else
		{
			return TextDrawSetString(text, string);
		}
	}
	
	#if defined _ALS_TextDrawSetString
		#undef TextDrawSetString
	#else
		
		native BAD_TextDrawSetString(Text:text, string[]) = TextDrawSetString;
		
		#define _ALS_TextDrawSetString
	#endif
	#define TextDrawSetString FIXES_TextDrawSetString
#endif

/*
 * FIXES_AllowInteriorWeapons(allow)
 *
 * FIXES:
 *     AllowInteriorWeapons
 */
#if FIX_AllowInteriorWeapons
	stock FIXES_AllowInteriorWeapons(allow)
	{
		if (allow)
		{
			FIXES_gsSettings |= e_FIXES_SETTINGS_INTERIOR;
		}
		else
		{
			FIXES_gsSettings &= ~e_FIXES_SETTINGS_INTERIOR;
		}
		return allow;
	}
	
	#if defined _ALS_AllowInteriorWeapons
		#undef AllowInteriorWeapons
	#else
		
		native BAD_AllowInteriorWeapons(allow) = AllowInteriorWeapons;
		
		#define _ALS_AllowInteriorWeapons
	#endif
	#define AllowInteriorWeapons FIXES_AllowInteriorWeapons
#endif

/* 
 * OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
 * 
 * FIXES:
 *     AllowTeleport
 */
#if FIX_AllowTeleport
	public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
	{
		// ======================
		//  BEGIN: AllowTeleport 
		// ======================
		#if FIX_AllowTeleport
			if ((FIXES_gsPlayerBools[playerid] & e_FIXES_BOOLS_TELEPORT) || ((FIXES_gsSettings & e_FIXES_SETTINGS_ADMIN_TELEPORT) && (IsPlayerAdmin(playerid))))
			{
				SetPlayerPosFindZ(playerid, fX, fY, fZ);
			}
		#endif
		// ======================
		//  END:   AllowTeleport 
		// ======================
		return FIXES_CALL_CALLBACK_2(OnPlayerClickMap, 1, "ifff", playerid, fX, fY, fZ);
	}
	
	#if defined _ALS_OnPlayerClickMap
		#undef OnPlayerClickMap
	#else
		#define _ALS_OnPlayerClickMap
	#endif
	#define OnPlayerClickMap FIXES_OnPlayerClickMap
	
	forward OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ);
#endif

/*
 * FIXES_AllowPlayerTeleport(playerid, allow)
 *
 * FIXES:
 *     AllowTeleport
 */
#if FIX_AllowTeleport
	stock FIXES_AllowPlayerTeleport(playerid, allow)
	{
		if (0 <= playerid < MAX_PLAYERS)
		{
			if (allow)
			{
				FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_TELEPORT;
			}
			else
			{
				FIXES_gsPlayerBools[playerid] &= ~e_FIXES_BOOLS_TELEPORT;
			}
			return allow;
		}
		return 0;
	}
	
	#if defined _ALS_AllowPlayerTeleport
		#undef AllowPlayerTeleport
	#else
		
		native BAD_AllowPlayerTeleport(playerid, allow) = AllowPlayerTeleport;
		
		#define _ALS_AllowPlayerTeleport
	#endif
	#define AllowPlayerTeleport FIXES_AllowPlayerTeleport
#endif

/*
 * FIXES_AllowAdminTeleport(allow)
 *
 * FIXES:
 *     AllowTeleport
 */
#if FIX_AllowTeleport
	stock FIXES_AllowAdminTeleport(allow)
	{
		if (allow)
		{
			FIXES_gsSettings |= e_FIXES_SETTINGS_ADMIN_TELEPORT;
		}
		else
		{
			FIXES_gsSettings &= ~e_FIXES_SETTINGS_ADMIN_TELEPORT;
		}
		return allow;
	}
	
	#if defined _ALS_AllowAdminTeleport
		#undef AllowAdminTeleport
	#else
		
		native BAD_AllowAdminTeleport(allow) = AllowAdminTeleport;
		
		#define _ALS_AllowAdminTeleport
	#endif
	#define AllowAdminTeleport FIXES_AllowAdminTeleport
#endif

/*
 * FIXES_SetPlayerSpecialAction(playerid, actionid)
 *
 * FIXES:
 *     SetPlayerSpecialAction
 */
#if FIX_SetPlayerSpecialAction
	stock FIXES_SetPlayerSpecialAction(playerid, actionid)
	{
		if (GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK) 
		{
			ClearAnimations(playerid);
		}
		SetPlayerSpecialAction(playerid, actionid);
		return 1;
	}
	
	#if defined _ALS_SetPlayerSpecialAction
		#undef SetPlayerSpecialAction
	#else
		
		native BAD_SetPlayerSpecialAction(playerid, actionid) = SetPlayerSpecialAction;
		
		#define _ALS_SetPlayerSpecialAction
	#endif
	#define SetPlayerSpecialAction FIXES_SetPlayerSpecialAction
#endif

/*
 * FIXES_ShowPlayerDialog(playerid, dialog, style, title[], caption[], button1[], button2[])
 *
 * FIXES:
 *     OnDialogResponse
 */
#if FIX_OnDialogResponse
	stock FIXES_ShowPlayerDialog(playerid, dialog, style, title[], caption[], button1[], button2[])
	{
		if (0 <= playerid < MAX_PLAYERS)
		{
			FIXES_gsDialogID[playerid] = dialog;
			return ShowPlayerDialog(playerid, dialog, style, title, caption, button1, button2);
		}
		return 0;
	}
	
	#if defined _ALS_ShowPlayerDialog
		#undef ShowPlayerDialog
	#else
		
		native BAD_ShowPlayerDialog(playerid, dialog, style, title[], caption[], button1[], button2[]) = ShowPlayerDialog;
		
		#define _ALS_ShowPlayerDialog
	#endif
	#define ShowPlayerDialog FIXES_ShowPlayerDialog
#endif

/* 
 * OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
 * 
 * FIXES:
 *     OnDialogResponse
 */
#if FIX_OnDialogResponse
	public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
	{
		// =========================
		//  BEGIN: OnDialogResponse 
		// =========================
		#if FIX_OnDialogResponse
			if (inputtext[0])
			{
				return FIXES_CALL_CALLBACK_2(OnDialogResponse, 1, "iiiis", playerid, FIXES_gsDialogID[playerid], response, listitem, inputtext);
			}
			else
			{
				return FIXES_CALL_CALLBACK_2(OnDialogResponse, 1, "iiiis", playerid, FIXES_gsDialogID[playerid], response, listitem, "\1\0");
			}
		#endif
		// =========================
		//  END:   OnDialogResponse 
		// =========================
	}
	
	#if defined _ALS_OnDialogResponse
		#undef OnDialogResponse
	#else
		#define _ALS_OnDialogResponse
	#endif
	#define OnDialogResponse FIXES_OnDialogResponse
	
	forward OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

/*
 * FIXES_GetPlayerDialog(playerid)
 *
 * FIXES:
 *     GetPlayerDialog
 */
#if FIX_GetPlayerDialog
	#if FIX_OnDialogResponse
		stock FIXES_GetPlayerDialog(playerid)
		{
			if (0 <= playerid < MAX_PLAYERS)
			{
				return FIXES_gsDialogID[playerid];
			}
			return -1;
		}
		
		#if defined _ALS_GetPlayerDialog
			#undef GetPlayerDialog
		#else
			#define _ALS_GetPlayerDialog
		#endif
		#define GetPlayerDialog FIXES_GetPlayerDialog
	#else
		#error FIX_GetPlayerDialog requires FIX_OnDialogResponse.
	#endif
#endif

/*
 * FIXES_HideMenuForPlayer(Menu:menuid, playerid
 *
 * FIXES:
 *     HideMenuForPlayer
 */
#if FIX_HideMenuForPlayer
	stock FIXES_HideMenuForPlayer(Menu:menuid, playerid)
	{
		if (IsValidMenu(menuid))
		{
			return HideMenuForPlayer(menuid, playerid);
		}
		return 0;
	}
	
	#if defined _ALS_HideMenuForPlayer
		#undef HideMenuForPlayer
	#else
		
		native BAD_HideMenuForPlayer(Menu:menuid, playerid) = HideMenuForPlayer;
		
		#define _ALS_HideMenuForPlayer
	#endif
	#define HideMenuForPlayer FIXES_HideMenuForPlayer
#endif

/*
 * FIXES_valstr(dest[], value, bool:pack = false)
 *
 * FIXES:
 *     valstr
 */
#if FIX_valstr
	stock FIXES_valstr(dest[], value, bool:pack = false)
	{
		// "format" can't handle cellmin properly.
		static const
			sc_szCellmin[] = !"-2147483648";
		if (value == cellmin)
		{
			pack && strpack(dest, sc_szCellmin, 12) || strunpack(dest, sc_szCellmin, 12);
		}
		else
		{
			format(dest, 12, "%d", value);
			pack && strpack(dest, dest, 12);
		}
		return 0;
	}
	
	#if defined _ALS_valstr
		#undef valstr
	#else
		
		native BAD_valstr(dest[], value, bool:pack = false) = valstr;
		
		#define _ALS_valstr
	#endif
	#define valstr FIXES_valstr
#endif

/*
 * FIXES_fclose(File:handle)
 *
 * FIXES:
 *     fclose
 */
#if FIX_fclose
	stock bool:FIXES_fclose(File:handle)
	{
		if (handle)
		{
			return fclose(handle);
		}
		return false;
	}
	
	#if defined _ALS_fclose
		#undef fclose
	#else
		
		native BAD_fclose(File:handle) = fclose;
		
		#define _ALS_fclose
	#endif
	#define fclose FIXES_fclose
#endif

/*
 * FIXES_fwrite(File:handle, const string[])
 *
 * FIXES:
 *     fwrite
 */
#if FIX_fwrite
	stock FIXES_fwrite(File:handle, const string[])
	{
		if (handle)
		{
			return fwrite(handle, string);
		}
		return 0;
	}
	
	#if defined _ALS_fwrite
		#undef fwrite
	#else
		
		native BAD_fwrite(File:handle, const string[]) = fwrite;
		
		#define _ALS_fwrite
	#endif
	#define fwrite FIXES_fwrite
#endif

/*
 * FIXES_fread(File:handle, string[], size = sizeof (string), bool:pack = false)
 *
 * FIXES:
 *     fread
 */
#if FIX_fread
	stock FIXES_fread(File:handle, string[], size = sizeof (string), bool:pack = false)
	{
		if (handle)
		{
			return fread(handle, string, size, pack);
		}
		return 0;
	}
	
	#if defined _ALS_fread
		#undef fread
	#else
		
		native BAD_fread(File:handle, string[], size = sizeof (string), bool:pack = false) = fread;
		
		#define _ALS_fread
	#endif
	#define fread FIXES_fread
#endif

/*
 * FIXES_fputchar(File:handle, value, bool:utf8 = true)
 *
 * FIXES:
 *     fputchar
 */
#if FIX_fputchar
	stock bool:FIXES_fputchar(File:handle, value, bool:utf8 = true)
	{
		if (handle)
		{
			return fputchar(handle, value, utf8);
		}
	   return false;
	}
	
	#if defined _ALS_fputchar
		#undef fputchar
	#else
		
		native BAD_fputchar(File:handle, value, bool:utf8 = true) = fputchar;
		
		#define _ALS_fputchar
	#endif
	#define fputchar FIXES_fputchar
#endif

/*
 * FIXES_fgetchar(File:handle, value, bool:utf8 = true)
 *
 * FIXES:
 *     fgetchar
 */
#if FIX_fgetchar
	stock FIXES_fgetchar(File:handle, value, bool:utf8 = true)
	{
		if (handle)
		{
			return fgetchar(handle, value, utf8);
		}
		return 0;
	}
	
	#if defined _ALS_fgetchar
		#undef fgetchar
	#else
		
		native BAD_fgetchar(File:handle, value, bool:utf8 = true) = fgetchar;
		
		#define _ALS_fgetchar
	#endif
	#define fgetchar FIXES_fgetchar
#endif

/*
 * FIXES_fblockwrite(File:handle, const buffer[], size = sizeof (buffer))
 *
 * FIXES:
 *     fblockwrite
 */
#if FIX_fblockwrite
	stock FIXES_fblockwrite(File:handle, const buffer[], size = sizeof (buffer))
	{
		if (handle)
		{
			return fblockwrite(handle, buffer, size);
		}
		return 0;
	}
	
	#if defined _ALS_fblockwrite
		#undef fblockwrite
	#else
		
		native BAD_fblockwrite(File:handle, const buffer[], size = sizeof (buffer)) = fblockwrite;
		
		#define _ALS_fblockwrite
	#endif
	#define fblockwrite FIXES_fblockwrite
#endif

/*
 * FIXES_fblockread(File:handle, buffer[], size = sizeof (buffer))
 *
 * FIXES:
 *     fblockread
 */
#if FIX_fblockread
	stock FIXES_fblockread(File:handle, buffer[], size = sizeof (buffer))
	{
		if (handle)
		{
			return fblockread(handle, buffer, size);
		}
		return 0;
	}
	
	#if defined _ALS_fblockread
		#undef fblockread
	#else
		
		native BAD_fblockread(File:handle, buffer[], size = sizeof (buffer)) = fblockread;
		
		#define _ALS_fblockread
	#endif
	#define fblockread FIXES_fblockread
#endif

/*
 * FIXES_fseek(File:handle, position = 0, seek_whence:whence = seek_start)
 *
 * FIXES:
 *     fseek
 */
#if FIX_fseek
	stock FIXES_fseek(File:handle, position = 0, seek_whence:whence = seek_start)
	{
		if (handle)
		{
			return fseek(handle, position, whence);
		}
		return 0;
	}
	
	#if defined _ALS_fseek
		#undef fseek
	#else
		
		native BAD_fseek(File:handle, position = 0, seek_whence:whence = seek_start) = fseek;
		
		#define _ALS_fseek
	#endif
	#define fseek FIXES_fseek
#endif

/*
 * FIXES_flength(File:handle)
 *
 * FIXES:
 *     flength
 */
#if FIX_flength
	stock FIXES_flength(File:handle)
	{
		if (handle)
		{
			return flength(handle);
		}
		return 0;
	}
	
	#if defined _ALS_flength
		#undef flength
	#else
		
		native BAD_flength(File:handle) = flength;
		
		#define _ALS_flength
	#endif
	#define flength FIXES_flength
#endif

/*
 * FIXES_IsPAttachedObjectSlotUsed(playerid, index)
 *
 * FIXES:
 *     IsPlayerAttachedObjectSlotUsed
 */
#if FIX_IsPlayerAttachedObjSlotUsed
	stock FIXES_IsPAttachedObjectSlotUsed(playerid, index)
	{
		if (IsPlayerConnected(playerid))
		{
			return FIXES_gsObjectSlots[playerid / _FIXES_ATTACHMENTS] & 1 << playerid % _FIXES_ATTACHMENTS * MAX_PLAYER_ATTACHED_OBJECTS + index;
		}
		return 0;
	}
	
	#if defined _ALS_IsPAttachedObjSlotUsed
		#undef IsPlayerAttachedObjectSlotUsed
	#else
		
		native BAD_IsPlayerAttachedObjSlotUsed(playerid, index) = IsPlayerAttachedObjectSlotUsed;
		
		#define _ALS_IsPAttachedObjSlotUsed
	#endif
	#define IsPlayerAttachedObjectSlotUsed FIXES_IsPAttachedObjectSlotUsed
#endif

/*
 * FIXES_SetPlayerAttachedObject(playerid, index, modelid, bone, Float:fOffsetX = 0.0, Float:fOffsetY = 0.0, Float:fOffsetZ = 0.0, Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fScaleX = 1.0, Float:fScaleY = 1.0, Float:fScaleZ = 1.0)
 *
 * FIXES:
 *     IsPlayerAttachedObjectSlotUsed
 *     SetPlayerAttachedObject
 */
#if FIX_IsPlayerAttachedObjSlotUsed || FIX_SetPlayerAttachedObject
	stock FIXES_SetPlayerAttachedObject(playerid, index, modelid, bone, Float:fOffsetX = 0.0, Float:fOffsetY = 0.0, Float:fOffsetZ = 0.0, Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fScaleX = 1.0, Float:fScaleY = 1.0, Float:fScaleZ = 1.0)
	{
		if (SetPlayerAttachedObject(playerid, index, modelid, bone, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ))
		{
			FIXES_gsObjectSlots[playerid / _FIXES_ATTACHMENTS] |= 1 << playerid % _FIXES_ATTACHMENTS * MAX_PLAYER_ATTACHED_OBJECTS + index;
			return 1;
		}
		return 0;
	}
	
	#if defined _ALS_SetPlayerAttachedObject
		#undef SetPlayerAttachedObject
	#else
		
		native BAD_SetPlayerAttachedObject(playerid, index, modelid, bone, Float:fOffsetX = 0.0, Float:fOffsetY = 0.0, Float:fOffsetZ = 0.0, Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fScaleX = 1.0, Float:fScaleY = 1.0, Float:fScaleZ = 1.0) = SetPlayerAttachedObject;
		
		#define _ALS_SetPlayerAttachedObject
	#endif
	#define SetPlayerAttachedObject FIXES_SetPlayerAttachedObject
#endif

/*
 * FIXES_RemovePlayerAttachedObj(playerid, index)
 *
 * FIXES:
 *     IsPlayerAttachedObjectSlotUsed
 */
#if FIX_IsPlayerAttachedObjSlotUsed || FIX_SetPlayerAttachedObject
	stock FIXES_RemovePlayerAttachedObj(playerid, index)
	{
		if (RemovePlayerAttachedObject(playerid, index))
		{
			FIXES_gsObjectSlots[playerid / _FIXES_ATTACHMENTS] &= ~(1 << playerid % _FIXES_ATTACHMENTS * MAX_PLAYER_ATTACHED_OBJECTS + index);
			return 1;
		}
		return 0;
	}
	
	#if defined _ALS_RemovePlayerAttachedObject
		#undef RemovePlayerAttachedObject
	#else
		
		native BAD_RemovePlayerAttachedObject(playerid, index) = RemovePlayerAttachedObject;
		
		#define _ALS_RemovePlayerAttachedObject
	#endif
	#define RemovePlayerAttachedObject FIXES_RemovePlayerAttachedObj
#endif

/*
 * FIXES_%%%!!!
 *
 * FIXES:
 *     %%%
 */
/*#if FIX_%%%
	stock FIXES_%%%!!!
	{
		return 0;
	}
	
	#if defined _ALS_%%%
		#undef %%%
	#else
		
		native BAD_%%%!!! = %%%;
		
		#define _ALS_%%%
	#endif
	#define %%% FIXES_%%%
#endif
*/

#undef _FIXES_CEILDIV
#undef _FIXES_ATTACHMENTS
#undef FIXES_DETECT_CALLBACK_1
#undef FIXES_DETECT_CALLBACK_2
#undef FIXES_CALL_CALLBACK_1
#undef FIXES_CALL_CALLBACK_2
