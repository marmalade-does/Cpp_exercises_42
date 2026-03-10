/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:50:26 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 19:29:05 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @note: redefinet he _type ∵ "Dog’s type will be initialized to "Dog""
 */
Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/**
 * !!!!!!FOOT GUN ALERT!!!!!!
 * @warning operator= is only called on an already-existing object:
 *   Dog dog_a;      → default constructor → Brain allodoged
 *   dog_a = dog_b;  → operator= → must delete old Brain first, then deep copy
 * @note Dog dog_a = dog_b; calls the COPY CONSTRUCTOR, not operator= 
 * 		AKA IF YOU DECLARE ON THE SAME LINE AS THE '=' INITIALIZATION THEN IT WILL DO THE COPY CONSTRUCTOR
 */
Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

// ------------

void Dog::makeSound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return _brain;
}
