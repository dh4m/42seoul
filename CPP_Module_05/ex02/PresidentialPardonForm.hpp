/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:14:38 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 17:14:41 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &copy);
private:

};

#endif
