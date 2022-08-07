/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:43:09 by dham              #+#    #+#             */
/*   Updated: 2022/07/10 12:54:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static void	left_unsign(unsigned int num, int fieldw, int precision);
static void	right_unsign(unsigned int num, int fieldw, int precision);
static void	right_zero_unsign(unsigned int num, int fieldw);
static void	print_unsign(unsigned int num);

int	unsign_put(unsigned char bit, int fieldw, int precision, va_list ap)
{
	unsigned int	result;
	int				result_len;

	result = va_arg(ap, unsigned int);
	result_len = num_len(result);
	if ((bit & 32) == 32 && !precision && !result)
		excep_process_i(0, &result_len, fieldw);
	else if ((bit & 8) == 8)
		left_unsign(result, fieldw, precision);
	else if ((bit & 1) == 1)
		right_zero_unsign(result, fieldw);
	else
		right_unsign(result, fieldw, precision);
	return (return_value_u(fieldw, precision, result_len));
}

static void	left_unsign(unsigned int num, int fieldw, int precision)
{
	int	len;

	len = num_len(num);
	filling('0', precision - len);
	print_unsign(num);
	if (precision - len > 0)
		filling(' ', fieldw - precision);
	else
		filling(' ', fieldw - len);
}

static void	right_unsign(unsigned int num, int fieldw, int precision)
{
	int	len;

	len = num_len(num);
	if (precision - len > 0)
		filling(' ', fieldw - precision);
	else
		filling(' ', fieldw - len);
	filling('0', precision - len);
	print_unsign(num);
}

static void	right_zero_unsign(unsigned int num, int fieldw)
{
	int	len;

	len = num_len(num);
	filling('0', fieldw - len);
	print_unsign(num);
}

static void	print_unsign(unsigned int num)
{
	char	buffer;

	if (num < 10)
	{
		buffer = (int)num + '0';
		write(1, &buffer, 1);
		return ;
	}
	print_unsign(num / 10);
	buffer = (int)(num % 10) + '0';
	write(1, &buffer, 1);
}
