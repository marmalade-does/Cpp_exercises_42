/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:24:06 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 15:38:04 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

/**
 * HumanA always uses a weapon ∴ better to use a reference that is set on initialisation
 * HumanB doesn't always have a weapon ∴ use pointer
 */
class HumanB
{
public:
	HumanB(std::string name);
	~HumanB(void);

	void	attack(void) const;
	void	setWeapon(Weapon &weapon);
private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif /* HUMANB_HPP */
