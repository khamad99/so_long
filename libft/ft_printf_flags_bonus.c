/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:30 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/16 20:24:06 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_flags(const char *s, va_list r, t_type *t)
{
	int	num;
	int	x;

	num = 1;
	if (t->hash && *(s + 1) == 'x')
	{
		x = va_arg (r, int);
		if (x != 0)
		{
			ft_putstr_fd("0x", 1);
			num = num + 2;
		}
		ft_printf_printx(x, &num, "0123456789abcdef");
		return (num);
	}
	return (ft_printf_flags2(s, r, t));
}

int	ft_printf_flags2(const char *s, va_list r, t_type *t)
{
	int	num;
	int	x;

	num = 1;
	if (t->hash && *(s + 1) == 'X')
	{
		x = va_arg (r, int);
		if (x != 0)
		{
			ft_putstr_fd("0X", 1);
			num = num + 2;
		}
		ft_printf_printxx(x, &num, "0123456789ABCDEF");
		return (num);
	}
	return (ft_printf_flags3(s, r, t));
}

int	ft_printf_flags3(const char *s, va_list r, t_type *t)
{
	int	num;
	int	d;

	num = 0;
	if (t->space && !t->plus && *(s + 1) == 'd')
	{
		d = va_arg (r, int);
		if (d >= 0)
		{
			ft_putstr_fd(" ", 1);
			num = num + 1;
		}
		ft_putnbr_fd(d, 1);
		return (num + ft_printf_countdigit(d));
	}
	return (ft_printf_flags4(s, r, t));
}

int	ft_printf_flags4(const char *s, va_list r, t_type *t)
{
	int	num;
	int	i;

	num = 0;
	if (t->space && !t->plus && *(s + 1) == 'i')
	{
		i = va_arg (r, int);
		if (i >= 0)
		{
			ft_putstr_fd(" ", 1);
			num = num + 1;
		}
		ft_putnbr_fd(i, 1);
		return (num + ft_printf_countdigit(i));
	}
	return (ft_printf_flags5(s, r, t));
}
