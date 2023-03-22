/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:37:21 by kalshaer          #+#    #+#             */
/*   Updated: 2023/02/01 12:21:21 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content, int pos)
{
	t_list	*r;

	r = ft_calloc(1, sizeof(t_list));
	if (!r)
		return (0);
	r->num = content;
	r->pos = pos;
	r->next = NULL;
	return (r);
}
