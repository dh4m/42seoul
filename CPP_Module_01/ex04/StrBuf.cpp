/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrBuf.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:40:38 by dham              #+#    #+#             */
/*   Updated: 2023/01/10 04:00:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StrBuf.hpp"
#include <iostream>

StrBuf::StrBuf(int size)
: buf_size(size * 2)
{
	last = 0;
	split_idx = 0;
	len = 0;
}

void	StrBuf::read(std::ifstream& ifs)
{
	int read_size = buf_size - len;
	char *read_str = new char[read_size + 1];

	ifs.read(read_str, read_size);
	read_str[ifs.gcount()] = 0;
	buf += read_str;
	len = buf.length();
	split_idx = buf_size / 2;
	if (!ifs)
	{
		last = 1;
		if (!ifs.eof())
			std::cerr << "Error in read" << '\n';
	}
	delete[] read_str;
}

void	StrBuf::replace(std::string& s1, std::string& s2)
{
	size_t	pos;
	
	pos = buf.find(s1);
	while (pos != std::string::npos)
	{
		buf.erase(pos, s1.length());
		buf.insert(pos, s2);
		split_idx = pos + s2.length();
		pos = buf.find(s1, split_idx);
	}
}

std::string	StrBuf::write_str(void)
{
	std::string ret_str;

	if (last)
		return (buf);
	ret_str = buf.substr(0, split_idx);
	buf = buf.substr(split_idx);
	len = buf.length();
	return (ret_str);
}
