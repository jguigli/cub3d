/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:48:50 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:48:51 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_linesize_max(t_main *main)
{
	size_t		x;
	size_t		y;

	x = 0;
	while (main->game->map[x])
	{
		y = ft_strlen(main->game->map[x]);
		if (y < main->c_map->linesizemax)
		{
			while (y < main->c_map->linesizemax)
			{
				main->game->map[x][y] = '1';
				y++;
			}
		}
		main->game->map[x][y] = '\0';
		x++;
	}
}

void	fill_map(t_main *main)
{
	size_t		x;
	size_t		y;

	x = 0;
	while (main->game->map[x])
	{
		y = 0;
		while (main->game->map[x][y])
		{
			if (main->game->map[x][y] == ' ')
				main->game->map[x][y] = '1';
			y++;
		}
		x++;
	}
	fill_linesize_max(main);
}

void	parse_map(t_main *main)
{
	main->game->map = ft_split_map(main, main->c_map->linejoin);
	free (main->c_map->linejoin);
}
