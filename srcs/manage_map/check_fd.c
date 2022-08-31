#include "../../includes/cub3d.h"

int	check_file_name(t_main *main, char *mapname)
{
	char	*rep;
	int		fd;

    // check si c'est un dossier
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		return (error_exit(main, BADFD));
	close(fd);
	rep = ft_strrchr(mapname, '.');
	if (rep == NULL || ft_strcmp(rep, ".cub") != 0)
		return (error_exit(main, BADFD));
	return (0);
}
