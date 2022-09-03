#include "../../includes/cub3d.h"

void	fill_map(t_main *main)
{
	size_t		x;
	size_t		y;

	x = 0;
	while (main->game->map[x])
	{
		y = 0;
		while (main->game->map[x][y])
		{
			if (main->game->map[x][y] == ' ')
				main->game->map[x][y] = '1';
			y++;
		}
		x++;
	}
	x = 0;
	while (main->game->map[x])
	{
		y = ft_strlen(main->game->map[x]);
		if (y < main->c_map->linesizemax)
		{
			while (y < main->c_map->linesizemax)
			{
				main->game->map[x][y] = '1';
				y++;
			}
		}
		main->game->map[x][y] = '\0';
		x++;
	}
}

void	affiche(t_main *main) // A SUPP
{
	int	x = 0;
	while (main->game->map[x])
	{
		printf("%s\n", main->game->map[x]);
		x++;
	}
}

void	parse_map(t_main *main)
{
	main->game->map = ft_split_map(main, main->c_map->linejoin);
	// affiche(main);
	free (main->c_map->linejoin);
}