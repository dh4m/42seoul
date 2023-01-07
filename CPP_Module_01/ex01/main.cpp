/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:22:32 by dham              #+#    #+#             */
/*   Updated: 2023/01/08 02:28:52 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie_horde;
	int		num;

	num = 10;
	zombie_horde = zombieHorde(num, "zombieHorde");
	for (int i = 0; i < num; i++)
	{
		zombie_horde[i].announce();
	}
	delete[] zombie_horde;
	return (0);
}