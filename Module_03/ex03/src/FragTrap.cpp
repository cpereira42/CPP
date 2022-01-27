/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:50:52 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:50:53 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int FragTrap::hitPointIni = 100;
int FragTrap::energyPointIni = 100;
int FragTrap::attackDamageIni = 30;

FragTrap::FragTrap( void ) : ClapTrap()
{
    this->setName("Anonimous");
    this->setEnergyPoint(energyPointIni);
    this->setHitPoint(hitPointIni);
    this->setAttackDamage(attackDamageIni);

    std::cout << "FragTrap constructor : " << getName()  << std::endl;
    return ;
}

FragTrap::FragTrap(std:: string name) : ClapTrap(name)
{
    this->setName(name);
    this->setEnergyPoint(100);
    this->setHitPoint(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap constructor : " << getName()  << std::endl;
    return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
    FragTrap::operator = (src);
    return ;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
    this->setHitPoint(rhs._hitpoint);
    this->setAttackDamage(rhs._attackdamage);
    this->setEnergyPoint(rhs._energypoint);
    this->setName(rhs._name);
    return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor FragTrap " <<getName() << std::endl;
    return ;
}


void FragTrap::attack(const std::string& target)
{
    if (getEnergyPoint() > 0 && getHitPoint() > 0)
    {
        setEnergyPoint(getEnergyPoint() - 1);
        std::cout 
            << "FragTrap "<< getName() 
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

void FragTrap:: highFivesGuys(void)
{   
    if (this->_modeFive == 0)
    {   
        this->_modeFive = 1;
        std::cout << "High Five is on" << std::endl;
    }
    else
    {
        this->_modeFive = 0;
        std::cout << "High Five is off" << std::endl;
    }
        
    return ;
}