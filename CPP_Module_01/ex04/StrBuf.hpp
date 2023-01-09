/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrBuf.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:21:22 by dham              #+#    #+#             */
/*   Updated: 2023/01/10 03:14:31 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRBUF_HPP
# define STRBUF_HPP

#include <string>
#include <fstream>

class StrBuf
{
public:
	StrBuf(int size);

	void		read(std::ifstream& ifs);
	void		replace(std::string& s1, std::string& s2);
	std::string	write_str(void);
private:
	int			last;
	std::string	buf;
	int			split_idx;
	int			len;
	const int	buf_size;
};

#endif