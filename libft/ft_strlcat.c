/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:58:42 by kalshaer          #+#    #+#             */
/*   Updated: 2022/08/17 07:33:05 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ii;
	size_t	r;

	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	else
		r = ft_strlen(src) + ft_strlen(dst);
	i = ft_strlen(dst);
	ii = 0;
	while (src[ii] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[ii];
		ii++;
		i++;
	}
	dst[i] = '\0';
	return (r);
}
