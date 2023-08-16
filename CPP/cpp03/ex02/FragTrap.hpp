#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
{
	private:
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &o);
		~FragTrap();
		void	highFiveGuys(void);
		FragTrap& operator=(const FragTrap &o);
};

#endif
