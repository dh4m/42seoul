/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:30:31 by dham              #+#    #+#             */
/*   Updated: 2023/02/12 15:33:24 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DATA_HPP
# define DATA_HPP

#include <cstdint>

struct Data
{
	int data;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif