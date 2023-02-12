/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:19:12 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 01:21:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
public:
	Array(void)
	{
		
	}

	Array(const Array &copy);
	~Array(void);

	Array	&operator=(const Array &copy);
private:

};

#endif