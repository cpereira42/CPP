/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:49:55 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:49:56 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        void setEnergyPoint(int EP);

        int  getAttackDamage(void);
        void setAttackDamage(int EP);

        std::string  getName(void);
        void setName(std:: string name);

    protected:
        std:: string	_name;
        int             _hitpoint;
        int             _energypoint;
        int             _attackdamage;
};

#endif