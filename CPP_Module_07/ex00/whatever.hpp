/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:33:29 by dham              #+#    #+#             */
/*   Updated: 2023/02/12 19:41:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T &max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
T &min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

#endif
