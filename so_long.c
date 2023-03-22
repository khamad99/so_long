/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:09:17 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/22 13:13:33 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
}

int	hooking_function(int key, t_mlx *mlx)
{
	static int	count;
	char		*s;

	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else if (key == 13 || key == 126)
		to_up(mlx, &count);
	else if (key == 2 || key == 124)
		to_right(mlx, &count);
	else if (key == 1 || key == 125)
		to_down(mlx, &count);
	else if (key == 0 || key == 123)
		to_left(mlx, &count);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->w.icon, 0, 0);
	s = ft_itoa(count);
	mlx_string_put(mlx->mlx, mlx->win, 0, 10, 0x00FF0000, s);
	free(s);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc == 1)
		errorh("No map in arguments\n");
	if (argc > 2)
		errorh("only one argument is allowed\n");
	mlx.map = map_check(argv[1], &(mlx.count));
	create_map(&mlx);
	mlx_string_put(mlx.mlx, mlx.win, 0, 10, 0x00FF0000, "0");
	mlx_hook(mlx.win, 2, 0, &hooking_function, &mlx);
	mlx_hook(mlx.win, 17, 0, &close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
