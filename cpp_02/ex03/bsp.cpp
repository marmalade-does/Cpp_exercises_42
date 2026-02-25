/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:38:25 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/24 20:35:32 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

/**
 * Is the cross_product product in 2 dimensions. Is a scalar
 * 	negative scalar p3 is to RIGHT of p1→p2
 * 	positive scalar p3 is to LEFT of p2→p1
 */
static Fixed cross_product(Point const p1, Point const p2, Point const p3)
{
        return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY())
                 - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());

}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = cross_product(a, b, point);
	Fixed d2 = cross_product(b, c, point);
	Fixed d3 = cross_product(c, a, point);

	bool hasNeg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	bool hasPos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

	if (hasNeg && hasPos)
			return false;
	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
			return false;
	return true;
}
