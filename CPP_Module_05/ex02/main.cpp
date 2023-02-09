/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:21:54 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 16:37:35 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a("a", 2);
		Bureaucrat b("b", 150);
		Bureaucrat c("c", 10);
		Form f_a("f_a", 1, 10);
		Form f_b("f_b", 150, 10);
		Form f_c("f_c", 10, 10);

		a.signForm(f_a);
		std::cout << a << '\n';
		std::cout << f_a << '\n';
		b.signForm(f_b);
		std::cout << b << '\n';
		std::cout << f_b << '\n';
		c.signForm(f_c);
		std::cout << c << '\n';
		std::cout << f_c << '\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}