/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:03:45 by dham              #+#    #+#             */
/*   Updated: 2022/08/03 20:12:23 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	is_difussion(long double z_real, long double z_img, long double c_real,
				long double c_img)
{
	int			i;
	long double	z_r_next;
	long double	z_i_next;

	i = 0;
	if (z_real * z_real + z_img * z_img > 4)
		return (i);
	while (i < 100)
	{
		z_r_next = z_real * z_real - z_img * z_img + c_real;
		z_i_next = 2 * z_real * z_img + c_img;
		z_real = z_r_next;
		z_img = z_i_next;
		i++;
		if (z_real * z_real + z_img * z_img > 4)
			return (i);
	}
	return (-1);
}

int	custom_cal(long double z_real, long double z_img, long double c_real,
				long double c_img)
{
	int			i;
	long double	z_r_next;
	long double	z_i_next;

	i = 0;
	if (z_real * z_real + z_img * z_img > 4)
		return (i);
	while (i < 100)
	{
		z_r_next = fabsl(z_real * z_real - z_img * z_img) - fabsl(c_real);
		z_i_next = 2 * z_real * z_img + c_img;
		z_real = z_r_next;
		z_img = z_i_next;
		i++;
		if (z_real * z_real + z_img * z_img > 4)
			return (i);
	}
	return (-1);
}
