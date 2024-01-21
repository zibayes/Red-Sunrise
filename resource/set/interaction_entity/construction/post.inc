{"post"
	{inflammation_time 4}
	{on break_armor
		{if volume "body"
			{call "break"}
		}
	}
	{on contact 
		{if can_crush
			{call "break"}
		}
	}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on "break"
   		{volumes "body" disable contact blast}
		{volumes "body1" disable contact blast}
		{volumes "body2" disable contact blast}
		{volumes "body3" disable contact blast}
		{volumes "body4" disable contact blast}
		{volumes "body5" disable contact blast}
		{volumes "body6" disable contact blast}
		{volumes "body7" disable contact blast}
		{volumes "body8" disable contact blast}
		{volumes "body9" disable contact blast}
		{volumes "body10" disable contact blast}
		{volumes "streetlight1" disable contact blast}
		{volumes "streetlight2" disable contact blast}
		{volumes "streetlight3" disable contact blast}
		
		{volumes "box00" disable contact blast}
		{volumes "box01" disable contact blast}
		{volumes "box02" disable contact blast}
		{volumes "box03" disable contact blast}
		{volumes "box04" disable contact blast}
		{volumes "box05" disable contact blast}
		{volumes "lamp_glass02" disable contact blast}
		{volumes "lamp_glass1" disable contact blast}
		{volumes "lamp1" disable contact blast}
		{volumes "lamp2" disable contact blast}
		
		{delay 1 {volumes "column1" disable contact blast}}
		{delay 1 {volumes "column2" disable contact blast}}
		{delay 1 {volumes "plank1" disable contact blast}}
		{delay 1 {volumes "plank2" disable contact blast}}
		{delay 1 {volumes "ferm" disable contact blast}}
		
		{call "light_break"}
		{if not fallen
			{pillar_fall}
		}
	}
	{on "light_break"} ; handled in extender
}

{"post wood"
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8
					{call "break"}
				}
			}
		}
	}
}

{"post concrete"
	{inflammation_time 10000}
}

{"post steel"
	{inflammation_time 10000}
}

{"disable_area post"
	{on "break"
		{area disable}
		{volumes disable obstacle}
	}
}

{"ring_post"
	{on "ring"
		{delay 0.5
			{ani_play "gong"}
			{start_sound "push/ring"}
			{tags add "gong"}
		}
	}
}
