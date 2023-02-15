/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:53:44 by dham              #+#    #+#             */
/*   Updated: 2023/02/15 14:17:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::Span(unsigned int n)
: _max_len(n)
{}

Span::Span(const Span &copy)
: _max_len(copy._max_len), _v(copy._v)
{}

Span::~Span(void)
{}

Span	&Span::operator=(const Span &copy)
{
	_v = copy._v;
	_max_len = copy._max_len;
	return (*this);
}

void Span::addNumber(int n)
{
	if (_v.size() == _max_len)
		throw (Span::ArrayNoSpaceException());
	_v.push_back(n);
}

unsigned int Span::shortestSpan(void)
{
	if (_v.size() < 2)
		throw (Span::TooFewElementException());
	std::sort(_v.begin(), _v.end());
	unsigned int gap = UINT_MAX;
	for (std::vector<int>::iterator it = _v.begin();
		it != _v.end() - 1;
		it++)
	{
		if ((unsigned int)*(it + 1) - *it < gap)
			gap = (unsigned int)*(it + 1) - *it;
	}
	return (gap);
}

unsigned int Span::longestSpan(void)
{
	if (_v.size() < 2)
		throw (Span::TooFewElementException());
	return (
		*std::max_element(_v.begin(), _v.end()) 
		- *std::min_element(_v.begin(), _v.end())
	);
}

const char *Span::ArrayNoSpaceException::what() const throw()
{
	return ("ArrayNoSpaceException: Array is full");
}

const char *Span::TooFewElementException::what() const throw()
{
	return ("TooFewElementException: The number of elements is too small.");
}

