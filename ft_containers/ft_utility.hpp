/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:36:40 by dham              #+#    #+#             */
/*   Updated: 2023/02/19 01:54:35 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

/* pair start */
template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;
	T1 first;
	T2 second;
	
	pair(void) {}

	pair(const T1& x, const T2& y)
	: first(x), second(y)
	{}

	template<class U1, class U2>
	pair(const pair<U1, U2>& p)
	: first(p.first), second(p.second)
	{}

	pair& operator=(const pair& other)
	{
		first = other.first;
		second = other.second;
		return (*this);
	}
};

template<class T1, class T2>
pair<T1, T2> make_pair(T1 a, T2 b)
{
	return (pair<T1, T2>(a, b));
}

template<class T1, class T2, class U1, class U2>
bool operator==(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template<class T1, class T2, class U1, class U2>
bool operator!=(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
{
	return (!(lhs == rhs));
}

template<class T1, class T2, class U1, class U2>
bool operator<(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
{
	if (lhs.first < rhs.first)
		return (true);
	if (lhs.first == rhs.first && lhs.second < rhs.second)
		return (true);
	return (false);
}
template<class T1, class T2, class U1, class U2>
bool operator<=(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
{
	if (lhs.first < rhs.first)
		return (true);
	if (lhs.first == rhs.first && lhs.second <= rhs.second)
		return (true);
	return (false);
}
template<class T1, class T2, class U1, class U2>
bool operator>(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
{
	if (lhs.first > rhs.first)
		return (true);
	if (lhs.first == rhs.first && lhs.second > rhs.second)
		return (true);
	return (false);
}
template<class T1, class T2, class U1, class U2>
bool operator>=(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
{
	if (lhs.first > rhs.first)
		return (true);
	if (lhs.first == rhs.first && lhs.second >= rhs.second)
		return (true);
	return (false);
}
/* pair end */

/* enable_if start */
template<bool B, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T>
{
	typedef T type
};
/* enable_if end*/

/* is_integral start */
template<class T>
struct is_integral
{
	enum {value = false};

	constexpr operator bool()??????

	typedef value_type bool;
	typedef type is_integral<T>;
};
/* is_integral end */

}