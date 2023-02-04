/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:28:20 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 16:15:34 by dham             ###   ########.fr       */
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

const std::string &Brain::getIdeas(int idx) const
{
	static const std::string empty;
	
	if (idx >= NUM_IDEAS)
	{
		std::cerr << "getIdeas: wrong index!" << '\n';
		return (empty);
	}
	return (ideas[idx]);
}

void Brain::setIdeas(int idx, const std::string &str)
{
	if (idx >= NUM_IDEAS)
	{
		std::cerr << "setIdeas: wrong index!" << '\n';
		return ;
	}
	ideas[idx] = str;
}

