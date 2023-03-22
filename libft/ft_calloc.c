/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:30:28 by kalshaer          #+#    #+#             */
/*   Updated: 2022/08/23 07:57:26 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	r = (void *) malloc(count * size);
	if (!r)
		return (0);
	ft_bzero(r, (count * size));
	return ((void *)r);
}
