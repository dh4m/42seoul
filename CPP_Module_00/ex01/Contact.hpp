/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:42:54 by dham              #+#    #+#             */
/*   Updated: 2023/01/06 16:19:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

enum	e_state
{
	UNFIXED,
	FIXED
};

enum	e_field
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
};

class Contact {
public:
	std::string	field_value(int field, int fixed);
	void		field_input(int field);
	bool		empty(void);
private:
	std::string	_field_string[5];
};

#endif