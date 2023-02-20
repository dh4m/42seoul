/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:53:40 by dham              #+#    #+#             */
/*   Updated: 2023/02/20 16:13:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &copy);
	~Span(void);

	Span	&operator=(const Span &copy);

	void addNumber(int n);

	template<typename T>
	void addNumber_range(T begin, T end)
	{
		for (T it = begin; it != end; it++)
		{
			addNumber(*it);
		}
	}

	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);

	class ArrayNoSpaceException: public std::exception
	{
	public:
		const char *what() const throw();
	};
	class TooFewElementException: public std::exception
	{
	public:
		const char *what() const throw();
	};
private:
	size_t _max_len;
	std::vector<int> _v;

	Span(void);
};

#endif
