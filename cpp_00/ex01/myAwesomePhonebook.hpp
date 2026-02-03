#ifndef MY_AWESOME_PHONE_BOOK_HPP

#define MY_AWESOME_PHONE_BOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Contact
{
	private:
		std::string firstName, lastName, nickName, secret, num;
	public:
		std::string		getFirstName(void);
		std::string		getLastName(void);
		std::string		getNickname(void);
		std::string		getDarkestSecret(void);
		std::string		getPhoneNumber(void);
		// TODO shoudln't I make individual setters?
		void			setContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber);
		
};

class PhoneBook
{
	public:
		void		cmdADD(void);
		void		cmdSEARCH(void);
		void		setIndex(int i);
		void		displayContactTable(void);
		void		displayContact(int i);
		void		addContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber);	
	private:
		int		index;
		Contact	contact[8];
};

#endif