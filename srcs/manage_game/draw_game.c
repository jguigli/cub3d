/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:45:52 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:45:53 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	display_floor_ceilling(t_main *main)
{
	int		x;
	int		y;

	x = -1;
	while (++x < main->scr_x)
	{
		y = 0;
		while (y < main->scr_y / 2)
		{
			main->img->addr[y * main->img->line_len / 4 + x]
				= main->game->color_c;
			y++;
		}
	}
	x = -1;
	while (++x < main->scr_x)
	{
		y = main->scr_y / 2;
		while (y < main->scr_y)
		{
			main->img->addr[y * main->img->line_len / 4 + x]
				= main->game->color_f;
			y++;
		}
	}
}

void	display_texture(t_main *main, int x)
{
	int		y;

	y = -1;
	while (++y < main->ray->drawstart && main->ray->drawstart <= main->scr_y)
		main->img->addr[y * main->img->line_len / 4 + x]
			= main->game->color_c;
	texture_calculation(main, x);
	y = main->ray->drawend;
	while (++y < main->scr_y && main->ray->drawend > 0)
		main->img->addr[y * main->img->line_len / 4 + x]
			= main->game->color_f;
}

int	draw_map(t_main *main)
{
	int		x;

	x = 0;
	//display_floor_ceilling(main);
	while (x < main->scr_x)
	{
		init_raycast(main, x);
		side_dist(main);
		algo_dda(main);
		wall_dist(main);
		get_dir_texture(main);
		display_texture(main, x);
		x++;
	}
	event_key(main);
	mlx_put_image_to_window(main->game->mlx_ptr,
		main->game->win_ptr, main->img->mlx_img, 0, 0);
	return (0);
}
