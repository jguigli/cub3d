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

void	stock_position(int x, int y, int rep, t_main *main)
{
	if (rep == 1)
	{
		main->ray->posx = x;
		main->ray->posy = y;
	}
	else if (rep == 2)
	{

	}
	else if (rep == 3)
	{
		
	}
	else if (rep == 4)
	{
		
	}
	main->c_map->pos_ok += 1;

}

int		check_position(main)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (main->game->map[x])
	{
		while (main->game->map[x][y])
		{
			if (main->game->map[x][y] == 'N')
				stock_position(x, y, 1, main)
			else if (main->game->map[x][y] == 'S')
				stock_position(x, y, 2, main);
			else if (main->game->map[x][y] == 'E')
				stock_position(x, y, 3, main);
			else if (main->game->map[x][y] == 'W')
				stock_position(x, y, 4, main);
			y++;
		}
		x++;
	}
	if (main->c_map->pos_ok == 0)
	{
		printf("Error\nNo position specified\n");
		return (1);
	}
	else if (main->c_map->pos_ok > 1)
	{
		printf("Error\nToo much positions specified\n");
		return (1);
	}
	return (0);
}

int		manage_file_map(t_main *main, char *mapname)
{
	if (check_file_name(mapname))
		return (-1);
    main->c_map->fd = open(mapname, O_RDONLY);
	read_file(main);
	check_position(main);
	check_outline(main);
	close(main->c_map->fd);
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

void    check_texture(t_main *main)
{
	if (!ft_strncmp(main->c_map->line, "NO ", 3))
	{
		main->game->check_no = 1;
		main->game->tex_no = ft_strdup(main->c_map->line);
	}
	else if (!ft_strncmp(main->c_map->line, "SO ", 3))
	{
		main->game->check_so = 1;
		main->game->tex_so = ft_strdup(main->c_map->line);
	}
	else if (!ft_strncmp(main->c_map->line, "WE ", 3))
	{
		main->game->check_we = 1;
		main->game->tex_we = ft_strdup(main->c_map->line);
	}
	else if (!ft_strncmp(main->c_map->line, "EA ", 3))
	{
		main->game->check_ea = 1;
		main->game->tex_ea = ft_strdup(main->c_map->line);
	}
	else if (!ft_strncmp(main->c_map->line, "F ", 2))
	{
		main->game->check_f = 1;
		main->game->tex_f = ft_strdup(main->c_map->line);
	}
	else if (!ft_strncmp(main->c_map->line, "C ", 2))
	{
		main->game->check_c = 1;
		main->game->tex_c = ft_strdup(main->c_map->line);
	}
	else
		printf("Error\nWrong texture option\n");

}

void	read_file(t_main *main)
{
    main->c_map->line = get_next_line(main->c_map->fd);
    while (main->c_map->line != NULL)
    {
        if (!ft_strcmp(main->c_map->line, "\n"))
            main->c_map->line = get_next_line(main->c_map->fd);
        else
        {
			check_texture(main);
			if (check_count_texture(main))
			{
				main->c_map->line = get_next_line(main->c_map->fd);
				break ;
			}
			main->c_map->line = get_next_line(main->c_map->fd);
        }
    }
	while (main->c_map->line != NULL)
	{
		while (!ft_strcmp(main->c_map->line, "\n"))
            main->c_map->line = get_next_line(main->c_map->fd);
		main->c_map->linejoin = ft_strjoin(main->c_map->linejoin, main->c_map->line);
		main->c_map->line = get_next_line(main->c_map->fd);
	}
	parse_map(main);
}
