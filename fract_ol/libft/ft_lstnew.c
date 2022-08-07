/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:47:12 by dham              #+#    #+#             */
/*   Updated: 2022/07/06 11:13:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*re_node;

	re_node = malloc(sizeof(t_list));
	if (!re_node)
		return (0);
	(re_node->content) = content;
	re_node->next = 0;
	return (re_node);
}
