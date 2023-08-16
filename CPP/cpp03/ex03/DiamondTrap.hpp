/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:20 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/16 18:58:15 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
		using FragTrap::_hit_points;
		using ScavTrap::_energy_points;
		using FragTrap::_attack_damage;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &o);
		~DiamondTrap();
		void	whoAmI(void);
		using ScavTrap::attack;
		DiamondTrap& operator=(const DiamondTrap &o);
};

#endif
