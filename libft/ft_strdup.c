/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:54:04 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/13 07:56:49 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;
	int		i;

	i = 0;
	r = (char *) ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (r == 0)
		return (0);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
