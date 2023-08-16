#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap
{
	private:
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &o);
		~ScavTrap();
		void attack(const std::string &target);
		void	guardGate(void);
		ScavTrap& operator=(const ScavTrap &o);
};

#endif
