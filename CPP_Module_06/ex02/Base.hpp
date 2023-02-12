/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:13:51 by dham              #+#    #+#             */
/*   Updated: 2023/02/12 16:54:11 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
public:
	virtual ~Base(void);
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
