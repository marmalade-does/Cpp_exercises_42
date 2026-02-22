/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:39:48 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/20 17:30:25 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"


PhoneBook::PhoneBook(void) : _index(0), _count(0)
{
}

/**
 * @remarks this uses initializer lists
 * you could also do someting like this (however this is redefinition not done initialization)
 * online syas a more Cpp way to do this is to use initialisation lists 
 * 
 * @remark std::string internally uses a `new/delete` allocations, however, those are managed when it enters/leaves scope
 * @remark std::string is returned as a first-class object
 */
std::string	PhoneBook::truncStr(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::addContact(void)
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
	_contacts[_index].setContact(first, last, nick, phone, secret);
	std::cout << "Contact added to index " << _index + 1 << "." << std::endl;
	_index = (_index + 1) % 8;
	if (_count < 8)
		_count++;
}

void	PhoneBook::searchContact(void) const
{
	std::string	input;

	displayContactTable();
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, input))
		return ;
	displayContact(std::atoi(input.c_str()));
}

/**
 * @remark 'std::setw(x)' is from the '# include <iomanip>' lib,
 * @remark 'std::setw(x)' sets the min fieild width for the next output → very nifty
 */
void	PhoneBook::displayContactTable(void) const
{
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1);
		std::cout << "|" << std::setw(10) << truncStr(_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << truncStr(_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << truncStr(_contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::displayContact(int i) const
{
	if (i < 1 || i > _count)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	i -= 1;
	std::cout << "First name: " << _contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[i].getDarkestSecret() << std::endl;
}
