/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:43:05 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 16:46:04 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "FragTrap default constructor called" << '\n';
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	std::cout << "FragTrap(" << _name <<  ") constructor called" << '\n';
}

FragTrap::FragTrap(const FragTrap &copy)
: ClapTrap(copy._name)
{
	_hit_point = copy._hit_point;
	_energy_point = copy._energy_point;
	_attack_damage = copy._attack_damage;
	std::cout << "FragTrap(" << _name <<  ") Copy constructor called" << '\n';
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap(" << _name <<  ") destructor called" << '\n';
}

FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	_name = copy._name;
	_hit_point = copy._hit_point;
	_energy_point = copy._energy_point;
	_attack_damage = copy._attack_damage;
	std::cout << "FragTrap Copy assignment operator called" << '\n';
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requested a positive high five!" << '\n';
}