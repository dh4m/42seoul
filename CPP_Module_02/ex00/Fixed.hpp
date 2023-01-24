/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:14:04 by dham              #+#    #+#             */
/*   Updated: 2023/01/24 23:38:49 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &f);
	~Fixed(void);
	Fixed &operator= (const Fixed &f);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					_number;
	static const int	_fractional_bits = 8;
};