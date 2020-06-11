/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 10:31:33 by home              #+#    #+#             */
/*   Updated: 2020/06/10 23:53:11 by home             ###   ########.fr       */
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

void	texture_map(int fetch_code)
{
	static char	image[80];

	image[ 0] = 0b00011000;
	image[ 1] = 0b00111100;
	image[ 2] = 0b01100110;
	image[ 3] = 0b01100110;
	image[ 4] = 0b01100110;
	image[ 5] = 0b01100110;
	image[ 6] = 0b00111100;
	image[ 7] = 0b00011000;

	image[ 8] = 0b00111100;
	image[ 9] = 0b01111100;
	image[10] = 0b00001100;
	image[11] = 0b00001100;
	image[12] = 0b00001100;
	image[13] = 0b00001100;
	image[14] = 0b00001100;
	image[15] = 0b01111110;

	image[16] = 0b00111100;
	image[17] = 0b01000010;
	image[18] = 0b00000010;
	image[19] = 0b00001110;
	image[20] = 0b00111100;
	image[21] = 0b01000000;
	image[22] = 0b01000010;
	image[23] = 0b00111110;

	image[24] = 0b00111100;
	image[25] = 0b01000010;
	image[26] = 0b00000010;
	image[27] = 0b00111100;
	image[28] = 0b00000100;
	image[29] = 0b00000010;
	image[30] = 0b01000010;
	image[31] = 0b00111100;

	image[32] = 0b01000100;
	image[33] = 0b01000100;
	image[34] = 0b01000100;
	image[35] = 0b00111100;
	image[36] = 0b00000100;
	image[37] = 0b00000100;
	image[38] = 0b00000100;
	image[39] = 0b00000100;

	image[40] = 0b00000000;
	image[41] = 0b00000000;
	image[42] = 0b00000000;
	image[43] = 0b00000000;
	image[44] = 0b00000000;
	image[45] = 0b00000000;
	image[46] = 0b00000000;
	image[47] = 0b00000000;

	image[48] = 0b00000000;
	image[49] = 0b00000000;
	image[50] = 0b00000000;
	image[51] = 0b00000000;
	image[52] = 0b00000000;
	image[53] = 0b00000000;
	image[54] = 0b00000000;
	image[55] = 0b00000000;

	image[56] = 0b00000000;
	image[57] = 0b00000000;
	image[58] = 0b00000000;
	image[59] = 0b00000000;
	image[60] = 0b00000000;
	image[61] = 0b00000000;
	image[62] = 0b00000000;
	image[63] = 0b00000000;

	image[64] = 0b00000000;
	image[65] = 0b00000000;
	image[66] = 0b00000000;
	image[67] = 0b00000000;
	image[68] = 0b00000000;
	image[69] = 0b00000000;

	(void)fetch_code;
}
