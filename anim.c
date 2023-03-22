/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:07 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/22 14:19:20 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_norm(t_mlx *mlx, char a, char *s)
{
	int	x;
	int	i;
	int	j;

	mlx_destroy_image(mlx->mlx, mlx->c.icon);
	mlx->c.icon = mlx_xpm_file_to_image(mlx->mlx, s, &x, &x);
	if (!(mlx->c.icon))
		errorh("Invalid image path or icon\n");
	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == a)
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c.icon,
					j * Pixcel, i * Pixcel);
		}
	}
}

int	animation(t_mlx *mlx)
{
	static int	i;
	static int	j;

	if (i % 8000 == 0)
		anim_norm(mlx, 'C', COIN_LEFT);
	if (j % 16000 == 0)
		anim_norm(mlx, 'C', COIN_RIGHT);
	i++;
	j++;
	return (0);
}
