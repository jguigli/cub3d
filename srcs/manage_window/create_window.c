#include "../../includes/cub3d.h"

void	create_window(t_main *main)
{
	main->game->mlx_ptr = mlx_init();
	if (main->game->mlx_ptr == NULL)
	{
		//close_struct(game);
		exit(EXIT_FAILURE);
	}
	main->game->win_ptr = mlx_new_window(main->game->mlx_ptr,
			main->scr_x, main->scr_y, "CUB3D");
	if (main->game->win_ptr == NULL)
	{
		//close_struct(game);
		exit(EXIT_FAILURE);
	}
}
