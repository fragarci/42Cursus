/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:02:21 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/05 17:22:21 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define N_ZOMBIES 5
# define ZOMBIES_NAME "PAKO"

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		~Zombie();
		void		anounce(void);
		void		setName(std::string name);
};
Zombie	*zombieHorde(int N, std::string name);
#endif
