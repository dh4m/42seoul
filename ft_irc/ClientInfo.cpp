/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientInfo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:21:08 by dham              #+#    #+#             */
/*   Updated: 2023/06/20 20:43:30 by dham             ###   ########.fr       */
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
	Client *cl = new Client(fd);

	_cl_list.insert(std::pair<int, Client *>(fd, cl));
}

Client *ClientInfo::find_client(int fd)
{
	std::map<int, Client *>::iterator it = _cl_list.find(fd);
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
