/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:24:33 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 20:37:33 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# define SLOT_MAX 4

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
public:
	Character(std::string name);
	Character(const Character &copy);
	~Character(void);

	Character	&operator=(const Character &copy);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	std::string _name;
	AMateria *_slot[SLOT_MAX];
	bool _valid_slot[SLOT_MAX];
	int _num_materia;
};

#endif
