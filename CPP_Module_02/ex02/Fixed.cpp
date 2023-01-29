/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:13:45 by dham              #+#    #+#             */
/*   Updated: 2023/01/29 13:18:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
: _number(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	_number = num << _fractional_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	_number = roundf(num * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called\n";
	_number = f.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator= (const Fixed &f)
{
	std::cout << "Copy assignment operator called\n";
	_number = f.getRawBits();
	return (*this);
}

bool	Fixed::operator> (const Fixed &f) const
{
	return (_number > f.getRawBits());
}

bool	Fixed::operator< (const Fixed &f) const
{
	return (_number < f.getRawBits());
}

bool	Fixed::operator>= (const Fixed &f) const
{
	return (_number >= f.getRawBits());
}

bool	Fixed::operator<= (const Fixed &f) const
{
	return (_number <= f.getRawBits());
}

bool	Fixed::operator== (const Fixed &f) const
{
	return (_number == f.getRawBits());
}

bool	Fixed::operator!= (const Fixed &f) const
{
	return (_number != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	Fixed	res;

	res.setRawBits(_number + f._number);
	return (res);
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	Fixed	res;

	res.setRawBits(_number - f._number);
	return (res);
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	long	temp;
	Fixed	ret_f;

	temp = (long)_number * f._number;
	temp = temp >> _fractional_bits;
	ret_f.setRawBits((int)temp);
	return (ret_f);
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	long	temp;
	Fixed	ret_f;

	temp = _number;
	temp = temp << _fractional_bits;
	temp /= f._number;
	ret_f.setRawBits((int)temp);
	return (ret_f);
}

Fixed	&Fixed::operator++(void)
{
	_number++;
	return (*this);
}

Fixed	Fixed::operator++(int post)
{
	Fixed	temp(*this);

	(void)post;
	_number++;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	_number--;
	return (*this);
}

Fixed	Fixed::operator--(int post)
{
	Fixed	temp(*this);

	(void)post;
	_number--;
	return (temp);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_number = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_number / (1 << _fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (_number >> _fractional_bits);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 <= f2)
		return (f1);
	else
		return (f2);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 <= f2)
		return (f1);
	else
		return (f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 >= f2)
		return (f1);
	else
		return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 >= f2)
		return (f1);
	else
		return (f2);
}

std::ostream& operator<<(std::ostream& out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
