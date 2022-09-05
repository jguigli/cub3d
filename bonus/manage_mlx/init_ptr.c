/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:59:10 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:59:12 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_mlx_ptr(t_main *main)
{
	main->game->mlx_ptr = mlx_init();
	if (main->game->mlx_ptr == NULL)
	{
		exit(EXIT_FAILURE);
	}
}
