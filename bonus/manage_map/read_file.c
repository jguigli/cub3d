/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:57:19 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:57:20 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	have_only_space(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i++] != ' ')
			return (0);
	}
	return (1);
}

int	skip_backline(t_main *main)
{
	free (main->c_map->line);
	main->c_map->line = get_next_line(main->c_map->fd);
	return (0);
}

int	read_map(t_main *main)
{
	while (main->c_map->line != NULL)
	{
		if (have_only_space(main->c_map->line))
		{
			free (main->c_map->linejoin);
			return (free_gnl_msg(main, SPACEMAP));
		}
		else
		{
			main->c_map->linesize = ft_strlen(main->c_map->line);
			if (main->c_map->linesize > main->c_map->linesizemax)
				main->c_map->linesizemax = main->c_map->linesize;
			main->c_map->linejoin = ft_strjoin(main->c_map->linejoin,
					main->c_map->line);
			free (main->c_map->line);
			main->c_map->line = get_next_line(main->c_map->fd);
		}
	}
	return (0);
}

int	loop_read_texture(t_main *main)
{
	while (main->c_map->line != NULL)
	{
		if (!ft_strcmp(main->c_map->line, "\n"))
			skip_backline(main);
		else if (have_only_space(main->c_map->line))
			return (free_gnl_msg(main, EMPTYSPACE));
		else if (main->c_map->line[0] == '1' || main->c_map->line[0] == '0'
			|| main->c_map->line[0] == ' ')
		{
			if (!check_count_texture(main))
				return (free_gnl_msg(main, MISSINGTEX));
			else
				break ;
		}
		else
		{
			if (check_texture(main))
				return (free_gnl_simple(main));
			free (main->c_map->line);
			if (check_count_texture(main))
				break ;
			main->c_map->line = get_next_line(main->c_map->fd);
		}
	}
	return (0);
}

int	read_file(t_main *main)
{
	main->c_map->line = get_next_line(main->c_map->fd);
	if (main->c_map->line == NULL)
		return (error_exit(EMPTYFD));
	if (loop_read_texture(main))
		return (1);
	while (!ft_strcmp(main->c_map->line, "\n"))
	{
		skip_backline(main);
		if (main->c_map->line == NULL)
			return (error_exit(MISSINGMAP));
	}
	if (read_map(main))
		return (1);
	return (0);
}
