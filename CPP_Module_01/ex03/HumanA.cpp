/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:40:56 by dham              #+#    #+#             */
/*   Updated: 2023/01/09 21:19:46 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string p_name, Weapon &p_weapon)
: weapon(p_weapon), name(p_name)
{

}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}