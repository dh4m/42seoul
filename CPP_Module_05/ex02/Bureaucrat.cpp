/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:03:02 by dham              #+#    #+#             */
/*   Updated: 2023/02/10 18:09:54 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void)
{}

Bureaucrat::Bureaucrat(std::string name, int grade)
:_name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
:_name(copy._name), _grade(copy._grade)
{}

Bureaucrat::~Bureaucrat(void)
{}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	_grade = copy._grade;
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(int grade)
{
	if (_grade - grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade -= grade;
}

void Bureaucrat::decrementGrade(int grade)
{
	if (_grade + grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade += grade;
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << '\n';
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't sign " << f.getName() \
					<< " because Bureaucrat has too low grade" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << '\n';
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() \
					<< " because Bureaucrat has too low grade" << '\n';
	}
	catch(const AForm::UnsignedFormException& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() \
					<< " because the form is not signed" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException : Bureaucrat has too high grade");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException : Bureaucrat has too low grade");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out);
}