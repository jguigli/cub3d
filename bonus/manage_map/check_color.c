/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:32 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:55:34 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	check_color_rgb_floor(t_main *main, int i, int y, int s)
{
	char	*temp;

	temp = ft_substr(main->game->tex_f, y, i - y);
	if (i == y || have_only_space(temp))
		return (free (temp), error_exit(MISSRGB));
	temp = ft_strtrim(temp, " ");
	if (space_inside(temp))
		return (free (temp), error_exit(RGBSPACE));
	main->game->rgb_f[s] = ft_atoi(temp);
	free (temp);
	return (0);
}

int	check_color_rgb_ceilling(t_main *main, int i, int y, int s)
{
	char	*temp;

	temp = ft_substr(main->game->tex_c, y, i - y);
	if (i == y || have_only_space(temp))
		return (free (temp), error_exit(MISSRGB));
	temp = ft_strtrim(temp, " ");
	if (space_inside(temp))
		return (free (temp), error_exit(RGBSPACE));
	main->game->rgb_c[s] = ft_atoi(temp);
	free (temp);
	return (0);
}

int	check_color_floor(t_main *main)
{
	int		i;
	int		y;
	int		s;

	i = 0;
	s = 0;
	while (main->game->tex_f[i])
	{
		y = i;
		while (main->game->tex_f[i] != ',' && main->game->tex_f[i])
			i++;
		if (check_color_rgb_floor(main, i, y, s))
			return (1);
		if (main->game->rgb_f[s] > 255 || main->game->rgb_f[s] < 0)
			return (error_exit(FRGBSCALE));
		s++;
		if (main->game->tex_f[i] == ',')
			i++;
		else
			break ;
	}
	return (0);
}

int	check_color_ceilling(t_main *main)
{
	int		i;
	int		y;
	int		s;

	i = 0;
	s = 0;
	while (main->game->tex_c[i])
	{
		y = i;
		while (main->game->tex_c[i] != ',' && main->game->tex_c[i])
			i++;
		if (check_color_rgb_ceilling(main, i, y, s))
			return (1);
		if (main->game->rgb_c[s] > 255 || main->game->rgb_c[s] < 0)
			return (error_exit(CRGBSCALE));
		s++;
		if (main->game->tex_c[i] == ',')
			i++;
		else
			break ;
	}
	return (0);
}

int	check_color(t_main *main)
{
	if (get_texture(main))
		return (1);
	if (get_addr_texture(main))
		return (exit_texture(main));
	if (check_comma_number(main->game->tex_f))
		return (exit_texture(main));
	if (check_comma_number(main->game->tex_c))
		return (exit_texture(main));
	if (check_color_floor(main))
		return (exit_texture(main));
	if (check_color_ceilling(main))
		return (exit_texture(main));
	main->game->color_f = create_trgb(main->game->rgb_f[0],
			main->game->rgb_f[1], main->game->rgb_f[2]);
	main->game->color_c = create_trgb(main->game->rgb_c[0],
			main->game->rgb_c[1], main->game->rgb_c[2]);
	return (0);
}
