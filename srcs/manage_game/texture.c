/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:47:12 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:47:13 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"	

int	get_texture(t_main *main)
{
	main->texture[0].mlx_img = mlx_xpm_file_to_image(main->game->mlx_ptr,
			main->game->tex_no, &main->texture[0].width,
			&main->texture[0].height);
	if (!main->texture[0].mlx_img)
		return (error_exit(FAILXPM));
	main->texture[1].mlx_img = mlx_xpm_file_to_image(main->game->mlx_ptr,
			main->game->tex_so, &main->texture[1].width,
			&main->texture[1].height);
	if (!main->texture[1].mlx_img)
		return (error_exit(FAILXPM));
	main->texture[2].mlx_img = mlx_xpm_file_to_image(main->game->mlx_ptr,
			main->game->tex_we, &main->texture[2].width,
			&main->texture[2].height);
	if (!main->texture[2].mlx_img)
		return (error_exit(FAILXPM));
	main->texture[3].mlx_img = mlx_xpm_file_to_image(main->game->mlx_ptr,
			main->game->tex_ea, &main->texture[3].width,
			&main->texture[3].height);
	if (!main->texture[3].mlx_img)
		return (error_exit(FAILXPM));
	return (0);
}

int	get_addr_texture(t_main *main)
{
	main->texture[0].addr = (int *)mlx_get_data_addr(main->texture[0].mlx_img,
			&main->texture[0].bpp, &main->texture[0].line_len,
			&main->texture[0].endian);
	if (!main->texture[0].addr)
		return (error_exit(FAILADDR));
	main->texture[1].addr = (int *)mlx_get_data_addr(main->texture[1].mlx_img,
			&main->texture[1].bpp, &main->texture[1].line_len,
			&main->texture[1].endian);
	if (!main->texture[1].addr)
		return (error_exit(FAILADDR));
	main->texture[2].addr = (int *)mlx_get_data_addr(main->texture[2].mlx_img,
			&main->texture[2].bpp, &main->texture[2].line_len,
			&main->texture[2].endian);
	if (!main->texture[2].addr)
		return (error_exit(FAILADDR));
	main->texture[3].addr = (int *)mlx_get_data_addr(main->texture[3].mlx_img,
			&main->texture[3].bpp, &main->texture[3].line_len,
			&main->texture[3].endian);
	if (!main->texture[3].addr)
		return (error_exit(FAILADDR));
	return (0);
}

void	get_dir_texture(t_main *main)
{
	if (main->ray->side == 0 && main->ray->raydirx < 0)
		main->tex->texdir = 0;
	if (main->ray->side == 0 && main->ray->raydirx >= 0)
		main->tex->texdir = 1;
	if (main->ray->side == 1 && main->ray->raydiry < 0)
		main->tex->texdir = 2;
	if (main->ray->side == 1 && main->ray->raydiry >= 0)
		main->tex->texdir = 3;
}

void	texture_calculation(t_main *main, int x)
{
	main->tex->texx = (int)(main->tex->wallx
			* (double)main->texture[main->tex->texdir].width);
	if (main->ray->side == 0 && main->ray->raydirx > 0)
		main->tex->texx = main->texture[main->tex->texdir].width
			- main->tex->texx - 1;
	if (main->ray->side == 1 && main->ray->raydirx < 0)
		main->tex->texx = main->texture[main->tex->texdir].width
			- main->tex->texx - 1;
	if (main->ray->side == 0)
		main->tex->wallx = (main->ray->posy + main->ray->perpwalldist
				* main->ray->raydiry);
	else
		main->tex->wallx = (main->ray->posx + main->ray->perpwalldist
				* main->ray->raydirx);
	main->tex->wallx -= floor((main->tex->wallx));
	display_color_texture(main, x);
}

void	display_color_texture(t_main *main, int x)
{
	int		y;

	y = main->ray->drawstart;
	main->tex->step = 1.0 * main->texture[main->tex->texdir].height
		/ main->ray->lineheight;
	main->tex->texpos = (main->ray->drawstart - main->scr_y / 2
			+ main->ray->lineheight / 2) * main->tex->step;
	while (y >= main->ray->drawstart && y < main->ray->drawend)
	{
		main->tex->texy = (int)main->tex->texpos
			& (main->texture[main->tex->texdir].height - 1);
		main->tex->texpos += main->tex->step;
		if (y < main->scr_y && x < main->scr_x && y > 0 && x > 0)
			main->img->addr[y * main->img->line_len / 4 + x]
				= main->texture[main->tex->texdir].addr[main->tex->texy
				* main->texture[main->tex->texdir].height + main->tex->texx];
		y++;
	}
}
