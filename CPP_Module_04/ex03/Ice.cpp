/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:54:23 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 20:38:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void)
:AMateria("ice")
{}

Ice::Ice(const Ice &copy)
:AMateria(copy)
{
	(void) copy;
}

Ice::~Ice(void)
{}

Ice	&Ice::operator=(const Ice &copy)
{
	(void) copy;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << '\n';
}