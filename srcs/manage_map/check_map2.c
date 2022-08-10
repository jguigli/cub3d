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

int		manage_file_map(t_main *main, char *mapname)
{
	if (check_file_name(mapname))
		return (-1);
    main->c_map->fd = open(mapname, O_RDONLY);
	read_file(main);
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
	if (strncmp(main->c_map->line, "NO ", 2))
	{
		main->game->check_no = 1;
		main->game->tex_no = ft_strdup(main->c_map->line);
	}
	else if (strncmp(main->c_map->line, "SO ", 2))
	{
		main->game->check_so = 1;
		main->game->tex_so = ft_strdup(main->c_map->line);
	}
	else if (strncmp(main->c_map->line, "WE ", 2))
	{
		main->game->check_we = 1;
		main->game->tex_we = ft_strdup(main->c_map->line);
	}
	else if (strncmp(main->c_map->line, "EA ", 2))
	{
		main->game->check_ea = 1;
		main->game->tex_ea = ft_strdup(main->c_map->line);
	}
	else if (strncmp(main->c_map->line, "F ", 2))
	{
		main->game->check_f = 1;
		main->game->tex_f = ft_strdup(main->c_map->line);
	}
	else if (strncmp(main->c_map->line, "C ", 2))
	{
		main->game->check_c = 1;
		main->game->tex_c = ft_strdup(main->c_map->line);
	}
	else
		printf("Error\nWrong texture option\n");

}

void	read_file(t_main *main)
{
	printf("LAAAAAAA\n");
    main->c_map->line = get_next_line(main->c_map->fd);
    while (main->c_map->line != NULL)
    {
        if (!strcmp(main->c_map->line, "\n"))
            main->c_map->line = get_next_line(main->c_map->fd);
        else
        {
			check_texture(main);
			if (check_count_texture(main))
				break ;
			main->c_map->line = get_next_line(main->c_map->fd);
        }
    }
	printf("LAAAAAAA\n");
	while (main->c_map->line != NULL)
	{
		while (!strcmp(main->c_map->line, "\n"))
            main->c_map->line = get_next_line(main->c_map->fd);
		main->c_map->linejoin = ft_strjoin(main->c_map->linejoin, main->c_map->line);
		printf("OUIIIIII %s\n", main->c_map->linejoin);
		main->c_map->line = get_next_line(main->c_map->fd);
	}
	parse_map(main);
}
