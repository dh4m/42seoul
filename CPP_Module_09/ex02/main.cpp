/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:41:41 by dham              #+#    #+#             */
/*   Updated: 2023/03/26 00:27:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	PmergeMe p(argc - 1);

	if (!p.init_arr(argv))
	{
		std::cout << "Error" << std::endl;
		return (EXIT_FAILURE);
	}
	p.vector_sort();
	p.deque_sort();
	return (0);
}