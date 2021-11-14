/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:30:03 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/13 23:30:04 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "karen.hpp"
# include <iostream>

Karen::Karen(void)
{
	return ;
}
Karen::~Karen()
{
	return ;
}

void    Karen::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void    Karen::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void    Karen::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void    Karen::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void    Karen::invalid(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void    Karen::complain(std::string level)
{
    int     i;
    std::string array_actions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void    (Karen::*execute_action[5])(void) = { &Karen::debug,
                                                 &Karen::info,
                                                 &Karen::warning,
                                                 &Karen::error,
                                                 &Karen::invalid,
    };

    i = 0;
    while (array_actions[i] != level && i <= 3)
    {
        i++;
    }
    switch (i)
	{
		case 0:
			(this->*(execute_action[0]))();
		case 1:
			(this->*(execute_action[1]))();
		case 2:
			(this->*(execute_action[2]))();
		case 3:
			(this->*(execute_action[3]))();
			break;
		default:
			(this->*(execute_action[4]))();
			break;
	}
}