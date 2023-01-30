/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:28:25 by dham              #+#    #+#             */
/*   Updated: 2023/01/30 15:44:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
: _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap(" << _name <<  ") constructor called" << '\n';
}

ClapTrap::ClapTrap(const ClapTrap &c)
:	_name(c._name), _hit_point(c._hit_point),
	_energy_point(c._energy_point), _attack_damage(c._attack_damage)
{
	std::cout << "ClapTrap(" << _name <<  ") Copy constructor called" << '\n';
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap(" << _name <<  ") destructor called" << '\n';
}

ClapTrap	&ClapTrap::operator==(const ClapTrap &c)
{
	_name = c._name;
	_hit_point = c._hit_point;
	_energy_point = c._energy_point;
	_attack_damage = c._attack_damage;
	std::cout << "Copy assignment operator called" << '\n';
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!able_action())
		return ;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", ";
	std::cout << "causing " << _attack_damage << " points of damage!" << '\n';
	_energy_point--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point == 0)
	{
		std::cout << _name << " already has no hit point." << '\n';
		return ;
	}
	std::cout << "ClapTrap " << _name << " received " << amount << " damage." << '\n';
	_hit_point -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!able_action())
		return ;
	std::cout << "ClapTrap " << _name << " repaired by " << amount << " points." << '\n';
	_hit_point += amount;
	_energy_point--;
}

bool	ClapTrap::able_action(void)
{
	if (_hit_point == 0)
	{
		std::cout << _name << " has no hit point." << '\n';
		return (false);
	}
	if (_energy_point == 0)
	{
		std::cout << _name << " has no energy." << '\n';
		return (false);
	}
	return (true);
}
