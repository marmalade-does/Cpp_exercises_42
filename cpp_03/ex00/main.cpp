/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:15:25 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/27 11:18:31 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// algunos tests diseñados por Chat >:)
int     main(void)
{
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	std::cout << std::endl << "=== Attack tests ===" << std::endl;
	a.attack("Beta");
	b.takeDamage(0);

	std::cout << std::endl << "=== Repair test ===" << std::endl;
	b.beRepaired(5);

	std::cout << std::endl << "=== Heavy damage test ===" << std::endl;
	a.takeDamage(15);
	a.attack("Beta");
	a.beRepaired(5);

	std::cout << std::endl << "=== Energy drain test ===" << std::endl;
	for (int i = 0; i < 12; i++)
			b.attack("Alpha");

	std::cout << std::endl << "=== Copy test ===" << std::endl;
	ClapTrap c(a);
	ClapTrap d;
	d = b;

	std::cout << std::endl << "=== Destruction ===" << std::endl;
	return 0;
}
