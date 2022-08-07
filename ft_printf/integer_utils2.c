/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:51:58 by dham              #+#    #+#             */
/*   Updated: 2022/07/09 22:07:51 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	flag_output(int num, int *flag, unsigned char bit)
{
	if (num < 0 && ++*flag)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
	}
	else if ((bit & 16) == 16 && ++*flag)
	{
		if (write(1, "+", 1) < 0)
			return (-1);
	}
	else if (((bit & 4) == 4) && ++*flag)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
	}
	return (0);
}

int	right_zero_int(int num, unsigned char bit, int fieldw)
{
	int	len;
	int	flag;

	len = num_len(num);
	flag = 0;
	if (flag_output(num, &flag, bit) < 0)
		return (-1);
	if (filling('0', fieldw - len - flag) < 0 || print_abs_num(num) < 0)
		return (-1);
	return (0);
}

int	left_int(int num, unsigned char bit, int fieldw, int precision)
{
	int	len;
	int	flag;

	len = num_len(num);
	flag = 0;
	if (flag_output(num, &flag, bit) < 0)
		return (-1);
	if (filling('0', precision - len) < 0 || print_abs_num(num) < 0)
		return (-1);
	if (precision - len > 0)
	{
		if (filling(' ', fieldw - precision - flag) < 0)
			return (-1);
	}
	else
	{
		if (filling(' ', fieldw - len - flag) < 0)
			return (-1);
	}
	return (0);
}

int	right_int(int num, unsigned char bit, int fieldw, int precision)
{
	int	len;
	int	flag;

	len = num_len(num);
	flag = 0;
	if (((bit & 16) == 16) || (((bit & 4) == 4) && num) || num < 0)
		flag = 1;
	if (precision - len > 0)
	{
		if (filling(' ', fieldw - precision - flag) < 0)
			return (-1);
	}
	else
	{
		if (filling(' ', fieldw - len - flag) < 0)
			return (-1);
	}
	if (flag_output(num, &flag, bit) < 0)
		return (-1);
	if (filling('0', precision - len) < 0 || print_abs_num(num) < 0)
		return (-1);
	return (0);
}

int	return_value_u(int fieldw, int precision, int len)
{
	if (len >= precision && len > fieldw)
		return (len);
	else if (len < precision && precision > fieldw)
		return (precision);
	else
		return (fieldw);
}
