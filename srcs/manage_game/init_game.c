#include "../../includes/cub3d.h"

t_map	*initialisation_struct_map(void)
{
	t_map *c_map;

	c_map = malloc(sizeof(t_map));
	if (!c_map)
		return (NULL);
	c_map->line = NULL;
	c_map->linejoin = NULL;
	c_map->length = 0;
	c_map->length2 = 0;
	c_map->fd = 0;
	c_map->count_line = 0;
	c_map->line_max = 0;
	c_map->position = 0;
	c_map->exit = 0;
	c_map->collectible = 0;
	return (c_map);
}

t_data	*initialisation_struct_game(void)
{
	t_data *game;

	game = malloc(sizeof(t_data));
	if (!game)
		return (NULL);
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = NULL;
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
	return (game);
}

t_ray	*initialisation_struct_raycasting(void)
{
	t_ray *ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->posx = 5;
	ray->posy = 10;
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
	return (ray);
}

t_xpm	*initialisation_struct_xpm(void)
{
	t_xpm	*img;

	img = malloc(sizeof(t_xpm));
	if (!img)
		return (NULL);
	img->mlx_img= NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	return (img);
}

t_main	*initialisation_struct_main(void)
{
	t_main	*main;
	
	main = malloc(sizeof(t_main));
	if (!main)
		return (NULL);
	main->scr_x = 800;
	main->scr_y = 600;
	main->c = 0;
	main->f = 0;
	main->c_map = initialisation_struct_map(); // mettre en int
	main->game = initialisation_struct_game(); // mettre en int
	main->ray = initialisation_struct_raycasting(); // mettre en int
	main->img = initialisation_struct_xpm(); // mettre en int
	return (main);
}
