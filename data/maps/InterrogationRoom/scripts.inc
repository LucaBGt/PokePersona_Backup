InterrogationRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, InterrogationRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, InterrogationRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

InterrogationRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_GAMESTATE, 0, InterrogationRoom_FirstScene
	.2byte 0


InterrogationRoom_OnTransition::
	setflag FLAG_SYS_PREVENT_MAP_FADE
	return


InterrogationRoom_FirstScene::
	lockall
	setobjectxy 1, 5, 7
	applymovement 1, CommonMovement_FaceRight
	removeobject 1
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	msgbox InterrogationRoom_FirstScene_Text_0
	closemessage
	delay 30
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, InterogationRoom_CameraUp
	waitmovement 0
	playse SE_DOOR
	waitse
	addobject 1
	delay 30
	applymovement 1, InterogationRoom_AgentSit
	waitmovement 0
	delay 30
	msgbox InterrogationRoom_FirstScene_Text_1
	closemessage
	delay 30
	msgbox InterrogationRoom_FirstScene_Text_2
	closemessage
	setvar VAR_GAMESTATE, 1
	closemessage
	releaseall
	end


InterogationRoom_CameraUp:
	walk_slow_up
	step_end

CommonMovement_FaceLeft:
	face_left
	step_end

CommonMovement_FaceRight:
	face_right
	step_end

CommonMovement_FaceUp:
	face_up
	step_end

CommonMovement_FaceDown:
	face_down
	step_end

InterogationRoom_AgentSit:
	walk_slow_right
	walk_slow_down
	walk_slow_right
	face_down
	delay_16
	step_end

InterrogationRoom_FirstScene_Text_0:
	.string "???: Alright.$"

InterrogationRoom_FirstScene_Text_1:
	.string "???: I see you finally decided to talk.$"

InterrogationRoom_FirstScene_Text_2:
	.string "???: See? This isn't so bad.\pLet us begin.$"
