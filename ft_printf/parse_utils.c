/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:24:40 by dham              #+#    #+#             */
/*   Updated: 2022/07/09 21:40:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	filling(char c, int len)
{
	if (len < 1)
		return (0);
	while (len--)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
	}
	return (0);
}

int	invalid_put_width(int fieldw, int precision)
{
	return (precision > 2147483640 || fieldw > 2147483640 \
			|| precision < 0 || fieldw < 0);
}
