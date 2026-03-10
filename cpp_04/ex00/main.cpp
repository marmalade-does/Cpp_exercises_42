/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:44:15 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 12:44:17 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "=== Correct Polymorphism ===" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;
	std::cout << "Type of j: " << j->getType() << std::endl;
	std::cout << "Type of i: " << i->getType() << std::endl;
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "=== Wrong Polymorphism ===" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;
	std::cout << std::endl;

	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << std::endl;
	delete wrongMeta;
	delete wrongCat;

	std::cout << std::endl;
	std::cout << "=== Stack objects ===" << std::endl;
	{
		Dog dog;
		Cat cat;
		Animal animal;

		std::cout << "dog type: " << dog.getType() << std::endl;
		std::cout << "cat type: " << cat.getType() << std::endl;
		std::cout << "animal type: " << animal.getType() << std::endl;

		dog.makeSound();
		cat.makeSound();
		animal.makeSound();
	}

	std::cout << std::endl;
	std::cout << "=== Copy constructor & assignment ===" << std::endl;
	{
		Dog dog1;
		dog1.makeSound();
		Dog dog2(dog1);
		std::cout << "dog2 type: " << dog2.getType() << std::endl;
		dog2.makeSound();

		Cat cat1;
		Cat cat2;
		cat2 = cat1;
		std::cout << "cat2 type: " << cat2.getType() << std::endl;
		cat2.makeSound();
	}

	std::cout << std::endl;
	std::cout << "=== WrongCat direct vs through pointer ===" << std::endl;
	{
		WrongCat wc;
		std::cout << "Direct WrongCat: ";
		wc.makeSound();
		const WrongAnimal *wcp = &wc;
		std::cout << "Through WrongAnimal*: ";
		wcp->makeSound();
	}

	return 0;
}
