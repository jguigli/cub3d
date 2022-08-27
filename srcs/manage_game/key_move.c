#include "../../includes/cub3d.h"

int    manage_key_press(int keysym, t_main *main)
{
    if (keysym == FORWARD_W_Z)
		main->game->move_forward = 1;
	else if (keysym == BACK_S_S)
		main->game->move_back = 1;
	else if (keysym == LEFT_A_Q)
		main->game->move_left = 1;
	else if (keysym == RIGHT_D_D)
		main->game->move_right = 1;
	else if (keysym == ROTATE_RIGHT)
		main->game->move_rotate_right = 1;
	else if (keysym == ROTATE_LEFT)
        main->game->move_rotate_left = 1;
    return (1);
}

int   manage_key_release(int keysym, t_main *main)
{
    if (keysym == FORWARD_W_Z)
		main->game->move_forward = 0;
	else if (keysym == BACK_S_S)
		main->game->move_back = 0;
	else if (keysym == LEFT_A_Q)
		main->game->move_left = 0;
	else if (keysym == RIGHT_D_D)
		main->game->move_right = 0;
	else if (keysym == ROTATE_RIGHT)
		main->game->move_rotate_right = 0;
	else if (keysym == ROTATE_LEFT)
        main->game->move_rotate_left = 0;
    return (1);
}
