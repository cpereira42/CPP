/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:50:02 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:50:03 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
# include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
    public :
        ScavTrap( void );
        ScavTrap(std:: string name);
        ScavTrap(ScavTrap const &src);
		~ScavTrap( void );
        ScavTrap &operator=(ScavTrap const &rhs);
        virtual void attack(const std::string& target);
        void guardGate(void);
    private :
        int _modeGuard ;
        
};

#endif
