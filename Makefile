SRC_M = ./srcs/main.c \
		./srcs/manage_map/check_closemap.c \
		./srcs/manage_map/manage_map.c \
		./srcs/manage_map/check_color.c \
		./srcs/manage_map/check_color_utils.c \
		./srcs/manage_map/check_position.c \
		./srcs/manage_map/check_texture.c \
		./srcs/manage_map/check_texture2.c \
		./srcs/manage_map/read_file.c \
		./srcs/manage_map/parse_map.c \
		./srcs/manage_map/split_map.c \
		./srcs/manage_mlx/create_window.c \
		./srcs/manage_mlx/init_ptr.c \
		./srcs/manage_game/init_game.c \
		./srcs/manage_game/init_game2.c \
		./srcs/manage_game/raycast.c \
		./srcs/manage_game/key_move.c \
		./srcs/manage_game/move_player.c \
		./srcs/manage_game/rotate_player.c \
		./srcs/manage_game/draw_game.c \
		./srcs/manage_game/texture.c \
		./srcs/manage_map/check_fd.c \
		./srcs/manage_exit/exit.c \
		./srcs/manage_exit/free.c \
		./gnl/get_next_line.c \

SRC_B = ./bonus/main.c \
		./bonus/manage_map/check_closemap.c \
		./bonus/manage_map/manage_map.c \
		./bonus/manage_map/check_color.c \
		./bonus/manage_map/check_color_utils.c \
		./bonus/manage_map/check_position.c \
		./bonus/manage_map/check_texture.c \
		./bonus/manage_map/check_texture2.c \
		./bonus/manage_map/read_file.c \
		./bonus/manage_map/parse_map.c \
		./bonus/manage_map/split_map.c \
		./bonus/manage_mlx/create_window.c \
		./bonus/manage_mlx/init_ptr.c \
		./bonus/manage_game/init_game.c \
		./bonus/manage_game/init_game2.c \
		./bonus/manage_game/raycast.c \
		./bonus/manage_game/key_move.c \
		./bonus/manage_game/move_player.c \
		./bonus/manage_game/rotate_player.c \
		./bonus/manage_game/draw_game.c \
		./bonus/manage_game/texture.c \
		./bonus/manage_map/check_fd.c \
		./bonus/manage_exit/exit.c \
		./bonus/manage_exit/free.c \
		./bonus/manage_game/minimap.c \
		./bonus/manage_game/rotate_mouse.c \
		./gnl/get_next_line.c \


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

CFLAGS			=	-Wall -Wextra -Werror -g3 #-fsanitize=address
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