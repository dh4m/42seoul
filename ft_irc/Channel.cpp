/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:34:09 by dham              #+#    #+#             */
/*   Updated: 2023/07/17 13:05:47 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel(std::string name)
: _name(name), _user_limit(-1), _mode(0)
{
	;
}

Channel::~Channel(void)
{
	;
}

int Channel::add_user(ClientRef client)
{
	ScopeLock lock(&_member_m);
}

int Channel::add_operator(ClientRef client)
{

}

int Channel::remove_user(ClientRef client)
{
	ScopeLock lock(&_member_m);
}

int Channel::remove_operator(ClientRef client)
{

}

int Channel::is_user(ClientRef client)
{
	ScopeLock lock(&_member_m);
	return (_member.find(client) != _member.end());
}

int Channel::is_operator(ClientRef client)
{

}

int Channel::add_invite(ClientRef client)
{

}

size_t Channel::limit_memb(void)
{
	return (_user_limit);
}

size_t Channel::curr_memb(void)
{
	ScopeLock lock(&_member_m);
	return (_member.size());
}

int Channel::set_topic(std::string topic)
{

}

int Channel::set_limit(std::string topic)
{

}

int Channel::set_passwd(std::string topic)
{

}

int Channel::mode_set(int mode)
{
	if (mode != 0 && mode != 1)
		return (0);
	_mode.set(mode, true);
}

int Channel::mode_unset(int mode)
{
	if (mode != 0 && mode != 1)
		return (0);
	_mode.set(mode, false);
}

int Channel::channel_output(std::string &content, int talker_fd)
{
	ScopeLock lock(&_member_m);
	for (std::set<ClientRef>::iterator it = _member.begin();
		it != _member.end();
		++it)
	{
		if ((*it)->get_fd() != talker_fd)
		{
			(*it)->add_output(content);
		}
	}
	return (1);
}