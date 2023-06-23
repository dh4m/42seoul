/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientInfo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:21:08 by dham              #+#    #+#             */
/*   Updated: 2023/06/23 15:57:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClientInfo.hpp"
#include <unistd.h>

ClientInfo::ClientInfo(void)
{

}

ClientInfo::~ClientInfo(void)
{

}

void ClientInfo::add_client(int fd)
{
	Client *cl = new Client(fd, *this);

	_cl_list.insert(std::pair<int, Client *>(fd, cl));
}

Client *ClientInfo::find_client(int fd) const
{
	std::map<int, Client *>::const_iterator it = _cl_list.find(fd);
	if (it == _cl_list.end())
		return (NULL);
	return (it->second);
}

void ClientInfo::remove_client(int fd, const char *msg)
{
	std::map<int, Client *>::iterator it = _cl_list.find(fd);
	if (it == _cl_list.end())
		return ;
	// delete 전 과정
	close(it->first);
	delete (it->second);
	_cl_list.erase(it);
	(void) msg;
}

void ClientInfo::add_chan(const std::string &name)
{
	(void) name;
	;
}

Channel *ClientInfo::find_chan(const std::string &name) const
{
	(void) name;
	return (NULL);
}

void ClientInfo::remove_chan(const std::string &name, const char *msg)
{
	(void) name;
	(void) msg;
}

int ClientInfo::server_all_notice(std::string &str, Client *talker)
{
	for (t_clientlist::iterator it = _cl_list.begin();
		it != _cl_list.end();
		++it)
	{
		if (it->second != talker)
		{
			(it->second)->add_output(str);
		}
	}
	return (1);
}
