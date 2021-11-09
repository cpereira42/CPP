/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:28:14 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/08 21:52:57 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    public:
    Weapon(std::string w_type);
    ~Weapon();

    std::string const &getType();
    void    setType(std::string w_type);

    private:
        std::string	_type;
};

#endif