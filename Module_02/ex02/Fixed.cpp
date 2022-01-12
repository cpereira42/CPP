/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:49:49 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/12 00:16:47 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>
#include <typeinfo>

Fixed::Fixed(void)
{
    this->_rawBits = 0;
}

Fixed::Fixed(int int_number)
{
    this->_rawBits = int_number << _fractionalBits;
}

Fixed::Fixed(float float_number)
{
    this->_rawBits = roundf(float_number * (1 << _fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    this->_rawBits = rhs.getRawBits();
    return *this;
}

Fixed Fixed::operator+(Fixed const &rhs){
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs){
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs){
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs){
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(){
    ++this->_rawBits;
    return *this;
}

Fixed &Fixed::operator--(){
    --this->_rawBits;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed val(*this);
    operator++();
    return val;
}

Fixed Fixed::operator--(int){
    Fixed val(*this);
    operator--();
    return val;
}

bool Fixed::operator > (Fixed const &rhs) const{
    return (this->_rawBits > rhs._rawBits);
}

bool Fixed::operator>=(Fixed const &rhs)const{
    return (this->_rawBits >= rhs._rawBits);
}

bool Fixed::operator<(Fixed const &rhs)const{
    return (this->_rawBits < rhs._rawBits);
}

bool Fixed::operator<=(Fixed const &rhs)const{
    return (this->_rawBits <= rhs._rawBits);
}

bool Fixed::operator==(Fixed const &rhs)const{
    return (this->_rawBits == rhs._rawBits);
}

bool Fixed::operator!=(Fixed const &rhs)const{
    return (this->_rawBits != rhs._rawBits);
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
    
}

const Fixed &Fixed::min(const Fixed &v1, const Fixed &v2)
{
	if (v1 < v2)
		return (v1);
	else
		return (v2);
}

const Fixed &Fixed::max(const Fixed &v1, const Fixed &v2)
{
	if (v1 < v2)
		return (v2);
	else
		return (v1);
} 
