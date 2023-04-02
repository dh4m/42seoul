/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:14:23 by dham              #+#    #+#             */
/*   Updated: 2023/04/02 21:04:46 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Eventq.hpp"

void invalid_input(void)
{
	std::cerr << "Invalid input!" << std::endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	Eventq evq;

	if (argc != 3)
		invalid_input();
	
}