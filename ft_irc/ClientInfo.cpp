/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientInfo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:21:08 by dham              #+#    #+#             */
/*   Updated: 2023/07/24 19:18:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClientInfo.hpp"
#include "Eventq.hpp"
#include "Operator.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <iostream>

ClientInfo::ClientInfo(void)
{
	pthread_rwlock_init(&_cl_list_lock, NULL);
	pthread_rwlock_init(&_ch_list_lock, NULL);
}

ClientInfo::~ClientInfo(void)
{
	pthread_rwlock_destroy(&_cl_list_lock);
	pthread_rwlock_destroy(&_ch_list_lock);
}

int ClientInfo::add_client(int fd)
{
	Eventq &ev_q = Eventq::getInstance();
	ClientRef cl = ClientRef::make_ClientRef(fd);

	std::cout << fd << " is new client" << std::endl;
	fcntl(fd, F_SETFL, O_NONBLOCK);
	pthread_rwlock_wrlock(&_cl_list_lock);
	_cl_list.insert(std::pair<int, ClientRef>(fd, cl));
	pthread_rwlock_unlock(&_cl_list_lock);
	ev_q.reg_event(fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	ev_q.reg_event(fd, EVFILT_WRITE, EV_ADD | EV_DISABLE, 0, 0, NULL);
}

int ClientInfo::reg_client(ClientRef cl, std::string nick)
{
	cl->set_user_state(AVAIL_USER);
	pthread_rwlock_wrlock(&_cl_list_lock);
	_cl_nick_list.insert(std::pair<std::string, ClientRef>(nick, cl));
	pthread_rwlock_unlock(&_cl_list_lock);
}

ClientRef ClientInfo::find_client(int fd)
{
	pthread_rwlock_rdlock(&_cl_list_lock);
	t_clientlist::const_iterator it = _cl_list.find(fd);
	if (it == _cl_list.end() || it->second->avail_client() == UNAVAIL_USER)
	{
		pthread_rwlock_unlock(&_cl_list_lock);
		return (ClientRef::NullClientRef());
	}
	pthread_rwlock_unlock(&_cl_list_lock);
	return (it->second);
}

ClientRef ClientInfo::find_client(std::string nick)
{
	pthread_rwlock_rdlock(&_cl_list_lock);
	t_nicklist::const_iterator it = _cl_nick_list.find(nick);
	if (it == _cl_nick_list.end() || it->second->avail_client() == UNAVAIL_USER)
	{
		pthread_rwlock_unlock(&_cl_list_lock);
		return (ClientRef::NullClientRef());
	}
	pthread_rwlock_unlock(&_cl_list_lock);
	return (it->second);
}

void ClientInfo::remove_client(int fd, const char *msg)
{
	Eventq &ev_q = Eventq::getInstance();

	ev_q.reg_event(fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
	ev_q.reg_event(fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
	pthread_rwlock_wrlock(&_cl_list_lock);
	std::map<int, ClientRef>::iterator it = _cl_list.find(fd);
	if (it == _cl_list.end())
	{
		pthread_rwlock_unlock(&_cl_list_lock);
		return ;
	}
	_cl_nick_list.erase(it->second->get_nick());
	_cl_list.erase(it);
	pthread_rwlock_unlock(&_cl_list_lock);
	it->second->leave_all_channel();
	(void) msg;
}

int ClientInfo::client_nick_change(int fd, std::string nick)
{
	pthread_rwlock_wrlock(&_cl_list_lock);
	std::map<int, ClientRef>::iterator it = _cl_list.find(fd);
	if (it == _cl_list.end())
	{
		pthread_rwlock_unlock(&_cl_list_lock);
		return ;
	}
	_cl_nick_list.erase(it->second->get_nick());
	it->second->nick_set(nick);
	_cl_nick_list.insert(std::pair<std::string, ClientRef>(nick, it->second));
	pthread_rwlock_unlock(&_cl_list_lock);
}

int ClientInfo::nick_dup_check(std::string nick)
{
	if (!find_client(nick))
		return (0);
	return (1);
}

int ClientInfo::join_chan(const std::string &name, const std::string key, ClientRef ref)
{
	// join 에러 처리 여기서 전부
	if (ref->include_chan(name))
	{
		return (-1);
	}
	pthread_rwlock_wrlock(&_ch_list_lock);
	t_chanlist::const_iterator it = _channel.find(name);
	if (it == _channel.end())
	{
		Channel *new_chan = new Channel(name);
		new_chan->add_user(ref);
		new_chan->add_operator(ref);
		ref->add_chan(name);
	}
	else
	{
		Channel *chan = it->second;
		if (chan->limit_memb() <= chan->curr_memb())
		{
			pthread_rwlock_unlock(&_ch_list_lock);
			return (ERR_CHANNELISFULL);
		}
		else if (chan->is_inviteonly() && !chan->is_invite_memb(ref->get_nick()))
		{
			pthread_rwlock_unlock(&_ch_list_lock);
			return (ERR_INVITEONLYCHAN);
		}
		else if (chan->is_needpasswd() && !chan->is_invite_memb(ref->get_nick()) \
				&& !chan->passwd_check(key))
		{
			pthread_rwlock_unlock(&_ch_list_lock);
			return (ERR_BADCHANNELKEY);
		}
		chan->add_user(ref);
		ref->add_chan(name);
	}
	pthread_rwlock_unlock(&_ch_list_lock);
	return (0);
}

int ClientInfo::leave_chan(const std::string &name, ClientRef ref)
{
	pthread_rwlock_wrlock(&_ch_list_lock);
	t_chanlist::const_iterator it = _channel.find(name);
	if (it == _channel.end())
	{
		pthread_rwlock_unlock(&_ch_list_lock);
		return (NULL);
	}
	Channel *chan = it->second;
	ref->del_chan(name);
	if (!chan->is_user(ref))
	{
		pthread_rwlock_unlock(&_ch_list_lock);
		return (0);
	}
	if (chan->is_operator(ref))
	{
		chan->remove_operator(ref);
		chan->remove_user(ref);
	}
	else
	{
		chan->remove_user(ref);
	}
	if (chan->curr_memb() == 0)
	{
		_channel.erase(name);
		delete chan;
	}
	pthread_rwlock_unlock(&_ch_list_lock);
	return (0);
}

Channel *ClientInfo::find_chan(const std::string &name)
{
	pthread_rwlock_rdlock(&_ch_list_lock);
	t_chanlist::const_iterator it = _channel.find(name);
	if (it == _channel.end())
	{
		pthread_rwlock_unlock(&_ch_list_lock);
		return (NULL);
	}
	pthread_rwlock_unlock(&_ch_list_lock);
	return (it->second);
}

int ClientInfo::destroy(void)
{
	return (0);
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
