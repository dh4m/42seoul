/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:11:41 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 21:21:55 by dham             ###   ########.fr       */
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

	Character test("test");

	tmp = src->createMateria("ice");
	test.equip(tmp);
	delete tmp;

	Character clone = test;
	tmp = src->createMateria("cure");
	clone.equip(tmp);
	delete tmp;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	clone.use(0, *me);
	me->use(1, *bob);
	test.use(1, *me);
	clone.use(1, *me);

	delete bob;
	delete me;
	delete src;
	return 0;
}
