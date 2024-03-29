/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:50:16 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 01:14:53 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T *arr, size_t len, F func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

#endif