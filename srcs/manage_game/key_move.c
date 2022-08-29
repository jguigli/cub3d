#include "../../includes/cub3d.h"

void	rotate_mouse(t_main *main) // BONUS
{
	int			ix;
	int			iy;

	ix = 0;
	iy = 0;
	mlx_mouse_get_pos(main->game->mlx_ptr, main->game->win_ptr, &ix, &iy);
	if (ix < main->scr_x / 2 && (ix - main->game->tempmouse < 5) && (ix - main->game->tempmouse > 0) && ix != main->game->tempmouse && ix > 0 && ix < main->scr_x && iy > 0 && iy < main->scr_y)
    	rotate_left_mouse(main, 2.0);
	else if (ix < main->scr_x / 2 && (ix - main->game->tempmouse < 10) && (ix - main->game->tempmouse > 5) && ix != main->game->tempmouse && ix > 0 && ix < main->scr_x && iy > 0 && iy < main->scr_y)
		rotate_left_mouse(main, 6.0);
	else if (ix < main->scr_x / 2 && (ix - main->game->tempmouse > 10) && ix != main->game->tempmouse && ix > 0 && ix < main->scr_x && iy > 0 && iy < main->scr_y)
		rotate_left_mouse(main, 8.0);
	if (ix >= main->scr_x / 2 && (main->game->tempmouse - ix < 5) && (main->game->tempmouse - ix > 0) && ix != main->game->tempmouse && ix > 0 && ix < main->scr_x && iy > 0 && iy < main->scr_y)
		rotate_right_mouse(main, 2.0);
	else if ((ix >= main->scr_x / 2 && (main->game->tempmouse - ix < 10) && (main->game->tempmouse - ix > 5) && ix != main->game->tempmouse && ix > 0 && ix < main->scr_x && iy > 0 && iy < main->scr_y))
		rotate_right_mouse(main, 6.0);
	else if ((ix >= main->scr_x / 2 && (main->game->tempmouse - ix > 10) && ix != main->game->tempmouse && ix > 0 && ix < main->scr_x && iy > 0 && iy < main->scr_y))
		rotate_right_mouse(main, 8.0);
	mlx_mouse_move(main->game->mlx_ptr, main->game->win_ptr, main->scr_x / 2, main->scr_y / 2);
	mlx_mouse_hide(main->game->mlx_ptr, main->game->win_ptr);
	main->game->tempmouse = ix;
}

int	event_key(t_main *main)
{
	if (main->game->move_forward == 1)
		move_forward(main);
	else if (main->game->move_back == 1)
		move_back(main);
	if (main->game->move_right == 1)
		move_right(main);
	else if (main->game->move_left == 1)
		move_left(main);
	if (main->game->move_rotate_left == 1)
		rotate_left(main);
	else if (main->game->move_rotate_right == 1)
		rotate_right(main);
	rotate_mouse(main);
	main->game->move_rotate_left = 0;
	main->game->move_rotate_right = 0;
	return (0);
}

int    manage_key_press(int keysym, t_main *main)
{
    if (keysym == FORWARD_W_Z)
		main->game->move_forward = 1;
	else if (keysym == BACK_S_S)
		main->game->move_back = 1;
	if (keysym == LEFT_A_Q)
		main->game->move_left = 1;
	else if (keysym == RIGHT_D_D)
		main->game->move_right = 1;
	if (keysym == ROTATE_RIGHT)
		main->game->move_rotate_right = 1;
	else if (keysym == ROTATE_LEFT)
        main->game->move_rotate_left = 1;
	if (keysym == XK_Escape)
		close_game(main);
    return (1);
}

int   manage_key_release(int keysym, t_main *main)
{
    if (keysym == FORWARD_W_Z)
		main->game->move_forward = 0;
	else if (keysym == BACK_S_S)
		main->game->move_back = 0;
	if (keysym == LEFT_A_Q)
		main->game->move_left = 0;
	else if (keysym == RIGHT_D_D)
		main->game->move_right = 0;
	if (keysym == ROTATE_RIGHT)
		main->game->move_rotate_right = 0;
	else if (keysym == ROTATE_LEFT)
        main->game->move_rotate_left = 0;
    return (1);
}
