/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientRef.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:59:20 by dham              #+#    #+#             */
/*   Updated: 2023/06/30 22:14:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClientRef.hpp"
#include <cstdlib>

ClientRef::ClientRef(void)
: _data({NULL, NULL})
{}

ClientRef::~ClientRef(void)
{
	if (_data.client)
	{
		_data.cnt--;
		if (_data.cnt == 0)
		{
			delete _data.client;
			delete _data.cnt;
		}
	}
}

ClientRef::ClientRef(const ClientRef &copy)
{
	
}

ClientRef	&ClientRef::operator=(const ClientRef &copy)
{
	if (_data.client == copy._data.client)
		return (*this);
	if (_data.client == NULL)
	{
		_data = copy._data;
		*(_data.cnt)++;
	}
	else
	{
		*(_data.cnt)--;
		if (*(_data.cnt) == 0)
		{
			delete _data.client;
			delete _data.cnt;
		}
		_data = copy._data;
		*(_data.cnt)++;////////
	}
	return (*this);
}

ClientRef ClientRef::make_ClientRef(int fd, ClientInfo &info)
{
	ClientRef ret_ref;

	ret_ref._data.client = new Client(fd, info);
	ret_ref._data.cnt = new int(1);
	return (ret_ref);
}