/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:58:57 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 18:13:16 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f' \
			|| c == '\v');
}

static int	overflow_multi_ten(int num)
{
	if (num > 2147483647 / 10)
		return (-1);
	if (num < -2147483648 / 10)
		return (0);
	return (1);
}

static int	overflow_add(int num, int add_num, int flag)
{
	if (flag > 0 && num > 2147483647 - add_num)
		return (-1);
	if (flag < 0 && num < -2147483648 - add_num)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	re_val;
	int	flag;

	flag = 1;
	re_val = 0;
	while (isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-' && str++)
		flag = -1;
	while (ft_isdigit(*str))
	{
		if (overflow_multi_ten(re_val) != 1)
			return (overflow_multi_ten(re_val));
		re_val *= 10;
		if (overflow_add(re_val, (*str - '0') * flag, flag) != 1)
			return (overflow_add(re_val, (*str - '0') * flag, flag));
		re_val += (*str - '0') * flag;
		str++;
	}
	return (re_val);
}
