/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:33:52 by dham              #+#    #+#             */
/*   Updated: 2023/07/01 21:53:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <set>
#include <string>
#include <bitset>

#include "Client.hpp"
#include "ClientRef.hpp"

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

	int channel_output(std::string &content, int talker_fd);
private:
	const std::string _name;
	std::string _passwd;
	std::set<ClientRef> _member;
	std::set<ClientRef> _operator;
	std::set<ClientRef> _ban_list;
	std::bitset<3> _mode;

	Channel	&operator=(const Channel &copy);
	Channel(const Channel &copy);
};

#endif
