/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientInfo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:21:08 by dham              #+#    #+#             */
/*   Updated: 2023/07/01 21:55:04 by dham             ###   ########.fr       */
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
	ClientRef cl = ClientRef::make_ClientRef(fd, *this);

	_cl_list.insert(std::pair<int, ClientRef>(fd, cl));
}

ClientRef ClientInfo::find_client(int fd) const
{
	std::map<int, ClientRef>::const_iterator it = _cl_list.find(fd);
	if (it == _cl_list.end())
		return (ClientRef::NullClientRef());
	return (it->second);
}

void ClientInfo::remove_client(int fd, const char *msg)
{
	std::map<int, ClientRef>::iterator it = _cl_list.find(fd);
	if (it == _cl_list.end())
		return ;
	
	// cl_list mutex 처리
	// delete 전 과정 채널에서도지워야됨
	//close(it->first);
	//delete (it->second);
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

int ClientInfo::server_all_notice(std::string &str, int talker_fd)
{
	for (t_clientlist::iterator it = _cl_list.begin();
		it != _cl_list.end();
		++it)
	{
		if ((it->second)->get_fd() != talker_fd)
		{
			(it->second)->add_output(str);
		}
	}
	return (1);
}
