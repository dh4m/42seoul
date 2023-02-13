/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:33:05 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 17:49:53 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &list, int search)
{
	return (std::find(list.begin(), list.end(), search));
}