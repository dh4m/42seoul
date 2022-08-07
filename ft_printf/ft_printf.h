/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:54:37 by dham              #+#    #+#             */
/*   Updated: 2022/08/07 17:23:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	parse(char *str, va_list ap, int re_val, unsigned char bit);
int	isset(char c);
int	put_conversion(unsigned char bit, int width[2], va_list ap, char spec);
int	filling(char c, int len);
int	num_len(long long num);
int	print_abs_num(int num);
int	hex_len(unsigned long long num);
int	excep_process_x(int *flag, int *result_len, int fieldw);
int	excep_process_i(unsigned char bit, int *result_len, int fieldw);
int	char_put(unsigned char bit, int fieldw, va_list ap);
int	string_put(unsigned char bit, int fieldw, int precision, va_list ap);
int	point_put(unsigned char bit, int fieldw, va_list ap);
int	integer_put(unsigned char bit, int fieldw, int precision, va_list ap);
int	unsign_put(unsigned char bit, int fieldw, int precision, va_list ap);
int	hex_put(unsigned char bit, int fieldw, int precision, va_list ap);
int	bighex_put(unsigned char bit, int fieldw, int precision, va_list ap);
int	unknown_put(unsigned char bit, int fieldw, char spec);
int	invalid_put_width(int fieldw, int precision);
int	print_hex(unsigned int num);
int	return_value_x(int fieldw, int precision, int len, int flag);
int	print_bhex(unsigned int num);
int	left_int(int num, unsigned char bit, int fieldw, int precision);
int	right_int(int num, unsigned char bit, int fieldw, int precision);
int	right_zero_int(int num, unsigned char bit, int fieldw);
int	return_value_u(int fieldw, int precision, int len);
int	return_value(int fieldw, int precision, int len, unsigned char bit);

#endif