/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:59:52 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/12 12:16:38 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default"), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
}

Character::Character(const std::string &name) : _name(name), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
}

Character::Character(const Character &src) : _name(src._name), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		for (int i = 0; i < _floorCount; i++)
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
		_floorCount = 0;
		for (int i = 0; i < 4; i++)
		{
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (int i = 0; i < _floorCount; i++)
		delete _floor[i];
}

// ----------------------------------------------

const std::string &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
}

/**
 * @brief each caracter has a "floor" where they drop things; 
 *  a bit conceptually wierd, but it works
 */
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	if (_floorCount < 100)
	{
		_floor[_floorCount] = _inventory[idx];
		_floorCount++;
	}
	else
		delete _inventory[idx];
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}
