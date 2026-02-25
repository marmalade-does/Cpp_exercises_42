/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:18:12 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/23 12:00:00 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
public:
	Zombie(std::string name_str);
	~Zombie(void);
	void	announce(void);
private:
	std::string	_name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif /* ZOMBIE_HPP */
