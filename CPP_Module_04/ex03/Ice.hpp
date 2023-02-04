/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:49:44 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 17:51:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice(void);
	Ice(const Ice &copy);
	~Ice(void);

	Ice	&operator=(const Ice &copy);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
