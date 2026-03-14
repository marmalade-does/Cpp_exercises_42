/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:46:19 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/12 12:31:02 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

/**
 * @remark Ice is inhereted from AMateria (and abstract class, therfore )
 */
Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &src) : AMateria(src)
{
}

Ice &Ice::operator=(const Ice &rhs)
{
	AMateria::operator=(rhs);
	return *this;
}

Ice::~Ice()
{
}

//----------

/**
 * this is abstract/virtual in 
 */
AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
