/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:53:47 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:53:48 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	move_forward(t_main *main)
{
	if (main->game->map[(int)(main->ray->posx
			+ (main->ray->dirx * 0.1))][(int)main->ray->posy] == '0')
		main->ray->posx += (main->ray->dirx * 0.1);
	if (main->game->map[(int)(main->ray->posx)][(int)(main->ray->posy
			+ (main->ray->diry * 0.1))] == '0')
		main->ray->posy += (main->ray->diry * 0.1);
}

void	move_back(t_main *main)
{
	if (main->game->map[(int)(main->ray->posx
			- (main->ray->dirx * 0.1))][(int)main->ray->posy] == '0')
	main->ray->posx -= (main->ray->dirx * 0.1);
	if (main->game->map[(int)(main->ray->posx)][(int)(main->ray->posy
			- (main->ray->diry * 0.1))] == '0')
	main->ray->posy -= (main->ray->diry * 0.1);
}

void	move_right(t_main *main)
{
	if (main->game->map[(int)(main->ray->posx
			+ (main->ray->diry * 0.1))][(int)main->ray->posy] == '0')
	main->ray->posx += (main->ray->diry * 0.1);
	if (main->game->map[(int)(main->ray->posx)][(int)(main->ray->posy
			- (main->ray->dirx * 0.1))] == '0')
	main->ray->posy -= (main->ray->dirx * 0.1);
}

void	move_left(t_main *main)
{
	if (main->game->map[(int)(main->ray->posx
			- (main->ray->diry * 0.1))][(int)main->ray->posy] == '0')
	main->ray->posx -= (main->ray->diry * 0.1);
	if (main->game->map[(int)(main->ray->posx)][(int)(main->ray->posy
			+ (main->ray->dirx * 0.1))] == '0')
	main->ray->posy += (main->ray->dirx * 0.1);
}
