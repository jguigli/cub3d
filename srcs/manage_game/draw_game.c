#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_main *main, int x, int y, int color)
{
	char	*dst;

	dst = main->img->addr + (y * main->img->line_len + x * (main->img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	display_texture(t_main *main, int x)
{
	int		y;

	y = 0;
	if (main->ray->side == 0)
		main->c = 0x808080;
	else
		main->c = 0xD3D3D3;
	while (y < main->ray->drawstart)
		my_mlx_pixel_put(main, x, y++, main->game->color_c);
	while (y < main->ray->drawend)
		my_mlx_pixel_put(main, x, y++, main->c);
	while (y <= main->scr_y)
		my_mlx_pixel_put(main, x, y++, main->game->color_f);
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
		display_texture(main, x);
		x++;
	}
	event_key(main);
	mlx_put_image_to_window(main->game->mlx_ptr, main->game->win_ptr, main->img->mlx_img, 0, 0);
	return (0);
}