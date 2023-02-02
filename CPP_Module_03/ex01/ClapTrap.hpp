/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:28:37 by dham              #+#    #+#             */
/*   Updated: 2023/02/02 15:06:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &c);
	virtual ~ClapTrap(void);

	ClapTrap	&operator=(const ClapTrap &c);

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
protected:
	bool	able_action(void);
	
	std::string		_name;
	unsigned int	_hit_point;
	unsigned int	_energy_point;
	unsigned int	_attack_damage;
};

#endif