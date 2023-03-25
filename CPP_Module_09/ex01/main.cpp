/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:49:10 by dham              #+#    #+#             */
/*   Updated: 2023/03/25 19:30:28 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument" << std::endl;
		exit(EXIT_FAILURE);
	}
	int i = 0;
	RPN stack;

	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
		{
			i++;
			continue;
		}
		stack.input_char(argv[1][i]);
		i++;
	}
	if (stack.cnt() != 1)
		std::cout << "Error" << std::endl;
	else
		std::cout << stack.check_num() << std::endl;
	return (0);
}