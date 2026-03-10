/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:15:49 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 18:34:24 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

/**
 * @note Dog inherits from Animal - it overrides `makeSound()`
 * @remark
 *      The 'virtual' keyword here is optional (∵ it's inhereted from 'Animal')
 *      BUT it's good practice to make your intent clear
 */
class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &src);
	Dog &operator=(const Dog &rhs);
	
	virtual ~Dog(void);

	virtual void makeSound(void) const;
	Brain		*getBrain(void) const;
private:
	Brain *_brain;

};

#endif