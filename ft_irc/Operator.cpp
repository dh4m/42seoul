/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:23:26 by dham              #+#    #+#             */
/*   Updated: 2023/06/23 20:25:27 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operator.hpp"

Operator::Operator(ClientInfo &info)
: _info(info)
{

}

Operator::~Operator(void)
{

}

int Operator::operator()(const std::string &cmd_str, Client *sender)
{
	_cmd = cmd_str;
	_sender = sender;

	_parsing_msg();
	
}