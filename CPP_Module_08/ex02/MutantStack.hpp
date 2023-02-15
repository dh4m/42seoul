/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:52:30 by dham              #+#    #+#             */
/*   Updated: 2023/02/15 14:33:45 by dham             ###   ########.fr       */
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
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	
	iterator begin(void)
	{
		return (this->c.begin());
	}
	
	iterator end(void)
	{
		return (this->c.end());
	}

	reverse_iterator rbegin(void)
	{
		return (this->c.rbegin());
	}

	reverse_iterator rend(void)
	{
		return (this->c.rend());
	}

	const_iterator begin(void) const
	{
		return (this->c.begin());
	}
	
	const_iterator end(void) const
	{
		return (this->c.end());
	}

	const_reverse_iterator rbegin(void) const
	{
		return (this->c.rbegin());
	}

	const_reverse_iterator rend(void) const
	{
		return (this->c.rend());
	}
};

#endif
