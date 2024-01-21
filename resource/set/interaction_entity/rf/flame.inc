; by Cosalcea
{"flame_pointer" ; Napalm, US portable flamethrower
	{on spawn
		{delay_ex 0.02 ; 80m/s*0.02=1.6m
			{volumes "body" enable contact overlap contact_ground}
		}
		{call "specificity"}
	}
	{on "specificity"
		{gravity 20}
		{delay 0.41 ; (range+5)/speed = (27.5+5)m / 80m/s = 0.41s
			{delete}
		}
		{delay 0.31 ; 0.41*0.75
			{if not altitude 0.25
				{call "to_end"}
			}
		}
	}
	{on "in_hole"
		{if not tagged "pierced_window"
			{tags add "pierced_window"}
			{delay_ex 0.01
				{tags remove "pierced_window"}
			}
		}
	}
	{on overlap begin
		{if effector "human"
			{with_effector}
			{if not tagged "burned"
				{call "hit-signal-napalm"}
			}
			{with_effector}
		}
	}
	{on contact
		{delay_ex 0
			{if not tagged "pierced_window"
				{call "to_end"}
			}
		}
	}
	{on ground_hit
		{call "to_end"}
	}
	{on "to_end"
		{if not tagged "end"
			{tags add "end"}
			{physics_work 0}
			{volumes disable all}
			{call "end"}
		}
	}
	{on "end"
		{if not under_water
			{spawn "flame_fuse"
				{tags add "flame_fuse"}
				{delay 0.2
					{delete}
				}
			}
		}
		{physics_work 0}
		{delete}
	}
}
{"flame_piece" ; Napalm, US portable flamethrower
	{on spawn
		{use_local_light 1}
		{delay_ex 0.02 ; 80m/s*0.02=1.6m
			{volumes "body" enable contact overlap contact_ground}
		}
		{delay 0.01
			{add_view "fire_flame_thrower_fly" "fire1" "root"}
			{view start "fire1"}
			{delay 0.01
				{view stop "fire1"}
				{add_view "fire_flame_thrower_fly4" "fire2" "root"}
				{view start "fire2"}
			}
		}
		{call "specificity"}
	}
	{on "specificity"
		{if rand 0.5
			{gravity 20} ; Lighter and has a flater trajectory
		else
			{gravity -5} ; Some fuel fully burned and fly off
		}
		{delay 0.02
			{fire radius 0.5 time 0.41 heating 0.5 follow} ; Not really dealing damage by this, but make soldiers evading flame.
		}
		{delay 0.41 ; (range+5)/speed = (27.5+5)m / 80m/s = 0.41s
			{call "to_end"}
		}
		{delay 0.31 ; 0.41*0.75
			{if not altitude 0.25
				{call "to_end"}
			}
		}
	}
	{on "in_hole"
		{if not tagged "pierced_window"
			{tags add "pierced_window"}
			{delay_ex 0.01
				{tags remove "pierced_window"}
			}
		}
	}
	{on overlap begin
		{if effector "flame_fuse"
			{tags add "detonated"}
			{if rand 0.5
				{call "to_end"}
			}
		}
	}
	{on contact
		{if not effector "fence"
			{if not effector "small construction parts"
				{if effector "human"
					{if tagged "detonated_in_hole"
						{fire radius 0.5 time 3 heating 10 effector}
					}
				}
				{delay_ex 0
					{if not tagged "pierced_window"
						{call "to_end"}
					else
						{tags add "detonated"}
						{if not tagged "detonated_in_hole"
							{tags add "detonated_in_hole"}
							{fire radius 3.0 time 0.1 heating 10}
							{delay_ex 0.06 0.01
								{tags remove "detonated_in_hole"}
							}
						}
					}
				}
			else
				{delay_ex 0
					{if not tagged "pierced_window"
						{call "to_end"}
					else
						{tags add "pierced_fence"}
					}
				}
			}
		else
			{delay_ex 0
				{if not tagged "pierced_window"
					{call "to_end"}
				else
					{tags add "pierced_fence"}
				}
			}
		}
	}
	{on ground_hit
		{call "to_end"}
	}
	{on "to_end"
		{if not tagged "end"
			{tags add "end"}
			{physics_work 0}
			{volumes disable all}
			{view stop "fire1"}
			{view stop "fire2"}
			{call "end"}
		}
	}
	{on "end"
		{if not under_water
			{if tagged "detonated"
				{if rand 0.5
					{call "end_detonated"}
					{fire radius 1.5 time 0.2 heating 0.5}
					{fire radius 0.75 time 0.2 heating 1}
				else
					{spawn "fire_die_small"}
					{fire radius 1.0 time 0.2 heating 0.5}
					{fire radius 0.5 time 0.2 heating 1}
				}
			else
				{spawn "fire_die_small"}
				{fire radius 1.0 time 0.2 heating 0.5}
				{fire radius 0.5 time 0.2 heating 1}
			}
		}
		{delete}
	}
	{on "end_detonated"
		{spawn "flame_detonated" dir_velocity
			{tags add "50s"}
			{delay 50 ; 50s burning area
				{delete}
			}
		}
	}
}
{"flame_pointer_tank" ; Napalm, US tank flamethrower
	{on "specificity" overload
		{gravity 20}
		{delay 0.53 ; 42.5/80
			{delete}
		}
		{delay 0.40 ; 0.53*0.75
			{if not altitude 0.25
				{call "to_end"}
			}
		}
	}
}
{"flame_piece_tank" ; Napalm, US tank flamethrower
	{on "specificity" overload
		{if rand 0.5
			{gravity 20} ; Lighter and has a flater trajectory
		else
			{gravity -5} ; Some fuel fully burning
		}
		{delay 0.02
			{fire radius 0.5 time 0.53 heating 0.5 follow}
		}
		{delay 0.53 ; 42.5/80
			{call "to_end"}
		}
		{delay 0.40 ; 0.53*0.75
			{if not altitude 0.25
				{call "to_end"}
			}
		}
	}
}

