/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:28:41 by dham              #+#    #+#             */
/*   Updated: 2023/01/30 20:42:22 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("a");
	ScavTrap	b("b");
	ClapTrap	*c = new ScavTrap("c");
	
	a.attack("b");
	c->attack("b");
	b.takeDamage(20);
	b.beRepaired(10);
	b.guardGate();
	delete c;
	return (0);
}