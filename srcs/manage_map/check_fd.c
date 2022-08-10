#include "../../includes/cub3d.h"

int	check_file_name(char *mapname)
{
	char	*rep;
	int		fd;

    // check si c'est un dossier
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
	{
        printf("Error\nBad file descriptor\n");
		return (1);
	}
	close(fd);
	rep = ft_strrchr(mapname, '.');
	if (rep == NULL || ft_strcmp(rep, ".cub") != 0)
    {
        printf("Error\nBad file extension\n");
		return (1);
    }
	return (0);
}
