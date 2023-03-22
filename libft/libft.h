/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:12:50 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/16 14:09:19 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<stdio.h>
# include	<stdint.h>
# include	<stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 90
# endif

typedef struct t_type
{
	void	*content;
	int		space;
	int		hash;
	int		plus;
	int		check;
}	t_type;

typedef struct s_list
{
	void			*content;
	int				num;
	int				pos;
	int				moves;
	long			order;
	struct s_list	*next;
}	t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
long long	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2, int i);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(int content, int pos);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

size_t		ft_gnl_strlen(const char *s);
char		*ft_gnl_strchr(char *s, int c, size_t i);
char		*ft_gnl_strjoin(char *s1, char *s2);
size_t		ft_gnl_strlcpy(char *dst, char *src, size_t dstsize);
void		*ft_gnl_calloc(size_t count, size_t size);
char		*read_buff(int fd, char *r);
char		*toprint(char *p);
char		*lft(char *r);
char		*get_next_line(int fd);

int			ft_printf(const char *s, ...);
void		ft_printf_tomin(const char *s, va_list r, t_type t, int *num);
int			ft_printf_countdigit(int d);
const char	*ft_printf_removeextraflags(const char *s, t_type *t);
void		ft_printf_s_type(t_type *t);
const char	*ft_printf_checkflags(const char *s, t_type *t);
int			ft_printf_checkspases(t_type *t);
int			ft_printf_to_convertc(const char *s, va_list r, t_type *t);
int			ft_printf_to_converts(const char *s, va_list r, t_type *t);
int			ft_printf_to_convertp(const char *s, va_list r, t_type *t);
int			ft_printf_to_convertdi(const char *s, va_list r, t_type *t);
int			ft_printf_to_convertuxxx(const char *s, va_list r, t_type *t);
int			ft_printf_flags(const char *s, va_list r, t_type *t);
int			ft_printf_flags2(const char *s, va_list r, t_type *t);
int			ft_printf_flags3(const char *s, va_list r, t_type *t);
int			ft_printf_flags4(const char *s, va_list r, t_type *t);
int			ft_printf_flags5(const char *s, va_list r, t_type *t);
int			ft_printf_flags6(const char *s, va_list r, t_type *t);
int			ft_printf_flags7(const char *s, va_list r, t_type *t);
void		ft_printf_putusnbr(unsigned int u, int *i);
void		ft_printf_printp(size_t p, int *i, char *base);
void		ft_printf_printx(unsigned int x, int *i, char *base);
void		ft_printf_printxx(unsigned int xx, int *i, char *base);

#endif