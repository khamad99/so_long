/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:04:48 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/22 11:04:44 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if(!s1)
		return (-3);

	i = 0;
	while (i < n)
	{
		if (s1[i] != 0 && s1[i] == s2[i])
		{
			while (s1[i] != 0 && s1[i] == s2[i] && i < n)
			i++;
		}
		else if (((unsigned char) s1[i] - (unsigned char) s2[i]) < 0)
			return (-1);
		else if (((unsigned char) s1[i] - (unsigned char) s2[i]) > 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
