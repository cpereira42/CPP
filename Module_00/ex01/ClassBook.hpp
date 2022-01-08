/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:46:12 by cpereira          #+#    #+#             */
/*   Updated: 2022/01/08 03:06:54 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSBOOK_HPP
# define CLASSBOOK_HPP

#include <iostream>
#include <string> // To use string
#include <iomanip>

class Book
{
	public:
		int		i;
		int		qtt;
		Contact list[8];

		Book( void );
		~Book( void );

		void	add(void);
		void	reduc_string(std::string s);
		void	list_book (void);
		void	creat(void);
		void	list_person(int i);
};

#endif
