/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:31:20 by dham              #+#    #+#             */
/*   Updated: 2023/01/08 02:39:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "address of str : " << &str << '\n';
	std::cout << "address of stringPTR : " << &stringPTR << '\n';
	std::cout << "address of stringREF : " << &stringREF << '\n';

	std::cout << "value of str : " << str << '\n';
	std::cout << "value pointed to by stringPTR : " << *stringPTR << '\n';
	std::cout << "value pointed to by stringREF : " << stringREF << '\n';
}