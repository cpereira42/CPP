/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:26:18 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/08 19:32:32 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include "Zombie.hpp"

int	main (void)
{
	std::string	name;
	Zombie player;

	std::cout << "Please what is your name ?"<< std::endl;
	std::getline(std::cin, name);
	player.set_name(name);
	std::cout << "Welcome " << player.get_name() << std::endl;
	randomChump("Amow ");
	std::cout << "RUN " << player.get_name() <<" RUN " << std::endl;
	return (0);
}
