#include "../../includes/cub3d.h"

char	*get_string_map(char *mapname)
{
	char	*line;
	char	*str;
	int		fd;

	fd = open(mapname, O_RDONLY);
	line = get_next_line(fd);
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (line)
	{
		str = ft_strjoin(str, line);
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
	return (str);
}

void	parse_map(t_main *main)
{
	main->game->map = ft_split(main->c_map->linejoin, '\n');
	free (main->c_map->linejoin);
}