/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:21:54 by dham              #+#    #+#             */
/*   Updated: 2023/02/11 01:04:13 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a("a", 2);
		Bureaucrat b("b", 50);
		Bureaucrat c("c", 30);

		Intern someRandomIntern;
		AForm *s_f;
		s_f = someRandomIntern.makeForm("shrubbery creation", "home");
		AForm *r_f;
		r_f = someRandomIntern.makeForm("robotomy request", "human");
		AForm *p_f;
		p_f = someRandomIntern.makeForm("presidential pardon", "dham");
		if (!s_f || !r_f || !p_f)
			return (1);
		std::cout << "\n";

		a.signForm(*s_f);
		std::cout << a << '\n';
		std::cout << *s_f << '\n';
		a.executeForm(*s_f);
		std::cout << "\n";

		b.signForm(*r_f);
		std::cout << b << '\n';
		std::cout << *r_f << '\n';
		b.executeForm(*r_f);
		std::cout << "\n";

		c.signForm(*p_f);
		std::cout << c << '\n';
		std::cout << *p_f << '\n';
		c.executeForm(*p_f);
		std::cout << "\n";

		delete s_f;
		delete r_f;
		delete p_f;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}