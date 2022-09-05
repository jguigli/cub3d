#include "../../includes/cub3d_bonus.h"

t_map	*initialisation_struct_map(void)
{
	t_map	*c_map;

	c_map = malloc(sizeof(t_map));
	if (!c_map)
		return (NULL);
	c_map->line = NULL;
	c_map->linejoin = NULL;
	c_map->linesize = 0;
	c_map->linesizemax = 0;
	c_map->fd = 0;
	c_map->count_line = 0;
	c_map->position = 0;
	return (c_map);
}

static void	initialisation_struct_game2(t_data *game)
{
	game->color_c = 0;
	game->pos_ok = 0;
	game->size_y = 0;
	game->size_x = 0;
	game->pos_y = 0;
	game->pos_x = 0;
	game->move_forward = 0;
	game->move_back = 0;
	game->move_right = 0;
	game->move_left = 0;
	game->move_rotate_left = 0;
	game->move_rotate_right = 0;
	game->mouse = 0;
}

t_data	*initialisation_struct_game(void)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	if (!game)
		return (NULL);
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = NULL;
	game->check_no = 0;
	game->check_so = 0;
	game->check_we = 0;
	game->check_ea = 0;
	game->check_f = 0;
	game->check_c = 0;
	game->tex_no = NULL;
	game->tex_so = NULL;
	game->tex_we = NULL;
	game->tex_ea = NULL;
	game->tex_f = NULL;
	game->tex_c = NULL;
	game->color_f = 0;
	initialisation_struct_game2(game);
	return (game);
}

static void	initialisation_struct_raycasting2(t_ray *ray)
{
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
}

t_ray	*initialisation_struct_raycasting(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->posx = 0;
	ray->posy = 0;
	ray->dirx = 0;
	ray->diry = 0;
	ray->planx = 0;
	ray->plany = 0;
	ray->raydirx = 0;
	ray->raydiry = 0;
	ray->camerax = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	initialisation_struct_raycasting2(ray);
	return (ray);
}
