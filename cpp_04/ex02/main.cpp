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

	return (0);
}
