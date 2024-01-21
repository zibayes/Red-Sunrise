{"firewood"
	{inflammation_time 10}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on break_armor
		{call "break"}
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{call "break"}
		}
	}
	{on "break"
		{spawn "wood_crush_big" "root"}
		{delay 0.2 {delete}}
	}
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8 "break_delay" {call "break"}}
			}
		}
	}
}

{"stack"
	{inflammation_time 0.3}
	{on bullet_hit
		{if stuff "shell"
			{spawn "hay_hit_norm"}
		else stuff "bullet"
			{spawn "hay_hit_small2"}
		}
	}
	{on break_armor
		{set "crush" 0}
		{call "crush"}
	}
	{on contact
		{if can_crush
			{set "crush" 1}
			{call "crush"}
		}
	}
	{on "crush"
		{volumes disable visible bullet contact blast}
		{call "crush_fx"}
		{set "fall" 1}
		{tex_morph "crushed" 0.1}
		{ani_play "crush" 10 callback}
	}
	{on "burn_volume"
		{if not burned
			{if volume "fire"
				{call "_burn"}
			}
		}
	}
	{on "_burn"
		{volumes disable visible bullet contact blast}
		{burn volume "fire0" fx "smoke_dead_norm" time 15 even_law}
		{burn volume "fire1" fx "smoke_dead_tree1" time 10 even_law}
		{tex_morph "burned" 8}
		{delay 6.0
			{spawn "burn_grass1"}
			{if not "fall"
				{set "fall" 1}
				{ani_play "crush" callback}
			}
		}
	}
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
		{area disable}
	}
	{on "crush_fx"
		{spawn "wheat_big" no_position}
		{if "crush"
			{spawn "hay_hit_fall" "fx_hayfall1"}
			{spawn "hay_hit_fall" "fx_hayfall2"}
			{spawn "hay_hit_fall" "fx_hayfall3"}
			{spawn "hay_hit_fall" "fx_hayfall4"}
		else
			{spawn "hay_hit_big" no_position}
			{spawn "hay_hit_big" "FX_haulm1"}
			{spawn "hay_hit_big" "FX_haulm2"}
		}
	}
}

{"stack_cta"
	{inflammation_time 0.3}
	{on bullet_hit
		{if stuff "shell"
			{spawn "hay_hit_norm"}
		else stuff "bullet"
			{spawn "hay_hit_small2"}
		}
	}
	{on break_armor
		{if name "blast"
			{if min_energy 40
				{impulse up 1.5 0.5 dir 1.5 0.5}
			else min_energy 25
				{impulse up 0.8 0.3 dir 0.8 0.3}
			}
			{set "crush" 0}
			{call "crush"}
		}		
	}
	{on contact
		{if can_crush
			{call "crush"}
		}
	}
	{on "crush"
		{volumes disable visible bullet contact blast}
		{call "crush_fx"}
		{delete}
	}
	{on "burn_volume"
		{if not burned
			{if volume "fire"
				{call "_burn"}
			}
		}
	}
	{on "_burn"
		{volumes disable visible bullet contact blast}
		{burn volume "body" fx "smoke_dead_norm" time 15 even_law}
		{burn volume "body" fx "smoke_dead_tree1" time 10 even_law}
		{tex_morph "burned" 8}
		{delay 6.0
			{spawn "burn_grass1"}
			{call "crush"}
		}
	}
	{on "crush_fx"
		{spawn "straw_1" no_position}
		{if "crush"
			{spawn "hay_hit_fall" "fx_hayfall1"}
			{spawn "hay_hit_fall" "fx_hayfall2"}
			{spawn "hay_hit_fall" "fx_hayfall3"}
			{spawn "hay_hit_fall" "fx_hayfall4"}
		else
			{spawn "hay_hit_big" no_position}
			{spawn "hay_hit_big" "FX_haulm1"}
			{spawn "hay_hit_big" "FX_haulm2"}
		}
	}
}

{"stack tent"
	{on "crush_fx" overload}
	{on bullet_hit overload
		{if not under_water
			{if stuff "bullet"
				{spawn "spheredust_small_short"}
			else stuff "zenite"
				{spawn "spheredust_small_short"}
			else stuff "shell"
				{spawn "spheredust_small_short"}
			else stuff "mortar"
				{spawn "spheredust_small_short"}
			}
		}
	}
}

