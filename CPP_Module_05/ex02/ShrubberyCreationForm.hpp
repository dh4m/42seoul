/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:15:13 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 17:15:18 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class ShrubberyCreationForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);
private:

};

#endif
