/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:48:05 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:29:59 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
    this->setName("Anonimous");
    this->setEnergyPoint(10);
    this->setHitPoint(10);
    this->setAttackDamage(0);
    std::cout << "ClapTrap constructor : " << getName()  << std::endl;
    return ;
}

ClapTrap::ClapTrap(std:: string name)
{
    this->setName(name);
    this->setEnergyPoint(10);
    this->setHitPoint(10);
    this->setAttackDamage(0);
    std::cout << "ClapTrap constructor : " << getName()  << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    ClapTrap::operator = (src);
    return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
    this->setHitPoint(rhs._hitpoint);
    this->setAttackDamage(rhs._attackdamage);
    this->setEnergyPoint(rhs._energypoint);
    this->setName(rhs._name);
    return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor " <<getName() << std::endl;
    return ;
}
void ClapTrap::attack(const std::string& target)
{
    if (getEnergyPoint() > 0 && getHitPoint() > 0)
    {
        setEnergyPoint(getEnergyPoint() - 1);
        std::cout 
            << "ClapTrap "<< getName()
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

void ClapTrap::takeDamage (unsigned int amount)
{
    int hp = getHitPoint();
    setHitPoint(hp - amount);
    std::cout 
        << "ClapTrap " << this->_name
        << " takes " << amount << " points, "
        << " HP = " << getHitPoint()
        << " Energy " << getEnergyPoint()
        << std::endl;
    return ; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
    int hp = getHitPoint();
    if (getEnergyPoint() > 0 && hp > 0)
    {
        setEnergyPoint(getEnergyPoint() - 1);
        setHitPoint(hp + amount);
        std::cout 
            << "ClapTrap " << this->_name
            << " repaired " << amount << " points, "
            << " HP = " << getHitPoint()
            << " Energy " << getEnergyPoint()
            << std::endl;
    }
    else
    {
        if (getEnergyPoint() < 0)
            std::cout << "No Energy to repair EP= " << getEnergyPoint() << std::endl;
        else
            std::cout << this->getName() << " Dead " << getHitPoint() << std::endl;
    }
        
    return ; 
}

//*********** GETTERS AND SETTERS *************/

std::string ClapTrap:: getName()
{
    return this->_name;
}

void ClapTrap:: setName(std::string name)
{
    this->_name = name;
}

int ClapTrap:: getHitPoint()
{
    return this->_hitpoint;
}
void ClapTrap:: setHitPoint(int HP)
{
    this->_hitpoint = HP;
    return ;
}

int ClapTrap:: getEnergyPoint()
{
    return this->_energypoint;
}

void ClapTrap:: setEnergyPoint(int EP)
{
    this->_energypoint = EP;
}

int ClapTrap:: getAttackDamage()
{
    return this->_attackdamage;
}
void ClapTrap:: setAttackDamage(int attack)
{
    this->_attackdamage = attack;
    return ;
}