{"gate"
	{on spawn
		{call "update_area"}
	}
	{on "open"
		{if not "user_opened"
			{set "opened" 1}
			{ani_play "open" resume callback}
			{call "update_area"}
		}
	}
	{on "close"
		{if not "user_opened"
			{set "opened" 0}
			{ani_play "open" -1 resume}
			{call "update_area"}
		}
	}
	{on animation_end "open"
		{tags add "opened"}
	}
	{on "update_area"
		{if "opened"
			{area disable	"close"}
			{area enable	"left"}
			{area enable	"right"}
		else
			{area enable	"close"}
			{area disable	"left"}
			{area disable	"right"}
		}
	}
	{on "open_disable"
		{volumes "door_lock" disable touch}
	}
	{on "open_enable"
		{volumes "door_lock" enable touch}
	}
}



{"ferry"
	{on spawn
		{call "update_area"}
	}
	(define "update_area"
		{if "opened%0"
			{area disable	"close%0_%1"}
			{area enable	"left%0_%1"}
			{area enable	"right%0_%1"}

			{area disable	"close%0_%2"}
			{area disable	"left%0_%2"}
			{area disable	"right%0_%2"}
		else
			{area enable	"close%0_%1"}
			{area disable	"left%0_%1"}
			{area disable	"right%0_%1"}

			{area disable	"close%0_%2"}
			{area disable	"left%0_%2"}
			{area disable	"right%0_%2"}
		}
	)
	(define "door"
		{on "open%0"
			{set "opened%0" 1}
			{ani_play "open%0"}
			{call "update_area%0"}
		}
		{on "close%0"
			{set "opened%0" 0}
			{ani_play "close%0"}
			{call "update_area%0"}
		}
		{on "open_fast%0"
			{set "opened%0" 1}
			{ani_wind "open%0" end}
			{call "update_area%0"}
		}
		{on "close_fast%0"
			{set "opened%0" 0}
			{ani_wind "close%0" end}
			{call "update_area%0"}
		}
		{on "update_area%0"
			{if not "moved"
				("update_area" args %0 1 2)
				{area enable	"rectangle01"}
				{area enable	"rectangle02"}
				{area disable	"rectangle03"}
				{area disable	"rectangle04"}
			else
				("update_area" args %0 2 1)
				{area disable	"rectangle01"}
				{area disable	"rectangle02"}
				{area enable	"rectangle03"}
				{area enable	"rectangle04"}
			}
		}
	)
	("door" args 1)
	("door" args 2)
	{on "update_area"
		{call "update_area1"}
		{call "update_area2"}
	}
	{on "move_front"
		{set "moved" 1}
		{call "update_area"}
		{land off}
		{ani_play "move" callback}
	}
	{on "move_back"
		{set "moved" 0}
		{call "update_area"}
		{land off}
		{ani_play "move" -1 callback}
	}
	{on "update_land"
		{land off}
		{land on}
	}
	{on animation_end "move"
		{land on}
	}
}

{"tank_platform"
	{on "close"
		{land off}
		{ani_play "close1"}
		{ani_play "close2"}
	}
	{on "open"
		{land on}
		{ani_play "close1" -1}
		{ani_play "close2" -1}
	}

	{on "move"
		{ani_play "move"}	
	}
}

{"switch"
	{on "switch"
		{tags add "switch"}
	}
}

{"dynamite_fuse"
	{on "switch"
		{tags add "switch"}
		{ani_play "move"}
	}
}


{"gate door_big"
	{on "open"
		{start_sound "vehicle/engine/door"}
	}
	{on "close"
		{start_sound "vehicle/engine/door"}
	}
}

{"gate lock"
	{on "open"
;		{start_sound "vehicle/engine/door"}
		{volumes "attach" enable touch}
	}
	{on bullet_hit
		{if volume "lock"
			{if not "opened"
				{call "open"}
				{set "user_opened" 1}
				{delay_ex 0
					{tear "piece_small_steel" bone "lock"
						{impulse up -1 0.7 dir 2.5 0.3 no_position}
					}
				}
			}
		}
	}
}

{"sandbag"
	{on bullet_hit
		{if stuff "bullet"
			{spawn "ex_air_sm"}
			{bullet_detonate}
		else stuff "shell"
			{spawn "sand_hit_small"}
			{bullet_detonate}
		}
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{delay 0
				{call "crush"}
			}
		}
	}
	{on "crush"
		{if not "crushed"
			{set "crushed" 1}
			{set_skeleton "_x"}
			{ani_play "crush1" callback}
			{call "update_fx"}
			{call "effects"}
		}
	}
	{on animation_end "crush1"
		{ani_play "crush2"}
	}
}

