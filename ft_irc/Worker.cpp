/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:58:24 by dham              #+#    #+#             */
/*   Updated: 2023/06/19 15:27:47 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"

Worker::Worker(void)
{

}

Worker::~Worker(void)
{

}

int Worker::init(void)
{

}

void Worker::add_client(int fd)
{

}

void Worker::remove_client(int fd, const char *msg)
{

}

void Worker::reg_msg(int fd, int cmd)
{

}

void Worker::reg_err_msg(int fd)
{

}

int Worker::_read_client(Client *op_cl)
{
	//op_cl->client_read();
	//if (op_cl)
}

int Worker::_write_client(Client *op_cl)
{

}

int Worker::_parsing_msg(std::string str)
{

}

