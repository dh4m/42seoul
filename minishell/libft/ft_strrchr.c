/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:02:55 by dham              #+#    #+#             */
/*   Updated: 2022/08/08 14:38:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*re_ptr;

	re_ptr = 0;
	while (*s)
	{
		if ((char)*s == (char)c)
			re_ptr = s;
		s++;
	}
	if ((char)*s == (char)c)
		re_ptr = s;
	return ((char *)re_ptr);
}
