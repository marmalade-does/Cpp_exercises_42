/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:12:10 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/23 21:23:52 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_value;
	static const int 	_fractBits = 8;

public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &rhs);
	Fixed &operator=(const Fixed &rhs);
	
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void)	const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */
