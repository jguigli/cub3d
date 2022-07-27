#include "../../includes/cub3d.h"

int	check_first_row(t_data *game)
{
	int		i;

	i = 0;
	while (game->check_map.line[i] != '\n')
	{
		if (game->check_map.line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_last_row(t_data *game)
{
	int		i;

	i = 0;
	while (game->check_map.line[i] != '\0')
	{
		if (game->check_map.line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_mid_row(t_data *game)
{
	int		i;

	i = 1;
	if (game->check_map.line[0] != '1'
		|| game->check_map.line[game->check_map.length - 2] != '1')
		return (1);
	while (i < game->check_map.length2 - 2)
	{
		if (game->check_map.line[i] == 'P')
			game->check_map.position++;
		else if (game->check_map.line[i] == 'E')
			game->check_map.exit++;
		else if (game->check_map.line[i] == 'C')
			game->check_map.collectible++;
		else if (game->check_map.line[i] == '0'
			|| game->check_map.line[i] == '1')
			;
		else
			return (1);
		i++;
	}
	return (0);
}

int	check_different_length(t_data *game)
{
	if (game->check_map.count_line == game->check_map.line_max)
		game->check_map.length2 = ft_strlen(game->check_map.line) + 1;
	else
		game->check_map.length2 = ft_strlen(game->check_map.line);
	if (game->check_map.length2 != game->check_map.length)
		return (1);
	return (0);
}

int	check_item_map(t_data *game)
{
	if (game->check_map.position != 1)
		return (1);
	if (game->check_map.collectible < 1 || game->check_map.exit < 1)
		return (1);
	return (0);
}