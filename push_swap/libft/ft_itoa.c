/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:31:52 by dham              #+#    #+#             */
/*   Updated: 2022/07/05 19:02:46 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*itoa(int n, int flag, int count);

char	*ft_itoa(int n)
{
	if (n < 0)
		return (itoa(n, -1, 1));
	else
		return (itoa(n, 1, 1));
}

static char	*itoa(int n, int flag, int count)
{
	char	*re_val;
	int		idx;

	idx = 0;
	if (n / 10 == 0)
	{
		if (flag < 0)
			re_val = ft_calloc(count + 2, 1);
		else
			re_val = ft_calloc(count + 1, 1);
		if (!re_val)
			return (0);
		if (flag < 0)
			re_val[idx++] = '-';
		re_val[idx] = (n * flag) + '0';
		return (re_val);
	}
	re_val = itoa(n / 10, flag, count + 1);
	if (!re_val)
		return (0);
	while (re_val[idx])
		idx++;
	re_val[idx] = ((n % 10) * flag) + '0';
	return (re_val);
}
