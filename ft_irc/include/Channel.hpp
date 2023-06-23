/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:33:52 by dham              #+#    #+#             */
/*   Updated: 2023/06/23 15:54:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <set>
#include <string>

#include "Client.hpp"

class Channel
{
public:
	Channel(std::string name);
	~Channel(void);

	int channel_output(std::string &content, Client *talker);
private:
	const std::string _name;
	std::set<Client*> _member;

	Channel	&operator=(const Channel &copy);
	Channel(const Channel &copy);
};

#endif
