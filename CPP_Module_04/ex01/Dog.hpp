/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:37:37 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 20:38:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
public:
	Dog(void);
	Dog(const Dog &copy);
	~Dog(void);

	Dog	&operator=(const Dog &copy);

	void	makeSound(void) const;
private:
	Brain	*brain;
};

#endif
