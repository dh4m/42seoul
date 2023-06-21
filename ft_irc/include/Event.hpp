/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:42:04 by dham              #+#    #+#             */
/*   Updated: 2023/06/21 21:53:13 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EVENT_HPP
# define EVENT_HPP

#include "Client.hpp"

class Event
{

};

class ReadEvent : public Event
{
	
};

class WriteEvent : public Event
{

};

class ListenEvent : public Event
{

};

class ErrorEvent : public Event
{

};

#endif
