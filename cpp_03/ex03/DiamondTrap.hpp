/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:08:31 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/05 20:08:33 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// 'virtual' in Cpp generally means "resolve this at runtime, not compile time"

/**
 * @remark Diamond inherits from both ScavTrap and FragTrap
 * 	this means they have to use virtual inheritance 
 * 
 * 	Normal inheritance:
 * 		* instantiate ClapTrap → mem alloc'd → [ data members | vptr ]
 * 		* instantiate `Class ScavTrap: ClapTrap` → [ ClapTrap members | ScavTrap members ]
 * 		* instantiate `Class CrapTrap: ClapTrap, Crap` → [ ClapTrap members | Crap members | CrapTrap ]
 * 		* if you redefine an attribute you end up having both but compiler defaults to inferring the CrapTrap one
 * 		* if you redefine a function, you end up having both (in vtables) but compiler defaults to inferring the CrapTrap one
 * 
 * 	Virtual inheritance: 
 * 		* Problem: without it, DiamondTrap gets TWO ClapTrap subobjects (one from ScavTrap, one from FragTrap)
 * 		*          → ambiguity: which ClapTrap does DiamondTrap::hitPoints refer to?
 * 		* Core idea: `virtual ClapTrap` means "I won't own a ClapTrap copy,
 * 		*             I defer its construction to whoever is most derived"
 * 		* Result: only ONE shared ClapTrap sub-object exists regardless of how many paths lead to it
 * 		* Cost: derived class MUST explicitly call ClapTrap's constructor,
 * 		*       even if it's many levels removed from it in the hierarchy
 */
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string     _name;

public:
	DiamondTrap(void);
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap(void);

	using ScavTrap::attack;
	void    whoAmI(void);
};

#endif /* DIAMONDTRAP_HPP */
