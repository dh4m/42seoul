/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:24:40 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 16:07:55 by dham             ###   ########.fr       */
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

int	put_conversion(unsigned char bit, int width[2], va_list ap, char spec)
{
	if (spec == 'c')
		return (char_put(bit, width[0], ap));
	else if (spec == 's')
		return (string_put(bit, width[0], width[1], ap));
	else if (spec == 'p')
		return (point_put(bit, width[0], ap));
	else if (spec == 'd')
		return (integer_put(bit, width[0], width[1], ap));
	else if (spec == 'i')
		return (integer_put(bit, width[0], width[1], ap));
	else if (spec == 'u')
		return (unsign_put(bit, width[0], width[1], ap));
	else if (spec == 'x')
		return (hex_put(bit, width[0], width[1], ap));
	else if (spec == 'X')
		return (bighex_put(bit, width[0], width[1], ap));
	else if (isset(spec) == 1)
		return (0);
	else
		return (unknown_put(bit, width[0], spec));
}
