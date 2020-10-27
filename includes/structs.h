/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2020/08/28 03:06:31 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct	s_display
{
	int				width;
	int				height;
	int				size;

	SDL_Window		*window;
	unsigned char	*pixels;
}				t_display;

#define GAME_COLS 29
#define GAME_ROWS 31

typedef char t_map[GAME_ROWS][GAME_COLS];

typedef enum	e_direction
{
	UP		= 0b00001,
	DOWN	= 0b00010,
	LEFT	= 0b00100,
	RIGHT	= 0b01000,
	NONE	= 0b10000, //Also stationary
}				t_dir;

typedef struct	s_player
{
	int			loc_x;
	int			loc_y;

	t_dir		prev_dir;
	t_dir		direction;
}				t_player;

typedef enum	e_ghost_state
{
	SCATTER		= 0b000001,
	CHASE		= 0b000010,
	FRIGHTEN	= 0b000100,
	EATEN		= 0b001000,
	FREEZE		= 0b010000,
	TURN_STUN	= 0b100000,
}				t_ghostmode;

typedef struct	s_ghost
{
	int			color;
	int			b_color;
	t_ghostmode	mode;

	t_dir		from;

	int			scatter_loc_x;
	int			scatter_loc_y;

	int			loc_x;
	int			loc_y;

	int			target_loc_x;
	int			target_loc_y;
}				t_ghost;

#define FRIGHT_DURATION 120
#define FREEZE_DURATION 75

typedef struct	s_game_context
{
	t_map		map;

	t_player	player;

	t_ghost		blinky;
	t_ghost		pinky;
	t_ghost		inky;
	t_ghost		clyde;

	int			lives;
	int			score;
	int			eaten;
	int			freeze;

	int			game_tick;
	int			fright_ticks;
	int			freeze_ticks;
	bool		active;
}				t_game_context;

#endif
