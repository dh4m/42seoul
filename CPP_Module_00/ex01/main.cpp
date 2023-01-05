/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:42:49 by dham              #+#    #+#             */
/*   Updated: 2023/01/06 01:08:33 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	do
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			book.add();
		else if (input.compare ("SEARCH") == 0)
			book.search();
	} while (input.compare("EXIT"));
	return (0);
}