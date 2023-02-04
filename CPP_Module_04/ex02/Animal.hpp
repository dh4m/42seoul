/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:58:53 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 16:21:43 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal(void);
	Animal(const Animal &copy);
	virtual ~Animal(void);

	Animal	&operator=(const Animal &copy);

	virtual void	makeSound(void) const = 0;
	const std::string	&getType(void) const;
protected:
	std::string	_type;
};

#endif
