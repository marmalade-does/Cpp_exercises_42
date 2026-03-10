/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:25:53 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/10 13:33:41 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (src._templates[i])
			_templates[i] = src._templates[i]->clone();
	}
}

/**
 * @remark remember the FOOTGUN.
 * 	`MateriaSource materia_a = materia_b`
 * 	→ since declaration is on initialisation line this defualts
 *  → to copy constructor.
 * 
 * 	`MateriaSource materia_a;
 * 	 materia_a = materia_b;`
 * 	→ this is a normal `operator=` assignation
 * 
 * 	∴ you always need to do the delete in the assignment operator 
 */
MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _templates[i];
			_templates[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (rhs._templates[i])
				_templates[i] = rhs._templates[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete _templates[i];
}

// --------------

/**
 * @todo have I implemented this right?
 */
void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = m;
			return ;
		}
	}
	delete m;
}

/**
 * @todo create materia only exists if 
 */
AMateria* MateriaSource::createMateria(const std::string & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return (0);
}
