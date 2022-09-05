/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:46:26 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:46:28 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	return (0);
}

int	manage_key_press(int keysym, t_main *main)
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
		exit_escape(main);
	return (1);
}

int	manage_key_release(int keysym, t_main *main)
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
