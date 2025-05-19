PetalburgCity_Gym_EventScript_NormanGivePokemon::
# 2 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_NormanGivePokemon_Text_0
# 3 "data/maps/PetalburgCity_Gym/scripts.pory"
	special ChooseAce
# 4 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 6 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_NormanGivePokemon_Text_1
	end


PetalburgCity_Gym_EventScript_InitGameState::
# 12 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 13 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 14 "data/maps/PetalburgCity_Gym/scripts.pory"
	special SetUnlockedPokedexFlags
# 15 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 16 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 17 "data/maps/PetalburgCity_Gym/scripts.pory"
	special EnableNationalPokedex
# 18 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 19 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 20 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_BIKE
# 21 "data/maps/PetalburgCity_Gym/scripts.pory"
	additem ITEM_ACRO_BIKE
	return


# 24 "data/maps/PetalburgCity_Gym/scripts.pory"

# 25 "data/maps/PetalburgCity_Gym/scripts.pory"
.set LOCALID_NORMAN, 1
# 26 "data/maps/PetalburgCity_Gym/scripts.pory"
.set LOCALID_WALLY, 10
# 27 "data/maps/PetalburgCity_Gym/scripts.pory"
.set LOCALID_WALLYS_DAD, 11
# 28 "data/maps/PetalburgCity_Gym/scripts.pory"

# 29 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_MapScripts::
# 30 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
# 31 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
# 32 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
# 33 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
# 34 "data/maps/PetalburgCity_Gym/scripts.pory"
	.byte 0
# 35 "data/maps/PetalburgCity_Gym/scripts.pory"

# 36 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnLoad:
# 37 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_InitGameState
# 38 "data/maps/PetalburgCity_Gym/scripts.pory"
    setvar VAR_PETALBURG_GYM_STATE, 9
# 39 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_OpenUnlockedDoors
# 40 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_ge VAR_PETALBURG_GYM_STATE, 7, PetalburgCity_Gym_EventScript_UnlockAllDoors
# 41 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 42 "data/maps/PetalburgCity_Gym/scripts.pory"

# 43 "data/maps/PetalburgCity_Gym/scripts.pory"
@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
# 44 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenUnlockedDoors::
# 45 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 46 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 47 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 48 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 49 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 50 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 51 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 52 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 53 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 54 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 55 "data/maps/PetalburgCity_Gym/scripts.pory"

# 56 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockAllDoors::
# 57 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 58 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 59 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 60 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 61 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 62 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 63 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 64 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 65 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 66 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 67 "data/maps/PetalburgCity_Gym/scripts.pory"

# 68 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnTransition:
# 69 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_MoveWallyToEntrance
# 70 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_MoveNormanToEntrance
# 71 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
# 72 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 73 "data/maps/PetalburgCity_Gym/scripts.pory"

# 74 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveWallyToEntrance::
# 75 "data/maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_WALLY, 5, 108
# 76 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 77 "data/maps/PetalburgCity_Gym/scripts.pory"

# 78 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveNormanToEntrance::
# 79 "data/maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_NORMAN, 4, 107
# 80 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 81 "data/maps/PetalburgCity_Gym/scripts.pory"

# 82 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_CheckNormanForRematch::
# 83 "data/maps/PetalburgCity_Gym/scripts.pory"
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
# 84 "data/maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsTrainerReadyForRematch
# 85 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
# 86 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
# 87 "data/maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_NORMAN, 4, 107
# 88 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 89 "data/maps/PetalburgCity_Gym/scripts.pory"

# 90 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontMoveNormanToFront::
# 91 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 8
# 92 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 93 "data/maps/PetalburgCity_Gym/scripts.pory"

# 94 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnWarp:
# 95 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
# 96 "data/maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 97 "data/maps/PetalburgCity_Gym/scripts.pory"

# 98 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_TurnPlayerNorth::
# 99 "data/maps/PetalburgCity_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 100 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 101 "data/maps/PetalburgCity_Gym/scripts.pory"

# 102 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnFrame:
# 103 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
# 104 "data/maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 105 "data/maps/PetalburgCity_Gym/scripts.pory"

# 106 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial::
# 107 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 108 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
# 109 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
# 110 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 111 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 112 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
# 113 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 114 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_EXIT
# 115 "data/maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_WALLY
# 116 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 117 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 118 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 119 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 120 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
# 121 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 2
# 122 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 123 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 124 "data/maps/PetalburgCity_Gym/scripts.pory"

# 125 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitGym:
# 126 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 127 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 128 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 129 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 130 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 131 "data/maps/PetalburgCity_Gym/scripts.pory"

# 132 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Norman::
# 133 "data/maps/PetalburgCity_Gym/scripts.pory"
	lock
# 134 "data/maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 135 "data/maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_PETALBURG_GYM_STATE
# 136 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
# 137 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
# 138 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
# 139 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
# 140 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
# 141 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
# 142 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
# 143 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 9, PetalburgCity_Gym_EventScript_NormanGivePokemon
# 144 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
# 145 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 146 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 147 "data/maps/PetalburgCity_Gym/scripts.pory"

# 148 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth::
# 149 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 0
# 150 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 151 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 152 "data/maps/PetalburgCity_Gym/scripts.pory"

# 153 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth::
# 154 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 155 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 156 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 157 "data/maps/PetalburgCity_Gym/scripts.pory"

# 158 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialWest::
# 159 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 160 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 161 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 162 "data/maps/PetalburgCity_Gym/scripts.pory"

# 163 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialEast::
# 164 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 165 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 166 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 167 "data/maps/PetalburgCity_Gym/scripts.pory"

