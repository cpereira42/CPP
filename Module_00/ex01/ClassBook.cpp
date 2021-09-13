/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:56:05 by cpereira          #+#    #+#             */
/*   Updated: 2021/09/10 20:20:25 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Book.hpp"

Book::Book(void)
{
	this->i = 0;
}

Book::~Book(void)
{
}

void Book::creat(void)
{
	list[0].setFirstName("Cezar");
	list[0].setLastName("Pereira");
	list[0].setNickname("cpereira");
	list[0].setPhone("11-9.8563-6187");
	list[0].setDarksecret("VSCODE");

	list[1].setFirstName("Angelica");
	list[1].setLastName("Miranda");
	list[1].setNickname("anolivei");
	list[1].setPhone("11-9.6762-9421");
	list[1].setDarksecret("VSCODE2");

	list[2].setFirstName("AMUM");
	list[2].setLastName("MEOW");
	list[2].setNickname("ARYA");
	list[2].setPhone("11-9.2222-2222");
	list[2].setDarksecret("PETS");

	list[3].setFirstName("Paulo");
	list[3].setLastName("Cunha");
	list[3].setNickname("pcunha");
	list[3].setPhone("11-9.3333-3333");
	list[3].setDarksecret("VIM");

	list[4].setFirstName("JACQUE");
	list[4].setLastName("Rodrigues");
	list[4].setNickname("jakrodri");
	list[4].setPhone("11-9.4444-4444");
	list[4].setDarksecret("LUTA");

	list[5].setFirstName("ADRIAN");
	list[5].setLastName("ROQUE");
	list[5].setNickname("ADROQUE");
	list[5].setPhone("11-9.5555-5555");
	list[5].setDarksecret("DEVOPS");

	list[6].setFirstName("NAYRAN");
	list[6].setLastName("SIMON");
	list[6].setNickname("NASIMON");
	list[6].setPhone("11-9.6666-6666");
	list[6].setDarksecret("DEVOPS");

	list[7].setFirstName("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	list[7].setLastName("PEREIRA");
	list[7].setNickname("IPEREIRA");
	list[7].setPhone("11-9.7777-7777");
	list[7].setDarksecret("CANIL");

	i = 7;
}


void	Book::add(void)
{
	std::string buffer;

	std::cout << "Insert First Name"<< std::endl;
	std::cin >> buffer;
	list[i].setFirstName(buffer);
	std::cout << "Insert Last Name"<< std::endl;
	std::cin >> buffer;
	list[i].setLastName(buffer);
	std::cout << "Insert NickName"<< std::endl;
	std::cin >> buffer;
	list[i].setNickname(buffer);
	std::cout << "Insert Phone Number"<< std::endl;
	std::cin >> buffer;
	list[i].setPhone(buffer);
	std::cout << "Insert Dark Secret"<< std::endl;
	std::cin >> buffer;
	list[i].setDarksecret(buffer);
	i++;
	if (i == 8)
		i = 0;
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
	std::cout << "-----------------------------------------------------------------"<< std::endl;
	std::cout << "   id     |First Name|Last Name | NickName |  Phone   |DarkSecret|"<< std::endl;
	std::cout << "-----------------------------------------------------------------"<< std::endl;
	while (i < 8 && list[i].get_FirstName() != "")
	{
		std::cout << std::setw(10) << i << "|";
		reduc_string(list[i].get_FirstName());
		reduc_string(list[i].get_LastName());
		reduc_string(list[i].get_Nickname());
		reduc_string(list[i].get_Phone());
		reduc_string(list[i].get_Darkestsecret());
		std::cout << std::endl;
		i++;
	}


	num = 9;

	while (num < 0 || num > 8)
	{
		std::cout << "Chose the ID or 8 to back menu > ";
		std::cin >> chose;
		num = atoi(chose.c_str());
		if (chose.length() != 1)
        	num = 9;
	}
	if (num != 8)
		list_person(num);
	return ;
}

void	Book::list_person(int i)
{
	std::cout << "--------------------INFORMATIONS-------------------------------"<< std::endl;
	std::cout << "ID = " << i << std::endl ;
	std::cout << "First Name = " << list[i].get_FirstName() << std::endl;
	std::cout << "Last Name = " << list[i].get_LastName() << std::endl;
	std::cout << "Nickname = " << list[i].get_Nickname() << std::endl;
	std::cout << "Phone = " << list[i].get_Phone() << std::endl;
	std::cout << "Secret = " << list[i].get_Darkestsecret() << std::endl ;
	std::cout << "---------------------------------------------------------------"<< std::endl;
	return ;
}
