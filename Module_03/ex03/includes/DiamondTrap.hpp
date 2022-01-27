/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:50:32 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:50:33 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"


class DiamondTrap : public FragTrap, public ScavTrap
{
    public :
        DiamondTrap( void );
        DiamondTrap(std:: string name);
        DiamondTrap(DiamondTrap const &src);
		~DiamondTrap( void );
        DiamondTrap &operator=(DiamondTrap const &rhs);
        virtual void attack(const std::string& target);
        void whoAmI(void);
    private :
        std:: string	_name;

};

#endif
