/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:40 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:55:41 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	create_trgb(int r, int g, int b)
{
	int		t;

	t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}

int	space_inside(char *temp)
{
	int		i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	free_gnl_msg(t_main *main, char *msg)
{
	while (main->c_map->line != NULL)
	{
		free (main->c_map->line);
		main->c_map->line = get_next_line(main->c_map->fd);
	}
	return (error_exit(msg));
}

int	free_gnl_simple(t_main *main)
{
	while (main->c_map->line != NULL)
	{
		free (main->c_map->line);
		main->c_map->line = get_next_line(main->c_map->fd);
	}
	return (1);
}
