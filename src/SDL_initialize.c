/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 05:22:09 by home              #+#    #+#             */
/*   Updated: 2020/06/11 00:46:23 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	SDLU_start(t_display *dest)
{
	SDL_Window	*window;
	SDL_Surface	*surface;

	dest->width = WIN_WIDTH;
	dest->height = WIN_HEIGHT;
	dest->size = dest->width * dest->height;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
				WIN_TITLE,
				WIN_POS_X, WIN_POS_Y,
				dest->width, dest->height,
				SDL_WINDOW_SHOWN
	);
	surface = SDL_GetWindowSurface(window);

	dest->window = window;
	dest->pixels = surface->pixels;
}

void	SDLU_close(t_display *display)
{
	SDL_DestroyWindow(display->window);
	SDL_Quit();
}
