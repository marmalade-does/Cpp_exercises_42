/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:42:35 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 19:22:42 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

/**
 * @remark Animal isn't used for that much in this code
 * 		just as progenitor for the other animals
 * 
 * 		the $(animals) en si usan composition and not inheritence.
 */
class Animal
{
public:
	Animal(void);
	Animal(const Animal &src);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal(void);

	virtual void    makeSound(void) const = 0;
	std::string             getType(void) const;

protected:
	std::string _type;
};

#endif /* ANIMAL_HPP */
