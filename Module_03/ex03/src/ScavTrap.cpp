/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:51:02 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:51:03 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int ScavTrap::hitPointIni = 100;
int ScavTrap::energyPointIni = 50;
int ScavTrap::attackDamageIni = 20;

ScavTrap::ScavTrap( void ) : ClapTrap()
{
    this->setName("Anonimous");
    this->setEnergyPoint(energyPointIni);
    this->setHitPoint(hitPointIni);
    this->setAttackDamage(attackDamageIni);
    std::cout << "ScavTrap constructor : " << getName()  << std::endl;
    return ;
}

ScavTrap::ScavTrap(std:: string name) : ClapTrap(name)
{
    this->setName(name);
    this->setEnergyPoint(50);
    this->setHitPoint(100);
    this->setAttackDamage(20);
    std::cout << "ScavTrap Constructor : " << getName()  << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) 
{
    ScavTrap::operator = (src);
    return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    this->setHitPoint(rhs._hitpoint);
    this->setAttackDamage(rhs._attackdamage);
    this->setEnergyPoint(rhs._energypoint);
    this->setName(rhs._name);
    return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor ScavTrap " <<getName() << std::endl;
    return ;
}

void ScavTrap::attack(const std::string& target)
{
    if (getEnergyPoint() > 0 && getHitPoint() > 0)
    {
        setEnergyPoint(getEnergyPoint() - 1);
        std::cout 
            << "ScavTrap "<< getName()
            << " attacks " << target
            << ", causing " << getAttackDamage()
            << " points of damage!"
            << std::endl;
    }
    else
    {
        if (getEnergyPoint() < 0)
            std::cout << "No Energy to attack EP= " << getEnergyPoint() << std::endl;
    }
    return ;
} 

void ScavTrap:: guardGate(void)
{   
    if (this->_modeguard == 0)
    {   
        this->_modeguard = 1;
        std::cout << "Gate Mode is on" << std::endl;
    }
    else
    {
        this->_modeguard = 0;
        std::cout << "Gate Mode is off" << std::endl;
    }
        
    return ;
}