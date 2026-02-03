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

#include "myAwesomePhonebook.hpp"

std::string	Contact::getFirstName(void)
{
	return (firstName);
}

std::string	Contact::getLastName(void)
{
	return (lastName);
}

std::string	Contact::getNickname(void)
{
	return (nickName);
}

std::string	Contact::getDarkestSecret(void)
{
	return (secret);
}

std::string	Contact::getPhoneNumber(void)
{
	return (num);
}


std::string Contact::setFirstName(std::string firstName)
{
	this->firstName.assign(firstName);
}

void		Contact::setContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber)
{
	this->first.assign(FirstName);
	this->last.assign(LastName);
	this->nick.assign(Nickname);
	this->secret.assign(DarkestSecret);
	this->num.assign(PhoneNumber);
}