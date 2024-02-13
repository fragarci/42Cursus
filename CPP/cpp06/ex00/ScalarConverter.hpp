/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:10:10 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 10:06:39 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits.h>
# include <float.h>
# include <stdlib.h>

class ScalarConverter
{
	public:
		virtual ~ScalarConverter() = 0;
		static void convert(std::string str);
};

#endif
