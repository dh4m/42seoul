/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:11:14 by dham              #+#    #+#             */
/*   Updated: 2023/03/25 18:42:55 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::~BitcoinExchange(void)
{}

void BitcoinExchange::input_database_file(const char *filename)
{
	std::ifstream	csvfile(filename);
	std::string		date;
	std::string		rate_str;
	float			rate;

	if (!csvfile.is_open())
	{
		std::cerr << "CSV file open error" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::getline(csvfile, date);
	if (date != "date,exchange_rate")
	{
		std::cerr << "invalid csv file error" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::getline(csvfile, date, ',');
	std::getline(csvfile, rate_str);
	while (csvfile)
	{
		rate = std::atof(rate_str.c_str());
		if (!valid_date(date) || !valid_rate(rate_str) || rate < 0)
		{
			std::cerr << "invalid CSV file error" << std::endl;
			exit(EXIT_FAILURE);
		}
		coin_data.insert(std::pair<std::string, float>(date, rate));
		std::getline(csvfile, date, ',');
		std::getline(csvfile, rate_str);
	}
	csvfile.close();
}

bool BitcoinExchange::valid_date(const std::string &date)
{
	int year;
	int month;
	int day;
	const char *date_str = date.c_str();
	char *de_ptr;

	year = std::strtol(date_str, &de_ptr, 10);
	if (*de_ptr != '-' || year < 0)
		return (false);
	month = std::strtol(de_ptr + 1, &de_ptr, 10);
	if (*de_ptr != '-' || month < 0 || month > 12)
		return (false);
	day = std::strtol(de_ptr + 1, &de_ptr, 10);
	if (*de_ptr)
		return (false);
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return (day > 0 && day <= 31 ? true : false);
		break;
	case 4: case 6: case 9: case 11:
		return (day > 0 && day <= 30 ? true : false);
		break;
	case 2:
		if (year % 4 == 0 && !(year % 100 == 0 && year % 400))
			return (day > 0 && day <= 29 ? true : false);
		return (day > 0 && day <= 28 ? true : false);
		break;
	default:
		break;
	}
	return (true);
}

bool BitcoinExchange::valid_rate(const std::string &rate_str)
{
	int 						flag = 0;
	std::string::const_iterator	it = rate_str.begin();

	if (*it == '+' || *it == '-')
		it++;
	for (; it != rate_str.end(); ++it)
	{
		if ((*it < '0' || *it > '9') && *it != '.')
			return (false);
		if (*it == '.' && flag++)
			return (false);
	}
	return (true);
}

void BitcoinExchange::execute_exchange(const char *txtfile)
{
	std::ifstream	txt(txtfile);
	std::string		input;

	if (!txt.is_open())
	{
		std::cerr << "txt file open error" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::getline(txt, input);
	if (input != "date | value")
	{
		std::cerr << "invalid txt file error" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::getline(txt, input);
	while (txt)
	{
		result_output(input);
		std::getline(txt, input);
	}
	txt.close();
}

void BitcoinExchange::result_output(const std::string &input)
{
	std::string								date;
	std::string								rate_str;
	float									rate;
	std::map<std::string, float>::iterator	iter;

	if (input.find('|') != std::string::npos)
	{
		date = input.substr(0, input.find('|') - 1);
		rate_str = input.substr(input.find('|') + 2);
		rate = std::atof(rate_str.c_str());
		if (!valid_date(date) || !valid_rate(rate_str))
			std::cout << "Error: bad input => " << input << std::endl;
		else if (rate < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (rate > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			iter = coin_data.lower_bound(date);
			if ((*iter).first != date)
			{
				if (iter != coin_data.begin())
				{
					iter--;
					std::cout << date << " => " << rate << " = " << (*iter).second * rate;
				}
				else
					std::cout << "Error: data does not exist.";
			}
			else
				std::cout << date << " => " << rate << " = " << (*iter).second * rate;
			std::cout << std::endl;
		}
	}
	else
		std::cout << "Error: bad input => " << input << std::endl;
}