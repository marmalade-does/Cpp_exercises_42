#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
		void		setContact(std::string first, std::string last,
						std::string nick, std::string phone,
						std::string secret);
};

#endif
