/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:29:51 by cpereira          #+#    #+#             */
/*   Updated: 2021/09/01 00:36:26 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	main (int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] >= 97 && argv[i][j] <= 122)
					argv[i][j] -= 32;
				std::cout << argv[i][j];
				j++;
			}
			std::cout << ' ';
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
