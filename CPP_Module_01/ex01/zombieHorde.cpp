/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:17:37 by dham              #+#    #+#             */
/*   Updated: 2023/01/08 02:22:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*ret_zombie_arr;

	ret_zombie_arr = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		ret_zombie_arr[i].nameSet(name);
	}
	return (ret_zombie_arr);
}