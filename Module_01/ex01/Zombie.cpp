/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:01:18 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/08 21:44:25 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//*******************SETTERS and GETTERS*******************************//

Zombie::~Zombie(void)
{
	std::cout << get_name() << " RUN " << std ::endl;
}

Zombie::Zombie(void)
{
	return ;
}

void Zombie::annouce(void)
{
	std::cout << _name << " Present !!!" << std ::endl ;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string	Zombie::get_name(void)
{
	return _name;
}



