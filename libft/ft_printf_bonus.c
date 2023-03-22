/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:31:28 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:59 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_tomin(const char *s, va_list r, t_type t, int *num)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '%' && ++(*num))
			write (1, &s[i], 1);
		if (s[i] == '%' && (ft_strchr("cspdiuxX%# +", s[i + 1])))
		{
			if (ft_strchr("# +", s[i + 1]))
			{
				*num = *num + ft_printf_to_convertc
					(ft_printf_checkflags (&s[i], &t), r, &t);
				i = i + ft_printf_checkspases(&t);
				ft_printf_s_type(&t);
			}
			else
			{
				*num = *num + ft_printf_to_convertc (&s[i + 1], r, &t);
				i++;
			}
		}
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	r;
	t_type	t;
	int		num;

	num = 0;
	ft_printf_s_type(&t);
	va_start (r, s);
	ft_printf_tomin(s, r, t, &num);
	va_end(r);
	return (num);
}
