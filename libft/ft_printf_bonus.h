/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:34:05 by kalshaer          #+#    #+#             */
/*   Updated: 2022/10/05 14:41:31 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct t_type
{
	int	space;
	int	hash;
	int	plus;
	int	check;
}	t_type;

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