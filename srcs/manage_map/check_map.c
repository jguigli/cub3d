#include "../../includes/cub3d.h"

// int	check_error_map2(t_data *game)
// {
// 	while (game->check_map.line != NULL)
// 	{
// 		if (check_different_length(game))
// 			return (1);
// 		if (game->check_map.count_line == 1)
// 		{
// 			if (check_first_row(game))
// 				return (1);
// 		}
// 		else if (game->check_map.count_line > 0
// 			&& game->check_map.count_line < game->check_map.line_max)
// 		{
// 			if (check_mid_row(game))
// 				return (1);
// 		}
// 		else if (game->check_map.count_line == game->check_map.line_max)
// 		{
// 			if (check_last_row(game))
// 				return (1);
// 		}
// 		free(game->check_map.line);
// 		game->check_map.line = get_next_line(game->check_map.fd);
// 		game->check_map.count_line++;
// 	}
// 	return (0);
// }

// int	check_error_map(t_data *game)
// {
// 	if (check_error_map2(game))
// 	{
// 		while (game->check_map.line)
// 		{
// 			free(game->check_map.line);
// 			game->check_map.line = get_next_line(game->check_map.fd);
// 		}
// 		close(game->check_map.fd);
// 		return (1);
// 	}
// 	free(game->check_map.line);
// 	close(game->check_map.fd);
// 	if (check_item_map(game))
// 		return (1);
// 	return (0);
// }

size_t	ft_strlen_double(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	check_first_last_row(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int		check_zero(char **map, int x, int y)
{
	if (map[x - 1][y] != '1' && map[x - 1][y] != '0')
	{
		printf("\t\terr : HAUT --> valeur = %c\n", map[x - 1][y]);
		return (1);
	}
	if (map[x + 1][y] != '1' && map[x + 1][y] != '0')
	{
		printf("\t\terr : BAS --> valeur = %i\n", map[x + 1][y]);
		return (1);
	}
	if (map[x][y - 1] != '1' && map[x][y - 1] != '0')
	{
		printf("\t\terr : GAUCHE --> valeur = %c\n", map[x][y - 1]);
		return (1);
	}
	if (map[x][y + 1] != '1' && map[x][y + 1] != '0')
	{
		printf("\t\terr : DROITE --> valeur = %c\n", map[x][y + 1]);
		return (1);
	}
	return (0);
}

int		if_map_not_good(char **map)
{
	size_t	x;
	size_t	y;
	int	error;

	x = 1;
	error = 0;
	if (check_first_last_row(map[0]) || check_first_last_row(map[ft_strlen_double(map) - 1]))
	{
		printf("first row = %s\nlast row = %s\n", map[0], map[ft_strlen_double(map) - 1]);
		error++;
	}
	while (x < ft_strlen_double(map) - 1)
	{
		printf("%s LENGTH : %ld\n", map[x], ft_strlen(map[x]));
		y = 0;
		while (map[x][y])
		{	
			//printf("%c", map[x][y]);
			if (map[x][y] == '0')
			{
				if (check_zero(map, x, y))
					error++;
			}
			y++;
		}
		x++;
	}
	if (error)
		printf("Erreur map zero : %d\n", error);
	else
		printf("Map correcte zero\n");
	return (0);
}