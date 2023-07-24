/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:33:52 by dham              #+#    #+#             */
/*   Updated: 2023/07/24 17:08:22 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <set>
#include <string>
#include <bitset>
#include <pthread.h>
#include <ScopeLock.hpp>

#include "Client.hpp"
#include "ClientRef.hpp"

enum e_chanmode
{
	INVITEONLY,
	TOPICRESTRICT
};

class Channel
{
public:
	Channel(std::string name);
	~Channel(void);

	int channel_output(std::string &content, int talker_fd);
	int add_user(ClientRef client);
	int add_operator(ClientRef client);
	int remove_user(ClientRef client);
	int remove_operator(ClientRef client);

	int is_user(ClientRef client);
	int is_operator(ClientRef client);

	int is_inviteonly(void);
	int is_needpasswd(void);

	int add_invite(std::string user);
	int is_invite_memb(std::string user);

	size_t limit_memb(void);
	size_t curr_memb(void);

	int set_topic(std::string topic);
	int set_limit(size_t limit);
	int set_passwd(std::string passwd);
	int passwd_check(std::string passwd);
	int mode_set(int mode);
	int mode_unset(int mode);

	std::string get_topic(void);
	std::string get_namelist(void);
private:
	const std::string _name;
	std::string _passwd;
	std::string _topic;

	std::set<ClientRef> _member;
	pthread_mutex_t _member_m;

	std::set<ClientRef> _operator;
	std::bitset<2> _mode;

	std::set<std::string> _invite_list;

	size_t _user_limit;

	Channel	&operator=(const Channel &copy);
	Channel(const Channel &copy);
};

#endif
