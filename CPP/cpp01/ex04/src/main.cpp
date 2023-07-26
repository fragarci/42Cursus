/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:23:43 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/26 11:10:30 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed <filename> <to_find> <replace>." << std::endl;
		return (EXIT_FAILURE);
	}
	else
	{
		Sed sed(argv[1]);
		sed.replace(argv[2], argv[3]);
	}
	return (EXIT_SUCCESS);
}
