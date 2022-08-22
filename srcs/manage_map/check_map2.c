#include "../../includes/cub3d.h"

// int	check_mid_row(t_data *game)
// {
// 	int		i;

// 	i = 1;
// 	if (game->check_map.line[0] != '1'
// 		|| game->check_map.line[game->check_map.length - 2] != '1')
// 		return (1);
// 	while (i < game->check_map.length2 - 2)
// 	{
// 		if (game->check_map.line[i] == 'P')
// 			game->check_map.position++;
// 		else if (game->check_map.line[i] == 'E')
// 			game->check_map.exit++;
// 		else if (game->check_map.line[i] == 'C')
// 			game->check_map.collectible++;
// 		else if (game->check_map.line[i] == '0'
// 			|| game->check_map.line[i] == '1')
// 			;
// 		else
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

void	stock_position_north(int x, int y, t_main *main)
{
	main->game->map[x][y] = '0';
	main->ray->posx = x;
	main->ray->posy = y;
	main->ray->dirx = -1;
	main->ray->diry = 0;
	main->ray->planx = 0;
	main->ray->plany = 0.66;
	main->game->pos_ok += 1;
}

void	stock_position_south(int x, int y, t_main *main)
{
	main->game->map[x][y] = '0';
	main->ray->posx = x;
	main->ray->posy = y;
	main->ray->dirx = 1;
	main->ray->diry = 0;
	main->ray->planx = 0;
	main->ray->plany = -0.66;
	main->game->pos_ok += 1;
}

void	stock_position_east(int x, int y, t_main *main)
{
	main->game->map[x][y] = '0';
	main->ray->posx = x;
	main->ray->posy = y;
	main->ray->dirx = 0;
	main->ray->diry = 1;
	main->ray->planx = 0.66;
	main->ray->plany = 0;
	main->game->pos_ok += 1;
}

void	stock_position_west(int x, int y, t_main *main)
{
	main->game->map[x][y] = '0';
	main->ray->posx = x;
	main->ray->posy = y;
	main->ray->dirx = 0;
	main->ray->diry = -1;
	main->ray->planx = -0.66;
	main->ray->plany = 0;
	main->game->pos_ok += 1;
}

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

int		check_position(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	while (main->game->map[x])
	{
		y = 0;
		while (main->game->map[x][y])
		{
			if (main->game->map[x][y] == 'N')
				stock_position_north(x, y, main);
			else if (main->game->map[x][y] == 'S')
				stock_position_south(x, y, main);
			else if (main->game->map[x][y] == 'E')
				stock_position_east(x, y, main);
			else if (main->game->map[x][y] == 'W')
				stock_position_west(x, y, main);
			y++;
		}
		x++;
	}
	if (main->game->pos_ok == 0)
	{
		printf("Error\nNo position specified\n");
		return (1);
	}
	else if (main->game->pos_ok > 1)
	{
		printf("Error\nToo much positions specified\n");
		return (1);
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

int	create_trgb_floor(t_main *main)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;

	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_trgb_ceilling(t_main *main)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	
	return (t << 24 | r << 16 | g << 8 | b);
}

int		manage_rgb(t_main *main)
{
	main->color_f = create_trgb(main);
	main->color_c = create_trgb(main);
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
	manage_rgb(main);
	close(main->c_map->fd);
	printf("texture N = %s\n", main->game->tex_no);
	printf("texture S = %s\n", main->game->tex_so);
	printf("texture E = %s\n", main->game->tex_ea);
	printf("texture W = %s\n", main->game->tex_we);
	printf("texture F = %s\n", main->game->tex_f);
	printf("texture C = %s\n", main->game->tex_c);
	return (0);
}

int		check_count_texture(t_main *main)
{
	int		count;

	count = main->game->check_no + main->game->check_so
			+ main->game->check_we + main->game->check_ea
			+ main->game->check_f + main->game->check_c;
	if (count == 6)
		return (1);
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
	str = ft_substr(main->c_map->line, i, j);
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
	str = ft_substr(main->c_map->line, i, j);
	return (str);
}

int		check_texture(t_main *main)
{
	if (!ft_strncmp(main->c_map->line, "NO ", 3))
	{
		if (main->game->check_no == 1)
		{
			printf("Error\nNorth texture mentioned several times\n");
			return (1);
		}
		main->game->check_no += 1;
		main->game->tex_no = crop_texture_side(main);
	}
	else if (!ft_strncmp(main->c_map->line, "SO ", 3))
	{
		if (main->game->check_so == 1)
		{
			printf("Error\nSouth texture mentioned several times\n");
			return (1);
		}
		main->game->check_so += 1;
		main->game->tex_so = crop_texture_side(main);
	}
	else if (!ft_strncmp(main->c_map->line, "WE ", 3))
	{
		if (main->game->check_we == 1)
		{
			printf("Error\nWest texture mentioned several times\n");
			return (1);
		}
		main->game->check_we += 1;
		main->game->tex_we = crop_texture_side(main);
	}
	else if (!ft_strncmp(main->c_map->line, "EA ", 3))
	{
		if (main->game->check_ea == 1)
		{
			printf("Error\nEast texture mentioned several times\n");
			return (1);
		}
		main->game->check_ea += 1;
		main->game->tex_ea = crop_texture_side(main);
	}
	else if (!ft_strncmp(main->c_map->line, "F ", 2))
	{
		if (main->game->check_f == 1)
		{
			printf("Error\nFloor texture mentioned several times\n");
			return (1);
		}
		main->game->check_f += 1;
		main->game->tex_f = crop_texture_high(main);
	}
	else if (!ft_strncmp(main->c_map->line, "C ", 2))
	{
		if (main->game->check_c == 1)
		{
			printf("Error\nCeilling texture mentioned several times\n");
			return (1);
		}
		main->game->check_c += 1;
		main->game->tex_c = crop_texture_high(main);
	}
	else
	{
		printf("%s\n", main->c_map->line);
		printf("Error\nWrong texture option in file\n");
		return (1);
	}
	return (0);

}

int		read_file(t_main *main)
{
    main->c_map->line = get_next_line(main->c_map->fd);
    while (main->c_map->line != NULL)
    {
        if (!ft_strcmp(main->c_map->line, "\n"))
		{
            main->c_map->line = get_next_line(main->c_map->fd);
			if ((main->c_map->line[0] == '1' || main->c_map->line[0] == '0'
				|| main->c_map->line[0] == ' ') && !check_count_texture(main))
			{
				printf("Error\nOne or several textures are missing\n");
				return (1);
			}
		}
        else
        {
			if (check_texture(main))
				return (1);
			if (check_count_texture(main))
			{
				main->c_map->line = get_next_line(main->c_map->fd);
				break ;
			}
			main->c_map->line = get_next_line(main->c_map->fd);
			if ((main->c_map->line[0] == '1' || main->c_map->line[0] == '0'
				|| main->c_map->line[0] == ' ') && !check_count_texture(main))
			{
				printf("Error\nOne or several textures are missing\n");
				return (1);
			}
        }
    }
	while (main->c_map->line != NULL)
	{
		while (!ft_strcmp(main->c_map->line, "\n"))
		{
            main->c_map->line = get_next_line(main->c_map->fd);
			if (main->c_map->line == NULL)
			{
				printf("Error\nThe map is missing\n");
				return (1);
			}
		}
		main->c_map->linejoin = ft_strjoin(main->c_map->linejoin, main->c_map->line);
		main->c_map->line = get_next_line(main->c_map->fd);
	}
	parse_map(main);
	return (0);
}
