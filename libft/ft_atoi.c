/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:19:39 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/24 20:41:26 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	s;
	size_t		r;

	s = 1;
	r = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str
		== '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	if (s == -1 && r > 9223372036854775807)
		return (0);
	else if (s == 1 && r >= 9223372036854775807)
		return (-1);
	return (r * s);
}
