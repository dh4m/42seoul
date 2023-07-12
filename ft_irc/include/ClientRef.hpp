/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientRef.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:58:28 by dham              #+#    #+#             */
/*   Updated: 2023/07/12 20:29:55 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLIENTREF_HPP
# define CLIENTREF_HPP

#include "Client.hpp"
#include <pthread.h>

struct ClientRefSet
{
	ClientRefSet(int fd);
	Client	_client;
	pthread_mutex_t _mut_cnt;
	int		_cnt;
};

class ClientRef
{
public:
	ClientRef(void);
	ClientRef(const ClientRef &copy);
	~ClientRef(void);

	ClientRef	&operator=(const ClientRef &copy);
	Client		&operator*(void) const;
	Client		*operator->(void) const;
	bool		operator==(const ClientRef &cmp) const;
	bool		operator!=(const ClientRef &cmp) const;
	bool		operator!(void) const;
	
	static ClientRef make_ClientRef(int fd);
	static ClientRef NullClientRef(void);
private:
	void _delete_object(void);

	ClientRefSet *_alloc_data;
};

#endif
