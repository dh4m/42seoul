/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:39:26 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 20:02:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# define MATERIA_MAX 4

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &copy);
	~MateriaSource(void);

	MateriaSource	&operator=(const MateriaSource &copy);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
private:
	AMateria *_materia[MATERIA_MAX];
	int	_num_materia;
};

#endif
