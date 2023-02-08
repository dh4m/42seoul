/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:32:16 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 00:43:51 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form
{
public:
	Form(const std::string &name, int grade_sign, int grade_exe);
	Form(const Form &copy);
	~Form(void);

	Form	&operator=(const Form &copy);

	bool getSigned(void) const;
	const std::string &getName(void) const;
	int getGradeSign(void) const;
	int getGradeExecute(void) const;
	void beSigned(const Bureaucrat &b);

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
	bool _sign;
	const int _grade_sign;
	const int _grade_execute;

	Form(void);
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
