/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:05:53 by dham              #+#    #+#             */
/*   Updated: 2023/02/19 20:24:40 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <type_traits>
#include "ft_utility.hpp"

template<int N> struct int2type
{
    static const int value = N;
};

template<typename T> struct is_pointer
{
    static const int value = 0;
};

template<typename T> struct is_pointer<T*>
{
    static const int value = 1;
};

template<typename T> struct is_false
{
    static const int value = 0;
};

template<typename T> void printv_imp(T v, int2type<1>)
{
    std::cout << v << " : " << *v << std::endl;
}

template<typename T> void printv_imp(T v, int2type<0>)
{
    std::cout << v <<std::endl;
}

template<class T, typename std::enable_if<is_false<T>::value, void>::type = 0>
void printv(T v)
{
    std::cout << v << "asdf" << '\n';
}

template<class T, typename std::enable_if<is_pointer<T>::value, T>::type = 0>
void printv(T v)
{
    std::cout << v << '\n';
}

int main()
{
    int n = 1;
    int *ptr_n = 0;

    //printv(n);
    printv(&n);
}