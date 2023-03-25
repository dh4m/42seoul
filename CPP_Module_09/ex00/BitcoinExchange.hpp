/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:11:12 by dham              #+#    #+#             */
/*   Updated: 2023/03/25 18:36:36 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	~BitcoinExchange(void);

	void input_database_file(const char *filename);
	void execute_exchange(const char *txtfile);
	void result_output(const std::string &input);
	static bool valid_date(const std::string &date);
	static bool valid_rate(const std::string &rate_str);
private:
	std::map<std::string, float> coin_data;

	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange	&operator=(const BitcoinExchange &copy);
};

#endif
