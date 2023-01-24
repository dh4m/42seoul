/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:05:13 by dham              #+#    #+#             */
/*   Updated: 2023/01/24 19:55:19 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

const std::string	Harl::level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(const std::string &level)
{
	filter_idx = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level.compare(level_list[i]) == 0)
		{
			filter_idx = i;
		}
	}
}

void	Harl::complain(void)
{
	void	(Harl::*m_func[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

	switch (filter_idx)
	{
	case 0:
		(this->*m_func[0])();
		std::cout << '\n';
	case 1:
		(this->*m_func[1])();
		std::cout << '\n';
	case 2:
		(this->*m_func[2])();
		std::cout << '\n';
	case 3:
		(this->*m_func[3])();
		std::cout << '\n';
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break ;
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
