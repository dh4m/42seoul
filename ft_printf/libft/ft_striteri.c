/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:29:28 by dham              #+#    #+#             */
/*   Updated: 2022/07/05 19:04:58 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;
	unsigned int	s_len;

	if (!s)
		return ;
	idx = 0;
	s_len = ft_strlen(s);
	while (idx < s_len)
	{
		f(idx, s + idx);
		idx++;
	}
}
