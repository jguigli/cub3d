

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <math.h>

# define BUFFER_SIZE 50

# define SCREEN_H 600
# define SCREEN_W 800
# define IMG_W 32
# define IMG_H 32

# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_xpm
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_xpm;

typedef struct s_map
{
	char	*line;
	int		length;
	int		length2;
	int		fd;
	int		count_line;
	int		line_max;
	int		position;
	int		exit;
	int		collectible;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		size_y;
	int		size_x;
	int		pos_y;
	int		pos_x;
	int		count_move;
	int		collectible_count;
	t_map	c_map;
}	t_data;

typedef struct	s_ray
{
	double		posx; //position x du joueur
	double		posy; //position y du joueur
	double		dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int			mapx; // coordonée x du carré dans lequel est pos
	int			mapy; // coordonnée y du carré dans lequel est pos
	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int			stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int			stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int			hit; // 1 si un mur a ete touche, 0 sinon
	int			side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int			lineheight; //hauteur de la ligne a dessiner
	int			drawstart; //position de debut ou il faut dessiner
	int			drawend; //position de fin ou il faut dessiner
	int			x; //permet de parcourir tous les rayons
}	t_ray;

int		get_number_line(char *mapname);
int		check_error_map(t_data *game);
int		check_error_map2(t_data *game);
int		check_error_arg(int argc);
int		check_file_name(char *mapname);
int		check_error(int argc, char **argv, t_data *game);
int		check_first_row(t_data *game);
int		check_last_row(t_data *game);
int		check_mid_row(t_data *game);
int		check_different_length(t_data *game);
int		check_item_map(t_data *game);
void	initialisation_struct_game(t_data *game, char *mapname);
int		check_end_line(char *s);
char	*readbuffer(int fd, char *tank);
char	*save(char *tank);
char	*get_line(char *str);
char	*get_next_line(int fd);
char	*get_string_map(char *mapname);
char	**parse_map(char *mapname);
void	load_xpm(t_data *game);
void	load_xpm2(t_data *game);
void	put_image(t_data *game, void *img, int x, int y);
void	get_the_right_image(char c, t_data *game, int i, int j);
void	launch_game(t_data *game);
void	create_window(t_data *game);
int		handle_keypress(int keysym, t_data *data);
int		handle_cross(t_data *data);
int		handle_no_event(void);
void	count_line(t_data *game, char *mapname);
void	close_game(t_data *game);
void	close_struct(t_data *game);
int		check_move_possibility(t_data *game, char pos, int dir);
int		event_key(int keysym, t_data *game);
void	check_move_character(t_data *game, char pos, int dir);
void	move_player(t_data *game, char pos, int dir);
int		check_y_possibility(t_data *game, char pos, int dir);
int		check_x_possibility(t_data *game, char pos, int dir);
int		check_y_exit(t_data *game, char pos, int dir);
int		check_x_exit(t_data *game, char pos, int dir);
int		after_event(int keysym, t_data *game);


int		if_map_not_good(char **map);
void	initialisation_struct_raycasting(t_ray *ray);

#endif