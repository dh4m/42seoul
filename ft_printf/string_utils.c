/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:57:33 by dham              #+#    #+#             */
/*   Updated: 2022/07/09 21:59:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_value(int fieldw, int precision, int len, unsigned char bit)
{
	if (((bit & 32) == 32) && precision < len)
	{
		if (precision < fieldw)
			return (fieldw);
		else
			return (precision);
	}
	else
	{
		if (len < fieldw)
			return (fieldw);
		else
			return (len);
	}
}
