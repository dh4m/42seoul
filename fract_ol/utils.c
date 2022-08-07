/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:47:19 by dham              #+#    #+#             */
/*   Updated: 2022/08/03 20:19:39 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

void	invalid_args(void)
{
	ft_putstr_fd("usage: ", 1);
	ft_putstr_fd("./fractol [fractal shape]([julia version])\n", 1);
	ft_putstr_fd("fractal shape: \n", 1);
	ft_putstr_fd("\t[mandelbrot | julia | custom]\n", 1);
	ft_putstr_fd("julia version: \n", 1);
	ft_putstr_fd("\t[1]. c = 0.31 + 0.074i\n", 1);
	ft_putstr_fd("\t[2]. c = -0.194 + 0.656i\n", 1);
	ft_putstr_fd("\t[3]. c = -0.74 + 0.11i\n", 1);
	exit(1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	color_select(int iter_num, int color)
{
	int	i;
	int	rgb_val;

	if (iter_num < 0)
		return (0x00C4CACE);
	i = 0;
	rgb_val = (color * 15) << (color - 1);
	while (i < iter_num)
	{
		rgb_val = rgb_val << (1);
		if ((rgb_val & 0x000FFFFF) == 0)
			rgb_val += (color * 15) << (color - 1);
		i++;
	}
	return (rgb_val & 0x00FFFFFF);
}

void	init_info(t_info *info)
{
	info->length = 4;
	info->sp_x = 0;
	info->sp_y = 0;
	info->color = 1;
}
