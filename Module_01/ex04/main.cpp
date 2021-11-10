/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:28:20 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/09 21:11:18 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

std::string to_upper(std::string name_file)
{
	int i;

	i = 0;
	while (name_file[i])
	{
		name_file[i] =std::toupper(name_file[i]);
		i++;
	}
	return(name_file);
}

static bool try_open(std::string file_name)
{
	std::ifstream	input;
	
	input.open(file_name.c_str());
	if (!input)
	{
		std::cout << "Invalid file" << std::endl;
		return (true);
	}
	return (false);
}

void	replace(std::string old_str, std::string new_str, std::string *text)
{
	std::size_t 	found;
	found = (*text).find(old_str);
	while (found!=std::string::npos)
	{
		(*text).erase(found,old_str.size());
		(*text).insert(found, new_str);
		found = (*text).find(old_str);
	}
}

int main (int argc, char **argv)
{
	std::string		file_name;
	std::string		out_file_name;
	std::string		text;
	std::ifstream	file_in;
	std::ofstream	file_out;

	if (argc != 4)
	{
		std::cout << "Error : invalid args, use ./replace Filename old_string new_string" << std::endl;
		return (1);
	}
	if (try_open(argv[1]))
		return (1);
		
	file_name = argv[1];
	file_in.open(file_name.c_str());
	out_file_name = to_upper(file_name) + ".replace";
	file_out.open(out_file_name.c_str());
	
	while (std::getline (file_in, text))
	{
		replace(argv[2],argv[3],&text);
		file_out << text << std::endl;
	}
	file_in.close();
	file_out.close();
}

