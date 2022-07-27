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

char	**parse_map(char *mapname)
{
	char	**map;
	char	*str;

	str = get_string_map(mapname);
	map = ft_split(str, '\n');
	free (str);
	return (map);
}