/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:43:08 by dham              #+#    #+#             */
/*   Updated: 2023/02/02 15:04:08 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	~FragTrap(void);

	FragTrap	&operator=(const FragTrap &copy);

	void	highFivesGuys(void);
};

#endif