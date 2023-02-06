/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:32:16 by dham              #+#    #+#             */
/*   Updated: 2023/02/06 20:44:46 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Form
{
public:
	Form(void);
	Form(const Form &copy);
	~Form(void);

	Form	&operator=(const Form &copy);

	bool getSigned(void) const;
	const std::string &getName(void);
	int getGradeSign(void);
	int getGradeExecute(void);

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
	const std::string name;
	bool sign;
	const int grade_sign;
	const int grade_execute;
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
