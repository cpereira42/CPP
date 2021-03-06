/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:45:15 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/11 00:54:13 by cpereira         ###   ########.fr       */
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
        ~Fixed(void);

        Fixed &operator=(Fixed const &rhs);
        void setRawBits(int const raw);
        int getRawBits(void) const;

    private:
        static const int _fractionalbBits = 8;
        int _rawBits;
        
};

#endif