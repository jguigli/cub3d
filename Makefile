SRC_M = ./srcs/main.c \
		./srcs/manage_map/check_map.c \
		./srcs/manage_map/parse_map.c \
		./gnl/get_next_line.c \
		./srcs/manage_window/create_window.c \
		./srcs/manage_game/init_game.c \
		#./srcs/manage_error/check_error.c \
		./srcs/manage_game/close_game.c \
		./srcs/manage_game/launch_game.c \
		./srcs/manage_map/check_map2.c \

SRC_B =


HEADER			=	includes/cub3d.h
HEADER_BONUS	=	includes/cub3d_bonus.h

SOURCES			=	$(SRC_M)
BONUS_FILES		=	$(SRC_B)

OBJECTS			= 	$(SOURCES:.c=.o)
OBJECTS_BONUS	= 	$(BONUS_FILES:.c=.o)

NAME			=	cub3d
NAME_BONUS		=	cub3d_bonus

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-I -g -L /usr/X11/lib -Lincludes -L./mlbx -Imlx -lXext -lX11 -lz -lm

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./mlx_linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):	$(LIBFT) $(MINILIBX) $(OBJECTS_BONUS) $(HEADER_BONUS)
				$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx bonus