#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
    std::cout << "ScavTrap constructor called" << std::endl;
    ScavTrap::_name = "Anonimous";
    ScavTrap::_energypoint = 50;
    ScavTrap::_hitpoint = 100;
    ScavTrap::_attackdamage = 20;
    return ;
}

ScavTrap::ScavTrap(std:: string name)
{
    std::cout << "ScavTrap Constructor " << name << " created :" << std::endl;
    ScavTrap::_name = name;
    ScavTrap::_energypoint = 50;
    ScavTrap::_hitpoint = 100;
    ScavTrap::_attackdamage = 20;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
    ScavTrap::operator = (src);
    return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    // fazer copia aqui
    this->_hitpoint = rhs._hitpoint;
    this->_attackdamage = rhs._attackdamage;
    this->_energypoint = rhs._energypoint;
    this->_name = rhs._name;
    
    return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor ScavTrap called" << std::endl;
    return ;
}

void ScavTrap::attack(const std::string& target)
{
    if (getEnergyPoint() > 0 && getHitPoint() > 0)
    {
        decreEnergyPoint();
        std::cout 
            << "ScavTrap "<< this->_name 
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

void ScavTrap:: guardGate(void)
{   
    if (this->_mode == 0)
    {   
        this->_mode = 1;
        std::cout << "Gate Mode is on" << std::endl;
    }
    else
    {
        this->_mode = 0;
        std::cout << "Gate Mode is off" << std::endl;
    }
        
    return ;
}