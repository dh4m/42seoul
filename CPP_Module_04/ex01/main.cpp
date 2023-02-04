/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:32:02 by dham              #+#    #+#             */
/*   Updated: 2023/02/04 16:18:47 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	Animal *animals[10];

	for (int idx = 0; idx < 5; idx++)
		animals[idx] = new Cat();
	for (int idx = 5; idx < 10; idx++)
		animals[idx] = new Dog();
	for(int idx = 0; idx < 10; idx++)
		delete animals[idx];

	Dog original_dog;
	Dog copy_dog;
	Cat original_cat;
	Cat copy_cat;

	original_dog.setIdeas(0, "original");
	copy_dog = original_dog;
	original_dog.setIdeas(0, "test");
	std::cout << "original dog's brain value : " << original_dog.getIdeas(0) << '\n';
	std::cout << "copy dog's brain value : " << copy_dog.getIdeas(0) << '\n';
	
	original_cat.setIdeas(0, "original");
	copy_cat = original_cat;
	original_cat.setIdeas(0, "test");
	std::cout << "original cat's brain value : " << original_cat.getIdeas(0) << '\n';
	std::cout << "copy cat's brain value : " << copy_cat.getIdeas(0) << '\n';
	system("leaks a.out");
	return 0;
}
