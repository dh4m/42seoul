/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:51:35 by dham              #+#    #+#             */
/*   Updated: 2023/01/08 01:53:40 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie_ptr;

	randomChump("stack zombie");
	zombie_ptr = newZombie("heap zombie");
	zombie_ptr->announce();
	delete zombie_ptr;
	return (0);
}