/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:49:49 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/14 00:15:57 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed(void) : fractionalbBits(8)
{
    this->setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const raw) : fractionalbBits(raw)
{
    this->setRawBits(0);
    std::cout << "Parametric Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) : fractionalbBits(8) {
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

void Fixed::setRawBits(int const raw) 
{
    this->rawBits = raw;
}

int Fixed::getRawBits(void) const 
{

    std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    this->rawBits = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}