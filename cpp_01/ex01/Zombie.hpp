/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:01:37 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 13:08:55 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
public:
	Zombie(void);
	Zombie(std::string name_str);
	~Zombie(void);
	void	announce(void);
	void	setName(std::string name_str);
private:
	std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif /* ZOMBIE_HPP */
