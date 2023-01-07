/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:38:41 by dham              #+#    #+#             */
/*   Updated: 2023/01/08 02:21:17 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::Zombie(std::string z_name)
{
	name = z_name;
}

Zombie::~Zombie(void)
{
	std::cout << name << " is destroyed" << '\n';
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << '\n';
}

void	Zombie::nameSet(std::string z_name)
{
	name = z_name;
}