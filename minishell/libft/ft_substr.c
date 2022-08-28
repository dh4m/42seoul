/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:29:06 by dham              #+#    #+#             */
/*   Updated: 2022/08/08 14:59:40 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*re_val;
	const size_t	s_len = ft_strlen(s);

	if (!s)
		return (0);
	if (s_len < start)
	{
		re_val = malloc(1);
		*re_val = 0;
		return (re_val);
	}
	if (s_len - start > len)
		re_val = malloc(len + 1);
	else
		re_val = malloc(s_len - start + 1);
	if (!re_val)
		return (0);
	if (s_len - start > len)
		ft_strlcpy(re_val, &s[start], len + 1);
	else
		ft_strlcpy(re_val, &s[start], s_len - start + 1);
	return (re_val);
}
