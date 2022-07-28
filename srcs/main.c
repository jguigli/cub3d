#include "../includes/cub3d.h"

int	handle_cross(t_data *game)
{
	mlx_loop_end(game->mlx_ptr);
	//close_game(game);
	return (0);
}

void	my_mlx_pixel_put(t_xpm *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_map(t_ray *r, t_xpm *img, t_data *game)
{
	int		x;
	int		y;
	int		color;

	x = 0;
	y = 0;
	color = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			r->camerax = (x - SCREEN_W) / (SCREEN_W / 2); //x-coordinate in camera space
			r->dirx = cos(r->planx) / 2 + cos(r->planx - 0.25) * r->camerax;
			r->diry = sin(r->plany) / 2 + sin(r->plany - 0.25) * r->camerax;
			r->mapx = floor(r->posx);
			r->mapy = floor(r->posy);
			r->deltadistx = sqrt(1 + ((r->diry * r->diry) / (r->dirx * r->dirx)));
			r->deltadisty = sqrt(1 + ((r->dirx * r->dirx) / (r->diry * r->diry)));
			r->raydirx = r->dirx + r->planx * r->camerax;
			r->raydiry = r->diry + r->plany * r->camerax;

			if (r->dirx < 0)
			{
				r->stepx = -1;
				r->sidedistx = (r->posx - r->mapx) * r->deltadistx;
			}
			else
			{
				r->stepx = 1;
				r->sidedistx = (r->mapx + 1 - r->posx) * r->deltadistx;
			}
			if (r->diry < 0)
			{
				r->stepy = -1;
				r->sidedisty = (r->posy - r->mapy) * r->deltadisty;
			}
			else
			{
				r->stepy = 1;
				r->sidedisty = (r->mapy + 1 - r->posy) * r->deltadisty;
			}

			r->hit = 0;
			while (r->hit == 0)
			{
				if (r->sidedistx < r->sidedisty)
				{
					r->sidedistx += r->deltadistx;
					r->mapx += r->stepx;
					r->side = 0;
				}
				else
				{
					r->sidedisty += r->deltadisty;
					r->mapy += r->stepy;
					r->side = 1;
				}
				if (game->map[r->mapy][r->mapx] != 0)
					r->hit = 1;
			}
			if (r->side == 0)
				r->perpwalldist = (r->mapx - r->posx + (1 - r->stepx) / 2) / r->dirx;
			else
				r->perpwalldist = (r->mapy - r->posy + (1 - r->stepy) / 2) / r->diry;
			if (r->side == 0)
				color = 0x00FF0000;
			else
				color = 0x0000FF00;
			my_mlx_pixel_put(img, x, y, color);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->mlx_img, x, y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	char    **map;
	t_data	*game;
	t_ray	*ray;
	t_xpm	*img;


	if (argc == 2)
	{
		map = parse_map(argv[1]);
		if_map_not_good(map);
    }
	game = malloc(sizeof(t_data));
	if (!game)
		return (-1);
	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (-1);
	img = malloc(sizeof(t_xpm));
	if (!img)
		return (-1);
	initialisation_struct_game(game, argv[1]);
	initialisation_struct_raycasting(ray);
	create_window(game);
	/******/
	img->mlx_img = mlx_new_image(game->mlx_ptr, SCREEN_W, SCREEN_W);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	/******/
	draw_map(ray, img, game);
	// launch_game(game);
	mlx_hook(game->win_ptr, DestroyNotify,
		StructureNotifyMask, handle_cross, game);
	// mlx_key_hook(game->win_ptr, event_key, game);
	mlx_loop(game->mlx_ptr);
	free(game);
	return (0);
}
