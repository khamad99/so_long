/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:25 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/22 13:53:27 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	eli_norm(t_mlx *mlx, char *s)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i][mlx->j] == 'K')
		exit(0);
	mlx_destroy_image(mlx->mlx, mlx->p.icon);
	mlx->p.icon = mlx_xpm_file_to_image(mlx->mlx, s, &x, &x);
	if (!(mlx->p.icon))
		errorh("Invalid image path or icon\n\n");
	if (mlx->map[mlx->i][mlx->j] == 'C' && mlx->count)
	{
		mlx->count--;
		mlx->map[mlx->i][mlx->j] = 'S';
	}
}

void	to_up(t_mlx *mlx, int *count)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i - 1][mlx->j] != '1')
	{
		*count = *count + 1;
		mlx->i = mlx->i - 1;
		eli_norm (mlx, PLAYER_UP);
		mlx->px_y = mlx->px_y - Pixcel;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			exit(0);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.icon, mlx->px_x,
			mlx->px_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, mlx->px_x,
			mlx->px_y + Pixcel);
		if (mlx->map[mlx->i + 1][mlx->j] == 'S')
			for_up(mlx);
		if (mlx->map[mlx->i + 1][mlx->j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.icon,
				mlx->px_x, mlx->px_y + Pixcel);
		ft_printf ("%d\n", *count);
	}
}

void	to_right(t_mlx *mlx, int *count)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i][mlx->j + 1] != '1')
	{
		*count += 1;
		mlx->j += 1;
		eli_norm (mlx, P_RIGHT);
		mlx->px_x += Pixcel;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			exit(0);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.icon, mlx->px_x,
			mlx->px_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon,
			mlx->px_x - Pixcel, mlx->px_y);
		if (mlx->map[mlx->i][mlx->j - 1] == 'S')
			for_right(mlx);
		if (mlx->map[mlx->i][mlx->j - 1] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.icon,
				mlx->px_x - Pixcel, mlx->px_y);
		ft_printf ("%d\n", *count);
	}
}

void	to_down(t_mlx *mlx, int *count)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i + 1][mlx->j] != '1')
	{
		*count += 1;
		mlx->i += 1;
		eli_norm (mlx, P_DOWN);
		mlx->px_y += Pixcel;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			exit(0);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.icon, mlx->px_x,
			mlx->px_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, mlx->px_x,
			mlx->px_y - Pixcel);
		if (mlx->map[mlx->i - 1][mlx->j] == 'S')
			for_down(mlx);
		if (mlx->map[mlx->i - 1][mlx->j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.icon, mlx->px_x,
				mlx->px_y - Pixcel);
		ft_printf ("%d\n", *count);
	}
}

void	to_left(t_mlx *mlx, int *count)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i][mlx->j - 1] != '1')
	{
		*count += 1;
		mlx->j -= 1;
		eli_norm (mlx, P_LEFT);
		mlx->px_x -= Pixcel;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			exit(0);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.icon, mlx->px_x,
			mlx->px_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon,
			mlx->px_x + Pixcel, mlx->px_y);
		if (mlx->map[mlx->i][mlx->j + 1] == 'S')
			for_left(mlx);
		if (mlx->map[mlx->i][mlx->j + 1] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.icon,
				mlx->px_x + Pixcel, mlx->px_y);
		ft_printf ("%d\n", *count);
	}
}
