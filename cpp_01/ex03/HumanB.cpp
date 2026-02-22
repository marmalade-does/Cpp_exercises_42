/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:38:59 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 15:40:46 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void) const
{
	if (_weapon)
		std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
