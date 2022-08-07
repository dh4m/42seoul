/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:30:45 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 17:16:41 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static void	bitset(unsigned char *bit, char c);
static void	bitmodi(unsigned char *bit);
static int	free_trick(void *ptr);
static int	idx_numberskip(char *str);

int	parse(char *str, va_list ap, int re_val, unsigned char bit)
{
	int				idx;
	int				fieldw;
	int				precision;

	fieldw = 0;
	precision = 0;
	idx = 0;
	if (!str)
		return (-1);
	while (str[++idx])
	{
		if (ft_isdigit(str[idx]) && str[idx - 1] == '.')
			precision = ft_atoi(&str[idx]);
		else if (str[idx] != '0' && ft_isdigit(str[idx]))
			fieldw = ft_atoi(&str[idx]);
		else
			bitset(&bit, str[idx]);
		if ((str[idx - 1] == '.' || str[idx] != '0') && ft_isdigit(str[idx]))
			idx += idx_numberskip(&str[idx]);
	}
	//printf("width=%d, pre=%d\n", fieldw, precision);
	bitmodi(&bit);
	if (invalid_put_width(fieldw, precision) && free_trick(str))
		return (-1);
	re_val = put_conversion(bit, (int [2]){fieldw, precision}, ap, \
							str[idx - 1]);
	free(str);
	return (re_val);
}

static int	idx_numberskip(char *str)
{
	int num_len;

	num_len = 0;
	while (ft_isdigit(str[num_len]))
		num_len++;
	return (num_len - 1);
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
