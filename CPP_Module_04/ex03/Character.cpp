/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:16 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 21:29:38 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{}

Character::Character(std::string name)
:_name(name)
{
	for (int i = 0; i < SLOT_MAX; i++)
	{
		_slot[i] = NULL;
		_valid_slot[i] = false;
	}
	_num_materia = 0;
}

Character::Character(const Character &copy)
:_name(copy._name)
{
	for (int i = 0; i < SLOT_MAX; i++)
	{
		if (copy._valid_slot[i])
		{
			_slot[i] = copy._slot[i]->clone();
			_valid_slot[i] = true;
		}
		else
		{
			_slot[i] = NULL;
			_valid_slot[i] = false;
		}
	}
	_num_materia = copy._num_materia;
}

Character::~Character(void)
{
	for(int i = 0; i < SLOT_MAX; i++)
	{
		if(_slot[i])
			delete _slot[i];
	}
}

Character	&Character::operator=(const Character &copy)
{
	_name = copy._name;
	for (int i = 0; i < SLOT_MAX; i++)
	{
		if(_slot[i])
			delete _slot[i];
		if (copy._valid_slot[i])
		{
			_slot[i] = copy._slot[i]->clone();
			_valid_slot[i] = true;
		}
		else
		{
			_slot[i] = NULL;
			_valid_slot[i] = false;
		}
	}
	_num_materia = copy._num_materia;
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	int input;

	if (_num_materia >= SLOT_MAX || !m)
		return ;
	input = 0;
	while (_valid_slot[input])
		input++;
	if (_slot[input])
		delete _slot[input];
	_slot[input] = m->clone();
	_valid_slot[input] = true;
	_num_materia++;
}

void Character::unequip(int idx)
{
	if (_num_materia == 0 || idx < 0 || idx > SLOT_MAX || !_valid_slot[idx])
		return ;
	_valid_slot[idx] = false;
	_num_materia--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > SLOT_MAX || !_valid_slot[idx])
		return ;
	_slot[idx]->use(target);
}
