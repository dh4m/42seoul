/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:14:50 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 17:15:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);
private:

};

#endif
