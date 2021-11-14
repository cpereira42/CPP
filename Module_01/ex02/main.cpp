/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:31:12 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/13 23:31:13 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string> // To use string
#include <iomanip>

int	main (void)
{
    std::string phrase;
    std::string *phrasePTR;
    std::string &phraseREF = phrase;

    phrase = "HI THIS IS BRAIN";
    phrasePTR = &phrase;

	std::cout << "Adress string "	<< &phrase << std::endl;
    std::cout << "Adress stringPTR "	<< phrasePTR << std::endl;
    std::cout << "Adress stringREF "	<< &phraseREF << std::endl;
    std::cout << "String by stringPTR "	<< *phrasePTR << std::endl;
    std::cout << "String by stringREF "	<< phraseREF << std::endl;
    return (0);
}