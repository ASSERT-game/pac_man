/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 10:31:33 by home              #+#    #+#             */
/*   Updated: 2020/06/11 00:34:37 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	draw_wall_tile(unsigned char *pixel_array, int x, int y)
{
	int	i;
	int	color;

	i = 0;
	color = 0x00aaFF;
	while (i < 8)
	{
		color_in(pixel_array, color, x * 8 + i, y * 8 + 0);
		color_in(pixel_array, color, x * 8 + i, y * 8 + 7);

		color_in(pixel_array, color, x * 8 + 0, y * 8 + i);
		color_in(pixel_array, color, x * 8 + 7, y * 8 + i);

		i++;
	}
}

void	draw_target(unsigned char *pixel_array, int x, int y, int color)
{
	color_in(pixel_array, color, x * 8 + 3, y * 8 + 3);
	color_in(pixel_array, color, x * 8 + 3, y * 8 + 4);
	color_in(pixel_array, color, x * 8 + 4, y * 8 + 3);
	color_in(pixel_array, color, x * 8 + 4, y * 8 + 4);

	color_in(pixel_array, color, x * 8 + 2, y * 8 + 2);
	color_in(pixel_array, color, x * 8 + 2, y * 8 + 5);
	color_in(pixel_array, color, x * 8 + 5, y * 8 + 2);
	color_in(pixel_array, color, x * 8 + 5, y * 8 + 5);
}

void	draw_pacman_tile(unsigned char *pixel_array, int x, int y)
{
	int	i;
	int	color;

	i = 0;
	color = 0xEEAA77;
	while (i < 4)
	{
		color_in(pixel_array, color, x * 8 + i + 2, y * 8 + 1);
		color_in(pixel_array, color, x * 8 + i + 2, y * 8 + 6);

		color_in(pixel_array, color, x * 8 + 1, y * 8 + i + 2);
		color_in(pixel_array, color, x * 8 + 6, y * 8 + i + 2);

		i++;
	}
}

void	draw_ghost_tile(unsigned char *pixel_array, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		color_in(pixel_array, color, x * 8 + i + 2, y * 8 + 1);
		color_in(pixel_array, color, x * 8 + i + 2, y * 8 + 6);

		color_in(pixel_array, color, x * 8 + 1, y * 8 + i + 2);
		color_in(pixel_array, color, x * 8 + 6, y * 8 + i + 2);

		i++;
	}
}

void	draw_pellet_tile(unsigned char *pixel_array, int x, int y)
{
	int	color;

	color = 0xFFFFFF;
	color_in(pixel_array, color, x * 8 + 3 + 0, y * 8 + 3 + 1);
	color_in(pixel_array, color, x * 8 + 3 + 1, y * 8 + 3 + 1);
	color_in(pixel_array, color, x * 8 + 3 + 0, y * 8 + 3 + 0);
	color_in(pixel_array, color, x * 8 + 3 + 1, y * 8 + 3 + 0);
}

void	draw_power_tile(unsigned char *pixel_array, int x, int y)
{
	int	color;

	color = 0xFFFFFF;
	color_in(pixel_array, color, x * 8 + 3 + 0, y * 8 + 3 - 1);
	color_in(pixel_array, color, x * 8 + 3 + 1, y * 8 + 3 - 1);

	color_in(pixel_array, color, x * 8 + 3 - 1, y * 8 + 3 + 0);
	color_in(pixel_array, color, x * 8 + 3 + 0, y * 8 + 3 + 0);
	color_in(pixel_array, color, x * 8 + 3 + 1, y * 8 + 3 + 0);
	color_in(pixel_array, color, x * 8 + 3 + 2, y * 8 + 3 + 0);

	color_in(pixel_array, color, x * 8 + 3 - 1, y * 8 + 3 + 1);
	color_in(pixel_array, color, x * 8 + 3 + 0, y * 8 + 3 + 1);
	color_in(pixel_array, color, x * 8 + 3 + 1, y * 8 + 3 + 1);
	color_in(pixel_array, color, x * 8 + 3 + 2, y * 8 + 3 + 1);

	color_in(pixel_array, color, x * 8 + 3 + 0, y * 8 + 3 + 2);
	color_in(pixel_array, color, x * 8 + 3 + 1, y * 8 + 3 + 2);
}

void	draw_freeze_tile(unsigned char *pixel_array, int x, int y)
{
	int	color;
	int	i;

	i = 0;
	color = 0x00DDFF;
	while (i < 6)
	{
		color_in(pixel_array, color, x * 8 + 1 + i, y * 8 + 3 + 0);
		color_in(pixel_array, color, x * 8 + 1 + i, y * 8 + 3 + 1);
		color_in(pixel_array, color, x * 8 + 1 + i, y * 8 + 3 + 2);
		color_in(pixel_array, color, x * 8 + 1 + i, y * 8 + 3 + 3);
		i++;
	}

	color_in(pixel_array, color, x * 8 + 1, y * 8 + 1);
	color_in(pixel_array, color, x * 8 + 1, y * 8 + 2);
	color_in(pixel_array, color, x * 8 + 6, y * 8 + 1);
	color_in(pixel_array, color, x * 8 + 6, y * 8 + 2);

	color_in(pixel_array, color, x * 8 + 3, y * 8 + 2);
	color_in(pixel_array, color, x * 8 + 4, y * 8 + 2);
}

void	draw_map(t_map map, unsigned char *pixel_array)
{
	int	x;
	int	y;

	y = 0;
	while (y < GAME_ROWS)
	{
		x = 0;
		while (x < GAME_COLS)
		{
			if (map[y][x] == 'W')
				draw_wall_tile(pixel_array, x, y + 3);
			else if (map[y][x] == '.')
				draw_pellet_tile(pixel_array, x, y + 3);
			else if (map[y][x] == 'P')
				draw_power_tile(pixel_array, x, y + 3);
			x++;
		}
		y++;
	}
}

void	draw_lives(unsigned char *pixel_array, int lives)
{
	int	i;

	i = 0;
	while (i < lives)
	{
		draw_pacman_tile(pixel_array, 0 + i, 34);
		i++;
	}
}

void	draw_freeze(unsigned char *pixel_array, int freeze)
{
	int	i;

	i = 0;
	while (i < freeze)
	{
		draw_freeze_tile(pixel_array, 0 + i, 35);
		i++;
	}
}
