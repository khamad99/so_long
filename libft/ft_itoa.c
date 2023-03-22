/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:35:35 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/13 07:54:49 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	toput(char *r, long int nb, long int d)
{
	if (nb == 0)
		r[0] = '0';
	if (nb < 0)
	{
		r[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		r[d - 1] = (nb % 10) + '0';
		nb = nb / 10;
		d--;
	}
}

char	*ft_itoa(int n)
{
	char		*r;
	long int	d;
	long int	i;
	long int	nm;

	d = 0;
	i = n;
	nm = n;
	while (i != 0)
	{
		i = i / 10;
		d++;
	}
	if (n <= 0)
		d++;
	r = ft_calloc((d + 1), sizeof(char));
	if (!r)
		return (0);
	toput(r, nm, d);
	r[d] = 0;
	return (r);
}
