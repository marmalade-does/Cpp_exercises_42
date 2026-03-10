/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:36:10 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/27 19:36:43 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**
 * @remark algunos tests hecho por chat
 */
int     main(void)
{
	std::cout << "=== Creating ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");

	std::cout << std::endl << "=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("Scavvy");

	std::cout << std::endl << "=== ScavTrap attacks ===" << std::endl;
	scav.attack("Clappy");
	clap.takeDamage(20);

	std::cout << std::endl << "=== ScavTrap repairs ===" << std::endl;
	scav.takeDamage(30);
	scav.beRepaired(10);

	std::cout << std::endl << "=== Guard Gate ===" << std::endl;
	scav.guardGate();

	std::cout << std::endl << "=== Copy ScavTrap ===" << std::endl;
	ScavTrap scav2(scav);
	scav2.attack("Clappy");

	std::cout << std::endl << "=== Destruction (reverse order) ===" << std::endl;
	return 0;
}
