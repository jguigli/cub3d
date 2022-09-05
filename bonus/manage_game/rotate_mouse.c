#include "../../includes/cub3d_bonus.h"

void	mrcondition(t_main *main, int ix, int iy)
{
	if (ix >= main->scr_x / 2 && (main->game->mouse - ix < 5)
		&& (main->game->mouse - ix > 0) && ix != main->game->mouse && ix > 0
		&& ix < main->scr_x && iy > 0 && iy < main->scr_y)
		rotate_right_mouse(main, 2.0);
	else if ((ix >= main->scr_x / 2 && (main->game->mouse - ix < 10)
			&& (main->game->mouse - ix > 5) && ix != main->game->mouse && ix > 0
			&& ix < main->scr_x && iy > 0 && iy < main->scr_y))
		rotate_right_mouse(main, 4.0);
	else if ((ix >= main->scr_x / 2 && (main->game->mouse - ix > 10)
			&& ix != main->game->mouse && ix > 0 && ix < main->scr_x && iy > 0
			&& iy < main->scr_y))
		rotate_right_mouse(main, 6.0);
}

void	mlcondition(t_main *main, int ix, int iy)
{
	if (ix < main->scr_x / 2 && (ix - main->game->mouse < 5)
		&& (ix - main->game->mouse > 0) && ix != main->game->mouse && ix > 0
		&& ix < main->scr_x && iy > 0 && iy < main->scr_y)
		rotate_left_mouse(main, 2.0);
	else if (ix < main->scr_x / 2 && (ix - main->game->mouse < 10)
		&& (ix - main->game->mouse > 5) && ix != main->game->mouse && ix > 0
		&& ix < main->scr_x && iy > 0 && iy < main->scr_y)
		rotate_left_mouse(main, 4.0);
	else if (ix < main->scr_x / 2 && (ix - main->game->mouse > 10)
		&& ix != main->game->mouse && ix > 0 && ix < main->scr_x && iy > 0
		&& iy < main->scr_y)
		rotate_left_mouse(main, 6.0);
}

void	rotate_mouse(t_main *main)
{
	int			ix;
	int			iy;

	ix = 0;
	iy = 0;
	mlx_mouse_get_pos(main->game->mlx_ptr, main->game->win_ptr, &ix, &iy);
	mlcondition(main, ix, iy);
	mrcondition(main, ix, iy);
	mlx_mouse_move(main->game->mlx_ptr, main->game->win_ptr,
		main->scr_x / 2, main->scr_y / 2);
	mlx_mouse_hide(main->game->mlx_ptr, main->game->win_ptr);
	main->game->mouse = ix;
}

void	rotate_left_mouse(t_main *main, double rotaspeed)
{
	double	olddirx;
	double	oldplanx;

	olddirx = main->ray->dirx;
	oldplanx = main->ray->planx;
	main->ray->dirx = main->ray->dirx * cos((0.033 * rotaspeed) / 2)
		- main->ray->diry * sin((0.033 * rotaspeed) / 2);
	main->ray->diry = olddirx * sin((0.033 * rotaspeed) / 2)
		+ main->ray->diry * cos((0.033 * rotaspeed) / 2);
	main->ray->planx = main->ray->planx * cos((0.033 * rotaspeed) / 2)
		- main->ray->plany * sin((0.033 * rotaspeed) / 2);
	main->ray->plany = oldplanx * sin((0.033 * rotaspeed) / 2)
		+ main->ray->plany * cos((0.033 * rotaspeed) / 2);
}

void	rotate_right_mouse(t_main *main, double rotaspeed)
{
	double	olddirx;
	double	oldplanx;

	olddirx = main->ray->dirx;
	oldplanx = main->ray->planx;
	main->ray->dirx = main->ray->dirx * cos(-(0.033 * rotaspeed) / 2)
		- main->ray->diry * sin(-(0.033 * rotaspeed) / 2);
	main->ray->diry = olddirx * sin(-(0.033 * rotaspeed) / 2)
		+ main->ray->diry * cos(-(0.033 * rotaspeed) / 2);
	main->ray->planx = main->ray->planx * cos(-(0.033 * rotaspeed) / 2)
		- main->ray->plany * sin(-(0.033 * rotaspeed) / 2);
	main->ray->plany = oldplanx * sin(-(0.033 * rotaspeed) / 2)
		+ main->ray->plany * cos(-(0.033 * rotaspeed) / 2);
}
