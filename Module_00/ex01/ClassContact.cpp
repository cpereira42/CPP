/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:01:18 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/08 19:28:45 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//*******************SETTERS*******************************//

Contact::~Contact(void)
{
}

Contact::Contact(void)
{
}

void	Contact::setFirstName(const std::string &first_name)
{
	this->_first_name = first_name;
}

void	Contact::setLastName(const std::string &last_name)
{
	this->_last_name = last_name;
}

void	Contact::setNickname(const std::string &nickname)
{
	this->_nickname = nickname;
}

void	Contact::setPhone(const std::string &phone)
{
	this->_phone = phone;
}

void	Contact::setDarksecret(const std::string &dark_secret)
{
	this->_darkest_secret = dark_secret;
}

//*********************GETTERS******************************//

const std::string	Contact::get_FirstName(void)
{
	return _first_name;
}

const std::string	Contact::get_LastName(void)
{
	return _last_name;
}

const std::string	Contact::get_Nickname(void)
{
	return _nickname;
}

const std::string	Contact::get_Phone(void)
{
	return _phone;
}

const std::string	Contact::get_Darkestsecret(void)
{
	return _darkest_secret;
}



