/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:33:40 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/24 17:54:51 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * BSP → Binairy Space Partition
 */
int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point inside(2.0f, 2.0f);
	Point onEdge(5.0f, 0.0f);
	Point onVertex(0.0f, 0.0f);
	Point outside(10.0f, 10.0f);
	Point insideClose(1.0f, 1.0f);

	std::cout << "Triangle: A(0,0) B(10,0) C(0,10)" << std::endl;

	std::cout << "Point (2,2) inside: ";
	if (bsp(a, b, c, inside)) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;

	std::cout << "Point (5,0) on edge: ";
	if (bsp(a, b, c, onEdge)) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;

	std::cout << "Point (0,0) on vertex: ";
	if (bsp(a, b, c, onVertex)) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;

	std::cout << "Point (10,10) outside: ";
	if (bsp(a, b, c, outside)) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;

	std::cout << "Point (1,1) inside: ";
	if (bsp(a, b, c, insideClose)) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;

	return 0;
}
