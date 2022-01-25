/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:48:05 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/24 22:04:49 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// fazer as canonicas operato= e copia

ClapTrap::ClapTrap( void )
{
    std::cout << "Default constructor called" << std::endl;
    this->_name = "Anonimous";
    this->_energypoint = 10;
    this->_hitpoint = 10;
    this->_attackdamage = 0;
    return ;
}

ClapTrap::ClapTrap(std:: string name)
{
    std::cout << "Constructor " << name << " created :" << std::endl;
    this->_name = name;
    this->_energypoint = 10;
    this->_hitpoint = 10;
    this->_attackdamage = 0;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    ClapTrap::operator = (src);
    return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
    // fazer copia aqui
    this->_hitpoint = rhs._hitpoint;
    this->_attackdamage = rhs._attackdamage;
    this->_energypoint = rhs._energypoint;
    this->_name = rhs._name;
    
    return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
    return ;
}
void ClapTrap::attack(const std::string& target)
{

    if (getEnergyPoint() > 0 && getHitPoint() > 0)
    {
        decreEnergyPoint();
        std::cout 
            << "ClapTrap "<< this->_name 
            << " attacks " << target
            << ", causing " << this->_attackdamage
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
        decreEnergyPoint();
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
void ClapTrap:: decreEnergyPoint(void)
{
    this->_energypoint -= 1 ;
    return ;
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

