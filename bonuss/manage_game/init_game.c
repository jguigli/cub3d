#include "../../includes/cub3d.h"

t_map	*initialisation_struct_map(void)
{
	t_map *c_map;

	c_map = malloc(sizeof(t_map));
	if (!c_map)
		return (NULL);
	c_map->line = NULL;
	c_map->linejoin = NULL;
	c_map->fd = 0;
	c_map->count_line = 0;
	c_map->line_max = 0;
	c_map->position = 0;
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
	game->tempmouse = 0; // BONUS
	return (game);
}

t_ray	*initialisation_struct_raycasting(void)
{
	t_ray *ray;

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
	return (ray);
}

t_xpm	*initialisation_struct_xpm(void)
{
	t_xpm	*img;

	img = malloc(sizeof(t_xpm));
	if (!img)
		return (NULL);
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	return (img);
}

t_xpm	*initialisation_struct_texture(void)
{
	t_xpm	*img;

	img = malloc(sizeof(t_xpm*) * 4);
	if (!img)
		return (NULL);
	return (img);
}

t_tex	*initialisation_struct_tex(void)
{
	t_tex	*tex;

	tex = malloc(sizeof(t_tex));
	if (!tex)
		return (NULL);
	tex->wallx = 0;
	tex->step = 0;
	tex->texpos = 0;
	tex->texX = 0;
	tex->texY = 0;
	tex->texdir = 0;
	return (tex);
}

t_main	*initialisation_struct_main(void)
{
	t_main	*main;
	int	i;
	
	i = 0;
	main = malloc(sizeof(t_main));
	if (!main)
		return (NULL);
	main->scr_x = 1600; //(int)SCREEN_W;
	main->scr_y = 1200; //(int)SCREEN_H;
	main->c = 0;
	main->f = 0;
	main->c_map = initialisation_struct_map();
	if (!main->c_map)
		return (NULL);
	main->game = initialisation_struct_game();
	if (!main->game)
		return (NULL);
	main->ray = initialisation_struct_raycasting();
	if (!main->ray)
		return (NULL);
	main->img = initialisation_struct_xpm();
	if (!main->img)
		return (NULL);
	main->texture = (t_xpm*)malloc(sizeof(t_xpm) * 4);
	if (!main->texture)
		return (NULL);
	while (i < 4)
		main->texture[i++] = (t_xpm){};
	main->tex = initialisation_struct_tex();
	if (!main->tex)
		return (NULL);
	return (main);
}
