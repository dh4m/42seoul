/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:20:52 by dham              #+#    #+#             */
/*   Updated: 2022/07/06 13:49:51 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*re_val;

	re_val = malloc(ft_strlen(s1) + 1);
	if (!re_val)
		return (0);
	ft_strlcpy(re_val, s1, ft_strlen(s1) + 1);
	return (re_val);
}
