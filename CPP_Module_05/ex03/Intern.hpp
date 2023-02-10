/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:08 by dham              #+#    #+#             */
/*   Updated: 2023/02/11 00:52:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

#define FORMTYPE_NUM 3

class Intern
{
public:
	Intern(void);
	Intern(const Intern &copy);
	~Intern(void);

	Intern &operator=(const Intern &copy);
	
	AForm *makeForm(std::string form_name, std::string form_target);
};

#endif
