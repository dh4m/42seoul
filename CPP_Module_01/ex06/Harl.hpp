/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:56:28 by dham              #+#    #+#             */
/*   Updated: 2023/01/24 19:47:30 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
public:
	Harl(const std::string &level);
	void	complain(void);
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	int	filter_idx;
	
	static const std::string	level_list[4];
};

#endif