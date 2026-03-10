/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:37:29 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 18:24:01 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &src);
	Cat &operator=(const Cat &rhs);

	virtual ~Cat(void);

	virtual void makeSound(void) const;
	Brain		*getBrain(void) const;
private:
	Brain *_brain;
};

#endif /* CAT_HPP */
