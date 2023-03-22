/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:09:08 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/22 13:53:31 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	func_for_p_norm(t_mlx *mlx, int i, int j, int y)
{
	mlx->px_y = y;
	mlx->i = i;
	mlx->j = j;
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.icon, mlx->px_x, y);
}

void	images(t_mlx *mlx)
{
	int		x;

	mlx->en.path = ENEMY_RED;
	mlx->e.path = EXIT;
	mlx->w.path = WALL;
	mlx->c.path = COIN_LEFT;
	mlx->s.path = SPACE;
	mlx->p.path = PLAYER_UP;
	mlx->p.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->p.path, &x, &x);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->s.path, &x, &x);
	mlx->c.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->c.path, &x, &x);
	mlx->w.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->w.path, &x, &x);
	mlx->e.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->e.path, &x, &x);
	mlx->en.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->en.path, &x, &x);
	if (!mlx->p.icon || !mlx->s.icon || !mlx->c.icon
		|| !mlx->w.icon || !mlx->e.icon || !mlx->en.icon)
		errorh("Invalid image path or icon\n");
}

void	fill_map2(t_mlx *mlx, int i, int *x, int y)
{
	int	j;

	j = -1;
	*x = 0;
	while (mlx->map[i][++j])
	{
		if (mlx->map[i][j] == '0')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, *x, y);
		else if (mlx->map[i][j] == '1')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->w.icon, *x, y);
		else if (mlx->map[i][j] == 'P')
		{
			mlx->px_x = *x;
			func_for_p_norm (mlx, i, j, y);
		}
		else if (mlx->map[i][j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.icon, *x, y);
		else if (mlx->map[i][j] == 'C')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->c.icon, *x, y);
		else if (mlx->map[i][j] == 'K')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->en.icon, *x, y);
		*x = *x + Pixcel;
	}
}

void	fill_map(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	y = 0;
	images(mlx);
	while (mlx->map[++i])
	{
		fill_map2(mlx, i, &x, y);
		y = y + Pixcel;
	}
}

void	create_map(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		errorh ("init function faild\n");
	mlx->map_y = 0;
	while (mlx->map[mlx->map_y])
		mlx->map_y++;
	mlx->map_x = Pixcel * ft_strlen(mlx->map[0]);
	mlx->map_y = Pixcel * mlx->map_y;
	mlx->win = mlx_new_window(mlx->mlx, mlx->map_x, mlx->map_y, "so_long");
	if (!(mlx->win))
		errorh("new_window function faild\n");
	mlx_loop_hook(mlx->mlx, &animation, mlx);
	fill_map(mlx);
}
