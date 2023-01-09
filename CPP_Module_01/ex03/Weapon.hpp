/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:06:41 by dham              #+#    #+#             */
/*   Updated: 2023/01/09 21:16:17 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class	Weapon
{
public:
	Weapon(std::string p_type);
	const std::string	&getType(void);
	void		setType(const std::string &type_str);
private:
	std::string type;
};

#endif