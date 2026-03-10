/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:37:29 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 12:38:50 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

/**
 * @note below is the comment for Dog, it's the same here for cat
 */
/**
 * @note Dog inherits from Animal - it overrides `makeSound()`
 * @remark
 *      The 'virtual' keyword here is optional (∵ it's inhereted from 'Animal')
 *      BUT it's good practice to make your intent clear
 */
class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &src);
	Cat &operator=(const Cat &rhs);

	virtual ~Cat(void);

	virtual void makeSound(void) const;
};

#endif /* CAT_HPP */
