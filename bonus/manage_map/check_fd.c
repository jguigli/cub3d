/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:46 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:55:47 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	check_file_name(char *mapname)
{
	char	*rep;
	int		fd;

	fd = open(mapname, __O_DIRECTORY);
	if (fd > 0)
		return (close(fd), error_exit(BADFD));
	close(fd);
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return (close(fd), error_exit(BADFD));
	close(fd);
	rep = ft_strrchr(mapname, '.');
	if (rep == NULL || ft_strcmp(rep, ".cub") != 0)
		return (error_exit(BADFEXT));
	return (0);
}
