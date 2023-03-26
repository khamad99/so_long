/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:54:05 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/26 16:56:44 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destory(char *s, t_mlx *mlx)
{
	if (s)
		ft_printf ("%s", s);
	mlx_destroy_image(mlx->mlx, mlx->p.img);
	mlx_destroy_image(mlx->mlx, mlx->w.img);
	mlx_destroy_image(mlx->mlx, mlx->s.img);
	mlx_destroy_image(mlx->mlx, mlx->c.img);
	mlx_destroy_image(mlx->mlx, mlx->e.img);
	mlx_destroy_image(mlx->mlx, mlx->sh.img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_s(mlx->map);
	exit (0);
}

void	errorh(char *s, char **split, char *ss)
{
	ft_printf ("Error\n%s", s);
	if (ss)
		free (ss);
	if (split)
		free_s(split);
	exit(1);
}

void	errorh2(char *s, char **split, char **split2, char *ss)
{
	ft_printf ("Error\n%s", s);
	if (ss)
		free (ss);
	if (split)
		free_s(split);
	if (split2)
		free_s(split2);
	exit(1);
}

void	free_s(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}
