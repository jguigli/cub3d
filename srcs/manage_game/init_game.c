/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:46:16 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:46:18 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_xpm	*initialisation_struct_xpm(void)
{
	t_xpm	*img;

	img = malloc(sizeof(t_xpm));
	if (!img)
		return (NULL);
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	return (img);
}

t_xpm	*initialisation_struct_texture(void)
{
	t_xpm	*img;

	img = malloc(sizeof(t_xpm *) * 4);
	if (!img)
		return (NULL);
	return (img);
}

t_tex	*initialisation_struct_tex(void)
{
	t_tex	*tex;

	tex = malloc(sizeof(t_tex));
	if (!tex)
		return (NULL);
	tex->wallx = 0;
	tex->step = 0;
	tex->texpos = 0;
	tex->texx = 0;
	tex->texy = 0;
	tex->texdir = 0;
	return (tex);
}

char	*initialisation_struct_other(t_main *main)
{
	int	i;

	i = 0;
		main->c_map = initialisation_struct_map();
	if (!main->c_map)
		return (NULL);
	main->game = initialisation_struct_game();
	if (!main->game)
		return (NULL);
	main->ray = initialisation_struct_raycasting();
	if (!main->ray)
		return (NULL);
	main->img = initialisation_struct_xpm();
	if (!main->img)
		return (NULL);
	main->texture = (t_xpm *)malloc(sizeof(t_xpm) * 4);
	if (!main->texture)
		return (NULL);
	while (i < 4)
		main->texture[i++] = (t_xpm){};
	main->tex = initialisation_struct_tex();
	if (!main->tex)
		return (NULL);
	return ("NICE");
}

t_main	*initialisation_struct_main(void)
{
	t_main	*main;

	main = malloc(sizeof(t_main));
	if (!main)
		return (NULL);
	main->scr_x = (int)SCREEN_W;
	main->scr_y = (int)SCREEN_H;
	if (!initialisation_struct_other(main))
		return (NULL);
	return (main);
}
