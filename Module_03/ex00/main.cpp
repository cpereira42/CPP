#include <iostream>
# include "ClapTrap.hpp"

int main( void ) 
{
    int round = 0;
    ClapTrap player1("Amon");
    ClapTrap player2("Meow");

    player1.setAttackDamage(5);
    player2.setAttackDamage(1);

    while ((player1.getHitPoint() > 0 && player2.getHitPoint() > 0) && (player2.getEnergyPoint() > 0 &&  player1.getEnergyPoint() > 0 ))
    {
        round += 1;
        std::cout << "Round " << round << std::endl;

        player1.attack(player2.getName());
        if (player1.getEnergyPoint() >= 0 && player1.getHitPoint() > 0)
            player2.takeDamage(player1.getAttackDamage());
        player2.beRepaired(10);
        std::cout << std::endl;
        player2.attack(player1.getName());
        if (player2.getEnergyPoint() >= 0 && player2.getHitPoint() > 0)
            player1.takeDamage(player2.getAttackDamage());
        player1.beRepaired(10);
        
        std::cout << std::endl;
    }

    if (player1.getHitPoint() < 0)
        std::cout << player1.getName() << "dead" << std::endl;
    if (player2.getHitPoint() < 0)
        std::cout << player2.getName() << "dead" << std::endl;
     if (player2.getEnergyPoint() <= 0 && player1.getEnergyPoint() <= 0)
        std::cout << "DRAW" << std::endl;







    return 0;
}