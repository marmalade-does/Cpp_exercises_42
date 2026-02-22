/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:22:25 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 16:48:31 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	typedef void (Harl::*HarlFunc)(void);

	HarlFunc        funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string     levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
			if (levels[i] == level)
			{
					(this->*funcs[i])();
					return ;
			}
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
