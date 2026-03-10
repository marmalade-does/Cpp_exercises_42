/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:14:29 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/10 13:14:48 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

class ICharacter;

/**
 * 
 */
class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(const std::string & type);
	AMateria(const AMateria & src);
	AMateria & operator=(const AMateria & rhs);
	virtual ~AMateria();

	const std::string & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter & target);
};

#endif /* AMATERIA_HPP */
