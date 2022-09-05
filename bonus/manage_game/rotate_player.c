#include "../../includes/cub3d_bonus.h"

void	rotate_left(t_main *main)
{
	double	olddirx;
	double	oldplanx;

	olddirx = main->ray->dirx;
	oldplanx = main->ray->planx;
	main->ray->dirx = main->ray->dirx * cos((0.033 * 1.8) / 2)
		- main->ray->diry * sin((0.033 * 1.8) / 2);
	main->ray->diry = olddirx * sin((0.033 * 1.8) / 2)
		+ main->ray->diry * cos((0.033 * 1.8) / 2);
	main->ray->planx = main->ray->planx * cos((0.033 * 1.8) / 2)
		- main->ray->plany * sin((0.033 * 1.8) / 2);
	main->ray->plany = oldplanx * sin((0.033 * 1.8) / 2)
		+ main->ray->plany * cos((0.033 * 1.8) / 2);
}

void	rotate_right(t_main *main)
{
	double	olddirx;
	double	oldplanx;

	olddirx = main->ray->dirx;
	oldplanx = main->ray->planx;
	main->ray->dirx = main->ray->dirx * cos(-(0.033 * 1.8) / 2)
		- main->ray->diry * sin(-(0.033 * 1.8) / 2);
	main->ray->diry = olddirx * sin(-(0.033 * 1.8) / 2)
		+ main->ray->diry * cos(-(0.033 * 1.8) / 2);
	main->ray->planx = main->ray->planx * cos(-(0.033 * 1.8) / 2)
		- main->ray->plany * sin(-(0.033 * 1.8) / 2);
	main->ray->plany = oldplanx * sin(-(0.033 * 1.8) / 2)
		+ main->ray->plany * cos(-(0.033 * 1.8) / 2);
}
