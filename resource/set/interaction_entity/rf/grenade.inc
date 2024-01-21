{"grenade"
	{on "onThrow" overload
		{volumes "body" disable contact overlap}
		{delay 0.1
			{tags add "fused"}
			{volumes "body" enable contact overlap}
		}
	}
	{on "onThrowActivate" overload}
	{on contact overload}
	{on "in_hole" overload}
	{on "fall_down" overload}
}
{"grenade contact"
	{on ground_hit overload
		{if tagged "fused"
			{if not name "water"
				{call "ground_detonate"}
			}
		}
	}
	{on "in_hole" overload}
	{on contact overload
		{if tagged "fused"
			{call "contact_detonate"}
		}
	}
	{on overlap begin overload
		{if not effector "vehicle"
			{if tagged "fused"
				{call "contact_detonate"}
			}
		}
	}
	{on "detonate" overload
		{if not "detonated"
			{set "detonated" 1}
			{stuff_detonate}
		}
	}
}