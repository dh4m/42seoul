/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:32:13 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 01:04:00 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int grade_sign, int grade_exe)
: _name(name), _sign(false), _grade_sign(grade_sign), _grade_execute(grade_exe)
{
	if (_grade_sign < 1 || _grade_execute < 1)
		throw (Form::GradeTooHighException());
	else if (_grade_sign > 150 || _grade_execute > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &copy)
: _name(copy._name), _sign(copy._sign), \
_grade_sign(copy._grade_sign), _grade_execute(copy._grade_execute)
{}

Form::~Form(void)
{}

Form	&Form::operator=(const Form &copy)
{
	(void) copy;
	std::cout << "Form cannot be copied.." << '\n';
	return (*this);
}

bool Form::getSigned(void) const
{
	return (_sign);
}

const std::string &Form::getName(void) const
{
	return (_name);
}

int Form::getGradeSign(void) const
{
	return (_grade_sign);
}

int Form::getGradeExecute(void) const
{
	return (_grade_execute);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _grade_sign)
		_sign = true;
	else
		throw (Form::GradeTooLowException());
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException : Form has too high grade");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException : Form has too low grade");
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << f.getName() << ", " \
		<< "signed: " << std::boolalpha << f.getSigned() << ", " \
		<< "grade required to sign it: " << f.getGradeSign() << ", " \
		<< "grade required to excute it: " << f.getGradeExecute() << ".";
	return (out);
}