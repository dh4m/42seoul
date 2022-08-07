/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:43:19 by dham              #+#    #+#             */
/*   Updated: 2022/07/05 19:05:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re_val;

	if (!s1 || !s2)
		return (0);
	re_val = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!re_val)
		return (0);
	ft_strlcpy(re_val, s1, ft_strlen(s1) + 1);
	ft_strlcat(re_val, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (re_val);
}
