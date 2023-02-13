/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:33:03 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 17:52:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> v_i;
	v_i.push_back(1);
	v_i.push_back(2);
	v_i.push_back(3);
	v_i.push_back(4);
	v_i.push_back(5);
	v_i.push_back(6);
	v_i.push_back(7);
	v_i.push_back(8);
	v_i.push_back(9);
	v_i.push_back(10);

	std::vector<int>::iterator it;
	int find_num = 12;
	it = easyfind(v_i, find_num);
	if (it == v_i.end())
		std::cout << find_num << " was not found!" << std::endl;
	else
		std::cout << *it << " is in the " << it - v_i.begin() << " index." << std::endl;
	return (0);
}