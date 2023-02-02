/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:28:41 by dham              #+#    #+#             */
/*   Updated: 2023/02/02 15:15:44 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a("a");
	FragTrap	b("b");
	ClapTrap	*c = new FragTrap("c");
	
	a.attack("b");
	c->attack("b");
	b.takeDamage(30);
	b.beRepaired(10);
	b.highFivesGuys();
	delete c;
	return (0);
}