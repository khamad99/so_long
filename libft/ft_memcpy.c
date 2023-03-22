/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:46:48 by kalshaer          #+#    #+#             */
/*   Updated: 2022/07/30 11:15:14 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || src == dst)
		return (dst);
	i = 0;
	while (i < n)
	{
		*((unsigned char *) dst + i) = *((unsigned char *) src + i);
		i++;
	}
	return (dst);
}
