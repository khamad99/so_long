/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:47 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/24 18:24:27 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int	c_bath(char **s, int x, int y, int *coll)
{
	if (x < 1 || y < 1 || s[x + 1] == NULL
		|| (size_t)y == ft_strlen(s[0]) - 1
		|| s[x][y] == '1' || s[x][y] == 'K')
		return (0);
	else if (s[x][y] == 'C')
		*coll = *coll - 1;
	s[x][y] = '1';
	if (*coll == 0)
		return (1);
	if (c_bath(s, x - 1, y, coll) > 0)
		return (2);
	if (c_bath(s, x, y - 1, coll) > 0)
		return (2);
	if (c_bath(s, x + 1, y, coll) > 0)
		return (2);
	if (c_bath(s, x, y + 1, coll) > 0)
		return (2);
	return (-1);
}

static int	e_bath(char **s, size_t len, int x, int y)
{
	if (x < 1 || y < 1 || s[x + 1] == NULL || (size_t)y == len - 1
		|| s[x][y] == '1' || s[x][y] == 'K')
		return (0);
	else if (s[x][y] == 'P')
		return (1);
	s[x][y] = '1';
	if (e_bath(s, len, x - 1, y) > 0)
		return (2);
	if (e_bath(s, len, x, y - 1) > 0)
		return (2);
	if (e_bath(s, len, x + 1, y) > 0)
		return (2);
	if (e_bath(s, len, x, y + 1) > 0)
		return (2);
	return (-1);
}

static int	counts_utils(char **s, t_count *count, int *i)
{
	int		j;

	while (s[++(*i)])
	{
		j = -1;
		while (s[*i][++j])
		{	
			if (s[*i][j] == 'E')
			{
				count->e_x = *i;
				count->e_y = j;
				count->e_count++;
			}
			else if (s[*i][j] == 'P')
				count->p_count++;
			else if (s[*i][j] == 'C')
				count->c_count++;
		}
	}
	return (count->e_y);
}

int	count_symbols(char *ss, int i)
{
	t_count		count;
	size_t		len;
	int			c;
	char		**s;
	char		**s2;

	s = ft_split(ss, '\n');
	len = ft_strlen(s[0]);
	count.p_count = 0;
	count.c_count = 0;
	count.e_count = 0;
	i = counts_utils(s, &count, &i);
	c = count.c_count;
	if (count.e_count != 1 || count.p_count != 1 || count.c_count == 0)
		errorh("You are not following the symbols role\n", s, ss);
	s2 = ft_split(ss, '\n');
	if (e_bath(s, len, count.e_x, count.e_y) != 2
		|| c_bath(s2, count.e_x, count.e_y, &count.c_count) != 2)
		errorh2("There are no vaild path to Exit or all C's\n", s, s2, ss);
	free_s(s);
	free_s(s2);
	return (c);
}
