/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:52:15 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:52:16 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_main	*main;

	main = NULL;
	if (argc != 2)
		return (error_exit(ARG));
	if (!env || !*env)
		return (error_exit(ENV));
	main = initialisation_struct_main();
	init_mlx_ptr(main);
	if (manage_file_map(main, argv[1]) == -1)
	{
		mlx_destroy_display(main->game->mlx_ptr);
		free_main(main);
		return (-1);
	}
	create_window(main);
	draw_map(main);
	manage_mlx(main);
	exit_escape(main);
	return (0);
}
