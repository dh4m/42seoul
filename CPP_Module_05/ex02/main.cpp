/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:21:54 by dham              #+#    #+#             */
/*   Updated: 2023/02/10 18:27:23 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a("a", 2);
		Bureaucrat b("b", 50);
		Bureaucrat c("c", 30);
		ShrubberyCreationForm s_f("home");
		RobotomyRequestForm r_f("human");
		PresidentialPardonForm p_f("dham");
		

		a.signForm(s_f);
		std::cout << a << '\n';
		std::cout << s_f << '\n';
		a.executeForm(s_f);
		std::cout << "\n";

		b.signForm(r_f);
		std::cout << b << '\n';
		std::cout << r_f << '\n';
		b.executeForm(r_f);
		std::cout << "\n";

		c.signForm(p_f);
		std::cout << c << '\n';
		std::cout << p_f << '\n';
		c.executeForm(p_f);
		std::cout << "\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}