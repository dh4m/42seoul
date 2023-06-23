/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:34:09 by dham              #+#    #+#             */
/*   Updated: 2023/06/23 15:57:00 by dham             ###   ########.fr       */
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

int Channel::channel_output(std::string &content, Client *talker)
{
	for (std::set<Client*>::iterator it = _member.begin();
		it != _member.end();
		++it)
	{
		if ((*it) != talker)
		{
			(*it)->add_output(content);
		}
	}
}