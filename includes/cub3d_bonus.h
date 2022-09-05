/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:50:07 by jguigli           #+#    #+#             */
/*   Updated: 2022/09/05 18:50:09 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define SCREEN_H 1200
# define SCREEN_W 1600

# define ARG "Error\nIncorrect number of arguments\n"
# define ENV "Error\nEmpty environnement\n"
# define MLXPTR "Error\nMlx pointer initialisation failed\n"
# define MLXWINPTR "Error\nMlx window pointer initialisation failed\n"
# define NTEXMEN "Error\nNorth texture mentioned several times\n"
# define STEXMEN "Error\nSouth texture mentioned several times\n"
# define WTEXMEN "Error\nWest texture mentioned several times\n"
# define ETEXMEN "Error\nEast texture mentioned several times\n"
# define FTEXMEN "Error\nFloor texture mentioned several times\n"
# define CTEXMEN "Error\nCeilling texture mentioned several times\n"
# define TEXOPT "Error\nWrong texture option in file\n"
# define CHARMAP "Error\nWrong character in the map\n"
# define FORMATMAP "Error\nWrong map format\n"
# define CHARRGB "Error\nWrong character in rgb floor/ceilling\n"
# define COMMARGB "Error\nMissing number after comma in rgb floor/ceilling\n"
# define NBRNBR "Error\nIncorrect number of number in rgb floor/ceilling\n"
# define NBRCOMMA "Error\nIncorrect number of comma in rgb floor/ceilling \n"
# define MISSINGTEX "Error\nOne or several textures are missing\n"
# define MISSINGMAP "Error\nThe map is missing\n"
# define TMPOS "Error\nToo much positions specified\n"
# define NOPOS "Error\nNo position specified\n"
# define BADFD "Error\nBad file descriptor\n"
# define BADFEXT "Error\nBad file extension\n"
# define NMAPCLOSED "Error\nThe map is not closed\n"
# define FAILXPM "Error\nFail xpm to image\n"
# define FAILADDR "Error\nFail addr texture\n"
# define EMPTYSPACE "Error\nSpace on empty line\n"
# define SPACEMAP "Error\nSpace or linefeed not allowed in map\n"
# define EMPTYFD "Error\nEmpty file\n"
# define RGBSPACE "Error\nSpace in rgb number\n"
# define CRGBSCALE "Error\nCeilling rgb are not in the right scale\n"
# define FRGBSCALE "Error\nFloor rgb are not in the right scale\n"

/*AZERYTY*/
/*
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD_W_Z 122
# define BACK_S_S 115
# define RIGHT_D_D 100
# define LEFT_A_Q 113
*/
/*QWERTY*/

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD_W_Z 119
# define BACK_S_S 115
# define RIGHT_D_D 100
# define LEFT_A_Q 97


typedef struct s_xpm
{
	void	*mlx_img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_xpm;

typedef struct s_map
{
	char	*line;
	char	*linejoin;
	size_t	linesizemax;
	size_t	linesize;
	int		fd;
	int		count_line;
	int		position;
}	t_map;

typedef struct s_tex
{
	double	wallx;
	double	step;
	double	texpos;
	int		texx;
	int		texy;
	int		texdir;
	int		color;
}	t_tex;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		check_no;
	int		check_so;
	int		check_we;
	int		check_ea;
	int		check_f;
	int		check_c;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	char	*tex_f;
	char	*tex_c;
	int		color_f;
	int		color_c;
	int		rgb_f[3];
	int		rgb_c[3];
	int		pos_ok;
	int		size_y;
	int		size_x;
	int		pos_y;
	int		pos_x;
	int		move_forward;
	int		move_back;
	int		move_left;
	int		move_right;
	int		move_rotate_left;
	int		move_rotate_right;
	int		mouse;
}	t_data;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
}	t_ray;

typedef struct s_main
{
	int		scr_y;
	int		scr_x;
	int		c;
	int		f;
	t_data	*game;
	t_xpm	*img;
	t_xpm	*texture;
	t_ray	*ray;
	t_map	*c_map;
	t_tex	*tex;
}	t_main;

char	*readbuffer(int fd, char *tank);
char	*save(char *tank);
char	*get_line(char *str);
char	*get_next_line(int fd);

int		check_outline(t_main *main);
t_map	*initialisation_struct_map(void);
t_ray	*initialisation_struct_raycasting(void);
t_data	*initialisation_struct_game(void);
t_xpm	*initialisation_struct_xpm(void);
t_xpm	*initialisation_struct_texture(void);
t_tex	*initialisation_struct_tex(void);
t_main	*initialisation_struct_main(void);
void	create_window(t_main *main);
int		check_file_name(char *mapname);
int		draw_map(t_main *main);
void	parse_map(t_main *main);
int		read_file(t_main *main);
int		check_texture(t_main *main);
int		check_count_texture(t_main *main);
int		manage_file_map(t_main *main, char *mapname);
int		check_comma_number(char *rgb);
int		event_key(t_main *main);
int		manage_key_press(int keysym, t_main *main);
int		manage_key_release(int keysym, t_main *main);
void	close_game(t_main *main);
void	rotate_right(t_main *main);
void	rotate_left(t_main *main);
void	move_forward(t_main *main);
void	move_back(t_main *main);
void	move_right(t_main *main);
void	move_left(t_main *main);
void	init_raycast(t_main *main, int x);
void	side_dist(t_main *main);
void	algo_dda(t_main *main);
void	wall_dist(t_main *main);
void	display_texture(t_main *main, int x);
void	stock_position_north(int x, int y, t_main *main);
void	stock_position_south(int x, int y, t_main *main);
void	stock_position_east(int x, int y, t_main *main);
void	stock_position_west(int x, int y, t_main *main);
int		check_position(t_main *main);
int		check_color(t_main *main);
int		create_trgb(int r, int g, int b);
int		manage_rgb(t_main *main);
int		check_color_floor(t_main *main);
int		check_color_ceilling(t_main *main);
int		check_char(t_main *main);
int		check_format(t_main *main);
int		manage_file_map(t_main *main, char *mapname);
int		get_texture(t_main *main);
int		get_addr_texture(t_main *main);
void	get_dir_texture(t_main *main);
void	texture_calculation(t_main *main, int x);
void	display_color_texture(t_main *main, int x);
void	my_mlx_pixel_put(t_main *main, int x, int y, int color);
void	free_main(t_main *main);
void	manage_mlx(t_main *main);
void	init_mlx_ptr(t_main *main);
int		error_exit(char *errormsg);
int		exit_escape(t_main *main);
char	**ft_split_map(t_main *main, char const *str);
void	fill_map(t_main *main);
int		check_texture_one(t_main *main);
int		check_texture_two(t_main *main);
char	*crop_texture_side(t_main *main);
char	*crop_texture_high(t_main *main);
int		loop_read_texture(t_main *main);
int		create_trgb(int r, int g, int b);
int		space_inside(char *temp);
int		loop_check_rgb(char *rgb, int *comma, int *i);
int		check_color_rgb_floor(t_main *main, int i, int y, int s);
int		check_color_rgb_floor(t_main *main, int i, int y, int s);
int		exit_texture(t_main *main);
int		free_gnl_msg(t_main *main, char *msg);
int		free_gnl_simple(t_main *main);
int		draw_minimap(t_main *main);
void	rotate_mouse(t_main *main);
void	rotate_left_mouse(t_main *main, double rotaspeed);
void	rotate_right_mouse(t_main *main, double rotaspeed);

#endif
