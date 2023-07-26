/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:41:32 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/05 17:23:32 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	Zombie *zombies;

	zombies = zombieHorde(N_ZOMBIES, ZOMBIES_NAME);
	for (int i = 0; i < N_ZOMBIES; i++)
		zombies[i].anounce();
	delete [] zombies;
	return (0);
}
