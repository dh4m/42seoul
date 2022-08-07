/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:30:45 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 15:57:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static void	bitset(unsigned char *bit, char c);
static void	bitmodi(unsigned char *bit);
static int	free_trick(void *ptr);

int	parse(char *str, va_list ap, int re_val, unsigned char bit)
{
	int				idx;
	int				fieldw;
	int				precision;

	fieldw = 0;
	precision = 0;
	idx = 0;
	while (str[++idx])
	{
		if (str[idx] != '0' && ft_isdigit(str[idx]) && str[idx - 1] == '.')
			precision = ft_atoi(&str[idx]);
		else if (str[idx] != '0' && ft_isdigit(str[idx]))
			fieldw = ft_atoi(&str[idx]);
		else
			bitset(&bit, str[idx]);
		while (str[idx] != '0' && ft_isdigit(str[idx]))
			idx++;
	}
	bitmodi(&bit);
	if (invalid_put_width(fieldw, precision) && free_trick(str))
		return (-1);
	re_val = put_conversion(bit, (int [2]){fieldw, precision}, ap, \
							str[idx - 1]);
	free(str);
	return (re_val);
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

static int	free_trick(void *ptr)
{
	free(ptr);
	return (1);
}

static void	bitset(unsigned char *bit, char c)
{
	if (c == '.')
		*bit |= 0x20;
	else if (c == '+')
		*bit |= 0x10;
	else if (c == '-')
		*bit |= 0x8;
	else if (c == ' ')
		*bit |= 0x4;
	else if (c == '#')
		*bit |= 0x2;
	else if (c == '0')
		*bit |= 0x1;
}

static void	bitmodi(unsigned char *bit)
{
	if ((*bit & 16) == 16)
		*bit &= 073;
	if ((*bit & 32) == 32 || (*bit & 8) == 8)
		*bit &= 076;
}
