{"barrel_fuel"
	{on "effects" overload
		{spawn "shockwave_sphere" "fx_expfuel"}
		{add_view "exhaust_dark_big" "burn_fire" "fxfire"}
		{view start "burn_fire"}
		{spawn "crater_extra_big" "basis" terrain_texmod}
		{spawn "shellhole_big_dead" "basis"}
		{blastwave c4 15 r0 6 r1 20}
		{fire radius 15 time 5 heating 50}
	}
}
{"barrel_small"
	{on "effects" overload
		{spawn "shockwave_sphere" "fx_expfuel"}
		{blastwave c4 7 r0 3 r1 12}
		{fire radius 10 time 5 heating 30}
	}
}
{"fuel_scaled"
	{on "effects" overload
		{blastwave c4 7 r0 5 r1 15}
		{fire radius 12 time 5 heating 30}
	}
}

{"explosive_barrel"
	{on spawn
		{delay 0.1
			{tags add "enable_contact"}
		}
	}
	{on break_armor overload
		{if name "pierce"
			{if stuff "bullet"
				{if stuff_filled "liquid" 20
					{burn fx "drops_water_small_short" fake}
				}
			else stuff "shell"
				{call "break"}
			}
		}
	}
	{on "burn" overload
		{if stuff_filled "fuel" 20
			{call "explosion"}
		}
	}
	{on blast_hit
		{if min_energy 1.75
			{call "break"}
		}
	}
}

(define "flame_pass_fence"
	{%0
		{on spawn
			{delay 0.01
				{volumes enable holed hole}
			}
		}
	}
)
("flame_pass_fence" args "fence_wood01")
("flame_pass_fence" args "fence-wood4a")
("flame_pass_fence" args "fence-wood4b")
("flame_pass_fence" args "fence-wood_3")
("flame_pass_fence" args "fence-wood_3a")
("flame_pass_fence" args "fence-wood_3b")
("flame_pass_fence" args "fence_decor1a")
("flame_pass_fence" args "fence_decor1b")
("flame_pass_fence" args "fence_port2")
("flame_pass_fence" args "fence_vine")
("flame_pass_fence" args "fence_wire")
("flame_pass_fence" args "fence_wire1")
("flame_pass_fence" args "fence_wire10")
("flame_pass_fence" args "fence_wire1_broken")
("flame_pass_fence" args "fence_wire3")
("flame_pass_fence" args "fence_wire4")
("flame_pass_fence" args "fence_wire5")
("flame_pass_fence" args "fence_wire6")
("flame_pass_fence" args "fence_wire8")
("flame_pass_fence" args "fence_wire9")
("flame_pass_fence" args "fence_wood_r10")
("flame_pass_fence" args "fence_wood_r11")
("flame_pass_fence" args "fence_wood_r5")
("flame_pass_fence" args "fence_wood_r6")
("flame_pass_fence" args "fence_wood_r9")
("flame_pass_fence" args "fence_woodr6")
("flame_pass_fence" args "gate_wire")
("flame_pass_fence" args "gate_wood1")
("flame_pass_fence" args "ironfence3n")
("flame_pass_fence" args "ironfence_4m")
("flame_pass_fence" args "ironfence_4n")
("flame_pass_fence" args "ironfence_n")
("flame_pass_fence" args "picket_cross1")
("flame_pass_fence" args "picket_cross2")
("flame_pass_fence" args "picket_fence_1")
("flame_pass_fence" args "picket_cross3")
("flame_pass_fence" args "picket_fence_2")
("flame_pass_fence" args "picket_fence_3")
("flame_pass_fence" args "picket_fence_4")
("flame_pass_fence" args "picket_fence_gate")
("flame_pass_fence" args "rock_metal_gate")
("flame_pass_fence" args "barbed_wire")
("flame_pass_fence" args "barbed_wire_crashed")
("flame_pass_fence" args "wires_11_post")
("flame_pass_fence" args "wires_3m_human")
("flame_pass_fence" args "wires_post_x")
("flame_pass_fence" args "wire_left")
("flame_pass_fence" args "wire_left_br")
("flame_pass_fence" args "wire_right")
("flame_pass_fence" args "wire_right_br")
("flame_pass_fence" args "wire_left_a")
("flame_pass_fence" args "wire_left_br_a")
("flame_pass_fence" args "wire_right_a")
("flame_pass_fence" args "wire_right_br_a")
("flame_pass_fence" args "wire_left_b")
("flame_pass_fence" args "wire_right_b")
("flame_pass_fence" args "wire_broken")
("flame_pass_fence" args "wire_trash")
("flame_pass_fence" args "wire_whole")
("flame_pass_fence" args "wires_x")