/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:14:44 by dham              #+#    #+#             */
/*   Updated: 2023/02/11 00:04:23 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
: AForm(copy)
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	check_excutable(executor);
	srand(time(NULL));
	std::cout << "whirrrrrrr whirrrrrrr..." << '\n';
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully!" << '\n';
	else
		std::cout << "Failed to robotomized " << getTarget() << ".." << '\n';
}

AForm *RobotomyRequestForm::formMaker(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}