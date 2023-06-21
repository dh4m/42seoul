/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientInfo.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:20:58 by dham              #+#    #+#             */
/*   Updated: 2023/06/20 17:55:07 by dham             ###   ########.fr       */
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

class ClientInfo
{
public:
	ClientInfo(void);
	~ClientInfo(void);

	void add_client(int fd);
	Client *find_client(int fd);
	void remove_client(int fd, const char *msg);
private:
	std::map<int, Client *> _cl_list;

	ClientInfo	&operator=(const ClientInfo &copy);
	ClientInfo(const ClientInfo &copy);
};

#endif
