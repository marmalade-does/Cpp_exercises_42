/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:24:18 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 15:35:32 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

/**
 * HumanA always uses a weapon ∴ better to use a reference that is set on initialisation
 * HumanB doesn't always have a weapon ∴ use pointer
 */
class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	
	void	attack(void) const;
	
private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif /* HUMANA_HPP */
