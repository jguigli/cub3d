#include "../../includes/cub3d_bonus.h"

int	check_count_texture(t_main *main)
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
	while (main->c_map->line[j] != ' ' && main->c_map->line[j] != '\n')
		j++;
	str = ft_substr(main->c_map->line, i, j - i);
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
	while (main->c_map->line[j] && main->c_map->line[j] != '\n')
		j++;
	str = ft_substr(main->c_map->line, i, j - i);
	return (str);
}

int	check_texture(t_main *main)
{
	if (check_texture_one(main) == 2)
		return (0);
	else if (check_texture_one(main) == 1)
		return (1);
	else if (!check_texture_one(main))
	{
		if (check_texture_two(main) == 2)
			return (0);
		else if (check_texture_two(main) == 1)
			return (1);
		else if (!check_texture_two(main))
			return (error_exit(TEXOPT));
	}
	return (0);
}
