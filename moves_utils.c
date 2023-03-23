/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:36 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/23 14:39:43 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_utils(t_mlx *mlx)
{
	int	x;

	mlx_destroy_image(mlx->mlx, mlx->s.img);
	mlx->s.img = mlx_xpm_file_to_image(mlx->mlx, SPACE, &x, &x);
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.img, mlx->p_x,
		mlx->p_y + Pixcel);
	mlx->s.img = mlx_xpm_file_to_image(mlx->mlx, SPACE, &x, &x);
}

void	right_utils(t_mlx *mlx)
{
	int	x;

	mlx_destroy_image(mlx->mlx, mlx->s.img);
	mlx->s.img = mlx_xpm_file_to_image(mlx->mlx, SPACE, &x, &x);
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.img,
		mlx->p_x - Pixcel, mlx->p_y);
	mlx->s.img = mlx_xpm_file_to_image(mlx->mlx, SPACE, &x, &x);
}

void	down_utils(t_mlx *mlx)
{
	int	x;

	mlx_destroy_image(mlx->mlx, mlx->s.img);
	mlx->s.img = mlx_xpm_file_to_image(mlx->mlx, SPACE, &x, &x);
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.img,
		mlx->p_x, mlx->p_y - Pixcel);
	mlx->s.img = mlx_xpm_file_to_image(mlx->mlx, SPACE, &x, &x);
}

void	left_utils(t_mlx *mlx)
{
	int	x;

	mlx_destroy_image(mlx->mlx, mlx->s.img);
	mlx->s.img = mlx_xpm_file_to_image(mlx->mlx, SPACE, &x, &x);
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.img,
		mlx->p_x + Pixcel, mlx->p_y);
	mlx->s.img = mlx_xpm_file_to_image(mlx->mlx, SPACE, &x, &x);
}
