/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:44:29 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:44:42 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	error_exit(char *errormsg)
{
	ft_putstr_fd(errormsg, 2);
	return (1);
}

int	exit_texture(t_main *main)
{
	mlx_destroy_image(main->game->mlx_ptr, main->texture[0].mlx_img);
	mlx_destroy_image(main->game->mlx_ptr, main->texture[1].mlx_img);
	mlx_destroy_image(main->game->mlx_ptr, main->texture[2].mlx_img);
	mlx_destroy_image(main->game->mlx_ptr, main->texture[3].mlx_img);
	return (1);
}

int	exit_escape(t_main *main)
{
	mlx_destroy_image(main->game->mlx_ptr, main->texture[0].mlx_img);
	mlx_destroy_image(main->game->mlx_ptr, main->texture[1].mlx_img);
	mlx_destroy_image(main->game->mlx_ptr, main->texture[2].mlx_img);
	mlx_destroy_image(main->game->mlx_ptr, main->texture[3].mlx_img);
	mlx_destroy_image(main->game->mlx_ptr, main->img->mlx_img);
	mlx_destroy_window(main->game->mlx_ptr, main->game->win_ptr);
	mlx_destroy_display(main->game->mlx_ptr);
	free_main(main);
	exit(1);
	return (0);
}
