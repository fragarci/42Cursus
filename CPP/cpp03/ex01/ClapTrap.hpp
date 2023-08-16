/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:03:44 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/15 11:00:26 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int	_hit_points;
		int	_energy_points;
		int	_attack_damage;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &copy);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int	getHitPoints(void) const;
		int	getEnergyPoints(void) const;
		int	getAttackDamage(void) const;

};
std::ostream& operator<<(std::ostream &out, const ClapTrap &obj);
#endif