# 168 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorial::
# 169 "data/maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_WALLY
# 170 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 171 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
# 172 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
# 173 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 174 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 175 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
# 176 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
# 177 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
# 178 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
# 179 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
# 180 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
# 181 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
# 182 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
# 183 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
# 184 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressWallySouth
# 185 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
# 186 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressWallyWest
# 187 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressWallyEast
# 188 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
# 189 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
# 190 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
# 191 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
# 192 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
# 193 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanFaceDoorWest
# 194 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanFaceDoorEast
# 195 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 196 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
# 197 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 198 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
# 199 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
# 200 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 201 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 202 "data/maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 203 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
# 204 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
# 205 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
# 206 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
# 207 "data/maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_WALLY
# 208 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
# 209 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 210 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 2
# 211 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 212 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
# 213 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 214 "data/maps/PetalburgCity_Gym/scripts.pory"
	special InitBirchState
# 215 "data/maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 216 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 217 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 218 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 219 "data/maps/PetalburgCity_Gym/scripts.pory"

# 220 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveSouth::
# 221 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 222 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 223 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 224 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 225 "data/maps/PetalburgCity_Gym/scripts.pory"

# 226 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveNorth::
# 227 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
# 228 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 229 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 230 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 231 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 232 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 233 "data/maps/PetalburgCity_Gym/scripts.pory"

# 234 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveWestEast::
# 235 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 236 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 237 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 238 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 239 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 240 "data/maps/PetalburgCity_Gym/scripts.pory"

# 241 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallySouth::
# 242 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 243 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 244 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
# 245 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 246 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 247 "data/maps/PetalburgCity_Gym/scripts.pory"

# 248 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth::
# 249 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
# 250 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
# 251 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 252 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 253 "data/maps/PetalburgCity_Gym/scripts.pory"

# 254 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyWest::
# 255 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 256 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
# 257 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 258 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 259 "data/maps/PetalburgCity_Gym/scripts.pory"

# 260 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyEast::
# 261 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
# 262 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
# 263 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 264 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 265 "data/maps/PetalburgCity_Gym/scripts.pory"

# 266 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth::
# 267 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterUp
# 268 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 269 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 270 "data/maps/PetalburgCity_Gym/scripts.pory"

# 271 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth::
# 272 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 273 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 274 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 275 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 276 "data/maps/PetalburgCity_Gym/scripts.pory"

# 277 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerWest::
# 278 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 279 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 280 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 281 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 282 "data/maps/PetalburgCity_Gym/scripts.pory"

# 283 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerEast::
# 284 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 285 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 286 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 287 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 288 "data/maps/PetalburgCity_Gym/scripts.pory"

# 289 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallySouth::
# 290 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 291 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 292 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 293 "data/maps/PetalburgCity_Gym/scripts.pory"

# 294 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyNorth::
# 295 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterRight
# 296 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 297 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 298 "data/maps/PetalburgCity_Gym/scripts.pory"

# 299 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyWest::
# 300 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 301 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 302 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 303 "data/maps/PetalburgCity_Gym/scripts.pory"

# 304 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyEast::
# 305 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 306 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 307 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 308 "data/maps/PetalburgCity_Gym/scripts.pory"

# 309 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFacePlayer::
# 310 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
# 311 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 312 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 313 "data/maps/PetalburgCity_Gym/scripts.pory"

# 314 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFaceDown::
# 315 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterDown
# 316 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 317 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 318 "data/maps/PetalburgCity_Gym/scripts.pory"

# 319 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanNoBadges::
# 320 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
# 321 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 322 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 323 "data/maps/PetalburgCity_Gym/scripts.pory"

# 324 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanOneBadge::
# 325 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
# 326 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 327 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 328 "data/maps/PetalburgCity_Gym/scripts.pory"

# 329 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanTwoBadges::
# 330 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 331 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 332 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 333 "data/maps/PetalburgCity_Gym/scripts.pory"

# 334 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanThreeBadges::
# 335 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 336 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 337 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 338 "data/maps/PetalburgCity_Gym/scripts.pory"

# 339 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorSouth::
# 340 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 341 "data/maps/PetalburgCity_Gym/scripts.pory"

# 342 "data/maps/PetalburgCity_Gym/scripts.pory"
@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
# 343 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth::
# 344 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 345 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 346 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 347 "data/maps/PetalburgCity_Gym/scripts.pory"

# 348 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorWest::
# 349 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 350 "data/maps/PetalburgCity_Gym/scripts.pory"

# 351 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorEast::
# 352 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 353 "data/maps/PetalburgCity_Gym/scripts.pory"

# 354 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanPostBattle::
# 355 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
# 356 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GiveEnigmaBerry
# 357 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_FACADE, PetalburgCity_Gym_EventScript_GiveFacade2
# 358 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
# 359 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
# 360 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 361 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 362 "data/maps/PetalburgCity_Gym/scripts.pory"

# 363 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade2::
# 364 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 365 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 366 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 367 "data/maps/PetalburgCity_Gym/scripts.pory"

# 368 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanRematch::
# 369 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
# 370 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
# 371 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 372 "data/maps/PetalburgCity_Gym/scripts.pory"

# 373 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry::
# 374 "data/maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsEnigmaBerryValid
# 375 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 376 "data/maps/PetalburgCity_Gym/scripts.pory"
	checkitem ITEM_ENIGMA_BERRY_E_READER
# 377 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 378 "data/maps/PetalburgCity_Gym/scripts.pory"
	checkpcitem ITEM_ENIGMA_BERRY_E_READER
# 379 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 380 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_ENIGMA_BERRY_AVAILABLE, 0, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 381 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
# 382 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, TRUE
# 383 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 384 "data/maps/PetalburgCity_Gym/scripts.pory"

