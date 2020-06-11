/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 11:30:10 by home              #+#    #+#             */
/*   Updated: 2020/06/09 19:24:43 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	process_user_input(t_game_context *game_state)
{
	SDL_Event		e;
	const Uint8		*keystate;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			game_state->active = false;
	}
	keystate = SDL_GetKeyboardState(NULL);

	game_state->player.prev_dir = game_state->player.direction;

	if (keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP])
		game_state->player.direction = UP;
	if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN])
		game_state->player.direction = DOWN;
	if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT])
		game_state->player.direction = LEFT;
	if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT])
		game_state->player.direction = RIGHT;
}
