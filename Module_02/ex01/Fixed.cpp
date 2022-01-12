/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:49:49 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/11 01:13:13 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>
#include <typeinfo>

Fixed::Fixed(void)
{
    this->_rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const int_number)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = int_number << Fixed::_fractionalBits;
}

Fixed::Fixed(float const float_number)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = (int)round(float_number * (1 << Fixed::_fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    this->_rawBits = rhs.getRawBits();
    return *this;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_rawBits / (float)(1 << this->_fractionalBits));
}

int		Fixed::toInt(void)const
{
	return (this->_rawBits >> Fixed::_fractionalBits);
}

void Fixed::setRawBits(int const raw) 
{
    this->_rawBits = raw;
}

std::ostream &operator<<(std::ostream &outputFile, Fixed const &i)
{
	outputFile << i.toFloat();
	return outputFile;
}

int Fixed::getRawBits(void) const 
{
    return this->_rawBits;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
