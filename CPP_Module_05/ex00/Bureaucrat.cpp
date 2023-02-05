/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:03:02 by dham              #+#    #+#             */
/*   Updated: 2023/02/05 15:48:55 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{}

Bureaucrat::Bureaucrat(std::string name, int grade)
:_name(name), _grade(grade)
{}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{

}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{

	return (*this);
}
