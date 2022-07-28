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

void	initialisation_struct_game(t_data *game, char *mapname)
{
	(void)mapname;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = parse_map(mapname);
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

void	initialisation_struct_raycasting(t_ray *ray)
{
	ray->posx = 5;
	ray->posy = 5;
	ray->dirx = -1;
	ray->diry = 0;
	ray->planx = 0;
	ray->plany = 0.66;
	ray->raydirx = 0;
	ray->raydiry = 0;
	ray->camerax = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perpwalldist = 0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->x = 0;
}
