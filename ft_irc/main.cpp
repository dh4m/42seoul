/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:14:23 by dham              #+#    #+#             */
/*   Updated: 2023/04/09 17:53:09 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Server.hpp"

void invalid_input(void)
{
	std::cerr << "Invalid input!" << std::endl;
	exit(EXIT_FAILURE);
}

bool isnum(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int main(int argc, char *argv[])
{
	if (argc != 3 || !isnum(argv[1]))
		invalid_input();
	
	Server serv(atoi(argv[1]), argv[2]);
	if (!serv.init())
		return (1);
	if (!serv.run())
		serv.errDetect();
	return (0);
}