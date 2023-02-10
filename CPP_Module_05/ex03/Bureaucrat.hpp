/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:02:53 by dham              #+#    #+#             */
/*   Updated: 2023/02/10 18:04:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class AForm;

class Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat(void);

	Bureaucrat	&operator=(const Bureaucrat &copy);

	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade(int grade);
	void decrementGrade(int grade);
	void signForm(AForm &f);
	void executeForm(AForm const& form) const;

	class GradeTooHighException: public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	const std::string _name;
	int _grade;

	Bureaucrat(void);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& b);

#endif
