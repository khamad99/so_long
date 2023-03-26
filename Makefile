# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 14:24:11 by kalshaer          #+#    #+#              #
#    Updated: 2023/03/26 22:15:30 by kalshaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

NAME_BONUS	=	so_long_bonus

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

SRS_B =		so_long_bonus.c \
			parsing1_bonus.c \
			parsing2_bonus.c \
			map_init_bonus.c \
			render_bonus.c \
			moves_bonus.c \
			hook_bonus.c \
			error_handling_bonus.c \
			moves_utils_bonus.c

OBJ		=	$(SRS:.c=.o)

OBJ_B	=	$(SRS_B:.c=.o)

all: make_MLX make_libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRS) -o $(NAME) -L./$(MLX_FILE) $(MLX_FLAGS) $(LIBFT)

$(NAME_BONUS): $(OBJ_B)
	$(CC) $(CFLAGS) $(SRS_B) -o $(NAME_BONUS) -L./$(MLX_FILE) $(MLX_FLAGS) $(LIBFT)

make_libft:
	make -C libft

make_MLX:
	make -C minilibx

bonus: make_MLX make_libft $(NAME_BONUS)

clean:
	rm -f *.o
	make clean -C libft
	make clean -C minilibx

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C libft

re: fclean all
