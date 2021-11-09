/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:26:18 by cpereira          #+#    #+#             */
/*   Updated: 2021/10/27 23:27:59 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include "Zombie.hpp"

int	main (void)
{
	std::string	name;
	Zombie *friends;
	int number;
	
	std::cout << "Please what is your name ?"<< std::endl;
	std::getline(std::cin, name);
	std::cout << "Welcome " << name << " How many friends you have?" << std::endl;
	std::cin>>number;  
	friends = zombieHorde(number, name);
	delete [] friends;
	
	return (0);
}