# 385 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry::
# 386 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, FALSE
# 387 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 388 "data/maps/PetalburgCity_Gym/scripts.pory"

# 389 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveEnigmaBerry::
# 390 "data/maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_ENIGMA_BERRY_E_READER
# 391 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 392 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
# 393 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 394 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 395 "data/maps/PetalburgCity_Gym/scripts.pory"

# 396 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanBattle::
# 397 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
# 398 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
# 399 "data/maps/PetalburgCity_Gym/scripts.pory"
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
# 400 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmessage
# 401 "data/maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 402 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
# 403 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 404 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 7
# 405 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_BADGE05_GET
# 406 "data/maps/PetalburgCity_Gym/scripts.pory"
	special ResetHealLocationFromDewford
# 407 "data/maps/PetalburgCity_Gym/scripts.pory"
	call EventScript_HideMrBriney
# 408 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
# 409 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
# 410 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 5
# 411 "data/maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 412 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
# 413 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
# 414 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 415 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_GiveFacade
# 416 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 417 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
# 418 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 419 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 40
# 420 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 421 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 422 "data/maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_WALLYS_DAD
# 423 "data/maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 424 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
# 425 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
# 426 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
# 427 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 428 "data/maps/PetalburgCity_Gym/scripts.pory"

# 429 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade::
# 430 "data/maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_TM_FACADE
# 431 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
# 432 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_FACADE
# 433 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
# 434 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 435 "data/maps/PetalburgCity_Gym/scripts.pory"

# 436 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesNorth::
# 437 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 438 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 439 "data/maps/PetalburgCity_Gym/scripts.pory"

# 440 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesEast::
# 441 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 442 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 443 "data/maps/PetalburgCity_Gym/scripts.pory"

# 444 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesWest::
# 445 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 446 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 447 "data/maps/PetalburgCity_Gym/scripts.pory"

# 448 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrives::
# 449 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
# 450 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 451 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_PIN
# 452 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_ExclamationMark
# 453 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 454 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_Delay48
# 455 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 456 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 457 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
# 458 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
# 459 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
# 460 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 461 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 462 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 20
# 463 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
# 464 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
# 465 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
# 466 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
# 467 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 468 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 469 "data/maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 470 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
# 471 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
# 472 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
# 473 "data/maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_WALLYS_DAD
# 474 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 4
# 475 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
# 476 "data/maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 15, 8
# 477 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 478 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 479 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 480 "data/maps/PetalburgCity_Gym/scripts.pory"

# 481 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth::
# 482 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFasterUp
# 483 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 484 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 485 "data/maps/PetalburgCity_Gym/scripts.pory"

# 486 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast::
# 487 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFasterRight
# 488 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 489 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 490 "data/maps/PetalburgCity_Gym/scripts.pory"

# 491 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest::
# 492 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFasterLeft
# 493 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 494 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 495 "data/maps/PetalburgCity_Gym/scripts.pory"

# 496 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth::
# 497 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
# 498 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 499 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 500 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterLeft
# 501 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 502 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 503 "data/maps/PetalburgCity_Gym/scripts.pory"

# 504 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast::
# 505 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
# 506 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 507 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 508 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 509 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 510 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 511 "data/maps/PetalburgCity_Gym/scripts.pory"

# 512 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest::
# 513 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
# 514 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 515 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 516 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 517 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 518 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 519 "data/maps/PetalburgCity_Gym/scripts.pory"

# 520 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth::
# 521 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
# 522 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFasterDown
# 523 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
# 524 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 525 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 526 "data/maps/PetalburgCity_Gym/scripts.pory"

# 527 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast::
# 528 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
# 529 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
# 530 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 531 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 532 "data/maps/PetalburgCity_Gym/scripts.pory"

# 533 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest::
# 534 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
# 535 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
# 536 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 537 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 538 "data/maps/PetalburgCity_Gym/scripts.pory"

# 539 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitNorth:
# 540 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 541 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 542 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 543 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 544 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 545 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 546 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 547 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 548 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 549 "data/maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 550 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 551 "data/maps/PetalburgCity_Gym/scripts.pory"

# 552 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitEast:
# 553 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 554 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 555 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 556 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 557 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 558 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 559 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 560 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 561 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 562 "data/maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 563 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 564 "data/maps/PetalburgCity_Gym/scripts.pory"

# 565 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitWest:
# 566 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 567 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 568 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 569 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 570 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 571 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 572 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 573 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 574 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 575 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 576 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 577 "data/maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 578 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 579 "data/maps/PetalburgCity_Gym/scripts.pory"

# 580 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
# 581 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 582 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 583 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 584 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 585 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 586 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 587 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 588 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 589 "data/maps/PetalburgCity_Gym/scripts.pory"

# 590 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
# 591 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 592 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 593 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 594 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 595 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 596 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 597 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 598 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 599 "data/maps/PetalburgCity_Gym/scripts.pory"

# 600 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
# 601 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 602 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 603 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 604 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 605 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 606 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 607 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 608 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 609 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 610 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 611 "data/maps/PetalburgCity_Gym/scripts.pory"

# 612 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadEnterGym:
# 613 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 614 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 615 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 616 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 617 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 618 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 619 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 620 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 621 "data/maps/PetalburgCity_Gym/scripts.pory"

# 622 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
# 623 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 624 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 625 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 626 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 627 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 628 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_right
# 629 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 630 "data/maps/PetalburgCity_Gym/scripts.pory"

# 631 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
# 632 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 633 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 634 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 635 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 636 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 637 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 638 "data/maps/PetalburgCity_Gym/scripts.pory"

