/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:01:44 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/21 11:21:57 by fragarci         ###   ########.fr       */
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

void BitcoinExchange::processInput(const std::string &filename)
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
		key = line.substr(0, line.find(" "));
		value = atof(line.substr(line.find("|") + 1).c_str());
		if (line.find("|") == std::string::npos)
			std::cerr << "Error: bad input => " << line << std::endl;
		else if (!_checkNbrLenght(line.substr(line.find("|") + 1)))
			std::cerr << "Error: too large a number" << std::endl;
		else if (!_checkDate(key))
			std::cerr << "Error: bad date => " << key << std::endl;
		else if (value < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (_dateExists(key))
			std::cout << key << "=> " << value << " = " << value * this->_data[key] << std::endl;
		else
			_getClosestDate(key, value);
	}
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

bool	BitcoinExchange::_checkNbrLenght(const std::string &str) const
{
	std::string	tmp;

	if (str.length() > 11)
		return (false);
	else if (str.length() == 11)
	{
		tmp = str.substr(1, 11);
		if (tmp.compare("2147483647") > 0)
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::_checkDate(const std::string &str) const
{
	int year = atoi(str.substr(0, 4).c_str());
	int	month = atoi(str.substr(5, 2).c_str());
	int	day = atoi(str.substr(8, 2).c_str());

	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if (((year % 4) && month == 2 && day > 28)
		|| (!(year % 4) && month == 2 && day > 29))
		return (false);
	return (true);
}

bool	BitcoinExchange::_dateExists(const std::string &str) const { return (this->_data.count(str) > 0); }

static void	nextDate(int *year, int *month, int *day)
{
	if (*day > 1)
		(*day)--;
	else if (*month > 1)
	{
		(*month)--;
		(*day) = 31;
	}
	else
	{
		(*year)--;
		(*month) = 12;
		(*day) = 31;
	}
}

void	BitcoinExchange::_getClosestDate(const std::string &str, float value) const
{
	std::string	final_date = str;
	std::stringstream	stream(final_date);
	int year = atoi(str.substr(0, 4).c_str());
	int	month = atoi(str.substr(5, 2).c_str());
	int	day = atoi(str.substr(8, 2).c_str());
	while (!_dateExists(final_date) && year > 2009)
	{
		stream.str("");
		nextDate(&year, &month ,&day);
		stream << year;
		if (month < 10)
			stream << "-0" << month;
		else
			stream << "-" << month;
		if (day < 10)
			stream << "-0" << day;
		else
			stream << "-" << day;
		final_date = stream.str();
	}
	if (this->_dateExists(final_date))
		std::cout << str << " => " << value << " = " << value * this->_data.find(final_date)->second << std::endl;
	else
		std::cerr << str << " => " << "no data found" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const BitcoinExchange &src)
{
	const std::map<std::string, float> data = src.getData();
	for (std::map<std::string, float>::const_iterator it = data.begin(); it != data.end(); it++)
		o << it->first << ": " << it->second << std::endl;
	return (o);
}
