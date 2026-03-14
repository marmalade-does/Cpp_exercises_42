/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:57:21 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/12 12:31:12 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &src);
	Ice &operator=(const Ice &rhs);
	~Ice();

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif /* ICE_HPP */
