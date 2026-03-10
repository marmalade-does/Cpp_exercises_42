/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:42:35 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 12:16:04 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

/**
 * @remark what is "virtual" used for?
 * 	'virtual' destructor → makes sure to destoy a derived class before destroying itself
 * 	'virtual' method → enables 'runtime polymorphism':
 * 		when 'makeSound()' called though base's pointer, it uses the derived class' sound
 * 
 * @note: once you mark a function as "virtual" (weather method or destructor)
 * 		then all their kids' funcitons will be virtual
 * @note: if you know that you will never use the polymorphism
 * 		(eg never `Animal *a = new Dog()` and ALWAYS Animal *a = new Animal())
 * 		then it's fine to not have virtual constructor / destructor
 */
class Animal
{
public:
	Animal(void);
	Animal(const Animal &src);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal(void);

	virtual void    makeSound(void) const;
	std::string             getType(void) const;

protected:
	std::string _type;
};

#endif /* ANIMAL_HPP */
