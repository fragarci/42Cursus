/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:16:33 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 10:21:39 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int	ft_special(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (std::cout <<
		"char: impossible\n"
		"int: impossible\n"
		"float: " << str << "\n"
		"double: " << str.substr(0, str.length() - 1) << std::endl, 1);
	else if (str == "-inf" || str == "+inf" || str == "nan")
		return (std::cout <<
		"char: impossible\n"
		"int: impossible\n"
		"float: " << str << "f\n"
		"double: " << str << std::endl, 1);
	return (0);
}

static int	ft_char(std::string str)
{
	if (str.length() != 1 || std::isdigit(str[0]))
		return (0);
	std::cout <<
	"char: " << str[0] << "\n"
	"int: " << (int)str[0] << "\n"
	"float: " << (float)str[0] << ".0f\n"
	"double: " << (double)str[0] << ".0" << std::endl;
	return (1);
}

static int	ft_int(std::string str)
{
	int		len = str.length();
	int		i = 0;
	long	nbr;

	if (str[i] == '-') { i++; }
	while (i < len && std::isdigit(str[i])) { i++; }
	if (i != len) { return (0); }
	nbr = atol(str.c_str());

	if (nbr < 33 || nbr > 126) { std::cout << "char: Non displayable\n"; }
	else { std::cout << "char: " << (char)nbr << "\n"; }

	if (nbr < INT_MIN || nbr > INT_MAX) { std::cout << "int: Overflow\n"; }
	else { std::cout << "int: " << (int)nbr << "\n"; }

	if (nbr > FLT_MAX) { std::cout << "float: Overflow\n"; }
	else { std::cout << "float: " << (float)nbr << ".0f\n"; }

	if (nbr > DBL_MAX) { std::cout << "double: Overflow\n"; }
	else { std::cout << "double: " << (double)nbr << ".0" << std::endl; }
	return (1);
}

static int	ft_decimal(std::string str)
{

	int		len = str.length();
	int		i = 0;
	double	nbr;

	if (str[i] == '-') { i++; }
	while (i < len && (std::isdigit(str[i]) || str[i] == '.'|| str[i] == 'f')) { i++; }
	if (i != len) { return (0); }
	nbr = atof(str.c_str());

	if (nbr < 33 || nbr > 126) { std::cout << "char: Non displayable\n"; }
	else { std::cout << "char: " << (char)nbr << "\n"; }

	if (nbr < INT_MIN || nbr > INT_MAX) { std::cout << "int: Overflow\n"; }
	else { std::cout << "int: " << (int)nbr << "\n"; }

	if ((double)(nbr - (int)nbr) == (double)0)
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(1);
	}

	if (nbr > FLT_MAX) { std::cout << "float: Overflow\n"; }
	else { std::cout << "float: " << (float)nbr << "f\n"; }

	if (nbr > DBL_MAX) { std::cout << "double: Overflow\n"; }
	else { std::cout << "double: " << (double)nbr << std::endl; }
	return (1);
}

void ScalarConverter::convert(std::string str)
{
	if (ft_special(str) || ft_char(str) || ft_int(str) || ft_decimal(str))
		return ;
	std::cout << "Error: Cannot convert D:" << std::endl;
}
