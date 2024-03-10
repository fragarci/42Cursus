/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:04 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/21 10:40:34 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <string>
# include <map>

class BitcoinExchange
{
	private:
	std::map<std::string, float> _data;
	void	_loadData(const std::string &filename);
	bool	_checkNbrLenght(const std::string &str) const;
	bool	_checkDate(const std::string &str) const;
	bool	_dateExists(const std::string &str) const;
	void	_getClosestDate(const std::string &str, float value) const;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		void processInput(const std::string &filename);
		std::map<std::string, float> getData(void) const;
};

std::ostream &operator<<(std::ostream &o, const BitcoinExchange &src);

#endif
