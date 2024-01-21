{"human"
	{on spawn overload
		{add_view	"cigarettesmoke"		"smoke"		"head"}
		{add_view	"drops_water_small2"	"on_water"	"foot3r"}
		{add_view	"drops_water_small2"	"on_water"	"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"foot3r"}
		{add_view	"drops_water_small3"	"swim"		"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"hand2r"}
		{add_view	"drops_water_small3"	"swim"		"hand2l"}
		{add_view	"wash_human_small"		"swim_move"	"head"}
		{add_view	"drops_puddle_small"	"on_puddle"	"foot3r"}
		{add_view	"drops_puddle_small"	"on_puddle"	"foot3l"}
		{add_view	"drops_puddle_small"	"die_in_swamp"	"foot3r"}
		{add_view	"drops_puddle_small"	"die_in_swamp"	"foot3l"}

		{add_view	"marker_healing" 		"marker_healing" "head"}
		{add_view	"marker_repair" 		"marker_repair" "head"}
		{add_view	"marker_ammo_out" 		"marker_ammo_out" "head"}
		{add_view	"marker_ammo_refill" 	"marker_ammo_refill" "head"}
		{add_view	"marker_personage" 		"marker_personage" "head"}
		{add_view	"marker_personage_acute""marker_personage_acute" "head"}
		{add_view	"marker_veterancy" 		"marker_veterancy" "head"}

		{link_sound "move_ground" "human/move/ground"}
		{link_sound "move_road"   "human/move/road"}
		{link_sound "move_sand"   "human/move/sand"}
		{link_sound "move_snow"   "human/move/snow"}
		{link_sound "move_grass"  "human/move/grass"}

		{link_sound "swim" "human/move/swim"}

		{call "burn_fx_inited"}
	}

	{on contact overload
		{if not impregnable
			{if not effector "flame_pointer"
				{if not effector "flame_piece"
					{if not effector "shoot_blocker"
						{if not tagged "contact_cooldown"
							{tags add "contact_cooldown"}
							{kill_flags reset}
							{if effector "tank"
								{if not user_control
									{health_damage_crush "die" "crush"}
								 else
									{health_damage_crush "die" "crush"}
								}
							else effector "vehicle"
								{if not dead
									{if not user_control
										{call "die"}
									 else
										{call "die"}
									}
								else
									{spawn "bloodsparks_small"}
								}
							else effector "knife"
								{if contact_velocity 5
									{health_damage_count 500
										{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
									}
								}
							(define "health_damage"
								{health_damage_count %c
									{effects "" "hit" "damage" "die" "die"}
								}
				  	        )
							else effector "axe"
								{if contact_velocity 5
				  		        	("health_damage" c(500))
				  		        }
							(define "contact_part"
								else effector %e
									{if contact_velocity %v
										{if difficulty "easy"
											{if user_control
												("health_damage" c(%ud))
											else
												("health_damage" c(%d))
											}
										else
											("health_damage" c(%d))
										}

										("health_damage" c(%d))
									}
				  	        )
							("contact_part" e("building_part")	v(3)	ud(20)	d(120))
							("contact_part" e("big part")		v(3)	ud(20)	d(120))
							("contact_part" e("medium part")	v(6)	ud(10)	d(80))
							("contact_part" e("small part")		v(10)	ud(3)	d(40))
							else effector "chicken"
								{health_damage_count 0
									{effects "" "hit" "hit" "hit" "hit"}
								}
							else effector "wire"
								{health_damage_count 20
									{effects "" "hit" "damage" "die" "die"}
								}
							else effector "molotov_coctail"
								{health_damage_count 10000
									{effects "" "hit" "hit" "_burn" "_burn"}
								}
							}
							{delay 2
								{tags remove "contact_cooldown"}
							}
						}
					}
				}
			else effector "napalm"
				{if not tagged "burned"
					{call "hit-signal-napalm"}
				}
			else
				{if not tagged "burned"
					{call "hit-signal-fuel"}
				}
			}
		}
	}
	{on "hit-signal-napalm"
		{kill_delay "to_quench"}
		{tags add "ignited"}
		{delay 1.5 "to_quench"
			{tags remove "ignited"}
		}
	}
	{on "hit-signal-fuel"
		{kill_delay "to_quench"}
		{tags add "ignited"}
		{delay 1.0 "to_quench"
			{tags remove "ignited"}
		}
	}

	{on "die_without_blood" overload
		{view pause "swim"}
		{call "die_scream"}
		{if not kill_flags blast
			{kill_flags piercing}
		}
		{if tagged "burned"
			{view pause	"napalmshot"}
			{view pause	"fuelshot"}
			{tex_morph "burned" 3}
			{able "personage" 0}
			{ani_stop "die_gas_dark_sintera"}
			{ani_stop "die_flame_dark_sintera"}
			{ani_stop "die_lie_dark_sintera"}
			{kill_delay "flamer_deadzone_check"}
			{die}
		else
			{view pause	"napalmshot"}
			{view pause	"fuelshot"}
			{kill_delay "flamer_deadzone_check"}
			{die}
		}
		{delay 3
			{volumes enable contact}
		}
	}

	{on "burn_fx_inited"
		{add_view "smoke_dead_small" "burn_fire"	"body"}
		{add_view "smoke_dead_small" "burn_fire"	"hand1l"}
		{add_view "smoke_dead_small" "burn_fire"	"hand1r"}
		{add_view "smoke_dead_small" "burn_fire"	"foot2l"}
		{add_view "smoke_dead_small" "burn_fire"	"foot2r"}
		{if able "burning"
			{view start "burn_fire"}
			{tags add "burn_fx_playing"}
		else
			{view stop "burn_fire"}
			{tags remove "burn_fx_playing"}
		}
	}
	{on "burn_volume" overload
		{if not tagged "burned"
			{if not tagged "ignited"
				{health_damage_count 1.5
					{effects "" "hit" "hit" "_burn" "_burn"}
				}
			else
				{health_damage_count 15
					{effects "" "hit" "hit" "_burn" "_burn"}
				}

				{kill_delay "stop_burn_fx"}
				{if not tagged "burn_fx_playing"
					{add_view "smoke_dead_small" "burn_fire"	"body"}
					{add_view "smoke_dead_small" "burn_fire"	"hand1l"}
					{add_view "smoke_dead_small" "burn_fire"	"hand1r"}
					{add_view "smoke_dead_small" "burn_fire"	"foot2l"}
					{add_view "smoke_dead_small" "burn_fire"	"foot2r"}
					{view start "burn_fire"}
					{tags add "burn_fx_playing"}
				}
				{delay 1.5 "stop_burn_fx"
					{if not tagged "burned"
						{view stop "burn_fire"}
						{tags remove "burn_fx_playing"}
					}
				}
			}
		}
	}
	{on "burn_scream" overload
		{if not dead
			{if not senseless
				{talk "burn_cry"}
			}
		}
	}
	{on "_burn" overload ; burn to die
		{if not dead
			{if not tagged "burned"
				{tags add "burned"}
				{able "burning" 1}
				{burn time 8} ; total burn time, use for flag checking

				{kill_delay "stop_burn_fx"}
				{if not tagged "burn_fx_playing"
					{add_view "smoke_dead_small" "burn_fire"	"body"}
					{add_view "smoke_dead_small" "burn_fire"	"hand1l"}
					{add_view "smoke_dead_small" "burn_fire"	"hand1r"}
					{add_view "smoke_dead_small" "burn_fire"	"foot2l"}
					{add_view "smoke_dead_small" "burn_fire"	"foot2r"}
					{view start "burn_fire"}
					{tags add "burn_fx_playing"}
				}
				{call "burn_scream"}

				{weapon_work "hand_right" 0}
				{able "select" 0}

				{if linked
					{tags add "burn_linked"}
					{throw_off up 0 1.5 dir 0 1.5 die}
				}
				{delay 0.5 0.2
					{if tagged "burn_linked"
						{if not altitude 0.5
							{chassis_work 0}
							{ani_play "die_lie_dark_sintera" 1.5 resume}
						}
					else
						{if not lying
							{chassis_work 0}
							{knockdown 0}
							{ani_play "die_gas_dark_sintera" 0.75 resume}
							{ani_play "die_flame_dark_sintera" 2.0 resume}
						else
							{chassis_work 0}
							{ani_play "die_lie_dark_sintera" 1.5 resume}
						}
					}
				}

				{delay 5 1
					{kill_flags reset}
					{kill_flags piercing}
					{health_damage_count 10000
						{effects "" "hit" "hit" "die" "die"}
					}
					{delay 0.5
						{view stop "burn_fire"}
						{tags remove "burn_fx_playing"}
						{if dead
							{if terrain_fx "puddle"
								{call "stop_burn"}
							else
								{if not tagged "burned_fx_playing"
									{add_view "smoke_dead_small1" "burn_fire1" 	"body"}
									{add_view "smoke_dead_small1" "burn_fire1"	"hand1l"}
									{add_view "smoke_dead_small1" "burn_fire1"	"hand1r"}
									{add_view "smoke_dead_small1" "burn_fire1"	"foot2l"}
									{add_view "smoke_dead_small1" "burn_fire1"	"foot2r"}
									{view start "burn_fire1"}
									{tags add "burned_fx_playing"}
								}
								{delay 7.5 1.5
									{view stop "burn_fire1"}
									{tags remove "burned_fx_playing"}
									{call "stop_burn"}
								}
							}
						else
							{call "stop_burn"}
						}
					}
				}
			}
		}
	}
	{on "stop_burn" overload
		{ani_stop "die_gas_dark_sintera"}
		{ani_stop "die_flame_dark_sintera"}
		{ani_stop "die_lie_dark_sintera"}
		{tags remove "burn_linked"}
		{tags remove "burned"}
		{able "burning" 0}

		{if not dead
			{chassis_work 1}
			{weapon_work "hand_right" 1}
			{able "select" 1}
		}

		{delay 1.5
			{burn stop_retry}
		}
	}

	{on "link_weapon" overload
		{view hide	"flashbarrel"}
		{view pause	"flashbarrel"}

		{view pause	"napalmshot"}
		{view pause	"fuelshot"}
		{view hide	"firebarrel"}
		{view pause	"firebarrel"}
		{tags remove "flamethrower"}
		{tags remove "napalm"}
		{kill_delay "flamer_deadzone_check"}

		{if stuff "pistol"
			{add_view "flash_gun_small" "flashbarrel" "foresight3"}
			{add_view "shell_smg"			"shell"			"FXshell"}
		else stuff "shotgun"
			{add_view "flash_gun_big" "flashbarrel" "foresight3"}
			{add_view "shell_shotgun"			"shell"			"FXshell"}
		else stuff "rifle"
			{add_view "flash_gun_small" "flashbarrel" "foresight3"}
			{add_view "shell_mgun"			"shell"			"FXshell"}
		else stuff "smg"
			{add_view "flash_gun_small" "flashbarrel" "foresight3"}
			{add_view "shell_smg"			"shell"			"FXshell"}
		else stuff "mgun"
			{add_view "flash_gun_big" "flashbarrel" "foresight3"}
			{add_view "shell_mgun"			"shell"			"FXshell"}
		else stuff "flame_thrower napalm"
			{add_view "flamer_foresight" "firebarrel" "foresight3"}
			{add_view "flash_flamer" "flashbarrel" "foresight3"}
			{view show	"firebarrel"}
			{view start	"firebarrel"}
			{add_view "flamer_piece" "napalmshot" "foresight3"}
			{tags add "flamethrower"}
			{tags add "napalm"}
			{call "flamer_deadzone_check"}
		else stuff "flame_thrower"
			{add_view "flamer_foresight" "firebarrel" "foresight3"}
			{add_view "flash_flamer" "flashbarrel" "foresight3"}
			{view show	"firebarrel"}
			{view start	"firebarrel"}
			{add_view "flamer_piece_g" "fuelshot" "foresight3"}
			{tags add "flamethrower"}
			{call "flamer_deadzone_check"}
		}
	}
	{on fire "hand_right" overload
		{kill_delay "fire"}
		{kill_delay "shell"}
		{view show	"flashbarrel"}
		{view start	"flashbarrel"}
		{view start "shell"}
		{delay 0.4 "fire"
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
		}
		{delay 0.1 "shell"
			{view pause "shell"}
		}

		{if tagged "flamethrower"
			{if tagged "napalm"
				{spawn "flame_pointer" "foresight3" x
					{impulse forward 90 rnd_dir 1}
				}
				{spawn "flame_pointer" "foresight3" x
					{impulse forward 90 rnd_dir 1}
				}
				{spawn "flame_pointer" "foresight3" x
					{impulse forward 90 rnd_dir 1}
				}
			else
				{spawn "flame_pointer_g" "foresight3" x
					{impulse forward 85 rnd_dir 1}
				}
				{spawn "flame_pointer_g" "foresight3" x
					{impulse forward 85 rnd_dir 1}
				}
				{spawn "flame_pointer_g" "foresight3" x
					{impulse forward 85 rnd_dir 1}
				}
			}
			{if not tagged "playing_flame_shot"
				{tags add "playing_flame_shot"}
				{start_sound "weapon/shot/flame/valour"}
				{delay 0.75 0.25
					{tags remove "playing_flame_shot"}
				}
			}
			{kill_delay "fireflamer"}
			{if tagged "napalm"
				{view start	"napalmshot"}
				{delay 0.5 "fireflamer"
					{view pause	"napalmshot"}
				}
			else
				{view start	"fuelshot"}
				{delay 0.5 "fireflamer"
					{view pause	"fuelshot"}
				}
			}
		}

		{spawn "bazooka_shot" "fxshot" x}
	}
	{on "flamer_deadzone_check"
		{if operatable
			{if not tagged "burned"
				{spawn "shoot_blocker_checker" "foresight3" x
					{impulse forward 0.2}
				}
			}
		}
		{delay 0.1 "flamer_deadzone_check"
			{call "flamer_deadzone_check"}
		}
	}

	{on move on overload
		{view pause	"napalmshot"}
		{view pause	"fuelshot"}

		{if swimming
			{view start "swim_move"}
		}
	}
	{on turn on
		{view pause	"napalmshot"}
		{view pause	"fuelshot"}
	}
	{on movement_mode_changed overload
		{view pause	"napalmshot"}
		{view pause	"fuelshot"}

		{call "stop_move_sounds"}
		{if name "fast"
			{if swimming
				{play_sound "swim" 1}
			else not lying
				{if terrain_fx "road"
					{play_sound "move_road" 1}
				else terrain_fx "country_road"
					{play_sound "move_road" 1}
				else terrain_fx "ice"
					{play_sound "move_snow" 1}
				else terrain_fx "snow"
					{play_sound "move_snow" 1}
				else terrain_fx "sand"
					{play_sound "move_sand" 1}
				else terrain_fx "grass"
					{play_sound "move_grass" 1}
				else
					{play_sound "move_ground" 1}
				}
			}
		}
	}
	{on board in overload
		{view pause	"napalmshot"}
		{view pause	"fuelshot"}

		{view pause "swim"}
	}
}

{"shoot_blocker"
	{on spawn
		{gravity 0}
		{delay 0.1
			{delete}
		}
	}
}
{"shoot_blocker_checker"
	{on "in_hole"
		{tags add "shoot_by_window"}
	}
	{on contact
		{delay_ex 0
			{if not tagged "shoot_by_window"
				{spawn "shoot_blocker" "basis" x}
			}
		}
	}
}