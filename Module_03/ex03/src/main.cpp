/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:50:58 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:50:59 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include "../includes/ClapTrap.hpp"
# include "../includes/ScavTrap.hpp"
# include "../includes/FragTrap.hpp"
# include "../includes/DiamondTrap.hpp"

int main( void ) 
{
    //int round = 0;

    /* ClapTrap player1("CT");
    ScavTrap player2("ST");
    FragTrap player3("FT");
    DiamondTrap player4("DT"); */
    

    /*std::cout << "FT HP = " << player3.getHitPoint() << "-" << player4.getHitPoint() <<std::endl;
    std::cout << "FT EP = " << player2.getEnergyPoint() << "-" << player4.getEnergyPoint() <<std::endl;
    std::cout << "FT AT = " << player2.getAttackDamage() << "-" << player4.getAttackDamage() <<std::endl;

    player4.whoAmI();
*/

    /*
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
    */

    std::cout << "=======================\n";
	DiamondTrap Dragonite;

   std::cout << "=======================\n";
	ClapTrap orc("Orc");

	orc.attack("Troll");
	//orc.takeDamage(3);
	//orc.beRepaired(1);

	std::cout << "=======================\n";
	ScavTrap troll("Troll");
	//troll.attack("Orc");
	//troll.takeDamage(5);
	//troll.beRepaired(4);
	troll.guardGate();

	std::cout << "=======================\n";
	FragTrap ogre("Ogre");
	//ogre.attack("Troll");
	//ogre.takeDamage(10);
	//ogre.beRepaired(8);
	ogre.highFivesGuys();

	std::cout << "=======================\n";
	DiamondTrap dragon("Dragon!");
	//dragon.attack("Troll");
    //dragon.takeDamage(20);
	//dragon.beRepaired(50);
	dragon.whoAmI();
	dragon.guardGate();
	dragon.highFivesGuys();

    std::cout << "=======================\n";
    std ::cout << Dragonite.getName() << "\n";
    Dragonite.whoAmI();


	std::cout << "=======================\n";

    std::cout << "FT HP = " << ogre.getHitPoint() << "-" << dragon.getHitPoint() <<std::endl;
    std::cout << "FT EP = " << troll.getEnergyPoint() << "-" << dragon.getEnergyPoint() <<std::endl;
    std::cout << "FT AT = " << ogre.getAttackDamage() << "-" << dragon.getAttackDamage() <<std::endl;


    return 0;
}
