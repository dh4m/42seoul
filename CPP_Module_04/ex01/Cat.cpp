/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:24:17 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 21:02:41 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << '\n';
	_type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat Copy constructor called" << '\n';
	_type = copy._type;
	brain = new Brain();
	*brain = *copy.brain;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << '\n';
	delete brain;
}

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat Copy assignment operator called" << '\n';
	_type = copy._type;
	delete brain;
	brain = new Brain();
	*brain = *copy.brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "meow! meow!" << '\n';
}
