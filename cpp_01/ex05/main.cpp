/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:02:40 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 19:02:59 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int     main(void)
{
	Harl    harl;

	std::cout << "=== Valid levels ===" << std::endl;

	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "[ INFO ]" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "[ WARNING ]" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "[ ERROR ]" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "=== Invalid levels ===" << std::endl;

	std::cout << "[ empty string ]" << std::endl;
	harl.complain("");
	std::cout << std::endl;

	std::cout << "[ lowercase: debug ]" << std::endl;
	harl.complain("debug");
	std::cout << std::endl;

	std::cout << "[ mixed case: Warning ]" << std::endl;
	harl.complain("Warning");
	std::cout << std::endl;

	std::cout << "[ random string: HELLO ]" << std::endl;
	harl.complain("HELLO");
	std::cout << std::endl;

	std::cout << "[ with space: ERROR  ]" << std::endl;
	harl.complain("ERROR ");
	std::cout << std::endl;

	std::cout << "=== Repeated calls ===" << std::endl;

	std::cout << "[ DEBUG again ]" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "[ ERROR again ]" << std::endl;
	harl.complain("ERROR");

	return (0);
}

