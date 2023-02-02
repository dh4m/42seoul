/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:03:05 by dham              #+#    #+#             */
/*   Updated: 2023/02/01 21:40:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << '\n';
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap(" << _name <<  ") constructor called" << '\n';
}

ScavTrap::ScavTrap(const ScavTrap &copy)
: ClapTrap(copy._name)
{
	_hit_point = copy._hit_point;
	_energy_point = copy._energy_point;
	_attack_damage = copy._attack_damage;
	std::cout << "ScavTrap(" << _name <<  ") Copy constructor called" << '\n';
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap(" << _name <<  ") destructor called" << '\n';
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &c)
{
	_name = c._name;
	_hit_point = c._hit_point;
	_energy_point = c._energy_point;
	_attack_damage = c._attack_damage;
	std::cout << "ScavTrap Copy assignment operator called" << '\n';
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!able_action())
		return ;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", ";
	std::cout << "causing " << _attack_damage << " points of damage!" << '\n';
	_energy_point--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << '\n';
}
