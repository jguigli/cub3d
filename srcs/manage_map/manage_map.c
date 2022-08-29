#include "../../includes/cub3d.h"

int		check_char(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	while (main->game->map[x])
	{
		y = 0;
		while (main->game->map[x][y])
		{
			if (main->game->map[x][y] != ' ' && main->game->map[x][y] != '0'
				&& main->game->map[x][y] != '1')
			{
				printf("Error\nWrong character in the map\n");
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		check_format(t_main *main)
{
	int	x;

	x = 0;
	while (main->game->map[x])
		x++;
	if (x < 3)
	{
		printf("Error\nWrong map format\n");
		return (1);
	}
	return (0);
}

int		check_comma_number(char *rgb)
{
	int		comma;
	int		i;

	comma = 0;
	i = 0;
	while (rgb[i])
	{
		while (rgb[i] != ',' && rgb[i])
		{
			if (!ft_isdigit(rgb[i]) && rgb[i] != ' ')
			{
				if ((rgb[i] == ' ' || rgb[i] == 9) && comma > 1
					&& (ft_isdigit(rgb[i - 1]) || rgb[i - 1] == ' '
					|| rgb[i - 1] == 9) && (rgb[i + 1] == ' '
					|| rgb[i + 1] == 9 || rgb[i + 1] == '\0'))
					;
				else
				{
					printf("Error\nWrong character in rgb floor/ceilling\n");
					return (1);
				}
			}
			i++;
		}
		if (rgb[i] == ',')
			comma++;
		if (rgb[i] == ',' && rgb[i + 1] == '\0' && comma == 2)
		{
			printf("Error\nMissing number after comma in rgb floor/ceilling\n");
			return (1);
		}
		if (rgb[i] == '\0' && comma < 2)
		{
			printf("Error\nIncorrect number of number in rgb floor/ceilling\n");
			return (1);
		}
		if (rgb[i] != '\0')
			i++;
	}
	if (comma > 2)
	{
		printf("Error\nIncorrect number of comma in rgb floor/ceilling \n");
		return (1);
	}
	return (0);
}

int		manage_file_map(t_main *main, char *mapname)
{
	if (check_file_name(mapname))
		return (-1);
    main->c_map->fd = open(mapname, O_RDONLY);
	if (read_file(main))
		return (-1);
	if (check_format(main))
		return (-1);
	if (check_position(main))
		return (-1);
	if (check_char(main))
		return (-1);
	if (check_outline(main->game->map))
		return (-1);
	if (check_color(main))
		return (-1);
	close(main->c_map->fd);
	return (0);
}
