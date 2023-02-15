/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:05:53 by dham              #+#    #+#             */
/*   Updated: 2023/02/15 21:21:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

template <typename T>
typename T::value_type foo(const T& t) {
  return -T(t);
}


//void foo(unsigned int i) { std::cout << "unsigned " << i << "\n"; }



int main(void)
{
	foo(42);
}