/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientInfo.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:20:58 by dham              #+#    #+#             */
/*   Updated: 2023/07/16 21:17:18 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLIENTINFO_HPP
# define CLIENTINFO_HPP

#include <map>
#include <string>
#include <vector>
#include <pthread.h>

#include "Client.hpp"
#include "Channel.hpp"
#include "ClientRef.hpp"

typedef std::map< std::string, Channel * > t_chanlist;
typedef std::map< int, ClientRef > t_clientlist;
typedef std::map< std::string, ClientRef > t_nicklist;

class ClientInfo
{
public:
	ClientInfo(void);
	~ClientInfo(void);

	void add_client(int fd);
	ClientRef find_client(int fd);
	void remove_client(int fd, const char *msg);
	int client_nick_change(int fd, std::string nick);

	void add_chan(const std::string &name);
	int join_chan(const std::string &name, ClientRef ref);
	Channel *find_chan(const std::string &name);
	void remove_chan(const std::string &name, const char *msg);
private:
	t_clientlist _cl_list;
	pthread_rwlock_t _cl_list_lock;

	t_nicklist _cl_nick_list;
	pthread_rwlock_t _cl_nick_list_lock;

	t_chanlist _channel;

	ClientInfo	&operator=(const ClientInfo &copy);
	ClientInfo(const ClientInfo &copy);
};

#endif
