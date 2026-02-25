/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:55:13 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/24 19:12:47 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Point.hpp"

/**
 * The `const Fixed` HAVE TO be set in initialization list
 */
Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
}

/**
 * This can't actually reassign because `const` for _x, _y
 */
Point &Point::operator=(const Point &rhs)
{
	(void)rhs;
	return *this;
}

Point::~Point(void)
{
}

Fixed Point::getX(void) const
{
	return this->_x;
}

Fixed Point::getY(void) const
{
	return this->_y;
}

