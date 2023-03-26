# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 14:24:11 by kalshaer          #+#    #+#              #
#    Updated: 2023/03/26 10:40:29 by kalshaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT		=	libft/libft.a

ifeq ($(shell uname), Darwin)
	MLX_FILE	=	minilibx
else
	MLX_FILE	=	minilibx-linux
endif

CFLAGS	=	-Wall -Wextra -Werror

ifeq ($(shell uname), Darwin)
	MLX_FLAGS = -I./$(MLX_FILE) -lm -lmlx -framework OpenGL -framework AppKit
else
	MLX_FLAGS = -I./$(MLX_FILE) -lmlx -lXext -lX11 
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
	$(CC) $(CFLAGS) $(SRS) -o $(NAME) -L./$(MLX_FILE) $(MLX_FLAGS) $(LIBFT)

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
ifeq ($(shell uname), Darwin)
	make clean -C minilibx
else
	cd minilibx-linux && make clean
endif

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: make_libft make_MLX all clean fclean re
