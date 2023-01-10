/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:05:13 by dham              #+#    #+#             */
/*   Updated: 2023/01/11 01:31:30 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::complain(std::string level)
{
	const std::string	level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*m_func[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(level_list[i]) == 0)
		{
			(this->*m_func[i])();
		}
	}
	std::cout << "Invalid input!" << '\n';
}

void	Harl::debug(void)
{
	;
}

void	Harl::info(void)
{
	;
}

void	Harl::warning(void)
{
	;
}

void	Harl::error(void)
{
	;
}
