/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:16:38 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 18:15:56 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

/**
 * @note is the same as 'Animal' b/ without the 'virtual' keywords
 */
class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	~WrongAnimal(void);

	void            makeSound(void) const;
	std::string     getType(void) const;

protected:
	std::string _type;
};

#endif /* WRONGANIMAL_HPP */
