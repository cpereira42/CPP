/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:26:18 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/08 17:03:26 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"
#include "ClassBook.hpp"

int	main (void)
{
	std::string command;
	Book book;

	command =  "";
	while (1)
	{
		std::cout << "Please choose the command ADD - SEARCH - EXIT : ";
		std::getline(std::cin, command);
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
