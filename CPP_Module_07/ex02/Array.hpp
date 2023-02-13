/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:19:12 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 14:28:54 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
public:
	Array(void)
	: _arr(NULL), _len(0)
	{}

	Array(unsigned int n)
	: _len(n)
	{
		_arr = new T[n];
	}

	Array(const Array &copy)
	: _len(copy._len)
	{
		if (_len == 0)
			_arr = NULL;
		else
		{
			_arr = new T[_len];
			for (unsigned int i = 0; i < _len; i++)
			{
				_arr[i] = copy._arr[i];
			}
		}
	}

	~Array(void)
	{
		delete[] _arr;
	}

	Array	&operator=(const Array &copy)
	{
		if (_arr)
			delete[] _arr;
		_len = copy._len;
		if (_len == 0)
			_arr = NULL;
		else
		{
			_arr = new T[_len];
			for (unsigned int i = 0; i < _len; i++)
			{
				_arr[i] = copy._arr[i];
			}
		}
	}

	T &operator[](unsigned int i)
	{
		if (_len == 0 || i >= _len || i < 0)
			throw (std::exception());
		return (_arr[i]);
	}

	const T &operator[](unsigned int i) const
	{
		if (_len == 0 || i >= _len || i < 0)
			throw (std::exception());
		return (_arr[i]);
	}

	unsigned int size(void) const
	{
		return (_len);
	}
private:
	T *_arr;
	unsigned int _len;
};

#endif