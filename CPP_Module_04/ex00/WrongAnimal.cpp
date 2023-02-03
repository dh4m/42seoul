/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:49:23 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 17:58:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
:_type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
:_type(copy._type)
{
	std::cout << "WrongAnimal Copy constructor called" << '\n';
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << '\n';
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	_type = copy._type;
	std::cout << "WrongAnimal Copy assignment operator called" << '\n';
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "I am an WrongAnimal! What kind of..." << '\n';
}

const std::string	&WrongAnimal::getType(void) const
{
	return (_type);
}
