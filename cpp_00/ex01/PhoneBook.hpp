#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		void	cmdADD(void);
		void	cmdSEARCH(void);

	private:
		int		index;
		int		count;
		Contact	contacts[8];
		void	displayContactTable(void);
		void	displayContact(int i);
		std::string	truncStr(std::string str) const;
};

#endif
