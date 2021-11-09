/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:28:20 by cpereira          #+#    #+#             */
/*   Updated: 2021/11/08 23:06:42 by cpereira         ###   ########.fr       */
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

int main (int argc, char **argv)
{
	std::string		file_name;
	std::string		out_file_name;
	std::ifstream	input_file;
	std::ofstream	output_file;
	std::string		str1;
	std::string		str2;

	if (argc != 4)
	{
		std::cout << "Error : invalid args, use ./replace Filename old_string new_string" << std::endl;
		return (1);
	}
	if (try_open(argv[1]))
		return (1);
		
	file_name = std::string(argv[1]);
	out_file_name = to_upper(file_name) + ".replace";
	output_file.open(out_file_name.c_str());
	output_file.write("oi",2);
	
	// falta copiar o arquivo e fazer o replace dele +/- 30 min
	
	input_file.close();
	output_file.close();
	
	
	
}