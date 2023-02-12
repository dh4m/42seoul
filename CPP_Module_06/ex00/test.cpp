/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:11:17 by dham              #+#    #+#             */
/*   Updated: 2023/02/12 14:07:44 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>

int main(void)
{
	char *ptr;
	std::string str = "nanf";
	float l;
	l = std::strtof(str.c_str(), &ptr);
	if (l == HUGE_VAL)
		std::cout << "asdf\n";
	std::cout << l << '\n';
	std::cout << ptr << '\n';
	return (0);
}