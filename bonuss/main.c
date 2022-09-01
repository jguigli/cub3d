#include "../includes/cub3d.h"

int	main(int argc, char **argv, char **env)
{
	t_main	*main;

	main = NULL;
	if (argc != 2)
		return (error_exit(ARG));
	if (!env || !*env)
		return (error_exit(ENV));
	main = initialisation_struct_main();
	init_mlx_ptr(main);
	if (manage_file_map(main, argv[1]) == -1)
	{
		free_main(main);
		return (-1);
	}
	create_window(main);
	draw_map(main);
	manage_mlx(main);
	mlx_destroy_image(main->game->mlx_ptr, main->img->mlx_img);
	mlx_destroy_window(main->game->mlx_ptr, main->game->win_ptr);
	mlx_destroy_display(main->game->mlx_ptr);
	free_main(main);
	return (0);
}
