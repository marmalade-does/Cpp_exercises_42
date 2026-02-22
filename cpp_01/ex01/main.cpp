/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:05:52 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 13:16:42 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 5;

	Zombie *horde = zombieHorde(N, "Joey's zombie hoard");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}
