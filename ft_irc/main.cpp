/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:14:23 by dham              #+#    #+#             */
/*   Updated: 2023/07/22 17:24:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Server.hpp"

void invalid_input(void)
{
	std::cerr << "Invalid input!" << std::endl;
	std::cerr << "Usage: ./ircserv port password(optional)" << std::endl; // usage 쓸 것
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

void server_close_signal(int sig)
{
	exit(0); // 더 좋은 게 있긴 한가...?
}

int main(int argc, char *argv[])
{
	int res;

	if (argc != 3 || !isnum(argv[1]))
		invalid_input();
	signal(SIGTERM, server_close_signal);
	Server serv(atoi(argv[1]), argv[2]);

	if (!serv.init())
		return (1);
	serv.run();
	serv.destroy();
	return (0);
}