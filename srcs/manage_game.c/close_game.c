#include "../../includes/cub3d.h"

void	close_struct(t_data *game)
{
	int	x;

	x = 0;
	while (x < game->size_y)
		free(game->map[x++]);
	free(game->map);
	free(game->mlx_ptr);
	free(game);
}
