/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:01:01 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/12 12:30:35 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
	AMateria *_floor[100];
	int _floorCount;

public:
	Character();
	Character(const std::string &name);
	Character(const Character &src);
	Character &operator=(const Character &rhs);
	~Character();

	const std::string &getName() const;
	void equip(AMateria * m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
