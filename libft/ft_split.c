/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:52:50 by kalshaer          #+#    #+#             */
/*   Updated: 2022/08/23 08:02:55 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**hmalloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	countw(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			w++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		w++;
	return (w);
}

static char	**min(char const *s, char c, char **r, int i)
{
	size_t	len;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			r[i] = ft_substr(s, 0, len);
			if (!r[i])
				return (hmalloc(r));
			s = s + len;
			i++;
		}
	}
	r[i] = NULL;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		i;

	if (!s)
		return (0);
	r = (char **)malloc((countw(s, c) + 1) * sizeof(char *));
	if (!r)
		return (0);
	i = 0;
	r = min (s, c, r, i);
	return (r);
}
