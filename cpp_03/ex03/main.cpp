/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:34:09 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/05 19:34:19 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int     main(void)
{
	std::cout << "=== Creating DiamondTrap ===" << std::endl;
	DiamondTrap diamond("Diamond");

	std::cout << std::endl << "=== Who Am I ===" << std::endl;
	diamond.whoAmI();

	std::cout << std::endl << "=== Attack (uses ScavTrap) ===" << std::endl;
	diamond.attack("Target");

	std::cout << std::endl << "=== Take Damage ===" << std::endl;
	diamond.takeDamage(40);

	std::cout << std::endl << "=== Repair ===" << std::endl;
	diamond.beRepaired(20);

	std::cout << std::endl << "=== Special abilities ===" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << std::endl << "=== Copy test ===" << std::endl;
	DiamondTrap diamond2(diamond);
	diamond2.whoAmI();

	std::cout << std::endl << "=== Destruction ===" << std::endl;
	return 0;
}