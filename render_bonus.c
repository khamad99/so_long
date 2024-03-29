/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:07 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/30 10:51:12 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	rendering_utils(t_mlx *mlx, char c, char *s)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	mlx_destroy_image(mlx->mlx, mlx->c.img);
	mlx->c.img = mlx_xpm_file_to_image(mlx->mlx, s, &x, &x);
	if (!(mlx->c.img))
		destory("Invalid image path or img\n", mlx, 0);
	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == c)
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c.img,
					j * PIXCEL, i * PIXCEL);
		}
	}
}

int	rendering(t_mlx *mlx)
{
	static size_t	i;
	static size_t	j;

	if (i % 5000 == 0)
		rendering_utils(mlx, 'C', F_LEFT);
	if (j % 10000 == 0)
		rendering_utils(mlx, 'C', F_RIGHT);
	i++;
	j++;
	return (0);
}
