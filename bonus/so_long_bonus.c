/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:05:54 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/23 14:40:04 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_mlx *mlx)
{
	system("leaks so_long");
	exit(0);
}

int	close_map(int key, t_mlx *mlx)
{
	static int	count;
	char		*s;

	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		system("leaks so_long");
		exit(0);
	}
	else if (key == 13 || key == 126)
		move_up(mlx, &count);
	else if (key == 2 || key == 124)
		move_right(mlx, &count);
	else if (key == 1 || key == 125)
		move_down(mlx, &count);
	else if (key == 0 || key == 123)
		move_left(mlx, &count);
	// mlx_loop_hook(mlx->mlx, &render_next_frame, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->W.img, 0, 0);
	s = ft_itoa(count);
	mlx_string_put(mlx->mlx, mlx->win, 0, 10, 0x00000000, s);
	free(s);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	universal_func(argc == 1, "No map, please add *.ber file in arguments\n");
	universal_func(argc > 2, "Many arguments, please stop it!!!\n");
	mlx.map = map_check(argv[1], &(mlx.count));
	create_map(&mlx);
	mlx_string_put(mlx.mlx, mlx.win, 0, 10, 0x00000000, "0");
	mlx_hook(mlx.win, 2, 0, &close_map, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
