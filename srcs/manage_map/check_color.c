#include "../../includes/cub3d.h"

int	create_trgb(int r, int g, int b)
{
	int		t;

	t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}

int		space_inside(char *temp)
{
	int		i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		check_color_floor(t_main *main)
{
	int		i;
	int		y;
	int		s;
	char	*temp;

	i = 0;
	s = 0;
	while (main->game->tex_f[i])
	{
		y = i;
		while (main->game->tex_f[i] != ',' && main->game->tex_f[i])
			i++;
		temp = ft_substr(main->game->tex_f, y, i - y);
		temp = ft_strtrim(temp, " ");
		if (space_inside(temp))
			return (error_exit(RGBSPACE));
		main->game->rgb_f[s] = ft_atoi(temp);
		free (temp);
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

int		check_color_ceilling(t_main *main)
{
	int		i;
	int		y;
	int		s;
	char	*temp;

	i = 0;
	s = 0;
	while (main->game->tex_c[i])
	{
		y = i;
		while (main->game->tex_c[i] != ',' && main->game->tex_c[i])
			i++;
		temp = ft_substr(main->game->tex_c, y, i - y);
		temp = ft_strtrim(temp, " ");
		if (space_inside(temp))
			return (error_exit(RGBSPACE));
		main->game->rgb_c[s] = ft_atoi(temp);
		free (temp);
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

int		check_color(t_main *main)
{

	if (get_texture(main))
		return (1);
	if (get_addr_texture(main))
		return (1);
	if (check_comma_number(main->game->tex_f))
		return (1);
	if (check_comma_number(main->game->tex_c))
		return (1);
	if (check_color_floor(main))
		return (1);
	if (check_color_ceilling(main))
		return (1);
	main->game->color_f = create_trgb(main->game->rgb_f[0],
		main->game->rgb_f[1], main->game->rgb_f[2]);
	main->game->color_c = create_trgb(main->game->rgb_c[0],
		main->game->rgb_c[1], main->game->rgb_c[2]);
	return (0);
}
