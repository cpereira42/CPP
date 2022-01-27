#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public :
        ClapTrap( void );
        ClapTrap(std:: string name);
        ClapTrap(ClapTrap const &src);
		~ClapTrap( void );
        ClapTrap &operator=(ClapTrap const &rhs);
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        int  getHitPoint(void);
        void setHitPoint(int HP);

        int  getEnergyPoint(void);
        void decreEnergyPoint(void);

        int  getAttackDamage(void);
        void setAttackDamage(int EP);

        std::string  getName(void);


    protected:
        std:: string	_name;
        int             _hitpoint;
        int             _energypoint;
        int             _attackdamage;
};

#endif