/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:58:27 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 20:37:52 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void)
:AMateria("cure")
{}

Cure::Cure(const Cure &copy)
:AMateria(copy)
{
	(void) copy;
}

Cure::~Cure(void)
{}

Cure	&Cure::operator=(const Cure &copy)
{
	(void) copy;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << '\n';
}