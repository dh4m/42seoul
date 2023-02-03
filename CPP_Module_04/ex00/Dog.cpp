/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:36:49 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 19:23:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << "Dog default constructor called" << '\n';
}

Dog::Dog(const Dog &copy)
{
	_type = copy._type;
	std::cout << "Dog Copy constructor called" << '\n';
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << '\n';
}

Dog	&Dog::operator=(const Dog &copy)
{
	_type = copy._type;
	std::cout << "Dog Copy assignment operator called" << '\n';
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "bow wow!" << '\n';
}
