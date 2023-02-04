/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:39:31 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 20:43:20 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < MATERIA_MAX; i++)
	{
		_materia[i] = NULL;
	}
	_num_materia = 0;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < MATERIA_MAX; i++)
	{
		if (copy._materia[i])
			_materia[i] = copy._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
	_num_materia = copy._num_materia;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < _num_materia; i++)
	{
		delete _materia[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	for (int i = 0; i < MATERIA_MAX; i++)
	{
		if (_materia[i])
			delete _materia[i];
		if (copy._materia[i])
			_materia[i] = copy._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
	_num_materia = copy._num_materia;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (_num_materia >= MATERIA_MAX || !m)
		return ;
	_materia[_num_materia] = m->clone();
	_num_materia++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MATERIA_MAX; i++)
	{
		if (_materia[i]->getType() == type)
			return (_materia[i]->clone());
	}
	return (NULL);
}

