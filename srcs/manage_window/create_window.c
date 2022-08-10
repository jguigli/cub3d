#include "../../includes/cub3d.h"

// void	count_line(t_data *game, char *mapname)
// {
// 	int		fd;
// 	char	*line;
// 	int		count;

// 	count = 0;
// 	fd = open(mapname, O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line[count])
// 	{
// 		game->size_x++;
// 		count++;
// 	}
// 	while (line)
// 	{
// 		game->size_y++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	game->size_x--;
// 	close (fd);
// }

void	create_window(t_main *main)
{
	main->game->mlx_ptr = mlx_init();
	if (main->game->mlx_ptr == NULL)
	{
		//close_struct(game);
		exit(EXIT_FAILURE);
	}
	main->game->win_ptr = mlx_new_window(main->game->mlx_ptr,
			SCREEN_W, SCREEN_H, "CUB3D");
	if (main->game->win_ptr == NULL)
	{
		//close_struct(game);
		exit(EXIT_FAILURE);
	}
}