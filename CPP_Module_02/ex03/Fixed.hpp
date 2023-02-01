/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:14:04 by dham              #+#    #+#             */
/*   Updated: 2023/01/29 12:11:52 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &f);
	~Fixed(void);
	Fixed	&operator= (const Fixed &f);
	bool	operator> (const Fixed &f) const;
	bool	operator< (const Fixed &f) const;
	bool	operator>= (const Fixed &f) const;
	bool	operator<= (const Fixed &f) const;
	bool	operator== (const Fixed &f) const;
	bool	operator!= (const Fixed &f) const;
	Fixed	operator+(const Fixed &f) const;
	Fixed	operator-(const Fixed &f) const;
	Fixed	operator*(const Fixed &f) const;
	Fixed	operator/(const Fixed &f) const;
	Fixed	&operator++(void);
	Fixed	operator++(int post);
	Fixed	&operator--(void);
	Fixed	operator--(int post);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed		&min(Fixed &f1, Fixed &f2);
	static const Fixed	&min(const Fixed &f1, const Fixed &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);
	static const Fixed	&max(const Fixed &f1, const Fixed &f2);
private:
	int					_number;
	static const int	_fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed &f);

#endif