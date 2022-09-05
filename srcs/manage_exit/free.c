/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:45:11 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:45:17 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_check_map(t_main *main)
{
	if (main->c_map->line)
		free(main->c_map->line);
	if (main->c_map)
		free(main->c_map);
}

static void	free_data(t_main *main)
{
	int		i;

	i = 0;
	if (main->game->map)
	{
		while (main->game->map[i])
			free (main->game->map[i++]);
		free (main->game->map);
	}
	if (main->game->mlx_ptr)
		free (main->game->mlx_ptr);
	if (main->game->tex_no)
		free (main->game->tex_no);
	if (main->game->tex_so)
		free (main->game->tex_so);
	if (main->game->tex_ea)
		free (main->game->tex_ea);
	if (main->game->tex_we)
		free (main->game->tex_we);
	if (main->game->tex_f)
		free (main->game->tex_f);
	if (main->game->tex_c)
		free (main->game->tex_c);
	free(main->game);
}

void	free_main(t_main *main)
{
	if (main)
	{
		free_data(main);
		free_check_map(main);
		if (main->texture)
			free(main->texture);
		if (main->tex)
			free(main->tex);
		if (main->img)
			free(main->img);
		if (main->ray)
			free(main->ray);
		free(main);
	}
}
