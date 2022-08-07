/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:34:07 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 18:12:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	idx;

	if (!dstsize)
		return (ft_strlen(src));
	idx = 0;
	while (src[idx] && --dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (ft_strlen(src));
}
