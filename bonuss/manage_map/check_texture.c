#include "../../includes/cub3d.h"

int		check_count_texture(t_main *main)
{
	int		count;

	count = main->game->check_no + main->game->check_so
			+ main->game->check_we + main->game->check_ea
			+ main->game->check_f + main->game->check_c;
	if (count == 6)
	{
		main->c_map->line = get_next_line(main->c_map->fd);
		return (1);
	}
	return (0);
}

char	*crop_texture_side(t_main *main)
{
	char	*str;
	int		i;
	int		j;

	i = 2;
	while (main->c_map->line[i] == ' ')
		i++;
	j = i;
	while (main->c_map->line[j])
		j++;
	str = ft_substr(main->c_map->line, i, j - i - 1);
	return (str);
}

char	*crop_texture_high(t_main *main)
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	while (main->c_map->line[i] == ' ')
		i++;
	j = i;
	while (main->c_map->line[j])
		j++;
	str = ft_substr(main->c_map->line, i, j - i - 1);
	return (str);
}

int		check_texture(t_main *main)
{
	if (!ft_strncmp(main->c_map->line, "NO ", 3))
	{
		if (main->game->check_no == 1)
			return (error_exit(NTEXMEN));
		main->game->check_no += 1;
		main->game->tex_no = crop_texture_side(main);
	}
	else if (!ft_strncmp(main->c_map->line, "SO ", 3))
	{
		if (main->game->check_so == 1)
			return (error_exit(STEXMEN));
		main->game->check_so += 1;
		main->game->tex_so = crop_texture_side(main);
	}
	else if (!ft_strncmp(main->c_map->line, "WE ", 3))
	{
		if (main->game->check_we == 1)
			return (error_exit(WTEXMEN));
		main->game->check_we += 1;
		main->game->tex_we = crop_texture_side(main);
	}
	else if (!ft_strncmp(main->c_map->line, "EA ", 3))
	{
		if (main->game->check_ea == 1)
			return (error_exit(ETEXMEN));
		main->game->check_ea += 1;
		main->game->tex_ea = crop_texture_side(main);
	}
	else if (!ft_strncmp(main->c_map->line, "F ", 2))
	{
		if (main->game->check_f == 1)
			return (error_exit(FTEXMEN));
		main->game->check_f += 1;
		main->game->tex_f = crop_texture_high(main);
	}
	else if (!ft_strncmp(main->c_map->line, "C ", 2))
	{
		if (main->game->check_c == 1)
			return (error_exit(CTEXMEN));
		main->game->check_c += 1;
		main->game->tex_c = crop_texture_high(main);
	}
	else
		return (error_exit(TEXOPT));
	return (0);

}
