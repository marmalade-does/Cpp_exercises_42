/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:48:40 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/12 12:29:46 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class AMateria;

/**
 * @remark even though this is an interface, I had to define the destructor in ICharacter.cpp
 * normal production code would have it as the comment has it, but I worried that was ANTI norm 
 */
class ICharacter
{
public:
	virtual ~ICharacter(); // {};
	virtual const std::string &getName() const = 0;
	virtual void equip(AMateria * m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

#endif