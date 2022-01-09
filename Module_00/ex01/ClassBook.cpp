/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:56:05 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/08 21:47:53 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"
#include "ClassBook.hpp"

Book::Book(void)
{
	this->i = 0;
	this->qtt = 0;
}

Book::~Book(void)
{
}

void	Book::add(void)
{
	std::string buffer;
	std::cout << "Insert First Name : ";
	std::getline(std::cin, buffer);
	list[i].setFirstName(buffer);
	std::cout << "Insert Last Name : ";
	std::getline(std::cin, buffer);
	list[i].setLastName(buffer);
	std::cout << "Insert NickName : ";
	std::getline(std::cin, buffer);
	list[i].setNickname(buffer);
	std::cout << "Insert Phone Number : ";
	std::getline(std::cin, buffer);
	list[i].setPhone(buffer);
	std::cout << "Insert Dark Secret : ";
	std::getline(std::cin, buffer);
	list[i].setDarksecret(buffer);
	i++;
	if (qtt <= 7)
		qtt++;
	if (i == 8)
		i = 0;
	return ;
}

void	Book::reduc_string(std::string s)
{
	if (s.size() > 10)
	{
		s = s.insert(9, ".");
		s = s.substr(0, 10);
	}
	std::cout << std::setw(10) << s << "|";
}

void	Book::list_book (void)
{
	int			i;
	int			num;
	std::string	chose;
	std::string	buffer;

	i = 0;
	std::cout << "-------------------------------------------"<< std::endl;
	std::cout << "   id     |First Name|Last Name | NickName |"<< std::endl;
	std::cout << "-------------------------------------------"<< std::endl;
	while (i < 8 && list[i].get_FirstName() != "")
	{
		std::cout << std::setw(10) << i + 1 << "|";
		reduc_string(list[i].get_FirstName());
		reduc_string(list[i].get_LastName());
		reduc_string(list[i].get_Nickname());
		std::cout << std::endl;
		i++;
	}

	num = 9;

	if (this->qtt > 0)
	{
		std::cout << "Chose the ID 1 to " << this->qtt << " > ";
		std::getline(std::cin, chose);
		num = atoi(chose.c_str());
		if (num >= 1 && num <= (this->qtt) && this->qtt > 0)
			list_person(num - 1);
		else
			std::cout << "Invalid choice ";
	}
	return ;
}

void	Book::list_person(int i)
{
	std::cout << "--------------------INFORMATIONS-------------------------------"<< std::endl;
	std::cout << "ID = " << i + 1 << std::endl ;
	std::cout << "First Name = " << list[i].get_FirstName() << std::endl;
	std::cout << "Last Name = " << list[i].get_LastName() << std::endl;
	std::cout << "Nickname = " << list[i].get_Nickname() << std::endl;
	std::cout << "Phone = " << list[i].get_Phone() << std::endl;
	std::cout << "Secret = " << list[i].get_Darkestsecret() << std::endl ;
	std::cout << "---------------------------------------------------------------"<< std::endl;
	return ;
}
