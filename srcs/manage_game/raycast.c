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

void	my_mlx_pixel_put(t_main *main, int x, int y, int color)
{
	char	*dst;

	dst = main->img->addr + (y * main->img->line_len + x * (main->img->bpp / 8));
	*(unsigned int*)dst = color;
	//main->img->addr[x * 4 + 4 * main->img->line_len * y] = color;
}

void	init_raycast(t_main *main, int x)
{
	main->ray->camerax = 2.0 * (double)(main->scr_x - 1 - x) / (double)main->scr_x - 1; //(x - main->scr_x) / (main->scr_x / 2); //x-coordinate in camera space
	//main->ray->dirx = cos(main->ray->planx) / 2 + cos(main->ray->planx - 0.25) * main->ray->camerax;
	//main->ray->diry = sin(main->ray->plany) / 2 + sin(main->ray->plany - 0.25) * main->ray->camerax;
	main->ray->mapx = (int)main->ray->posx;
	main->ray->mapy = (int)main->ray->posy;
	main->ray->raydirx = main->ray->dirx + main->ray->planx * main->ray->camerax;
	main->ray->raydiry = main->ray->diry + main->ray->plany * main->ray->camerax;
	main->ray->deltadistx = fabs(1 / main->ray->raydirx);//sqrt(1 + ((main->ray->diry * main->ray->diry) / (main->ray->dirx * main->ray->dirx)));
	main->ray->deltadisty = fabs(1 / main->ray->raydiry);//sqrt(1 + ((main->ray->dirx * main->ray->dirx) / (main->ray->diry * main->ray->diry)));
}

void	side_dist(t_main *main)
{
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
}

void	algo_dda(t_main *main)
{
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
		if (main->game->map[(int)main->ray->mapy][(int)main->ray->mapx] == '1')
		{
			
			main->ray->hit = 1;
		}
	}
}

void	wall_dist(t_main *main)
{
	if (main->ray->side == 0)
		main->ray->perpwalldist = (main->ray->mapx - main->ray->posx + (1 - main->ray->stepx) / 2) / main->ray->raydirx;
	else
		main->ray->perpwalldist = (main->ray->mapy - main->ray->posy + (1 - main->ray->stepy) / 2) / main->ray->raydiry;
	if (main->ray->side == 0)
		main->c = 0x00FF0000;
	else
		main->c = 0xFF0FF00;
	main->ray->lineheight = (int)(main->scr_y / main->ray->perpwalldist);
	main->ray->drawstart = (int)(-main->ray->lineheight / 2) + (main->scr_y / 2);
	// printf("mapx = %d\n", main->ray->mapx);
	// printf("mapy = %d\n", main->ray->mapy);
	// printf("posx = %f\n", main->ray->posx);
	// printf("posy = %f\n", main->ray->posy);
	// printf("stepx = %d\n", main->ray->stepx);
	// printf("stepy = %d\n", main->ray->stepy);
	// printf("sidedistx = %f\n", main->ray->sidedistx);
	// printf("sidedisty = %f\n", main->ray->sidedisty);
	// printf("deltadistx = %f\n", main->ray->deltadistx);
	// printf("deltadisty = %f\n", main->ray->deltadisty);
	// printf("raydirx = %f\n", main->ray->raydirx);
	// printf("raydiry = %f\n", main->ray->raydiry);
	// printf("perpwalldist = %f\n", main->ray->perpwalldist);
	// printf("lineheight = %d\n", main->ray->lineheight);
	printf("drawstart = %d\n", main->ray->drawstart);
	printf("drawsend = %d\n", main->ray->drawend);
	if (main->ray->drawstart < 0)
		main->ray->drawstart = 0;
	main->ray->drawend = (main->ray->lineheight / 2) + (main->scr_y/ 2);
	if (main->ray->drawend >= main->scr_y)
		main->ray->drawend = main->scr_y - 1;
}

void	display_texture(t_main *main, int x)
{
	int		y;

	y = 0;
	while (y < main->ray->drawstart)
	{
		//printf("Y = %d\n", y);
		my_mlx_pixel_put(main, x, y++, main->c);
	}
	y = 0;
	while (main->ray->drawend <= y && y < main->scr_y)
	{
		my_mlx_pixel_put(main, x, y++, main->c);
	}
}

int		draw_map(t_main *main)
{
	int		x;

	x = 0;
	main->ray->x = 0;
	while (x < main->scr_x)
	{
		init_raycast(main, x);
		side_dist(main);
		algo_dda(main);
		wall_dist(main);
		display_texture(main, x);
		//printf("X = %d\n", x);
		// ft_color_column(main);
		// main->ray->x++;
		// my_mlx_pixel_put(main->img, main->ray->drawstart, main->ray->drawend, main->c);
		x++;
	}
	//my_mlx_pixel_put(main->img, main->ray->drawstart, main->ray->drawend, color);
	mlx_put_image_to_window(main->game->mlx_ptr, main->game->win_ptr, main->img->mlx_img, 0, 0);
	return (0);
}
