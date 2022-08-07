/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:53:55 by dham              #+#    #+#             */
/*   Updated: 2022/07/10 11:51:26 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static int	parse_len(const char *str);
static int	printf_unit(const char **str, int *total_len, va_list ap);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		total_len;

	va_start(ap, str);
	total_len = 0;
	while (*str)
	{
		if (printf_unit(&str, &total_len, ap) < 0)
		{
			va_end(ap);
			return (-1);
		}
		str++;
	}
	va_end(ap);
	return (total_len);
}

static int	printf_unit(const char **str, int *total_len, \
va_list ap)
{
	int	len;

	if (**str == '%' && *((*str) + 1) == '%' && ++*total_len)
	{
		if (write(1, (*str)++, 1) < 0)
			return (-1);
	}
	else if (**str == '%')
	{
		len = parse(ft_substr(*str, 0, parse_len(*str)), ap, 0, 0);
		if (len == -1)
			return (-1);
		*total_len += len;
		*str += parse_len(*str) - 1;
	}
	else if (**str != '%' && ++*total_len)
	{
		if (write(1, *str, 1) < 0)
			return (-1);
	}
	return (0);
}

int	isset(char c)
{
	if (ft_isalpha(c))
		return (-1);
	else if (ft_isdigit(c) || c == '+' || c == '-' || c == ' ' || c == '#' \
			|| c == '.')
		return (1);
	return (0);
}

static int	parse_len(const char *str)
{
	int	count;

	count = 1;
	str++;
	while (*str && isset(*str) == 1)
	{
		str++;
		count++;
	}
	if (!*str)
		return (count);
	else
		return (count + 1);
}
