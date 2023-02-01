/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:59:40 by dham              #+#    #+#             */
/*   Updated: 2023/02/01 18:52:27 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(float a, float b);
	Point(const Point &copy);
	~Point(void);

	Point	&operator=(const Point &copy);
	Point	operator-(const Point &p) const;
	
	const Fixed	&x_val(void) const;
	const Fixed	&y_val(void) const;
	const Fixed	cross(const Point &v) const;
private:
	Fixed	x;
	Fixed	y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif