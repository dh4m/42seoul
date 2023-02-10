/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:32:13 by dham              #+#    #+#             */
/*   Updated: 2023/02/10 14:37:51 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int grade_sign, int grade_exe)
: _name(name), _sign(false), _grade_sign(grade_sign), _grade_execute(grade_exe)
{
	if (_grade_sign < 1 || _grade_execute < 1)
		throw (AForm::GradeTooHighException());
	else if (_grade_sign > 150 || _grade_execute > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &copy)
: _name(copy._name), _sign(copy._sign), \
_grade_sign(copy._grade_sign), _grade_execute(copy._grade_execute), \
_target(copy._target)
{}

AForm::~AForm(void)
{}

bool AForm::getSigned(void) const
{
	return (_sign);
}

const std::string &AForm::getName(void) const
{
	return (_name);
}

int AForm::getGradeSign(void) const
{
	return (_grade_sign);
}

int AForm::getGradeExecute(void) const
{
	return (_grade_execute);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _grade_sign)
		_sign = true;
	else
		throw (AForm::GradeTooLowException());
}

const std::string &AForm::getTarget(void) const
{
	return (_target);
}

void AForm::setTarget(const std::string &target)
{
	_target = target;
}

bool AForm::check_excutable(Bureaucrat const & executor) const
{
	if (!_sign)
		throw (AForm::UnsignedFormException());
	if (executor.getGrade() > _grade_execute)
		throw (AForm::GradeTooLowException());
	return (true);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException : Form has too high grade");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException : Form has too low grade");
}

const char *AForm::UnsignedFormException::what(void) const throw()
{
	return ("UnsignedFormException : Form is not signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << f.getName() << ", " \
		<< "signed: " << std::boolalpha << f.getSigned() << ", " \
		<< "grade required to sign it: " << f.getGradeSign() << ", " \
		<< "grade required to excute it: " << f.getGradeExecute() << ".";
	return (out);
}