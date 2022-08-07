/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:36:07 by dham              #+#    #+#             */
/*   Updated: 2022/08/03 20:18:39 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define LINE_LEN 800

enum e_type
{
	MANDELBROT = 0,
	JULIA,
	CUSTOM
};

enum e_key
{
	ESC = 53,
	LEFT = 123,
	RIGHT,
	DOWN,
	UP
};

typedef struct s_info
{
	void		*mlx;
	void		*win;
	long double	sp_x;
	long double	sp_y;
	long double	length;
	int			type;
	int			color;
	long double	real;
	long double	img;
}	t_info;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

int		mandelbrot_main(int argc, char *argv[]);
int		julia_main(int argc, char *argv[]);
int		custom_main(int argc, char *argv[]);

int		is_difussion(long double z_real, long double z_img, \
				long double c_real, long double c_img);
int		custom_cal(long double z_real, long double z_img, long double c_real, \
				long double c_img);

void	invalid_args(void);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		color_select(int iter_num, int color);
void	init_info(t_info *info);

void	mangdelbrot(t_info *info);
void	drawing_man(t_info *info, t_img *img);

void	julia_complex_set(t_info *info, char *argv);
void	julia(t_info *info);
void	drawing_jul(t_info *info, t_img *img);

void	custom(t_info *info);
void	drawing_custom(t_info *info, t_img *img);

int		key_event(int keycode, t_info *param);
int		mouse_event(int botton, int x, int y, t_info *param);
void	moving_arrow(int keycode, t_info *info);
int		destroy(void *param);
void	color_shift(t_info *info);

void	zoom_in(int x, int y, t_info *info);
void	zoom_out(int x, int y, t_info *info);

#endif