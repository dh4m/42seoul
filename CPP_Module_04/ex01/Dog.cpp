/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:36:49 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 21:06:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << '\n';
	_type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog Copy constructor called" << '\n';
	_type = copy._type;
	brain = new Brain();
	*brain = *copy.brain;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << '\n';
	delete brain;
}

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << "Dog Copy assignment operator called" << '\n';
	_type = copy._type;
	delete brain;
	brain = new Brain();
	*brain = *copy.brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "bow wow!" << '\n';
}
