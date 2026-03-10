/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:55:51 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 19:26:08 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

/**
 * we have a deep copy of the brain done
 */
Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*src._brain);
}

/**
 * !!!!!!FOOT GUN ALERT!!!!!!
 * @warning operator= is only called on an already-existing object:
 *   Cat cat_a;      → default constructor → Brain allocated
 *   cat_a = cat_b;  → operator= → must delete old Brain first, then deep copy
 * @note Cat cat_a = cat_b; calls the COPY CONSTRUCTOR, not operator= 
 * 		AKA IF YOU DECLARE ON THE SAME LINE AS THE '=' INITIALIZATION THEN IT WILL DO THE COPY CONSTRUCTOR
 */
Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow! Meow!" << std::endl;
}

Brain *Cat::getBrain(void) const
{
        return _brain;
}
