/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:33:47 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 18:34:12 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << "=== Create array of animals ===" << std::endl;
	const Animal *animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	std::cout << std::endl << "=== Delete array ===" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << std::endl << "=== Deep copy test ===" << std::endl;
	Dog basic;
	basic.getBrain()->setIdea(0, "I want food");
	{
		Dog tmp = basic;
		std::cout << "tmp brain idea: " << tmp.getBrain()->getIdea(0) << std::endl;
		std::cout << "basic brain idea: " << basic.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "basic brain idea after tmp destroyed: " << basic.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "=== Deep copy test (Cat) ===" << std::endl;
	{
		Cat cat1;
		cat1.getBrain()->setIdea(0, "Chase laser");
		cat1.getBrain()->setIdea(1, "Sleep on keyboard");
		Cat cat2(cat1);
		std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
		std::cout << "cat2 idea[1]: " << cat2.getBrain()->getIdea(1) << std::endl;
		cat2.getBrain()->setIdea(0, "Knock things off table");
		std::cout << "cat1 idea[0] (should be unchanged): " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "cat2 idea[0] (should be changed): " << cat2.getBrain()->getIdea(0) << std::endl;
	}

	std::cout << std::endl << "=== Assignment operator deep copy ===" << std::endl;
	{
		Dog dog1;
		dog1.getBrain()->setIdea(0, "Fetch stick");
		Dog dog2;
		dog2.getBrain()->setIdea(0, "Roll over");
		std::cout << "Before assignment - dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
		dog2 = dog1;
		std::cout << "After assignment - dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
		dog1.getBrain()->setIdea(0, "Dig hole");
		std::cout << "dog2 idea (should still be Fetch stick): " << dog2.getBrain()->getIdea(0) << std::endl;
	}

	return (0);
}
