/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:11:42 by dham              #+#    #+#             */
/*   Updated: 2022/07/10 12:53:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	return_value_i(int fieldw, int precision, int len, int flag);
static int	output_int(int resule, int fieldw, int precision, \
						unsigned char bit);

int	integer_put(unsigned char bit, int fieldw, int precision, va_list ap)
{
	int	result;
	int	result_len;
	int	flag;

	result = va_arg(ap, int);
	flag = 0;
	result_len = num_len(result);
	if (((bit & 16) == 16) || (((bit & 4) == 4)) || result < 0)
		flag = 1;
	if ((bit & 32) == 32 && !precision && !result)
	{
		if (excep_process_i(bit, &result_len, fieldw) < 0)
			return (-1);
	}
	else
	{
		if (output_int(result, fieldw, precision, bit) < 0)
			return (-1);
	}
	return (return_value_i(fieldw, precision, result_len, flag));
}

static int	output_int(int result, int fieldw, int precision, \
unsigned char bit)
{
	if ((bit & 8) == 8)
	{
		if (left_int(result, bit, fieldw, precision) < 0)
			return (-1);
	}
	else if ((bit & 1) == 1)
	{
		if (right_zero_int(result, bit, fieldw) < 0)
			return (-1);
	}
	else
	{
		if (right_int(result, bit, fieldw, precision) < 0)
			return (-1);
	}
	return (0);
}

static int	return_value_i(int fieldw, int precision, int len, int flag)
{
	if (len >= precision && len + flag > fieldw)
		return (len + flag);
	else if (len < precision && precision + flag > fieldw)
		return (precision + flag);
	else
		return (fieldw);
}
