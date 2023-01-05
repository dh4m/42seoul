/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:10:11 by dham              #+#    #+#             */
/*   Updated: 2023/01/05 23:08:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

static	int	str_to_index(std::string& str)
{
	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++)
	{
		if (!isdigit(*iter))
			return (0);
	}
	return (atoi(str.c_str()));
}

void	PhoneBook::add(void)
{
	int	i;

	i = num % 8;
	contact[i].field_input(FIRST_NAME);
	contact[i].field_input(LAST_NAME);
	contact[i].field_input(NICKNAME);
	contact[i].field_input(PHONE_NUMBER);
	contact[i].field_input(DARKEST_SECRET);
	num++;
}

void	PhoneBook::search(void)
{
	std::string	choice;
	int			index;

	if (num == 0)
		return ;
	for (int i = 0; i < 8 && i < num; i++)
	{
		std::cout << std::setw(10) << i + 1 << '|';
		std::cout << std::setw(10) << contact[i].field_value(FIRST_NAME, FIXED) << '|';
		std::cout << std::setw(10) << contact[i].field_value(LAST_NAME, FIXED) << '|';
		std::cout << std::setw(10) << contact[i].field_value(NICKNAME, FIXED) << '|' << '\n';
	}
	std::cout << "Please input index of the entry to display : ";
	std::cin >> choice;
	index = str_to_index(choice);
	while (!index || index > num)
	{
		std::cout << "invalid input! Please try again : ";
		std::cin >> choice;
		index = str_to_index(choice);
	}
	std::cout << "first name : " << contact[index - 1].field_value(FIRST_NAME, UNFIXED) << '\n';
	std::cout << "last name : " << contact[index - 1].field_value(LAST_NAME, UNFIXED) << '\n';
	std::cout << "nickname : " << contact[index - 1].field_value(NICKNAME, UNFIXED) << '\n';
	std::cout << "phone number : " << contact[index - 1].field_value(PHONE_NUMBER, UNFIXED) << '\n';
	std::cout << "darkest secret : " << contact[index - 1].field_value(DARKEST_SECRET, UNFIXED) << '\n';
}

PhoneBook::PhoneBook(void)
{
	num = 0;
}