{"sand_bag_small"
	{on break_armor
		{spawn "sand_hit_small"}
		{delay 0.2
			{delete}
		}
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{spawn "sand_hit_small"}
			{delete}
		}
	}
}

{"sand_bag_big"
	{on break_armor
		{spawn "wood_crush_big"}
		{delay 0.2
			{delete}
		}
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{spawn "wood_crush_big"}
			{delete}
		}
	}
}

{"showcase"
	{on "break_window"
		{area disable}
	}
}

{"fountain_small"
	{on spawn
		{add_view "drops_water_fountain" "water" "FX_water"}
		{add_view "drops_water_fountain" "water" "FX_water1"}
		{add_view "drops_water_fountain" "water" "FX_water2"}
		{add_view "drops_water_fountain" "water" "FX_water3"}
		{add_view "fountain_small" "water" "FX_water4"}
		{view start "water"}
	}
}

{"waterfall_big"
	{on spawn
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall1"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall2"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall3"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall4"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall5"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall6"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall7"	}
		{view start "wfall"}
	}
}

{"steam_small"
	{on spawn
		{add_view "steam" "smoke" "FX_steam"}
		{view start "smoke"}
	}
}

{"steam_big"
	{on spawn
		{add_view "smoke_black" "smoke" "FX_steam"}
		{view start "smoke"}
	}
}

{"trench"
	{on blast
		{if volume "body"
			{if min_energy 3
				{call "break"}
			}
		}
	}
	{on "break"
		{if not "broken"
			{set "broken" 1}
			{tags add "crushed"}
			{call "disable_volumes"}
			{delay_ex 0
				{set_skeleton "_x"}
				{call "update_fx"}
				{set "first_stage" 1}
				{set "last_stage" 1}
				{call "effects"}
				{ani_play "crush"}
				{delay 0.1
					{update_visibility_patch}
				}
			}
		}
	}
}

{"sewer"
	{on spawn
		{call "update_area"}
		{ani_play "open"}
	}
	{on "update_area"
		{if "opened"
			{area enable "sewer"}
		else
			{area disable "sewer"}
		}
	}
	{on "open"
		{ani_play "open" +1 resume}
		{set "opened" 1}
		{call "update_area"}
	}
	{on "close"
		{ani_play "open" -1 resume}
		{set "opened" 0}
		{call "update_area"}
	}
}

{"delete_after_crush"
	{on "break"
		{delete}
	}
}

{"boat_trap"
	{on "open"
		{land off}
		{ani_wind "land" end}
		{ani_play "open"}
		{delay 0.1
			{land on}
			{area disable "left"}
			{area disable "right"}
		}
	}
	{on "close"
		{land off}
		{ani_wind "land" begin}
		{ani_play "open" -1}
		{delay 5
			{land on}
			{area enable "left"}
			{area enable "right"}
		}
	}
}

;// MODERN PATCH

