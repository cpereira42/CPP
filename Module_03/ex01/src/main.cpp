/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:49:34 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:49:35 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main( void ) 
{
    int round = 0;
    ClapTrap player1("Amon");

    ScavTrap trap("ScravTrap");

    player1.setAttackDamage(5);

    while ((player1.getHitPoint() > 0 && trap.getHitPoint() > 0) && (trap.getEnergyPoint() > 0 &&  player1.getEnergyPoint() > 0 ))
    {
        round += 1;
        std::cout << "Round " << round << std::endl;

        player1.attack(trap.getName());
        if (player1.getEnergyPoint() >= 0 && player1.getHitPoint() > 0)
            trap.takeDamage(player1.getAttackDamage());
        trap.beRepaired(10);
        std::cout << std::endl;
        trap.attack(player1.getName());
        if (trap.getEnergyPoint() >= 0 && trap.getHitPoint() > 0)
            player1.takeDamage(trap.getAttackDamage());
        player1.beRepaired(2);
        
        trap.guardGate();
        trap.guardGate();
        std::cout << std::endl;
    }

    if (player1.getHitPoint() < 0)
        std::cout << player1.getName() << " dead" << std::endl;
    if (trap.getHitPoint() < 0)
        std::cout << trap.getName() << " dead" << std::endl;
     if (trap.getEnergyPoint() <= 0 && player1.getEnergyPoint() <= 0)
        std::cout << "DRAW" << std::endl;

    return 0;
}
