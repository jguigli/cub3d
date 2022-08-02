#include "../../includes/cub3d.h"

int	get_number_line(char *mapname)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(mapname, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

void	initialisation_struct_game(t_main *main, char *mapname)
{
	main->game = malloc(sizeof(t_data));
	if (!main->game)
		return ;
	main->game->mlx_ptr = NULL;
	main->game->win_ptr = NULL;
	main->game->map = parse_map(mapname);
// 	game->size_y = 0;
// 	game->size_x = 0;
// 	count_line(game, mapname);
// 	game->pos_y = 0;
// 	game->pos_x = 0;
// 	game->count_move = 0;
// 	game->collectible_count = 0;
// 	game->check_map.line_max = get_number_line(mapname);
// 	game->check_map.fd = open(mapname, O_RDONLY);
// 	game->check_map.line = get_next_line(game->check_map.fd);
// 	game->check_map.length = ft_strlen(game->check_map.line);
// 	game->check_map.length2 = 0;
// 	game->check_map.count_line = 1;
// 	game->check_map.position = 0;
// 	game->check_map.exit = 0;
// 	game->check_map.collectible = 0;
}

void	initialisation_struct_raycasting(t_main *main)
{
	main->ray = malloc(sizeof(t_ray));
	if (!main->ray)
		return ;
	main->ray->posx = 5;
	main->ray->posy = 10;
	main->ray->dirx = -1;
	main->ray->diry = 0;
	main->ray->planx = 0;
	main->ray->plany = 0.66;
	main->ray->raydirx = 0;
	main->ray->raydiry = 0;
	main->ray->camerax = 0;
	main->ray->mapx = 0;
	main->ray->mapy = 0;
	main->ray->sidedistx = 0;
	main->ray->sidedisty = 0;
	main->ray->deltadistx = 0;
	main->ray->deltadisty = 0;
	main->ray->stepx = 0;
	main->ray->stepy = 0;
	main->ray->hit = 0;
	main->ray->side = 0;
	main->ray->perpwalldist = 0;
	main->ray->lineheight = 0;
	main->ray->drawstart = 0;
	main->ray->drawend = 0;
	main->ray->x = 0;
}

void	initialisation_struct_xpm(t_main *main)
{
	main->img = malloc(sizeof(t_xpm));
	if (!main->img)
		return ;
	main->img->mlx_img= NULL;
	main->img->addr = NULL;
	main->img->bpp = 0;
	main->img->line_len = 0;
	main->img->endian = 0;
	main->img->width = 0;
	main->img->height = 0;
}

void	initialisation_struct_main(t_main *main, char *mapname)
{
	main->scr_x = 800;
	main->scr_y = 600;
	main->c = 0;
	main->f = 0;
	initialisation_struct_game(main, mapname);
	initialisation_struct_raycasting(main);
	initialisation_struct_xpm(main);
}
