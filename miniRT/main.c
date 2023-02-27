/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:03 by dham              #+#    #+#             */
/*   Updated: 2023/02/27 14:21:25 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"

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
	if (make_image(&info, &img, argv[1]) != SUCCESS)
		return (EXIT_FAILURE);
	mlx_put_image_to_window(info.mlx, info.win, img.img, 0, 0);
	mlx_hook(info.win, 17, 0, win_destroy, 0);
	mlx_loop(info.mlx);
	return (EXIT_SUCCESS);
}