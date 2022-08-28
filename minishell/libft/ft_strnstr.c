/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:44:26 by dham              #+#    #+#             */
/*   Updated: 2022/08/08 14:17:57 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *niddle, size_t len)
{
	size_t			idx;
	const size_t	nid_len = ft_strlen(niddle);

	if (nid_len == 0)
		return ((char *)haystack);
	idx = 0;
	if (!haystack[idx] || len < nid_len)
		return (0);
	while (haystack[idx] && idx < len - nid_len + 1)
	{
		if (haystack[idx] == *niddle && \
			ft_strncmp(&haystack[idx], niddle, nid_len) == 0)
		{
			return ((char *)&haystack[idx]);
		}
		idx++;
	}
	return (0);
}
