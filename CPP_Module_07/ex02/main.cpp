/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:19:51 by dham              #+#    #+#             */
/*   Updated: 2023/02/13 14:29:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
	// default value test
	for (int i = 0; i < 10; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
    int* mirror = new int[MAX_VAL];
	// value assignment test
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
    }
    // deep copy test and subscript operator test
    {
        Array<int> tmp = numbers;
		for (int i = 0; i < 10; i++)
		{
			tmp[i] = numbers[i] + 1;
		}
        Array<int> test(tmp);
		for (int i = 0; i < 10; i++)
		{
			test[i] = tmp[i] + 1;
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << i << " " << numbers[i] << " " << tmp[i] << " " << test[i] << std::endl;
		}
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	// out of range test
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	// size member function test
	std::cout << "numbers size: " << numbers.size() << std::endl;

    delete [] mirror;//
    return 0;
}