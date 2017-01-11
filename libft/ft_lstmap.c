/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 02:23:25 by aviau             #+#    #+#             */
/*   Updated: 2015/12/28 02:23:44 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *list;

	begin = NULL;
	if (lst)
	{
		list = f(lst);
		begin = list;
		while (lst->next)
		{
			list->next = f(lst->next);
			list = list->next;
			lst = lst->next;
		}
		list = f(lst);
	}
	return (begin);
}
