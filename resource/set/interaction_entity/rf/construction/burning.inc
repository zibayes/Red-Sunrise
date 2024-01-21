{"straw construction"
	{inflammation_time 15}
	{on contact
		{if effector "flame_pointer"
			{burn volume fx "smoke_dead_small" time 6 1 fake even_law}
		else effector "molotov_coctail"
			{burn volume fx "smoke_dead_small" time 6 1 fake even_law}
		}
	}
}
{"wood construction"
	{inflammation_time 50}
	{on contact
		{if effector "flame_pointer"
			{burn volume fx "smoke_dead_small" time 6 1 fake even_law}
		else effector "molotov_coctail"
			{burn volume fx "smoke_dead_small" time 6 1 fake even_law}
		}
	}
}
{"concrete construction"
	{inflammation_time 100}
	{on contact
		{if effector "flame_pointer"
			{burn volume fx "smoke_dead_small" time 3 1 fake even_law}
		else effector "molotov_coctail"
			{burn volume fx "smoke_dead_small" time 6 1 fake even_law}
		}
	}
}
{"burning_old construction"
	(define "burn_volume_rf"
		{delay %1 0.7
			{if not "stop_burn"
				{burn volume "fire%0" fx "smoke_fire_window" time 30 fake even_law}
				{fire volume "fire%0" radius 2 time 30 heating 30}
				{burn volume "smoke%0" fx "smoke_black_window" time 30 fake even_law}
				{fire volume "smoke%0" radius 2 time 30 heating 30}
			}
		}
	)
	(define "burn_from_volume_rf"
		{if not burned
			{if volume %0
				("burn_volume_rf" args %1 %2)
				("burn_volume_rf" args %3 %4)
				("burn_volume_rf" args %5 %6)
				("burn_volume_rf" args %7 %8)
				("burn_volume_rf" args %9 %10)
				("burn_volume_rf" args %11 %12)
				("burn_volume_rf" args %13 %14)
				("burn_volume_rf" args %15 %16)
				("burn_volume_rf" args %17 %18)
				{burn time 30}
				{delay 20 3
					{call "next_stage"}
	 				{call "burn_end"}
				}
			}
		}
	)
	{on "burn_process" overload
		{if not "last_stage"
			("burn_from_volume_rf" args "fire0"	0 2		1 4		2 8		3 12	4 16	5 18	6 16	7 12	8 8		9 4)
			("burn_from_volume_rf" args "fire1"	1 2		2 4		3 8		4 12	5 16	6 18	7 16	8 12	9 8		0 4)
			("burn_from_volume_rf" args "fire2"	2 2		3 4		4 8		5 12	6 16	7 18	8 16	9 12	0 8		1 4)
			("burn_from_volume_rf" args "fire3"	3 2		4 4		5 8		6 12	7 16	8 18	9 16	0 12	1 8		2 4)
			("burn_from_volume_rf" args "fire4"	4 2		5 4		6 8		7 12	8 16	9 18	0 16	1 12	2 8		3 4)
			("burn_from_volume_rf" args "fire5"	5 2		6 4		7 8		8 12	9 16	0 18	1 16	2 12	3 8		4 4)
			("burn_from_volume_rf" args "fire6"	6 2		7 4		8 8		9 12	0 16	1 18	2 16	3 12	4 8		5 4)
			("burn_from_volume_rf" args "fire7"	7 2		8 4		9 8		0 12	1 16	2 18	3 16	4 12	5 8		6 4)
			("burn_from_volume_rf" args "fire8"	8 2		9 4		0 8		1 12	2 16	3 18	4 16	5 12	6 8		7 4)
			("burn_from_volume_rf" args "fire9"	9 2		0 4		1 8		2 12	3 16	4 18	5 16	6 12	7 8		8 4)
			("burn_from_volume_rf" args "body"		1 2		2 4		3 8		4 12	5 16	6 18	7 16	8 12	9 8		0 4)
			("burn_from_volume_rf" args "body1"	2 2		3 4		4 8		5 12	6 16	7 18	8 16	9 12	0 8		1 4)
		}
	}
	{on "burn_body" overload
		{if volume "fire"
			{if not burned
				{if not "last_stage"
					{burn volume fx "smoke_dead_tree1" time 30 2 fake even_law}
					{fire radius 2 time 30 heating 30}
					{burn time 30 2}
					{delay 20
						{call "next_stage"}
		 				{call "burn_end"}
					}
				}
			}
		else
			{call "burn_process"}
		}
	}
}
{"burning construction"
	(define "burn_volume_fx_rf"
		{burn volume fx %0 time 30 fake even_law}
		{fire radius 2 time 30 heating 30}
	)
	(define "burn_bone_fx_rf"
		{burn fx %0 time 30 fake even_law}
		{fire radius 2 time 30 heating 30}
	)
	{on "burn_volume_next" overload
		{if volume "window"
			{if volume "fire"
				("burn_bone_fx_rf" args "smoke_fire_window")
			else volume "smoke"
				("burn_bone_fx_rf" args "smoke_black_window")
			}
		else
			{if volume "fire"
				("burn_volume_fx_rf" args "smoke_fire_window")
			else volume "smoke"
				("burn_volume_fx_rf" args "smoke_fire_window")
			}
		}
	}
}