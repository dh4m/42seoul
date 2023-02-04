/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:59:31 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 17:59:31 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << '\n';
}

WrongCat::WrongCat(const WrongCat &copy)
{
	_type = copy._type;
	std::cout << "WrongCat Copy constructor called" << '\n';
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << '\n';
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	_type = copy._type;
	std::cout << "WrongCat Copy assignment operator called" << '\n';
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "meow! meow!" << '\n';
}
