/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:55:12 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/24 18:06:38 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

/**
 * @remarks
 * operator= is declared for Orthodox Canonical Form, but it cannot actually
 * 	reassign _x and _y because they are `const`
 */
class Point
{
private:
	const Fixed     _x;
	const Fixed     _y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &src);
	Point &operator=(const Point &rhs);
	~Point(void);

	Fixed   getX(void) const;
	Fixed   getY(void) const;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif
