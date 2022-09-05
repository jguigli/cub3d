/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:59 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:56:00 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	check_texture_one(t_main *main)
{
	if (!ft_strncmp(main->c_map->line, "NO ", 3))
	{
		if (main->game->check_no == 1)
			return (error_exit(NTEXMEN));
		main->game->check_no += 1;
		main->game->tex_no = crop_texture_side(main);
		return (2);
	}
	if (!ft_strncmp(main->c_map->line, "SO ", 3))
	{
		if (main->game->check_so == 1)
			return (error_exit(STEXMEN));
		main->game->check_so += 1;
		main->game->tex_so = crop_texture_side(main);
		return (2);
	}
	if (!ft_strncmp(main->c_map->line, "WE ", 3))
	{
		if (main->game->check_we == 1)
			return (error_exit(WTEXMEN));
		main->game->check_we += 1;
		main->game->tex_we = crop_texture_side(main);
		return (2);
	}
	return (0);
}

int	check_texture_two(t_main *main)
{
	if (!ft_strncmp(main->c_map->line, "EA ", 3))
	{
		if (main->game->check_ea == 1)
			return (error_exit(ETEXMEN));
		main->game->check_ea += 1;
		main->game->tex_ea = crop_texture_side(main);
		return (2);
	}
	if (!ft_strncmp(main->c_map->line, "F ", 2))
	{
		if (main->game->check_f == 1)
			return (error_exit(FTEXMEN));
		main->game->check_f += 1;
		main->game->tex_f = crop_texture_high(main);
		return (2);
	}
	if (!ft_strncmp(main->c_map->line, "C ", 2))
	{
		if (main->game->check_c == 1)
			return (error_exit(CTEXMEN));
		main->game->check_c += 1;
		main->game->tex_c = crop_texture_high(main);
		return (2);
	}
	return (0);
}
