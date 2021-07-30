InterrogationRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, InterrogationRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, InterrogationRoom_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_FRAME_TABLE, InterrogationRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

InterrogationRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return

InterrogationRoom_MapScripts_MAP_SCRIPT_ON_RESUME:
	return

InterrogationRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_GAMESTATE, 1, InterrogationRoom_FirstScene
	.2byte 0


InterrogationRoom_FirstScene::
	lockall
	setobjectxy 1, 19, 19
	setobjectxy 2, 19, 19
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	delay 30
	msgbox InterrogationRoom_FirstScene_Text_0
	closemessage
	delay 30
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	special SpawnCameraObject
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, InterogationRoom_CameraUp
	waitmovement 0
	delay 30
	playse SE_DOOR
	waitse
	setobjectxy 1, 5, 7
	applymovement 1, CommonMovement_FaceRight
	delay 30
	applymovement 1, InterogationRoom_AgentSit
	waitmovement 0
	delay 30
	load_field_pic 0, 40, 80
	msgbox InterrogationRoom_FirstScene_Text_1
	msgbox InterrogationRoom_FirstScene_Text_2
	closemessage
	destroy_field_pic 0
	applymovement 1, CommonMovement_FaceLeft
	waitmovement 0
	delay 60
	applymovement 1, CommonMovement_FaceDown
	waitmovement 0
	delay 30
	setobjectxy 2, 7, 9
	clearflag FLAG_HIDE_FILES
	delay 30
	load_field_pic 0, 40, 80
	msgbox InterrogationRoom_FirstScene_Text_3
	msgbox InterrogationRoom_FirstScene_Text_4
	closemessage
	destroy_field_pic 0
	applymovement 2, InterogationRoom_OpenFile
	waitmovement 0
	load_field_pic 0, 40, 80
	msgbox InterrogationRoom_FirstScene_Text_5
	msgbox InterrogationRoom_FirstScene_Text_6
	closemessage
	destroy_field_pic 0
	delay 30
	call Agent_ShakeHead
	load_field_pic 0, 40, 80
	msgbox InterrogationRoom_FirstScene_Text_7
	closemessage
	destroy_field_pic 0
	playse SE_DOOR
	fadescreen FADE_TO_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, InterogationRoom_CameraDown
	waitmovement 0
	special RemoveCameraObject
	msgbox InterrogationRoom_FirstScene_Text_8
	closemessage
	delay 60
	msgbox InterrogationRoom_FirstScene_Text_9, MSGBOX_SIGN
	closemessage
	setvar VAR_GAMESTATE, 2
	setflag FLAG_SYS_REMOVE_WARP_FADE
	warp MAP_OAK_LAB_INTRO, 255, 9, 20
	closemessage
	releaseall
	end


InterogationRoom_CameraUp:
	walk_up
	walk_up
	step_end

InterogationRoom_CameraDown:
	walk_down
	walk_down
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

Agent_ShakeHead::
	applymovement 1, CommonMovement_AgentShakeHead
	waitmovement 0
	delay 30
	return


CommonMovement_AgentShakeHead:
	emote_anim_frame_one
	emote_anim_frame_two
	emote_anim_frame_one
	emote_anim_frame_two
	face_down
	delay_16
	step_end

InterogationRoom_OpenFile:
	face_down
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	step_end

InterrogationRoom_FirstScene_Text_0:
	.string "???: And so, the game begins.$"

InterrogationRoom_FirstScene_Text_1:
	.string "???: I see you finally decided to talk.$"

InterrogationRoom_FirstScene_Text_2:
	.string "???: See?\nThis isn't so bad.\pLet us begin.$"

InterrogationRoom_FirstScene_Text_3:
	.string "Agent: So.\nA bit of backstory on you.$"

InterrogationRoom_FirstScene_Text_4:
	.string "Remember, I'm here to help you.\pYou're not getting away if you don't\ncooperate.$"

InterrogationRoom_FirstScene_Text_5:
	.string "Agent: Says here you used to\nbe a POKéMON trainer.$"

InterrogationRoom_FirstScene_Text_6:
	.string "A quite prolific one,\nat that.$"

InterrogationRoom_FirstScene_Text_7:
	.string "Now I'm wondering...\nHow does a person like THAT stoop to\lsuch lows...$"

InterrogationRoom_FirstScene_Text_8:
	.string "Agent: You got your start like so many\n"
	.string "trainers back in the day. How long ago\l"
	.string "was that?$"

InterrogationRoom_FirstScene_Text_9:
	.string "PROLOGUE\n11 Years ago...$"
