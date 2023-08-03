/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:58:57 by dham              #+#    #+#             */
/*   Updated: 2023/03/18 22:01:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include <stdio.h>

int	_checking_argument(const char *str)
{
	int	i;
	int dot;

	i = 0;
	dot = 0;
	if (str[i] == '+' || str[i] == '-')
		i ++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (dot == 1)
				return (0);
			dot = 1;
			i++;
		}
		if (('0' > str[i] || str[i] > '9'))
			return (0);
		i ++;
	}
	return (1);
}

float	ft_atof(const char *str)
{
	float		re_val;
	float		tmp;
	int			i;
	const char	*word = ft_strchr(str, '.');

	if (!str || !_checking_argument(str))
		return (NAN);
	re_val = ft_atoi(str);
	tmp = 0;
	if (!word)
		return (re_val);
	i = ft_strlen(word + 1);
	while (i)
	{
		tmp += word[i] - '0';
		tmp *= 0.1;
		i --;
	}
	if (str[0] == '-')
		re_val -= tmp;
	else
		re_val += tmp;
	return (re_val);
}
