#include "../../includes/cub3d.h"

int		skip_backline(t_main *main)
{
	free (main->c_map->line);
	main->c_map->line = get_next_line(main->c_map->fd);
	if ((main->c_map->line[0] == '1' || main->c_map->line[0] == '0'
		|| main->c_map->line[0] == ' ') && !check_count_texture(main))
		return (error_exit(MISSINGTEX));
	return (0);
}

int		read_map(t_main *main)
{
	while (!ft_strcmp(main->c_map->line, "\n"))
	{
		free (main->c_map->line);
		main->c_map->line = get_next_line(main->c_map->fd);
		if (main->c_map->line == NULL)
			return (error_exit(MISSINGMAP));
	}
	main->c_map->linejoin = ft_strjoin(main->c_map->linejoin, main->c_map->line);
	free (main->c_map->line);
	main->c_map->line = get_next_line(main->c_map->fd);
	return (0);
}

int		read_file(t_main *main)
{
    main->c_map->line = get_next_line(main->c_map->fd);
    while (main->c_map->line != NULL)
    {
        if (!ft_strcmp(main->c_map->line, "\n"))
		{
			if (skip_backline(main))
				return (1);
		}
        else
        {
			if (check_texture(main))
				return (1);
			free (main->c_map->line);
			if (check_count_texture(main))
				break ;
			main->c_map->line = get_next_line(main->c_map->fd);
			if ((main->c_map->line[0] == '1' || main->c_map->line[0] == '0'
				|| main->c_map->line[0] == ' ') && !check_count_texture(main))
				return (error_exit(MISSINGTEX));
        }
    }
	while (main->c_map->line != NULL)
	{
		if (read_map(main))
			return (1);
	}
	return (0);
}