{"hangar1_mod_v1" 
	(define "OpenDoorHangar" ;("OpenDoorHangar" Num() doorL() doorR() )
		{on "openDoor%Num"
			{damage_report "openDoor" "Код работает начало"}
			{if not tagged "lockDoor"
				{damage_report "noLock" "Двери не заблокированы \ "}
				
				{if tagged "%doorL"
					{set "opened" 0}
					{set "doorOpen%Num" 0}
					{tags remove "%doorL %doorR"}
					{tags remove "opened_%doorL opened_%doorR"}
					{tags remove "DoorOpen%Num"}
					{call "closeDoor%Num"}
						{call "update_areas_door1"}
						{call "update_areas_door2"}
						{call "update_areas_door3"}
						{call "update_areas_door4"}
				else not tagged "%doorL"
					{set "opened" 1}
					{set "doorOpen%Num" 1}
					{tags add "%doorL %doorR"}
					{tags add "DoorOpen%Num"}
					{play_sound "OpenClose"}
					{ani_play "open%Num" 0.25 resume callback}
					{delay 3.5 {stop_sound "OpenClose"}}
						{call "update_areas_door1"}
						{call "update_areas_door2"}
						{call "update_areas_door3"}
						{call "update_areas_door4"}
				}
			else tagged "lockDoor"
				{if not tagged "%doorL"	
					{set "opened" 1}
					{set "doorOpen%Num" 1}
					{tags add "%doorL %doorR"}
					{tags add "DoorOpen%Num"}
					{play_sound "OpenClose"}
					{ani_play "open%Num" 0.25 resume callback}
					{delay 3.5 {stop_sound "OpenClose"}}
						{call "update_areas_door1"}
						{call "update_areas_door2"}
						{call "update_areas_door3"}
						{call "update_areas_door4"}
				}
			}
			
			{damage_report "openDoor" "Код работает конец"}
		}
		{on "closeDoor%Num"
			{if not tagged "%doorL"
				{set "opened" 0}
				{set "doorOpen%Num" 0}
				{play_sound "OpenClose"}
				{ani_play "open%Num" -0.25}
				{delay 3.5 {stop_sound "OpenClose"}}
					{call "update_areas_door1"}
					{call "update_areas_door2"}
					{call "update_areas_door3"}
					{call "update_areas_door4"}
			}
		}
		{on animation_end "open%Num"
			{tags add "opened_%doorL opened_%doorR"}
		}
	)	
	{on spawn
		{call "update_areas_door1"}
		{call "update_areas_door2"}
		{call "update_areas_door3"}
		{call "update_areas_door4"}
		{link_sound "OpenClose" "vehicle/engine/door"}
	}
	
	("OpenDoorHangar" Num(1) doorL(door1l) doorR(door1r))
	("OpenDoorHangar" Num(2) doorL(door2l) doorR(door2r))
	("OpenDoorHangar" Num(3) doorL(door3l) doorR(door3r))
	("OpenDoorHangar" Num(4) doorL(door4l) doorR(door4r))
	
	{on "open_disable"
		{volumes "door1l" disable touch}
		{volumes "door1r" disable touch}
		
		{volumes "door2l" disable touch}
		{volumes "door2r" disable touch}
		
		{volumes "door3l" disable touch}
		{volumes "door3r" disable touch}
		
		{volumes "door4l" disable touch}
		{volumes "door4r" disable touch}
	}
	{on "open_enable"
		{volumes "door1l" enable touch}
		{volumes "door1r" enable touch}
		
		{volumes "door2l" enable touch}
		{volumes "door2r" enable touch}
			
		{volumes "door3l" enable touch}
		{volumes "door3r" enable touch}
			
		{volumes "door4l" enable touch}
		{volumes "door4r" enable touch}
	}
	
	
	
	
	{on "update_areas_door1"
		{if "opened"
			{if "doorOpen1"
				{damage_report "door1" "door1 - Активна"}
				{area disable	"door1close"}
				{area enable	"door1left"}
				{area enable	"door1right"}
			}
		else
			{if not "doorOpen1"
				{area enable	"door1close"}
				{area disable	"door1left"}
				{area disable	"door1right"}
			}	
		}
	}
	{on "update_areas_door2"
		{if "opened"
			{if "doorOpen2"	
				{damage_report "door2" "door2 - Активна"}
				{area disable	"door2close"}
				{area enable	"door2left"}
				{area enable	"door2right"}
			}
		else
			{if not "doorOpen2"	
				{area enable	"door2close"}
				{area disable	"door2left"}
				{area disable	"door2right"}
			}
		}
	}
	{on "update_areas_door3"
		{if "opened"
			{if "doorOpen3"		
				{damage_report "door3" "door3 - Активна"}
				{area disable	"door3close"}
				{area enable	"door3left"}
				{area enable	"door3right"}
			}
		else
			{if not "doorOpen3"		
				{area enable	"door3close"}
				{area disable	"door3left"}
				{area disable	"door3right"}
			}
		}
	}
	{on "update_areas_door4"
		{if "opened"
			{if "doorOpen4"			
				{damage_report "door4" "door4 - Активна"}
				{area disable	"door4close"}
				{area enable	"door4left"}
				{area enable	"door4right"}
			}
		else
			{if not "doorOpen4"	
				{area enable	"door4close"}
				{area disable	"door4left"}
				{area disable	"door4right"}
			}
		}
	
	}
}

