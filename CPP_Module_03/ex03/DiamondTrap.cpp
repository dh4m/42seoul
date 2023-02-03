/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:14:54 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 16:46:09 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
:ClapTrap(), FragTrap(), ScavTrap()
{
	_attack_damage = 30;
	std::cout << "DiamondTrap default constructor called" << '\n';
}

DiamondTrap::DiamondTrap(std::string name)
:ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
	ClapTrap::_name = name + "_clap_name";
	_attack_damage = 30;
	std::cout << "DiamondTrap(" << _name <<  ") constructor called" << '\n';
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
:ClapTrap(copy), FragTrap(copy), ScavTrap(copy), _name(copy._name)
{
	std::cout << "DiamondTrap(" << _name <<  ") Copy constructor called" << '\n';
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap(" << _name <<  ") destructor called" << '\n';
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	_name = copy._name;
	ClapTrap::_name = copy.ClapTrap::_name;
	_hit_point = copy._hit_point;
	_energy_point = copy._energy_point;
	_attack_damage = copy._attack_damage;
	std::cout << "DiamondTrap Copy assignment operator called" << '\n';
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << _name << "." << '\n';
	std::cout << "And my ClapTrap name is " << ClapTrap::_name << "." << '\n';
}
