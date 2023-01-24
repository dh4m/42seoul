/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:43:05 by dham              #+#    #+#             */
/*   Updated: 2023/01/24 19:49:35 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Please input only one input!\n";
		return (1);
	}
	Harl	harl(argv[1]);

	harl.complain();
	return (0);
}