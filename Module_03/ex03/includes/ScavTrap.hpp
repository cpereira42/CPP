#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
# include "ClapTrap.hpp"


class ScavTrap : public virtual ClapTrap
{
    public :
        ScavTrap( void );
        ScavTrap(std:: string name);
        ScavTrap(ScavTrap const &src);
		~ScavTrap( void );
        ScavTrap &operator=(ScavTrap const &rhs);
        virtual void attack(const std::string& target);
        void guardGate(void);
    protected :
        static int hitPointIni;
        static int energyPointIni;
        static int attackDamageIni;
        int _modeguard ; 

};

#endif
