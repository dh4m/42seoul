/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:54:47 by dham              #+#    #+#             */
/*   Updated: 2022/07/06 14:51:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;

	if (!dst || !src)
		return (dst);
	if (dst > src && len > 0)
	{
		idx = len - 1;
		while (idx > 0)
		{
			((char *)dst)[idx] = ((char *)src)[idx];
			idx--;
		}
		((char *)dst)[idx] = ((char *)src)[idx];
	}
	else
	{
		idx = 0;
		while (idx < len)
		{
			((char *)dst)[idx] = ((char *)src)[idx];
			idx++;
		}
	}
	return (dst);
}
