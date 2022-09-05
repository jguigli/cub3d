/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:53 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:55:54 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	stock_position_north(int x, int y, t_main *main)
{
	main->game->map[x][y] = '0';
	main->ray->posx = x;
	main->ray->posy = y;
	main->ray->dirx = -1;
	main->ray->diry = 0;
	main->ray->planx = 0;
	main->ray->plany = 0.66;
	main->game->pos_ok += 1;
}

void	stock_position_south(int x, int y, t_main *main)
{
	main->game->map[x][y] = '0';
	main->ray->posx = x;
	main->ray->posy = y;
	main->ray->dirx = 1;
	main->ray->diry = 0;
	main->ray->planx = 0;
	main->ray->plany = -0.66;
	main->game->pos_ok += 1;
}

void	stock_position_east(int x, int y, t_main *main)
{
	main->game->map[x][y] = '0';
	main->ray->posx = x;
	main->ray->posy = y;
	main->ray->dirx = 0;
	main->ray->diry = 1;
	main->ray->planx = 0.66;
	main->ray->plany = 0;
	main->game->pos_ok += 1;
}

void	stock_position_west(int x, int y, t_main *main)
{
	main->game->map[x][y] = '0';
	main->ray->posx = x;
	main->ray->posy = y;
	main->ray->dirx = 0;
	main->ray->diry = -1;
	main->ray->planx = -0.66;
	main->ray->plany = 0;
	main->game->pos_ok += 1;
}

int	check_position(t_main *main)
{
	int	x;
	int	y;

	x = -1;
	while (main->game->map[++x])
	{
		y = 0;
		while (main->game->map[x][y])
		{
			if (main->game->map[x][y] == 'N')
				stock_position_north(x, y, main);
			else if (main->game->map[x][y] == 'S')
				stock_position_south(x, y, main);
			else if (main->game->map[x][y] == 'E')
				stock_position_east(x, y, main);
			else if (main->game->map[x][y] == 'W')
				stock_position_west(x, y, main);
			y++;
		}
	}
	if (main->game->pos_ok == 0)
		return (error_exit(NOPOS));
	else if (main->game->pos_ok > 1)
		return (error_exit(TMPOS));
	return (0);
}
