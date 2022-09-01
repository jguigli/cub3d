#include "../../includes/cub3d.h"

void	create_window(t_main *main)
{
	main->game->win_ptr = mlx_new_window(main->game->mlx_ptr,
			main->scr_x, main->scr_y, "CUB3D");
	if (main->game->win_ptr == NULL)
	{
		free_main(main);
		exit(EXIT_FAILURE);
	}
	main->img->mlx_img = mlx_new_image(main->game->mlx_ptr, main->scr_x, main->scr_y);
	main->img->addr = (int*)mlx_get_data_addr(main->img->mlx_img, &main->img->bpp, &main->img->line_len, &main->img->endian);
}

void	manage_mlx(t_main *main)
{
	mlx_hook(main->game->win_ptr, 2, 1L << 0, manage_key_press, main);
	mlx_loop_hook(main->game->mlx_ptr, draw_map, main);
	//mlx_loop_hook(main->game->mlx_ptr, draw_minimap, main);
	mlx_hook(main->game->win_ptr, 3, 1L << 1, manage_key_release, main);
	mlx_hook(main->game->win_ptr, DestroyNotify,
		StructureNotifyMask, exit_escape, main);
	mlx_loop(main->game->mlx_ptr);
}
