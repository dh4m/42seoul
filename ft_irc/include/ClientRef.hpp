/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientRef.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:58:28 by dham              #+#    #+#             */
/*   Updated: 2023/06/30 22:14:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLIENTREF_HPP
# define CLIENTREF_HPP

#include "Client.hpp"
#include <pthread.h>

struct ClientRefData
{
	Client	*client;
	int		*cnt;
	pthread_mutex_t *mut_cnt;
};

class ClientRef
{
public:
	ClientRef(void);
	ClientRef(const ClientRef &copy);
	~ClientRef(void);

	ClientRef	&operator=(const ClientRef &copy);
	
	static ClientRef make_ClientRef(int fd, ClientInfo &info);
private:
	ClientRefData _data;
};

#endif
