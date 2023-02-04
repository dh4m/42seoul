/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:49:48 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 17:51:20 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure(void);
	Cure(const Cure &copy);
	~Cure(void);

	Cure	&operator=(const Cure &copy);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
