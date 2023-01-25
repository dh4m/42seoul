/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:14:04 by dham              #+#    #+#             */
/*   Updated: 2023/01/25 20:03:57 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &f);
	~Fixed(void);
	Fixed &operator= (const Fixed &f);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
private:
	int					_number;
	static const int	_total_bits = sizeof(int) * 8;
	static const int	_fractional_bits = 8;
	static const int	_integer_bits = _total_bits - _fractional_bits - 1;
};


std::ostream& operator<<(std::ostream& out, const Fixed &f);

#endif