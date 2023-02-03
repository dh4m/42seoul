/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:28:41 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 13:59:53 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a("a");
	DiamondTrap	b("b");
	ClapTrap	*c = new DiamondTrap("c");
	
	a.attack("b");
	c->attack("b");
	b.takeDamage(30);
	b.beRepaired(10);
	b.highFivesGuys();
	b.guardGate();
	b.whoAmI();
	delete c;
	return (0);
}