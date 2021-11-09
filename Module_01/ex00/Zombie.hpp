/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:46:12 by cpereira          #+#    #+#             */
/*   Updated: 2021/10/27 22:36:12 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string> // To use string
#include <iomanip>

class Zombie
{
	public:
		Zombie( void );
		~Zombie( void );
		
		void			annouce(void);
		std:: string	get_name(void);
		void			set_name(std::string name);

		
	private:
		std::string	_name;

};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
