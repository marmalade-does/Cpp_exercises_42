/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:44:00 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 13:49:52 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
}

Weapon::~Weapon(void)
{
}

const std::string	&Weapon::getType(void) const
{
	return (_type);	
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}


