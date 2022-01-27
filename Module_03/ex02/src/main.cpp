/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:54:56 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/26 20:54:57 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include "../includes/ClapTrap.hpp"
# include "../includes/ScavTrap.hpp"
# include "../includes/FragTrap.hpp"

int main( void ) 
{
    //int round = 0;
    ClapTrap player1("ClapTrap");
    ScavTrap player2("ScravTrap");
    FragTrap player3("FragTrap");

    player1.attack(player2.getName());
    player2.takeDamage(player1.getAttackDamage());
    player2.beRepaired(10);

    player2.attack(player3.getName());
    player3.takeDamage(player2.getAttackDamage());
    player3.beRepaired(1);

    player3.attack(player1.getName());
    player1.takeDamage(player3.getAttackDamage());
    player1.beRepaired(1);

    return 0;
}
