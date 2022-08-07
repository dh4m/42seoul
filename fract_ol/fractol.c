/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:37:39 by dham              #+#    #+#             */
/*   Updated: 2022/08/03 20:15:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 2)
		invalid_args();
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
		mandelbrot_main(argc, argv);
	else if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
		julia_main(argc, argv);
	else if (ft_strncmp(argv[1], "custom", ft_strlen(argv[1])) == 0)
		custom_main(argc, argv);
	else
		invalid_args();
}
