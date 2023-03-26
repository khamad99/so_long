# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 14:24:11 by kalshaer          #+#    #+#              #
#    Updated: 2023/03/26 17:00:50 by kalshaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

LIBFT		=	libft/libft.a

MLX_FILE	=	minilibx

CFLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	= -I./$(MLX_FILE) -lm -lmlx -framework OpenGL -framework AppKit

SRS =		so_long.c \
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
	make -C minilibx

clean:
	rm -f *.o
	make clean -C libft
	make clean -C minilibx

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: make_libft make_MLX all clean fclean re
