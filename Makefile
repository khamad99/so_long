# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 14:24:11 by kalshaer          #+#    #+#              #
#    Updated: 2023/03/25 13:25:33 by kalshaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT		=	libft/libft.a

MLX_FILE	=	minilibx

FLAGS	=	-Wall -Wextra -Werror

MLX_FLAGS	= -lm -lmlx

ifeq ($(shell uname), Darwin)
	MLX_FLAGS += -Lminilibx -Iminilibx -framework OpenGL -framework AppKit
else
	MLX_FILE = minilibx-linux
	MLX_FLAGS += -Lminilibx_linux -Iminilibx_linux -lXext -lX11 -lz
endif

SRS	=		so_long.c \
			parsing1.c \
			parsing2.c \
			map_init.c \
			render.c \
			moves.c \
			hook.c \
			error_handling.c \
			moves_utils.c

OBJ		=	$(SRS:.c=.o)

all: make_MLX make_libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRS) -o $(NAME) -L./minilibx $(MLX_FLAGS) $(LIBFT)

make_libft:
	make -C libft

make_MLX:
ifeq ($(shell uname), Darwin)
	make -C minilibx
else
	cd minilibx-linux && make
endif

clean:
	rm -f *.o
	make clean -C libft
	make clean -C minilibx

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: run_lib run_MLX all clean fclean re
