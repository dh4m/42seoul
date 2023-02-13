/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:50:14 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 14:21:43 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void print_int(const T i)
{
	std::cout << i << std::endl;
}

template<typename T>
void increament(T &i)
{
	i++;
}

template<>
void increament<std::string>(std::string &i)
{
	i += "_test";
}

int main(void)
{
	std::string arr[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

	iter(arr, 10, print_int<std::string>);
	iter(arr, 10, increament<std::string>);
	iter(arr, 10, print_int<std::string>);
}