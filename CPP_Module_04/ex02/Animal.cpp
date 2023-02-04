/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:17:22 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 16:21:51 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
:_type("Animal")
{
	std::cout << "Animal default constructor called" << '\n';
}

Animal::Animal(const Animal &copy)
:_type(copy._type)
{
	std::cout << "Animal Copy constructor called" << '\n';
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << '\n';
}

Animal	&Animal::operator=(const Animal &copy)
{
	_type = copy._type;
	std::cout << "Animal Copy assignment operator called" << '\n';
	return (*this);
}

const std::string	&Animal::getType(void) const
{
	return (_type);
}
