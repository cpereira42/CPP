/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:45:15 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/11 01:11:14 by cpereira         ###   ########.fr       */
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
        void setRawBits(int const raw);
        int getRawBits(void) const;
        float	toFloat(void)const;
		int		toInt(void)const;

    private:
        static const int _fractionalBits = 8;
        int _rawBits;
        
};

std::ostream &operator<<(std::ostream &outputFile, Fixed const &i);

#endif