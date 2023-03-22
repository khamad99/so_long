/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:48:57 by kalshaer          #+#    #+#             */
/*   Updated: 2022/08/16 21:41:21 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len == 0 || dst == src)
		return (dst);
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len > 0)
		{
			*((unsigned char *)dst + len - 1) = *((unsigned char *)
					src + len - 1);
			len--;
		}
		return (dst);
	}
}
