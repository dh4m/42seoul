/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:18:37 by dham              #+#    #+#             */
/*   Updated: 2023/02/01 18:53:16 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	Point	a(0, 1);
	Point	b(-1, 0);
	Point	c(1, 0);
	Point	p(0, 0.5);

	if (bsp(a, b, c, p))
		std::cout << "The point (" << p.x_val() << " " << p.y_val() << ") is in the triangle abc." << '\n';
	else
		std::cout << "The point (" << p.x_val() << " " << p.y_val() << ") is not in the triangle abc." << '\n';
	return (0);
}