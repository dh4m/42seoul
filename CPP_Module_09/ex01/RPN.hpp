/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:48:16 by dham              #+#    #+#             */
/*   Updated: 2023/03/25 19:24:57 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>

class RPN
{
public:
	RPN(void);
	~RPN(void);

	void	input_char(char c);
	int		check_num(void);
	int		cnt(void);
private:
	std::stack<int> input_stack;

	RPN(const RPN &copy);
	RPN	&operator=(const RPN &copy);
};

#endif
