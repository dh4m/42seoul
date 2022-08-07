/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:42:54 by dham              #+#    #+#             */
/*   Updated: 2022/07/10 11:27:34 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	char_put(unsigned char bit, int fieldw, va_list ap)
{
	int		left;
	char	result;

	left = ((bit & 8) == 8);
	result = (char)va_arg(ap, int);
	if (left)
	{
		write(1, &result, 1);
		filling(' ', fieldw - 1);
	}
	else
	{
		filling(' ', fieldw - 1);
		write(1, &result, 1);
	}
	if (fieldw > 1)
		return (fieldw);
	else
		return (1);
}
