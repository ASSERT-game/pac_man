/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:05:36 by home              #+#    #+#             */
/*   Updated: 2020/06/10 20:03:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	fill_ghost(t_ghost *ghost, int color, int x, int y)
{
	ghost->b_color = color;
	ghost->loc_x = x;
	ghost->loc_y = y;

	ghost->from = NONE;
	ghost->mode = CHASE;
}

void	common_ghost_update(t_game_context *game_state, t_ghost *ghost)
{
	ghost->color = ghost->b_color;
	if (ghost->mode == FRIGHTEN)
	{
		ghost->color = 0x0000FF;
		if (ghost->loc_x == game_state->player.loc_x && ghost->loc_y == game_state->player.loc_y)
			ghost->mode = EATEN;
		if (game_state->fright_ticks == 0)
			ghost->mode = CHASE;
		if (game_state->fright_ticks < 21 && game_state->fright_ticks % 2 == 0)
				ghost->color ^= (0xDDDDDD ^ 0x0000FF);
	}
	if (ghost->mode == EATEN)
	{
		ghost->color = 0x444444;
		ghost->target_loc_x = 11;
		ghost->target_loc_y = 11;
		if (ghost->loc_x == 11 && ghost->loc_y == 11)
			ghost->mode = CHASE;
	}
}

void	double_buffer_update(t_game_context *game_state, t_ghost *ghost)
{
	if (ghost->loc_x == game_state->player.loc_x &&
		ghost->loc_y == game_state->player.loc_y &&
		ghost->mode == FRIGHTEN)
		ghost->mode = EATEN;
}

void	move_ghost(t_game_context *game_state, t_ghost *ghost)
{
	int	aviable_dir;
	int	x;
	int	y;

	x = ghost->loc_x;
	y = ghost->loc_y;
	aviable_dir = (UP | DOWN | LEFT | RIGHT);
	aviable_dir &= ~(ghost->from);

	if ((x == 12 && y == 11) ||
		(x == 12 && y == 23) ||
		(x == 15 && y == 11) ||
		(x == 15 && y == 23))
		aviable_dir &= ~(UP);

	if (ghost->mode & TURN_STUN)
		aviable_dir &= ~(UP | DOWN | LEFT | RIGHT);

	if (game_state->map[y - 1][x + 0] == 'W')
		aviable_dir &= ~(UP);
	if (game_state->map[y + 1][x + 0] == 'W')
		aviable_dir &= ~(DOWN);
	if (game_state->map[y + 0][x - 1] == 'W')
		aviable_dir &= ~(LEFT);
	if (game_state->map[y + 0][x + 1] == 'W')
		aviable_dir &= ~(RIGHT);

	int	t_x;
	int	t_y;
	int	dis;
	int	result;
	int	min_dis;

	result = 0;
	min_dis = INT32_MAX;
	t_x = ghost->target_loc_x;
	t_y = ghost->target_loc_y;

	dis = ((x - t_x) * (x - t_x) + (y - 1 - t_y) * (y - 1 - t_y));
	if ((aviable_dir & UP) && dis < min_dis)
	{
		result = UP;
		min_dis = dis;
	}
	dis = ((x - 1 - t_x) * (x - 1 - t_x) + (y - t_y) * (y - t_y));
	if ((aviable_dir & LEFT) && dis < min_dis)
	{
		result = LEFT;
		min_dis = dis;
	}
	dis = ((x - t_x) * (x - t_x) + (y + 1 - t_y) * (y + 1 - t_y));
	if ((aviable_dir & DOWN) && dis < min_dis)
	{
		result = DOWN;
		min_dis = dis;
	}
	dis = ((x + 1 - t_x) * (x + 1 - t_x) + (y - t_y) * (y - t_y));
	if ((aviable_dir & RIGHT) && dis < min_dis)
	{
		result = RIGHT;
		min_dis = dis;
	}

		 if (result & UP)    { ghost->loc_y--; ghost->from = DOWN;  }
	else if (result & LEFT)  { ghost->loc_x--; ghost->from = RIGHT; }
	else if (result & DOWN)  { ghost->loc_y++; ghost->from = UP;    }
	else if (result & RIGHT) { ghost->loc_x++; ghost->from = LEFT;  }

	ghost->mode &= ~(TURN_STUN);
	if ((result == UP || result == DOWN) && (ghost->from == RIGHT || ghost->from == LEFT))
		ghost->mode |= TURN_STUN;
	if ((result == LEFT || result == RIGHT) && (ghost->from == UP || ghost->from == DOWN))
		ghost->mode |= TURN_STUN;

	ghost->loc_x += (GAME_COLS - 1);
	ghost->loc_x %= (GAME_COLS - 1);
}
