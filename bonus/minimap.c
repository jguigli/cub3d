#include "../includes/cub3d.h"

void	draw_player(t_main *main)
{
	int		pixelx;
	int		pixely;
	int     colorplayer;

	colorplayer = 0x00FF00;
	pixelx = 2;
    while (pixelx < 6)
	{
		pixely = 3;
		while (pixely < 6)
		{
			main->img->addr[(pixely + (int)main->ray->posx * 8) * main->img->line_len
				/ 4 + (pixelx + (int)main->ray->posy * 8)] = colorplayer;
			pixely++;
		}
		pixelx++;
	}
}

static void    draw_square(t_main *main, int *color, int x, int y)
{
    int		pixelx;
	int		pixely;

	pixelx = 0;
    while (pixelx < 10)
	{
		pixely = 0;
		while (pixely < 10)
		{
			main->img->addr[(pixely + y * 8) * main->img->line_len / 4 + (pixelx + x * 8)] = *color;
			pixely++;
		}
		pixelx++;
	}
}

int	draw_minimap(t_main *main)
{
	int		x;
	int		y;
	int     colorwall;
	int     colorfloor;


	colorwall = 0xFF0000;
	colorfloor = 0x080808;
	y = 0;
	while (main->game->map[y])
	{
		x = 0;
		while (main->game->map[y][x])
		{
			if (main->game->map[y][x] == '1')
				draw_square(main, &colorwall, x, y);
			if (main->game->map[y][x] == '0')
				draw_square(main, &colorfloor, x, y);
			x++;
		}
		y++;
	}
	draw_player(main);
	return (0);
}