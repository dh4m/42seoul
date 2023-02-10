/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:15 by dham              #+#    #+#             */
/*   Updated: 2023/02/11 01:00:37 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}

Intern::~Intern(void)
{}

Intern	&Intern::operator=(const Intern &copy)
{
	(void) copy;
	return (*this);
}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
	const std::string form_name_list[FORMTYPE_NUM] = {
		"shrubbery creation", "robotomy request", "presidential pardon"
	};
	const std::string form_class_name_list[FORMTYPE_NUM] = {
		"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"
	};
	AForm *(*maker[3])(const std::string &target) = {
		ShrubberyCreationForm::formMaker, 
		RobotomyRequestForm::formMaker, 
		PresidentialPardonForm::formMaker
	};
	
	for (int i = 0; i < FORMTYPE_NUM; i++)
	{
		if (form_name_list[i] == form_name)
		{
			std::cout << "Intern creates " << form_class_name_list[i] << '\n';
			return (maker[i](form_target));
		}
	}
	std::cerr	<< "The intern failed to create the form "\
				<< "because there was no name for the matching form." << '\n';
	return (NULL);
}
