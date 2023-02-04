/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:15:14 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 18:34:12 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
:_type(type)
{}

AMateria::AMateria(const AMateria &copy)
:_type(copy._type)
{}

AMateria::~AMateria(void)
{}

AMateria	&AMateria::operator=(const AMateria &copy)
{
	_type = copy._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}
