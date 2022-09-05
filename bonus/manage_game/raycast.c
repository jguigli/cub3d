/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:53:55 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:53:57 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_raycast(t_main *main, int x)
{
	main->ray->camerax = 2 * x / (double)main->scr_x - 1;
	main->ray->mapx = (int)main->ray->posx;
	main->ray->mapy = (int)main->ray->posy;
	main->ray->raydirx = main->ray->dirx + main->ray->planx
		* main->ray->camerax;
	main->ray->raydiry = main->ray->diry + main->ray->plany
		* main->ray->camerax;
	main->ray->deltadistx = fabs(1 / main->ray->raydirx);
	main->ray->deltadisty = fabs(1 / main->ray->raydiry);
}

void	side_dist(t_main *main)
{
	if (main->ray->raydirx < 0)
	{
		main->ray->stepx = -1;
		main->ray->sidedistx = (main->ray->posx - main->ray->mapx)
			* main->ray->deltadistx;
	}
	else
	{
		main->ray->stepx = 1;
		main->ray->sidedistx = (main->ray->mapx + 1.0 - main->ray->posx)
			* main->ray->deltadistx;
	}
	if (main->ray->raydiry < 0)
	{
		main->ray->stepy = -1;
		main->ray->sidedisty = (main->ray->posy - main->ray->mapy)
			* main->ray->deltadisty;
	}
	else
	{
		main->ray->stepy = 1;
		main->ray->sidedisty = (main->ray->mapy + 1.0 - main->ray->posy)
			* main->ray->deltadisty;
	}
}

void	algo_dda(t_main *main)
{
	main->ray->hit = 0;
	while (main->ray->hit == 0)
	{
		if (main->ray->sidedistx < main->ray->sidedisty)
		{
			main->ray->sidedistx += main->ray->deltadistx;
			main->ray->mapx += main->ray->stepx;
			main->ray->side = 0;
		}
		else
		{
			main->ray->sidedisty += main->ray->deltadisty;
			main->ray->mapy += main->ray->stepy;
			main->ray->side = 1;
		}
		if (main->game->map[(int)main->ray->mapx][(int)main->ray->mapy] > '0')
			main->ray->hit = 1;
	}
}

void	wall_dist(t_main *main)
{
	if (main->ray->side == 0)
		main->ray->perpwalldist = main->ray->sidedistx - main->ray->deltadistx;
	else
		main->ray->perpwalldist = main->ray->sidedisty - main->ray->deltadisty;
	main->ray->lineheight = (int)(main->scr_y / main->ray->perpwalldist);
	main->ray->drawstart = -main->ray->lineheight / 2 + main->scr_y / 2;
	if (main->ray->drawstart < 0 || main->ray->drawstart > main->scr_y)
		main->ray->drawstart = 0;
	main->ray->drawend = main->ray->lineheight / 2 + main->scr_y / 2;
	if (main->ray->drawend >= main->scr_y || main->ray->drawend < 0)
		main->ray->drawend = main->scr_y - 1;
}
