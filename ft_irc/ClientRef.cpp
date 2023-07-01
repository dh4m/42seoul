/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientRef.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:59:20 by dham              #+#    #+#             */
/*   Updated: 2023/07/01 21:16:57 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClientRef.hpp"
#include <cstdlib>

ClientRef::ClientRef(void)
: _alloc_data(NULL)
{}

ClientRef::~ClientRef(void)
{
	if (_alloc_data)
	{
		pthread_mutex_lock(&_alloc_data->_mut_cnt);
		_alloc_data->_cnt--;
		if (_alloc_data->_cnt == 0)
		{
			pthread_mutex_unlock(&_alloc_data->_mut_cnt);
			_delete_object();
		}
		else
			pthread_mutex_unlock(&_alloc_data->_mut_cnt);
	}
}

ClientRef::ClientRef(const ClientRef &copy)
: _alloc_data(copy._alloc_data)
{
	if (!_alloc_data)
		return ;
	pthread_mutex_lock(&_alloc_data->_mut_cnt);
	_alloc_data->_cnt++;
	pthread_mutex_unlock(&_alloc_data->_mut_cnt);
}

ClientRef	&ClientRef::operator=(const ClientRef &copy)
{
	if (_alloc_data == copy._alloc_data)
		return (*this);
	if (_alloc_data)
	{
		pthread_mutex_lock(&_alloc_data->_mut_cnt);
		_alloc_data->_cnt--;
		if (_alloc_data->_cnt == 0)
		{
			pthread_mutex_unlock(&_alloc_data->_mut_cnt);
			_delete_object();
		}
		else
			pthread_mutex_unlock(&_alloc_data->_mut_cnt);
	}
	_alloc_data = copy._alloc_data;
	if (_alloc_data)
	{
		pthread_mutex_lock(&_alloc_data->_mut_cnt);
		_alloc_data->_cnt++;
		pthread_mutex_unlock(&_alloc_data->_mut_cnt);
	}
	return (*this);
}

Client &ClientRef::operator*(void) const
{
	return (_alloc_data->_client);
}

Client *ClientRef::operator->(void) const
{
	return (&_alloc_data->_client);
}

bool ClientRef::operator==(const ClientRef &cmp) const
{
	return (_alloc_data == cmp._alloc_data);
}

bool ClientRef::operator!=(const ClientRef &cmp) const
{
	return (_alloc_data != cmp._alloc_data);
}

bool ClientRef::operator!(void) const
{
	return (_alloc_data == NULL);
}

ClientRef ClientRef::make_ClientRef(int fd, ClientInfo &info)
{
	ClientRef ret_ref;

	ret_ref._alloc_data = new ClientRefSet(fd, info);
	pthread_mutex_init(&ret_ref._alloc_data->_mut_cnt, NULL);
	return (ret_ref);
}

ClientRef ClientRef::NullClientRef(void)
{
	return (ClientRef());
}

void ClientRef::_delete_object(void)
{
	pthread_mutex_destroy(&_alloc_data->_mut_cnt);
	delete _alloc_data;
	_alloc_data = NULL;
}

ClientRefSet::ClientRefSet(int fd, ClientInfo &info)
: _client(fd, info), _cnt(1)
{}