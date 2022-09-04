/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:54:39 by dham              #+#    #+#             */
/*   Updated: 2022/09/04 20:17:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	isset(char c, char const *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*re_val;
	int				idx;

	if (!s1)
		return (0);
	while (isset(*s1, set) && *s1)
		s1++;
	idx = ft_strlen(s1) - 1;
	while (idx >= 0 && isset(s1[idx], set))
		idx--;
	re_val = malloc(idx + 2);
	if (!re_val)
		return (0);
	ft_strlcpy(re_val, s1, idx + 2);
	return (re_val);
}
