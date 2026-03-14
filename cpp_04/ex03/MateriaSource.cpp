/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:37:56 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/12 12:31:44 by lroberts         ###   ########.fr       */
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

// ---------------------

/// @brief makes the MateriaSource learn a Materia
/// @param m a materia
/// @todo do I want to delete the materia when I don't need it?
void MateriaSource::learnMateria(AMateria *m)
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
 * This will create a materia fron the materia source
 */
AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] &&_templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return (0);
}
