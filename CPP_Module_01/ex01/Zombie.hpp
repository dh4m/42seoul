/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:14:53 by dham              #+#    #+#             */
/*   Updated: 2023/01/08 02:21:26 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
public:
	Zombie(void);
	Zombie(std::string z_name);
	~Zombie(void);
	void	announce(void);
	void	nameSet(std::string z_name);
private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif