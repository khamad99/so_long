/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:31:28 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/16 20:24:01 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_s_type(t_type *t)
{
	t->check = 0;
	t->hash = 0;
	t->plus = 0;
	t->space = 0;
}

const char	*ft_printf_removeextraflags(const char *s, t_type *t)
{
	int	i;
	int	ii;

	i = 1;
	ii = 2;
	while ((s[i] == '#' || s[i] == '+') && ft_strchr("# +", s[ii]))
		ii++;
	while (s[i] == ' ' && ft_strchr("# +", s[ii]))
	{
		t->hash = 1;
		if (s[ii] == '+')
		{
			t->space = 0;
			t->plus = 1;
		}
		ii++;
	}
	if (t->plus || t->hash || t->space)
	{
		t->check = ii;
		return (&s[ii - 1]);
	}
	return (s);
}

const char	*ft_printf_checkflags(const char *s, t_type *t)
{
	if (s[1] == '#')
		t->hash = 1;
	if (s[1] == ' ')
		t->space = 1;
	if (s[1] == '+')
		t->plus = 1;
	return (ft_printf_removeextraflags(s, t));
}

int	ft_printf_checkspases(t_type *t)
{
	if (t->check)
		return (t->check);
	else
		return (0);
}
