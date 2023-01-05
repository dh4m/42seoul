/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:08:22 by dham              #+#    #+#             */
/*   Updated: 2023/01/06 01:07:04 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include "Contact.hpp"

void	Contact::field_input(int field)
{
	std::string		str;
	std::string		filed_name;

	if (field == FIRST_NAME) filed_name = "first name";
	else if (field == LAST_NAME) filed_name = "last name";
	else if (field == NICKNAME) filed_name = "nickname";
	else if (field == PHONE_NUMBER) filed_name = "phone number";
	else if (field == DARKEST_SECRET) filed_name = "darkest secret";
	std::cout << filed_name << " : ";
	std::getline(std::cin, str);
	while (str.empty())
	{
		std::cout << "contact can't have empty space!" << '\n';
		std::cout << filed_name << " : ";
		std::cin.clear();
		std::cin.ignore();
		std::clearerr(stdin);
		std::getline(std::cin, str);
	}
	field_string[field] = str;
}

std::string	Contact::field_value(int field, int fixed)
{
	std::string	ret_str;

	if (fixed && field_string[field].length() > 10)
		ret_str = field_string[field].substr(0, 9) + ".";
	else
		ret_str = field_string[field];
	return (ret_str);
}

bool	Contact::empty(void)
{
	return (field_string[FIRST_NAME].empty());
}
