/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:41:02 by dham              #+#    #+#             */
/*   Updated: 2023/01/09 21:14:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string p_name)
{
	name = p_name;
	weapon = NULL;
}

void	HumanB::setWeapon(Weapon &p_weapon)
{
	weapon = &p_weapon;
}

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << '\n';
	else
		std::cout << name << " doesn't have a weapon" << '\n';
}