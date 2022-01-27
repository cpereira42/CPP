/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:50:36 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:50:37 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
# include "ClapTrap.hpp"


class FragTrap : public virtual ClapTrap
{
    public :
        FragTrap( void );
        FragTrap(std:: string name);
        FragTrap(FragTrap const &src);
		~FragTrap( void );
        FragTrap &operator=(FragTrap const &rhs);
        virtual void attack(const std::string& target);
        void highFivesGuys(void);
    
    protected: 
        static int hitPointIni;
        static int energyPointIni;
        static int attackDamageIni;

        int _modeFive ; 
        
};

#endif
