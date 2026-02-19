/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:39:48 by lroberts          #+#    #+#             */
/*   Updated: 2025/09/24 16:40:09 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : index(0), count(0)
{
}

std::string	PhoneBook::truncStr(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::cmdADD(void)
{
	std::string	first, last, nick, phone, secret;

	std::cout << "First name: ";
	if (!std::getline(std::cin, first))
		return ;
	std::cout << "Last name: ";
	if (!std::getline(std::cin, last))
		return ;
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, nick))
		return ;
	std::cout << "Phone number: ";
	if (!std::getline(std::cin, phone))
		return ;
	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, secret))
		return ;
	if (first.empty() || last.empty() || nick.empty()
		|| phone.empty() || secret.empty())
	{
		std::cout << "One or more fields empty, contact not saved." << std::endl;
		return ;
	}
	this->contacts[this->index].setContact(first, last, nick, phone, secret);
	std::cout << "Contact added to index " << this->index + 1 << "." << std::endl;
	this->index = (this->index + 1) % 8;
	if (this->count < 8)
		this->count++;
}

void	PhoneBook::cmdSEARCH(void)
{
	std::string	input;

	displayContactTable();
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, input))
		return ;
	displayContact(std::atoi(input.c_str()));
}

void	PhoneBook::displayContactTable(void)
{
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1);
		std::cout << "|" << std::setw(10) << truncStr(this->contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << truncStr(this->contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << truncStr(this->contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::displayContact(int i)
{
	if (i < 1 || i > this->count)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	i -= 1;
	std::cout << "First name: " << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[i].getDarkestSecret() << std::endl;
}
