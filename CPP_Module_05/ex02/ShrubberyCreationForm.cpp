/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:15:10 by dham              #+#    #+#             */
/*   Updated: 2023/02/10 18:18:29 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
: AForm(copy)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	check_excutable(executor);
	std::ofstream ofs(getTarget() + "_shrubbery");
	if (!ofs.is_open())
	{
		std::cerr << "Failed to output file open" << '\n';
		return ;
	}
	ofs << "              ,@@@@@@@,\n"
		<< "      ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
		<< "       |o|        | |         | |\n"
		<< "       |.|        | |         | |\n"
		<< "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	ofs.close();
}
