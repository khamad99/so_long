/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:36 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/22 08:08:39 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	for_up(t_mlx *mlx)
{
	int	x;

	mlx_destroy_image(mlx->mlx, mlx->s.icon);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, \
		COIN_EXTRA, &x, &x);
	mlx_put_image_to_window (mlx->mlx, mlx->win, \
			mlx->s.icon, mlx->px_x, mlx->px_y + PX);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, \
		SPACE, &x, &x);
}

void	for_right(t_mlx *mlx)
{
	int	x;

	mlx_destroy_image(mlx->mlx, mlx->s.icon);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, \
		COIN_EXTRA, &x, &x);
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, \
			mlx->px_x - PX, mlx->px_y);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, \
		SPACE, &x, &x);
}

void	for_down(t_mlx *mlx)
{
	int	x;

	mlx_destroy_image(mlx->mlx, mlx->s.icon);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, \
		COIN_EXTRA, &x, &x);
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, \
			mlx->px_x, mlx->px_y - PX);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, \
		SPACE, &x, &x);
}

void	for_left(t_mlx *mlx)
{
	int	x;

	mlx_destroy_image(mlx->mlx, mlx->s.icon);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, \
		COIN_EXTRA, &x, &x);
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, \
			mlx->px_x + PX, mlx->px_y);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, \
		SPACE, &x, &x);
}