# 639 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
# 640 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 641 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 642 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 643 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 644 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 645 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 646 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 647 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 648 "data/maps/PetalburgCity_Gym/scripts.pory"

# 649 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_Unused:
# 650 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 651 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 652 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 653 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 654 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 655 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 656 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 657 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 658 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 659 "data/maps/PetalburgCity_Gym/scripts.pory"

# 660 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArriveNorth:
# 661 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 662 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 663 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 664 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 665 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 666 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 667 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 668 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 669 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_left
# 670 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 671 "data/maps/PetalburgCity_Gym/scripts.pory"

# 672 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArrive:
# 673 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 674 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 675 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 676 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 677 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 678 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 679 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 680 "data/maps/PetalburgCity_Gym/scripts.pory"

# 681 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitNorth:
# 682 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 683 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 684 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 685 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 686 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 687 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 688 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 689 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 690 "data/maps/PetalburgCity_Gym/scripts.pory"

# 691 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitEast:
# 692 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 693 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 694 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 695 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 696 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 697 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 698 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 699 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 700 "data/maps/PetalburgCity_Gym/scripts.pory"

# 701 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitSouthWest:
# 702 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 703 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 704 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 705 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_up
# 706 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 707 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 708 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 709 "data/maps/PetalburgCity_Gym/scripts.pory"

# 710 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
# 711 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 712 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 713 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 714 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 715 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 716 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 717 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 718 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 719 "data/maps/PetalburgCity_Gym/scripts.pory"

# 720 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
# 721 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 722 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 723 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 724 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 725 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 726 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 727 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 728 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 729 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 730 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 731 "data/maps/PetalburgCity_Gym/scripts.pory"

# 732 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
# 733 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 734 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 735 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 736 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 737 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 738 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 739 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 740 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 741 "data/maps/PetalburgCity_Gym/scripts.pory"

# 742 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
# 743 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_faster_down
# 744 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 745 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 746 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 747 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 748 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 749 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 750 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 751 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 752 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 753 "data/maps/PetalburgCity_Gym/scripts.pory"

# 754 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough::
# 755 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
# 756 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 757 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 758 "data/maps/PetalburgCity_Gym/scripts.pory"

# 759 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SpeedRoomDoor::
# 760 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 761 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 762 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 763 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 85
# 764 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
# 765 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 766 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 767 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 768 "data/maps/PetalburgCity_Gym/scripts.pory"

# 769 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_EnterRoom::
# 770 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 771 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 772 "data/maps/PetalburgCity_Gym/scripts.pory"
	warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009
# 773 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 774 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 775 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 776 "data/maps/PetalburgCity_Gym/scripts.pory"

# 777 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontEnterRoom::
# 778 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 779 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 780 "data/maps/PetalburgCity_Gym/scripts.pory"

# 781 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DoorLocked::
# 782 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
# 783 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 784 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 785 "data/maps/PetalburgCity_Gym/scripts.pory"

# 786 "data/maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
# 787 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AccuracyRoomDoor::
# 788 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 789 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
# 790 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 791 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 98
# 792 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
# 793 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 794 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 795 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 796 "data/maps/PetalburgCity_Gym/scripts.pory"

# 797 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ConfusionRoomDoor::
# 798 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 799 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 800 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 801 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 46
# 802 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
# 803 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 804 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 805 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 806 "data/maps/PetalburgCity_Gym/scripts.pory"

# 807 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor::
# 808 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 809 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 810 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 811 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 812 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 813 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 814 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 815 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 816 "data/maps/PetalburgCity_Gym/scripts.pory"

# 817 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightDefenseRoomDoor::
# 818 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 819 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 820 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 821 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 822 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 823 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 824 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 825 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 826 "data/maps/PetalburgCity_Gym/scripts.pory"

# 827 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RecoveryRoomDoor::
# 828 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 829 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 830 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 831 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 72
# 832 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
# 833 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 834 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 835 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 836 "data/maps/PetalburgCity_Gym/scripts.pory"

# 837 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor::
# 838 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 839 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
# 840 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 841 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 842 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 843 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 844 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 845 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 846 "data/maps/PetalburgCity_Gym/scripts.pory"

# 847 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightStrengthRoomDoor::
# 848 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 849 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 850 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 851 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 852 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 853 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 854 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 855 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 856 "data/maps/PetalburgCity_Gym/scripts.pory"

# 857 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftOHKORoomDoor::
# 858 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 859 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 860 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 861 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 862 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 863 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 864 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 865 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 866 "data/maps/PetalburgCity_Gym/scripts.pory"

# 867 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightOHKORoomDoor::
# 868 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 869 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
# 870 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 871 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 872 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 873 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 874 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 875 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 876 "data/maps/PetalburgCity_Gym/scripts.pory"

# 877 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor::
# 878 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 879 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
# 880 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 881 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 882 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 883 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 884 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 885 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 886 "data/maps/PetalburgCity_Gym/scripts.pory"

# 887 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor::
# 888 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 889 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
# 890 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 891 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 892 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 893 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
# 894 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
# 895 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 896 "data/maps/PetalburgCity_Gym/scripts.pory"

# 897 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Randall::
# 898 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
# 899 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
# 900 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
# 901 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 902 "data/maps/PetalburgCity_Gym/scripts.pory"

# 903 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors::
# 904 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 905 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 906 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 907 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 908 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 909 "data/maps/PetalburgCity_Gym/scripts.pory"

# 910 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RandallPostBadge::
# 911 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
# 912 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 913 "data/maps/PetalburgCity_Gym/scripts.pory"

