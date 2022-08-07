/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:42:17 by dham              #+#    #+#             */
/*   Updated: 2022/07/09 22:52:28 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	return_value_x(int fieldw, int precision, int len, int flag)
{
	if (len >= precision && len + flag > fieldw)
		return (len + flag);
	else if (len < precision && precision + flag > fieldw)
		return (precision + flag);
	else
		return (fieldw);
}

int	print_hex(unsigned int num)
{
	if (num < 16)
	{
		if (write(1, &("0123456789abcdef"[num % 16]), 1) < 0)
			return (-1);
		return (0);
	}
	if (print_hex(num / 16) < 0)
		return (-1);
	if (write(1, &("0123456789abcdef"[num % 16]), 1) < 0)
		return (-1);
	return (0);
}

int	print_bhex(unsigned int num)
{
	if (num < 16)
	{
		if (write(1, &("0123456789ABCDEF"[num % 16]), 1) < 0)
			return (-1);
		return (0);
	}
	if (print_bhex(num / 16) < 0)
		return (-1);
	if (write(1, &("0123456789ABCDEF"[num % 16]), 1) < 0)
		return (-1);
	return (0);
}
