/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:39:20 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 12:42:22 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

/**
 * @remark since WrongAnimal's `makeSound()` is not virutal, calling 
 * `makeSound()` will call WrongAnimal's sound
 * 
 * this is called "Hinding" instead of actually overriding
 */
class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &rhs);
	~WrongCat(void);

	void makeSound(void) const;
};

#endif