{"flame_pointer_g" ; Mixed fuel portable flamethrower
	{on "specificity" overload
		{gravity 50}
		{delay 0.38 ; 30/80
			{delete}
		}
		{delay 0.29 ; 0.38*0.75
			{if not altitude 0.25
				{call "to_end"}
			}
		}
	}
	{on overlap begin overload
		{if effector "human"
			{with_effector}
			{if not tagged "burned"
				{call "hit-signal-fuel"}
			}
			{with_effector}
		}
	}
}
{"flame_piece_g" ; Mixed fuel portable flamethrower
	{on "specificity" overload
		{gravity 50} ; Heavier and has a curved trajectory
		{delay 0.02
			{fire radius 0.5 time 0.38 heating 0.5 follow} ; Not really dealing damage by this, but make soldiers evading flame.
		}
		{delay 0.38 ; 30/80
			{call "to_end"}
		}
		{delay 0.29 ; 0.38*0.75
			{if not altitude 0.25
				{call "to_end"}
			}
		}
	}
	{on "end_detonated" overload
		{spawn "flame_detonated" dir_velocity
			{tags add "40s"}
			{delay 40 ; 50s burning area
				{delete}
			}
		}
	}
}
{"flame_pointer_tank_g" ; Mixed fuel tank flamethrower
	{on "specificity" overload
		{gravity 50}
		{delay 0.5 ; 40/80
			{delete}
		}
		{delay 0.38 ; 0.5*0.75
			{if not altitude 0.25
				{call "to_end"}
			}
		}
	}
}
{"flame_piece_tank_g" ; Mixed fuel tank flamethrower
	{on "specificity" overload
		{gravity 50}
		{delay 0.02
			{fire radius 0.5 time 0.5 heating 0.5 follow}
		}
		{delay 0.5 ; 40/80
			{call "to_end"}
		}
		{delay 0.38 ; 0.5*0.75
			{if not altitude 0.25
				{call "to_end"}
			}
		}
	}
}

