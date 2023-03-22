/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:55:50 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/13 14:51:40 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int i3)
{
	char	*r;
	int		i;
	int		ii;

	if (!s2)
		return (0);
	r = (char *) ft_calloc(1, ft_strlen((char *) s1)
			+ ft_strlen((char *)s2) + 3);
	if (!r)
		return (0);
	i = 0;
	ii = 0;
	while (s1[i])
		r[ii++] = s1[i++];
	r[ii++] = ' ';
	i = 0;
	while (s2[i])
		r[ii++] = s2[i++];
	r[ii++] = ' ';
	r[ii] = 0;
	if (i3 != 2)
		free(s1);
	return (r);
}
