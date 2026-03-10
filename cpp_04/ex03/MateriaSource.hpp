/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:18:36 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/10 13:24:55 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

/**
 * @remark that IMateriaSource contains: 
 * 		virtual destructor()
 * 		learnMateria
 * 		createMateria
 */
class MateriaSource : public IMateriaSource
{
private:
	AMateria *_templates[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource &operator=(const MateriaSource &rhs);
	~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria *createMateria(const std::string &type);
};

#endif /* MATERIASOURCE_HPP */