# 914 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Parker::
# 915 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
# 916 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
# 917 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
# 918 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 919 "data/maps/PetalburgCity_Gym/scripts.pory"

# 920 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors::
# 921 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 922 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 923 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 924 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 925 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 926 "data/maps/PetalburgCity_Gym/scripts.pory"

# 927 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ParkerPostBadge::
# 928 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
# 929 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 930 "data/maps/PetalburgCity_Gym/scripts.pory"

# 931 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_George::
# 932 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
# 933 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
# 934 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
# 935 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 936 "data/maps/PetalburgCity_Gym/scripts.pory"

# 937 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors::
# 938 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 939 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 940 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 941 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 942 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 943 "data/maps/PetalburgCity_Gym/scripts.pory"

# 944 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GeorgePostBadge::
# 945 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
# 946 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 947 "data/maps/PetalburgCity_Gym/scripts.pory"

# 948 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Berke::
# 949 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
# 950 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
# 951 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
# 952 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 953 "data/maps/PetalburgCity_Gym/scripts.pory"

# 954 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors::
# 955 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 956 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 957 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 958 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 959 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 960 "data/maps/PetalburgCity_Gym/scripts.pory"

# 961 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BerkePostBadge::
# 962 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
# 963 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 964 "data/maps/PetalburgCity_Gym/scripts.pory"

# 965 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Mary::
# 966 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
# 967 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
# 968 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
# 969 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 970 "data/maps/PetalburgCity_Gym/scripts.pory"

# 971 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors::
# 972 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 973 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 974 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 975 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 976 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 977 "data/maps/PetalburgCity_Gym/scripts.pory"

# 978 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MaryPostBadge::
# 979 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
# 980 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 981 "data/maps/PetalburgCity_Gym/scripts.pory"

# 982 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Alexia::
# 983 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
# 984 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
# 985 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
# 986 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 987 "data/maps/PetalburgCity_Gym/scripts.pory"

# 988 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors::
# 989 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 990 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 991 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 992 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 993 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 994 "data/maps/PetalburgCity_Gym/scripts.pory"

# 995 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AlexiaPostBadge::
# 996 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
# 997 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 998 "data/maps/PetalburgCity_Gym/scripts.pory"

# 999 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Jody::
# 1000 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
# 1001 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
# 1002 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
# 1003 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1004 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1005 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors::
# 1006 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 1007 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 1008 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 1009 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1010 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1011 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1012 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_JodyPostBadge::
# 1013 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
# 1014 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1015 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1016 "data/maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8004 below is the room number
# 1017 "data/maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
# 1018 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors::
# 1019 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 1020 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1021 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1022 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
# 1023 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1024 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1025 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors::
# 1026 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 1027 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1028 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1029 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
# 1030 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1031 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1032 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors::
# 1033 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 1034 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1035 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1036 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
# 1037 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1038 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1039 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors::
# 1040 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 4
# 1041 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1042 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1043 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
# 1044 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1045 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1046 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors::
# 1047 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 5
# 1048 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1049 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1050 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
# 1051 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1052 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1053 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors::
# 1054 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 6
# 1055 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1056 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1057 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
# 1058 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1059 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1060 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors::
# 1061 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 7
# 1062 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1063 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1064 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
# 1065 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1066 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1067 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenOHKORoomDoors::
# 1068 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 8
# 1069 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1070 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1071 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
# 1072 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1073 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1074 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles::
# 1075 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1076 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1077 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1078 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1079 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1080 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1081 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles::
# 1082 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1083 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1084 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1085 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1086 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1087 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1088 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles::
# 1089 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1090 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1091 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1092 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1093 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1094 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1095 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles::
# 1096 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1097 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1098 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1099 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1100 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles::
# 1101 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1102 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1103 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1104 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1105 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1106 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1107 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles::
# 1108 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1109 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1110 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1111 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1112 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles::
# 1113 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1114 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1115 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1116 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1117 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles::
# 1118 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
# 1119 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
# 1120 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1121 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1122 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRoomDoors::
# 1123 "data/maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymSlideOpenRoomDoors
# 1124 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 1125 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1126 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1127 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockRoomDoors::
# 1128 "data/maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymUnlockRoomDoors
# 1129 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1130 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1131 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuide::
# 1132 "data/maps/PetalburgCity_Gym/scripts.pory"
	lock
