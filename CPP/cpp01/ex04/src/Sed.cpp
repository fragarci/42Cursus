/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:10:57 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/13 17:57:14 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Sed.hpp"

Sed::Sed(std::string filename) : _in_file(filename){
		this->_out_file = this->_in_file + ".replace";
}

Sed::~Sed(void) {}

void	Sed::replace(std::string toFind, std::string replace)
{
	std::ifstream in_stream(this->_in_file.c_str());
	if (in_stream.is_open())
	{
		std::string file_content;
		if (std::getline(in_stream, file_content, '\0'))
		{
			std::ofstream out_stream(this->_out_file.c_str());
			size_t pos = file_content.find(toFind);
			while ( pos != std::string::npos )
			{
					file_content.erase(pos, toFind.length());
					file_content.insert(pos, replace);
					pos = file_content.find(toFind);
			}
			out_stream << file_content;
			out_stream.close();
		}
		else
			std::cerr << "Empty file found." << std::endl;
		in_stream.close();
	}
	else
	{
		std::cerr << "Unable to open the file." << std::endl;
		exit(EXIT_FAILURE);
	}
}
