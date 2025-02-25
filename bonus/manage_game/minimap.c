/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:53:35 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:53:36 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	check_map_4_minimap(t_main *main)
{
	int	i;

	i = 0;
	if (main->c_map->linesizemax > 100)
		return (error_exit(SCALEMINIMAP));
	while (main->game->map[i])
		i++;
	if (i > 50)
		return (error_exit(SCALEMINIMAP));
	return (0);
}

void	draw_player(t_main *main)
{
	int		pixelx;
	int		pixely;
	int		colorplayer;

	colorplayer = 0x00FF00;
	pixelx = 2;
	while (pixelx < 6)
	{
		pixely = 3;
		while (pixely < 6)
		{
			main->img->addr[(pixely + (int)main->ray->posx * 8)
				* main->img->line_len
				/ 4 + (pixelx + (int)main->ray->posy * 8)] = colorplayer;
			pixely++;
		}
		pixelx++;
	}
}

static void	draw_square(t_main *main, int *color, int x, int y)
{
	int		pixelx;
	int		pixely;

	pixelx = 0;
	while (pixelx < 10)
	{
		pixely = 0;
		while (pixely < 10)
		{
			main->img->addr[(pixely + y * 8)
				* main->img->line_len / 4 + (pixelx + x * 8)] = *color;
			pixely++;
		}
		pixelx++;
	}
}

int	draw_minimap(t_main *main)
{
	int		x;
	int		y;
	int		colorfloor;

	colorfloor = 0x080808;
	y = 0;
	while (main->game->map[y])
	{
		x = 0;
		while (main->game->map[y][x])
		{
			if (main->game->map[y][x] == '0')
				draw_square(main, &colorfloor, x, y);
			x++;
		}
		y++;
	}
	draw_player(main);
	return (0);
}
