/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:33:52 by dham              #+#    #+#             */
/*   Updated: 2023/06/25 22:17:51 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <set>
#include <string>
#include <bitset>

#include "Client.hpp"

enum e_chanmode
{
	INVITEONLY,
	TOPICEXIST,
	MODERATED
};

class Channel
{
public:
	Channel(std::string name);
	~Channel(void);

	int channel_output(std::string &content, Client *talker);
private:
	const std::string _name;
	std::string _passwd;
	std::set<Client*> _member;
	std::set<Client*> _operator;
	std::set<Client*> _ban_list;
	std::bitset<3> _mode;

	Channel	&operator=(const Channel &copy);
	Channel(const Channel &copy);
};

#endif
