/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:25:37 by dham              #+#    #+#             */
/*   Updated: 2023/02/03 20:35:40 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define NUM_IDEAS 100

class Brain
{
public:
	Brain(void);
	Brain(const Brain &copy);
	~Brain(void);

	Brain	&operator=(const Brain &copy);
private:
	std::string	ideas[NUM_IDEAS];
};

#endif
