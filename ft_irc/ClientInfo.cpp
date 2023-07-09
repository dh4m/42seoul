/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientInfo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:21:08 by dham              #+#    #+#             */
/*   Updated: 2023/07/09 16:57:40 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClientInfo.hpp"
#include <unistd.h>

ClientInfo::ClientInfo(void)
{
	pthread_rwlock_init(&_cl_list_lock, NULL);
}

ClientInfo::~ClientInfo(void)
{
	pthread_rwlock_destroy(&_cl_list_lock);
}

void ClientInfo::add_client(int fd)
{
	ClientRef cl = ClientRef::make_ClientRef(fd, *this);

	pthread_rwlock_wrlock(&_cl_list_lock);
	_cl_list.insert(std::pair<int, ClientRef>(fd, cl));
	pthread_rwlock_unlock(&_cl_list_lock);
}

ClientRef ClientInfo::find_client(int fd)
{
	pthread_rwlock_rdlock(&_cl_list_lock);
	std::map<int, ClientRef>::const_iterator it = _cl_list.find(fd);
	if (it == _cl_list.end())
	{
		pthread_rwlock_unlock(&_cl_list_lock);
		return (ClientRef::NullClientRef());
	}
	pthread_rwlock_unlock(&_cl_list_lock);
	return (it->second);
}

void ClientInfo::remove_client(int fd, const char *msg)
{
	pthread_rwlock_rdlock(&_cl_list_lock);
	std::map<int, ClientRef>::iterator it = _cl_list.find(fd);
	if (it == _cl_list.end())
	{
		pthread_rwlock_unlock(&_cl_list_lock);
		return ;
	}
	pthread_rwlock_unlock(&_cl_list_lock);
	
	// cl_list mutex 처리
	pthread_rwlock_wrlock(&_cl_list_lock);
	_cl_list.erase(it);
	pthread_rwlock_unlock(&_cl_list_lock);
	(void) msg;
}

void ClientInfo::add_chan(const std::string &name)
{
	(void) name;
	;
}

Channel *ClientInfo::find_chan(const std::string &name)
{
	(void) name;
	return (NULL);
}

void ClientInfo::remove_chan(const std::string &name, const char *msg)
{
	(void) name;
	(void) msg;
}

/*
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
*/
