/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:18:14 by dham              #+#    #+#             */
/*   Updated: 2022/07/05 19:05:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	unsigned int	s_len;
	char			*re_val;

	if (!s)
		return (0);
	idx = 0;
	re_val = malloc(ft_strlen(s) + 1);
	if (!re_val)
		return (0);
	s_len = ft_strlen(s);
	while (idx < s_len)
	{
		re_val[idx] = f(idx, s[idx]);
		idx++;
	}
	re_val[idx] = 0;
	return (re_val);
}
