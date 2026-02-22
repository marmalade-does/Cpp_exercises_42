

# include "Harl.hpp"



Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

/**
 * @brief `typedef void (Harl::*HarlFunc)(void);` defines Harlfunc as a pointer to a function
 * look through the levels and then use the appropiate function.
 */
void    Harl::complain(std::string level)
{
	switch (level)
	{
		case "DEBUG":   debug();   break;
		case "INFO":    info();    break;
		case "WARNING": warning(); break;
		case "ERROR":   error();   break;
	}
}


void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}


void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}


void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


