#include "../../includes/cub3d.h"

int error_exit(t_main *main, char *errormsg)
{
    ft_putstr_fd(errormsg, 2);
    free_main(main);
    return (1);
}

int error_exit_noinit(char *errormsg)
{
    ft_putstr_fd(errormsg, 2);
    return (-1);
}

void    exit_escape(t_main *main)
{
    free_main(main);
    exit(1);
}