; АНГАР 2 типа
{"hangar1_mod_v2" 
	(define "OpenDoorHangarL" ;("OpenDoorHangarL" args 1)
		{on "OpenDoor%0Left"
			{if tagged "doorL%0"
				{set "openedL%0" 0}
				{tags remove "doorL%0"}
				{call "CloseDoor%0Left"}
				{call "update_areas_door%0L"}
			else not tagged "doorL%0"
				{set "openedL%0" 1}
				{tags add "doorL%0"}
				{play_sound "OpenClose"}
				{ani_play "open%0l" 0.25 resume callback}
				{delay 4.1 {stop_sound "OpenClose"}}
				{call "update_areas_door%0L"}
			}
		}
		{on "CloseDoor%0Left"
			{if tagged "opened_L%0"
				{tags remove "opened_L%0"}
				{set "openedL%0" 0}
				{play_sound "OpenClose"}
				{ani_play "open%0l" -0.25}
				{delay 4.1 {stop_sound "OpenClose"}}
				{call "update_areas_door%0L"}
			}
		}
		{on animation_end "open%0l"
			{tags add "opened_L%0"}
		}
	)
	(define "OpenDoorHangarR" ;("OpenDoorHangarR" args 1)
		{on "OpenDoor%0Right"
			{if tagged "doorR%0"
				{set "openedR%0" 0}
				{tags remove "doorR%0"}
				{call "CloseDoor%0Right"}
				{call "update_areas_door%0R"}
			else not tagged "doorR%0"
				{set "openedR%0" 1}
				{tags add "doorR%0"}
				{play_sound "OpenClose"}
				{ani_play "open%0r" 0.25 resume callback}
				{delay 4.1 {stop_sound "OpenClose"}}
				{call "update_areas_door%0R"}
			}
		}
		{on "CloseDoor%0Right"
			{if tagged "opened_R%0"
				{tags remove "opened_R%0"}
				{set "openedR%0" 0}
				{play_sound "OpenClose"}
				{ani_play "open%0r" -0.25}
				{delay 4.1 {stop_sound "OpenClose"}}
				{call "update_areas_door%0R"}
			}
		}
		{on animation_end "open%0r"
			{tags add "opened_R%0"}
		}
	)
	{on spawn
		{call "update_areas_all"}
		{link_sound "OpenClose" "vehicle/engine/door"}
	}
	
	("OpenDoorHangarL" args 1)
	("OpenDoorHangarL" args 2)
	("OpenDoorHangarL" args 3)
	("OpenDoorHangarL" args 4)
	
	("OpenDoorHangarR" args 1)
	("OpenDoorHangarR" args 2)
	("OpenDoorHangarR" args 3)
	("OpenDoorHangarR" args 4)
	
	{on "update_areas_all" ; {call "update_areas_all"}
		{call "update_areas_door1L"}
		{call "update_areas_door2L"}
		{call "update_areas_door3L"}
		{call "update_areas_door4L"}
		
		{call "update_areas_door1R"}
		{call "update_areas_door2R"}
		{call "update_areas_door3R"}
		{call "update_areas_door4R"}
	}
	
	{on "open_disable"
		{volumes "door1l" disable touch}
		{volumes "door1r" disable touch}
		
		{volumes "door2l" disable touch}
		{volumes "door2r" disable touch}
		
		{volumes "door3l" disable touch}
		{volumes "door3r" disable touch}
		
		{volumes "door4l" disable touch}
		{volumes "door4r" disable touch}
	}
	{on "open_enable"
		{volumes "door1l" enable touch}
		{volumes "door1r" enable touch}
		
		{volumes "door2l" enable touch}
		{volumes "door2r" enable touch}
			
		{volumes "door3l" enable touch}
		{volumes "door3r" enable touch}
			
		{volumes "door4l" enable touch}
		{volumes "door4r" enable touch}
	}
	;---------------------------------------
	{on "update_areas_door1L"
		{if "openedL1" ;Открыта первая левая дверь
			{damage_report "wall" "doorl - Активна"}
			{area disable	"door1close_left"} ; Левая часть зоны двери.
			{area disable	"door1close"} ; Вся зона
			{area enable	"door1left"} ; Зона открытой двери
			{if not tagged "doorR1" ; Если нет тэга правой двери, вкл. зону правую.
				{area disable "door1right"}
				{area enable "door1close_right"}
			}
		else ;Если закрыта первая дверь
			{area enable	"door1close_left"}; Вкл. Левую часть зоны двери.
			{if not tagged "doorR1" ; Если нет тэга правой двери, вкл. всю зону.
				{area enable	"door1close"}
				{area disable	"door1right"}	
			}
			{area disable	"door1left"}
		}
	}
	{on "update_areas_door2L"
		{if "openedL2"
			{damage_report "wall" "doorl - Активна"}
			{area disable	"door2close_left"}
			{area disable	"door2close"}
			{area enable	"door2left"}
			{if not tagged "doorR2"
				{area disable "door2right"}
				{area enable "door2close_right"}
			}
		else
			{area enable	"door2close_left"}
			{if not tagged "doorR2"
				{area enable	"door2close"}
				{area disable	"door2right"}	
			}
			{area disable	"door2left"}
		}
	}
	{on "update_areas_door3L"
		{if "openedL3"
			{damage_report "wall" "doorl - Активна"}
			{area disable	"door3close_left"}
			{area disable	"door3close"}
			{area enable	"door3left"}
			{if not tagged "doorR3"
				{area disable "door3right"}
				{area enable "door3close_right"}
			}
		else
			{area enable	"door3close_left"}
			{if not tagged "doorR3"
				{area enable	"door3close"}
				{area disable	"door3right"}	
			}
			{area disable	"door3left"}
		}
	}
	{on "update_areas_door4L"
		{if "openedL4"
			{damage_report "wall" "doorl - Активна"}
			{area disable	"door4close_left"}
			{area disable	"door4close"}
			{area enable	"door4left"}
			{if not tagged "doorR4"
				{area disable "door4right"}
				{area enable "door4close_right"}
			}
		else
			{area enable	"door4close_left"}
			{if not tagged "doorR4"
				{area enable	"door4close"}
				{area disable	"door4right"}	
			}
			{area disable	"door4left"}
		}
	}

	{on "update_areas_door2R"
		{if "openedR2"
			{damage_report "wall" "doorr - Активна"}
			{area disable	"door2close_right"}
			{area disable	"door2close"}
			{area enable	"door2right"}
			{if not tagged "doorL2"
				{area disable "door2left"}
				{area enable "door2close_left"}
			}
		else
			{area enable	"door2close_right"}
			{if not tagged "doorL2"
				{area enable	"door2close"}
				{area disable	"door2left"}	
			}
			{area disable	"door2right"} 
		}
	}
	{on "update_areas_door3R"
		{if "openedR3"
			{damage_report "wall" "doorr - Активна"}
			{area disable	"door3close_right"}
			{area disable	"door3close"}
			{area enable	"door3right"}
			{if not tagged "doorL3"
				{area disable "door3left"}
				{area enable "door3close_left"}
			}
		else
			{area enable	"door3close_right"}
			{if not tagged "doorL3"
				{area enable	"door3close"}
				{area disable	"door3left"}	
			}
			{area disable	"door3right"} 
		}
	}
	{on "update_areas_door4R"
		{if "openedR4"
			{damage_report "wall" "doorr - Активна"}
			{area disable	"door4close_right"}
			{area disable	"door4close"}
			{area enable	"door4right"}
			{if not tagged "doorL4"
				{area disable "door4left"}
				{area enable "door4close_left"}
			}
		else ;Если закрыта первая дверь
			{area enable	"door4close_right"}
			{if not tagged "doorL4"
				{area enable	"door4close"}
				{area disable	"door4left"}	
			}
			{area disable	"door4right"} 
		}
	}
}

;// END OF MODERN PATCH

{"animation"
	{on spawn
		{ani_play "animation" loop}
	}
}

{"opened_one"
	{on spawn
		{if tagged "open" 
			{ani_wind "open_door" end}
			{area enable	"left"}
			{area enable	"right"}
			{area disable	"close"}
		else 
			{tags add "close"}
			{area disable	"left"}
			{area disable	"right"}
			{area enable	"close"}
			}
		)
	}
	{on "door_open"
		{if tagged "close" 
			{tags remove "close"}
			{tags add "open"}
			{ani_wind "open_door_%tag" end}
			{ani_play "open" +1.8 resume callback}
			{volumes "door_open" disable touch}
			{delay 4
				{area enable	"left"}
				{area enable	"right"}
				{area disable	"close"}
			
				{volumes "door_open" enable touch}
			}
		else tagged "open" 
			{tags add "close"}
			{ani_play "open" -2.0 resume callback}
			{tags remove "open"}
			{volumes "door_open" disable touch}
			{delay 3
				{area disable	"left"}
				{area disable	"right"}
				{area enable	"close"}
				{volumes "door_open" enable touch}
			}
		}
	}
}