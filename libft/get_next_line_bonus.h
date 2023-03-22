/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:26:45 by kalshaer          #+#    #+#             */
/*   Updated: 2023/01/16 20:18:30 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 90
# endif

size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(char *s, int c, size_t i);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_gnl_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_gnl_calloc(size_t count, size_t size);
char	*read_buff(int fd, char *r);
char	*toprint(char *p);
char	*lft(char *r);
char	*get_next_line(int fd);

#endif