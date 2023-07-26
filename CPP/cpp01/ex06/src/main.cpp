/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:35:39 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/13 18:41:07 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int	main(int	argc, char **argv)
{
	Harl		harl;

	if (argc != 2)
		return (EXIT_FAILURE);
	harl.complain(argv[1]);
}
