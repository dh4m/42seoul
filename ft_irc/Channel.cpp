/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:34:09 by dham              #+#    #+#             */
/*   Updated: 2023/07/12 20:23:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel(std::string name)
: _name(name)
{
	;
}

Channel::~Channel(void)
{
	;
}

int Channel::channel_output(std::string &content, int talker_fd)
{
	for (std::set<ClientRef>::iterator it = _member.begin();
		it != _member.end();
		++it)
	{
		if ((*it)->get_fd() != talker_fd)
		{
			(*it)->add_output(content);
		}
	}
	return (1);
}