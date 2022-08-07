/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:29:06 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 17:14:54 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*re_val;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		re_val = malloc(1);
		if (!re_val)
			return (0);
		*re_val = 0;
		return (re_val);
	}
	if (ft_strlen(s) - start > len)
		re_val = malloc(len + 1);
	else
		re_val = malloc(ft_strlen(s) - start + 1);
	if (!re_val)
		return (0);
	ft_strlcpy(re_val, &s[start], len + 1);
	return (re_val);
}
