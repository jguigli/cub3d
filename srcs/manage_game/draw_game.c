#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_main *main, int x, int y, int color)
{
	int	*dst;

	dst = main->img->addr + (y * main->img->line_len + x * (main->img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	display_texture(t_main *main, int x)
{
	int		y;

	y = 0;
	while (y < main->ray->drawstart)
		main->img->addr[y++ * main->img->line_len / 4 + x] = main->game->color_c;
	if (y <= main->ray->drawend)
		texture_calculation(main, x);
	y = main->ray->drawend;
	while (y <= main->scr_y)
		main->img->addr[y++ * main->img->line_len / 4 + x] = main->game->color_f;
}

int		draw_map(t_main *main)
{
	int		x;

	x = 0;
	while (x < main->scr_x)
	{
		init_raycast(main, x);
		side_dist(main);
		algo_dda(main);
		wall_dist(main);
		get_dir_texture(main);
		display_texture(main, x);
		x++;
	}
	event_key(main);
	mlx_put_image_to_window(main->game->mlx_ptr, main->game->win_ptr, main->img->mlx_img, 0, 0);
	return (0);
}