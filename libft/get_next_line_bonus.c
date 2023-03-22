/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:26:34 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/23 09:17:10 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_buff(int fd, char *r)
{
	char	*f;
	int		size;

	f = (char *) ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!f)
		return (NULL);
	size = 1;
	while (!ft_gnl_strchr(r, '\n', size) && size)
	{
		size = read(fd, f, BUFFER_SIZE);
		if (size == -1)
		{
			free (f);
			return (NULL);
		}
		f[size] = '\0';
		r = ft_gnl_strjoin(r, f);
	}
	free(f);
	return (r);
}

char	*toprint(char *p)
{
	size_t	i;
	char	*r;

	i = 0;
	if (!p[i])
		return (NULL);
	while (p[i] != '\n' && p[i])
		i++;
	r = (char *)ft_gnl_calloc(i + 2, sizeof(char));
	ft_gnl_strlcpy(r, p, (i + 2));
	return (r);
}

char	*lft(char *r)
{
	size_t	len;
	size_t	i;
	char	*l;

	len = ft_gnl_strlen(r);
	i = 0;
	while (r[i] && r[i] != '\n')
		i++;
	if (!r[i + 1] || !r[i])
	{
		free (r);
		return (NULL);
	}
	l = (char *) ft_gnl_calloc (len - i + 1, sizeof(char));
	if (!l)
		return (NULL);
	i++;
	ft_gnl_strlcpy(l, &r[i], (len - i + 1));
	free (r);
	return (l);
}

char	*get_next_line(int fd)
{
	static char	*r[1024];
	char		*p;

	if (fd >= 0)
	{
		r[fd] = read_buff(fd, r[fd]);
		if (!r[fd] || BUFFER_SIZE < 0)
			return (NULL);
		p = toprint(r[fd]);
		r[fd] = lft(r[fd]);
		return (p);
	}
	return (0);
}
