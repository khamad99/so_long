/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_to_convert_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:17:24 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/16 20:24:16 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_to_convertc(const char *s, va_list r, t_type *t)
{
	if (*s == 'c')
	{
		ft_putchar_fd(va_arg (r, int), 1);
		return (1);
	}
	if (*s == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}	
	return (ft_printf_to_converts(s, r, t));
}

int	ft_printf_to_converts(const char *s, va_list r, t_type *t)
{
	char	*ss;

	if (*s == 's')
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
	return (ft_printf_to_convertp(s, r, t));
}

int	ft_printf_to_convertp(const char *s, va_list r, t_type *t)
{
	int	num;

	num = 1;
	if (*s == 'p')
	{
		ft_putstr_fd("0x", 1);
		num = num + 2;
		ft_printf_printp((unsigned long)va_arg(r, void *),
			&num, "0123456789abcdef");
		return (num);
	}
	return (ft_printf_to_convertdi(s, r, t));
}

int	ft_printf_to_convertdi(const char *s, va_list r, t_type *t)
{
	int	d;
	int	i;

	if (*s == 'd')
	{
		d = va_arg (r, int);
		ft_putnbr_fd(d, 1);
		return (ft_printf_countdigit(d));
	}
	if (*s == 'i')
	{
		i = va_arg (r, int);
		ft_putnbr_fd(i, 1);
		return (ft_printf_countdigit(i));
	}
	return (ft_printf_to_convertuxxx(s, r, t));
}

int	ft_printf_to_convertuxxx(const char *s, va_list r, t_type *t)
{
	unsigned int	u;
	int				num;

	num = 1;
	if (*s == 'u')
	{
		u = va_arg (r, unsigned int);
		ft_printf_putusnbr(u, &num);
		return (num);
	}
	if (*s == 'x')
	{
		ft_printf_printx(va_arg (r, int), &num, "0123456789abcdef");
		return (num);
	}
	if (*s == 'X')
	{
		ft_printf_printxx(va_arg (r, int), &num, "0123456789ABCDEF");
		return (num);
	}
	return (ft_printf_flags(s, r, t));
}
