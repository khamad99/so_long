/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:09:08 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/30 10:49:35 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dolphin_position(t_mlx *mlx, int i, int j, int y)
{
	mlx->p_y = y;
	mlx->i = i;
	mlx->j = j;
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.img, mlx->p_x, y);
}

static void	images(t_mlx *mlx)
{
	int		x;

	x = 0;
	mlx->sh.path = SHARK;
	mlx->e.path = EXIT;
	mlx->w.path = WALL;
	mlx->c.path = F_LEFT;
	mlx->s.path = SPACE;
	mlx->p.path = D_UP;
	mlx->p.img = mlx_xpm_file_to_image(mlx->mlx, mlx->p.path, &x, &x);
	mlx->s.img = mlx_xpm_file_to_image(mlx->mlx, mlx->s.path, &x, &x);
	mlx->c.img = mlx_xpm_file_to_image(mlx->mlx, mlx->c.path, &x, &x);
	mlx->w.img = mlx_xpm_file_to_image(mlx->mlx, mlx->w.path, &x, &x);
	mlx->e.img = mlx_xpm_file_to_image(mlx->mlx, mlx->e.path, &x, &x);
	mlx->sh.img = mlx_xpm_file_to_image(mlx->mlx, mlx->sh.path, &x, &x);
	if (!mlx->p.img || !mlx->s.img || !mlx->c.img
		|| !mlx->w.img || !mlx->e.img || !mlx->sh.img)
		destory("Invalid image path or img\n", mlx, 0);
}

static void	fill_map2(t_mlx *mlx, int i, int *x, int y)
{
	int	j;

	j = -1;
	*x = 0;
	while (mlx->map[i][++j])
	{
		if (mlx->map[i][j] == '0')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.img, *x, y);
		else if (mlx->map[i][j] == '1')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->w.img, *x, y);
		else if (mlx->map[i][j] == 'P')
		{
			mlx->p_x = *x;
			dolphin_position (mlx, i, j, y);
		}
		else if (mlx->map[i][j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.img, *x, y);
		else if (mlx->map[i][j] == 'C')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->c.img, *x, y);
		else if (mlx->map[i][j] == 'K')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->sh.img, *x, y);
		*x = *x + PIXCEL;
	}
}

static void	fill_map(t_mlx *mlx)
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
		y = y + PIXCEL;
	}
}

void	create_map(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		errorh ("init function faild\n", mlx->map, NULL);
	mlx->map_y = 0;
	while (mlx->map[mlx->map_y])
		mlx->map_y++;
	mlx->map_x = PIXCEL * ft_strlen(mlx->map[0]);
	mlx->map_y = PIXCEL * mlx->map_y;
	mlx->win = mlx_new_window(mlx->mlx, mlx->map_x, mlx->map_y, "so_long");
	if (!(mlx->win))
		errorh("new_window function faild\n", mlx->map, NULL);
	mlx_loop_hook(mlx->mlx, &rendering, mlx);
	fill_map(mlx);
}
