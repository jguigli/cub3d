#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	char    **map;

	if (argc == 2)
	{
		map = parse_map(argv[1]);
		if_map_not_good(map);
    }



	// t_data	*game;

	// game = malloc(sizeof(t_data));
	// if (!game)
	// 	return (-1);
	// initialisation_struct_game(game, argv[1]);
	// if (check_error(argc, argv, game))
	// {
	// 	close_struct(game);
	// 	return (-1);
	// }
	// create_window(game);
	// launch_game(game);
	// mlx_hook(game->win_ptr, DestroyNotify,
	// 	StructureNotifyMask, handle_cross, game);
	// mlx_key_hook(game->win_ptr, event_key, game);
	// mlx_loop(game->mlx_ptr);
	// free(game);
	return (0);
}
