/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:28:20 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/13 00:35:48 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
# include <unistd.h>
#include "karen.hpp"


int main (void)
{
	Karen   karen;
    
    karen.complain("INFO");
    karen.complain("DEBUG");
    karen.complain("WARNING");
    karen.complain("ERROR");
    
    return (0);
}

