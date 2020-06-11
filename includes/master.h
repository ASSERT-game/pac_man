/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2020/06/10 20:19:57 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

#include <stdio.h>
#include <strings.h>
#include <unistd.h>

#include "structs.h"
#include "window_config.h"

void		SDLU_start(t_display *dest);

void		fill_map(t_map *map_dest);
void		fill_ghost(t_ghost *ghost, int color, int x, int y, int s_x, int s_y);

void		draw_wall_tile(unsigned char *pixel_array, int x, int y);
void		draw_pacman_tile(unsigned char *pixel_array, int x, int y);
void		draw_ghost_tile(unsigned char *pixel_array, int x, int y, int color);
void		draw_target(unsigned char *pixel_array, int x, int y, int color);

void		draw_map(t_map map, unsigned char *pixel_array);

void		color_in(unsigned char *pixel_array, int color, int x, int y);
void		clear_screen(unsigned char *pixel_array);

void		process_user_input(t_game_context *game_state);
void		update_game_state(t_game_context *game_state);

void		move_ghost(t_game_context *game_state, t_ghost *ghost);
void		common_ghost_update(t_game_context *game_state, t_ghost *ghost);
void		double_buffer_update(t_game_context *game_state, t_ghost *ghost);

#endif
