/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:36:04 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/20 16:49:09 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

// "getters"
std::string	Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (_lastName);
}

std::string	Contact::getNickname(void) const
{
	return (_nickName);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

/**
 * @brief setter
 * @remark Cpp convention is to have leading underscore for elements of a class
 * 		but you can also use `this->element = element`.
 */
void	Contact::setContact(std::string first, std::string last,
		std::string nick, std::string phone, std::string secret)
{
	_firstName = first;
	_lastName = last;
	_nickName = nick;
	_phoneNumber = phone;
	_darkestSecret = secret;
}
