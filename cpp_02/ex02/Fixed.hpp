/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:34:10 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/23 21:37:55 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/**
 * @brief most boring exercise ever, just teaching a bunch of operator overloading.
 */
class Fixed
{
private:
	int					_value;
	static const int	_fractBits = 8;

public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static Fixed			&min(Fixed &a, Fixed &b);
	static const Fixed		&min(const Fixed &a, const Fixed &b);
	static Fixed			&max(Fixed &a, Fixed &b);
	static const Fixed		&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */
