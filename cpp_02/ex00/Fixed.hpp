/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:57:50 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/23 19:25:05 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed(void);						// default constructor
	Fixed(const Fixed &src);			// copy constructor
	Fixed &operator=(const Fixed &rhs);	// '=' assignment operator
	~Fixed(void);						// Destructor

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int	_value;
	static const int _fracBits=8;
};

#endif /* FIXED_HPP */