{"balloon"
	{on break_armor overload}
}

{"molotov_coctail"
	{on bullet_hit overload}
	{on pierce overload
		{call "detonate"}
	}
	{on blast overload
		{if min_energy 0.3
			{call "detonate"}
		}
	}
	{on "contact_detonate" overload
		{if effector "human"
			{call "detonate"}
		else
			{fire radius 0.5 time 3 heating 5 effector follow}
			{call "detonate"}
		}
	}
	{on "detonate" overload
		{if not "detonated"
			{set "detonated" 1}
			{if not under_water
				{if not altitude 1.0
					{spawn "flame_detonated_molotov"
						{tags add "40s"}
						{delay 40 ; 40s burning area
							{delete}
						}
					}
					{fire radius 2.0 time 0.5 heating 5}
					{fire radius 1.25 time 0.5 heating 10}
				else
					{fire radius 1.5 time 0.5 heating 5}
					{fire radius 0.75 time 0.5 heating 10}
				}
			}
			{stuff_detonate}
		}
	}
}

{"flame_detonated"
	{on spawn
		{use_local_light 1}
		{if not altitude 1.0
			{if altitude 0.2
   				{pillar_fall}
				{delay 0.25
					{gravity 0}
					{physics_work 0}
					{tags add "grounded"}
					{volumes "body" enable contact obstacle visible}
					{update_visibility_patch}
				}
			else altitude 0.1
   				{pillar_fall}
				{delay 0.15
					{gravity 0}
					{physics_work 0}
					{tags add "grounded"}
					{volumes "body" enable contact obstacle visible}
					{update_visibility_patch}
				}
			else
				{gravity 0}
				{physics_work 0}
				{tags add "grounded"}
				{volumes "body" enable contact obstacle visible}
				{update_visibility_patch}
			}
		else
			{delay 0.1
				{delete}
			}
		}
		{delay 0.01
			{call "add_fx"}
		}
		{delay 0.1
			{tags add "can_remove"}
		}
		{delay 0.2
			{call "burning_area"}
		}
		{delay 3.0
			{tags add "heavy_bruning"}
			{link_sound "burn" "fire/big/big"}
			{play_sound "burn" 1}
		}
		{delay 60
			{delete}
		}
	}
	{on "add_fx"
		{add_view "fire_flame_thrower" "flame" "root"}
		{add_view "fire_molot_groundm_light" "flame" "root"}
		{view start "flame"}
		{start_sound "weapon/shot/flame/fire"}
	}
	{on "burning_area"
		{if not tagged "heavy_bruning"
			{fire radius 0.5 time 0.2 heating 2 follow}
			{fire radius 1.5 time 0.2 heating 1 follow}
		else
			{fire radius 0.5 time 0.2 heating 20 follow}
			{fire radius 1.5 time 0.2 heating 10 follow}
		}
		{delay 0.2
			{call "burning_area"}
		}
	}
	{on contact
		{if effector "flame_detonated"
			{if tagged "can_remove"
				{delete}
			}
		}
	}
}
{"flame_detonated_molotov"
	{on "add_fx" overload
		{add_view "fire_molot_groundm" "flame" "root"}
		{add_view "fire_molot_groundm_light" "flame" "root"}
		{view start "flame"}
		{start_sound "weapon/shot/flame/fire"}
	}
	{on "burning_area" overload
		{if not tagged "heavy_bruning"
			{fire radius 0.75 time 0.2 heating 2 follow}
			{fire radius 1.75 time 0.2 heating 1 follow}
		else
			{fire radius 0.75 time 0.2 heating 20 follow}
			{fire radius 1.75 time 0.2 heating 10 follow}
		}
		{delay 0.2
			{call "burning_area"}
		}
	}
}