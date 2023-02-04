/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:15:06 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 20:26:29 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
public:
	AMateria(std::string const & type);
	AMateria(const AMateria &copy);
	virtual ~AMateria(void);

	AMateria	&operator=(const AMateria &copy);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
protected:
	std::string _type;
};

#endif
