/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:38:22 by dham              #+#    #+#             */
/*   Updated: 2023/02/02 22:35:44 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

class DiamondTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap &copy);
	~DiamondTrap(void);

	DiamondTrap	&operator=(const DiamondTrap &copy);
private:

};

#endif
