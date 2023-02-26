/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:42:40 by dham              #+#    #+#             */
/*   Updated: 2022/07/05 19:03:43 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer;

	if (n / 10 == 0)
	{
		if (n < 0)
		{
			buffer = -n + '0';
			write(fd, "-", 1);
		}
		else
			buffer = n + '0';
		write(fd, &buffer, 1);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	if (n < 0)
		buffer = -(n % 10) + '0';
	else
		buffer = n % 10 + '0';
	write(fd, &buffer, 1);
}
