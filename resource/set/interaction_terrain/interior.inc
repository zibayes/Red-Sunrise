;SDL
{"interior"
  {on hit
    {if effector "wind"				
        {spawn "heli_dust_ground"}			
      else				
    {if min_mass 100
      {if effector "tree"
        {spawn "tree_crush"}
      else
        {spawn "spheredust_small"}
      }
    else min_mass 10
      {spawn "spheredust_small_short"}
    }}
  }
  {on detonate
    {if stuff "molotov_coctail"
      {spawn "ex_molot"}
      {spawn "fire_molot_ground"}
      {spawn "fire_shellhole"}
	else stuff "con_block"
		{spawn "exp_concrete_block"}
	;/Gas
    else stuff "gas"
		{spawn "gas"}
	;
    else stuff "big smoke"
	{spawn "ex_arm_big"}
	{spawn "smoke_shell"}
    else stuff "dynamite"
      {spawn "ex_bomb_big"}
      {spawn "shellhole_big"}
    else stuff "grenade_flash"
      {spawn "ex_flashbang"}
	  {spawn "fire_shellhole"}
    else stuff "grenade big"
      {spawn "ex_grenade_big"}
      {spawn "grenade_at_shellhole" terrain_texmod}
    else stuff "uber_bazooka"
      {spawn "ex_fg_minimum"}
    else stuff "grenade"
      {spawn "ex_grenade_sm_interior"}
	  {spawn "fire_shellhole"}
	else stuff "grenadelauncher"
      {spawn "ex_grenade_sm"}
      {spawn "fire_shellhole"}
    else stuff "m79 fg"
      {spawn "ex_grenade_sm"}
      {spawn "fire_shellhole"}
    else stuff "small bullet"
      {spawn "ex_bul_sm"}
    else stuff "zenite"
      {spawn "ex_bul_zenit"}
      {spawn "shellhole_small"}
    else stuff "bullet"
      {spawn "ex_bul_big"}
    else stuff "mortar"
      {spawn "ex_mort_big"}
      {spawn "shellhole_big"}
    else stuff "shell size_minimum fg"
      {spawn "ex_fg_minimum"}
      {spawn "grenade_shellhole" terrain_texmod}
    else stuff "shell size_minimum"
      {spawn "ex_ap_minimum"}
	  {spawn "shellhole_small"}
    else stuff "shell size_small fg"
      {spawn "ex_fg_small"}
      {spawn "crater_norm" terrain_texmod}
    else stuff "shell size_small"
      {spawn "ex_ap_small"}
	  {spawn "shellhole_small"}
    else stuff "shell size_medium fg"
      {spawn "ex_fg_medium"}
      {spawn "crater_norm" terrain_texmod}
    else stuff "shell size_medium"
      {spawn "ex_ap_medium"}
	  {spawn "shellhole_medium"}
    else stuff "shell size_big fg"
      {spawn "ex_fg_big"}
      {spawn "crater_norm" terrain_texmod}
    else stuff "shell size_big m830a1"
      {spawn "ex_fg_medium"}
	  {spawn "shellhole_small"} 
    else stuff "shell size_big"
      {spawn "ex_ap_medium"}
	  {spawn "shellhole_medium"}
    else stuff "shell size_maximum"
      {spawn "ex_fg_maximum"}
      {spawn "crater_big" terrain_texmod}
    else stuff "nuclear_shell"
      {spawn "expluto"}
      {spawn "crater_big" terrain_texmod}		  
    else stuff "ap shell"
      {spawn "ex_grenade_sm"}
    else stuff "big shell extra"
      {spawn "ex_bomb_big" offset 0 0 20}
      {spawn "crater_norm" terrain_texmod}
    else stuff "big shell extra305"
      {spawn "ex_cannon400" offset 0 0 20}
      {spawn "crater_big" terrain_texmod}
    else stuff "big shell fg bomb no_crater small"
      {spawn "shockwave"}
      {spawn "ex_anti_big"}
      {spawn "shellhole4d3"}
    else stuff "big shell fg bomb no_crater"
      {spawn "ex_bomb_big"}
      {spawn "shellhole4d2"}
    else stuff "big shell fg bomb"
      {spawn "ex_bomb_big"}
      {spawn "crater_norm" terrain_texmod} 
    else stuff "mine antipersonnel"
      {spawn "ex_grenade_big"}
      {spawn "shellhole_medium"}
    else stuff "mine claymore"
      {spawn "ex_grenade_big"}
      {spawn "shellhole_medium"}
    else stuff "mine antitank"
	  {spawn "ex_arm_big"}
      {spawn "shellhole_big"}
	else stuff "mine clockwork"
	  {spawn "ex_anti_big"}
	  {spawn "shellhole_big"}
    else stuff "dynamite_clockwork"
      {spawn "ex_bomb_big"}
      {spawn "shellhole_big"}
    else stuff "tnt_bag"
      {spawn "ex_bomb_big"}
      {spawn "shellhole_big"}
    else stuff "flaerammo"
	  {spawn "artillery_explosion_flaer"}
    else stuff "wind"
      {spawn "heli_dust_ground"}
	else stuff "rocket_mine"
	  {spawn "pom_2_5_dropper"}
      {spawn "ex_grenade_sm"}
      {spawn "grenade_shellhole"}
    else stuff "kaset"
      {spawn "ex_kaset"}
      {spawn "grenade_shellhole" terrain_texmod}
    else stuff "thermal"
      {spawn "train_die"}
      {spawn "grenade_shellhole" terrain_texmod}
	}	
  }
}
