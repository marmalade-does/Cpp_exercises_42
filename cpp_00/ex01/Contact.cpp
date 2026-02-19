/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:36:04 by lroberts          #+#    #+#             */
/*   Updated: 2025/09/24 16:38:41 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFirstName(void) const
{
	return (this->firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->lastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}

void	Contact::setContact(std::string first, std::string last,
		std::string nick, std::string phone, std::string secret)
{
	this->firstName = first;
	this->lastName = last;
	this->nickName = nick;
	this->phoneNumber = phone;
	this->darkestSecret = secret;
}
