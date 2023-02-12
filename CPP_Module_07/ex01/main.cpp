/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:50:14 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 01:18:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


void print_int(int i)
{
	std::cout << i << std::endl;
}

void increament_int(int &i)
{
	i++;
}

int main(void)
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter(arr, 10, print_int);
	iter(arr, 10, increament_int);
	iter(arr, 10, print_int);
}