/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:32:16 by dham              #+#    #+#             */
/*   Updated: 2023/02/10 14:38:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class AForm
{
public:
	AForm(const std::string &name, int grade_sign, int grade_exe);
	AForm(const AForm &copy);
	virtual ~AForm(void);

	bool getSigned(void) const;
	const std::string &getName(void) const;
	int getGradeSign(void) const;
	int getGradeExecute(void) const;
	void beSigned(const Bureaucrat &b);
	const std::string &getTarget(void) const;
	void setTarget(const std::string &target);
	virtual void execute(Bureaucrat const & executor) const = 0;
	bool check_excutable(Bureaucrat const & executor) const;

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
	class UnsignedFormException: public std::exception
	{
	public:
		const char *what() const throw();
	};
private:
	const std::string _name;
	bool _sign;
	const int _grade_sign;
	const int _grade_execute;
	std::string _target;

	AForm(void);
	AForm	&operator=(const AForm &copy);
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
