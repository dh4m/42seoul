/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:14:25 by dham              #+#    #+#             */
/*   Updated: 2023/02/11 00:02:35 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5)
{
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm(copy)
{}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	check_excutable(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << '\n';
}

AForm *PresidentialPardonForm::formMaker(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}