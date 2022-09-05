/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closemap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:47:37 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:47:38 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	ft_strlen_double(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	check_first_last_row(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_zero(char **map, int x, int y)
{
	if (map[x - 1][y] != '1' && map[x - 1][y] != '0')
		return (1);
	if (map[x + 1][y] != '1' && map[x + 1][y] != '0')
		return (1);
	if (map[x][y - 1] != '1' && map[x][y - 1] != '0')
		return (1);
	if (map[x][y + 1] != '1' && map[x][y + 1] != '0')
		return (1);
	return (0);
}

int	check_outline(t_main *main)
{
	size_t	x;
	size_t	y;

	x = 1;
	if (check_first_last_row(main->game->map[0])
		|| check_first_last_row(main->game->map
			[ft_strlen_double(main->game->map) - 1]))
		return (error_exit(NMAPCLOSED));
	while (x < ft_strlen_double(main->game->map) - 1)
	{
		y = 0;
		while (main->game->map[x][y])
		{
			if (main->game->map[x][y] == '0')
			{
				if (check_zero(main->game->map, x, y))
					return (error_exit(NMAPCLOSED));
			}
			y++;
		}
		x++;
	}
	return (0);
}
