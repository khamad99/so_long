/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:47 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/22 13:41:59 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_s(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int	rec_for_c(char **split, int x, int y, int *coll)
{
	if (x < 1 || y < 1 || split[x + 1] == NULL
		|| (size_t)y == ft_strlen(split[0]) - 1
		|| split[x][y] == '1' || split[x][y] == 'K')
		return (0);
	else if (split[x][y] == 'C')
		*coll = *coll - 1;
	split[x][y] = '1';
	if (*coll == 0)
		return (1);
	if (rec_for_c(split, x - 1, y, coll) > 0)
		return (2);
	if (rec_for_c(split, x, y - 1, coll) > 0)
		return (2);
	if (rec_for_c(split, x + 1, y, coll) > 0)
		return (2);
	if (rec_for_c(split, x, y + 1, coll) > 0)
		return (2);
	return (-1);
}

int	rec_for_e(char **split, size_t len, int x, int y)
{
	if (x < 1 || y < 1 || split[x + 1] == NULL || (size_t)y == len - 1 \
		|| split[x][y] == '1' || split[x][y] == 'K')
		return (0);
	else if (split[x][y] == 'P')
		return (1);
	split[x][y] = '1';
	if (rec_for_e(split, len, x - 1, y) > 0)
		return (2);
	if (rec_for_e(split, len, x, y - 1) > 0)
		return (2);
	if (rec_for_e(split, len, x + 1, y) > 0)
		return (2);
	if (rec_for_e(split, len, x, y + 1) > 0)
		return (2);
	return (-1);
}

int	counts_norm(char **s, t_count *a, int *i)
{
	int		j;

	while (s[++(*i)])
	{
		j = -1;
		while (s[*i][++j])
		{	
			if (s[*i][j] == 'E')
			{
				a->e_x = *i;
				a->e_y = j;
				a->e_count++;
			}
			else if (s[*i][j] == 'P')
				a->p_count++;
			else if (s[*i][j] == 'C')
				a->c_count++;
		}
	}
	return (a->e_y);
}

int	count_symbols(char **s)
{
	t_count		a;
	int			i;
	size_t		len;
	int			c;
	
	len = ft_strlen(s[0]);
	i = -1;
	a.p_count = 0;
	a.c_count = 0;
	a.e_count = 0;
	i = counts_norm(s, &a, &i);
	c = a.c_count;
	if (a.e_count != 1 || a.p_count != 1 || a.c_count == 0)
		errorh("You are not following the symbols role\n");
	if (rec_for_e(s, len, a.e_x, a.e_y != 2)
		|| rec_for_c(s, a.e_x, a.e_y, &a.c_count) != 2)
		errorh("There are no vaild path to Exit or all C's\n");
	free_s(s);
	return (c);
}
