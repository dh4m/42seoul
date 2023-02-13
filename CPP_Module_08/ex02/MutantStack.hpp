/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:52:30 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 21:42:55 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP


#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack(void) {}
	MutantStack(const MutantStack &copy) 
	{
		*this = copy;
		(void) copy;
	}
	~MutantStack(void) {}
	MutantStack	&operator=(const MutantStack &copy) 
	{
		static_cast<std::stack<T>&>(*this) = static_cast<std::stack<T>&>(copy);
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	
	iterator begin(void)
	{
		return (std::stack<T>::c.begin());
	}
	
	iterator end(void)
	{
		return (std::stack<T>::c.end());
	}
};

#endif
