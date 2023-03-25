/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:25 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/25 11:01:19 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moves_utils(t_mlx *mlx, char *s)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i][mlx->j] == 'K')
		destory("You loss!\n", mlx);
	mlx_destroy_image(mlx->mlx, mlx->p.img);
	mlx->p.img = mlx_xpm_file_to_image(mlx->mlx, s, &x, &x);
	if (!(mlx->p.img))
		errorh("Invalid image path or img\n", mlx->map, NULL);
	if (mlx->map[mlx->i][mlx->j] == 'C' && mlx->count)
	{
		mlx->count--;
		mlx->map[mlx->i][mlx->j] = 'S';
	}
}

void	move_up(t_mlx *mlx, int *count)
{
	if (mlx->map[mlx->i - 1][mlx->j] != '1')
	{
		*count = *count + 1;
		mlx->i = mlx->i - 1;
		moves_utils(mlx, D_UP);
		mlx->p_y = mlx->p_y - PIXCEL;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			destory("You win!\n", mlx);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.img, mlx->p_x,
			mlx->p_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.img, mlx->p_x,
			mlx->p_y + PIXCEL);
		if (mlx->map[mlx->i + 1][mlx->j] == 'S')
			up_utils(mlx);
		if (mlx->map[mlx->i + 1][mlx->j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.img,
				mlx->p_x, mlx->p_y + PIXCEL);
		ft_printf("%d\n", *count);
	}
}

void	move_right(t_mlx *mlx, int *count)
{
	if (mlx->map[mlx->i][mlx->j + 1] != '1')
	{
		*count += 1;
		mlx->j += 1;
		moves_utils(mlx, D_RIGHT);
		mlx->p_x += PIXCEL;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			destory("You win!\n", mlx);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.img, mlx->p_x,
			mlx->p_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.img,
			mlx->p_x - PIXCEL, mlx->p_y);
		if (mlx->map[mlx->i][mlx->j - 1] == 'S')
			right_utils(mlx);
		if (mlx->map[mlx->i][mlx->j - 1] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.img,
				mlx->p_x - PIXCEL, mlx->p_y);
		ft_printf("%d\n", *count);
	}
}

void	move_down(t_mlx *mlx, int *count)
{
	if (mlx->map[mlx->i + 1][mlx->j] != '1')
	{
		*count += 1;
		mlx->i += 1;
		moves_utils(mlx, D_DOWN);
		mlx->p_y += PIXCEL;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			destory("You win!\n", mlx);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.img, mlx->p_x,
			mlx->p_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.img, mlx->p_x,
			mlx->p_y - PIXCEL);
		if (mlx->map[mlx->i - 1][mlx->j] == 'S')
			down_utils(mlx);
		if (mlx->map[mlx->i - 1][mlx->j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.img, mlx->p_x,
				mlx->p_y - PIXCEL);
		ft_printf("%d\n", *count);
	}
}

void	move_left(t_mlx *mlx, int *count)
{
	if (mlx->map[mlx->i][mlx->j - 1] != '1')
	{
		*count += 1;
		mlx->j -= 1;
		moves_utils(mlx, D_LEFT);
		mlx->p_x -= PIXCEL;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			destory("You win!\n", mlx);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.img, mlx->p_x,
			mlx->p_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.img,
			mlx->p_x + PIXCEL, mlx->p_y);
		if (mlx->map[mlx->i][mlx->j + 1] == 'S')
			left_utils(mlx);
		if (mlx->map[mlx->i][mlx->j + 1] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.img,
				mlx->p_x + PIXCEL, mlx->p_y);
		ft_printf("%d\n", *count);
	}
}
