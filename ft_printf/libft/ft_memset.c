/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:09:30 by dham              #+#    #+#             */
/*   Updated: 2022/07/06 14:52:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			idx;
	unsigned char	*mem;

	if (!b)
		return (b);
	idx = 0;
	mem = b;
	while (idx < len)
	{
		mem[idx] = (unsigned char)c;
		idx++;
	}
	return (b);
}
