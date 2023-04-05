/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:08:56 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/05 11:34:15 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_map(char *map)
{
	int		fd;
	int		i;
	char	r;
	char	*s;

	i = 0;
	if (ft_strncmp(ft_strrchr(map, '.'), ".ber", 5))
		errorh("Invalid file\n", NULL, NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		errorh("Invalid file\n", NULL, NULL);
	while (read(fd, &r, 1) > 0)
		i++;
	close(fd);
	if (i == 0)
		errorh("empty file\n", NULL, NULL);
	fd = open(map, O_RDONLY);
	s = ft_calloc (i + 1, sizeof(char));
	if (!s)
		errorh("error in mallocing\n", NULL, NULL);
	read(fd, s, i);
	s[i] = 0;
	return (s);
}

static char	**check_lenth(char *s)
{
	int		i;
	int		len;
	char	**split;

	split = ft_split(s, '\n');
	len = ft_strlen(split[0]);
	i = -1;
	while (split[++i])
		if (i > 57 || len > 102)
			errorh("map is too larg\n", split, s);
	return (split);
}

static void	symbols_checker2(char **s, int i, size_t len, char *ss)
{
	int	j;

	j = -1;
	if (s[i + 1] == NULL || i == 0)
	{
		while (s[i][++j])
			if (s[i][j] != '1')
				errorh("Invalid map\n", s, ss);
	}
	else
		while (s[i][++j])
			if (s[i][0] != '1' || s[i][len - 1] != '1')
				errorh("Invalid map\n", s, ss);
}

static void	symbols_checker(char *s)
{
	char	**split;
	int		j;
	int		i;
	size_t	len;

	i = -1;
	split = ft_split(s, '\n');
	if (!split || (*split) == 0)
		errorh ("error in spliting\n", NULL, s);
	len = ft_strlen(split[0]);
	while (split[++i])
	{
		j = -1;
		if (len != ft_strlen(split[i]))
			errorh("map lines not identical\n", split, s);
		while (split[i][++j])
			if (split[i][j] != '0' && split[i][j] != '1' && split[i][j] != 'C'
			&& split[i][j] != 'E' && split[i][j] != 'P' && split[i][j] != '\n'
			&& split[i][j] != 'K')
				errorh("Invalid symbols\n", split, s);
		symbols_checker2(split, i, len, s);
	}
	free_s(split);
}

char	**map_check(char *f, int *mlxcount)
{
	char	**map;
	char	*s;
	int		i;

	i = 0;
	s = read_map(f);
	symbols_checker(s);
	*mlxcount = count_symbols(s, i);
	map = check_lenth(s);
	free(s);
	return (map);
}
