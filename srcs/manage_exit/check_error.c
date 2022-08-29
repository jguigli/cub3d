#include "../../includes/cub3d.h"

int	check_error_arg(int argc)
{
	if (argc != 2)
		return (1);
	return (0);
}

int	check_file_name(char *mapname)
{
	char	*rep;
	int		fd;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	rep = ft_strrchr(mapname, '.');
	if (rep == NULL || ft_strcmp(rep, ".ber") != 0)
		return (1);
	return (0);
}

int	check_error(int argc, char **argv, t_data *game)
{
	char	*mapname;

	mapname = argv[1];
	if (check_error_arg(argc))
	{
		ft_printf("Error\nThe programm expects one and only argument\n");
		return (1);
	}
	if (check_file_name(mapname) || game->check_map.fd < 0)
	{
		ft_printf("Error\nIncorrect file\n");
		return (1);
	}
	if (check_error_map(game))
	{
		ft_printf("Error\nThe map is incorrect or empty\n");
		return (1);
	}
	return (0);
}