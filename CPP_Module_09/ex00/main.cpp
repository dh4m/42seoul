/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:11:16 by dham              #+#    #+#             */
/*   Updated: 2023/03/25 17:11:00 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

void invalid_arg(void)
{
	std::cerr << "Error: could not open file." << std::endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	BitcoinExchange btc;

	if (argc != 2)
		invalid_arg();
	btc.input_database_file("data.csv");
	btc.execute_exchange(argv[1]);
	return (0);
}