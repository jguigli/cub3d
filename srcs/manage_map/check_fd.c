#include "../../includes/cub3d.h"

int	check_file_name(char *mapname)
{
	char	*rep;
	int		fd;

	fd = open(mapname, __O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (error_exit(BADFD));
	}
	close(fd);
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (error_exit(BADFD));
	}
	close(fd);
	rep = ft_strrchr(mapname, '.');
	if (rep == NULL || ft_strcmp(rep, ".cub") != 0)
		return (error_exit(BADFEXT));
	return (0);
}
