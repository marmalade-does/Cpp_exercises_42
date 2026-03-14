/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:46:18 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/12 12:30:54 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &src);
	Cure &operator=(const Cure &rhs);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif /* CURE_HPP */
