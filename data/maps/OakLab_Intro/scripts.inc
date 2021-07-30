OakLab_Intro_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OakLab_Intro_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OakLab_Intro_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, OakLab_Intro_Init
	.2byte 0


OakLab_Intro_Init::
	msgbox OakLab_Intro_Init_Text_0
	closemessage
	setvar VAR_TEMP_0, 1
	return


OakLab_Intro_Init_Text_0:
	.string "Transform!$"
