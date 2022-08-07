/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:27:45 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 17:09:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int	print_abs_num(int num)
{
	if (num == -2147483648)
	{
		if (write(1, "2147483648", 10) < 0)
			return (-1);
	}
	else if (num < 0)
		ft_putnbr_fd(-num, 1);
	else
		ft_putnbr_fd(num, 1);
	return (0);
}

int	num_len(long long num)
{
	int	count;

	if (!num)
		return (1);
	count = 0;
	while (num)
	{
		count++;
		num /= 10;
	}
	return (count);
}

int	hex_len(unsigned long long num)
{
	int	count;

	if (!num)
		return (1);
	count = 0;
	while (num)
	{
		count++;
		num /= 16;
	}
	return (count);
}

int	excep_process_x(int *flag, int *result_len, int fieldw)
{
	*flag = 0;
	*result_len = 0;
	if (filling(' ', fieldw))
		return (-1);
	return (1);
}

int	excep_process_i(unsigned char bit, int *result_len, int fieldw)
{
	char	flag;
	*result_len = 0;

	flag = 0;
	if ((bit & 16) == 16)
		flag = '+';
	else if ((bit & 4) == 4)
		flag = ' ';
	if (flag && (bit & 8) == 8)
	{
		if (write(1, &flag, 1) < 0 || filling(' ', fieldw - 1) < 0)
			return (-1);
	}
	else if (flag)
	{
		if (filling(' ', fieldw - 1) < 0 || write(1, &flag, 1) < 0)
			return (-1);
	}
	else
	{
		if (filling(' ', fieldw) < 0)
			return (-1);
	}
	return (1);
}
