/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:39:48 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 20:02:00 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"


/**
 * @remark getline() returns a stream (allowing for chaining);
 * 	however if the stream has a EOF then in boolean contexts
 * 	it evaluates to false
 */
int	main(void)
{
	PhoneBook	book;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << std::endl;
			break ;
		}
		if (cmd == "ADD")
			book.addContact();
		else if (cmd == "SEARCH")
			book.searchContact();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}
