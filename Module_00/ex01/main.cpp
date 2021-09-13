/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:26:18 by cpereira          #+#    #+#             */
/*   Updated: 2021/09/10 20:32:31 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Book.hpp"

int	main (void)
{
	std::string command;
	Book book;

	book.creat();
	command =  "";
	while (1)
	{
		std::cout << "Please choose the command ADDR - SEARCH - EXIT > ";
		std::cin >> command ;
		if (command.compare("ADD") == 0)
			book.add();
		if (command.compare("SEARCH") == 0)
			book.list_book();
		if (command.compare("EXIT") == 0)
			break;
		command = "";
	}
	return (0);
}
