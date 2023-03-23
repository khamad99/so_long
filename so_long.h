/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:09:56 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/23 14:19:09 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//This is game about Hummer and policemen with their cars.

//Your goal is to kill all policemen and not been crashed by their cars.

//If you want win, go to garage after killing all policemen.

//If you want to change game theme, change the 
// image paths from here(header file macros).

//If your player haven`t images in 4 directions, you may
// change directions.c file, only comment
// lines where is written macros which you don`t use

//And please, keep images size in 50PX in width and height,
// or change it from below

# define Pixcel 50
# define D_UP "textures/dolphinup.xpm"
# define D_RIGHT "textures/dolphinright.xpm"
# define D_DOWN "textures/dolphindown.xpm"
# define D_LEFT "textures/dolphinleft.xpm"
# define SHARK "textures/shark.xpm"
# define F_RIGHT "textures/fishleft.xpm"
# define F_LEFT "textures/fishright.xpm"
# define WALL "textures/wall.xpm"
# define SPACE "textures/seab.xpm"
# define EXIT "textures/seagate.xpm"
# include "minilibx/mlx.h"
# include "libft/libft.h"

typedef struct s_img
{
	char	*path;
	void	*icon;
}	t_img;

typedef struct s_mlx
{
	t_img	p;
	t_img	w;
	t_img	e;
	t_img	s;
	t_img	c;
	t_img	en;
	void	*mlx;
	void	*win;
	char	**map;
	int		map_x;
	int		map_y;
	int		p_x;
	int		p_y;
	int		i;
	int		j;
	int		count;
}	t_mlx;

typedef struct s_count
{
	int	e_count;
	int	c_count;
	int	p_count;
	int	e_x;
	int	e_y;
}	t_count;

int		count_symbols(char **s);
char	**map_check(char *file, int *mlxcount);
void	move_up(t_mlx *mlx, int *count);
void	move_right(t_mlx *mlx, int *count);
void	move_down(t_mlx *mlx, int *count);
void	move_left(t_mlx *mlx, int *count);
void	up_utils(t_mlx *mlx);
void	right_utils(t_mlx *mlx);
void	down_utils(t_mlx *mlx);
void	left_utils(t_mlx *mlx);
int		close_window(t_mlx *mlx);
int		hooking_function(int key, t_mlx *mlx);
void	create_map(t_mlx *mlx);
void	errorh(char *s);
int		animation(t_mlx *mlx);

#endif
