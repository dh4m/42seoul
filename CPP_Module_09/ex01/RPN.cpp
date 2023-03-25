/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:49:05 by dham              #+#    #+#             */
/*   Updated: 2023/03/25 19:31:20 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

RPN::RPN(void)
{}

RPN::~RPN(void)
{}

void	RPN::input_char(char c)
{
	int a;
	int b;

	if (c >= '0' && c <= '9')
		input_stack.push(c - '0');
	else if (c == '+' || c == '-' || c == '*' || c == '/')
	{
		if (cnt() < 2)
		{
			std::cout << "Error" << std::endl;
			exit(EXIT_FAILURE);
		}
		a = input_stack.top();
		input_stack.pop();
		b = input_stack.top();
		input_stack.pop();
		switch (c)
		{
		case '+':
			input_stack.push(b + a);
			break;
		case '-':
			input_stack.push(b - a);
			break;
		case '*':
			input_stack.push(b * a);
			break;
		case '/':
			if (a == 0)
			{
				std::cout << "Error: zero division" << std::endl;
				exit(EXIT_FAILURE);
			}
			input_stack.push(b / a);
			break;
		}
	}
	else
	{
		std::cout << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}
}

int		RPN::check_num(void)
{
	return (input_stack.top());
}

int		RPN::cnt(void)
{
	return (input_stack.size());
}
