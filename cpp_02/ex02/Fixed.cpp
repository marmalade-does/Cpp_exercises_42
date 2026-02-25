/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:38:37 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/24 17:23:32 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(const int value)
{
	this->_value = value << _fractBits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << _fractBits));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
			this->_value = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (float)(1 << _fractBits);
}

int Fixed::toInt(void) const
{
	return this->_value >> _fractBits;
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return this->_value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->_value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->_value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->_value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return this->_value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->_value != rhs._value;
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_value + rhs._value);
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_value - rhs._value);
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits((long long)this->_value * rhs._value / (1 << _fractBits));
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits((long long)this->_value * (1 << _fractBits) / rhs._value);
	return result;
}

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

/**
 * you need both const and non-const version for non-const/const corectness
 */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
			return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
			return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
			return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
			return a;
	return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
