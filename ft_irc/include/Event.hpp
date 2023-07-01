/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:42:04 by dham              #+#    #+#             */
/*   Updated: 2023/07/01 21:17:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EVENT_HPP
# define EVENT_HPP

#include "Client.hpp"
#include "ClientRef.hpp"

class Event
{
private:
	virtual int Handler(void) = 0;
	ClientRef getClient(void);
private:
	ClientRef cl;
}; 

class ReadEvent : public Event
{
	int Handler();
};

class WriteEvent : public Event
{
	int Handler();
};

class ListenEvent : public Event
{
	int Handler();
};

class ErrorEvent : public Event
{
	int Handler();
};

#endif
