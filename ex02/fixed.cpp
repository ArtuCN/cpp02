/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:07:15 by aconti            #+#    #+#             */
/*   Updated: 2024/10/25 15:48:04 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"



Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits)); // Correggi qui
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = fixed._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &fixed)
        _fixedPointValue = fixed._fixedPointValue;
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed& fixed)
{
	float num = fixed.toFloat() / roundf(fixed.toFloat());
	
	if (num == 1.0f)
		out << fixed.toInt();
	else
		out << fixed.toFloat();
	return out;
}
// Overload operators

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

//Arithmetic operators

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_fixedPointValue++;
	return (tmp);
}

Fixed Fixed::operator++()
{
	_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_fixedPointValue--;
	return (tmp);
}

Fixed Fixed::operator--()
{
	_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed tmp;
	tmp.setRawBits(_fixedPointValue + fixed.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed tmp;
	tmp.setRawBits(_fixedPointValue - fixed.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed tmp;
	tmp.setRawBits((_fixedPointValue * fixed.getRawBits()) >> _fractionalBits);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed tmp;
	if (fixed.getRawBits() == 0)
	{
		std::cout << "Error: Division by zero" << std::endl;
		return (tmp);
	}
	tmp.setRawBits((_fixedPointValue << _fractionalBits) / fixed.getRawBits());
	return (tmp);
}


// Comparison operators

bool Fixed::operator>(const Fixed &fixed) const
{
	return (_fixedPointValue > fixed.getRawBits() ? true : false);
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (_fixedPointValue < fixed.getRawBits() ? true : false);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (_fixedPointValue >= fixed.getRawBits() ? true : false);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (_fixedPointValue <= fixed.getRawBits() ? true : false);
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (_fixedPointValue == fixed.getRawBits() ? true : false);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (_fixedPointValue != fixed.getRawBits() ? true : false);
}