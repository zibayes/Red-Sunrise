{"car"
	{on "mp_destroy"
		{if not tagged "destroyed"
			{damage_report "body" "component/body_broken"}
			{if not tagged "body_break"
				{components "body" break}
				{call "stat_break"}
			}
		}

		{delay 2
			{tags add "destroyed"}
			{kick_entity_manager}
		}

		{call "check_burn_emit"}
		{delay 2.3
			{view start "smoke4_1"}
		}
		{delay 30
  			{view stop "smoke4_1"}
  		}

		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
	}
	{on "pierce_fuel" overload
		{if rand 0.5
			{volumes "fuel" disable bullet contact blast}
			{spawn "tank_die_particle"}
			{call "_burn"}
		}
	}
	{on "burn" overload ; disable instant burning damage
		; do nothing
	}
}
{"fuel_tank"
	{on "_explosion" overload
		{call "break_all"}
		{stop_sound "move"}
		{stop_sound "move_end"}
		{stop_sound "engine"}
		{stop_sound "engine_end"}
		{stop_sound "exhaust"}
		{view stop "fire1"}
		{view stop "fire2"}
		{tags add "destroyed"}
		{kick_entity_manager}
		{call "explosion_sound"}

		{if not terrain_fx "bridge"
			{if not under_water
				{call "spawn_shellhole"}
			}
		}

		{delay_ex 0
			{set "no_burn_volumes" 1}
			{set_skeleton "_xx" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}

		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{if not "crush"
			{spawn "tank_die" "Basis"}
			{spawn "tank_die_particle"}
			{impulse up 2.5 1.5 dir 2 1}
		}
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 8 time 10 heating 50}
	}
	{on "burn_volume"
		{if tagged "ignited"
			{if volume "bodyback"
				{burn volume fx "smoke_dead_small" time 12 fake even_law}
				{call "_burn"}
			}
		}
	}
	{on "_burn" overload
        {delay 1
            {crew_emit}
        }
        {delay 2
            {crew_emit}
        }
        {delay 3
            {crew_emit}
        }
        {if not tagged "burned"
			{if not able "exploded"
				{damage_report "engine" "component/burn_engine"}
            	{add_view		"smoke_dead_norm"	"burn_fire"		"bodyback"}
            	{add_view		"smoke_dead_norm"	"burn_fire"		"FXfire1"}
				{view start "burn_fire"}
				{burn time 12}
				{tags add "burned"}
            	{add_view		"smoke_black"	"burn_fire"		"bodyback"}
				{add_view "smoke_black" "burn_fire" "FXfire1"}
				{play_sound "flame" 1}
				{view start "burn_fire"}
				{set "burn_fire" 1}
                {call "stat_break"}
				{delay 4 2
                	{call "check_burn_emit"}
                }
				{delay 10 2
						{call "mp_destroy"}
						{start_sound "crush/medium/metal"}
				}
				{delay 10 2
					{components "engine" break}
					{start_sound "crush/medium/metal"}
                    	{delay 5 4
						{call "mp_destroy"}
					}
				}
				{delay 12
					{explosive 0}
					{view stop "burn_fire"}
					{stop_sound "flame"}
					{set "burn_fire" 0}
					{call "check_burn_emit"}
					{if rand 0.9
						{call "explosion"}
					else
						{able "burning" 0}
					}
				}
			}
    	}
	}
}
{"moto"
	{on "burn" overload ; disable instant burning damage
		; do nothing
	}
}