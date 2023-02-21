/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:54:53 by dham              #+#    #+#             */
/*   Updated: 2022/07/06 10:59:12 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list_idx;

	if (!lst || !*lst || !del)
		return ;
	list_idx = *lst;
	while (list_idx)
	{
		list_idx = list_idx->next;
		ft_lstdelone(*lst, del);
		*lst = list_idx;
	}
}
