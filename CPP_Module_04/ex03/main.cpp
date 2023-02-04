/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:11:41 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 20:56:43 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp;
	tmp = new Ice();
	src->learnMateria(tmp);
	delete tmp;
	tmp = new Cure();
	src->learnMateria(tmp);
	delete tmp;

	ICharacter* me = new Character("me");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
}