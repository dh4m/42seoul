/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:17:19 by dham              #+#    #+#             */
/*   Updated: 2023/02/12 16:56:48 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base(void)
{}

Base * generate(void)
{
	srand(time(NULL));
	int rand_num = rand() % 3;
	switch (rand_num)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		break;
	}
	return (0);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	if (dynamic_cast<B*>(p))
		std::cout << "B";
	if (dynamic_cast<C*>(p))
		std::cout << "C";
	std::cout << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}
