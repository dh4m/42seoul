/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:01:07 by dham              #+#    #+#             */
/*   Updated: 2023/02/12 16:04:52 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data test;
	test.data = 42;
	Data *test_ptr = &test;

	if (&test == deserialize(serialize(&test)))
		std::cout << "Success!" << std::endl;
	if (test_ptr == deserialize(serialize(test_ptr)))
		std::cout << "Success!" << std::endl;
	std::cout << deserialize(serialize(&test))->data << std::endl;
	return (0);
}