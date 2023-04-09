/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientInfo.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:20:58 by dham              #+#    #+#             */
/*   Updated: 2023/04/09 16:21:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLIENTINFO_HPP
# define CLIENTINFO_HPP

class ClientInfo
{
public:
	ClientInfo(void);
	ClientInfo(const ClientInfo &copy);
	~ClientInfo(void);

	ClientInfo	&operator=(const ClientInfo &copy);
private:

};

#endif
