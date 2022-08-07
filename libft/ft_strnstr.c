/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:44:26 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 18:39:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *niddle, size_t len)
{
	size_t	idx;

	if (ft_strlen(niddle) == 0)
		return ((char *)haystack);
	idx = 0;
	if (len < ft_strlen(niddle))
		return (0);
	while (idx < len - ft_strlen(niddle) + 1)
	{
		if (haystack[idx] == *niddle && \
			ft_strncmp(&haystack[idx], niddle, ft_strlen(niddle)) == 0)
		{
			return ((char *)&haystack[idx]);
		}
		idx++;
	}
	return (0);
}
