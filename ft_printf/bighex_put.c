/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bighex_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:06:45 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 16:48:13 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	left_hex(unsigned int num, int fieldw, int precision, int flag);
static int	right_hex(unsigned int num, int fieldw, int precision, int flag);
static int	right_zero_hex(unsigned int num, int fieldw, int flag);
static int	output_bhex(unsigned char bit, int width[2], int hex_flag, \
						unsigned int result);

int	bighex_put(unsigned char bit, int fieldw, int precision, va_list ap)
{
	unsigned int	result;
	int				result_len;
	int				flag;

	result = va_arg(ap, unsigned int);
	result_len = hex_len(result);
	flag = 0;
	if ((bit & 2) == 2 && result)
		flag = 2;
	if ((bit & 32) == 32 && !precision && !result)
	{
		if (excep_process_x(&flag, &result_len, fieldw) < 0)
			return (-1);
	}
	else
	{
		if (output_bhex(bit, (int [2]){fieldw, precision}, flag, result) < 0)
			return (-1);
	}
	return (return_value_x(fieldw, precision, result_len, flag));
}

static int	output_bhex(unsigned char bit, int width[2], int hex_flag, \
unsigned int result)
{
	if ((bit & 8) == 8)
	{
		if (left_hex(result, width[0], width[1], hex_flag) < 0)
			return (-1);
	}
	else if ((bit & 1) == 1)
	{
		if (right_zero_hex(result, width[0], hex_flag) < 0)
			return (-1);
	}
	else
	{
		if (right_hex(result, width[0], width[1], hex_flag) < 0)
			return (-1);
	}
	return (0);
}

static int	left_hex(unsigned int num, int fieldw, int precision, int flag)
{
	int	len;

	len = hex_len(num);
	if (flag)
	{
		if (write(1, "0X", 2) < 0)
			return (-1);
	}
	if (filling('0', precision - len) < 0 || print_bhex(num) < 0)
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

static int	right_hex(unsigned int num, int fieldw, int precision, int flag)
{
	int	len;

	len = hex_len(num);
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
	if (flag)
	{
		if (write(1, "0X", 2) < 0)
			return (-1);
	}
	if (filling('0', precision - len) < 0 || print_bhex(num) < 0)
		return (-1);
	return (0);
}

static int	right_zero_hex(unsigned int num, int fieldw, int flag)
{
	int	len;

	len = hex_len(num);
	if (flag)
	{
		if (write(1, "0X", 2) < 0)
			return (-1);
	}
	if (filling('0', fieldw - len - flag) < 0 || print_bhex(num) < 0)
		return (-1);
	return (0);
}
