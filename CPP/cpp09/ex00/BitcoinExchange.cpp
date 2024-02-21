/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:01:44 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/15 11:54:55 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { _loadData("data.csv"); }
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }
BitcoinExchange::~BitcoinExchange(void) { return ; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		this->_data = src._data;
	return (*this);
}

std::map<std::string, float> BitcoinExchange::getData(void) const { return (this->_data); }

void BitcoinExchange::_loadData(const std::string &filename)
{
	std::ifstream	stream;
	std::string		line;
	std::string		key;
	float			value;

	stream.open(filename.c_str());
	if (!stream.is_open())
		return (std::cerr << "Error: Couldn't open " << filename << std::endl, (void)0);
	while (std::getline(stream, line))
	{
		key = line.substr(0, line.find(','));
		value = atof(line.substr(line.find(',') + 1).c_str());
		this->_data.insert(std::pair<std::string, float>(key, value));
	}
	stream.close();
}

std::ostream &operator<<(std::ostream &o, const BitcoinExchange &src)
{
	const std::map<std::string, float> data = src.getData();
	for (std::map<std::string, float>::const_iterator it = data.begin(); it != data.end(); it++)
		o << it->first << ": " << it->second << std::endl;
	return (o);
}
