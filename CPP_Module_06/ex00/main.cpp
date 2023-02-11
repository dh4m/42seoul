/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:38:26 by dham              #+#    #+#             */
/*   Updated: 2023/02/11 19:04:46 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScalarLiteral.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: The program can receive only one parameter!" << std::endl;
		return (1);
	}
	std::string raw = argv[1];
	ScalarLiteral scalar(raw);

	scalar.printAllConversion();
	return (0);
}