/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:10:11 by dham              #+#    #+#             */
/*   Updated: 2023/02/05 14:21:09 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

static	int	str_to_index(std::string& str)
{
	if (str.empty())
		return (0);
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

	i = _num % 8;
	_contact[i].field_input(FIRST_NAME);
	_contact[i].field_input(LAST_NAME);
	_contact[i].field_input(NICKNAME);
	_contact[i].field_input(PHONE_NUMBER);
	_contact[i].field_input(DARKEST_SECRET);
	_num++;
}

void	PhoneBook::search(void)
{
	std::string	choice;
	int			index;

	if (_num == 0)
		return ;
	for (int i = 0; i < 8 && i < _num; i++)
	{
		std::cout << std::setw(10) << i + 1 << '|';
		std::cout << std::setw(10) << _contact[i].field_value(FIRST_NAME, FIXED) << '|';
		std::cout << std::setw(10) << _contact[i].field_value(LAST_NAME, FIXED) << '|';
		std::cout << std::setw(10) << _contact[i].field_value(NICKNAME, FIXED) << '|' << '\n';
	}
	std::cout << "Please input index of the entry to display : ";
	std::getline(std::cin, choice);
	index = str_to_index(choice);
	while (!index || index > _num)
	{
		if (std::cin.eof())
		{
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << '\n';
		}
		std::cout << "invalid input! Please try again : ";
		std::getline(std::cin, choice);
		index = str_to_index(choice);
	}
	std::cout << "first name : " << _contact[index - 1].field_value(FIRST_NAME, UNFIXED) << '\n';
	std::cout << "last name : " << _contact[index - 1].field_value(LAST_NAME, UNFIXED) << '\n';
	std::cout << "nickname : " << _contact[index - 1].field_value(NICKNAME, UNFIXED) << '\n';
	std::cout << "phone number : " << _contact[index - 1].field_value(PHONE_NUMBER, UNFIXED) << '\n';
	std::cout << "darkest secret : " << _contact[index - 1].field_value(DARKEST_SECRET, UNFIXED) << '\n';
}

PhoneBook::PhoneBook(void)
{
	_num = 0;
}