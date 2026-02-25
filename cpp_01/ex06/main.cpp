/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:35:37 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/23 12:00:00 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return (1);
	}
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}
