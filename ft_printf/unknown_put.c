/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:58:22 by dham              #+#    #+#             */
/*   Updated: 2022/07/09 20:12:12 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	unknown_put(unsigned char bit, int fieldw, char spec)
{
	int	left;

	left = ((bit & 8) == 8);
	if (left)
	{
		if (write(1, &spec, 1) < 0 || filling(' ', fieldw - 1) < 0)
			return (-1);
	}
	else
	{
		if (filling(' ', fieldw - 1 || write(1, &spec, 1) < 0) < 0)
			return (-1);
	}
	if (fieldw > 1)
		return (fieldw);
	else
		return (1);
}
