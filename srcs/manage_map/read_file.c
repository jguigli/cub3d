#include "../../includes/cub3d.h"

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
