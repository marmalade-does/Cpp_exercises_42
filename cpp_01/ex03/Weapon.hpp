/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:37:33 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 13:45:34 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>
# include <iomanip>

/**
 * The subject says `type`,
 * but the norm says private thing should be preceded with '_' ....
 */
class Weapon
{
public:
	// Weapon(void);
	Weapon(std::string weapon_name);
	~Weapon(void);

	const std::string	&getType(void) const;
	void				setType(std::string type);
	
private:
	std::string	_type;
};

#endif /* WEAPON_HPP */


