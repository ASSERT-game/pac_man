/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:05:36 by home              #+#    #+#             */
/*   Updated: 2020/06/10 23:06:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	fill_ghost(t_ghost *ghost, int color, int x, int y, int s_x, int s_y)
{
	ghost->b_color = color;

	ghost->scatter_loc_x = s_x;
	ghost->scatter_loc_y = s_y;

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
		if (game_state->fright_ticks < 50 && game_state->fright_ticks % 4 == 0)
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
	if (ghost->mode == SCATTER)
	{
		ghost->target_loc_x = ghost->scatter_loc_x;
		ghost->target_loc_y = ghost->scatter_loc_y;
	}
	if (ghost->mode == SCATTER || ghost->mode == CHASE)
	{
		if (ghost->loc_x == game_state->player.loc_x && ghost->loc_y == game_state->player.loc_y)
			game_state->lives--;
	}
}

void	double_buffer_update(t_game_context *game_state, t_ghost *ghost)
{
	if (ghost->loc_x == game_state->player.loc_x &&
		ghost->loc_y == game_state->player.loc_y &&
		ghost->mode == FRIGHTEN)
		ghost->mode = EATEN;
}

int		random_dir_pick(int available_dir)
{
	int	a;
	int	b;
	int	c;
	int	pick;
	int	count_dirs;

	count_dirs = 0;
	if (available_dir & UP)
		count_dirs++;
	if (available_dir & DOWN)
		count_dirs++;
	if (available_dir & LEFT)
		count_dirs++;
	if (available_dir & RIGHT)
		count_dirs++;

	a = rand();
	b = rand();
	c = rand();

	if (count_dirs == 1)
		pick = 1;
	if (count_dirs == 2)
	{
		if (a > b)
			pick = 1;
		else
			pick = 2;
	}
	if (count_dirs == 3)
	{
		if (a > b && a > c)
			pick = 1;
		else if (a < b && a < c)
			pick = 3;
		else
			pick = 2;
	}

	int	dir_result = 0;
	if (pick > 0 && (available_dir & UP))
	{
		pick--;
		dir_result = UP;
	}
	if (pick > 0 && (available_dir & LEFT))
	{
		pick--;
		dir_result = LEFT;
	}
	if (pick > 0 && (available_dir & DOWN))
	{
		pick--;
		dir_result = DOWN;
	}
	if (pick > 0 && (available_dir & RIGHT))
	{
		pick--;
		dir_result = RIGHT;
	}

	return (dir_result);
}

void	move_ghost(t_game_context *game_state, t_ghost *ghost)
{
	int	available_dir;
	int	x;
	int	y;

	x = ghost->loc_x;
	y = ghost->loc_y;
	available_dir = (UP | DOWN | LEFT | RIGHT);
	available_dir &= ~(ghost->from);

	if ((x == 12 && y == 11) ||
		(x == 12 && y == 23) ||
		(x == 15 && y == 11) ||
		(x == 15 && y == 23))
		available_dir &= ~(UP);

	if (game_state->freeze_ticks > 0)
		return ;

	if (ghost->mode & TURN_STUN)
		available_dir &= ~(UP | DOWN | LEFT | RIGHT);

	if (game_state->map[y - 1][x + 0] == 'W')
		available_dir &= ~(UP);
	if (game_state->map[y + 1][x + 0] == 'W')
		available_dir &= ~(DOWN);
	if (game_state->map[y + 0][x - 1] == 'W')
		available_dir &= ~(LEFT);
	if (game_state->map[y + 0][x + 1] == 'W')
		available_dir &= ~(RIGHT);

	if (ghost->mode == FRIGHTEN)
	{
		available_dir = random_dir_pick(available_dir);
		if (game_state->game_tick % 2 == 0)
			return ;
	}
	if (ghost->mode == EATEN && game_state->game_tick % 4 == 0)
		return ;

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
	if ((available_dir & UP) && dis < min_dis)
	{
		result = UP;
		min_dis = dis;
	}
	dis = ((x - 1 - t_x) * (x - 1 - t_x) + (y - t_y) * (y - t_y));
	if ((available_dir & LEFT) && dis < min_dis)
	{
		result = LEFT;
		min_dis = dis;
	}
	dis = ((x - t_x) * (x - t_x) + (y + 1 - t_y) * (y + 1 - t_y));
	if ((available_dir & DOWN) && dis < min_dis)
	{
		result = DOWN;
		min_dis = dis;
	}
	dis = ((x + 1 - t_x) * (x + 1 - t_x) + (y - t_y) * (y - t_y));
	if ((available_dir & RIGHT) && dis < min_dis)
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
