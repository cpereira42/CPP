/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:45:15 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/14 00:16:26 by cpereira         ###   ########.fr       */
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
        Fixed(int const raw);
        Fixed(Fixed const &src);
        ~Fixed(void);

        Fixed &operator=(Fixed const &rhs);
        void setRawBits(int const raw);
        int getRawBits(void) const;

    private:
        const int fractionalbBits;
        int rawBits;
        
};

#endif