/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:12:04 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/10 13:12:32 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(const std::string & type) : _type(type)
{
}

AMateria::AMateria(const AMateria & src) : _type(src._type)
{
}

AMateria & AMateria::operator=(const AMateria & rhs)
{
	(void)rhs;
	return *this;
}

AMateria::~AMateria()
{
}

const std::string & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter & target)
{
	(void)target;
}
