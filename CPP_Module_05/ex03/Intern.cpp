/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:15 by dham              #+#    #+#             */
/*   Updated: 2023/02/10 19:30:29 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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
	return (*this);
}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
	
}