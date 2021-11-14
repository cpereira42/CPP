/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:30:08 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/13 23:30:09 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

class Karen
{
    public:

    Karen(void);
	~Karen(void);
    void complain(std::string level);

    private:

    void    info(void);
    void    debug(void);
    void    warning(void);
    void    error(void);
    void    invalid(void);

};
#endif