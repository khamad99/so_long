/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:09:17 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/26 22:10:15 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc == 1)
		errorh("No map in arguments\n", NULL, NULL);
	if (argc > 2)
		errorh("only one argument is allowed\n", NULL, NULL);
	mlx.map = map_check(argv[1], &(mlx.count));
	create_map(&mlx);
	mlx_string_put(mlx.mlx, mlx.win, 0, 10, 0x00000000, "0");
	mlx_hook(mlx.win, 2, 0, &hooking_function, &mlx);
	mlx_hook(mlx.win, 17, 0, &close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
