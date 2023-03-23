/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:56 by kalshaer          #+#    #+#             */
/*   Updated: 2023/03/23 14:19:27 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errorh(char *s)
{
	ft_printf ("Error\n%s", s);
	exit(1);
}

void	read_map(char **s, char *file)
{
	int		fd;
	int		i;
	char	r;

	i = 0;
	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 4))
		errorh("Invalid file\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		errorh("Invalid file\n");
	while (read(fd, &r, 1) > 0)
		i++;
	close(fd);
	if (i == 0)
		errorh("empty file\n");
	fd = open(file, O_RDONLY);
	*s = ft_calloc (i + 1, sizeof(char));
	if (!s)
		errorh("error in mallocing\n");
	read(fd, *s, i);
	(*s)[i] = 0;
}

void	symbols_checker(char **split, int j, int i, size_t len)
{
	len = ft_strlen(split[0]);
	while (split[++i])
	{
		j = -1;
		if (len != ft_strlen(split[i]))
			errorh("map lines not identical\n");
		while (split[i][++j])
			if (split[i][j] != '0' && split[i][j] != '1' && split[i][j] != 'C'
			&& split[i][j] != 'E' && split[i][j] != 'P' && split[i][j] != '\n'
			&& split[i][j] != 'K')
				errorh("Invalid symbols\n");
		j = -1;
		if (split[i + 1] == NULL || i == 0)
		{
			while (split[i][++j])
				if (split[i][j] != '1')
					errorh("Invalid map\n");
		}
		else
			while (split[i][++j])
				if (split[i][0] != '1' || split[i][len - 1] != '1')
					errorh("Invalid map\n");
	}
}

char	**map_check(char *file, int *mlxcount)
{
	char	**split;
	int		len;
	char	*s;
	int		i;

	read_map(&s, file);
	split = ft_split(s, '\n');
	if (!split || !(*split))
		errorh ("error in spliting\n");
	symbols_checker(split, 0, -1, 0);
	*mlxcount = count_symbols(ft_split(s, '\n'));
	len = ft_strlen(split[0]);
	i = -1;
	free(s);
	while (split[++i])
		if (i > 20 || len > 40)
			errorh("map is too larg\n");
	return (split);
}