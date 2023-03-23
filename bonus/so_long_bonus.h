/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:05:14 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/23 13:53:34 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define PX 50

typedef	struct s_img
{
	char	*path;
	void	*icon;
}	t_img;

typedef	struct s_mlx
{
	t_img	P;
	t_img	W;
	t_img	E;
	t_img	S;
	t_img	C;
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
	int	e_tox;
	int	e_syun;
	int	nl;
}	t_count;

# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "printf/ft_printf.h"

int		counts(char **split, char **split2);
char	**map_check(char *file, int *c_count);
void	up_utils(t_mlx *mlx);
void	right_utils(t_mlx *mlx);
void	down_utils(t_mlx *mlx);
void	left_utils(t_mlx *mlx);
void	create_map(t_mlx *mlx);
void	universal_func(int a, char *s);
void	move_up(t_mlx *mlx, int *count);
void	move_right(t_mlx *mlx, int *count);
void	move_down(t_mlx *mlx, int *count);
void	move_left(t_mlx *mlx, int *count);

#endif
