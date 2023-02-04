/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:37:37 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 16:06:38 by dham             ###   ########.fr       */
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
	const std::string &getIdeas(int idx) const;
	void setIdeas(int idx, const std::string &str);
private:
	Brain	*brain;
};

#endif
