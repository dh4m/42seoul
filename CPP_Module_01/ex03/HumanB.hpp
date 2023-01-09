/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:08:36 by dham              #+#    #+#             */
/*   Updated: 2023/01/09 21:16:50 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class	HumanB
{
public:
	HumanB(std::string p_name);
	void	setWeapon(Weapon &p_weapon);
	void	attack(void);
private:
	Weapon		*weapon;
	std::string	name;
};

#endif