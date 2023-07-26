/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:07:13 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/13 18:06:16 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class	Sed
{
	private:
		std::string _in_file;
		std::string _out_file;

	public:
		Sed(std::string filename);
		~Sed();

	void	replace(std::string s1, std::string s2);
};
#endif
