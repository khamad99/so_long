# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 14:24:11 by kalshaer          #+#    #+#              #
#    Updated: 2023/03/22 13:53:21 by kalshaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	libft/libft.a

MLX		=	minilibx

LFLAGS	=	-I./minilibx -lm -lmlx -framework OpenGL -framework AppKit

FILES	=	so_long.c \
			parsing1.c \
			parsing2.c \
			images.c \
			anim.c \
			moves.c \
			moves_utils.c

OBJ		=	$(FILES:.c=.o)

all: run_MLX run_lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(FILES) -o $(NAME) -L./$(MLX) $(LFLAGS) $(LIB)

run_lib:
	@make -C libft

run_MLX:
	@make -C $(MLX)

clean:
	@rm -f *.o
	@make clean -C libft
	@make clean -C $(MLX)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: run_lib run_MLX all clean fclean re
