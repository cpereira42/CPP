/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:01:18 by cpereira          #+#    #+#             */
/*   Updated: 2021/10/27 22:39:05 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//*******************SETTERS*******************************//

Zombie::~Zombie(void)
{
	std::cout << get_name() << " Brainzzss " << std ::endl;
}

Zombie::Zombie(void)
{
	return ;
}

void Zombie::annouce(void)
{
	std::cout << _name << "appear behind of you, Give me you Brain !!!!" << std ::endl ;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string	Zombie::get_name(void)
{
	return _name;
}



