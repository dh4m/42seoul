/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:46:04 by dham              #+#    #+#             */
/*   Updated: 2023/01/06 03:46:41 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

char	*upper_str(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		i++;
	}
	return (str);
}

int main(int argc, char *argv[])
{
	int	i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (argv[i])
	{
		std::cout << upper_str(argv[i]);
		i++;
	}
	std::cout << '\n';
	return (0);
}