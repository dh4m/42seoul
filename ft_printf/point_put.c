/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:15:39 by dham              #+#    #+#             */
/*   Updated: 2022/07/12 10:45:20 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	hex_write(unsigned long long num);

int	point_put(unsigned char bit, int fieldw, va_list ap)
{
	int				left;
	void			*result;
	int				result_len;

	left = ((bit & 8) == 8);
	result = va_arg(ap, void *);
	result_len = hex_len((unsigned long long)result);
	if (left)
	{
		if (hex_write((unsigned long long)result) < 0 \
			|| filling(' ', fieldw - result_len - 2) < 0)
			return (-1);
	}
	else
	{
		if (filling(' ', fieldw - result_len - 2) < 0 \
			|| hex_write((unsigned long long)result) < 0)
			return (-1);
	}
	if (fieldw > result_len + 2)
		return (fieldw);
	else
		return (result_len + 2);
}

static int	_hex_write(unsigned long long num)
{
	if (num < 16)
	{
		if (write(1, &("0123456789abcdef"[num % 16]), 1) < 0)
			return (-1);
		return (0);
	}
	if (_hex_write(num / 16) < 0 \
		|| write(1, &("0123456789abcdef"[num % 16]), 1) < 0)
		return (-1);
	return (0);
}

static int	hex_write(unsigned long long num)
{
	if (write(1, "0x", 2) < 0 || _hex_write(num) < 0)
		return (-1);
	return (0);
}
