/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:24:13 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 16:06:41 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
public:
	Cat(void);
	Cat(const Cat &copy);
	~Cat(void);

	Cat	&operator=(const Cat &copy);
	
	void	makeSound(void) const;
	const std::string &getIdeas(int idx) const;
	void setIdeas(int idx, const std::string &str);
private:
	Brain	*brain;
};

#endif
