/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:02:29 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 16:14:16 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int	left_write(char *str, int len, int filling);
static int	right_write(char *str, int len, int filling);
static int	precision_output(char *result, int fieldw, int precision, int left);
static int	full_output(char *result, int fieldw, int left);

int	string_put(unsigned char bit, int fieldw, int precision, va_list ap)
{
	char	*result;

	result = va_arg(ap, char *);
	if (!result)
		result = "(null)";
	if (((bit & 32) == 32) && (size_t)precision < ft_strlen(result))
	{
		if (precision_output(result, fieldw, precision, (bit & 8) == 8) < 0)
			return (-1);
	}
	else
	{
		if (full_output(result, fieldw, (bit & 8) == 8) < 0)
			return (-1);
	}
	return (return_value(fieldw, precision, (int)ft_strlen(result), bit));
}

static int	precision_output(char *result, int fieldw, int precision, int left)
{
	if (left)
	{
		if (left_write(result, precision, fieldw - precision) < 0)
			return (-1);
	}
	else
	{
		if (right_write(result, precision, fieldw - precision) < 0)
			return (-1);
	}
	return (0);
}

static int	full_output(char *result, int fieldw, int left)
{
	if (left)
	{
		if (left_write(result, ft_strlen(result), \
			fieldw - ft_strlen(result)) < 0)
			return (-1);
	}
	else
	{
		if (right_write(result, ft_strlen(result), \
			fieldw - ft_strlen(result)) < 0)
			return (-1);
	}
	return (0);
}

static int	left_write(char *str, int len, int fill_len)
{
	if (write(1, str, len) < 0 || filling(' ', fill_len) < 0)
		return (-1);
	return (0);
}

static int	right_write(char *str, int len, int fill_len)
{
	if (filling(' ', fill_len) < 0 || write(1, str, len) < 0)
		return (-1);
	return (0);
}
