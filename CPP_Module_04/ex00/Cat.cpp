/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:24:17 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 19:23:14 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Cat default constructor called" << '\n';
}

Cat::Cat(const Cat &copy)
{
	_type = copy._type;
	std::cout << "Cat Copy constructor called" << '\n';
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << '\n';
}

Cat	&Cat::operator=(const Cat &copy)
{
	_type = copy._type;
	std::cout << "Cat Copy assignment operator called" << '\n';
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "meow! meow!" << '\n';
}
