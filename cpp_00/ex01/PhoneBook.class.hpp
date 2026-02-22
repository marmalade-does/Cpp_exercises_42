#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contact.class.hpp"

class PhoneBook
{
	public:
		PhoneBook(void); // is the constructor function
		void	addContact(void);
		void	searchContact(void) const;

	private:
		int		_index;
		int		_count;
		Contact	_contacts[8];
		bool	getInput(const std::string &prompt, std::string &out);
		void	displayContactTable(void) const;
		void	displayContact(int i) const;
		std::string	truncStr(std::string str) const;
};

#endif
