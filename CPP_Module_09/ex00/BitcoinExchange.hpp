/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:11:12 by dham              #+#    #+#             */
/*   Updated: 2023/03/25 15:12:24 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange(void);

	BitcoinExchange	&operator=(const BitcoinExchange &copy);
private:

};

#endif
