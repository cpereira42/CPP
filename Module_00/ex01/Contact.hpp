/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:46:12 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/08 19:15:11 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string> // To use string
#include <iomanip>
# include <stdlib.h>

class Contact
{
	public:
		void	setFirstName(const std::string &firstname);
		void	setLastName(const std::string &lastname);
		void	setNickname(const std::string &nickname);
		void	setPhone(const std::string &phone);
		void	setDarksecret(const std::string &darkest_secret);

		Contact( void );
		~Contact( void );

		int			get_index(void);
		const std::string	get_FirstName(void);
		const std::string	get_LastName(void);
		const std::string	get_Nickname(void);
		const std::string	get_Phone(void);
		const std::string	get_Darkestsecret(void);

	private:
		int			_index;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone;
		std::string	_darkest_secret;

};

#endif
