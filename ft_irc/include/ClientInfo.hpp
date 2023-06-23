/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientInfo.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:20:58 by dham              #+#    #+#             */
/*   Updated: 2023/06/23 15:54:46 by dham             ###   ########.fr       */
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

typedef std::map< std::string, Channel * > t_chanlist;
typedef std::map< int, Client * > t_clientlist;

class ClientInfo
{
public:
	ClientInfo(void);
	~ClientInfo(void);

	void add_client(int fd);
	Client *find_client(int fd) const;
	void remove_client(int fd, const char *msg);

	void add_chan(const std::string &name);
	Channel *find_chan(const std::string &name) const;
	void remove_chan(const std::string &name, const char *msg);

	int server_all_notice(std::string &str, Client *talker);
private:
	t_clientlist _cl_list;
	t_chanlist _channel;

	ClientInfo	&operator=(const ClientInfo &copy);
	ClientInfo(const ClientInfo &copy);
};

#endif
