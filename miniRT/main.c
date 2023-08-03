/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:03 by dham              #+#    #+#             */
/*   Updated: 2023/04/08 16:01:16 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>

int	key_event(int keycode, t_info *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_img	img;

	if (argc != 2)
		invalid_args();
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "miniRT");
	img.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
									&img.line_length, &img.endian);
	if (make_image(&img, argv[1]) != SUCCESS)
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(info.mlx, info.win, img.img, 0, 0);
	mlx_hook(info.win, 17, 0, win_destroy, 0);
	mlx_key_hook(info.win, key_event, &info);
	mlx_loop(info.mlx);
	exit (EXIT_SUCCESS);
}
