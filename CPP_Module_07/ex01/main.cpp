/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:50:14 by dham              #+#    #+#             */
/*   Updated: 2023/02/20 15:30:30 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void print_int(const T i)
{
	std::cout << i << std::endl;
}

template<typename T>
void increament(T &i)
{
	i++;
}

template<>
void increament<std::string>(std::string &i)
{
	i += "_test";
}

int main(void)
{
	std::string arr[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

	iter(arr, 10, print_int<std::string>);
	iter(arr, 10, increament<std::string>);
	iter(arr, 10, print_int<std::string>);
}

/*
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
  Awesome tab2[5];

  iter( tab, 5, print<int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
*/