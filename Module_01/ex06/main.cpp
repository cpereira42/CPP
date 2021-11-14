/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:28:20 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/13 23:30:17 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
# include <unistd.h>
#include "karen.hpp"


int main (int argc, char **argv)
{
	Karen   karen;
    
    if (argc != 2)
	{
		std::cout << "Invalid number os args, Please Check!!" << std::endl;
		return (1);
	}
    karen.complain(argv[1]);
    return (0);
}

