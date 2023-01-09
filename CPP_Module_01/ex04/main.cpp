/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:35:12 by dham              #+#    #+#             */
/*   Updated: 2023/01/10 03:58:52 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StrBuf.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Invalid Argument" << '\n';
		return (-1);
	}
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	StrBuf buffer(s1.length());
	std::ifstream ifs(argv[1]);
	if (!ifs.is_open())
	{
		std::cerr << "Failed to input file open" << '\n';
		return (-1);
	}
	std::ofstream ofs(std::string(argv[1]) + ".replace");
	if (!ofs.is_open())
	{
		std::cerr << "Failed to output file open" << '\n';
		return (-1);
	}
	while (ifs)
	{
		buffer.read(ifs);
		buffer.replace(s1, s2);
		ofs << buffer.write_str();
	}
	return (0);
}