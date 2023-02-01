/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:59:37 by dham              #+#    #+#             */
/*   Updated: 2023/02/01 20:15:32 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point(void)
:x(0), y(0)
{
	std::cout << "Point Default constructor called\n";
}

Point::Point(float a, float b)
:x(a), y(b)
{
	std::cout << "Point(" << x << "," << y << ") constructor called\n";
}

Point::Point(const Point &copy)
:x(copy.x), y(copy.y)
{
	std::cout << "Point Copy constructor called\n";
}

Point::~Point(void)
{
	std::cout << "Point Destructor called\n";
}

Point	&Point::operator=(const Point &copy)
{
	std::cout << "Point Copy assignment operator called\n";
	x = copy.x;
	y = copy.y;
	return (*this);
}

Point	Point::operator-(const Point &p) const
{
	Point	ret_v;

	ret_v.x = x - p.x;
	ret_v.y = y - p.y;
	return (ret_v);
}

const Fixed &Point::x_val(void) const
{
	return (x);
}

const Fixed &Point::y_val(void) const
{
	return (y);
}

const Fixed	Point::cross(const Point &v) const
{
	return (Fixed(x * v.y - y * v.x));
}