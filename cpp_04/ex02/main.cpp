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

	std::cout << std::endl << "=== Deep copy test (Dog) ===" << std::endl;
	Dog basic;
	basic.getBrain()->setIdea(0, "I want food");
	{
		Dog copy = basic;
		copy.getBrain()->setIdea(0, "I want a walk");
		std::cout << "basic idea[0]: " << basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "copy  idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "basic idea[0] after copy destroyed: " << basic.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "=== Deep copy test (Cat) ===" << std::endl;
	Cat cat_basic;
	cat_basic.getBrain()->setIdea(0, "I want food");
	{
		Cat cat_copy = cat_basic;
		cat_copy.getBrain()->setIdea(0, "I want a walk");
		std::cout << "cat_basic idea[0]: " << cat_basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "cat_copy idea[0]: " << cat_copy.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "cat_basic idea[0] after cat_copy destroyed: " << cat_basic.getBrain()->getIdea(0) << std::endl;

	return (0);
}
