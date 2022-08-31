#include "../../includes/cub3d.h"

void    init_mlx_ptr(t_main *main)
{
	main->game->mlx_ptr = mlx_init();
	if (main->game->mlx_ptr == NULL)
	{
		exit(EXIT_FAILURE);
	}
}
