#include "../../includes/cub3d.h"	

int    get_texture(t_main *main)
{
    main->texture[0].mlx_img = mlx_xpm_file_to_image(main->game->mlx_ptr,
			main->game->tex_no, &main->texture[0].width,
			&main->texture[0].height);
	if (!main->texture[0].mlx_img)
		return (1);
    main->texture[1].mlx_img = mlx_xpm_file_to_image(main->game->mlx_ptr,
			main->game->tex_so, &main->texture[1].width,
			&main->texture[1].height);
	if (!main->texture[1].mlx_img)
		return (1);
    main->texture[2].mlx_img = mlx_xpm_file_to_image(main->game->mlx_ptr,
			main->game->tex_we, &main->texture[2].width,
			&main->texture[2].height);
	if (!main->texture[2].mlx_img)
		return (1);
    main->texture[3].mlx_img = mlx_xpm_file_to_image(main->game->mlx_ptr,
			main->game->tex_ea, &main->texture[3].width,
			&main->texture[3].height);
	if (!main->texture[3].mlx_img)
		return (1);
	return (0);
}


int		get_addr_texture(t_main *main)
{
    main->texture[0].addr = mlx_get_data_addr(main->game->mlx_ptr, &main->texture[0].bpp, &main->texture[0].line_len, &main->texture[0].endian);
	if (!main->texture[0].addr)
		return (1);
    main->texture[1].addr = mlx_get_data_addr(main->game->mlx_ptr, &main->texture[1].bpp, &main->texture[1].line_len, &main->texture[1].endian);
	if (!main->texture[1].addr)
		return (1);
    main->texture[2].addr = mlx_get_data_addr(main->game->mlx_ptr, &main->texture[2].bpp, &main->texture[2].line_len, &main->texture[2].endian);
	if (!main->texture[2].addr)
		return (1);
    main->texture[3].addr = mlx_get_data_addr(main->game->mlx_ptr, &main->texture[3].bpp, &main->texture[3].line_len, &main->texture[3].endian);
	if (!main->texture[3].addr)
		return (1);
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
	if (main->ray->side == 0)
		main->tex->wallx = (main->ray->posy + main->ray->perpwalldist * main->ray->raydiry);
	else
		main->tex->wallx = (main->ray->posx + main->ray->perpwalldist * main->ray->raydirx);
	main->tex->wallx -= floor((main->tex->wallx));
	main->tex->texX = (int)(main->tex->wallx * (double)main->texture[main->tex->texdir].width);
	if (main->ray->side == 0 && main->ray->raydirx > 0)
		main->tex->texX = main->texture[main->tex->texdir].width - main->tex->texX - 1;
	if (main->ray->side == 1 && main->ray->raydirx < 0)
		main->tex->texX = main->texture[main->tex->texdir].width - main->tex->texX - 1;
	display_color_texture(main, x);
}

void	display_color_texture(t_main *main, int x)
{
	int		y;

	y = main->ray->drawstart;
	main->tex->step = 1.0 * main->texture[main->tex->texdir].height / main->ray->lineheight;
	main->tex->texpos = (main->ray->drawstart - main->scr_y / 2 + main->ray->lineheight / 2) * main->tex->step;
	while (y < main->ray->drawend)
	{
		main->tex->texY = (int)main->tex->texpos & (main->texture[main->tex->texdir].height - 1);
		main->tex->texpos += main->tex->step;
		if (y < main->scr_y && x < main->scr_x)
		{
			my_mlx_pixel_put(main, x, y, main->texture[main->tex->texdir].addr[main->texture[main->tex->texdir].height * main->tex->texY + main->tex->texX]);
			//recup->texture[recup->t.texdir].addr[recup->t.texy * recup->texture[recup->t.texdir].line_length /4 + recup->t.texx];
		}
		y++;
	}
}