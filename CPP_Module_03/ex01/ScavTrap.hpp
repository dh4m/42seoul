/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:02:58 by dham              #+#    #+#             */
/*   Updated: 2023/02/02 15:06:51 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap(void);

	ScavTrap	&operator=(const ScavTrap &c);

	void	attack(const std::string& target);
	void	guardGate(void);
};

#endif