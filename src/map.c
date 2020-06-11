/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 08:31:33 by home              #+#    #+#             */
/*   Updated: 2020/06/08 07:22:25 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	fill_map(t_map *map_dest)
{
	memcpy((*map_dest)[ 0], "WWWWWWWWWWWWWWWWWWWWWWWWWWWW", GAME_COLS);
	memcpy((*map_dest)[ 1], "W............WW............W", GAME_COLS);
	memcpy((*map_dest)[ 2], "W.WWWW.WWWWW.WW.WWWWW.WWWW.W", GAME_COLS);
	memcpy((*map_dest)[ 3], "WPWWWW.WWWWW.WW.WWWWW.WWWWPW", GAME_COLS);
	memcpy((*map_dest)[ 4], "W.WWWW.WWWWW.WW.WWWWW.WWWW.W", GAME_COLS);
	memcpy((*map_dest)[ 5], "W..........................W", GAME_COLS);
	memcpy((*map_dest)[ 6], "W.WWWW.WW.WWWWWWWW.WW.WWWW.W", GAME_COLS);
	memcpy((*map_dest)[ 7], "W.WWWW.WW.WWWWWWWW.WW.WWWW.W", GAME_COLS);
	memcpy((*map_dest)[ 8], "W......WW....WW....WW......W", GAME_COLS);
	memcpy((*map_dest)[ 9], "WWWWWW.WWWWW.WW.WWWWW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[10], "WWWWWW.WWWWW.WW.WWWWW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[11], "WWWWWW.WW          WW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[12], "WWWWWW.WW WWWWWWWW WW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[13], "WWWWWW.WW W      W WW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[14], "      .   W      W   .      ", GAME_COLS);
	memcpy((*map_dest)[15], "WWWWWW.WW W      W WW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[16], "WWWWWW.WW WWWWWWWW WW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[17], "WWWWWW.WW          WW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[18], "WWWWWW.WW.WWWWWWWW.WW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[19], "WWWWWW.WW.WWWWWWWW.WW.WWWWWW", GAME_COLS);
	memcpy((*map_dest)[20], "W............WW............W", GAME_COLS);
	memcpy((*map_dest)[21], "W.WWWW.WWWWW.WW.WWWWW.WWWW.W", GAME_COLS);
	memcpy((*map_dest)[22], "W.WWWW.WWWWW.WW.WWWWW.WWWW.W", GAME_COLS);
	memcpy((*map_dest)[23], "WP..WW.......  .......WW..PW", GAME_COLS);
	memcpy((*map_dest)[24], "WWW.WW.WW.WWWWWWWW.WW.WW.WWW", GAME_COLS);
	memcpy((*map_dest)[25], "WWW.WW.WW.WWWWWWWW.WW.WW.WWW", GAME_COLS);
	memcpy((*map_dest)[26], "W......WW....WW....WW......W", GAME_COLS);
	memcpy((*map_dest)[27], "W.WWWWWWWWWW.WW.WWWWWWWWWW.W", GAME_COLS);
	memcpy((*map_dest)[28], "W.WWWWWWWWWW.WW.WWWWWWWWWW.W", GAME_COLS);
	memcpy((*map_dest)[29], "W..........................W", GAME_COLS);
	memcpy((*map_dest)[30], "WWWWWWWWWWWWWWWWWWWWWWWWWWWW", GAME_COLS);
}
