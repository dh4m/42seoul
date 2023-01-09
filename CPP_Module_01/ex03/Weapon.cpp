/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:17:21 by dham              #+#    #+#             */
/*   Updated: 2023/01/09 19:40:46 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string p_type)
{
	type = p_type;
}

const std::string	&Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(const std::string &type_str)
{
	type = type_str;
}