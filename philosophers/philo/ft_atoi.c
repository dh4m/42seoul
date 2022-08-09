/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:16:00 by dham              #+#    #+#             */
/*   Updated: 2022/08/09 15:35:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f' \
			|| c == '\v');
}

static int	overflow_multi_ten(int num)
{
	if (num > 2147483647 / 10)
		return (-1);
	return (1);
}

static int	overflow_add(int num, int add_num)
{
	if (num > 2147483647 - add_num)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	re_val;

	re_val = 0;
	while (isspace(*str))
		str++;
	if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (overflow_multi_ten(re_val) != 1)
			return (-1);
		re_val *= 10;
		if (overflow_add(re_val, (*str - '0')) != 1)
			return (-1);
		re_val += (*str - '0');
		str++;
	}
	while (isspace(*str))
		str++;
	if (*str != 0)
		return (-1);
	return (re_val);
}