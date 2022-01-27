/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:50:47 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:50:48 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), FragTrap(),ScavTrap()
{
    ClapTrap::setName("Anonimous_clap_name");
    DiamondTrap::_name = "Anonimous";
    DiamondTrap::setEnergyPoint(ScavTrap::energyPointIni);
    DiamondTrap::setHitPoint(FragTrap::hitPointIni);
    DiamondTrap::setAttackDamage(FragTrap::attackDamageIni);
    std::cout << "DiamondTrap constructor : "<< getName() << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std:: string name)
{
    ClapTrap::setName(name + "_clap_name");
    DiamondTrap::_name = name;
    DiamondTrap::setEnergyPoint(ScavTrap::energyPointIni);
    DiamondTrap::setHitPoint(FragTrap::hitPointIni);
    DiamondTrap::setAttackDamage(FragTrap::attackDamageIni);
    std::cout << "DiamondTrap constructor : "<< getName() << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
    DiamondTrap::operator = (src);
    return ;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
    this->setHitPoint(rhs._hitpoint);
    this->setAttackDamage(rhs._attackdamage);
    this->setEnergyPoint(rhs._energypoint);
    this->setName(rhs._name);
    return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor DiamondTrap " << getName() << std::endl;
    return ;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
    return ;
} 

void DiamondTrap:: whoAmI (void)
{
	std::cout << "Clap " << ClapTrap::_name<<  " Diamond "  << this->_name << std::endl;
    return ;
}