# 1133 "data/maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 1134 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
# 1135 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 1136 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1137 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1138 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1139 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuidePostVictory::
# 1140 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 1141 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1142 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1143 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1144 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymStatue::
# 1145 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1146 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1147 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1148 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1149 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1150 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymStatue::
# 1151 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1152 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1153 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1154 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1155 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1156 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatueCertified::
# 1157 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 1158 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1159 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1160 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1161 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatue::
# 1162 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 1163 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1164 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1165 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1166 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon:
# 1167 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm?\p"
# 1168 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, if it isn't {PLAYER}!\n"
# 1169 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "So you're all finished moving in?\p"
# 1170 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm surprised that you managed to\n"
# 1171 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "get here by yourself.\p"
# 1172 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Oh, I see.\n"
# 1173 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You're with your POKéMON.\p"
# 1174 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hm… Then I guess you're going to\n"
# 1175 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "become a TRAINER like me, {PLAYER}.\p"
# 1176 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That's great news!\n"
# 1177 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll be looking forward to it!$"
# 1178 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1179 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
# 1180 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Um… I…\n"
# 1181 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'd like to get a POKéMON, please…$"
# 1182 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1183 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadOhYoureWallyRight:
# 1184 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? You're… Uh… Oh, right.\n"
# 1185 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You're WALLY, right?$"
# 1186 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1187 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
# 1188 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: I'm going to go stay with my\n"
# 1189 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "relatives in VERDANTURF TOWN.\p"
# 1190 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I thought I would be lonely by myself,\n"
# 1191 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "so I wanted to take a POKéMON along.\p"
# 1192 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But I've never caught a POKéMON before.\n"
# 1193 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I don't know how…$"
# 1194 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1195 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHmISee:
# 1196 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm. I see.$"
# 1197 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1198 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadPlayerGoWithWally:
# 1199 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you heard that,\n"
# 1200 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "right?\p"
# 1201 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go with WALLY and make sure that he\n"
# 1202 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "safely catches a POKéMON.$"
# 1203 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1204 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
# 1205 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY, here, I'll loan you my POKéMON.\p"
# 1206 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a ZIGZAGOON!$"
# 1207 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1208 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall:
# 1209 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1210 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "A POKéMON!\p"
# 1211 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm. I'll give you a POKé BALL, too.\n"
# 1212 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go for it!\p"
# 1213 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY received a POKé BALL!$"
# 1214 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1215 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyOhWowThankYou:
# 1216 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Oh, wow!\n"
# 1217 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Thank you!$"
# 1218 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1219 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
# 1220 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}… Would you really come\n"
# 1221 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with me?$"
# 1222 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1223 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadSoDidItWorkOut:
# 1224 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: So, did it work out?$"
# 1225 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1226 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouBye:
# 1227 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "WALLY: Thank you, yes, it did.\n"
# 1228 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Here's your POKéMON back.\p"
# 1229 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, thank you for coming along\n"
# 1230 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with me.\p"
# 1231 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You two are why I was able to catch\n"
# 1232 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "my POKéMON.\p"
# 1233 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I promise I'll take really good\n"
# 1234 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "care of it.\p"
# 1235 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Oh! My mom's waiting for me,\n"
# 1236 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "so I have to go!\p"
# 1237 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Bye, {PLAYER}!$"
# 1238 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1239 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoCollectBadges:
# 1240 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Now…\p"
# 1241 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, if you want to become a\n"
# 1242 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "strong TRAINER, here's my advice.\p"
# 1243 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Head for RUSTBORO CITY beyond this\n"
# 1244 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "town.\p"
# 1245 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "There, you should challenge\n"
# 1246 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER, ROXANNE.\p"
# 1247 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "After her, go on to other POKéMON\n"
# 1248 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "GYMS and defeat their LEADERS.\p"
# 1249 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Collect BADGES from them,\n"
# 1250 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "understood?\p"
# 1251 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Of course, I'm a GYM LEADER, too.\n"
# 1252 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "We'll battle one day, {PLAYER}.\p"
# 1253 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But that's only after you become\n"
# 1254 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.$"
# 1255 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1256 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToRustboro:
# 1257 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm? Aren't you going to the\n"
# 1258 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON GYM in RUSTBORO CITY?\p"
# 1259 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "There's no challenge for me to\n"
# 1260 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "battle a greenhorn TRAINER.\p"
# 1261 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, I want you to challenge me\n"
# 1262 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "when you become a lot stronger.\p"
# 1263 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll battle you, {PLAYER}, when you\n"
# 1264 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "can show me four GYM BADGES, okay?$"
# 1265 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1266 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToDewford:
# 1267 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: I see… So, you've beaten\n"
# 1268 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the GYM LEADER in RUSTBORO CITY.\p"
# 1269 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But there are many more TRAINERS\n"
# 1270 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "who are stronger than you, {PLAYER}.\p"
# 1271 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Across the sea in DEWFORD TOWN is a\n"
# 1272 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER named BRAWLY.\p"
# 1273 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You should go challenge him.$"
# 1274 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1275 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_YouHaveGottenStronger:
# 1276 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm… {PLAYER}, you have gotten\n"
# 1277 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1278 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I can tell by the number of BADGES\n"
# 1279 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "that you've earned.$"
# 1280 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1281 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanIntro:
# 1282 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: Hm…\n"
# 1283 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "So, you did get four GYM BADGES.\p"
# 1284 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Fine, as I promised, we will have\n"
# 1285 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON battle.\p"
# 1286 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}…\p"
# 1287 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm so happy that I can have\n"
# 1288 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a real battle with my own child.\p"
# 1289 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But, a battle is a battle!\p"
# 1290 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I will do everything in my power as\n"
# 1291 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a GYM LEADER to win.\p"
# 1292 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, you'd better give it your\n"
# 1293 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "best shot, too!$"
# 1294 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1295 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanDefeat:
# 1296 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "…\p"
# 1297 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I… I can't…\p"
# 1298 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I can't believe it. {PLAYER}…\p"
# 1299 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost to {PLAYER}?\p"
# 1300 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But, rules are rules!\n"
# 1301 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Here, take this.$"
# 1302 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1303 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ReceivedBalanceBadge:
# 1304 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER} received the BALANCE BADGE\n"
# 1305 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "from DAD!$"
# 1306 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1307 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis:
# 1308 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: With that BADGE, the DEFENSE\n"
# 1309 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "of all your POKéMON will increase.\p"
# 1310 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "POKéMON that know the HM move SURF\n"
# 1311 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "will be able to travel over water.\p"
# 1312 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is my gift to you. {PLAYER}, I'm\n"
# 1313 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "sure you can use it correctly.$"
# 1314 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1315 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainFacade:
# 1316 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: TM42 contains FACADE.\p"
# 1317 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It doubles the power of moves if\n"
# 1318 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the POKéMON is poisoned, paralyzed,\l"
# 1319 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "or burned.\p"
# 1320 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It might be able to turn a bad\n"
# 1321 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "situation into an advantage.$"
# 1322 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1323 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHappyAndSad:
# 1324 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: As the GYM LEADER, I can't\n"
# 1325 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "express how upset I am…\p"
# 1326 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But as a father, it makes me both\n"
# 1327 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "happy and a little sad. It's odd…$"
# 1328 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1329 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_PleaseComeWithMe:
# 1330 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
# 1331 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Please come with me.\n"
# 1332 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I have something I want you to have.$"
# 1333 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1334 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_LetMeBorrowPlayer:
# 1335 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN, you don't mind, do you?\p"
# 1336 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
# 1337 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a minute or two.$"
# 1338 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1339 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoingToKeepTraining:
# 1340 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, you should go visit\n"
# 1341 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "your mother every so often.\p"
# 1342 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to stay here and redouble\n"
# 1343 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "my training.\p"
# 1344 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It would bother me as a TRAINER to\n"
# 1345 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "not avenge my loss to you, {PLAYER}!$"
# 1346 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1347 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough:
# 1348 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}, how are things going?\p"
# 1349 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The world of POKéMON is deep.\p"
# 1350 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I honestly think that no amount of\n"
# 1351 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "training would ever be enough.$"
# 1352 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1353 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuideAdvice:
# 1354 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 1355 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 1356 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The doors in this GYM open when you\n"
# 1357 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "beat the awaiting TRAINERS.\p"
# 1358 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Whoops! The doors in this room are\n"
# 1359 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "already open, so don't attack me!\p"
# 1360 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The TRAINERS of PETALBURG GYM\n"
# 1361 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "use all kinds of items.\p"
# 1362 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the left leads to\n"
# 1363 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the SPEED ROOM.\p"
# 1364 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the right leads to\n"
# 1365 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the ACCURACY ROOM.\p"
# 1366 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The room's name will be on\n"
# 1367 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the door, so choose carefully.\p"
# 1368 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Once you've chosen the door…\n"
# 1369 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, hey, go for it!$"
# 1370 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1371 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuidePostVictory:
# 1372 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}! Whoa! You've overcome even\n"
# 1373 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "your own father!\p"
# 1374 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Like, whoa!\n"
# 1375 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "What a stunning turn of events!$"
# 1376 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1377 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallIntro:
# 1378 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The ability to attack before the\n"
# 1379 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "opponent…\p"
# 1380 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Just that alone puts me at a great\n"
# 1381 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "advantage, don't you agree?$"
# 1382 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1383 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallDefeat:
# 1384 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That was a magnificent battle!$"
# 1385 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1386 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBattle:
# 1387 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on to the next room where a new\n"
# 1388 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "challenge awaits you.\p"
# 1389 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "At the left is the CONFUSION ROOM.\p"
# 1390 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door leads to the DEFENSE\n"
# 1391 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "ROOM.$"
# 1392 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1393 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBadge:
# 1394 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Whomever you beat, and whomever you\n"
# 1395 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "may lose to, you never shirk from\l"
# 1396 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "training yourself and your POKéMON.\p"
# 1397 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That's what I think being a\n"
# 1398 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "GYM LEADER is all about.$"
# 1399 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1400 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerIntro:
# 1401 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the CONFUSION ROOM.\p"
# 1402 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me see how well bonded you are\n"
# 1403 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with your POKéMON!$"
# 1404 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1405 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerDefeat:
# 1406 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't confuse your team enough…\n"
# 1407 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You share a strong bond together.$"
# 1408 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1409 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBattle:
# 1410 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The next room is the STRENGTH ROOM.\n"
# 1411 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you withstand brute force?$"
# 1412 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1413 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBadge:
# 1414 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "After you beat our LEADER, the\n"
# 1415 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "training has become a lot tougher.$"
# 1416 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1417 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeIntro:
# 1418 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Just when you think you're going to\n"
# 1419 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "win, your opponent restores HP…\p"
# 1420 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you just imagine how awful that\n"
# 1421 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "must feel?\p"
# 1422 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you exactly how awful it\n"
# 1423 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "feels!$"
# 1424 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1425 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeDefeat:
# 1426 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't restore HP enough…\n"
# 1427 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "What ATTACK power…$"
# 1428 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1429 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBattle:
# 1430 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I should have expected no less from\n"
# 1431 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "our LEADER's kid.\p"
# 1432 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "No, wait! A TRAINER's abilities are\n"
# 1433 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "earned only through effort.\p"
# 1434 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost because my own efforts\n"
# 1435 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "weren't enough.\p"
# 1436 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on! The ONE-HIT KO ROOM is next.$"
# 1437 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1438 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBadge:
# 1439 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to keep training at GYMS.\n"
# 1440 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "One day, I'll become a LEADER.$"
# 1441 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1442 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeIntro:
# 1443 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm not going to take it easy just\n"
# 1444 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "because you're our LEADER's kid.\p"
# 1445 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you how horrid it is for\n"
# 1446 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a POKéMON to take a critical hit!$"
# 1447 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1448 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeDefeat:
# 1449 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Your power…\n"
# 1450 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You're the real deal.$"
# 1451 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1452 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBattle:
# 1453 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Your father really is strong.\n"
# 1454 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "He's a TRAINER worth my respect.\p"
# 1455 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "And, I sense the same glow coming\n"
# 1456 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "from you as your father.\p"
# 1457 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I hope that you'll stage a terrific\n"
# 1458 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "battle with your father!$"
# 1459 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1460 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBadge:
# 1461 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Since your dad became the LEADER,\n"
# 1462 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the TRAINERS of PETALBURG CITY have\l"
# 1463 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "become a lot tougher.$"
# 1464 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1465 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryIntro:
# 1466 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Giggle…\n"
# 1467 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the ACCURACY ROOM.\p"
# 1468 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It's pretty nasty when every attack\n"
# 1469 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "lands without fail.$"
# 1470 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1471 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryDefeat:
# 1472 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You were a cut above me…$"
# 1473 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1474 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBattle:
# 1475 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "There are some even stronger\n"
# 1476 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "TRAINERS waiting for you.\p"
# 1477 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The left is the DEFENSE ROOM, and\n"
# 1478 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the right is the RECOVERY ROOM.\p"
# 1479 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Your POKéMON's ATTACK power will be\n"
# 1480 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "on trial either way.$"
# 1481 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1482 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBadge:
# 1483 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you know what we're trying to\n"
# 1484 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "achieve as TRAINERS?\p"
# 1485 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "We're striving to become soul mates\n"
# 1486 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with our POKéMON.$"
# 1487 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1488 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaIntro:
# 1489 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The higher the DEFENSE, the more\n"
# 1490 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "reckless I can be in attack.$"
# 1491 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1492 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaDefeat:
# 1493 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Our defenses weren't enough…$"
# 1494 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1495 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBattle:
# 1496 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I think you've taught me a valuable\n"
# 1497 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "lesson here.\p"
# 1498 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Now, go on! The left door goes to\n"
# 1499 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the STRENGTH ROOM.\p"
# 1500 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door opens to\n"
# 1501 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the ONE-HIT KO ROOM.\p"
# 1502 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Both of them have TRAINERS who are\n"
# 1503 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "skilled at offense.$"
# 1504 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1505 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBadge:
# 1506 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hi! Have you tried using SURF?$"
# 1507 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1508 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyIntro:
# 1509 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Our GYM LEADER told us to go all out\n"
# 1510 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "and beat you.\p"
# 1511 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Even if you happen to be the\n"
# 1512 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "LEADER's kid!$"
# 1513 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1514 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyDefeat:
# 1515 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But… I went all out!$"
# 1516 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1517 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBattle:
# 1518 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The way you use your POKéMON…\n"
# 1519 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It's like your father's style.\p"
# 1520 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on through! The GYM LEADER, your\n"
# 1521 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "father, is waiting!$"
# 1522 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1523 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBadge:
# 1524 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Sure, it's fine to make your POKéMON\n"
# 1525 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1526 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But what decides the winner?\p"
# 1527 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Why, it's the feelings TRAINERS have\n"
# 1528 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "for their POKéMON.$"
# 1529 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1530 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked:
# 1531 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1532 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1533 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1534 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterSpeedRoom:
# 1535 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“SPEED ROOM,” the sign says.\p"
# 1536 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1537 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1538 "data/maps/PetalburgCity_Gym/scripts.pory"
@ Unused
# 1539 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked2:
# 1540 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1541 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1542 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1543 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterAccuracyRoom:
# 1544 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“ACCURACY ROOM,” the sign says.\p"
# 1545 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1546 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1547 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterConfusionRoom:
# 1548 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“CONFUSION ROOM,” the sign says.\p"
# 1549 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1550 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1551 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterDefenseRoom:
# 1552 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“DEFENSE ROOM,” the sign says.\p"
# 1553 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1554 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1555 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterRecoveryRoom:
# 1556 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“RECOVERY ROOM,” the sign says.\p"
# 1557 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1558 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1559 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterStrengthRoom:
# 1560 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“STRENGTH ROOM,” the sign says.\p"
# 1561 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1562 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1563 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterOHKORoom:
# 1564 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“ONE-HIT KO ROOM,” the sign says.\p"
# 1565 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1566 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1567 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterGymLeadersRoom:
# 1568 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“GYM LEADER'S ROOM\p"
# 1569 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“See for yourself what POKéMON await\n"
# 1570 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "you!” the sign says.\p"
# 1571 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1572 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1573 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatue:
# 1574 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM$"
# 1575 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1576 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatueCertified:
# 1577 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "PETALBURG CITY POKéMON GYM\p"
# 1578 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "NORMAN'S CERTIFIED TRAINERS:\n"
# 1579 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 1580 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1581 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPreRematch:
# 1582 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1583 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1584 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1585 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1586 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1587 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1588 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1589 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "…No, because we are parent and child,\n"
# 1590 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we owe it to each other to do the best\l"
# 1591 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we can. Isn't that right, {PLAYER}?$"
# 1592 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1593 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchDefeat:
# 1594 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Uh… Haha…\n"
# 1595 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Maybe that was going too hard…$"
# 1596 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1597 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPostRematch:
# 1598 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1599 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "What is your dream?\p"
# 1600 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "My dream…\n"
# 1601 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hahaha…\l"
# 1602 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It has already come true, actually.$"
# 1603 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1604 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchNeedTwoMons:
# 1605 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "DAD: {PLAYER}…\n"
# 1606 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1607 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1608 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1609 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1610 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a GYM, it doesn't matter that\n"
# 1611 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1612 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hm? Wait a second, {PLAYER}.\p"
# 1613 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you only have one POKéMON that is\n"
# 1614 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "capable of battle?\p"
# 1615 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Sorry, but you'll have to come back\n"
# 1616 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with at least two POKéMON.$"

PetalburgCity_Gym_EventScript_NormanGivePokemon_Text_0:
# 2 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hey kid! I got some POKéMON from the\n"
	.string "League to get you started. Have you\l"
	.string "picked what type your gym will use?$"

PetalburgCity_Gym_EventScript_NormanGivePokemon_Text_1:
# 6 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I think that's a great pick! You'll have\n"
	.string "a lot of fun with it. Make me proud!$"
