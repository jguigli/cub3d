#include "../../includes/cub3d.h"

// int		ft_color_column(t_main *main)
// {
// 	int j;
// 	int i;

// 	j = -1;
// 	main->ray->drawend = main->scr_y - main->ray->drawstart;
// 	i = main->ray->drawend;
// 	while (++j < main->ray->drawstart)
// 		main->img->addr[main->ray->x * 4 / 4 * main->img->line_len * j] = main->c;
// 	// if (j <= main->ray->drawend)
// 	// 	ft_draw_texture(main, main->ray->x, j);
// 	j = i;
// 	while (++j < main->scr_y)
// 		main->img->addr[main->ray->x * 4 / 4 * main->img->line_len * j] = main->f;
// 	return (0);
// }

void	my_mlx_pixel_put(t_xpm *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
	
}

int		draw_map(t_main *main)
{
	main->ray->x = 0;
	while (main->ray->x < main->scr_x)
	{
		main->ray->camerax = 2 * main->ray->x / (double)main->scr_x - 1; //(x - main->scr_x) / (main->scr_x / 2); //x-coordinate in camera space
		main->ray->dirx = cos(main->ray->planx) / 2 + cos(main->ray->planx - 0.25) * main->ray->camerax;
		main->ray->diry = sin(main->ray->plany) / 2 + sin(main->ray->plany - 0.25) * main->ray->camerax;
		main->ray->mapx = floor(main->ray->posx);
		main->ray->mapy = floor(main->ray->posy);
		main->ray->deltadistx = sqrt(1 + ((main->ray->diry * main->ray->diry) / (main->ray->dirx * main->ray->dirx)));
		main->ray->deltadisty = sqrt(1 + ((main->ray->dirx * main->ray->dirx) / (main->ray->diry * main->ray->diry)));
		main->ray->raydirx = main->ray->dirx + main->ray->planx * main->ray->camerax;
		main->ray->raydiry = main->ray->diry + main->ray->plany * main->ray->camerax;

		if (main->ray->dirx < 0)
		{
			main->ray->stepx = -1;
			main->ray->sidedistx = (main->ray->posx - main->ray->mapx) * main->ray->deltadistx;
		}
		else
		{
			main->ray->stepx = 1;
			main->ray->sidedistx = (main->ray->mapx + 1 - main->ray->posx) * main->ray->deltadistx;
		}
		if (main->ray->diry < 0)
		{
			main->ray->stepy = -1;
			main->ray->sidedisty = (main->ray->posy - main->ray->mapy) * main->ray->deltadisty;
		}
		else
		{
			main->ray->stepy = 1;
			main->ray->sidedisty = (main->ray->mapy + 1 - main->ray->posy) * main->ray->deltadisty;
		}
		main->ray->hit = 0;
		while (main->ray->hit == 0)
		{
			if (main->ray->sidedistx < main->ray->sidedisty)
			{
				main->ray->sidedistx += main->ray->deltadistx;
				main->ray->mapx += main->ray->stepx;
				main->ray->side = 0;
			}
			else
			{
				main->ray->sidedisty += main->ray->deltadisty;
				main->ray->mapy += main->ray->stepy;
				main->ray->side = 1;
			}
			if (main->game->map[main->ray->mapx][main->ray->mapy] != 0)
				main->ray->hit = 1;
		}
		if (main->ray->side == 0)
			main->ray->perpwalldist = fabs((double)main->ray->mapx - main->ray->posx + (1 - (double)main->ray->stepx) / 2) / main->ray->dirx;
		else
			main->ray->perpwalldist = fabs((double)main->ray->mapy - main->ray->posy + (1 - (double)main->ray->stepy) / 2) / main->ray->diry;
		if (main->ray->side == 0)
			main->c = 0x00FF0000;
		else
			main->c = 0xFF0FF00;
		main->ray->lineheight = (int)(SCREEN_H / main->ray->perpwalldist);
		main->ray->drawstart = (-main->ray->lineheight / 2) + (SCREEN_H / 2);
		if (main->ray->drawstart < 0)
			main->ray->drawstart = 0;
		main->ray->drawend = (main->ray->lineheight / 2) + (SCREEN_H / 2);
		if (main->ray->drawend >= SCREEN_H)
			main->ray->drawend = SCREEN_H - 1;
		// ft_color_column(main);
		//mlx_pixel_put(main->game->mlx_ptr, main->game->win_ptr, main->ray->drawstart, main->ray->drawend, main->c);
		my_mlx_pixel_put(main->img, main->ray->drawstart, main->ray->drawend, main->c);
		// mlx_put_image_to_window(main->game->mlx_ptr, main->game->win_ptr, main->img->mlx_img, 0, 0);
		main->ray->x++;
	}
	//my_mlx_pixel_put(main->img, main->ray->drawstart, main->ray->drawend, color);
	mlx_put_image_to_window(main->game->mlx_ptr, main->game->win_ptr, main->img->mlx_img, 0, 0);
	return (0);
}
