/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:58 by dham              #+#    #+#             */
/*   Updated: 2023/02/01 20:08:33 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "bsp start##############\n";
	Point const	v1 = b - a;
	std::cout << "bsp start##############\n";
	Point const	v2 = c - b;
	std::cout << "bsp start##############\n";
	Point const	v3 = a - c;
	std::cout << "bsp start##############\n";

	return ((v1.cross(point - a) > 0 && v2.cross(point - b) > 0 && v3.cross(point - c) > 0) \
		|| (v1.cross(point - a) < 0 && v2.cross(point - b) < 0 && v3.cross(point - c) < 0));
}