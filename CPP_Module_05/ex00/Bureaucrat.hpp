/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:02:53 by dham              #+#    #+#             */
/*   Updated: 2023/02/05 20:04:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat(void);

	Bureaucrat	&operator=(const Bureaucrat &copy);

	class GradeTooHighException: public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooHighException: public std::exception
	{
	public:
		const char *what() const throw();
	};
private:
	Bureaucrat(void);
	const std::string _name;
	int _grade;
};

#endif
