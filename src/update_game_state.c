/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 06:12:16 by home              #+#    #+#             */
/*   Updated: 2020/06/10 20:32:59 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	move_player(t_game_context *game_state)
{
	t_player	*player;
	int			x;
	int			y;

	player = &(game_state->player);
	x = player->loc_x;
	y = player->loc_y;
	if (player->direction == UP && game_state->map[y - 1][x] != 'W')
		player->loc_y--;
	else if (player->direction == DOWN && game_state->map[y + 1][x] != 'W')
		player->loc_y++;
	else if (player->direction == LEFT && game_state->map[y][x - 1] != 'W')
		player->loc_x--;
	else if (player->direction == RIGHT && game_state->map[y][x + 1] != 'W')
		player->loc_x++;
	else
	{
		player->direction = player->prev_dir;
		if (player->direction == UP && game_state->map[y - 1][x] != 'W')
			player->loc_y--;
		else if (player->direction == DOWN && game_state->map[y + 1][x] != 'W')
			player->loc_y++;
		else if (player->direction == LEFT && game_state->map[y][x - 1] != 'W')
			player->loc_x--;
		else if (player->direction == RIGHT && game_state->map[y][x + 1] != 'W')
			player->loc_x++;
	}

	player->loc_x += (GAME_COLS - 1);
	player->loc_x %= (GAME_COLS - 1);
}

void	update_blinky(t_game_context *game_state)
{
	game_state->blinky.target_loc_x = game_state->player.loc_x;
	game_state->blinky.target_loc_y = game_state->player.loc_y;

	common_ghost_update(game_state, &(game_state->blinky));
}


void	update_pinky(t_game_context *game_state)
{
	game_state->pinky.target_loc_x = game_state->player.loc_x;
	game_state->pinky.target_loc_y = game_state->player.loc_y;

	if (game_state->player.direction == UP)
	{
		game_state->pinky.target_loc_x = game_state->player.loc_x - 4;
		game_state->pinky.target_loc_y = game_state->player.loc_y - 4;
	}
	else if (game_state->player.direction == DOWN)
		game_state->pinky.target_loc_y = game_state->player.loc_y  + 4;
	else if (game_state->player.direction == LEFT)
		game_state->pinky.target_loc_x = game_state->player.loc_x - 4;
	else if (game_state->player.direction == RIGHT)
		game_state->pinky.target_loc_x = game_state->player.loc_x + 4;

	common_ghost_update(game_state, &(game_state->pinky));
}

void	update_inky(t_game_context *game_state)
{
	int	m_x;
	int	m_y;

	int	d_x;
	int	d_y;

	m_x = game_state->player.loc_x;
	m_y = game_state->player.loc_y;

	if (game_state->player.direction == UP)
	{
		m_x = game_state->player.loc_x - 2;
		m_y = game_state->player.loc_y - 2;
	}
	else if (game_state->player.direction == DOWN)
		m_y = game_state->player.loc_y  + 2;
	else if (game_state->player.direction == LEFT)
		m_x = game_state->player.loc_x - 2;
	else if (game_state->player.direction == RIGHT)
		m_x = game_state->player.loc_x + 2;

	d_x = game_state->blinky.loc_x - m_x;
	d_y = game_state->blinky.loc_y - m_y;

	game_state->inky.target_loc_x = m_x - d_x;
	game_state->inky.target_loc_y = m_y - d_y;

	common_ghost_update(game_state, &(game_state->inky));
}

void	update_clyde(t_game_context *game_state)
{
	int	dis_to_pacman;
	int	x;
	int	y;
	int	p_x;
	int	p_y;

	x = game_state->clyde.loc_x;
	y = game_state->clyde.loc_y;
	p_x = game_state->player.loc_x;
	p_y = game_state->player.loc_y;
	dis_to_pacman = (p_x - x) * (p_x - x) + (p_y - y) * (p_y - y);
	if (dis_to_pacman > 64)
	{
		game_state->clyde.target_loc_x = game_state->player.loc_x;
		game_state->clyde.target_loc_y = game_state->player.loc_y;
	}
	else
	{
		game_state->clyde.target_loc_x = game_state->clyde.scatter_loc_x;
		game_state->clyde.target_loc_y = game_state->clyde.scatter_loc_y;
	}

	common_ghost_update(game_state, &(game_state->clyde));
}

void	update_game_state(t_game_context *game_state)
{

	if (game_state->map[game_state->player.loc_y][game_state->player.loc_x] == '.')
	{
		game_state->map[game_state->player.loc_y][game_state->player.loc_x] = ' ';
		game_state->score++;
	}
	if (game_state->map[game_state->player.loc_y][game_state->player.loc_x] == 'P')
	{
		game_state->map[game_state->player.loc_y][game_state->player.loc_x] = ' ';
		game_state->score++;
		game_state->blinky.mode = FRIGHTEN;
		game_state->pinky.mode = FRIGHTEN;
		game_state->inky.mode = FRIGHTEN;
		game_state->clyde.mode = FRIGHTEN;
		game_state->fright_ticks = FRIGHT_DURATION;
	}

	move_player(game_state);

	update_blinky(game_state);
	update_pinky(game_state);
	update_inky(game_state);
	update_clyde(game_state);

	if (game_state->game_tick % 6 != 0)
	{
		move_ghost(game_state, &(game_state->blinky));
		move_ghost(game_state, &(game_state->pinky));
		move_ghost(game_state, &(game_state->inky));
		move_ghost(game_state, &(game_state->clyde));
	}

	double_buffer_update(game_state, &(game_state->blinky));
	double_buffer_update(game_state, &(game_state->pinky));
	double_buffer_update(game_state, &(game_state->inky));
	double_buffer_update(game_state, &(game_state->clyde));

	if (game_state->fright_ticks > 0)
		game_state->fright_ticks--;

	printf("SCORE: %d\n", game_state->score);
}
