/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:02:26 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 13:09:08 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Regular zombie")
{
}

Zombie::Zombie(std::string name_str) : _name(name_str)
{
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is slain" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name_str)
{
	this->_name = name_str;
}
