/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/03/31 18:46:19 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_context *game_state)
{
	fill_map(&(game_state->map));

	game_state->player.loc_x = 14;
	game_state->player.loc_y = 23;
	game_state->player.prev_dir = NONE;
	game_state->player.direction = NONE;

	fill_ghost(&(game_state->blinky), 0xFF0000, 11, 11, 25, -3);
	fill_ghost(&(game_state->pinky),  0xFF33AA, 14, 11,  2, -3);
	fill_ghost(&(game_state->inky),   0x00AAFF, 12, 11, 27, 32);
	fill_ghost(&(game_state->clyde),  0xEE7777, 16, 11,  0, 32);

	game_state->lives = 5;
	game_state->score = 0;
	game_state->eaten = 0;
	game_state->freeze = 1;

	game_state->game_tick = 0;
	game_state->fright_ticks = 0;
	game_state->freeze_ticks = 0;
	game_state->active = true;

	srand(time(NULL));
}

int	main(void)
{
	t_display		display;
	t_game_context	game_state;

	SDLU_start(&display);
	game_context_initialize(&game_state);
	while (game_state.active == true)
	{
		process_user_input(&game_state);

		update_game_state(&game_state);

		draw_map(game_state.map, display.pixels);

		draw_pacman_tile(display.pixels, game_state.player.loc_x, game_state.player.loc_y + 3);
		draw_lives(display.pixels, game_state.lives);
		draw_freeze(display.pixels, game_state.freeze);

		draw_ghost_tile(display.pixels, game_state.blinky.loc_x, game_state.blinky.loc_y + 3, game_state.blinky.color);
		draw_ghost_tile(display.pixels, game_state.pinky.loc_x,  game_state.pinky.loc_y + 3,  game_state.pinky.color);
		draw_ghost_tile(display.pixels, game_state.clyde.loc_x,  game_state.clyde.loc_y + 3,  game_state.clyde.color);
		draw_ghost_tile(display.pixels, game_state.inky.loc_x,   game_state.inky.loc_y + 3,   game_state.inky.color);

		draw_target(display.pixels, game_state.blinky.target_loc_x, game_state.blinky.target_loc_y + 3, game_state.blinky.color);
		draw_target(display.pixels, game_state.pinky.target_loc_x,  game_state.pinky.target_loc_y + 3,  game_state.pinky.color);
		draw_target(display.pixels, game_state.inky.target_loc_x,   game_state.inky.target_loc_y + 3,   game_state.inky.color);
		draw_target(display.pixels, game_state.clyde.target_loc_x,  game_state.clyde.target_loc_y + 3,  game_state.clyde.color);

		SDL_UpdateWindowSurface(display.window);
		clear_screen(display.pixels);
		game_state.game_tick++;
		usleep(GAME_TICK);
	}
	SDLU_close(&display);
	printf("Thank you for playing\n");
	return (0);
}
