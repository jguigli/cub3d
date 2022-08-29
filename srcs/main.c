#include "../includes/cub3d.h"

int	handle_cross(t_data *game)
{
	mlx_loop_end(game->mlx_ptr);
	//close_game(game);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_main	*main;

	if (argc != 2)
	{
		printf("Error\nIncorrect number of arguments\n");
		return (-1);
	}
	if (!env || !*env)
	{
		printf("Error\nEmpty environnement\n");
		return (-1);
	}
	main = initialisation_struct_main();
	create_window(main);
	if (manage_file_map(main, argv[1]) == -1)
		return (-1);
	/******/
	main->img->mlx_img = mlx_new_image(main->game->mlx_ptr, main->scr_x, main->scr_y);
	main->img->addr = mlx_get_data_addr(main->img->mlx_img, &main->img->bpp, &main->img->line_len, &main->img->endian);
	/******/
	draw_map(main);
	// launch_game(game);
	mlx_hook(main->game->win_ptr, 2, 1L << 0, manage_key_press, main);
	mlx_loop_hook(main->game->mlx_ptr, draw_map, main);
	mlx_hook(main->game->win_ptr, 3, 1L << 1, manage_key_release, main);
	//mlx_key_hook(main->game->win_ptr, event_key, main);
	mlx_hook(main->game->win_ptr, DestroyNotify,
		StructureNotifyMask, handle_cross, main->game);
	// mlx_key_hook(game->win_ptr, event_key, game);
	mlx_loop(main->game->mlx_ptr);
	//free(game);
	return (0);
}
