/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:56:19 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:56:20 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	check_char(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	while (main->game->map[x])
	{
		y = 0;
		while (main->game->map[x][y])
		{
			if (main->game->map[x][y] != ' ' && main->game->map[x][y] != '\t'
				&& main->game->map[x][y] != '0' && main->game->map[x][y] != '1')
				return (error_exit(CHARMAP));
			y++;
		}
		x++;
	}
	return (0);
}

int	check_format(t_main *main)
{
	int	x;

	x = 0;
	while (main->game->map[x])
		x++;
	if (x < 3)
		return (error_exit(FORMATMAP));
	return (0);
}

int	loop_check_rgb(char *rgb, int *comma, int *i)
{
	while (rgb[*i] != ',' && rgb[*i])
	{
		if (!ft_isdigit(rgb[*i]) && rgb[*i] != ' ')
		{
			if ((rgb[*i] == ' ' || rgb[*i] == 9) && *comma > 1
				&& (ft_isdigit(rgb[*i - 1]) || rgb[*i - 1] == ' '
					|| rgb[*i - 1] == 9) && (rgb[*i + 1] == ' '
					|| rgb[*i + 1] == 9 || rgb[*i + 1] == '\0'))
				;
			else
				return (error_exit(CHARRGB));
		}
		(*i)++;
	}
	return (0);
}

int	check_comma_number(char *rgb)
{
	int		comma;
	int		i;

	comma = 0;
	i = 0;
	while (rgb[i])
	{
		if (loop_check_rgb(rgb, &comma, &i))
			return (1);
		if (rgb[i] == ',')
			comma++;
		if (rgb[i] == ',' && rgb[i + 1] == '\0' && comma == 2)
			return (error_exit(COMMARGB));
		if (rgb[i] == '\0' && comma < 2)
			return (error_exit(NBRNBR));
		if (rgb[i] != '\0')
			i++;
	}
	if (comma > 2)
		return (error_exit(NBRCOMMA));
	return (0);
}

int	manage_file_map(t_main *main, char *mapname)
{
	if (check_file_name(mapname))
		return (-1);
	main->c_map->fd = open(mapname, O_RDONLY);
	if (read_file(main))
	{
		close(main->c_map->fd);
		return (-1);
	}
	parse_map(main);
	if (check_map_4_minimap(main))
		return (-1);
	close(main->c_map->fd);
	if (check_format(main))
		return (-1);
	if (check_position(main))
		return (-1);
	if (check_char(main))
		return (-1);
	if (check_outline(main))
		return (-1);
	if (check_color(main))
		return (-1);
	fill_map(main);
	return (0);
}
