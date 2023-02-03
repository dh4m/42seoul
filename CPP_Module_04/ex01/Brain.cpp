/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:28:20 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 21:01:56 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << '\n';
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy constructor called" << '\n';
	for(int i = 0; i < NUM_IDEAS; i++)
	{
		ideas[i] = copy.ideas[i];
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << '\n';
}

Brain	&Brain::operator=(const Brain &copy)
{
	std::cout << "Brain Copy assignment operator called" << '\n';
	for(int i = 0; i < NUM_IDEAS; i++)
	{
		ideas[i] = copy.ideas[i];
	}
	return (*this);
}
