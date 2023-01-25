/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:13:45 by dham              #+#    #+#             */
/*   Updated: 2023/01/25 21:24:07 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	_number = 0;
}

Fixed::Fixed(const int num)
{
	_number = 0;////
	
}

Fixed::Fixed(const float num)
{

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

}

int	Fixed::toInt(void) const
{

}

std::ostream& operator<<(std::ostream& out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
