/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:30 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/16 20:24:10 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_flags5(const char *s, va_list r, t_type *t)
{
	int	num;
	int	i;

	num = 0;
	if (t->plus && *(s + 1) == 'i')
	{
		i = va_arg (r, int);
		if (i >= 0)
		{
			ft_putstr_fd("+", 1);
			num = num + 1;
		}
		ft_putnbr_fd(i, 1);
		return (num + ft_printf_countdigit(i));
	}
	return (ft_printf_flags6(s, r, t));
}

int	ft_printf_flags6(const char *s, va_list r, t_type *t)
{
	int	num;
	int	d;

	num = 0;
	if (t->plus && *(s + 1) == 'd')
	{
		d = va_arg (r, int);
		if (d >= 0)
		{
			ft_putstr_fd("+", 1);
			num = num + 1;
		}
		ft_putnbr_fd(d, 1);
		return (num + ft_printf_countdigit(d));
	}
	return (ft_printf_flags7(s, r, t));
}

int	ft_printf_flags7(const char *s, va_list r, t_type *t)
{
	char	*ss;

	if (t->space && *(s + 1) == 's')
	{
		ss = va_arg (r, char *);
		if (!ss)
		{
			ft_putstr_fd("(null)", 1);
			return (ft_strlen("(null)"));
		}
		else
		{
			ft_putstr_fd(ss, 1);
			return (ft_strlen(ss));
		}
	}
	return (0);
}
