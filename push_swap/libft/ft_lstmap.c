/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:57:18 by dham              #+#    #+#             */
/*   Updated: 2022/07/06 11:09:22 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*re_list;
	t_list	*new_node;

	if (!lst || !f)
		return (0);
	re_list = 0;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			if (del)
				ft_lstclear(&re_list, del);
			return (0);
		}
		ft_lstadd_back(&re_list, new_node);
		lst = lst->next;
	}
	return (re_list);
}
