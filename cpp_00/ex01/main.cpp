/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:39:48 by lroberts          #+#    #+#             */
/*   Updated: 2025/09/24 16:40:09 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break ;
		if (cmd == "ADD")
			book.cmdADD();
		else if (cmd == "SEARCH")
			book.cmdSEARCH();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}
