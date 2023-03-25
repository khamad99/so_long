/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:54:36 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/25 10:57:27 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->p.img);
	mlx_destroy_image(mlx->mlx, mlx->w.img);
	mlx_destroy_image(mlx->mlx, mlx->s.img);
	mlx_destroy_image(mlx->mlx, mlx->c.img);
	mlx_destroy_image(mlx->mlx, mlx->e.img);
	mlx_destroy_image(mlx->mlx, mlx->sh.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_s(mlx->map);
	exit (0);
}

int	hooking_function(int key, t_mlx *mlx)
{
	static int	count;
	char		*s;

	if (key == 53)
		destory(NULL, mlx);
	else if (key == 13 || key == 126)
		move_up(mlx, &count);
	else if (key == 2 || key == 124)
		move_right(mlx, &count);
	else if (key == 1 || key == 125)
		move_down(mlx, &count);
	else if (key == 0 || key == 123)
		move_left(mlx, &count);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->w.img, 0, 0);
	s = ft_itoa(count);
	mlx_string_put(mlx->mlx, mlx->win, 0, 10, 0x00000000, s);
	free(s);
	return (0);
}
