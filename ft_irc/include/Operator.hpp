/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:23:40 by dham              #+#    #+#             */
/*   Updated: 2023/06/25 22:19:44 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef OPERATOR_HPP
# define OPERATOR_HPP

#include "ClientInfo.hpp"

enum e_reply
{
	
};

class Operator
{
public:
	Operator(ClientInfo &info);
	~Operator(void);

	int operator()(const std::string &cmd_str, Client *sender);
private:
	int _parsing_msg(void);



	ClientInfo &_info;
	std::string _cmd;
	Client *_sender;

	Operator(const Operator &copy);
	Operator	&operator=(const Operator &copy);
};

#endif
