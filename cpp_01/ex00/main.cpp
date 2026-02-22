/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:28:27 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 12:57:01 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.class.hpp"

void	randomChump( std::string name );
Zombie	*newZombie( std::string name_str );

/**
 * what is the main learning
 * `new` keyword puts it on the heap, ∴ you have to `delete` it
 * When it is on the stack destructor is run when function popped of function stack 
 */
int main(void)
{
	std::cout  << "----- Heap Zombie -----" << std::endl;	
	Zombie *zombie = newZombie("Joey");
	zombie->announce();
	delete zombie;

	std::cout  << "----- Stack Zombie -----" << std::endl;
	randomChump("Billy");
	// zombie.announe() // <-- invalid
	
	return (0);
}


Zombie	*newZombie( std::string name_str )
{
	Zombie *zombie = new Zombie(name_str);
	return (zombie);	
}

// RAII  zombie deleted with function popped off stack	
void	randomChump( std::string name )
{
	Zombie zombie(name);
	zombie.announce();
}
