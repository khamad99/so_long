/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:06:50 by kalshaer          #+#    #+#             */
/*   Updated: 2022/08/10 10:41:13 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	index2;

	if (!*needle)
		return ((char *)haystack);
	index2 = 0;
	while (haystack[index2])
	{
		index = 0;
		while (haystack[index2 + index] == needle[index]
			&& index2 + index < len)
		{
			index++;
			if (!needle[index])
				return ((char *)(haystack + index2));
		}
		index2++;
	}
	return (0);
}
