/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:02:25 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/05 16:03:14 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/**
 * @remark more goofy tests to make sure that it works
 */
int     main(void)
{
	std::cout << "=== Creating ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");

	std::cout << std::endl << "=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("Scavvy");

	std::cout << std::endl << "=== Creating FragTrap ===" << std::endl;
	FragTrap frag("Fraggy");

	std::cout << std::endl << "=== FragTrap attacks ===" << std::endl;
	frag.attack("Scavvy");
	scav.takeDamage(30);

	std::cout << std::endl << "=== FragTrap high five ===" << std::endl;
	frag.highFivesGuys();

	std::cout << std::endl << "=== ScavTrap guard gate ===" << std::endl;
	scav.guardGate();

	std::cout << std::endl << "=== FragTrap repairs ===" << std::endl;
	frag.takeDamage(50);
	frag.beRepaired(25);

	std::cout << std::endl << "=== Destruction (reverse order) ===" << std::endl;
	return 0;
}
