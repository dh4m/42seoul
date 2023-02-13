/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:53:44 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 20:42:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::Span(void)
: _arr(NULL), _len(0), _idx(0)
{}

Span::Span(unsigned int n)
: _len(n), _idx(0)
{
	_arr = new int[n];
}

Span::Span(const Span &copy)
: _len(copy._len), _idx(copy._idx)
{
	_arr = new int[_len];
	for(size_t i = 0; i < _idx; i++)
	{
		_arr[i] = copy._arr[i];
	}
}

Span::~Span(void)
{
	if (_arr)
		delete[] _arr;
}

Span	&Span::operator=(const Span &copy)
{
	if (_arr)
		delete[] _arr;
	_len = copy._len;
	_idx = copy._idx;
	_arr = new int[_len];
	for(size_t i = 0; i < _idx; i++)
	{
		_arr[i] = copy._arr[i];
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_idx == _len)
		throw (Span::ArrayNoSpaceException());
	_arr[_idx++] = n;
}

unsigned int Span::shortestSpan(void)
{
	if (_idx < 2)
		throw (Span::TooFewElementException());
	std::sort(_arr, _arr + _idx);
	unsigned int gap = UINT_MAX;
	for (size_t i = 0; i < _idx - 1; i++)
	{
		if ((unsigned int)_arr[i + 1] - _arr[i] < gap)
			gap = _arr[i + 1] - _arr[i];
	}
	return (gap);
}

unsigned int Span::longestSpan(void)
{
	if (_idx < 2)
		throw (Span::TooFewElementException());
	std::sort(_arr, _arr + _idx);
	return (_arr[_idx - 1] - _arr[0]);
}

const char *Span::ArrayNoSpaceException::what() const throw()
{
	return ("ArrayNoSpaceException: Array is full");
}

const char *Span::TooFewElementException::what() const throw()
{
	return ("TooFewElementException: The number of elements is too small.");
}

