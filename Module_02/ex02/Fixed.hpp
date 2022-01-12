/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:45:15 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/11 23:58:44 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string> // To use string
#include <iomanip>

class Fixed
{
    public :
        Fixed(void);
        Fixed(Fixed const &src);
        Fixed(int const int_number);
		Fixed(float const float_number);
        ~Fixed(void);

        Fixed &operator=(Fixed const &rhs);
        Fixed operator+(Fixed const &rhs);
        Fixed operator-(Fixed const &rhs);
        Fixed operator*(Fixed const &rhs);
        Fixed operator/(Fixed const &rhs);
        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        bool operator>(Fixed const &rhs) const;
        bool operator>=(Fixed const &rhs) const;
        bool operator<(Fixed const &rhs) const;
        bool operator<=(Fixed const &rhs) const;
        bool operator==(Fixed const &rhs) const;
        bool operator!=(Fixed const &rhs) const; 

        void setRawBits(int const raw);
        int getRawBits(void) const;
        float	toFloat(void)const;
		int		toInt(void)const;

        static const Fixed	&min(Fixed const &v1, Fixed const &v2);
		static const Fixed	&max(Fixed const &v1, Fixed const &v2);

    private:
        static const int _fractionalBits = 8;
        int _rawBits;
        
};

std::ostream &operator<<(std::ostream &outputFile, Fixed const &i);

#endif